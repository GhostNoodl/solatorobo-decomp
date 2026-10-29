#include "nitro/fx.h"
#include "nitro/std.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Flags021c194c;

typedef struct {
    Flags021c194c flags;
    s32 state;
    u8 *obj;
    u8 *model;
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    u8 pad22[0x16];
    VecFx32 target;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
} Self021c194c;

extern "C" {

extern char *data_ov000_021cc8a0[2];
extern char data_ov000_021cc92d[];
void *func_0203dd9c(u32 size);
u8 *func_ov000_0218e9c4(void *p);
u8 *func_ov000_0218fe1c(void *p);
BOOL func_ov000_0218f110(u8 *o);
BOOL func_ov000_0218ffdc(u8 *m, u8 *o, s32 a, s32 b);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02190a80(void *a, s32 b);
void func_02040578(u16 *out, VecFx32 *dir);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline void SetNamesA021c194c(u8 *o) {
    char **names = data_ov000_021cc8a0;
    char *n0 = names[0];
    char *n1 = names[1];
    STD_CopyString((char *)o + 0x10, n0);
    STD_CopyString((char *)o + 0x30, n1);
    o[3] |= 2;
}

static inline void SetNamesB021c194c(u8 *o) {
    char **names = data_ov000_021cc8a0;
    char *n0 = names[0];
    char *n1 = names[1];
    STD_CopyString((char *)o + 0x4c, n0);
    STD_CopyString((char *)o + 0x6c, n1);
    o[3] |= 4;
}

static inline u8 *GetObj021c194c(Self021c194c *s) {
    return s->obj;
}

static inline BOOL Ready021c194c(u8 *o) {
    BOOL r = TRUE;
    if (o != NULL && LFLD(s16, o, 0) >= 0) {
        if (!func_ov000_0218f110(o)) {
            r = FALSE;
        }
    }
    return r;
}

#define SIN021c194c(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS021c194c(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov000_021c194c(Self021c194c *self, BOOL flag, u8 *p) {
    MtxFx33 m_0;
    VecFx32 d4;
    VecFx32 d;
    MtxFx33 tmp;
    u16 a4[3];
    u16 ang[3];
    switch (self->state) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
    case 9:
        break;
    case 1: {
        p = (u8 *)func_0203dd9c(0x138);
        if (p != NULL) {
            p = func_ov000_0218e9c4(p);
        }
        self->obj = p;
        SetNamesA021c194c(p);
        SetNamesB021c194c(GetObj021c194c(self));
        LFLD(s16, self->obj, 0) = 0;
        self->state = 7;
    }
    case 7: {
        u8 *m_1;
        if (!Ready021c194c(self->obj)) {
            return;
        }
        m_1 = (u8 *)func_0203dd9c(0xe8);
        if (m_1 != NULL) {
            m_1 = func_ov000_0218fe1c(m_1);
        }
        self->model = m_1;
        func_ov000_0218ffdc(m_1, GetObj021c194c(self), 0, 1);
        func_ov000_02190cb0(self->model, data_ov000_021cc92d, 0, 1);
        LFLD(u16, self->model, 0xb4) = 0;
        func_ov000_021915a0(self->model);
        m_1 = self->model;
        LFLD(s32, m_1, 0xa8) = 0xb33;
        LFLD(s32, m_1, 0xac) = 0xb33;
        LFLD(s32, m_1, 0xb0) = 0xb33;
        self->state = 4;
    }
    case 4: {
        self->unk_44 = 0;
        self->unk_48 = 0;
        self->unk_4c = 0xf000;
        self->unk_50 = 0x1000;
        if (!self->flags.b1) {
            return;
        }
        self->flags.b0 = 1;
        d4.x = self->target.x - self->pos.x;
        d4.y = self->target.y - self->pos.y;
        d4.z = self->target.z - self->pos.z;
        VEC_Normalize(&d4, &d4);
        func_02040578(a4, &d4);
        self->rx = a4[0];
        self->ry = -a4[1];
        self->state = 10;
    }
    case 10: {
        BOOL set;
        u16 rz;
        s32 t;
        u16 ry;
        u16 rx;
        if (self->model == NULL) {
            return;
        }
        flag = FALSE;
        if (!self->flags.b1) {
            self->unk_44 -= 0x1000;
        } else {
            self->unk_44 += 0x1000;
        }
        t = FX_Div(self->unk_44, 0xf000);
        if (t >= 0x1000) {
            self->unk_44 = 0xf000;
            t = 0x1000;
        } else if (t <= 0) {
            self->unk_44 = 0;
            self->unk_48 = 0;
            self->state = 4;
            return;
        } else if (self->flags.b1) {
            flag = TRUE;
        }
        self->unk_48 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        if (!flag) {
            if (!self->flags.b0) {
                self->unk_4c -= 0x1000;
            } else {
                self->unk_4c += 0x1000;
            }
            t = FX_Div(self->unk_4c, 0xf000);
            if (t >= 0x1000) {
                if (self->unk_4c > 0x78000) {
                    self->flags.b0 = 0;
                }
                t = 0x1000;
            } else if (t <= 0) {
                if (self->unk_4c < -0x78000) {
                    self->flags.b0 = 1;
                }
                t = 0;
            }
            self->unk_50 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        }
        d.x = self->target.x - self->pos.x;
        d.y = self->target.y - self->pos.y;
        d.z = self->target.z - self->pos.z;
        VEC_Normalize(&d, &d);
        func_02040578(ang, &d);
        self->rx = func_01ffc128(ang[0], self->rx, 0x266, 1, 0x8000);
        self->ry = func_01ffc128(-ang[1], self->ry, 0x266, 1, 0x8000);
        ry = self->ry;
        rz = self->rz;
        rx = self->rx;
        set = FALSE;
        MTX_Identity33_(&m_0);
        if (ry != 0) {
            MTX_RotY33_(&m_0, SIN021c194c(ry), COS021c194c(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&tmp, SIN021c194c(rx), COS021c194c(rx));
                MTX_Concat33(&tmp, &m_0, &m_0);
            } else {
                MTX_RotX33_(&m_0, SIN021c194c(rx), COS021c194c(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&tmp, SIN021c194c(rz), COS021c194c(rz));
                MTX_Concat33(&tmp, &m_0, &m_0);
            } else {
                MTX_RotZ33_(&m_0, SIN021c194c(rz), COS021c194c(rz));
            }
        }
        MI_Copy36B(&m_0, self->model + 0x84);
        {
            u8 *md = self->model;
            LFLD(s32, md, 0x78) = self->pos.x;
            LFLD(s32, md, 0x7c) = self->pos.y;
            LFLD(s32, md, 0x80) = self->pos.z;
        }
        func_ov000_02190a80(self->model, 0x1000);
        break;
    }
    }
}

}
