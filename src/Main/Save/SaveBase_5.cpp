#include "Main/Save/SaveBase.h"

extern "C" {

void func_0204880c(SaveBase *s) {
    SaveBase_LoadData(s);
}

void func_02048868(SaveBase *s) {
    u32 off = s->curSlot * s->slotSize + 0x14;
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            if (SaveBase_ReadHeader(s, hdr) == 1) {
                return;
            }
            s->step = 1;
        case 1:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            s->step = 2;
            break;
        case 2:
            func_02016e28((u8 *)hdr + off, 0, s->slotSize);
            s->step = 3;
        case 3:
            if (SaveBase_WriteHeader(s, hdr) != 1) {
                s->step = 4;
            }
            break;
        case 4:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            SaveBase_SetState(s, 16);
            break;
    }
}

#ifdef NONMATCHING
BOOL func_02048a48(SaveBase *s, SaveHeader *hdr) {
    switch (s->step) {
        case 100:
            if (s->backupCount == 0) {
                return FALSE;
            }
            hdr->backupIdx++;
            if (hdr->backupIdx >= s->backupCount) {
                hdr->backupIdx -= s->backupCount;
            }
            s->step = 101;
        case 101:
            if (func_02047004(data_02097e44, SaveBase_BackupOffset(s, hdr->backupIdx), s->data, s->dataSize) != 1) {
                s->step = 102;
            }
            break;
        case 102:
            if (SysCard_IsBusy()) {
                break;
            }
            SysCard_EndAccess();
            return FALSE;
    }
    return TRUE;
}
#endif

}
