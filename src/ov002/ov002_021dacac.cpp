#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];
extern u8 data_ov002_021efe30[];
int func_ov002_021dac8c(void *self, void *arg);
BOOL func_ov000_0219d5a0(void);
void *ListOwner_GetNth(void *a, u8 b);

static inline void ov002_SetId(void *x, u16 id) {
    if (x != NULL) {
        func_ov002_021e2754(x, id);
    }
}

static inline void ov002_CamInit(u8 *c, const VecFx32 *pos) {
    FIELD(c, 0x90, s32) = 15;
    FIELD(c, 0x94, s32) = 15;
    *(VecFx32 *)(c + 0x98) = *(VecFx32 *)FIELD(c, 0x8c, u8 *);
    *(VecFx32 *)(c + 0xa4) = *(VecFx32 *)(FIELD(c, 0x8c, u8 *) + 0xc);
    if (pos != NULL) {
        *(VecFx32 *)(c + 0xb0) = *pos;
    }
    FIELD(c, 0xbc, s32) = -0x2b8;
    FIELD(c, 0xc0, s32) = 0;
    FIELD(c, 0xc4, s32) = 0x2b8;
}

void func_ov002_021dacac(Obj021eff74 *self) {
    void *g = data_02149ef8;
    UiObj *o;
    VObj *m;
    u8 *s;
    u8 *w;
    void *t;
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_0c = (UiList *)o;
    self->unk_0c->vfunc_10(MsgRes_GetString(g, 0xba));
    self->unk_0c->vfunc_14(MsgRes_GetString(g, 0xbb));
    FIELD(self->unk_0c, 0x20, s32) = 2;
    FIELD(self->unk_0c, 0x24, s32) = 0x78;
    s = ((u8 *)self->unk_0c);
    FIELD(s, 0x64, s16) = 0;
    FIELD(s, 0x66, s16) = 0x1e;
    FIELD(s, 0x68, s16) = -0x2000;
    FIELD(self->unk_0c, 0x68, s16) = -0x2000;
    s = ((u8 *)self->unk_0c);
    FIELD(s, 0x58, s32) = -0xff;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x2000;
    FIELD(self->unk_0c, 0xc, u32) &= ~0x400000;
    FIELD(self->unk_0c, 0xc, u32) &= ~0x80000;
    FIELD(self->unk_0c, 0xc, u32) &= ~0x40000;
    FIELD(self->unk_0c, 0xc, u32) |= 0x800000;
    FIELD(self->unk_0c, 0x8, void *) = self;
    FIELD(self->unk_0c, 0x84, void *) = (void *)func_ov002_021dac8c;
    self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xbc), 0, 0xffff, 0xffff);
    if (func_020594bc(data_02fe152c, 5, 1, 1)) {
        u8 *e = (u8 *)self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xbe), 1, 0xffff, 0xffff);
        if (func_ov000_0219bf90()) {
            if ((self->unk_20 = func_ov000_0219d5a0()) != 0) {
                FIELD(e, 0x24, s32) = 0xe;
            }
        }
    }
    self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xfa), 2, 0xffff, 0xffff);
    m = self->unk_0c;
    m->vfunc_a8(ListOwner_GetNth(m, *(u8 *)data_ov002_021f0f90));
    FIELD(self->unk_0c, 0xc, u32) &= ~0x20000;
    FIELD(self->unk_0c, 0xc, u32) &= ~0x40000;
    FIELD(self->unk_0c, 0xc, u32) &= ~0x10000;
    self->unk_0c->vfunc_08();
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_10 = (Lo021cadcc *)o;
    o->width = 0xf8;
    FIELD(self->unk_10, 0x20, s32) = 2;
    s = ((u8 *)self->unk_10);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x96;
    FIELD(s, 0x68, s16) = -0x2000;
    s = ((u8 *)self->unk_10);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x2000;
    FIELD(self->unk_10, 0x2c, s32) = 1;
    self->unk_10->vfunc_08();
    {
        u8 kind = *(u8 *)data_ov002_021f0f90;
        if (self->unk_10 != NULL) {
            void *str;
            void *g2 = data_02149ef8;
            switch (kind) {
            case 0:
                str = MsgRes_GetString(g2, 0xbd);
                break;
            case 1:
                str = MsgRes_GetString(g2, 0xbf);
                break;
            case 2:
                str = MsgRes_GetString(g2, 0xfb);
                break;
            default:
                str = data_ov002_021efe30;
                break;
            }
            func_ov000_0215bb14(self->unk_10, str);
            self->unk_10->vfunc_70();
        }
    }
    ov002_CamInit(self->unk_04, (const VecFx32 *)(data_ov002_021eef74 + 0x70));
    if (func_ov002_isMode4()) {
        func_0203cb78(0xa000, 0, -1);
    }
    {
        u8 *c = self->unk_04;
        FIELD(c, 0x74, u8) = 0;
        FIELD(c, 0x75, u8) = 1;
    }
    w = self->unk_04;
    if (data_0214a424->bits18.mode == 1) {
        func_ov000_021c9544(w + 0x76, FIELD(w, 0x6c, void *));
        func_ov000_021c95ac(w + 0x76, data_0214a424->bits18.unk_3 | 0x8000);
    } else {
        func_ov000_021c9544(w + 0x76, FIELD(w, 0x6c, void *));
    }
    t = Task_FindById(0x1b);
    if (t != NULL && data_0214a424->bits18.mode == 1) {
        ov002_SetId(FIELD(t, 0x3c, void *), data_0214a424->bits18.unk_3 | 0x8000);
    }
}

}
