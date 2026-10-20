#include "Main/Save/SaveBase.h"

extern "C" {

void func_02047f60(SaveBase *s) {
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            if (!SaveBase_CheckSlot(s, hdr)) {
                SaveBase_SetState(s, 11);
            } else {
                s->step = 1;
            }
            break;
        case 1:
            if (func_02046e48(data_02097e44, s->data, SaveBase_DataOffset(s, s->curSlot), s->dataSize) != 1) {
                s->step = 2;
            }
            break;
        case 2:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            if (!func_02047724(s)) {
                SaveBase_SetState(s, 11);
            } else {
                SaveBase_SetState(s, 10);
            }
            break;
    }
}

void func_02048164(SaveBase *s) {
    SaveBase_LoadData(s);
}

static inline BOOL VerifyLoadedData(SaveBase *s) {
    u32 size;
    SaveData *data;
    data = s->data;
    size = s->dataSize;
    if (data->slotIdx != s->curSlot || data->size != size || (data->slot.flags & 2)) {
        return FALSE;
    }
    {
        u32 n = s->slotSize - 1;
        if (n != 0) {
            u8 cks;
            u8 x;
            const u8 *p;
            u32 i;
            BOOL ok;
            x = 0;
            p = (const u8 *)&data->slot + 1;
            cks = data->slot.checksum;
            for (i = 0; i < n; i++) {
                x ^= p[i];
            }
            ok = (x ^ cks) == 0;
            if (!ok) {
                return FALSE;
            }
        }
    }
    {
        u32 n = size - (s->slotSize + 4);
        if (n != 0) {
            u8 cks;
            u8 x;
            const u8 *p;
            u32 i;
            BOOL ok;
            x = 0;
            p = (const u8 *)data + (size - n);
            cks = data->checksum;
            for (i = 0; i < n; i++) {
                x ^= p[i];
            }
            ok = (x ^ cks) == 0;
            if (!ok) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

static inline u32 BackupDataOffset(SaveBase *s, s32 idx) {
    u32 off = s->dataSize * s->slotCount;
    off += s->baseOffset + s->headerSize;
    off += idx * s->dataSize;
    return off;
}

void func_020481c0(SaveBase *s) {
    u32 off = s->curSlot * s->slotSize + 0x14;
    SaveHeader *hdr = s->header;
    SaveData *data = s->data;
    switch (s->step) {
        case 0:
            if (func_02046e48(data_02097e44, data, SaveBase_DataOffset(s, s->curSlot), s->dataSize) != 1) {
                s->step = 1;
            }
            break;
        case 1:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            if (!VerifyLoadedData(s)) {
                s->step = 2;
            } else {
                s->step = 5;
            }
            break;
        case 2:
            if (s->backupCount == 0 || hdr->backupIdx == 0xff) {
                SaveBase_SetState(s, 14);
                return;
            }
            s->backupIdx = hdr->backupIdx;
            s->backupStart = hdr->backupIdx;
        case 3:
            if (func_02046e48(data_02097e44, data, BackupDataOffset(s, s->backupIdx), s->dataSize) != 1) {
                s->step = 4;
            }
            break;
        case 4:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            if (!VerifyLoadedData(s)) {
                s->backupIdx--;
                if (s->backupIdx >= s->backupCount) {
                    s->backupIdx = s->backupCount - 1;
                }
                if (s->backupIdx == s->backupStart) {
                    SaveBase_SetState(s, 14);
                    return;
                }
                s->step = 3;
            } else {
                s->step = 5;
            }
            break;
        case 5:
            hdr->curSlot = s->curSlot;
            MI_CpuCopy8(&data->slot, (u8 *)hdr + off, s->slotSize);
            s->step = 100;
        case 6:
            if (SaveBase_WriteHeader(s, hdr) != 1) {
                s->step = 7;
            }
            break;
        case 7:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            s->step = 8;
            break;
        case 8:
            if (func_02047004(data_02097e44, SaveBase_DataOffset(s, s->curSlot), data, s->dataSize) != 1) {
                s->step = 9;
            }
            break;
        case 9:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            SaveBase_SetState(s, 13);
            break;
        default:
            if (!s->WriteBackup(hdr)) {
                s->step = 6;
            }
            break;
    }
}
}
