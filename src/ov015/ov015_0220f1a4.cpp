#include "ov015/ov015.h"

extern "C" {

Ov015Fade *Ov015_GetFade(void);
void Ov015Fade_Start(Ov015Fade *self, u8 a, u8 b, s32 c, u16 d);
extern u8 Ov015Result_vtbl[];
extern u8 Ov015ResultPanel_vtbl[];
void Ov015ResultPanel_DtorBase(Ov015ResultPanel *self);


static inline BOOL Ov015_IsKind5f1a4(UiObj *o) {
    return o->state == 5 ? TRUE : FALSE;
}

static inline void Ov015_SetMoney2(StageFlags *g, u32 v) {
    if (v > 99999) {
        v = 99999;
    }
    g->unk_618 = v;
}
BOOL func_ov015_0220ed70(Ov015ResultPanel *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        Ov015Fade_Start(Ov015_GetFade(), 0, 0xf, 0x3c000, 0x2639);
        self->state++;
    case 1: {
        Ov015Fade *f = Ov015_GetFade();
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
        if (self->timer <= self->unk_04->openLen) {
            self->timer += 0x1000;
        } else {
            self->timer = 0;
            self->state = 0x14;
            self->unk_14->flags &= ~2;
        }
        break;
    case 0x14: {
        s32 n = gOv015Shared->total;
        if (n != 0) {
            if (gPad->trig & 1) {
                Lo021cae48_SetValue(self->unk_10, ((s32)self->unk_10->value) + n, 0);
                Lo021cae48_SetValue(self->unk_0c, 0, 0);
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                self->state = 0x1e;
            }
        } else {
            self->state = 0x28;
            self->timer = 0;
        }
        break;
    }
    case 0x1e: {
        Ov015UiNum *a = self->unk_10;
        if ((s32)a->value != a->unk_88 || ((s32)self->unk_0c->value) != self->unk_0c->unk_88) {
            if (gPad->trig & 1) {
                Lo021cae48_SetValue(self->unk_10, ((s32)self->unk_10->value), 1);
                Lo021cae48_SetValue(self->unk_0c, 0, 1);
            } else {
                if (++self->timer % 4 == 0) {
                    SndMgr_PlayVolume(gSndMgr, 0x18, -1, -1, -1);
                }
                break;
            }
        }
        SndMgr_PlayVolume(gSndMgr, 0x4a, -1, -1, -1);
        self->state = 0x28;
        self->timer = 0;
        break;
    }
    case 0x28:
        if (self->timer >= 0x14000) {
            if (gPad->trig & 1) {
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                Ov015_SetMoney2(gStageFlags, self->unk_10->value);
                self->unk_04->flags |= 2;
                self->unk_08->flags |= 2;
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
        if (Ov015_IsKind5f1a4(self->unk_04) && Ov015_IsKind5f1a4(self->unk_08) && Ov015_IsKind5f1a4(self->unk_14)) {
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
        self->unk_04->vfunc_1c();
        self->unk_08->vfunc_1c();
        self->unk_0c->vfunc_1c();
        self->unk_10->vfunc_1c();
        self->unk_14->vfunc_1c();
    }
    return r;
}


BOOL func_ov015_0220f1a4(Ov015ResultPanel *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        Ov015Fade_Start(Ov015_GetFade(), 0, 0x14, 0x3c000, 0x2639);
        self->state++;
    case 1: {
        Ov015Fade *f = Ov015_GetFade();
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
        if (self->timer >= self->unk_14->openLen && (t = gPad->trig & 1) != 0) {
            if (t) {
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            }
            self->unk_04->flags |= 2;
            self->unk_08->flags |= 2;
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
        if (Ov015_IsKind5f1a4(self->unk_04) && Ov015_IsKind5f1a4(self->unk_08) && Ov015_IsKind5f1a4(self->unk_14)) {
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
        self->unk_04->vfunc_1c();
        self->unk_08->vfunc_1c();
        self->unk_0c->vfunc_1c();
        self->unk_10->vfunc_1c();
        self->unk_14->vfunc_1c();
    }
    return r;
}

Ov015Result *Ov015Result_Ctor(Ov015Result *self) {
    SET_VT(self, Ov015Result_vtbl);
    self->state = 0;
    self->mode = 1;
    self->unk_0c = 0;
    self->panel = NULL;
    return self;
}

void Ov015Result_Init(Ov015Result *self) {
    Ov015ResultPanel *p = (Ov015ResultPanel *)Heap_Alloc(0x64);
    if (p != NULL) {
        SET_VT(p, Ov015ResultPanel_vtbl);
        p->unk_04 = NULL;
        p->unk_08 = NULL;
        p->unk_0c = NULL;
        p->unk_10 = NULL;
        p->unk_14 = NULL;
        p->state = 0;
        p->timer = 0;
        MI_CpuFill8(p->name, 0, 0x40);
        p->mode = -1;
    }
    self->panel = p;
}

void Ov015Result_DtorBase(Ov015Result *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->panel);
    HEAP_POP(saved);
    if (gOv002Stage != NULL) {
        Ov002Stage_Delete();
    }
}

void *Ov015ResultPanel_DtorDelete(Ov015ResultPanel *self) {
    SET_VT(self, Ov015ResultPanel_vtbl);
    Ov015ResultPanel_DtorBase(self);
    Heap_Free(self);
    return self;
}

extern Ov015Globals gOv015Globals;
void Ov015Fade_Reset(Ov015Fade *self);
void func_ov015_0220f878(Ov015Result *self);
void func_ov015_0220fb78(Ov015Result *self);
void func_ov015_0220e634(Ov015ResultPanel *a, s32 b);
static inline void Ov015_SetStageSkip(s32 v) {
    Ov002Stage *g = gOv002Stage;
    g->unk_14 = v;
    g->unk_18 = 0;
}
BOOL Ov015Result_Update(Ov015Result *self) {
    BOOL r = TRUE;
    switch (self->state) {
    case 0:
        Ov002Stage_Create();
        gOv002Stage->unk_1a = 0;
        gOv002Stage->unk_130 = 1;
        gOv002Stage->unk_134 = 2;
        self->mode = gOv015Globals.mainSeq->unk_08;
        switch (self->mode) {
        case 1:
            func_ov015_0220f878(self);
            Ov015_SetStageSkip(0x51000);
            self->unk_0c = 0x50000;
            break;
        case 0:
            func_ov015_0220fb78(self);
            Ov015_SetStageSkip(0x14a000);
            self->unk_0c = 0x79000;
            break;
        default:
            Ov002Vt_021f0694_New(0);
            self->unk_0c = 0;
            break;
        }
        self->state = 10;
    case 10:
        if (gOv002Stage != NULL) Ov002Stage_Update(gOv002Stage);
        {
            s32 v = self->unk_0c;
            Ov002Stage *g = gOv002Stage;
            if (v <= g->unk_d4 || v > g->unk_d0) {
                break;
            }
        }
        func_ov015_0220e634(self->panel, self->mode);
        gOv002Stage->unk_128 = 0;
        self->state = 0x14;
    case 0x14: {
        BOOL ok = TRUE;
        switch (self->panel->mode) {
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
            Ov015_SetStageSkip(-1);
            Ov002Vt_021f0694_New(gOv002Stage->unk_d0);
            self->state = 0x1e;
        }
        if (gOv002Stage != NULL) Ov002Stage_Update(gOv002Stage);
        break;
    }
    case 0x1e: {
        BOOL busy;
        if (gOv002Stage == NULL) {
            busy = 0;
        } else {
            busy = Ov002Stage_Update(gOv002Stage);
        }
        if (busy == 0) {
            Ov002Stage_Delete();
            Ov015Fade_Reset(Ov015_GetFade());
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
