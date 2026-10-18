#include "ov014/ov014.h"

struct Ov014Slot {
    s32 id;
    u8 unk_04[0x30];
};

extern "C" {

extern void *data_02097cdc;
extern void *data_02097e4c;
extern void *data_0214a420;
extern u8 data_ov014_02217968[];
extern u8 data_ov014_02217a0c[];
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Actor *self, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void NNS_G3dGetCurrentMtx(void *p, s32 a);
extern void func_ov003_021cf278(void *self, s32 a, s32 b);
extern void func_ov003_021ceedc(void *p);
extern void func_ov003_021cef0c(void *p);
extern void MTX_Identity43_(void *p);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_020359d0(void *a, s32 b, s32 c);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_02035b90(void *a, s32 b);
extern BOOL func_0204985c(void *a);
extern void func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern u8 data_ov014_02216a60[];
extern u8 data_ov014_02216afc[];
extern u8 data_ov014_02216b6c[];
extern u8 data_ov014_02217a1b[];
extern u8 data_ov014_02217a1c[];
extern u8 data_ov014_02217a28[];
extern u8 data_ov014_02217a38[];
extern void func_ov003_021d112c(Ov014Actor *self);
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);
extern s32 func_ov000_021909a8(void *a, const void *b, const void *c);
extern void NNS_G3dRenderObjSetInitFunc(void *a, void *b);

void func_ov014_02208fe4(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->unk_64 + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = func_ov000_02199ba0(FLD(void *, self, 0x4c))->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov014Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            u8 *s = FLD(u8 *, q, 0x4c);
            if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
                func_ov000_0218996c(5, 8);
                return;
            }
        }
    }
}

