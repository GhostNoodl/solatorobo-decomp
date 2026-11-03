#include "ov000/VObj.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/HeapScope.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/MsgEntry.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[4];
    VObj *unk_04;
    u8 pad_08[0xc];
    VObj *unk_14;
    VObj *unk_18;
    VObj *unk_1c;
    void *unk_20;
} Obj021b8ecc;

extern "C" {

void func_ov000_0214bc10(void);
void func_ov000_0214c210(void);

void Obj021b8ecc_Release(Obj021b8ecc *self) {
    HEAP_DELETE_VOBJ(self->unk_18);
    HEAP_DELETE_VOBJ(self->unk_1c);
    HEAP_DELETE_VOBJ(self->unk_14);
    HEAP_DELETE_MODEL(self->unk_20);
    HEAP_DELETE_VOBJ(self->unk_04);
    func_ov000_0214bc10();
    func_ov000_0214c210();
}

}

typedef struct {
    u8 pad_00[4];
    VObj *unk_04;
    s32 state;
    s32 mode;
    u16 unk_10;
    u16 unk_12;
    VObj *unk_14;
    TextWin *unk_18;
    TextWin *unk_1c;
    Model *unk_20;
    s32 timer;
    s32 v28;
    s32 v2c;
    s32 v30;
    s32 v34;
    s32 v38;
} Obj021b9010;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits021b9010;

extern "C" {
void *Heap_Alloc(u32 size);
extern char *data_ov000_021cc858[];
extern void *gMsgRes;
extern u8 ResHandle_vtbl[];
extern u8 TextWin_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 Menu021ca94c_vtbl[];
extern void *gSndMgr;
void LangData_LocalizePath(void *buf, const char *s);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214c270(void);
BOOL func_ov000_0214bc6c(void);
s32 func_ov000_0214bc94(void);
void *func_02061d54(s32 id);
void *func_02061df0(u16 id);
void *func_02061e7c(u16 id);
void *MsgRes_GetString(void *g, void *id);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void *ResList_FindType2(s32 a, void *b);
BOOL ActorMgr_FindPlayer(void);
void Robo021ca458_RestoreHp(void);
BOOL Model_IsReady(void *m, s32 a);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void *func_ov000_0214c064(u16 id);
void Text_ScanTags(void *a, s32 b, void *c, void *fn);
void func_ov000_0214c668(VObj *o, u16 a);
BOOL func_ov000_0214c6a0(void *o);

static inline TextWin *NewTextWin_021b9010(void) {
    TextWin *p = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, TextWin_vtbl);
        TextWin_Init(p);
    }
    return p;
}

static inline void TextWinStart_021b9010(TextWin *w, void *text) {
    w->str = (u32)text;
    w->unk_4c = Text_Measure(w->font, w->spacing, w->str, &w->width, &w->height, (s8)w->unk_37 != 0);
    gGfxMgr->unk_004 = ((s32)w->font);
}

static inline s32 Ease_021b9010(s32 t, s32 d) {
    s32 r;
    if (t < 0) {
        t = 0;
    }
    r = FX_Div(t << 12, d);
    if (r >= 0x1000) {
        r = 0x1000;
    }
    return FX_SinCosTable_[((r * 0x4000) >> 16) * 2];
}

static inline BOOL IsA_021b9010(s32 v) {
    return (v == 0x14 || (u32)(v - 0x16) <= 1) ? TRUE : FALSE;
}

static inline BOOL Idle_021b9010(VObj *o) {
    return LFLD(Bits021b9010, o, 0xc).b0 == 0 ? TRUE : FALSE;
}

