#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097cdc;
extern char data_ov014_02217c72[];
extern char data_ov014_02217c81[];
extern char data_ov014_02217c93[];
extern char data_ov014_02217c9f[];
extern char data_ov014_02217cb1[];
extern char data_ov014_02217cbd[];
extern char data_ov014_02217ccf[];
extern u8 data_ov014_02217e6c[];
extern u8 data_ov014_02217d1d[];
extern u8 *func_02066900(const char *a, const char *b, Ov014Vec *pos);
extern u8 *func_02066774(const char *a, const char *b, s32 c, Ov014Vec *pos);
extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern void func_ov003_021cf278(void *self, s32 a, s32 b);
extern void func_ov003_021ceedc(void *p);
extern void func_ov003_021cef0c(void *p);
extern void func_ov000_02198328(void *p);
extern void MIi_CpuClear32(s32 v, void *p, u32 n);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_020359d0(void *a, s32 b, s32 c);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern u8 data_ov014_02217d2c[];
extern u8 data_ov014_02217d33[];
extern u8 data_ov014_02217db0[];
extern u8 data_ov014_02216c80[];
extern u8 data_ov014_02216e50[];
extern u8 data_ov014_02216ea8[];
extern u8 data_ov014_02216f00[];
extern void func_ov003_021d112c(Ov014Actor *self);
extern void func_0203f2b8(void *p);
extern s32 func_ov000_021909a8(void *a, const void *b, const void *c);
extern void MTX_Identity43_(void *m);
extern void NNS_G3dRenderObjSetInitFunc(void *a, void *b);
extern void MIi_CpuClear16(s32 v, void *p, u32 n);
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);

u8 *func_ov014_0220f7f0(s32 k, Ov014Vec *pos) {
    u8 *r = NULL;
    switch (k) {
    case 0:
        r = func_02066900((const char *)data_ov014_02217c72, (const char *)data_ov014_02217c81, pos);
        break;
    case 1:
        r = func_02066774((const char *)data_ov014_02217c72, (const char *)data_ov014_02217c93, 0, pos);
        r[0x28] = 2;
        break;
    case 2:
        r = func_02066900((const char *)data_ov014_02217c72, (const char *)data_ov014_02217c9f, pos);
        break;
    case 3:
        r = func_02066774((const char *)data_ov014_02217c72, (const char *)data_ov014_02217cb1, 0, pos);
        r[0x28] = 2;
        break;
    case 4:
        r = func_02066900((const char *)data_ov014_02217c72, (const char *)data_ov014_02217cbd, pos);
        break;
    case 5:
        r = func_02066900((const char *)data_ov014_02217c72, (const char *)data_ov014_02217ccf, pos);
        break;
    }
    return r;
}

void func_ov014_0220f8a4(u8 *self) {
    u8 *t = FLD(u8 *, FLD(u8 *, self, 4), 0x2c);
    s32 k;
    if (t == NULL) {
        return;
    }
    if (FLD(u32, self, 8) & 0x10) {
        k = FLD(u8, self, 0xae);
    } else {
        k = -1;
    }
    if (k == FLD(s32, t, 0)) {
        NNS_G3dGetCurrentMtx(t + 4, 0);
    }
}

void func_ov014_0220f8e4(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov014_0220f8a4;
    FLD(u8, self, 0x92) = 3;
}

