#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003SdVec;

typedef struct {
    s32 m[9];
    Ov003SdVec t;
} Ov003SdMtx43;

typedef struct {
    u8 unk_00[0x24];
    u8 rob[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov003SdVec pos;
    u8 mtx[0x24];
    u8 unk_a8[0xe];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be;
    u8 unk_bf[3];
    u16 unk_c2;
} Ov003SdModel;

typedef struct {
    Ov003SdMtx43 mtx[2];
    u8 idx[2];
    u16 unk_62[2];
    u8 unk_66[2];
    Ov003SdModel *sub[2];
} Ov003SdParts;

typedef struct {
    u8 unk_00[0x18];
    u8 unk_18_0 : 1;
    u8 unk_19[7];
    u8 mtx[0x24];
} Ov003SdS4c;

typedef struct {
    u16 unk_00;
} Ov003SdS50;

typedef struct {
    u8 unk_00[0x74];
    s32 unk_74;
    u8 unk_78[0xc];
    s32 unk_84;
} Ov003SdUnit;

typedef struct {
    u8 unk_00[0x1c];
    u16 unk_1c;
    u8 unk_1e[2];
    u8 mtx[0x24];
    Ov003SdVec unk_44;
} Ov003SdTgt;

typedef struct {
    u8 unk_00[0x4c];
    Ov003SdTgt *unk_4c;
} Ov003SdObj;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    void *unk_d4;
    u8 unk_d8[0x20];
    s32 unk_f8;
    u8 unk_fc[4];
    s32 unk_100;
} Ov003SdGame;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x12];
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003SdModel *model;
    u8 unk_3c[0x10];
    Ov003SdS4c *unk_4c;
    Ov003SdS50 *unk_50;
    u8 unk_54[8];
    void *unk_5c;
    u8 unk_60[8];
    s32 unk_68;
    u8 unk_6c[4];
    Ov003SdVec pos;
    u16 rot[3];
    u8 unk_82[0x11];
    u8 unk_93_0 : 1;
    u8 unk_94[0x3c];
    Ov003SdParts *parts;
    u8 unk_d4[0x16];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 3;
    u16 unk_ea_9 : 1;
    u16 unk_ea_10 : 3;
    u16 unk_ea_13 : 1;
    u16 unk_ea_14 : 1;
} Ov003Sd;

extern "C" {

extern void *data_ov000_021ccd64;
extern Ov003SdGame *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern Ov003SdUnit *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov003SdObj *func_ov000_0218e640(void *mgr, u16 id);
extern s32 FX_Div(s32 a, s32 b);
extern void NNS_G3dRenderObjSetInitFunc(void *rob, void *func);
extern void func_ov003_021d0c04(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MI_Copy48B(const void *src, void *dst);
extern u16 func_ov000_0218cea4(Ov003Sd *self);
extern u16 func_ov000_021903b4(Ov003SdModel *m);
extern void func_01ffc9fc(Ov003SdVec *out, Ov003SdVec *in, u16 ang);
extern void VEC_Add(Ov003SdVec *a, Ov003SdVec *b, Ov003SdVec *dst);
extern void func_ov000_021bd7a0(void *p);

}

static inline void Ov003Sd_SetSqrtImm64(u64 param) {
    *(volatile u64 *)0x040002b8 = param;
}

static inline void Ov003Sd_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    Ov003Sd_SetSqrtImm64(param);
}

static inline void Ov003Sd_WaitSqrt(void) {
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
}

static inline u32 Ov003Sd_GetSqrtResult32(void) {
    return *(volatile u32 *)0x040002b4;
}

static inline s32 Ov003Sd_Dist(s64 sq) {
    Ov003Sd_SetSqrt64((u64)(sq << 2));
    Ov003Sd_WaitSqrt();
    return (s32)(Ov003Sd_GetSqrtResult32() + 1) >> 1;
}

static inline void Ov003Sd_SetLight(Ov003SdModel *m) {
    m->unk_b6 = 0x3def;
    m->unk_b8 = 0x3def;
    m->unk_ba = 2;
    m->unk_bc = 1;
}

static inline BOOL Ov003Game_IsBusy(Ov003SdGame *g) {
    BOOL r = g->unk_90 != g->unk_94;
    return r;
}

static inline BOOL Ov003Game_IsIdle(Ov003SdGame *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003SdGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003SdGame *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54) ? TRUE : FALSE;
}

