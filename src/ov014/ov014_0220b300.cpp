#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_0220d274(Ov014Actor *self);
extern void func_ov003_021d4fd8(Ov014Actor *self);

void func_ov014_0220b300(Ov014Actor *self) {
    func_ov014_0220d274(self);
}

void func_ov014_0220b30c(Ov014Actor *self) {
    func_ov003_021d4fd8(self);
}

void func_ov014_0220b318(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, FLD(u8 *, self, 0x4c), 0) = 0xf;
    }
    func_ov003_021d5900(self);
}


extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern char data_ov014_02217a84[];
extern void func_02065860(void *a, void *b);
extern Ov014V *func_020657b0(void *a, void *b);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_020639d4(void *e, s32 a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_021911c8(void *a, s32 b);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov003_021d6a3c(Ov014Actor *self, s32 a, s32 b, s32 c);

void func_ov014_0220b33c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        FLD(u8, self, 0xfc) = 0;
        func_02065860(data_0214a420, FLD(void *, self, 0x1dc));
        FLD(void *, self, 0x1dc) = NULL;
        func_02065860(data_0214a420, FLD(void *, self, 0x1e0));
        FLD(void *, self, 0x1e0) = NULL;
        func_02065860(data_0214a420, FLD(void *, self, 0x1e4));
        FLD(void *, self, 0x1e4) = NULL;
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a84, 0xcd, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x800);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4819, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x481d, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x481e, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x481f, 0x15);
        self->unk_40->state++;
        self->unk_40->timer = 0xf0;
        break;
    case 1: {
        Ov014Vec pos;
        Ov014Vec pos2;
        Ov014Vec p3;
        Ov014Vec p4;
        s32 t;
        s32 v;
        u8 *a;
        self->rot[1] = func_01ffc128(0, self->rot[1], self->unk_b0->unk_02, 1, 0x8000);
        t = self->unk_40->timer;
        v = 0;
        a = func_ov000_02190a30(self->unk_38, 0);
        if (FLD(s32 *, a, 0) != NULL) {
            v = *FLD(s32 *, a, 0);
        }
        if (v > 0x14000) {
            func_ov000_021911c8(self->unk_38, 0);
        }
        if (t % 90 == 0) {
            Ov014V *e;
            pos.x = self->pos.x + func_02040528(0x7000);
            pos.y = self->pos.y + func_02040498(0x5000) + 0x2000;
            pos.z = self->pos.z + 0x3000;
            e = func_02065f88(0x38a, &pos);
            {
                s32 r = func_02040498(0xccd) + 0xccd;
                e->v0c(r);
            }
        }
        if (t % 55 == 0) {
            Ov014V *e;
            pos2.x = self->pos.x + func_02040528(0x7000);
            pos2.y = self->pos.y + func_02040498(0x5000) + 0x2000;
            pos2.z = self->pos.z + 0x3000;
            e = func_02065f88(4, &pos2);
            e->v0c(func_02040498(0xccd) + 0xccd);
            func_020639d4(e, 0x56, 2);
        }
        if (t == 0x78) {
            Ov014V *e;
            p3 = self->pos;
            p3.y += 0x3800;
            e = func_02065f88(0x322, &p3);
            e->v0c(0x2e66);
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, self, 0x1f0) = FLD(s32, e, 0x24);
        }
        {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        self->unk_40->state++;
        self->unk_40->timer = 0x14a;
        p4.x = 0;
        p4.y = 0x3800;
        p4.z = 0;
        func_02065f88(0x38a, &p4)->v0c(0x3000);
        break;
    }
    case 2:
        func_ov003_021d6a3c(self, 0, 1, 1);
        self->unk_ea_6 = 1;
        self->unk_40->state++;
        self->unk_40->timer = 0x190;
        break;
    case 3: {
        Ov014V *e = func_020657b0(data_0214a420, FLD(void *, self, 0x1f0));
        Ov014Vec v;
        if (e == NULL) {
            break;
        }
        v = self->pos;
        v.y += 0x3800;
        e->v18(&v);
        break;
    }
    }
}


extern Ov014V *func_020658cc(void *mgr, s32 id);
extern void func_02063a14(void *e);
extern s32 func_02049210(s32 t, s32 from, s32 to);
extern s32 FX_Div(s32 a, s32 b);

