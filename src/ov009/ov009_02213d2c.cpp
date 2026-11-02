#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern u8 data_ov009_022179f1[];
extern u8 data_ov009_022179b4[];
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_021911c8(void *model, s32 a);
extern void *func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void Actor_MoveToPos(Ov009Actor *self, Ov009Vec *v, s32 a);
extern s32 Rand_UpTo(s32 max);

static inline Ov009Actor *Ov009_FindActor3(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02213d2c(Ov009ActVt_02217cb0 *self) {
    Ov009Actor *t = Ov009_FindActor3(self->unk_90);
    Ov009Sub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179f1, 0x2ab, 0);
        func_ov000_021911c8(self->unk_38, 0x800);
        self->unk_40->state = 10;
        self->unk_40->timer = 3;
        break;
    case 10:
        if (self->unk_38->anim_state != 1) {
            return;
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_021911c8(self->unk_38, 0x1000);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = self->unk_b0->unk_00 << 1;
            self->unk_a8 = 0x52;
            self->unk_40->state = 0x14;
            if (self->unk_1a == 0) {
                func_02049f44(data_02097e4c, 0xd02, &self->pos, 0);
                self->unk_40->timer = 200;
            } else {
                func_02049f44(data_02097e4c, 0xe02, &self->pos, 0);
                self->unk_40->timer = 0x96;
            }
        } else {
            func_ov000_02191318(self->unk_38, 0);
        }
        break;
    case 0x14:
        self->unk_f0.x = t->pos.x;
        self->unk_f0.y = t->pos.y;
        self->unk_f0.z = t->pos.z;
        Actor_MoveToPos(self, &self->unk_f0, -0xcd);
        self->unk_9c = self->unk_b0->unk_00 << 1;
        if (self->unk_48 != NULL) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
        }
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x1000, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x15;
            self->unk_40->timer = Rand_UpTo(0xf) + 0x32;
        }
        break;
    case 0x15:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
