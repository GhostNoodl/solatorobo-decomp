#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"


extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void func_ov000_0215ce8c(void *self, s32 id);

void func_ov000_02151018(Lo021ca9c4 *self) {
    switch (self->unk_08) {
    case 13: {
        s32 n;
        VObj *o = self->unk_58;
        if (o != NULL) {
            BOOL busy = LFLD(s32, self->unk_50, 0x74) != 0 ? TRUE : FALSE;
            if (!busy && !o->vfunc_1c()) {
                s32 id;
                LO_FREE_V(self, 0x58);
                id = self->unk_5c;
                if (id != 0xffff) {
                    if (self->unk_58 == NULL) {
                        VObj *p = (VObj *)Heap_Alloc(0xe8);
                        if (p) {
                            VOBJ_SET_VTABLE(p, data_ov000_021cac60);
                            p->vfunc_28();
                            VOBJ_SET_VTABLE(p, data_ov000_021cad50);
                            p->vfunc_28();
                        }
                        self->unk_58 = p;
                    }
                    LFLD(s32, self->unk_58, 0x1c) = 4;
                    self->unk_58->vfunc_08();
                    func_ov000_0215ce8c(self->unk_58, id);
                    LFLD(s16, self->unk_58, 0x68) = -0x1666;
                    self->unk_58->vfunc_70();
                    self->unk_5c = 0xffff;
                }
            }
        }
        n = 0;
        if (self->unk_4c != NULL && self->unk_4c->vfunc_1c()) {
            n++;
        }
        if (self->unk_50 != NULL && self->unk_50->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
        break;
    }
    case 10:
        if (self->vfunc_54()) {
            if (self->unk_4c != NULL) {
                LFLD(u32, self->unk_4c, 0xc) |= 2;
            }
            if (self->unk_50 != NULL) {
                LFLD(u32, self->unk_50, 0xc) |= 2;
            }
            if (self->unk_58 != NULL) {
                LFLD(u32, self->unk_58, 0xc) |= 2;
            }
        }
        break;
    }
    if (self->unk_50 != NULL) {
        LFLD(u32, self->unk_50, 0xc) |= 4;
    }
}
}
