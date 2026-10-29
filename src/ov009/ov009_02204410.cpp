#include "ov009/ov009.h"

extern "C" {

struct Ov009Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    Ov009Vec v;
};

extern BOOL func_ov003_021d1c00(Ov009Actor *self, Ov009Msg *msg);

void func_ov009_02204410(Ov009Actor *self, Ov009Msg *msg) {
    if (msg->type == 0xe) {
        Ov009Vec *dst = (Ov009Vec *)((u8 *)self + msg->idx * 0xc + 0x10c);
        dst->x = msg->v.x;
        dst->y = msg->v.y;
        dst->z = msg->v.z;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov003_021d1c00(self, msg);
}

extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
struct Ov009AngSrc {
    u8 unk_00[0x40];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
};

extern u16 func_0204bfa8(Ov009AngSrc *p);

static inline s32 Ov009_GetAng(Ov009AngSrc *p) {
    if (p->unk_40 != 0) {
        return p->unk_44;
    }
    return func_0204bfa8(p);
}

static inline BOOL Ov009Game_IsPaused(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_02204468(Ov009Actor *self) {
    Ov009Vec v;
    Ov009V *obj;
    s32 ang;
    s32 h;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
            return;
        }
        obj = func_02065f88(0x389, &self->pos);
        obj->v0c(0x3000);
        ang = Ov009_GetAng((Ov009AngSrc *)((u8 *)data_ov000_021ccd54 + 0xf4));
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        func_01ffc9fc(&v, &v, ang);
        obj->v20(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x32) {
            h = FLD(s32, self->unk_38, 0xa8) + 0x266;
            if (h >= FLD(s32, self, 0x100)) {
                h = FLD(u32, self, 0x100);
                func_02065f88(0x69, &self->pos);
                func_02065f88(0x38a, &self->pos);
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
                self->unk_40->timer = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            {
                Ov009Vec *s = &FLD(Ov009Vec, self->unk_38, 0xa8);
                s->x = h;
                s->y = h;
                s->z = h;
            }
        }
        break;
    }
    func_ov000_0218d988(self, func_ov000_0219bf90(), 0x400);
}

}