static inline Ov003SdObj *Ov003Sd_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

extern "C" u16 func_ov003_021d16cc(Ov003Sd *self) {
    s32 i;
    Ov003SdModel *sub;
    u8 buf[0x24];
    Ov003SdVec v;
    Ov003SdUnit *unit;
    u8 alpha;
    u16 r;
    Ov003SdMtx43 *mt;
    if (self->unk_50 != NULL && self->unk_50->unk_00 == 0 && !self->unk_ea_9) {
        Ov003Sd_SetLight(self->model);
        if (self->parts != NULL && self->unk_ea_3) {
            s32 j;
            for (j = 0; j < 2; j++) {
                sub = self->parts->sub[j];
                if (sub != NULL) {
                    Ov003Sd_SetLight(sub);
                }
            }
        }
    }
    alpha = 0x1f;
    unit = NULL;
    if (!self->unk_ea_14) {
        unit = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    }
    if (unit != NULL) {
        Ov003SdGame *g = data_ov000_021ccd54;
        s32 dx = self->pos.x - g->unk_f8;
        s32 dz = self->pos.z - g->unk_100;
        s64 sq = (s64)dx * dx;
        s32 dist;
        s32 f;
        sq += (s64)dz * dz;
        dist = Ov003Sd_Dist(sq);
        f = 0x1000;
        if (dist > unit->unk_84) {
            if (dist >= unit->unk_74) {
                f = 0;
            } else {
                f -= FX_Div(dist - unit->unk_84, unit->unk_74 - unit->unk_84);
            }
        }
        if (f == 0) {
            alpha = 0;
        } else if (f < 0x1000) {
            alpha = (f * 31) >> 12;
        }
    }
    if (self->parts != NULL && self->unk_ea_3) {
        for (i = 0; i < 2; i++) {
            if (self->parts->idx[i] != 0xff) {
                Ov003SdModel *m;
                self->model->unk_50 = self->parts;
                m = self->model;
                NNS_G3dRenderObjSetInitFunc(m->rob, (void *)func_ov003_021d0c04);
                m->unk_c2 |= 0x20;
                self->model->unk_c2 |= 0x100;
                break;
            }
        }
    }
    r = FALSE;
    {
        Ov003SdS4c *s = self->unk_4c;
        if (s != NULL && s->unk_18_0) {
            MI_Copy36B(s->mtx, buf);
            MI_Copy36B(buf, self->model->mtx);
            self->unk_93_0 = 1;
        }
    }
    if (alpha == 0x1f) {
        r = func_ov000_0218cea4(self);
    } else if (alpha != 0) {
        u8 old = self->model->unk_be;
        if (old > alpha) {
            self->model->unk_be = alpha;
        }
        r = func_ov000_0218cea4(self);
        self->model->unk_be = old;
    }
    if (self->parts != NULL && self->unk_ea_3) {
        for (i = 0; i < 2; i++) {
            if (r && (sub = self->parts->sub[i]) != NULL) {
                mt = &self->parts->mtx[i];
                MI_Copy36B(mt, sub->mtx);
                sub->pos.x = mt->t.x;
                sub->pos.y = mt->t.y;
                sub->pos.z = mt->t.z;
                if (alpha == 0x1f) {
                    func_ov000_021903b4(sub);
                } else if (alpha != 0) {
                    u8 old = sub->unk_be;
                    if (old > alpha) {
                        sub->unk_be = alpha;
                    }
                    r = func_ov000_021903b4(sub);
                    sub->unk_be = old;
                }
            } else if (self->parts->unk_62[i] != 0xffff) {
                Ov003SdObj *o = Ov003Sd_FindObj(self->parts->unk_62[i]);
                if (o != NULL && (sub = (Ov003SdModel *)o->unk_4c) != NULL) {
                    ((Ov003SdTgt *)sub)->unk_1c = self->unk_0c;
                    if (r) {
                        MI_Copy48B(&self->parts->mtx[i], ((Ov003SdTgt *)sub)->mtx);
                    } else {
                        v.y = self->unk_68 >> 1;
                        v.x = 0xccd;
                        v.z = 0xccd;
                        func_01ffc9fc(&v, &v, self->rot[1]);
                        VEC_Add(&v, &self->pos, &v);
                        ((Ov003SdTgt *)sub)->unk_44 = v;
                    }
                }
            }
        }
    }
    if (r && self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    self->unk_ea_13 = r;
    return r;
}
