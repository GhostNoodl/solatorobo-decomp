#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u16 st;
    u16 timer;
} State021b08ec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot021b08ec;

extern "C" {

void func_ov000_021b0db0(void *self, s32 id);

void func_ov000_021b08d8(void *self) {
    func_ov000_021b0db0(self, 0x2cd);
}

extern void *data_02097e4c;
extern u8 *data_ov000_021ccd30;
extern VecFx32 data_ov000_021ca024;
extern u8 data_ov000_021ca2a8[];
extern u8 data_ov000_021ca2e4[];
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u16 ang);
void *func_ov000_0219be1c(s32 kind, VecFx32 *pos, void *rot, u16 a, u16 b);
void func_0204a028(void *a, s32 b, void *c, s32 d);
void func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov000_02198360(void *s, s32 a, s32 b);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);
VObj *func_02065f88(s32 id, VecFx32 *pos);

static inline void SetPal(u8 *sub) {
    LFLD(u16, sub, 0xb6) = 0x73ea;
    LFLD(u16, sub, 0xb8) = 0x7ffc;
    LFLD(u16, sub, 0xba) = 0x15;
    LFLD(u16, sub, 0xbc) = 0x14;
}

void func_ov000_021b08ec(u8 *self) {
    State021b08ec *s;
    s32 id;
    switch (LFLD(State021b08ec *, self, 0x40)->st) {
    case 0:
        if (LFLD(u16, self, 0xb36) != 0) {
            LFLD(u16, self, 0xb36) = 1;
        }
        LFLD(s32, self, 0xb08) = 0x2cd;
        LFLD(State021b08ec *, self, 0x40)->st++;
    case 1:
        s = LFLD(State021b08ec *, self, 0x40);
        s->timer++;
        if (s->timer <= LFLD(u16, self, 0xb36)) {
            u16 t = LFLD(State021b08ec *, self, 0x40)->timer;
            VecFx32 ofs;
            u8 *p;
            if (t < 0xc) {
                break;
            }
            if (t == 0xc) {
                func_0204a028(data_02097e4c, 0x5b, self + 0x70, 2);
            } else if (t == 0x23) {
                func_0204a028(data_02097e4c, 0x44, self + 0x70, 2);
                func_02049f44(data_02097e4c, 0x78, self + 0x70, 0);
                SetPal(LFLD(u8 *, self, 0x38));
            } else if (t >= 0x41) {
                func_02049f44(data_02097e4c, 0x36, self + 0x70, 0);
                SetPal(LFLD(u8 *, self, 0x38));
                LFLD(State021b08ec *, self, 0x40)->timer = 0x23;
            }
            ofs.x = 0;
            ofs.y = 0xc00;
            ofs.z = 0;
            if (t > 0x23) {
                t = 0x23;
            }
            p = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
            if (p != NULL && LFLD(void *, p, 0x70) != NULL) {
                func_ov000_02168e18(LFLD(void *, p, 0x70), t, 0x23, &ofs);
            }
            LFLD(s32, self, 0xb08) = 0x166;
        } else {
            s32 kind;
            u8 *tbl;
            s32 ang;
            u16 tm;
            VecFx32 pos;
            Rot021b08ec rot;
            VObj *o;
            kind = 0x4831;
            tbl = data_ov000_021ca2a8;
            ang = 0x7b;
            s = LFLD(State021b08ec *, self, 0x40);
            tm = s->timer;
            {
                u16 nt = 0xa;
                if (tm >= 0x23) {
                    nt = 0x28;
                    kind++;
                    tbl = data_ov000_021ca2e4;
                    ang = 0xa4;
                }
                s->timer = nt;
            }
            func_01ffc9fc(&pos, &data_ov000_021ca024, LFLD(u16, self, 0x7e));
            VEC_Add(&pos, (VecFx32 *)(self + 0xaf0), &pos);
            rot.x = ((-0x6800 - LFLD(s32, self, 0xaf4)) >> 5) + 0xfa00;
            rot.y = 0x8000;
            rot.z = 0;
            o = (VObj *)func_ov000_0219be1c(kind, &pos, &rot, LFLD(u16, self, 0xc), 0xffff);
            if (o != NULL) {
                VObj *e;
                LFLD(u8 *, o, 0x60) = tbl;
                if (LFLD(u8 *, o, 0x4c) != NULL) {
                    LFLD(u8, LFLD(u8 *, o, 0x4c), 0x18) |= 0x40;
                }
                e = func_02065f88(0x68, &pos);
                LFLD(s32, self, 0xb48) = LFLD(s32, e, 0x24);
                LFLD(u16, self, 0xb5e) = ang;
                LFLD(s32, self, 0xb4c) = 0;
                LFLD(s32, self, 0xb50) = 0x3400;
                LFLD(s32, self, 0xb54) = 0x3000;
                LFLD(u16, self, 0xb58) = 0xc000;
                LFLD(u16, self, 0xb5a) = 0;
                LFLD(u16, self, 0xb5c) = 0;
                LFLD(u8, e, 0x29) = 1;
                e->vfunc_0c(0x666);
            }
            LFLD(State021b08ec *, self, 0x40)->st++;
        }
        break;
    case 2: {
        s = LFLD(State021b08ec *, self, 0x40);
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            if (LFLD(u16, self, 0xb36) != 0) {
                LFLD(State021b08ec *, self, 0x40)->st = 0;
            } else {
                func_ov000_02198360(LFLD(State021b08ec *, self, 0x40), 1, 0);
            }
        }
        break;
    }
    }
    id = 0;
    if (LFLD(u16, self, 0xb68) & 0xf0) {
        id = LFLD(s32, self, 0xb08);
    }
    func_ov000_021b0db0(self, id);
}

}