BOOL func_ov000_021b9010(Obj021b9010 *self) {
    char buf[0x20];
    MsgEntryEx tb;

    switch (self->state) {
    case 1: {
        VObj *p = (VObj *)Heap_Alloc(0x4c);
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, ResHandle_vtbl);
            p->vfunc_08();
        }
        self->unk_04 = p;
        LangData_LocalizePath(buf, data_ov000_021cc858[0]);
        LFLD(s32, self->unk_04, 0x44) = 7;
        self->unk_04->vfunc_1c(buf);
        func_ov000_0214bb80();
        func_ov000_0214c1ac();
        self->state = 2;
        break;
    }
    case 2:
        if (!func_ov000_0214c270()) {
            break;
        }
        if (!self->unk_04->vfunc_2c()) {
            break;
        }
        if (!func_ov000_0214bc6c()) {
            break;
        }
        self->state = 4;
    case 4: {
        s32 v = gSceneCmd->unk_98;
        void *text;
        void *text1;
        Model *m;
        VObj *o;
        if (!IsA_021b9010(v) && (u32)(v - 0x11) > 2) {
            break;
        }
        if (self->mode <= 1) {
            text = func_02061d54(0x8a);
        } else {
            text = func_02061d54(0x8b);
        }
        text1 = MsgRes_GetString(gMsgRes, text);
        self->unk_18 = NewTextWin_021b9010();
        self->unk_18->font = 4;
        self->unk_18->unk_2c = 0;
        TextWinStart_021b9010(self->unk_18, text1);
        self->unk_18->unk_vf14();
        self->unk_18->flags |= 0x40;
        self->unk_18->flags |= 0x40000000;
        self->unk_18->flags |= 4;
        if (self->mode <= 1) {
            text = func_02061df0(self->unk_10);
        } else {
            text = func_02061e7c(self->unk_10);
        }
        self->unk_1c = NewTextWin_021b9010();
        self->unk_1c->font = 8;
        self->unk_1c->unk_2c = 0;
        TextWinStart_021b9010(self->unk_1c, text);
        self->unk_1c->unk_vf14();
        self->unk_1c->flags |= 0x40;
        self->unk_1c->flags |= 0x40000000;
        self->unk_1c->flags |= 4;
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            const char *nm = data_ov000_021cc858[1];
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, nm, 0);
        }
        self->unk_20 = m;
        TexObj_SetRes(self->unk_20, ResList_FindType2(self->unk_04->vfunc_10(), self->unk_20->unk_04c));
        self->unk_20->flags |= 2;
        TexObj_SelectImage(self->unk_20, 0, 1);
        if (self->mode == 1 || self->mode == 3) {
            self->unk_20->flags |= 2;
            TexObj_SelectImage(self->unk_20, 0, 0);
            if (ActorMgr_FindPlayer()) {
                Robo021ca458_RestoreHp();
            }
        }
        func_ov000_0214bc94();
        o = (VObj *)Heap_Alloc(0x21c);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, UiObj_vtbl);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, Menu021ca94c_vtbl);
            VOBJ_SET_VTABLE((u8 *)o + 0x90, TextWin_vtbl);
            TextWin_Init((u8 *)o + 0x90);
            VOBJ_SET_VTABLE((u8 *)o + 0x148, TextWin_vtbl);
            TextWin_Init((u8 *)o + 0x148);
            o->vfunc_28();
        }
        self->unk_14 = o;
        o->vfunc_08();
        LFLD(s16, self->unk_14, 0x68) = -0x91a;
        self->state = 10;
        break;
    }
    case 10:
        if (!Model_IsReady(self->unk_20, 0xffff)) {
            break;
        }
        self->state = 11;
    case 11:
        if (!Model_IsReady(self->unk_20, 0xffff)) {
            break;
        }
        if (self->mode == 0 || self->mode == 2) {
            if (self->timer == 0) {
                SndMgr_PlayVolume(gSndMgr, 0x25, -1, -1, -1);
            }
            if (++self->timer > 0xb4) {
                self->timer = 0;
                self->state = 12;
                break;
            }
            self->v28 = Ease_021b9010(self->timer, 0x3c000);
            self->v2c = Ease_021b9010(self->timer, 0x3c000);
            self->v30 = Ease_021b9010(self->timer - 0x1e, 0x3c000);
            self->v34 = Ease_021b9010(self->timer - 0x5a, 0x5a000);
        } else {
            if (self->timer == 0) {
                SndMgr_PlayVolume(gSndMgr, 0x26, -1, -1, -1);
            }
            if (++self->timer > 0x78) {
                self->timer = 0;
                self->state = 12;
                break;
            }
            self->v28 = Ease_021b9010(self->timer, 0x1e000);
            self->v2c = Ease_021b9010(self->timer - 0x3c, 0xf000);
            self->v30 = Ease_021b9010(self->timer - 0x4b, 0xf000);
            self->v34 = Ease_021b9010(self->timer - 0x3c, 0xf000);
            self->v38 = Ease_021b9010(self->timer - 0x5a, 0x1e000);
        }
        break;
    case 12:
        if (++self->timer > 0x3c) {
            self->timer = 0;
            self->v38 = 0;
            self->v34 = 0;
            self->v30 = 0;
            self->v2c = 0;
            self->v28 = 0;
            self->state = 13;
        }
        break;
    case 13:
        if (self->mode == 0 || self->mode == 2) {
            s32 v;
            if (++self->timer > 0x28) {
                self->timer = 0;
                self->state = 0x11;
                break;
            }
            v = Ease_021b9010(self->timer, 0x28000);
            self->v28 = v;
            self->v2c = v;
            self->v30 = v;
            self->v34 = v;
        } else {
            s32 v;
            if (++self->timer > 0x3c) {
                self->timer = 0;
                if (self->mode == 3) {
                    self->state = 0x10;
                } else {
                    self->state = 0x11;
                }
                break;
            }
            self->v38 = Ease_021b9010(self->timer, 0x1e000);
            self->v2c = Ease_021b9010(self->timer - 0x2d, 0xf000);
            self->v30 = Ease_021b9010(self->timer - 0x1e, 0xf000);
            v = Ease_021b9010(self->timer - 0x1e, 0x1e000);
            self->v28 = v;
            self->v34 = v;
        }
        break;
    case 16: {
        VObj *o = self->unk_14;
        if (o == NULL) {
            self->state = 0x11;
            break;
        }
        switch (self->unk_12) {
        case 0:
            if (Idle_021b9010(o)) {
                self->unk_12++;
            }
            break;
        case 0xf:
            MsgEntry_Init(&tb);
            tb.vals[0] = 0;
            tb.vals[1] = 0;
            tb.vals[2] = 0;
            tb.vals[3] = 0;
            Text_ScanTags(func_ov000_0214c064(self->unk_10), 1, &tb, (void *)func_ov000_0214dc20);
            func_ov000_0214c668(self->unk_14, tb.vals[3]);
            self->unk_12 = 0x10;
            MsgEntry_Release(&tb);
            break;
        case 0x10:
            if (!func_ov000_0214c6a0(o)) {
                self->unk_12++;
            }
            break;
        case 0x4c:
            LFLD(u32, o, 0xc) |= 2;
            self->unk_12 = 0x4d;
            break;
        case 0x4d:
            break;
        default:
            self->unk_12++;
            break;
        }
        if (!self->unk_14->vfunc_1c()) {
            HEAP_DELETE_VOBJ(self->unk_14);
            self->state = 0x11;
        }
        break;
    }
    case 17:
        return FALSE;
    }
    return TRUE;
}
}
