#include "ov002/ov002.h"

extern "C" {

// Ov002ResNames (ov002.h); hdExt/pic/cepct read as [n] here: as a struct the cepct load is
// scheduled after the num stores (24 lines), as an incomplete array before them, like the ROM.
// Round dtD: as six separate globals merged into ov002_021ef150.cpp the schedule is the ROM's,
// but the FX_Div-initialised scale then goes to .bss, so the .data layout cannot be kept.
extern void *data_ov002_021ef5ac[];


void func_ov002_021d36b8(void *self, s32 n) {
    char num[4];
    char buf[0x20];
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0xc4, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558((Model *)p);
                    func_02041278((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                FIELD(self, 0xc4, void *) = NULL;
            }
        }
        HEAP_POP(saved);
    }
    if (FIELD(self, 0xc8, VObject *) == NULL) {
        VObject *p = (VObject *)Heap_Alloc(0x4c);
        if (p != NULL) {
            *(VFunc **)p = (VFunc *)data_0208b318;
            p->v0x8();
        }
        FIELD(self, 0xc8, VObject *) = p;
    } else {
        FIELD(self, 0xc8, VObject *)->v0xc();
    }
    FIELD(FIELD(self, 0xc8, void *), 0x44, s32) = 2;
    num[0] = n / 10 + '0';
    num[1] = n % 10 + '0';
    num[2] = 0;
    STD_CopyString(buf, (char *)data_ov002_021ef5ac[5]);
    STD_ConcatenateString(buf, num);
    FIELD(self, 0xc8, VObject *)->v0x24(data_ov002_021ef5ac[2], buf);
    FIELD(self, 0xcc, s32) = n;
}

}