static inline s32 Ov014b_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_0220b74c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        // The target reloads the state it just switched on.
        (*(volatile u16 *)&self->unk_40->state)++;
        self->unk_40->timer = 0x5a;
        break;
    case 1: {
        if (self->unk_40->timer == 0x59) {
            Ov014Vec p;
            Ov014V *e;
            p = self->pos;
            p.y += 0x3800;
            e = func_02065f88(0x390, &p);
            e->v14(0x2000, 0x2000, 0x2000);
            FLD(s32, e, 0xc8) = -1;
            FLD(s32, e, 0x50) = -0x1e000;
            func_020639d4(e, 0x44, 0);
            func_020639d4(e, 0x44, 0x14);
            func_020639d4(e, 0x44, 0x28);
            FLD(s32, e, 0xc8) = -2;
        }
        {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        {
            Ov014V *e = func_020658cc(data_0214a420, 0x390);
            if (e != NULL) {
                func_02063a14(e);
            }
        }
        self->unk_40->state++;
        self->unk_40->timer = 0xd2;
        break;
    }
    case 2: {
        s32 t = self->unk_40->timer;
        if (t == 0xd2) {
            Ov014Vec p;
            Ov014V *e;
            func_02065860(data_0214a420, FLD(void *, self, 0x1f0));
            p = self->pos;
            p.y += 0x3800;
            e = func_02065f88(0x391, &p);
            FLD(s32, e, 0x3c) = 0x99a;
            FLD(s32, e, 0xc8) = -2;
        } else if (t > 0xb4) {
            Ov014V *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0xd2 - self->unk_40->timer) << 12, 0x1e000);
                e->v0c(func_02049210(r, 0x1000, 0x3000));
            }
        } else if (t > 0x6e) {
            Ov014V *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0xb4 - self->unk_40->timer) << 12, 0x46000);
                e->v0c(func_02049210(r, 0x3000, 0x1e000));
            }
        } else if (t > 0x5a) {
            Ov014V *e = func_020658cc(data_0214a420, 0x391);
            if (e != NULL) {
                s32 r = FX_Div((0x6e - self->unk_40->timer) << 12, 0x14000);
                u8 a = (Ov014b_Mul64(r, -0x1f000) + 0x1f000) >> 12;
                a = a > 0x1f ? 0x1f : a;
                FLD(s32, e, 0x7c) = FX_Div(a << 12, 0x1f000);
            }
        } else {
            if (t == 0x5a) {
                Ov014V *e = func_020658cc(data_0214a420, 0x391);
                if (e != NULL) {
                    u32 saved = data_02097dd0->cur;
                    data_02097dd0->cur = data_02097dd0->def;
                    if (e != NULL) {
                        if (e != NULL) {
                            e->v04();
                        }
                    }
                    data_02097dd0->cur = saved;
                }
            }
            if (t % 30 == 0) {
                Ov014Vec p;
                Ov014V *e;
                p.x = self->pos.x + func_02040528(0x7000);
                p.y = self->pos.y + func_02040498(0x5000) + 0x2000;
                p.z = self->pos.z + 0x3000;
                e = func_02065f88(4, &p);
                {
                    s32 r = func_02040498(0xccd) + 0xccd;
                    e->v0c(r);
                }
            }
        }
        {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer != 0) {
                break;
            }
        }
        self->unk_40->state++;
        self->unk_40->timer = 0x168;
        break;
    }
    case 3: {
        Ov014Vec p;
        s32 m = self->unk_40->timer % 120;
        if (m == 0) {
            Ov014V *e;
            p.x = self->pos.x + func_02040528(0x7000);
            p.y = self->pos.y + func_02040498(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            e = func_02065f88(4, &p);
            {
                s32 r = func_02040498(0xccd) + 0xccd;
                e->v0c(r);
            }
        }
        if (m == 0x32) {
            Ov014V *e;
            s32 r = func_02040498(0xccd) + 0xccd;
            p.x = self->pos.x + func_02040528(0x7000);
            p.y = self->pos.y + func_02040498(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            func_02065f88(4, &p)->v0c(r);
            e = func_02065f88(0x6d, &p);
            e->v0c(r);
            func_020639d4(e, 0x56, 0);
        }
        if (m == 0x1e) {
            Ov014V *e;
            s32 r = func_02040498(0xccd) + 0xccd;
            p.x = self->pos.x + func_02040528(0x7000);
            p.y = self->pos.y + func_02040498(0x5000) + 0x2000;
            p.z = self->pos.z + 0x3000;
            func_02065f88(0x322, &p)->v0c(r);
            e = func_02065f88(0x320, &p);
            e->v0c(r);
            FLD(s32, e, 0x30) = -0x1e000;
            func_020639d4(e, 0x56, 0);
        }
        {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->unk_40->timer = 0x168;
            }
        }
        break;
    }
    }
}

}
