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

BOOL FSi_IsEventCommand(FSCommandType command) {
    return (command == FS_COMMAND_ACTIVATE) || (command == FS_COMMAND_IDLE) || (command == FS_COMMAND_SUSPEND) ||
           (command == FS_COMMAND_RESUME) || (command == FS_COMMAND_MOUNT) || (command == FS_COMMAND_UNMOUNT) ||
           (command == FS_COMMAND_INVALID);
}

void FSi_EndCommand(FSFile *file, FSResult ret) {
    OSIntrMode bak_psr = OS_DisableInterrupts();
    FSArchive *const arc = file->arc;

    if (arc) {
        FSFile **pp;
        for (pp = &arc->list; *pp; pp = &(*pp)->next) {
            if (*pp == file) {
                *pp = file->next;
                break;
            }
        }
        file->next = NULL;
    }
    {
        FSCommandType command = FSi_GetCurrentCommand(file);
        if (!FSi_IsEventCommand(command) && arc) {
            arc->command = command;
            arc->result = ret;
        }
    }
    file->error = ret;
    file->stat &= ~(FS_FILE_STATUS_CMD_MASK & ~(FS_FILE_STATUS_IS_FILE | FS_FILE_STATUS_IS_DIR));
    OS_WakeupThread(file->queue);
    (void)OS_RestoreInterrupts(bak_psr);
}

FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result) {
    if (result == FS_RESULT_PROC_ASYNC) {
        FSi_WaitConditionOn(&file->stat, FS_FILE_STATUS_ASYNC_DONE, file->queue);
        file->stat &= ~FS_FILE_STATUS_ASYNC_DONE;
        result = file->error;
    }
    return result;
}