void *func_ov014_022090fc(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov014_02209118(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov014_0220912c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov014_02209148(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov014_0220915c(u8 *self) {
    u8 *t = FLD(u8 *, FLD(u8 *, self, 4), 0x2c);
    s32 k;
    u32 i;
    u32 n;
    if (t == NULL || t[0] == 0) {
        return;
    }
    if (FLD(u32, self, 8) & 0x10) {
        k = FLD(u8, self, 0xae);
    } else {
        k = -1;
    }
    n = FLD(u32, t, 4);
    for (i = 0; i < n; i++) {
        if (k == FLD(s32, t + i * 0x34, 8)) {
            NNS_G3dGetCurrentMtx(t + 0xc + i * 0x34, 0);
            return;
        }
    }
}

void func_ov014_022091d4(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov014_0220915c;
    FLD(u8, self, 0x92) = 3;
}

void func_ov014_022091ec(void *self, Ov014Actor *a) {
    u16 *hp = a->unk_50;
    u32 cur = hp[0];
    u32 max = hp[1];
    u8 *q = FLD(u8 *, self, 0xc);
    if (cur >= max * 80 / 100) {
        if (FLD(u16, q, 4) != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    } else if (cur >= max * 35 / 100) {
        if (FLD(u16, q, 4) != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (FLD(u16, q, 4) != 2) {
            func_ov003_021cf278(self, 2, 0);
        }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_02209280(Ov014Actor *self) {
    s32 i;
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217968;
    func_ov003_021ceedc((u8 *)self + 0x1c0);
    FLD(s32, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(u16, self, 0xf8) = 0;
    FLD(u8, self, 0xfc) = 0;
    for (i = 0; i < 3; i++) {
        ((Ov014Slot *)((u8 *)self + 0x104))[i].id = -1;
        MTX_Identity43_((u8 *)self + 0x108 + i * 0x34);
    }
    FLD(u16, self, 0x1a0) = 0;
    FLD(u16, self, 0x1a2) = 0;
    FLD(u8, self, 0x1a4) = 1;
    FLD(u8, self, 0x1a5) = 0;
    FLD(s32, self, 0x1a8) = 0;
    FLD(s32, self, 0x1ac) = 0;
    FLD(s32, self, 0x1b0) = 0;
    FLD(s32, self, 0x1b4) = 0;
    FLD(s32, self, 0x1b8) = 0;
    FLD(s32, self, 0x1bc) = 0;
    FLD(s32, self, 0x1dc) = 0;
    FLD(s32, self, 0x1e0) = 0;
    FLD(s32, self, 0x1e4) = 0;
    FLD(s32, self, 0x1e8) = 0;
    FLD(s32, self, 0x1ec) = 0;
    FLD(s32, self, 0x1f0) = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Kill1f0(Ov014Actor *self) {
    Ov014V *o;
    if (data_0214a420 != NULL && (o = func_020657b0(data_0214a420, FLD(void *, self, 0x1f0))) != NULL) {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        data_02097dd0->cur = saved;
    }
}

Ov014Actor *func_ov014_02209334(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217968;
    Ov014_Kill1f0(self);
    func_02036838(data_02097cdc, data_ov014_02217a0c, 7, 0);
    func_ov003_021cef0c((u8 *)self + 0x1c0);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Actor *func_ov014_022093e0(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217968;
    Ov014_Kill1f0(self);
    func_02036838(data_02097cdc, data_ov014_02217a0c, 7, 0);
    func_ov003_021cef0c((u8 *)self + 0x1c0);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02209494(Ov014Actor *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov014_02217a0c, 7, 0);
    func_02049678(data_02097e4c, 4, 0xc, -1);
}

BOOL func_ov014_022094d0(Ov014Actor *self) {
    BOOL r = TRUE;
    r = (r & func_ov000_0218cf5c(self)) ? TRUE : FALSE;
    r = (r & func_02035b90(data_ov014_02217a0c, 7)) ? TRUE : FALSE;
    return (r & func_0204985c(data_02097e4c)) ? TRUE : FALSE;
}

void func_ov014_02209520(Ov014Actor *self, Ov014Msg *msg) {
    func_ov003_021d1c00(self, msg);
}

void func_ov014_0220952c(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov003_021d112c(self);
    {
        Ov014Sub48 *q = self->unk_48;
        q->unk_9a_1 = 0;
        q->unk_9a_4 = 0;
    }
    {
        Ov014Sub48 *q = self->unk_48;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
    }
    {
        Ov014Sub44 *n = self->unk_44;
        FLD(s32, n, 0xc) = 0;
        n->unk_10 = -0x800;
        FLD(s32, n, 0x14) = 0x1000;
    }
    self->unk_44->unk_1c = 0x1000;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
    }
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 0, 9, data_ov014_02216a60);
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 1, 14, data_ov014_02216afc);
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 2, 17, data_ov014_02216b6c);
    FLD(u8, self, 0xfc) = 0;
    FLD(void *, self, 0x1d4) = self;
    FLD(void *, self, 0x1d0) = (void *)func_ov014_022091ec;
    FLD(s32, self, 0x100) = 3;
    FLD(s32, self, 0x104) = func_ov000_021909a8(self->unk_38, data_ov014_02217a1b, data_ov014_02217a1c);
    FLD(s32, self, 0x138) = func_ov000_021909a8(self->unk_38, data_ov014_02217a1b, data_ov014_02217a28);
    FLD(s32, self, 0x16c) = func_ov000_021909a8(self->unk_38, data_ov014_02217a1b, data_ov014_02217a38);
    m = self->unk_38;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)func_ov014_022091d4);
    m->unk_c2_5 = 0;
    self->unk_38->unk_c2_8 = 1;
    self->unk_38->unk_50 = &FLD(u8, self, 0xfc);
    FLD(Ov014Flags, self->unk_38, 0xc2).b4 = 0;
    FLD(u8, FLD(u8 *, self, 0x4c), 0x18) |= 0x10;
    FLD(s32, self, 0x1a8) = self->pos.x;
    FLD(s32, self, 0x1ac) = self->pos.y;
    FLD(s32, self, 0x1b0) = self->pos.z;
}

struct Ov014Anim8c {
    s16 kind;
    u8 unk_02[0x4];
    u16 unk_06;
};

extern u8 *func_ov000_0219bf90(void);
extern void func_02065860(void *a, void *b);
extern void func_ov003_021ceff4(void *p);
extern BOOL func_ov000_021983b0(void *p, s32 a, s32 b, s32 c);

static inline BOOL Ov014_TickB6(Ov014Actor *self) {
    BOOL r = FALSE;
    if (FLD(u16, self, 0xb6) == 0) {
        r = TRUE;
    } else if (FLD(u16, self, 0xb6) != 0xffff && FLD(u16, self, 0xb6) != 0) {
        FLD(u16, self, 0xb6)--;
    }
    return r;
}

void func_ov014_022096e0(Ov014Actor *self) {
    u8 *pl;
    if (!Ov014_GameIdle()) {
        return;
    }
    pl = func_ov000_0219bf90();
    self->unk_90 = 0xffff;
    if (pl != NULL) {
        self->unk_90 = FLD(u16, pl, 0xc);
    }
    if (FLD(u16, self, 0xb4) != 0 && !FLD(Ov014Flags, self->unk_b0, 0xa).b12) {
        self->unk_93_4 = 1;
    }
    if (*self->unk_50 == 0 || (self->unk_40->flags & 0x200000)) {
        if (FLD(u16, self, 0xb4) / 10 != 9) {
            FLD(u16, self, 0xb4) = 0x5a;
        }
        *self->unk_50 = 0;
        self->unk_93_4 = 0;
    }
    if (self->unk_30 != 0 && (self->unk_30 & 0x200)) {
        FLD(u8, self, 0xfc) = 0;
        func_02065860(data_0214a420, FLD(void *, self, 0x1dc));
        FLD(void *, self, 0x1dc) = NULL;
        func_02065860(data_0214a420, FLD(void *, self, 0x1e0));
        FLD(void *, self, 0x1e0) = NULL;
        func_02065860(data_0214a420, FLD(void *, self, 0x1e4));
        FLD(void *, self, 0x1e4) = NULL;
    }
    switch (FLD(u16, self, 0xb4)) {
    case 0:
        if (func_ov000_021983b0(self->unk_40, 0x14, 1, 1)) {
            FLD(u16, self, 0xb4) = 0x64;
            break;
        }
        if (func_ov000_021983b0(self->unk_40, 0xb, 3, 1)) {
            FLD(u16, self, 0xb4) = 0x6e;
            break;
        }
        if (func_ov000_021983b0(self->unk_40, 0x13, 1, 1)) {
            FLD(u16, self, 0xb4) = 0x50;
        } else {
            FLD(u16, self, 0xb4) = 10;
        }
        break;
    case 10:
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4) = 0x15;
        FLD(u16, self, 0xb6) = 0xc8;
        break;
    case 0x14:
        func_ov003_021ceff4(&FLD(u8, self, 0x1c0));
        FLD(u16, self, 0xb4)++;
    case 0x15: {
        u8 *t;
        u16 idx;
        u8 *a;
        if (!Ov014_TickB6(self) && self->unk_40->state != 0xffff) {
            break;
        }
        t = FLD(u8 *, self, 0x1cc);
        idx = FLD(u16, t, 8);
        a = FLD(u8 *, t, 0xc);
        FLD(u8 *, self, 0xf0) = a + idx * 8;
        switch (*(s16 *)(a + idx * 8)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            FLD(u16, self, 0xb4) = 0x1e;
            break;
        case 5:
        case 6:
        case 7:
            FLD(u16, self, 0xb4) = 0x32;
            break;
        case 9:
        case 10:
            FLD(u16, self, 0xb4) = 0x28;
            break;
        case 8:
            FLD(u16, self, 0xb4) = 0x3c;
            break;
        case 11:
        case 12:
            FLD(u16, self, 0xb4) = 0x78;
            break;
        case 13:
            FLD(u16, self, 0xb4) = 0x82;
            break;
        }
        break;
    }
    case 0x1e:
        func_ov000_02198360(self->unk_40, 0xe, 0);
        self->unk_40->state = 0;
        FLD(u16, self, 0xb6) = 0xffff;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x1f:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = FLD(Ov014Anim8c *, self, 0xf0)->unk_06;
        break;
    case 0x32:
        func_ov000_02198360(self->unk_40, 0x10, 0);
        self->unk_40->state = 0;
        FLD(u16, self, 0xb6) = 0xffff;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x33:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = FLD(Ov014Anim8c *, self, 0xf0)->unk_06;
        break;
    case 0x28:
        func_ov000_02198360(self->unk_40, 0xf, 0);
        self->unk_40->state = 0;
        FLD(u16, self, 0xb6) = 0xffff;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x29:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = FLD(Ov014Anim8c *, self, 0xf0)->unk_06;
        break;
    case 0x3c:
        func_ov000_02198360(self->unk_40, 0x11, 0);
        self->unk_40->state = 0;
        FLD(u16, self, 0xb6) = 0xffff;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x3d:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = FLD(Ov014Anim8c *, self, 0xf0)->unk_06;
        break;
    case 0x46:
        if (self->unk_40->unk_13 == 1) {
            FLD(u16, self, 0xb4) = 0x14;
            FLD(u16, self, 0xb6) = 0x3c;
        }
        break;
    case 0x47:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->timer = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = 0x3c;
        break;
    case 0x50:
        if (self->unk_40->unk_13 == 1) {
            FLD(u16, self, 0xb4) = 0x14;
            FLD(u16, self, 0xb6) = 0x3c;
        }
        break;
    case 0x5a:
        self->unk_40->flags |= 0x200000;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb6) = 0xffff;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x64:
        self->unk_48->unk_9a_5 = 0;
        if (self->unk_40->unk_13 == 1) {
            FLD(u16, self, 0xb4) = 0x14;
            FLD(u16, self, 0xb6) = 0x3c;
        }
        break;
    case 0x6e:
        self->unk_48->unk_9a_5 = 0;
        if (self->unk_40->unk_13 == 1) {
            FLD(u16, self, 0xb4) = 0x14;
            FLD(u16, self, 0xb6) = 0x3c;
        }
        break;
    case 0x78:
        self->unk_40->flags |= 4;
        self->unk_40->state = 0;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x79:
        if (self->unk_40->state != 0xffff) {
            self->unk_40->flags |= 4;
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->timer = 0;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = FLD(Ov014Anim8c *, self, 0xf0)->unk_06;
        self->unk_a0 = 0;
        self->unk_a8 = 0;
        break;
    case 0x82:
        self->unk_40->flags |= 0x400000000ULL;
        self->unk_40->state = 0;
        self->unk_ea_0 = 4;
        FLD(u16, self, 0xb4)++;
        break;
    case 0x83:
        if (self->unk_40->state != 0xffff) {
            break;
        }
        self->unk_40->flags |= 2;
        self->unk_40->timer = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        FLD(u16, self, 0xb4) = 0x14;
        FLD(u16, self, 0xb6) = 0;
        break;
    case 0x5b:
    default:
        break;
    }
}

}
