#include "ov015/ov015.h"

extern "C" {

Ov015V *func_ov015_021fa6d0(void);
void Ov015Fade_Start(Ov015Fade *self, u8 a, u8 b, s32 c, u16 d);
extern u8 *data_02097dc8;
extern u8 data_ov015_022128ec[];
extern u8 data_ov015_02213188[];
extern u8 *data_ov002_021f0f9c;
void func_ov002_021e7c1c(void);
void func_ov015_0220ec40(Ov015ResultPanel *self);

extern Ov015Shared *data_ov015_02213368;
extern u8 *data_0214a424;
void func_ov000_0215d980(void *a, s32 b, s32 c);

static inline BOOL Ov015_IsKind5f1a4(u8 *o) {
    return FLD(s32, o, 0x4) == 5 ? TRUE : FALSE;
}

static inline void Ov015_SetMoney2(u8 *g, u32 v) {
    if (v > 99999) {
        v = 99999;
    }
    FLD(u32, g, 0x618) = v;
}
BOOL func_ov015_0220ed70(Ov015ResultPanel *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        Ov015Fade_Start((Ov015Fade *)func_ov015_021fa6d0(), 0, 0xf, 0x3c000, 0x2639);
        self->state++;
    case 1: {
        Ov015Fade *f = (Ov015Fade *)func_ov015_021fa6d0();
        if (f->time >= f->duration) {
            self->timer = 0;
            self->state++;
        }
        break;
    }
    case 2:
        if (self->timer > 0x3c000) {
            self->state = 10;
            self->timer = 0;
        } else {
            self->timer += 0x1000;
        }
        break;
    case 10:
        if (self->timer <= self->unk_04->unk_34) {
            self->timer += 0x1000;
        } else {
            self->timer = 0;
            self->state = 0x14;
            self->unk_14->flags &= ~2;
        }
        break;
    case 0x14: {
        s32 n = FLD(s32, data_ov015_02213368, 0x28);
        if (n != 0) {
            if (FLD(u16, data_02097dc8, 0x12) & 1) {
                func_ov000_0215d980(self->unk_10, ((s32)self->unk_10->value) + n, 0);
                func_ov000_0215d980(self->unk_0c, 0, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                self->state = 0x1e;
            }
        } else {
            self->state = 0x28;
            self->timer = 0;
        }
        break;
    }
    case 0x1e: {
        u8 *a = ((u8 *)self->unk_10);
        if (FLD(s32, a, 0x8c) != FLD(s32, a, 0x88) || ((s32)self->unk_0c->value) != self->unk_0c->unk_88) {
            if (FLD(u16, data_02097dc8, 0x12) & 1) {
                func_ov000_0215d980(self->unk_10, ((s32)self->unk_10->value), 1);
                func_ov000_0215d980(self->unk_0c, 0, 1);
            } else {
                if (++self->timer % 4 == 0) {
                    func_02049a48(data_02097e4c, 0x18, -1, -1, -1);
                }
                break;
            }
        }
        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        self->state = 0x28;
        self->timer = 0;
        break;
    }
    case 0x28:
        if (self->timer >= 0x14000) {
            if (FLD(u16, data_02097dc8, 0x12) & 1) {
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
                Ov015_SetMoney2(data_0214a424, self->unk_10->value);
                self->unk_04->flags |= 2;
                FLD(u32, self->unk_08, 0xc) |= 2;
                self->unk_0c->flags |= 2;
                self->unk_10->flags |= 2;
                self->unk_14->flags |= 2;
                self->state = 0x32;
                self->timer = 0;
            }
        } else {
            self->timer += 0x1000;
        }
        break;
    case 0x32:
        if (Ov015_IsKind5f1a4(((u8 *)self->unk_04)) && Ov015_IsKind5f1a4(self->unk_08) && Ov015_IsKind5f1a4(((u8 *)self->unk_14))) {
            self->state = 0x3c;
        }
        break;
    case 0x3c:
        if (self->timer <= 0xa000) {
            self->timer += 0x1000;
        } else {
            self->timer = 0;
            self->state = -1;
        }
        break;
    default:
        self->state = -1;
        r = FALSE;
        break;
    }
    if (self->state >= 10) {
        ((Ov015V *)self->unk_04)->v1c();
        ((Ov015V *)self->unk_08)->v1c();
        ((Ov015V *)self->unk_0c)->v1c();
        ((Ov015V *)self->unk_10)->v1c();
        ((Ov015V *)self->unk_14)->v1c();
    }
    return r;
}


BOOL func_ov015_0220f1a4(Ov015ResultPanel *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        Ov015Fade_Start((Ov015Fade *)func_ov015_021fa6d0(), 0, 0x14, 0x3c000, 0x2639);
        self->state++;
    case 1: {
        Ov015Fade *f = (Ov015Fade *)func_ov015_021fa6d0();
        if (f->time >= f->duration) {
            self->timer = 0;
            self->state++;
        }
        break;
    }
    case 2:
        if (self->timer <= 0x3c000) {
            self->timer += 0x1000;
        } else {
            self->timer = 0;
            self->state = 10;
            self->unk_14->flags &= ~2;
        }
        break;
    case 10: {
        u32 t;
        if (self->timer >= self->unk_14->unk_34 && (t = FLD(u16, data_02097dc8, 0x12) & 1) != 0) {
            if (t) {
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            }
            self->unk_04->flags |= 2;
            FLD(u32, self->unk_08, 0xc) |= 2;
            self->unk_0c->flags |= 2;
            self->unk_10->flags |= 2;
            self->unk_14->flags |= 2;
            self->state = 0x14;
            self->timer = 0;
        } else {
            self->timer += 0x1000;
        }
        break;
    }
    case 0x14:
        if (Ov015_IsKind5f1a4(((u8 *)self->unk_04)) && Ov015_IsKind5f1a4(self->unk_08) && Ov015_IsKind5f1a4(((u8 *)self->unk_14))) {
            self->state = 0x1e;
        }
        break;
    case 0x1e:
        if (self->timer <= 0xa000) {
            self->timer += 0x1000;
        } else {
            self->timer = 0;
            self->state = -1;
        }
        break;
    default:
        self->state = -1;
        r = FALSE;
        break;
    }
    if (self->state >= 10) {
        ((Ov015V *)self->unk_04)->v1c();
        ((Ov015V *)self->unk_08)->v1c();
        ((Ov015V *)self->unk_0c)->v1c();
        ((Ov015V *)self->unk_10)->v1c();
        ((Ov015V *)self->unk_14)->v1c();
    }
    return r;
}

