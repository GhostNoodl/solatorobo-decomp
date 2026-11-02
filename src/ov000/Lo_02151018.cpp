#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"


extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void Obj0215c1bc_SetMsg(void *self, s32 id);

void Lo021ca9c4_PostUpdate(Lo021ca9c4 *self) {
    switch (self->state) {
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
                        self->unk_58 = (Lo021cad50 *)p;
                    }
                    self->unk_58->font = 4;
                    self->unk_58->vfunc_08();
                    Obj0215c1bc_SetMsg(self->unk_58, id);
                    self->unk_58->posZ = -0x1666;
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
                self->unk_4c->flags |= 2;
            }
            if (self->unk_50 != NULL) {
                self->unk_50->flags |= 2;
            }
            if (self->unk_58 != NULL) {
                self->unk_58->flags |= 2;
            }
        }
        break;
    }
    if (self->unk_50 != NULL) {
        self->unk_50->flags |= 4;
    }
}
}
