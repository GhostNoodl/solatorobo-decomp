#include "ov000/LoCommon.h"


extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void func_ov000_0215ce8c(void *self, s32 id);

void func_ov000_02151018(VObj *self) {
    switch (LFLD(s32, self, 8)) {
    case 13: {
        s32 n;
        VObj *o = LFLD(VObj *, self, 0x58);
        if (o != NULL) {
            BOOL busy = LFLD(s32, LFLD(VObj *, self, 0x50), 0x74) != 0 ? TRUE : FALSE;
            if (!busy && !o->vfunc_1c()) {
                s32 id;
                LO_FREE_V(self, 0x58);
                id = LFLD(s32, self, 0x5c);
                if (id != 0xffff) {
                    if (LFLD(VObj *, self, 0x58) == NULL) {
                        VObj *p = (VObj *)func_0203dd9c(0xe8);
                        if (p) {
                            VOBJ_SET_VTABLE(p, data_ov000_021cac60);
                            p->vfunc_28();
                            VOBJ_SET_VTABLE(p, data_ov000_021cad50);
                            p->vfunc_28();
                        }
                        LFLD(VObj *, self, 0x58) = p;
                    }
                    LFLD(s32, LFLD(VObj *, self, 0x58), 0x1c) = 4;
                    LFLD(VObj *, self, 0x58)->vfunc_08();
                    func_ov000_0215ce8c(LFLD(VObj *, self, 0x58), id);
                    LFLD(s16, LFLD(VObj *, self, 0x58), 0x68) = -0x1666;
                    LFLD(VObj *, self, 0x58)->vfunc_70();
                    LFLD(s32, self, 0x5c) = 0xffff;
                }
            }
        }
        n = 0;
        if (LFLD(VObj *, self, 0x4c) != NULL && LFLD(VObj *, self, 0x4c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x50) != NULL && LFLD(VObj *, self, 0x50)->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
        break;
    }
    case 10:
        if (self->vfunc_54()) {
            if (LFLD(VObj *, self, 0x4c) != NULL) {
                LFLD(u32, LFLD(VObj *, self, 0x4c), 0xc) |= 2;
            }
            if (LFLD(VObj *, self, 0x50) != NULL) {
                LFLD(u32, LFLD(VObj *, self, 0x50), 0xc) |= 2;
            }
            if (LFLD(VObj *, self, 0x58) != NULL) {
                LFLD(u32, LFLD(VObj *, self, 0x58), 0xc) |= 2;
            }
        }
        break;
    }
    if (LFLD(VObj *, self, 0x50) != NULL) {
        LFLD(u32, LFLD(VObj *, self, 0x50), 0xc) |= 4;
    }
}
}
