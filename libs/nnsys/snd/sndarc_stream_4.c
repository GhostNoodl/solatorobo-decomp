#include "nnsys/snd/sndarc_stream.h"

void StrmPlayer_SetFileFuncs(StrmPlayer *player, u32 fileId) {
    if (NNS_SndArcGetFileAddress(fileId) == NULL) {
        player->openFn = StrmPlayer_OpenArcFile;
        player->closeFn = StrmPlayer_CloseArcFile;
        player->readFn = StrmPlayer_ReadArcFile;
        player->stopFn = StrmPlayer_CancelArcFile;
    } else {
        player->openFn = StrmPlayer_OpenMem;
        player->closeFn = StrmPlayer_CloseMem;
        player->readFn = StrmPlayer_ReadMem;
        player->stopFn = StrmPlayer_CancelMem;
    }
}

BOOL StrmPlayer_OpenArcFile(StrmPlayer *player, u32 fileId) {
    if (NNS_SndArcReadFile(fileId, &player->header, sizeof(StrmHeader), 0) != sizeof(StrmHeader)) {
        return FALSE;
    }
    if (!FS_OpenFileFast(player->file, NNS_SndArcGetFileID())) {
        void *arc;
        u32 top;
        u32 bottom;
        BOOL opened;
        BOOL set;
        arc = SndArc_GetAltPath();
        if (arc == NULL) {
            return FALSE;
        }
        top = SndArc_GetAltTop();
        bottom = SndArc_GetAltBottom();
        if (top == 0) {
            return FALSE;
        }
        if (bottom == 0) {
            return FALSE;
        }
        opened = FS_OpenFileEx(player->file, arc, 1);
        set = FS_SetSeekCache(player->file, top, bottom);
        if (!opened) {
            return FALSE;
        }
        if (!set) {
            return FALSE;
        }
    }
    player->fileOffset = NNS_SndArcGetFileOffset(fileId);
    return TRUE;
}

void StrmPlayer_CloseArcFile(StrmPlayer *player) {
    FS_CloseFile(player->file);
}

u32 StrmPlayer_ReadArcFile(StrmPlayer *player, void *buf, u32 size, u32 offset) {
    FS_SeekFile(player->file, player->fileOffset + offset, 0);
    return FS_ReadFile(player->file, buf, size);
}

void StrmPlayer_CancelArcFile(StrmPlayer *player) {
    FS_CancelFile(player->file);
}

BOOL StrmPlayer_OpenMem(StrmPlayer *player, u32 fileId) {
    player->fileOffset = (u32)NNS_SndArcGetFileAddress(fileId);
    MI_CpuCopy8((void *)player->fileOffset, &player->header, sizeof(StrmHeader));
    return TRUE;
}

void StrmPlayer_CloseMem(StrmPlayer *player) {
}

u32 StrmPlayer_ReadMem(StrmPlayer *player, void *buf, u32 size, u32 offset) {
    MI_CpuCopy8((u8 *)player->fileOffset + offset, buf, size);
    return size;
}

void StrmPlayer_CancelMem(StrmPlayer *player) {
}

void StrmThread_Main(void *arg) {
    StrmThread *thread = arg;
    StrmCommand *cmd;
    while (TRUE) {
        OS_SleepThread(&thread->queue);
        while (TRUE) {
            OS_LockMutex(&thread->mutex);
            cmd = Strm_PopCommand(&thread->cmdList);
            if (cmd == NULL) {
                OS_UnlockMutex(&thread->mutex);
                break;
            }
            Strm_ProcessCommand(cmd);
            Strm_FreeCommand(cmd);
            OS_UnlockMutex(&thread->mutex);
        }
    }
}
