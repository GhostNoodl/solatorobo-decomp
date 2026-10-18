#include "fs_private.h"

#pragma force_active on

typedef struct FSiArchiveStatics {
    FSArchive *arc_list;    // 0x00
    FSDirPos current_dir_pos; // 0x04
} FSiArchiveStatics;

extern FSiArchiveStatics data_0208e80c;
#define arc_list        data_0208e80c.arc_list
#define current_dir_pos data_0208e80c.current_dir_pos
extern char data_0208e81c[16][16];
#define FSiArchiveNameTable data_0208e81c
extern char data_0208e91c[FS_ENTRY_LONGNAME_MAX];
#define current_dir_path data_0208e91c
extern const char data_0208af38[];

static inline void FSi_WaitConditionOn(u32 *flag, u32 bits, OSThreadQueue *queue) {
    OSIntrMode bak_psr = OS_DisableInterrupts();
    while (!(*flag & bits)) {
        OS_SleepThread(queue);
    }
    (void)OS_RestoreInterrupts(bak_psr);
}

static inline void FSi_WaitConditionOff(u32 *flag, u32 bits, OSThreadQueue *queue) {
    OSIntrMode bak_psr = OS_DisableInterrupts();
    while (*flag & bits) {
        OS_SleepThread(queue);
    }
    (void)OS_RestoreInterrupts(bak_psr);
}

FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner);
void FSi_ExecuteAsyncCommand(FSFile *file);
void FSi_ExecuteSyncCommand(FSFile *file);
FSResult FSi_TranslateCommand(FSFile *p_file, FSCommandType command);
void FSi_EndCommand(FSFile *file, FSResult ret);

const char *FS_GetArchiveName(const FSArchive *arc) {
    return (arc->name.pack[3] != '\0') ? arc->name.ptr : arc->name.pack;
}

BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl) {
    FSFile tmp[1];

    arc->userdata = userdata;
    arc->vtbl = vtbl;
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_TranslateCommand(tmp, FS_COMMAND_MOUNT);
    arc->flag |= FS_ARCHIVE_FLAG_LOADED;
    return TRUE;
}

BOOL FS_SuspendArchive(FSArchive *arc) {
    BOOL retval;
    OSIntrMode bak_psr = OS_DisableInterrupts();

    retval = !FS_IsArchiveSuspended(arc);
    if (retval) {
        if (!(arc->flag & FS_ARCHIVE_FLAG_RUNNING)) {
            arc->flag |= FS_ARCHIVE_FLAG_SUSPEND;
        } else {
            arc->flag |= FS_ARCHIVE_FLAG_SUSPENDING;
            FSi_WaitConditionOff(&arc->flag, FS_ARCHIVE_FLAG_SUSPENDING, &arc->queue);
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return retval;
}

BOOL FS_ResumeArchive(FSArchive *arc) {
    BOOL retval;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        retval = !FS_IsArchiveSuspended(arc);
        if (!retval) {
            arc->flag &= ~FS_ARCHIVE_FLAG_SUSPEND;
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
    {
        FSFile *file = FSi_NextCommand(arc, TRUE);
        if (file) {
            FSi_ExecuteAsyncCommand(file);
        }
    }
    return retval;
}

void FS_NotifyArchiveAsyncEnd(FSArchive *arc, FSResult ret) {
    FSFile *file = arc->list;

    if (file->stat & FS_FILE_STATUS_BLOCKING) {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        file->stat |= FS_FILE_STATUS_ASYNC_DONE;
        file->error = ret;
        OS_WakeupThread(file->queue);
        (void)OS_RestoreInterrupts(bak_psr);
    } else {
        FSi_EndCommand(file, ret);
        file = FSi_NextCommand(arc, TRUE);
        if (file) {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}

BOOL FS_WaitAsync(FSFile *file) {
    BOOL is_owner = FALSE;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (FS_IsBusy(file)) {
            is_owner = !(file->stat & (FS_FILE_STATUS_BLOCKING | FS_FILE_STATUS_OPERATING));
            if (is_owner) {
                file->stat |= FS_FILE_STATUS_BLOCKING;
            }
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
    if (is_owner) {
        FSi_ExecuteSyncCommand(file);
    } else {
        FSi_WaitConditionOff(&file->stat, FS_FILE_STATUS_BUSY, file->queue);
    }
    return FS_IsSucceeded(file);
}

int FSi_DecrementSjisPosition(const char *str, int pos) {
    int prev = --pos;
    for (; (prev > 0) && STD_IsSjisLeadByte(str[prev - 1]); --prev) {
    }
    return pos - ((pos - prev) & 1);
}

int FSi_IncrementSjisPositionToSlash(const char *str, int pos) {
    while (str[pos] && !FSi_IsSlash((u8)str[pos])) {
        pos = FSi_IncrementSjisPosition(str, pos);
    }
    return pos;
}

int FSi_DecrementSjisPositionToSlash(const char *str, int pos) {
    for (;;) {
        pos = FSi_DecrementSjisPosition(str, pos);
        if ((pos < 0) || FSi_IsSlash((u8)str[pos])) {
            break;
        }
    }
    return pos;
}

int FSi_TrimSjisTrailingSlash(char *str) {
    int len = STD_GetStringLength(str);
    int lastpos = FSi_DecrementSjisPosition(str, len);

    if ((lastpos >= 0) && FSi_IsSlash((u8)str[lastpos])) {
        len = lastpos;
        str[len] = '\0';
    }
    return len;
}

void FS_InitFile(FSFile *p_file) {
    p_file->arc = NULL;
    p_file->userdata = NULL;
    p_file->next = NULL;
    OS_InitThreadQueue(p_file->queue);
    p_file->stat = 0;
    p_file->stat |= FS_COMMAND_INVALID << FS_FILE_STATUS_CMD_SHIFT;
    p_file->argument = NULL;
    p_file->error = FS_RESULT_SUCCESS;
}

void FS_CancelFile(FSFile *p_file) {
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (FS_IsBusy(p_file)) {
        FSArchive *const arc = p_file->arc;
        p_file->stat |= FS_FILE_STATUS_CANCEL;
        arc->flag |= FS_ARCHIVE_FLAG_CANCELING;
    }
    (void)OS_RestoreInterrupts(bak_psr);
}
