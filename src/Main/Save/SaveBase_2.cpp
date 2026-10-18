#include "Main/Save/SaveBase.h"

extern "C" {

#ifdef NONMATCHING
BOOL func_02047724(SaveBase *s) {
    u32 slotSize;
    u8 *p;
    SaveData *data;
    u8 *slot;
    u32 i;
    u32 n;
    slotSize = s->slotSize;
    data = s->data;
    slot = (u8 *)SaveBase_GetSlot(s, s->curSlot);
    if (data->size != s->dataSize || (data->slot.flags & 2)) {
        return FALSE;
    }
    p = (u8 *)&data->slot;
    for (i = 0; i < slotSize; i++) {
        if (*p != *slot) {
            return FALSE;
        }
        p++;
        slot++;
    }
    n = s->dataSize - (slotSize + 4);
    if (n != 0) {
        u8 cks;
        u8 x;
        const u8 *q;
        BOOL ok;
        x = 0;
        q = (const u8 *)data + (s->dataSize - n);
        cks = data->checksum;
        for (i = 0; i < n; i++) {
            x ^= q[i];
        }
        ok = (x ^ cks) == 0;
        if (!ok) {
            return FALSE;
        }
    }
    return TRUE;
}
#endif

void func_020477fc(SaveBase *s, void *src, u32 size) {}

void func_02047800(SaveBase *s, SaveHeader *hdr) {
    func_02016e28(hdr, 0, s->headerSize);
    func_0201e520(hdr->magic, s->name);
    hdr->curSlot = 0xff;
    hdr->backupIdx = 0xff;
}

#ifdef NONMATCHING
void func_02047838(SaveBase *s) {
    SaveSlot *slot;
    u8 cks;
    const u8 *p;
    u8 x;
    s32 i;
    u32 j;
    u32 n;
    BOOL ok;
    SaveHeader *hdr = s->header;
    switch (s->step) {
        case 0:
            if (SaveBase_ReadHeader(s, hdr) != 1) {
                s->step++;
            }
            break;
        case 1:
            if (SysCard_IsBusy()) {
                return;
            }
            SysCard_EndAccess();
            s->step++;
            break;
        case 2:
            if (func_0201e7b0(hdr->magic, s->name) == 0) {
                for (i = 0; i < s->slotCount; i++) {
                    slot = SaveBase_GetSlot(s, i);
                    cks = slot->checksum;
                    if (cks != 0 || (slot->flags & 1)) {
                        n = s->slotSize - 1;
                        x = 0;
                        p = (const u8 *)slot + 1;
                        for (j = 0; j < n; j++) {
                            x ^= p[j];
                        }
                        ok = (x ^ cks) == 0;
                        if (!ok) {
                            slot->flags |= 2;
                        }
                    }
                }
            } else {
                s->formatted = 1;
                s->InitHeader(hdr);
            }
            SaveBase_SetState(s, 3);
            break;
    }
}
#endif

}
