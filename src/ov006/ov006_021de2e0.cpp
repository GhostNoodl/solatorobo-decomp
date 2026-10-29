#include "ov006/Model.h"
#include <nitro/fx.h>

typedef struct ov006_Obj14_021de2e0 {
    u8 unk0[0x14];
    s32 x;
    s32 y;
    s32 z;
} ov006_Obj14_021de2e0;

typedef struct ov006_Obj18_021de2e0 {
    void *vtbl;
    int ready;
    u8 unk8;
    u8 unk9;
    u8 unkA[2];
    s32 x;
    s32 y;
    s32 z;
    VObj *unk18;
    void *unk1C;
} ov006_Obj18_021de2e0;

typedef struct ov006_Unk021de2e0 {
    void *vtbl;
    u8 state;
    u8 unk5[3];
    int timer;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
    u8 unk10[4];
    ov006_Obj14_021de2e0 *unk14;
    ov006_Obj18_021de2e0 *unk18;
    u32 *unk1C;
    ov006_Model *unk20;
    ov006_Model *unk24;
    VecFx32 unk28;
    void *unk34;
} ov006_Unk021de2e0;

extern "C" {

extern const char data_ov006_021ec094[];
extern const char data_ov006_021ec0a0[];
BOOL func_02054f10(void *a, int b);
void func_0204918c(VecFx32 *out, fx32 t, const VecFx32 *from, const VecFx32 *to);
void func_ov006_021dd0e4(ov006_Obj14_021de2e0 *p);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
BOOL func_ov000_0216dae4(void *p);

static inline void ov006_Obj14_SetPos(ov006_Obj14_021de2e0 *o, s32 x, s32 y, s32 z) {
    o->x = x;
    o->y = y;
    o->z = z;
}

static inline void ov006_Obj18_SetPos(ov006_Obj18_021de2e0 *o, s32 x, s32 y, s32 z) {
    o->x = x;
    o->y = y;
    o->z = z;
}

static inline void ov006_Obj18_Update(ov006_Obj18_021de2e0 *o) {
    if (!o->ready) {
        if (o->unk1C != NULL && func_02054f10(o->unk1C, 0xffff)) {
            o->ready = 1;
        }
    } else {
        if (o->unk8 && ((u8)++o->unk9 & 1)) {
            func_ov000_0215fdfc(o->unk18, 2, data_ov006_021ec094);
        } else {
            func_ov000_0215fdfc(o->unk18, 2, data_ov006_021ec0a0);
        }
        o->unk18->v0C();
    }
}

void func_ov006_021de2e0(ov006_Unk021de2e0 *self) {
    fx32 t;
    if (self->state == 0) {
        if (self->unk20 == NULL || !func_02054f10(self->unk20, 0xffff)) {
            return;
        }
        if (self->unk24 == NULL || !func_02054f10(self->unk24, 0xffff)) {
            return;
        }
        if (self->unk34 == NULL || !func_02054f10(self->unk34, 0xffff)) {
            return;
        }
        self->state = 1;
    }
    switch (self->state) {
    case 1:
        *self->unk1C |= 4;
        self->timer = 0;
        self->b1 = 0;
        self->state = 2;
    case 2:
        if (++self->timer > 20) {
            self->timer = 20;
            self->state = 3;
        }
        break;
    case 3:
        if (self->b1) {
            self->state = 4;
            self->b1 = 0;
        }
        break;
    case 4:
        *self->unk1C &= ~4;
        self->timer = 20;
        self->b0 = 0;
        self->state = 5;
    case 5:
        if (--self->timer < 0) {
            self->timer = 0;
            self->state = 6;
        }
        break;
    case 6:
        if (self->b0) {
            self->state = 2;
            self->b0 = 0;
        }
        break;
    }
    t = FX_Div(self->timer << 12, 0x14000);
    {
        VecFx32 from;
        VecFx32 to;
        VecFx32 out;
        from.x = -0x40000;
        from.y = 0;
        from.z = 0;
        to.x = 0;
        to.y = 0;
        to.z = 0;
        func_0204918c(&out, t, &from, &to);
        ov006_Obj14_SetPos(self->unk14, out.x & ~0xfff, (u32)FX_Whole(out.y) << 12, self->unk14->z);
    }
    func_ov006_021dd0e4(self->unk14);
    {
        VecFx32 from;
        VecFx32 to;
        VecFx32 out;
        from.x = 0;
        from.y = -0x40000;
        from.z = 0;
        to.x = 0;
        to.y = 0;
        to.z = 0;
        func_0204918c(&out, t, &from, &to);
        ov006_Obj18_SetPos(self->unk18, out.x & ~0xfff, (u32)FX_Whole(out.y) << 12, self->unk18->z);
    }
    ov006_Obj18_Update(self->unk18);
    func_ov000_0216dae4(self->unk1C);
    {
        VecFx32 from;
        VecFx32 to;
        VecFx32 out;
        from.x = -0x40000;
        from.y = 0;
        from.z = 0;
        to.x = 0;
        to.y = 0;
        to.z = 0;
        func_0204918c(&out, t, &from, &to);
        ov006_Model_SetPos(self->unk20, 0, out.x & ~0xfff, (u32)FX_Whole(out.y) << 12);
    }
    {
        VecFx32 from;
        VecFx32 to;
        VecFx32 out;
        from.x = 0x40000;
        from.y = 0;
        from.z = 0;
        to.x = 0;
        to.y = 0;
        to.z = 0;
        func_0204918c(&out, t, &from, &to);
        ov006_Model_SetPos(self->unk24, 0, out.x & ~0xfff, (u32)FX_Whole(out.y) << 12);
    }
    {
        VecFx32 from;
        VecFx32 to;
        from.x = 0x96000;
        from.y = 0x57000;
        from.z = 0;
        to.x = 0x44000;
        to.y = 0x57000;
        to.z = 0;
        func_0204918c(&self->unk28, t, &from, &to);
    }
}

}
