#include "Main/Save/SaveBase.h"

extern "C" {

void func_02047a20(SaveBase *s) {
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            s->tmpBuf = func_0203de84(s->tmpSize, 4);
            MI_CpuFill8(s->tmpBuf, 0, s->tmpSize);
            s->InitHeader(hdr);
            s->step = 1;
            break;
        case 1:
            if (func_02047004(data_02097e44, s->baseOffset, s->tmpBuf, s->tmpSize) != 1) {
                s->step = 2;
            }
            break;
        case 2:
            if (SysCard_IsBusy()) {
                return;
            }
            if (s->tmpBuf != NULL) {
                func_0203df0c(s->tmpBuf);
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

void func_02047c2c(SaveBase *s) {
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
            if (func_02047004(data_02097e44, SaveBase_DataOffset(s, s->curSlot), s->data, s->dataSize) != 1) {
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