FSResult FSi_TranslateCommand(FSFile *p_file, FSCommandType command) {
    FSResult result = FS_RESULT_PROC_DEFAULT;
    FSArchive *const arc = p_file->arc;
    const void *const *table = (const void *const *)arc->vtbl;

    if (command >= FS_COMMAND_MAX) {
        result = FS_RESULT_UNSUPPORTED;
    } else if (table[command] == NULL) {
        result = FS_RESULT_UNSUPPORTED;
    } else {
        switch (command) {
        case FS_COMMAND_READFILE: {
            FSArgumentForReadFile *arg = (FSArgumentForReadFile *)p_file->argument;
            result = arc->vtbl->ReadFile(arc, p_file, arg->buffer, &arg->length);
        } break;
        case FS_COMMAND_WRITEFILE: {
            FSArgumentForWriteFile *arg = (FSArgumentForWriteFile *)p_file->argument;
            result = arc->vtbl->WriteFile(arc, p_file, arg->buffer, &arg->length);
        } break;
        case FS_COMMAND_SEEKDIR: {
            FSArgumentForSeekDirectory *arg = (FSArgumentForSeekDirectory *)p_file->argument;
            result = arc->vtbl->SeekDirectory(arc, p_file, arg->id, arg->position);
        } break;
        case FS_COMMAND_READDIR: {
            FSArgumentForReadDirectory *arg = (FSArgumentForReadDirectory *)p_file->argument;
            result = arc->vtbl->ReadDirectory(arc, p_file, arg->info);
        } break;
        case FS_COMMAND_FINDPATH: {
            FSArgumentForFindPath *arg = (FSArgumentForFindPath *)p_file->argument;
            result = arc->vtbl->FindPath(arc, arg->baseid, arg->relpath, &arg->target_id, arg->target_is_directory);
        } break;
        case FS_COMMAND_GETPATH: {
            FSArgumentForGetPath *arg = (FSArgumentForGetPath *)p_file->argument;
            result = arc->vtbl->GetPath(arc, p_file, (BOOL)arg->buffer, (char *)arg->length, (u32 *)&arg->is_directory);
        } break;
        case FS_COMMAND_OPENFILEFAST: {
            FSArgumentForOpenFileFast *arg = (FSArgumentForOpenFileFast *)p_file->argument;
            result = arc->vtbl->OpenFileFast(arc, p_file, arg->id, arg->mode);
        } break;
        case FS_COMMAND_OPENFILEDIRECT: {
            FSArgumentForOpenFileDirect *arg = (FSArgumentForOpenFileDirect *)p_file->argument;
            result = arc->vtbl->OpenFileDirect(arc, p_file, arg->top, arg->bottom, &arg->id);
        } break;
        case FS_COMMAND_CLOSEFILE: {
            result = arc->vtbl->CloseFile(arc, p_file);
        } break;
        case FS_COMMAND_ACTIVATE:
            arc->vtbl->Activate(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_IDLE:
            arc->vtbl->Idle(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_SUSPEND:
            arc->vtbl->Suspend(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_RESUME:
            arc->vtbl->Resume(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_OPENFILE: {
            FSArgumentForOpenFile *arg = (FSArgumentForOpenFile *)p_file->argument;
            result = arc->vtbl->OpenFile(arc, p_file, arg->baseid, arg->relpath, arg->mode);
        } break;
        case FS_COMMAND_SEEKFILE: {
            FSArgumentForSeekFile *arg = (FSArgumentForSeekFile *)p_file->argument;
            result = arc->vtbl->SeekFile(arc, p_file, &arg->offset, arg->from);
        } break;
        case FS_COMMAND_GETFILELENGTH: {
            FSArgumentForGetFileLength *arg = (FSArgumentForGetFileLength *)p_file->argument;
            result = arc->vtbl->GetFileLength(arc, p_file, &arg->length);
        } break;
        case FS_COMMAND_GETFILEPOSITION: {
            FSArgumentForGetFilePosition *arg = (FSArgumentForGetFilePosition *)p_file->argument;
            result = arc->vtbl->GetFilePosition(arc, p_file, &arg->position);
        } break;
        case FS_COMMAND_MOUNT:
            arc->vtbl->Mount(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_UNMOUNT:
            arc->vtbl->Unmount(arc);
            return FS_RESULT_SUCCESS;
        case FS_COMMAND_GETARCHIVECAPS: {
            FSArgumentForGetArchiveCaps *arg = (FSArgumentForGetArchiveCaps *)p_file->argument;
            result = arc->vtbl->GetArchiveCaps(arc, &arg->caps);
        } break;
        case FS_COMMAND_CREATEFILE: {
            FSArgumentForCreateFile *arg = (FSArgumentForCreateFile *)p_file->argument;
            result = arc->vtbl->CreateFile(arc, arg->baseid, arg->relpath, arg->permit);
        } break;
        case FS_COMMAND_DELETEFILE: {
            FSArgumentForDeleteFile *arg = (FSArgumentForDeleteFile *)p_file->argument;
            result = arc->vtbl->DeleteFile(arc, arg->baseid, arg->relpath);
        } break;
        case FS_COMMAND_RENAMEFILE: {
            FSArgumentForRenameFile *arg = (FSArgumentForRenameFile *)p_file->argument;
            result = arc->vtbl->RenameFile(arc, arg->baseid_src, arg->relpath_src, arg->baseid_dst, arg->relpath_dst);
        } break;
        case FS_COMMAND_GETPATHINFO: {
            FSArgumentForGetPathInfo *arg = (FSArgumentForGetPathInfo *)p_file->argument;
            result = arc->vtbl->GetPathInfo(arc, arg->baseid, arg->relpath, arg->info);
        } break;
        case FS_COMMAND_SETPATHINFO: {
            FSArgumentForSetPathInfo *arg = (FSArgumentForSetPathInfo *)p_file->argument;
            result = arc->vtbl->SetPathInfo(arc, arg->baseid, arg->relpath, arg->info);
        } break;
        case FS_COMMAND_CREATEDIRECTORY: {
            FSArgumentForCreateDirectory *arg = (FSArgumentForCreateDirectory *)p_file->argument;
            result = arc->vtbl->CreateDirectory(arc, arg->baseid, arg->relpath, arg->permit);
        } break;
        case FS_COMMAND_DELETEDIRECTORY: {
            FSArgumentForDeleteDirectory *arg = (FSArgumentForDeleteDirectory *)p_file->argument;
            result = arc->vtbl->DeleteDirectory(arc, arg->baseid, arg->relpath);
        } break;
        case FS_COMMAND_RENAMEDIRECTORY: {
            FSArgumentForRenameDirectory *arg = (FSArgumentForRenameDirectory *)p_file->argument;
            result = arc->vtbl->RenameDirectory(arc, arg->baseid_src, arg->relpath_src, arg->baseid_dst, arg->relpath_dst);
        } break;
        case FS_COMMAND_GETARCHIVERESOURCE: {
            FSArgumentForGetArchiveResource *arg = (FSArgumentForGetArchiveResource *)p_file->argument;
            result = arc->vtbl->GetArchiveResource(arc, arg->resource);
        } break;
        case FS_COMMAND_FLUSHFILE: {
            result = arc->vtbl->FlushFile(arc, p_file);
        } break;
        case FS_COMMAND_SETFILELENGTH: {
            FSArgumentForSetFileLength *arg = (FSArgumentForSetFileLength *)p_file->argument;
            result = arc->vtbl->SetFileLength(arc, p_file, arg->length);
        } break;
        case FS_COMMAND_OPENDIRECTORY: {
            FSArgumentForOpenDirectory *arg = (FSArgumentForOpenDirectory *)p_file->argument;
            result = arc->vtbl->OpenDirectory(arc, p_file, arg->baseid, arg->relpath, arg->mode);
        } break;
        case FS_COMMAND_CLOSEDIRECTORY: {
            result = arc->vtbl->CloseDirectory(arc, p_file);
        } break;
        case FS_COMMAND_SETSEEKCACHE: {
            FSArgumentForSetSeekCache *arg = (FSArgumentForSetSeekCache *)p_file->argument;
            result = arc->vtbl->SetSeekCache(arc, p_file, arg->buf, arg->buf_size);
        } break;
        default:
            result = FS_RESULT_UNSUPPORTED;
            break;
        }
    }

    if (!FSi_IsEventCommand(command)) {
        if (p_file->stat & FS_FILE_STATUS_BLOCKING) {
            result = FSi_WaitForArchiveCompletion(p_file, result);
        } else if (result != FS_RESULT_PROC_ASYNC) {
            FSi_EndCommand(p_file, result);
        }
    }
    return result;
}

FSFile *FSi_NextCommand(FSArchive *arc, BOOL owner) {
    FSFile *next = NULL;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (arc->flag & FS_ARCHIVE_FLAG_CANCELING) {
            FSFile *p = arc->list;
            arc->flag &= ~FS_ARCHIVE_FLAG_CANCELING;
            while (p != NULL) {
                FSFile *q = p->next;
                if (FS_IsCanceling(p) && !(p->stat & FS_FILE_STATUS_OPERATING)) {
                    FSi_EndCommand(p, FS_RESULT_CANCELED);
                    if (!q) {
                        q = arc->list;
                    }
                }
                p = q;
            }
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (!(arc->flag & FS_ARCHIVE_FLAG_SUSPENDING) && !(arc->flag & FS_ARCHIVE_FLAG_SUSPEND) && arc->list) {
            const BOOL is_started = owner && !(arc->flag & FS_ARCHIVE_FLAG_RUNNING);
            if (is_started) {
                arc->flag |= FS_ARCHIVE_FLAG_RUNNING;
            }
            (void)OS_RestoreInterrupts(bak_psr);
            if (is_started) {
                (void)FSi_TranslateCommand(arc->list, FS_COMMAND_ACTIVATE);
            }
            bak_psr = OS_DisableInterrupts();
            if (owner || is_started) {
                next = arc->list;
                next->stat |= FS_FILE_STATUS_OPERATING;
            }
            if (owner && (next->stat & FS_FILE_STATUS_BLOCKING)) {
                OS_WakeupThread(next->queue);
                next = NULL;
            }
            (void)OS_RestoreInterrupts(bak_psr);
        } else {
            if (owner) {
                if (arc->flag & FS_ARCHIVE_FLAG_RUNNING) {
                    FSFile tmp;
                    FS_InitFile(&tmp);
                    tmp.arc = arc;
                    arc->flag &= ~FS_ARCHIVE_FLAG_RUNNING;
                    (void)FSi_TranslateCommand(&tmp, FS_COMMAND_IDLE);
                }
                if (arc->flag & FS_ARCHIVE_FLAG_SUSPENDING) {
                    arc->flag &= ~FS_ARCHIVE_FLAG_SUSPENDING;
                    arc->flag |= FS_ARCHIVE_FLAG_SUSPEND;
                    OS_WakeupThread(&arc->queue);
                }
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
    }
    return next;
}

void FSi_ExecuteAsyncCommand(FSFile *file) {
    FSArchive *const arc = file->arc;

    while (file) {
        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            file->stat |= FS_FILE_STATUS_OPERATING;
            if (file->stat & FS_FILE_STATUS_BLOCKING) {
                OS_WakeupThread(file->queue);
                file = NULL;
            }
            (void)OS_RestoreInterrupts(bak_psr);
        }
        if (!file) {
            break;
        }
        if (FSi_TranslateCommand(file, FSi_GetCurrentCommand(file)) == FS_RESULT_PROC_ASYNC) {
            break;
        }
        file = FSi_NextCommand(arc, TRUE);
    }
}

void FSi_ExecuteSyncCommand(FSFile *file) {
    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        while (!(file->stat & FS_FILE_STATUS_OPERATING) && (file->stat & FS_FILE_STATUS_BUSY)) {
            OS_SleepThread(file->queue);
        }
        (void)OS_RestoreInterrupts(bak_psr);
    }
    if (file->stat & FS_FILE_STATUS_OPERATING) {
        FSArchive *const arc = file->arc;
        FSResult result = FSi_TranslateCommand(file, FSi_GetCurrentCommand(file));
        FSi_EndCommand(file, result);
        file = FSi_NextCommand(arc, TRUE);
        if (file) {
            FSi_ExecuteAsyncCommand(file);
        }
    }
}

BOOL FSi_SendCommand(FSFile *p_file, FSCommandType command, BOOL blocking) {
    BOOL retval = FALSE;
    FSArchive *const arc = p_file->arc;
    BOOL owner;

    if (FS_IsBusy(p_file)) {
        OS_Terminate();
    }
    if (!arc) {
        p_file->error = FS_RESULT_INVALID_PARAMETER;
        return FALSE;
    }

    p_file->error = FS_RESULT_BUSY;
    p_file->stat = (p_file->stat & ~(FS_FILE_STATUS_CMD_MASK << FS_FILE_STATUS_CMD_SHIFT)) | (command << FS_FILE_STATUS_CMD_SHIFT) | FS_FILE_STATUS_BUSY;
    p_file->next = NULL;
    if (blocking) { p_file->stat |= FS_FILE_STATUS_BLOCKING; }

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        if (arc->flag & FS_ARCHIVE_FLAG_UNLOADING) {
            FSi_EndCommand(p_file, FS_RESULT_CANCELED);
        } else {
            FSFile **pp;
            for (pp = &arc->list; *pp; pp = &(*pp)->next) {
            }
            *pp = p_file;
        }
        owner = (arc->list == p_file) && !(arc->flag & FS_ARCHIVE_FLAG_RUNNING);
        (void)OS_RestoreInterrupts(bak_psr);
    }

    if (p_file->error != FS_RESULT_CANCELED) {
        FSFile *next = FSi_NextCommand(arc, owner);
        if (blocking) {
            FSi_ExecuteSyncCommand(p_file);
            retval = FS_IsSucceeded(p_file);
        } else {
            if (next) {
                FSi_ExecuteAsyncCommand(next);
            }
            retval = TRUE;
        }
    }

    return retval;
}

FSArchive *FS_FindArchive(const char *name, int name_len) {
    OSIntrMode bak_psr = OS_DisableInterrupts();
    FSArchive *arc = arc_list;

    for (; arc; arc = arc->next) {
        if (FS_IsArchiveLoaded(arc)) {
            const char *arcname = FS_GetArchiveName(arc);
            if (STD_CompareNString(arcname, name, name_len) == 0 && arcname[name_len] == '\0') {
                break;
            }
        }
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return arc;
}

BOOL FS_SetCurrentDirectory(const char *path) {
    BOOL retval = FALSE;
    FSArchive *arc;
    u32 baseid = 0;
    char relpath[FS_ENTRY_LONGNAME_MAX];

    arc = FS_NormalizePath(path, &baseid, relpath);
    if (arc) {
        current_dir_pos.arc = arc;
        current_dir_pos.own_id = 0;
        current_dir_pos.index = 0;
        current_dir_pos.pos = 0;
        (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
        if (arc->vtbl->FindPath != NULL) {
            FSFile file[1];
            FSArgumentForFindPath arg[1];
            FS_InitFile(file);
            file->arc = arc;
            file->argument = arg;
            arg->baseid = baseid;
            arg->relpath = relpath;
            arg->target_is_directory = TRUE;
            if (FSi_SendCommand(file, FS_COMMAND_FINDPATH, TRUE)) {
                current_dir_pos.own_id = (u16)arg->target_id;
                (void)STD_CopyLString(current_dir_path, relpath, sizeof(current_dir_path));
            }
        }
        retval = TRUE;
    }
    return retval;
}

int FSi_CopySafeString(char *dst, int dstlen, const char *src, int srclen, BOOL *stickyFailure) {
    int i;
    int n = (dstlen - 1 < srclen) ? (dstlen - 1) : srclen;

    for (i = 0; (i < n) && src[i]; ++i) {
        dst[i] = src[i];
    }
    if ((i < srclen) && src[i]) {
        *stickyFailure = TRUE;
    }
    dst[i] = '\0';
    return i;
}

FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath) {
    FSArchive *arc = NULL;
    int pathlen = 0;
    int pathmax = FS_ENTRY_LONGNAME_MAX;
    BOOL stickyFailure = FALSE;

    if (current_dir_pos.arc == NULL) {
        current_dir_pos.arc = arc_list;
        current_dir_pos.own_id = 0;
        current_dir_pos.pos = 0;
        current_dir_pos.index = 0;
        current_dir_path[0] = '\0';
    }

    if (FSi_IsSlash((u8)*path)) {
        arc = current_dir_pos.arc;
        ++path;
        if (baseid) {
            *baseid = 0;
        }
    } else {
        int i;
        for (i = 0;; i = FSi_IncrementSjisPosition(path, i)) {
            u32 c = (u8)path[i];
            if (!c || FSi_IsSlash(c)) {
                arc = current_dir_pos.arc;
                if (baseid) {
                    *baseid = current_dir_pos.own_id;
                }
                if (relpath && (current_dir_pos.own_id == 0) && (current_dir_path[0] != '\0')) {
                    pathlen += FSi_CopySafeString(&relpath[pathlen], pathmax - pathlen, current_dir_path, pathmax, &stickyFailure);
                    pathlen += FSi_CopySafeString(&relpath[pathlen], pathmax - pathlen, data_0208af38, 1, &stickyFailure);
                }
                break;
            } else if (c == ':') {
                arc = FS_FindArchive(path, i);
                path += i + 1;
                if (FSi_IsSlash((u8)*path)) {
                    ++path;
                }
                if (baseid) {
                    *baseid = 0;
                }
                break;
            }
        }
    }

    if (relpath) {
        int curlen = 0;
        while (!stickyFailure) {
            char c = path[curlen];
            if ((c != '\0') && !FSi_IsSlash((u8)c)) {
                curlen += (STD_IsSjisLeadByte(c) && STD_IsSjisTrailByte(path[curlen + 1])) ? 2 : 1;
            } else {
                if (curlen == 0) {
                } else if ((curlen == 1) && (path[0] == '.')) {
                } else if ((curlen == 2) && (path[0] == '.') && (path[1] == '.')) {
                    if (pathlen > 0) {
                        --pathlen;
                    }
                    pathlen = FSi_DecrementSjisPositionToSlash(relpath, pathlen) + 1;
                } else {
                    pathlen += FSi_CopySafeString(&relpath[pathlen], pathmax - pathlen, path, curlen, &stickyFailure);
                    if (c != '\0') {
                        pathlen += FSi_CopySafeString(&relpath[pathlen], pathmax - pathlen, data_0208af38, 1, &stickyFailure);
                    }
                }
                if (c == '\0') {
                    break;
                }
                path += curlen + 1;
                curlen = 0;
            }
        }
        relpath[pathlen] = '\0';
        pathlen = FSi_TrimSjisTrailingSlash(relpath);
    }
    return stickyFailure ? NULL : arc;
}

void FS_InitArchive(FSArchive *arc) {
    MI_CpuClear8(arc, sizeof(FSArchive));
    OS_InitThreadQueue(&arc->queue);
}

