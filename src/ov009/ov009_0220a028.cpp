#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);
extern void func_ov000_0219864c(ActorSub48 *p, VecFx32 *a, u16 *b);

void Ov009ActVt_02217390_Start(Ov009ActVt_02217390 *self) {
    Ov003Actor *a;
    ActorSub44 *s44;
    func_ov003_021d112c(self);
    self->unk_ea_6 = 1;
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
    }
    self->unk_f4 = self->rot_y;
    self->unk_f8 = self->pos;
    self->unk_b8 = self->pos;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    self->unk_f2 = 0;
    self->unk_f0 = 0;
    if (self->unk_1a == 1) {
        self->unk_b6 = Rand_UpTo(0x3c) + 0x3c;
    }
    if (self->hit != NULL) {
        self->hit->unk_48 = self->radius << 1;
        func_ov000_0219864c(self->hit, 0, 0);
    }
    func_ov000_02198360(self->fsm, 0x20, 0);
    self->model->visible = 0;
    FLD(u8, self, 0x93) |= 0x80;
}

struct Ov009RotS {
    u16 x;
    u16 y;
    u16 z;
};

extern void func_01ffc9fc(VecFx32 *out, VecFx32 *a, u16 b);
extern BOOL func_01ffc624(const VecFx32 *a, const VecFx32 *b, Ov009RotS *r, s32 c, s32 d);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);

static inline void Ov009_CountDown(Ov009ActVt_02217390 *self) {
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 == 0) {
        self->unk_b4++;
    }
}

static inline BOOL Ov009_Skip(u8 st, u32 f) {
    BOOL flag = FALSE;
    if (st != 0x15 && st != 9 && (f & 0x20000000)) {
        if (!(f & 0x400)) {
            flag = TRUE;
        }
        if (st == 0x13) {
            flag = TRUE;
        }
        if (st == 4) {
            flag = TRUE;
        }
    }
    return flag;
}

void Ov009ActVt_02217390_Update(Ov009ActVt_02217390 *self, u8 st) {
    VecFx32 v;
    Ov009RotS r;
    ActorSub40 *s;
    s32 z;
    s32 y;
    if (!Ov009_GameIdle() || (st = (s = self->fsm)->current) == 0x20) {
        return;
    }
    u32 f = self->hit->unk_50;
    BOOL flag = Ov009_Skip(st, f);
    if (flag) {
        s->flags |= 0x200000;
        func_02049a48(data_02097e4c, 0x6c, -1, -1, -1);
        return;
    }
    Ov003Actor *pl = Actor_GetTarget(self);
    if (pl == NULL) {
        return;
    }
    {
        ActorSub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    v = self->unk_b8;
    switch (self->unk_1a) {
    case 0:
        switch (self->unk_b4) {
        case 0:
            Ov009_CountDown(self);
            break;
        case 1:
            if ((f & 0x40000000) || Hit_DiffInSphere(&self->pos, &v, self->radius + 0xc00)) {
                {
                    s32 z = Rand_PlusMinus(0x800) + 0x2400;
                    v.x = 0;
                    v.y = 0;
                    v.z = z;
                }
                func_01ffc9fc(&v, &v, (u16)(self->unk_f4 - 0x4000));
                VEC_Add(&v, &self->unk_f8, &v);
                self->unk_b8 = v;
                self->unk_b6 = Rand_UpTo(0x1e) + 0x14;
                self->unk_b4 = 10;
            } else {
                self->fsm->flags |= 4;
            }
            break;
        case 10:
            Ov009_CountDown(self);
            break;
        case 11:
            if ((f & 0x40000000) || Hit_DiffInSphere(&self->pos, &v, self->radius + 0xc00)) {
                {
                    s32 z = Rand_PlusMinus(0x800) + 0x2400;
                    v.x = 0;
                    v.y = 0;
                    v.z = z;
                }
                func_01ffc9fc(&v, &v, (u16)(self->unk_f4 + 0x4000));
                VEC_Add(&v, &self->unk_f8, &v);
                self->unk_b8 = v;
                self->unk_b6 = Rand_UpTo(0x1e) + 0x14;
                self->unk_b4 = 0;
            } else {
                self->fsm->flags |= 4;
            }
            break;
        }
        if ((u8)(st + 0xff) > 1) {
            return;
        }
        {
            u16 ry = self->unk_f4;
            r.x = 0x4000;
            r.y = ry;
            r.z = 0;
        }
        if (!func_01ffc624(&pl->pos, &self->pos, &r, pl->radius + 0x1800, 0x6000)) {
            return;
        }
        self->fsm->flags |= 0x8000;
        break;
    case 1:
        if (st != 1) {
            return;
        }
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 != 0) {
            return;
        }
        {
            s32 t = self->pos.z;
            z = t;
            y = self->pos.y;
            s32 px = pl->pos.x;
            v.x = px + Rand_PlusMinus(0x3000);
            v.y = y;
            v.z = z;
            if (v.x < -0xa000) {
                v.x = -0xa000;
            }
            if (v.x > 0xa800) {
                v.x = 0xa800;
            }
            self->pos = v;
        }
        self->unk_b6 = Rand_UpTo(0x1e) + 0x3c;
        func_ov000_02198360(self->fsm, 0x20, 0);
        break;
    }
}


}
