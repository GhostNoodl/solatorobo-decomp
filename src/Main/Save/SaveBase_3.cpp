#include "Main/Save/SaveBase.h"

extern "C" {

void SaveBase_State5(SaveBase *s) {
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            s->tmpBuf = Heap_AllocHi(s->tmpSize, 4);
            MI_CpuFill8(s->tmpBuf, 0, s->tmpSize);
            s->InitHeader(hdr);
            s->step = 1;
            break;
        case 1:
            if (SysCard_Write(gSysCard, s->baseOffset, s->tmpBuf, s->tmpSize) != 1) {
                s->step = 2;
            }
            break;
        case 2:
            if (SysCard_IsBusy()) {
                return;
            }
            if (s->tmpBuf != NULL) {
                Heap_FreeHi(s->tmpBuf);
                s->tmpBuf = NULL;
            }
            SysCard_EndAccess();
            s->step = 3;
            break;
        case 3:
            if (SaveBase_WriteHeader(s, hdr) != 1) {
                s->step = 4;
            }
            break;
        case 4:
            if (SysCard_IsBusy()) {
                return;
            }
            s->formatted = 0;
            SysCard_EndAccess();
            SaveBase_SetState(s, 6);
            break;
    }
}

void SaveBase_State7(SaveBase *s) {
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            hdr->curSlot = s->curSlot;
            SaveBase_BuildSlot(s);
            SaveBase_BuildData(s);
            s->step = 100;
            break;
        case 1:
            if (SaveBase_WriteHeader(s, hdr) != 1) {
                s->step = 2;
            }
            break;
        case 2:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            s->step = 3;
            break;
        case 3:
            if (SysCard_Write(gSysCard, SaveBase_DataOffset(s, s->curSlot), s->data, s->dataSize) != 1) {
                s->step = 4;
            }
            break;
        case 4:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            SaveBase_SetState(s, 8);
            break;
        default:
            if (!s->WriteBackup(hdr)) {
                s->step = 1;
            }
            break;
    }
}

}
