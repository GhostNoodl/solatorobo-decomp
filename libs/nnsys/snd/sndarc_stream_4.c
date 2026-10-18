#include "nnsys/snd/sndarc_stream.h"

void func_02032c54(StrmPlayer *player, u32 fileId) {
    if (NNS_SndArcGetFileAddress(fileId) == NULL) {
        player->openFn = func_02032cbc;
        player->closeFn = func_02032db4;
        player->readFn = func_02032dc4;
        player->stopFn = func_02032dfc;
    } else {
        player->openFn = func_02032e0c;
        player->closeFn = func_02032e34;
        player->readFn = func_02032e38;
        player->stopFn = func_02032e54;
    }
}

BOOL func_02032cbc(StrmPlayer *player, u32 fileId) {
    if (NNS_SndArcReadFile(fileId, &player->header, sizeof(StrmHeader), 0) != sizeof(StrmHeader)) {
        return FALSE;
    }
    if (!func_0200ee40(player->file, NNS_SndArcGetFileID())) {
        void *arc;
        u32 top;
        u32 bottom;
        BOOL opened;
        BOOL set;
        arc = func_020304dc();
        if (arc == NULL) {
            return FALSE;
        }
        top = func_020304f0();
        bottom = func_02030504();
        if (top == 0) {
            return FALSE;
        }
        if (bottom == 0) {
            return FALSE;
        }
        opened = func_0200ee98(player->file, arc, 1);
        set = func_0200ef30(player->file, top, bottom);
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

void func_02032db4(StrmPlayer *player) {
    func_0200ef1c(player->file);
}

u32 func_02032dc4(StrmPlayer *player, void *buf, u32 size, u32 offset) {
    func_0200f00c(player->file, player->fileOffset + offset, 0);
    return func_0200f038(player->file, buf, size);
}

void func_02032dfc(StrmPlayer *player) {
    func_0200ed2c(player->file);
}

BOOL func_02032e0c(StrmPlayer *player, u32 fileId) {
    player->fileOffset = (u32)NNS_SndArcGetFileAddress(fileId);
    func_02016fa0((void *)player->fileOffset, &player->header, sizeof(StrmHeader));
    return TRUE;
}

void func_02032e34(StrmPlayer *player) {
}

u32 func_02032e38(StrmPlayer *player, void *buf, u32 size, u32 offset) {
    func_02016fa0((u8 *)player->fileOffset + offset, buf, size);
    return size;
}

void func_02032e54(StrmPlayer *player) {
}

void func_02032e58(void *arg) {
    StrmThread *thread = arg;
    StrmCommand *cmd;
    while (TRUE) {
        OS_SleepThread(&thread->queueHead);
        while (TRUE) {
            OS_LockMutex(thread->mutex);
            cmd = func_0203207c(&thread->cmdList);
            if (cmd == NULL) {
                OS_UnlockMutex(thread->mutex);
                break;
            }
            func_0203244c(cmd);
            func_02032110(cmd);
            OS_UnlockMutex(thread->mutex);
        }
    }
}
