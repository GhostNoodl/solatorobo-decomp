#include "Main/Save/SaveBase.h"

extern "C" {

void func_0204730c(SaveBase *s) {
    u32 n;
    s->header = (SaveHeader *)func_0203de84(s->headerSize, 4);
    func_02016e28(s->header, 0, s->headerSize);
    s->data = (SaveData *)func_0203de84(s->dataSize, 4);
    func_02016e28(s->data, 0, s->dataSize);
    n = (s->tmpSize - (s->dataSize * s->slotCount + s->headerSize)) / s->dataSize;
    if (n > 0x80) {
        n = 0x80;
    }
    s->backupCount = n;
    SaveBase_SetState(s, 1);
    s->stateChanged = 0;
}

void func_020473ac(SaveBase *s, s32 state) {
    SaveBase_SetState(s, state);
}

BOOL func_020473d4(SaveBase *s) {
    switch (data_02097e44->state) {
        case 7:
        case 8:
            s->OnError();
            return TRUE;
    }
    switch (s->state) {
        case 0: break;
        case 1: s->State1(); break;
        case 2: s->State2(); break;
        case 3: s->State3(); break;
        case 4: s->State4(); break;
        case 5: s->State5(); break;
        case 6: s->State6(); break;
        case 7: s->State7(); break;
        case 8: s->State8(); break;
        case 9: s->State9(); break;
        case 10: s->State10(); break;
        case 11: s->State11(); break;
        case 12: s->State12(); break;
        case 13: s->State13(); break;
        case 14: s->State14(); break;
        case 15: s->State15(); break;
        case 16: s->State16(); break;
    }
    if (!s->stateChanged) {
        s->counter++;
        if (s->counter > 0x7ffffffe) {
            s->counter = 0x7ffffffe;
        }
    }
    s->stateChanged = 0;
    return TRUE;
}

void func_02047558(SaveBase *s) {}
void func_0204755c(SaveBase *s) {}
void func_02047560(SaveBase *s) {}
void func_02047564(SaveBase *s) {}
void func_02047568(SaveBase *s) {}
void func_0204756c(SaveBase *s) {}
void func_02047570(SaveBase *s) {}
void func_02047574(SaveBase *s) {}
void func_02047578(SaveBase *s) {}
void func_0204757c(SaveBase *s) {}

void func_02047580(SaveBase *s) {
    s->name = data_0208b5fd;
    s->formatted = 0;
    s->tmpBuf = NULL;
    s->tmpSize = data_02097e44->sectorSize;
    s->baseOffset = 0;
    s->state = 0;
    s->step = 0;
    s->counter = 0;
    s->stateChanged = 0;
    s->header = NULL;
    s->headerSize = 0;
    s->slotSize = 0;
    s->data = NULL;
    s->dataSize = 0;
    s->slotCount = 0;
    s->curSlot = 0;
    s->backupIdx = 0;
    s->backupStart = 0;
    s->backupCount = 0;
}

void func_020475ec(SaveBase *s) {
    if (s->tmpBuf != NULL) {
        func_0203df0c(s->tmpBuf);
        s->tmpBuf = NULL;
    }
    if (s->header != NULL) {
        func_0203df0c(s->header);
        s->header = NULL;
    }
    if (s->data != NULL) {
        func_0203df0c(s->data);
        s->data = NULL;
    }
    SysCard_Reset(data_02097e44);
}

void func_0204768c(SaveBase *s, void *dst, u32 size) {}
void func_02047690(SaveBase *s, void *dst, u32 size) {}

BOOL func_02047694(SaveBase *s) {
    SaveSlot *slot;
    u8 cks;
    u8 x;
    const u8 *p;
    u32 i;
    u32 n;
    slot = SaveBase_GetSlot(s, s->curSlot);
    if (slot->size != s->slotSize || (slot->flags & 2)) {
        return FALSE;
    }
    n = s->slotSize - 1;
    if (n != 0) {
        BOOL ok;
        x = 0;
        p = (const u8 *)slot + 1;
        cks = slot->checksum;
        for (i = 0; i < n; i++) {
            x ^= p[i];
        }
        ok = (x ^ cks) == 0;
        if (!ok) {
            return FALSE;
        }
    }
    return TRUE;
}

}
