#include "ov000/HeapScope.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    VObj base;
    s32 unk_04_;
    s32 unk_08;
    u8 pad_0c[0x30];
    void *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    s32 unk_48;
    u16 unk_4c;
    u8 pad_4e[2];
    VObj *unk_50;
} Win02179684;

extern "C" {
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void *func_0203dd9c(u32 size);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_0204c7d0(void *p);
void func_02050f70(void *p);

void func_ov000_02179684(Win02179684 *self) {
    if (self->unk_08 == 0xd) {
        switch (self->unk_48) {
        case 0: {
            s32 busy = 0;
            if (self->unk_40 != NULL && self->unk_40->vfunc_1c()) {
                busy++;
            }
            if (self->unk_44 != NULL && self->unk_44->vfunc_1c()) {
                busy++;
            }
            if (busy != 0) {
                break;
            }
            if (self->unk_4c != 0xffff) {
                s32 ofs;
                s32 n = func_0204c08c(self->unk_3c, self->unk_4c, &ofs, 1);
                VObj *o = (VObj *)func_0203dd9c(0xb80);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, data_0208ba70);
                    func_0204c7d0(o);
                    VOBJ_SET_VTABLE(o, data_0208bbc8);
                    func_02050f70(o);
                }
                self->unk_50 = o;
                LFLD(s32, o, 0x28) = 8;
                {
                    u8 *p = (u8 *)self->unk_50;
                    LFLD(s32, p, 0xb7c) = ofs;
                    LFLD(s32, p, 0xb70) = 0;
                    LFLD(s32, p, 0xb74) = n;
                }
                LFLD(u32, self->unk_50, 0xb8) = (LFLD(u32, self->unk_50, 0xb8) & ~0xf) | 4;
                LFLD(u32, self->unk_50, 0xbc) |= 0x80;
                LFLD(u32, self->unk_50, 0x4) |= 4;
                self->unk_4c = 0xffff;
                self->unk_48 = 1;
            } else {
                self->base.vfunc_0c(0);
            }
            break;
        }
        case 1:
            if (!self->unk_50->vfunc_8c()) {
                HEAP_DELETE_VOBJ(self->unk_50);
                if (self->unk_40 != NULL) {
                    LFLD(u32, self->unk_40, 0xc) &= ~2;
                }
                if (self->unk_44 != NULL) {
                    LFLD(u32, self->unk_44, 0xc) &= ~2;
                }
                self->unk_48 = 0;
            }
            break;
        }
    }
    if (self->unk_44 != NULL) {
        LFLD(u32, self->unk_44, 0xc) |= 4;
    }
}
}