void func_ov014_0220f8fc(void *self, Ov014Actor *a) {
    u16 pct = a->unk_50[0] * 100 / a->unk_50[1];
    u16 s;
    if (FLD(u8 *, a, 0x154) != NULL) {
        s = FLD(u16, FLD(u8 *, a, 0x154), 8);
    } else {
        s = 0;
    }
    if (pct < 40) {
        if (s == 0) {
            if (FLD(u16, FLD(u8 *, self, 0xc), 4) != 3) {
                func_ov003_021cf278(self, 3, 0);
            }
        } else {
            if (FLD(u16, FLD(u8 *, self, 0xc), 4) != 2) {
                func_ov003_021cf278(self, 2, 0);
            }
        }
    } else if (pct < 80) {
        if (FLD(u16, FLD(u8 *, self, 0xc), 4) != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (FLD(u16, FLD(u8 *, self, 0xc), 4) != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_0220f9d0(Ov014Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217e6c;
    func_ov003_021ceedc((u8 *)self + 0x124);
    FLD(s16, self, 0x15c) = 0;
    FLD(s16, self, 0x15e) = 0;
    func_ov000_02198328((u8 *)self + 0x16c);
    FLD(u16, self, 0xde) = 0xffff;
    MIi_CpuClear32(0, (u8 *)self + 0xf0, 0x34);
    FLD(s32, self, 0x140) = 0;
    FLD(s16, self, 0x14c) = 0;
    FLD(void *, self, 0x154) = NULL;
    FLD(u8, self, 0x180) = 1;
    FLD(u16, self, 0x14e) = 0xffff;
    FLD(u16, self, 0x150) = 0xffff;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free154(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov014V *, self, 0x154) != NULL) {
        Ov014V *p = FLD(Ov014V *, self, 0x154);
        if (p != NULL) {
            p->v04();
        }
        FLD(Ov014V *, self, 0x154) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov014_StopSnd(void) {
    if (func_02035b90(data_ov014_02217d1d, 7)) {
        func_02036838(data_02097cdc, data_ov014_02217d1d, 7, 0);
    }
}

Ov014Actor *func_ov014_0220fa4c(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217e6c;
    Ov014_Free154(self);
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x124);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Actor *func_ov014_0220fafc(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217e6c;
    Ov014_Free154(self);
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x124);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220fbb4(Ov014Actor *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov014_02217d1d, 7, 0);
}

BOOL func_ov014_0220fbd4(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    return (r & func_02035b90(data_ov014_02217d1d, 7)) ? TRUE : FALSE;
}

void func_ov014_0220fc00(Ov014Actor *self, Ov014Msg *msg) {
    if (msg->type == 9) {
        Ov014Actor *a;
        u16 id = FLD(u16, msg, 0xc);
        FLD(u16, self, 0x14e) = id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        FLD(u16, self, 0x150) = a->kind;
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov014_0220fc5c(Ov014Actor *self) {
    Ov014Sub38 *m;
    u8 *p;
    func_ov003_021d112c(self);
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rot[0] = 0;
    self->rot[1] = 0;
    self->rot[2] = 0;
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_3c != NULL) {
            Ov014V *v = self->unk_3c;
            if (v != NULL) {
                v->v04();
            }
            self->unk_3c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_48 != NULL) {
            Ov014Sub48 *q = self->unk_48;
            if (q != NULL) {
                func_0203f2b8(q);
                func_0203de1c(q);
            }
            self->unk_48 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_44->unk_1c = 0x2000;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
    }
    FLD(s32, self, 0xf0) = func_ov000_021909a8(self->unk_38, data_ov014_02217d2c, data_ov014_02217d33);
    MTX_Identity43_((u8 *)self + 0xf4);
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov014_0220f8e4);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xf0);
    FLD(Ov014Flags, self->unk_38, 0xc2).b4 = 0;
    p = (u8 *)func_0203dd9c(0x1c);
    if (p != NULL) {
        FLD(void *, p, 0) = data_ov014_02217db0;
        MIi_CpuClear16(0xffff, p + 4, 4);
        FLD(u16, p, 8) = 0;
        FLD(u8, p, 0xa) = 0;
        FLD(u8, p, 0xb) = 0;
        FLD(s32, p, 0x10) = 0;
        FLD(s32, p, 0x14) = 0xffff;
        FLD(s32, p, 0x18) = 0;
    }
    FLD(u8 *, self, 0x154) = p;
    func_ov003_021cf1f0((u8 *)self + 0x124, 0, 7, data_ov014_02216c80);
    func_ov003_021cf1f0((u8 *)self + 0x124, 1, 11, data_ov014_02216e50);
    func_ov003_021cf1f0((u8 *)self + 0x124, 2, 11, data_ov014_02216ea8);
    func_ov003_021cf1f0((u8 *)self + 0x124, 3, 12, data_ov014_02216f00);
    FLD(void *, self, 0x138) = self;
    FLD(void *, self, 0x134) = (void *)func_ov014_0220f8fc;
}

}
