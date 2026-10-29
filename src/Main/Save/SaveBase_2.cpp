#include "Main/Save/SaveBase.h"

extern "C" {

void func_020477fc(SaveBase *s, void *src, u32 size) {}

void func_02047800(SaveBase *s, SaveHeader *hdr) {
    MI_CpuFill8(hdr, 0, s->headerSize);
    STD_CopyString(hdr->magic, s->name);
    hdr->curSlot = 0xff;
    hdr->backupIdx = 0xff;
}

void func_02047838(SaveBase *s) {
    SaveSlot *slot;
    s32 i;
    u8 x;
    BOOL ok;
    const u8 *p;
    u32 n;
    u32 size;
    u32 j;
    u8 cks;
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
            if (STD_CompareString(hdr->magic, s->name) == 0) {
                for (i = 0; i < s->slotCount; i++) {
                    size = s->slotSize;
                    slot = (SaveSlot *)((u8 *)s->header + (i * size + 0x14));
                    cks = slot->checksum;
                    if (cks != 0 || (slot->flags & 1)) {
                        n = size - 1;
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

}
