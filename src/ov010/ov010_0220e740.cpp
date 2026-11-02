#include "ov010/ov010.h"

struct Ov010PathSm {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 mode;
};

struct Ov010Path {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    void *unk_18;
    VecFx32 unk_1c;
    u8 unk_28[0x30];
    Ov010PathSm sm;
};

extern "C" {

extern void *data_0214a420;
extern void MI_CpuCopy8(s32 a, void *b, s32 c);
extern VObj *func_02065f88(s32 a, VecFx32 *b);
extern void EffectMgr_StopLoop(void *a, s32 b);
extern VObj *func_020657b0(void *a, s32 b);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

BOOL func_ov010_0220e740(Ov010Path *self, void *a, s32 b, s32 c, const VecFx32 *v, s32 e) {
    self->b0 = 1;
    self->b1 = 0;
    self->unk_18 = a;
    self->unk_02 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = e;
    self->unk_10 = 0x1000;
    self->unk_1c = *v;
    MI_CpuCopy8(b, self->unk_28, c);
    func_ov003_021da48c(&self->sm, 1);
    return TRUE;
}

static inline u16 Ov010_SubClamp(u16 a, s32 b) {
    s32 d = a - b;
    u16 r;
    if (d < 0) {
        r = 0;
    } else {
        r = d;
    }
    return r;
}

void func_ov010_0220e7c8(Ov010Path *self) {
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        return;
    }
    self->unk_02++;
    switch (self->sm.mode) {
    case 0:
    case 1:
        break;
    case 2: {
        u16 lim = Ov010_SubClamp(self->unk_04, 80);
        if (self->unk_02 < lim) {
            return;
        }
        func_ov000_02198360(&self->sm, 3, 0);
        break;
    }
    case 3:
        if (self->sm.state == 0) {
            VecFx32 p;
            VObj *e;
            p.x = FLD(s32, self->unk_18, 0x70);
            p.y = FLD(s32, self->unk_18, 0x74);
            p.z = FLD(s32, self->unk_18, 0x78);
            e = func_02065f88(0x322, &p);
            e->vfunc_0c(0xf00);
            e->vfunc_20(&self->unk_1c);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da904(e, self->unk_18, &self->unk_1c);
            self->unk_08 = FLD(s32, e, 0x24);
            self->sm.state++;
        } else {
            u16 lim = Ov010_SubClamp(self->unk_04, 40);
            if (self->unk_02 < lim) {
                return;
            }
            EffectMgr_StopLoop(data_0214a420, self->unk_08);
            self->unk_08 = 0;
            func_ov000_02198360(&self->sm, 4, 0);
        }
        break;
    case 4: {
        VObj *fx;
        if (self->sm.state == 0) {
            VecFx32 p;
            VObj *e;
            p.x = FLD(s32, self->unk_18, 0x70);
            p.y = FLD(s32, self->unk_18, 0x74);
            p.z = FLD(s32, self->unk_18, 0x78);
            e = func_ov003_021da8e4(self->unk_0c, &p, 0xe66);
            e->vfunc_0c(self->unk_14);
            e->vfunc_20(&self->unk_1c);
            FLD(s32, e, 0x3c) = self->unk_10;
            self->unk_08 = FLD(s32, e, 0x24);
            self->sm.state++;
        }
        fx = func_020657b0(data_0214a420, self->unk_08);
        if (fx != NULL) {
            VecFx32 q;
            q.x = FLD(s32, self->unk_18, 0x70);
            q.y = FLD(s32, self->unk_18, 0x74);
            q.z = FLD(s32, self->unk_18, 0x78);
            VEC_Add(&q, &self->unk_1c, &q);
            fx->vfunc_18(&q);
        }
        if (self->unk_02 < self->unk_04) {
            return;
        }
        ActorMgr_SendMsg(FLD(u16, self->unk_18, 0xc), 0xffff, 0xe, 1, 0x30, self->unk_28);
        func_ov000_02198360(&self->sm, 1, 0);
        break;
    }
    }
}
}
