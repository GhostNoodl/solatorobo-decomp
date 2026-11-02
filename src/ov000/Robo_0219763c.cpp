#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 rest : 8;
} Bits0219763c;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save0219763c;

typedef struct {
    s16 snd;
    s16 fx0;
    s16 scale0;
    s16 fx1;
    s16 scale1;
    u8 a;
    u8 b;
} Ent0219763c;

extern "C" {
extern void *data_ov000_021ccd64;
extern Save0219763c *data_0214a424;
extern Ent0219763c data_ov000_021c9ecc[];
extern void *data_02097e4c;
void func_0203f364(void *a);
void func_ov000_0218bed8(void *a, s32 b, void *c);
VObj *func_02065f88(s32 a, void *b);
void func_020627a0(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);
u16 func_0206e7ec(u32 a, u32 b);
Robo021ca458 *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void MIi_CpuClear32(u32 data, void *dst, u32 size);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
void func_ov000_0218996c(u8 a, u8 b);
u8 *func_020704b4(u16 id);
void func_ov000_0219b400(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
void func_ov000_02198c8c(void *p, u16 id);

static inline void SetNibble0219763c(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble0219763c(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

struct Die0219763cSelf {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x7];
    u8 unk_17;
    u8 unk_18[0x94];
    u8 unk_ac;
    u8 unk_ad;
};

static inline void Die0219763c(VObj *obj) {
    Die0219763cSelf *self = (Die0219763cSelf *)obj;
    {
        u8 idx = self->unk_17;
        s32 row;
        if (idx != 0xff) {
            row = func_0206e7ec(self->unk_ac, self->unk_ad);
            if (row != 0xffff) {
                u8 val = 0xf;
                val |= GetNibble0219763c(row, idx) & 8;
                SetNibble0219763c(row, idx, val);
            }
        }
    }
    if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(0x63);
        {
            FieldState *pl = data_ov000_021ccd54;
            ((u8 *)pl)[0xac] = 1;
            func_ov000_02182590((u8 *)pl + 0xac);
        }
    }
    func_020627c8();
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    obj->vfunc_08();
}

static inline void Spawn0219763c(ActorEx *self, s16 id, const s16 *scale, VecFx32 *p) {
    VObj *fx = func_02065f88(id, p);
    s32 s = *scale << 4;
    if (s == 0) {
        s = self->radius + (self->radius >> 3);
    }
    fx->vfunc_0c(s);
    if (!self->unk_cc_5) {
        MIi_CpuClear32(-1, (u8 *)fx + 0x84, 0x40);
    }
}

void func_ov000_0219763c(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    s32 zero = 0;
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0: {
        u8 *t = ((u8 *)self->targetObj);
        Ent0219763c *e = (Ent0219763c *)zero;
        VecFx32 p;
        if (t != NULL) {
            if (t[2] != 1 && t[2] != 2) {
                Die0219763c(obj);
                return;
            }
            {
                u16 id = LFLD(u16, t, 6);
                if (id >= 0x14) {
                    id = 0;
                }
                e = &data_ov000_021c9ecc[id];
            }
        }
        p = *(VecFx32 *)((u8 *)self + 0x70);
        p.y += self->centerY + (self->centerY >> 1);
        if (e != NULL) {
            if (e->fx0 != -1) {
                Spawn0219763c(self, e->fx0, &e->scale0, &p);
            }
            if (e->fx1 != -1) {
                Spawn0219763c(self, e->fx1, &e->scale1, &p);
            }
            if (e->snd >= 0 && self->unk_cc_5) {
                func_02049f44(data_02097e4c, e->snd, &self->pos, 0);
            }
            if (e->a != 0 && e->b != 0) {
                func_ov000_0218996c(e->a, e->b);
            }
        }
        {
            u8 *r = func_020704b4(self->kind);
            func_ov000_0219b400((u16 *)(r + 0x20), r + 0x24, 2, &p, (u8 *)self + 0x7c, zero);
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *q = self->unk_44;
            LFLD(Bits0219763c, q, 0x22).b0 = 0;
            LFLD(Bits0219763c, q, 0x22).b1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *q;
            func_ov000_02198c8c(self->hit, 0xffff);
            q = self->hit;
            LFLD(Bits0219763c, q, 0x9a).b0 = 0;
            q->unk_9a_3 = 0;
            func_0203f364(q);
            q = self->hit;
            LFLD(Bits0219763c, q, 0x9a).b1 = 0;
            q->unk_9a_4 = 0;
        }
        if (self->hitMesh != NULL) {
            self->unk_cc_0 = 0;
        }
        self->fsm->st++;
        return;
    }
    case 1:
        s->timer++;
        if (s->timer > 5) {
            Die0219763c(obj);
            return;
        }
        if (((u8 *)self->model) != NULL) {
            self->model->alpha = 0x1f - (self->fsm->timer << 2);
        }
        return;
    }
}

}
