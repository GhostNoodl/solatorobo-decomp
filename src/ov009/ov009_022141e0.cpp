#include "ov009/ov009.h"

extern "C" {

extern Ov009Obj *Target_Get(void *p);
extern s32 func_ov000_0219a510(Ov009Obj *self, u16 mask, const Ov009Vec *pos, s32 r, s32 b, void **out);
extern Ov009Actor *func_ov000_021985c0(void *p);
extern void func_ov003_021f0c60(Ov009Obj *self, s32 a);
extern void func_ov000_02196060(Ov009Obj *self);

void func_ov009_022141e0(Ov009ActorEx *self) {
    void *list[32];
    s32 n;
    s32 r;
    u16 grp;
    s32 i;
    if (Target_Get(self->unk_4c) == NULL) {
        return;
    }
    if (self->unk_40->state == 1) {
        Actor_Move((Actor *)self, 0);
        if (self->unk_48 != NULL) {
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
            if (self->unk_48->unk_50 & 0x20000000) {
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        }
        r = self->unk_64 + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->unk_48->unk_44 = r;
        grp = Target_Get(self->unk_4c)->id & 0xf000;
        n = func_ov000_0219a510(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov009Actor *a;
                if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
                    Ov009Target *p = a->unk_4c;
                    if (p == NULL || grp != (u16)(p->target & 0xf000)) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        return;
                    }
                }
            }
        }
    } else {
        func_ov000_02196060(self);
    }
}

}
