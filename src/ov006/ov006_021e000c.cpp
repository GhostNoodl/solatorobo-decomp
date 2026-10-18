#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Loader021e000c {
    void *vtbl;
    u8 ready;
    u8 unk5[0x17];
    void *unk1C;
} ov006_Loader021e000c;

typedef struct ov006_Pic021e000c {
    void *vtbl;
    u8 ready;
    u8 unk5[3];
    s32 x;
    s32 y;
    s32 z;
    void *unk14;
    ov006_Loader021e000c *unk18;
} ov006_Pic021e000c;

typedef struct ov006_Win021e000c {
    void *vtbl;
    u8 state;
    u8 unk5[3];
    int timer;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} ov006_Win021e000c;

typedef struct ov006_Eff021e000c {
    u8 unk0[0x24];
    int id;
} ov006_Eff021e000c;

typedef struct ov006_Vec021e000c {
    s32 x;
    s32 y;
    s32 z;
} ov006_Vec021e000c;

typedef struct ov006_Unk021e000c {
    void *vtbl;
    s16 state;
    s16 sub;
    int timer;
    fx32 fade;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 unk11;
    u8 unk12[2];
    int id1;
    int id2;
    ov006_Pic021e000c *unk1C;
    ov006_Win021e000c *unk20;
} ov006_Unk021e000c;

extern "C" {

extern void *data_0214a420;
VObj *func_020657b0(void *a, int id);
ov006_Eff021e000c *func_ov006_021e37d0(int type, ov006_Vec021e000c *arg);
s32 func_02049130(fx32 t, s32 a, s32 b);
BOOL func_02054f10(void *a, int b);
void func_ov006_021df44c(ov006_Win021e000c *self);

static inline void ov006_Unk021e000c_Kill(int id) {
    if (id != -1) {
        Object *o = (Object *)func_020657b0(data_0214a420, id);
        if (o != NULL) {
            void *saved = data_02097dd0->current;
            data_02097dd0->current = data_02097dd0->unk8;
            if (o != NULL) {
                if (o != NULL) {
                    o->vtbl->dtor(o);
                }
            }
            data_02097dd0->current = saved;
        }
    }
}

static inline void ov006_Pic021e000c_SetPos(ov006_Pic021e000c *p, s32 x, s32 y, s32 z) {
    p->x = x;
    p->y = y;
    p->z = z;
}

static inline void ov006_Loader021e000c_Update(ov006_Loader021e000c *self) {
    if (!self->ready && self->unk1C != NULL && func_02054f10(self->unk1C, 0xffff)) {
        self->ready = 1;
    }
}

void func_ov006_021e000c(ov006_Unk021e000c *self) {
    int zero = 0;
    if (self->state == 0) {
        return;
    }
    switch (self->state) {
    case 1: {
        ov006_Vec021e000c v;
        v.x = zero;
        v.y = -0x19a;
        v.z = -0x2000;
        self->id1 = func_ov006_021e37d0(0xc, &v)->id;
        v.x = zero;
        v.y = zero;
        v.z = -0x1666;
        self->id2 = func_ov006_021e37d0(self->unk11 + 0xc, &v)->id;
        self->unk20->b0 = 1;
        self->b1 = 0;
        self->timer = 0x1e;
        self->fade = 0x1000;
        self->state = 2;
        self->sub = zero;
    }
    case 2:
        switch (self->sub) {
        case 0:
            if (--self->timer < 0) {
                self->timer = zero;
                self->sub++;
            }
            self->fade = (self->timer << 12) / 30;
            break;
        case 1:
            if (self->unk20->state == 3) {
                self->state = 3;
                self->sub = zero;
            }
            break;
        }
        break;
    case 3:
        if (self->b1) {
            self->b1 = 0;
            self->unk20->b1 = 1;
            self->fade = zero;
            self->state = 4;
            self->sub = zero;
        }
        break;
    case 4:
        if (self->b1) {
            self->b1 = 0;
            self->b0 = 0;
            self->timer = zero;
            self->state = 5;
            self->sub = zero;
        }
        self->fade += 0xcc;
        if (self->fade > 0x1000) {
            self->fade = 0x1000;
        }
        break;
    case 5: {
        fx32 t = (self->timer << 12) / 20;
        VObj *o = func_020657b0(data_0214a420, self->id1);
        if (o != NULL) {
            o->v14(0x1000, FX_Mul(t, 0x800) + 0x1000, 0x1000);
        }
        o = func_020657b0(data_0214a420, self->id2);
        if (o != NULL) {
            o->v1C(FX_Mul(t, -0x80000), 0, *(s32 *)((u8 *)o + 0x60));
        }
        self->fade += 0xcc;
        if (self->fade > 0x1000) {
            self->fade = 0x1000;
        }
        if (++self->timer > 20) {
            self->timer = 20;
            if (self->unk20->state == 6) {
                ov006_Unk021e000c_Kill(self->id1);
                ov006_Unk021e000c_Kill(self->id2);
                self->timer = zero;
                self->state = 6;
                self->sub = zero;
            }
        }
        break;
    }
    case 6:
        if (self->b0) {
            self->b0 = 0;
            self->state = 1;
            self->sub = zero;
        }
        break;
    }
    {
        s32 x = func_02049130(self->fade, 0x46000, 0x86000);
        ov006_Pic021e000c_SetPos(self->unk1C, (u32)FX_Whole(x) << 12, -0x4a000, self->unk1C->z);
    }
    {
        ov006_Pic021e000c *p = self->unk1C;
        if (!p->ready) {
            if (p->unk14 == NULL || !func_02054f10(p->unk14, 0xffff)) {
                goto skip;
            }
            p->ready = 1;
        }
        ov006_Loader021e000c_Update(p->unk18);
    }
skip:
    func_ov006_021df44c(self->unk20);
}

}