Ov015Result *Ov015Result_Ctor(Ov015Result *self) {
    SET_VT(self, data_ov015_022128ec);
    self->state = 0;
    self->mode = 1;
    self->unk_0c = 0;
    FLD(s32, self, 0x10) = 0;
    return self;
}

void func_ov015_0220f470(Ov015Result *self) {
    Ov015ResultPanel *p = (Ov015ResultPanel *)Heap_Alloc(0x64);
    if (p != NULL) {
        SET_VT(p, data_ov015_02213188);
        FLD(s32, p, 0x4) = 0;
        FLD(s32, p, 0x8) = 0;
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0;
        FLD(s32, p, 0x14) = 0;
        p->state = 0;
        p->timer = 0;
        MI_CpuFill8(p->name, 0, 0x40);
        p->mode = -1;
    }
    self->panel = p;
}

void func_ov015_0220f4d4(Ov015Result *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->panel);
    HEAP_POP(saved);
    if (data_ov002_021f0f9c != NULL) {
        func_ov002_021e7c1c();
    }
}

void *Ov015ResultPanel_DtorDelete(Ov015ResultPanel *self) {
    SET_VT(self, data_ov015_02213188);
    func_ov015_0220ec40(self);
    Heap_Free(self);
    return self;
}

extern Ov015Globals data_ov015_02213320;
void func_ov002_021e7b58(void);
void *func_ov002_021e9b28(s32 a);
s32 func_ov002_021e7ea8(void *p);
void Ov015Fade_Reset(Ov015Fade *self);
void func_ov015_0220f878(Ov015Result *self);
void func_ov015_0220fb78(Ov015Result *self);
void func_ov015_0220e634(Ov015ResultPanel *a, s32 b);
static inline void Ov015_SetCam14(s32 v) {
    u8 *g = data_ov002_021f0f9c;
    FLD(s32, g, 0x14) = v;
    FLD(u16, g, 0x18) = 0;
}
BOOL func_ov015_0220f568(Ov015Result *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        func_ov002_021e7b58();
        FLD(u8, data_ov002_021f0f9c, 0x1a) = 0;
        FLD(s32, data_ov002_021f0f9c, 0x130) = 1;
        FLD(s32, data_ov002_021f0f9c, 0x134) = 2;
        self->mode = FLD(s32, data_ov015_02213320.unk_00, 0x8);
        switch (self->mode) {
        case 1:
            func_ov015_0220f878(self);
            Ov015_SetCam14(0x51000);
            self->unk_0c = 0x50000;
            break;
        case 0:
            func_ov015_0220fb78(self);
            Ov015_SetCam14(0x14a000);
            self->unk_0c = 0x79000;
            break;
        default:
            func_ov002_021e9b28(0);
            self->unk_0c = 0;
            break;
        }
        self->state = 10;
    case 10:
        if (data_ov002_021f0f9c != NULL) func_ov002_021e7ea8(data_ov002_021f0f9c);
        {
            s32 v = self->unk_0c;
            u8 *g = data_ov002_021f0f9c;
            if (v <= FLD(s32, g, 0xd4) || v > FLD(s32, g, 0xd0)) {
                break;
            }
        }
        func_ov015_0220e634(self->panel, self->mode);
        FLD(s32, data_ov002_021f0f9c, 0x128) = 0;
        self->state = 0x14;
    case 0x14: {
        BOOL ok = TRUE;
        switch (FLD(s32, self->panel, 0x60)) {
        case 1:
            ok = func_ov015_0220ed70(self->panel);
            break;
        case 0:
            ok = func_ov015_0220f1a4(self->panel);
            break;
        case 2:
            ok = FALSE;
            break;
        }
        if (!ok) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->panel);
            HEAP_POP(saved);
            Ov015_SetCam14(-1);
            func_ov002_021e9b28(FLD(s32, data_ov002_021f0f9c, 0xd0));
            self->state = 0x1e;
        }
        if (data_ov002_021f0f9c != NULL) func_ov002_021e7ea8(data_ov002_021f0f9c);
        break;
    }
    case 0x1e: {
        s32 busy;
        if (data_ov002_021f0f9c == NULL) {
            busy = 0;
        } else {
            busy = func_ov002_021e7ea8(data_ov002_021f0f9c);
        }
        if (busy == 0) {
            func_ov002_021e7c1c();
            Ov015Fade_Reset((Ov015Fade *)func_ov015_021fa6d0());
            r = FALSE;
        }
        break;
    }
    default:
        self->state = 0x1e;
        break;
    }
    return r;
}

}
