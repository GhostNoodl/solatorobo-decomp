#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} St021a2670;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 lock : 2;
    u32 f7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 mode : 2;
    u32 b14 : 2;
    u32 b16 : 1;
    u32 b17 : 1;
    u32 b18 : 4;
    u32 b22 : 2;
    u32 rest : 8;
} B24_021a2670;

typedef struct {
    u16 b0 : 6;
    u16 b6 : 1;
    u16 rest : 9;
} B2c_021a2670;

typedef struct {
    u8 b0 : 3;
    u8 b3 : 1;
    u8 rest : 4;
} B2a_021a2670;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} B93_021a2670;

typedef struct {
    u16 b0 : 6;
    u16 b6 : 1;
    u16 rest : 9;
} Ba4_021a2670;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern void *data_ov000_021ca030[];
extern void *data_ov000_021ca040[];
extern void *const data_ov000_021ca080[];
extern u8 data_ov000_021cc62a[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021b1dd8(void *self, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_02198360(void *st, s32 a, s32 b);
u8 *func_ov000_0218e640(void *mgr, u16 id);
u8 *func_02065f88(s32 id, void *pos);
void func_ov000_02168e18(void *a, s32 b, s32 c, VecFx32 *v);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u16 FX_Atan2(s32 x, s32 z);

static inline u8 *GetObj021a2670(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Jump021a2670(Robo021ca458 *self) {
    BOOL go = FALSE;
    if (LFLD(B24_021a2670, self, 0xb24).b1 && (LFLD(u32, self->unk_48, 0x54) & 0x400)) {
        self->unk_98 = FX_Atan2(self->unk_af0 - self->unk_70.x, self->unk_af8 - self->unk_70.z);
        self->unk_9c = 0x66;
        self->unk_a4 = 0;
        if (!LFLD(B24_021a2670, self, 0xb24).b17 || (LFLD(u32, self->unk_48, 0x50) & 0x40000000)) {
            self->unk_a0 = 0x200;
        }
        self->unk_a8 = 0x52;
        LFLD(B24_021a2670, self, 0xb24).b17 = 1;
        go = TRUE;
    }
    return go;
}

static inline void PlaySe021a2670(s32 id, void *pos) {
    if (id >= 0) {
        func_02049f44(data_02097e4c, id, pos, 0);
    }
}

void func_ov000_021a2670(Robo021ca458 *self) {
    u16 thr = 0;
    s32 kind;
    void *anm;
    switch (((St021a2670 *)self->unk_40)->state) {
    case 0: {
        LFLD(B24_021a2670, self, 0xb24).b16 = 0;
        LFLD(B24_021a2670, self, 0xb24).b17 = 0;
        LFLD(B2c_021a2670, self, 0xb2c).b6 = 0;
        self->unk_a4 = 0xc00;
        if (self->unk_9c > 0x252) {
            self->unk_9c = 0x252;
        }
        self->unk_b36 = 0;
        func_ov000_021b1fac(self, TRUE, 1);
        if (Jump021a2670(self)) {
            func_ov000_02198360(self->unk_40, 4, 0);
            return;
        }
        if (LFLD(B24_021a2670, self, 0xb24).b1) {
            thr = 6;
        }
        {
            St021a2670 *st = (St021a2670 *)self->unk_40;
            st->timer++;
            if (st->timer <= thr) {
                return;
            }
        }
        if (0) {
            return;
        }
        if ((self->unk_b1c >> 12) == 5) {
            u8 *o = GetObj021a2670(self->unk_b1c);
            u8 *p = NULL;
            if (o != NULL) {
                p = LFLD(u8 *, o, 0x4c);
            }
            if (p != NULL) {
                u8 k = p[0];
                if (k == 0xf || k == 0x11) {
                    LFLD(B24_021a2670, self, 0xb24).b22 = 1;
                }
            }
        }
        ((St021a2670 *)self->unk_40)->timer = 0;
        if (LFLD(B24_021a2670, self, 0xb24).b1 && LFLD(B24_021a2670, self, 0xb24).mode == 0 &&
            self->unk_ba4 != NULL && LFLD(Ba4_021a2670, self->unk_ba4, 6).b6 &&
            self->unk_b38 >= thr) {
            func_ov000_02190cb0(self->unk_38, data_ov000_021ca030[LFLD(B24_021a2670, self, 0xb24).lock], 0x19a, 1);
            self->unk_9c = 0;
            self->unk_a4 = 0;
            ((St021a2670 *)self->unk_40)->state++;
            self->unk_b38 = 1;
            return;
        }
        ((St021a2670 *)self->unk_40)->state = 10;
        return;
    }
    case 1: {
        St021a2670 *st = (St021a2670 *)self->unk_40;
        u16 t;
        st->timer++;
        t = st->timer;
        if (self->unk_b38 < t) {
            if (t < 0x1e) {
                ((St021a2670 *)self->unk_40)->state = 10;
                return;
            }
            func_ov000_02190cb0(self->unk_38, data_ov000_021ca040[LFLD(B24_021a2670, self, 0xb24).lock], 0x800, 0);
            LFLD(B2c_021a2670, self, 0xb2c).b6 = 1;
            func_ov000_02198360(self->unk_40, 0x16, 0);
            self->unk_b48 = 0;
            return;
        }
        if (t >= 10) {
            if ((t & 0x1f) == 10) {
                u8 *e = func_02065f88(0x646, (u8 *)self + 0x70);
                self->unk_b48 = LFLD(s32, e, 0x24);
                self->unk_b5e = 0;
                self->unk_b4c = 0;
                self->unk_b54 = 0;
                self->unk_b50 = self->unk_6c;
                self->unk_b58 = 0;
                self->unk_b5a = 0;
                self->unk_b5c = 0;
            }
            {
                u8 *g = data_ov000_021ccd30;
                VecFx32 v;
                v.x = 0;
                v.y = 0;
                v.z = 0;
                if (t > 0x1e) {
                    t = 0x1e;
                }
                g = LFLD(u8 *, g, 0x11c);
                if (g != NULL && LFLD(u8 *, g, 0x70) != NULL) {
                    func_ov000_02168e18(LFLD(u8 *, g, 0x70), t, 0x1e, &v);
                }
            }
        }
        LFLD(u16, self->unk_48, 0x9a) |= 0x20;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (LFLD(u32, self->unk_48, 0x50) & 0x20000000) {
            return;
        }
        func_ov000_02198360(self->unk_40, 4, 0);
        return;
    }
    case 10: {
        s32 snd;
        s32 lock;
        anm = data_ov000_021cc62a;
        LFLD(B2a_021a2670, self, 0xb2a).b3 = 1;
        if (LFLD(B24_021a2670, self, 0xb24).b1) {
            lock = LFLD(B24_021a2670, self, 0xb24).lock;
            anm = data_ov000_021ca080[lock];
            self->unk_a8 = 0x52;
            self->unk_a0 = 0x53f;
            kind = self->unk_b1c >> 12;
            if (kind != 5) {
                switch (lock) {
                case 1:
                    self->unk_a0 = 0x4cd;
                    break;
                case 2:
                    self->unk_a0 = 0x200;
                    break;
                }
            }
            ((St021a2670 *)self->unk_40)->timer = 9;
            snd = 7;
        } else {
            if (LFLD(u32, self->unk_48, 0x50) & 0x400) {
                self->unk_a0 = 0x31f;
                snd = 0x3c;
            } else {
                self->unk_a0 = 0x53f;
                snd = 9;
            }
            self->unk_a8 = 0x50;
            ((St021a2670 *)self->unk_40)->timer = 0xf;
        }
        func_ov000_02190cb0(self->unk_38, anm, 0x800, 0);
        PlaySe021a2670(snd, (u8 *)self + 0x70);
        if (!LFLD(B93_021a2670, self, 0x93).b4) {
            s32 se = 0x300;
            if (LFLD(u16, data_ov000_021ccd68, 0xa) & 1) {
                se = 0x304;
            }
            PlaySe021a2670(se, (u8 *)self + 0x70);
        }
        ((St021a2670 *)self->unk_40)->state++;
    }
    case 11:
        if (!LFLD(B24_021a2670, self, 0xb24).b16 && !LFLD(B24_021a2670, self, 0xb24).b17) {
            func_ov000_021b1dd8(self, self->unk_b08 + (self->unk_b08 >> 1), 0x200, 0xf00, 0x466, 1);
        } else {
            func_ov000_021b1fac(self, FALSE, 0);
        }
        if (Jump021a2670(self)) {
            func_ov000_02198360(self->unk_40, 4, 0);
            return;
        }
        if (LFLD(B24_021a2670, self, 0xb24).mode == 0) {
            if ((LFLD(u32, self->unk_48, 0x50) & 0x40000000) || LFLD(s32, self->unk_48, 0x58) != 0) {
                self->unk_9c = 0;
                LFLD(B24_021a2670, self, 0xb24).b16 = 1;
            }
        }
        {
            St021a2670 *st = (St021a2670 *)self->unk_40;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                func_ov000_02198360(self->unk_40, 4, 0);
            }
        }
        break;
    }
}
}
