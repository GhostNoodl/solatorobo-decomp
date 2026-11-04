#include "ov002/ov002.h"
#include "ov002/StaffRoll.h"

extern "C" {

// The staff roll's .bss: the run list head, the staff object, the run list tail and the per-kind
// node lists. All of them are reached through the 0x021f0fa0 pool literal plus offsets (a
// constant index into data_ov002_021f0fac as base + 0x20), so they are defined before the first
// function. MWCC lays these three out in the reverse of this order.
Ov002StaffNode *data_ov002_021f0fa8;
Ov002Staff *gOv002Staff;
Ov002StaffNode *gOv002StaffPool;
Ov002StaffNode *data_ov002_021f0fac[9];

}

// ---- merged from ov002_021ecb90.cpp
namespace m_021ecb90 {
extern "C" {

int STD_CompareString(const char *a, const char *b);

static inline BOOL ov002_Tag_IsActive(Ov002StaffModel *t) {
    return t->clock.flags.active == 1 ? TRUE : FALSE;
}

static inline BOOL ov002_Tag_IsDone(Ov002StaffModel *t) {
    return t->clock.flags.done == 1 ? TRUE : FALSE;
}

static inline s32 ov002_Tag_Sin(s32 t) {
    if (t >= 0x1000) {
        t = 0x1000;
    }
    return FX_SinCosTable_[((t << 14) >> 16) * 2];
}

static inline BOOL ov002_Tag_Crossed(Ov002StaffModel *t, s32 time) {
    if (t->clock.timer >= time && time > t->clock.prevTimer) {
        return TRUE;
    }
    return FALSE;
}

BOOL Ov002StaffModel_Run(Ov002StaffModel *self) {
    BOOL result = TRUE;
    Ov002StaffModel *p;

    switch (self->entry->unk_0e) {
    case 0:
        if (self->clock.state == 3) {
            self->alpha = FX_MUL(self->maxAlpha << 12, 0x1000 - ov002_Tag_Sin(FX_Div(self->clock.timer, data_ov002_021f0d88.tagFadeOut))) >> 12;
            if (self->alpha == 0) {
                result = FALSE;
                break;
            }
        } else {
            self->alpha = FX_MUL(self->maxAlpha << 12, ov002_Tag_Sin(FX_Div(self->clock.timer, data_ov002_021f0d88.tagFadeIn))) >> 12;
        }
        result = TRUE;
        break;
    case 1:
        for (p = (Ov002StaffModel *)data_ov002_021f0fac[5]; p != NULL; p = (Ov002StaffModel *)p->link) {
            if (ov002_Tag_IsActive(p) && p != self) {
                if (self->entry->str != NULL && p->entry->str != NULL) {
                    if (STD_CompareString(self->entry->str, p->entry->str) == 0) {
                        break;
                    }
                } else if (self->screen == p->screen) {
                    break;
                }
            }
        }
        if (p != NULL) {
            p->clock.flags.done = 1;
        }
        return FALSE;
    }
    if (self->clock.state == 3) {
        return result;
    }
    switch (self->entry->unk_10) {
    case 0: {
        s32 t = self->entry->unk_12;
        if (t == 0) {
            t = data_ov002_021f0d88.tagTime;
        }
        if (ov002_Tag_Crossed(self, t << 12)) {
            self->clock.flags.done = 1;
        }
        break;
    }
    case 1:
        break;
    case 2:
        for (p = (Ov002StaffModel *)data_ov002_021f0fac[5]; p != NULL; p = (Ov002StaffModel *)p->link) {
            if (ov002_Tag_IsActive(p) && p != self) {
                if (!ov002_Tag_IsDone(p)) {
                    self->clock.flags.done = 1;
                    break;
                }
            }
        }
        break;
    case 3:
        for (p = (Ov002StaffModel *)data_ov002_021f0fac[5]; p != NULL; p = (Ov002StaffModel *)p->link) {
            if (ov002_Tag_IsActive(p) && p != self && p->screen == self->screen) {
                if (!ov002_Tag_IsDone(p)) {
                    self->clock.flags.done = 1;
                    break;
                }
            }
        }
        break;
    }
    if (ov002_Tag_IsDone(self) && self->clock.state != 3) {
        self->clock.next = 3;
    }
    return result;
}

}
}  // namespace m_021ecb90

// ---- merged from ov002_021eceb8.cpp
namespace m_021eceb8 {
extern "C" {

typedef struct Bits021eceb8 {
    u32 lo : 2;
    u32 b : 5;
    u32 c : 6;
    u32 hi : 19;
} Bits021eceb8;

static inline bool isMode3(Ov002StaffModel *self) {
    return self->clock.state == 3;
}

void Ov002StaffModel_Render(Ov002StaffModel *self) {
    s32 x;
    s32 y;
    s32 z;
    Model *model;
    ModelRes *res;
    ModelPart *anim;
    void *arg;
    ModelPartRes *t;
    if (self->model == NULL || !self->alpha) {
        return;
    }
    x = self->x & -0x1000;
    y = self->y & -0x1000;
    {
        BOOL m3 = isMode3(self);
        if (m3) {
            z = -0x2000;
        } else {
            z = -0x1ccd;
        }
    }
    // Two fields of the model's flags word: the polygon id and the alpha.
    FIELD(self->model, 0x6c, Bits021eceb8).c = (u32)Gfx3DState_NextPolyId(gGfxSys->unk_8b0);
    FIELD(self->model, 0x6c, Bits021eceb8).b = self->alpha;
    {
        Model *m = self->model;
        m->x = x;
        m->y = y;
    }
    self->model->unk_150 = z;
    model = self->model;
    if ((res = model->res) == NULL) {
        return;
    }
    anim = NULL;
    if (model->numParts > 0) {
        anim = model->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)FIELD(e, 0xc, void *));
    }
    TexObj_DrawCell(model, arg, anim, 0);
}

}
}  // namespace m_021eceb8

// ---- merged from ov002_021ecfd8.cpp
namespace m_021ecfd8 {
extern "C" {

void Ov002StaffPhoto_Init(Ov002StaffPhoto *self) {
    self->photo = NULL;
}

void Ov002StaffPhoto_Release(Ov002StaffPhoto *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_WITH(self->photo, TwlLoader_Unload);
    HEAP_POP(saved);
}

BOOL Ov002StaffPhoto_CanLoad(void) {
    return TRUE;
}

BOOL Ov002StaffPhoto_Load(Ov002StaffPhoto *self) {
    switch (self->clock.sub) {
    case 0: {
        void *p = Heap_Alloc(0x3c);
        if (p != NULL) {
            p = Twl0214b6d8_Init(p);
        }
        self->photo = p;
        Loader_Start(p, data_ov002_021f0d88.photo);
        self->clock.sub++;
        break;
    }
    case 1:
        TwlLoader_Load(self->photo);
        if (Loader_IsDone(self->photo)) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL Ov002StaffPhoto_Setup(Ov002StaffPhoto *self) {
    if (self->clock.sub != 0) {
        return FALSE;
    }
    self->screen = self->entry->unk_0c;
    self->maxAlpha = 0x1f;
    return TRUE;
}

static inline BOOL func_ov002_021ed0ec_is3(Ov002StaffPhoto *self) {
    return self->clock.state == 3 ? TRUE : FALSE;
}
void Ov002StaffPhoto_Render(Ov002StaffPhoto *self) {
    if (self->photo == NULL || self->alpha == 0) {
        return;
    }
    {
        VecFx32 b = data_ov002_021ef124;
        VecFx32 a;
        a.x = self->x;
        a.y = self->y;
        a.z = self->z;
        a.x = (a.x & ~0xfff) + 0x80000;
        a.y = (a.y & ~0xfff) + 0x60000;
        if (func_ov002_021ed0ec_is3(self)) {
            a.z = -0x2000;
        } else {
            a.z = -0x1ccd;
        }
        Gfx_DrawTexQuad(&a, &b, self->alpha, Loader_GetTexAddr(self->photo));
    }
}

void Ov002StaffText_Init(Ov002StaffText *self) {
    self->line[0].text = 0;
    self->line[1].text = 0;
    self->line[0].x = 0;
    self->line[0].y = 0;
    self->line[0].z = 0;
    self->line[1].x = 0;
    self->line[1].y = 0;
    self->line[1].z = 0;
    self->alpha = 0x1f;
}

void Ov002StaffText_Release(Ov002StaffText *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->line[0].text);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->line[1].text);
    HEAP_POP(saved);
}

}

extern "C" {

extern VFunc TextWin_vtbl[];
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_RenderToVram(void *p);
char *Str_FindCharMb(char *s, int c);

static inline Ov002Text2 *ov002_021ed270_newText(char *str) {
    Ov002Text2 *t = (Ov002Text2 *)Heap_Alloc(0xb8);
    if (t != NULL) {
        *(VFunc **)t = TextWin_vtbl;
        TextWin_Init(t);
    }
    t->font = 4;
    t->str = (s32)str;
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, t->unk_37 != 0);
    gGfxMgr->unk_004 = t->font;
    return t;
}

static inline void ov002_021ed270_create(Ov002StaffText *self, char *str) {
    Ov002Text2 *t;
    char *sub = Str_FindCharMb(str, '/');
    if (sub) {
        *sub = 0;
        sub++;
    }
    t = ov002_021ed270_newText(str);
    self->line[0].text = t;
    t->flags |= 0x40;
    self->line[0].text->flags |= 0x1000000;
    self->line[0].text->flags |= 4;
    if (sub != NULL) {
        t = ov002_021ed270_newText(sub);
        self->line[1].text = t;
        t->flags |= 0x40;
        self->line[1].text->flags |= 0x1000000;
        self->line[1].text->flags |= 4;
    }
}

void Ov002StaffText_Start(Ov002StaffText *self) {
    Ov002StaffEntry *info = self->entry;
    switch (info->unk_0c) {
    case 0:
        ov002_021ed270_create(self, info->str);
        self->line[0].text->color0 = 0x77df;
        self->line[0].text->color1 = 0x67e;
        self->line[0].text->unk_78 = 0x9000;
        self->line[0].y = data_ov002_021f0d88.w24;
        self->screen = 0;
        break;
    case 1:
        ov002_021ed270_create(self, info->str);
        self->line[0].y = data_ov002_021f0d88.w24;
        self->screen = 0;
        break;
    case 2:
        ov002_021ed270_create(self, info->str);
        self->line[0].text->vfunc_14();
        self->line[0].y = 0x60000 - ((self->line[0].text->height >> 1) << 12);
        if (self->line[1].text != NULL) {
            s32 h;
            self->line[1].text->vfunc_14();
            h = self->line[1].text->height;
            self->line[1].y = self->line[0].y + h + ((h + 2) << 12);
        }
        self->screen = 0;
        break;
    case 3:
        ov002_021ed270_create(self, info->str);
        self->line[0].text->color0 = 0x339f;
        self->line[0].y = data_ov002_021f0d88.w24;
        if (self->line[1].text != NULL) {
            s32 h;
            self->line[1].text->color0 = 0x7fff;
            h = self->line[1].text->height;
            self->line[1].y = self->line[0].y + h + ((h + 2) << 12);
        }
        self->screen = 0;
        break;
    case 4:
        ov002_021ed270_create(self, info->str);
        self->line[0].y = data_ov002_021f0d88.w24;
        self->screen = 0;
        break;
    }
    if (self->line[0].text != NULL) {
        Ov002StaffText *m;
        self->line[0].x = data_ov002_021f0d88.w20 - ((self->line[0].text->width >> 1) << 12);
        m = gOv002Staff->text;
        if (m != NULL) {
            self->line[0].y += m->line[0].y & 0xfff;
        }
        TextWin_RenderToVram(self->line[0].text);
    }
    if (self->line[1].text != NULL) {
        Ov002StaffText *m;
        self->line[1].x = data_ov002_021f0d88.w20 - ((self->line[1].text->width >> 1) << 12);
        m = gOv002Staff->text;
        if (m != NULL) {
            self->line[1].y += m->line[0].y & 0xfff;
        }
        TextWin_RenderToVram(self->line[1].text);
    }
}

}

extern "C" {

static inline BOOL ov002_021edab4_reached(Ov002StaffText *self, s32 lim) {
    BOOL r;
    if (self->clock.timer >= lim << 12 && lim << 12 > self->clock.prevTimer) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL ov002_021edab4_flag3(Ov002StaffText *self) {
    return self->clock.flags.done == 1 ? TRUE : FALSE;
}

BOOL Ov002StaffText_Run(Ov002StaffText *self) {
    BOOL r = TRUE;
    s32 dt;
    if (self->line[0].text == NULL) {
        return FALSE;
    }
    gOv002Staff->text = self;
    dt = self->clock.step;
    switch (self->entry->unk_0c) {
    case 0:
    case 1:
    case 3:
    case 4:
        r = FALSE;
        if (self->line[0].text != NULL && self->line[0].y > -0x10000) {
            self->line[0].y += FX_MUL(data_ov002_021f0d88.w10, dt);
            r = TRUE;
        }
        if (self->line[1].text != NULL && self->line[1].y > -0x10000) {
            self->line[1].y += FX_MUL(data_ov002_021f0d88.w10, dt);
            r = TRUE;
        }
        break;
    case 2:
        if (self->clock.state == 3) {
            s32 t = FX_Div(self->clock.timer, data_ov002_021f0d88.w4);
            if (t >= 0x1000) {
                t = 0x1000;
            }
            self->alpha = (s32)(((s64)(0x1000 - FX_SinCosTable_[((s32)(t << 14) >> 16) * 2]) * 0x1f000 + 0x800) >> 12) >> 12;
            if (self->alpha == 0) {
                r = FALSE;
                break;
            }
        } else {
            s32 t = FX_Div(self->clock.timer, data_ov002_021f0d88.w0);
            if (t >= 0x1000) {
                t = 0x1000;
            }
            self->alpha = (s32)(((s64)FX_SinCosTable_[((s32)(t << 14) >> 16) * 2] * 0x1f000 + 0x800) >> 12) >> 12;
        }
        r = TRUE;
        break;
    }
    if (self->clock.state == 3) {
        return r;
    }
    if (self->entry->unk_0c == 2) {
        s32 lim = self->entry->unk_0e;
        if (lim == 0) {
            lim = data_ov002_021f0d88.w1c;
        }
        if (ov002_021edab4_reached(self, lim)) {
            self->clock.flags.done = 1;
        }
    }
    if (ov002_021edab4_flag3(self) && self->clock.state != 3) {
        self->clock.next = 3;
    }
    return r;
}

}
}  // namespace m_021ecfd8

// ---- merged from ov002_021edcec.cpp
namespace m_021edcec {
extern "C" {

void Ov002StaffText_Render(Ov002StaffText *self, int mode) {
    s32 x;
    s32 y;
    if (self->line[0].text == NULL || self->alpha == 0) {
        return;
    }
    x = self->line[0].x >> 12;
    y = self->line[0].y >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    self->line[0].text->polyId = Gfx3DState_NextPolyId(gGfxSys->unk_8b0);
    self->line[0].text->alpha = self->alpha;
    self->line[0].text->vfunc_20(x, y);
    self->line[0].text->posZ = -0x1000;
    self->line[0].text->vfunc_90();
    if (self->line[1].text == NULL) {
        return;
    }
    x = self->line[1].x >> 12;
    y = self->line[1].y >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    self->line[1].text->polyId = Gfx3DState_NextPolyId(gGfxSys->unk_8b0);
    self->line[1].text->alpha = self->alpha;
    self->line[1].text->vfunc_20(x, y);
    self->line[1].text->posZ = -0x1000;
    self->line[1].text->vfunc_90();
}

}
}  // namespace m_021edcec

// ---- merged from ov002_021ede54.cpp
namespace m_021ede54 {
extern "C" {

void Ov002Vt_021f0e14_Init(void) {
}

void Ov002Vt_021f0e14_Release(void) {
}

}
}  // namespace m_021ede54

// ---- merged from ov002_021ede5c.cpp
namespace m_021ede5c {
extern "C" {

void SndMgr_LoadBgm(SndMgr *mgr, s32 seq);

s32 SndMgr_GetSeqVolume_0204a2c8(SndMgr *mgr, s32 seq);

void SndMgr_MoveBgmVolume(SndMgr *mgr, int volume, int frames);

void SndMgr_StopSeqNo(SndMgr *mgr, int playerNo, int fadeFrames);

void SndMgr_SetStrmVolume_0204a2a8(SndMgr *mgr, int b, u16 c);

BOOL Ov002Vt_021f0e14_Run(Ov002StaffNode *self) {
    BOOL busy = FALSE;
    Ov002StaffEntry *d = self->entry;
    switch (d->unk_0c) {
    case 0:
        if (self->clock.sub == 0) {
            SndMgr_LoadBgm(gSndMgr, d->seq);
            self->clock.sub++;
        }
        if (self->entry->unk_0e != 0) {
            s32 t = FX_Div(self->clock.timer, self->entry->unk_0e << 12);
            s32 tot;
            s32 cur;
            if (t >= 0x1000) {
                t = 0x1000;
            }
            tot = SndMgr_GetSeqVolume_0204a2c8(gSndMgr, self->entry->seq);
            cur = FX_MUL(tot << 12, FX_SINCOS_TABLE[((t << 14) >> 16) * 2]) >> 12;
            SndMgr_MoveBgmVolume(gSndMgr, cur, 0);
            if (cur != tot) {
                busy = TRUE;
            }
        }
        break;
    case 1:
        SndMgr_StopSeqNo(gSndMgr, d->seq, d->unk_0e);
        break;
    case 2:
        SndMgr_SetStrmVolume_0204a2a8(gSndMgr, 100, d->unk_0e);
        break;
    case 3:
        {
            SndQueue *g = gSndQueue.queue;
            g->unk_80 = 0x8000;
            g->unk_7c = 0;
        }
        break;
    }
    return busy;
}

}
}  // namespace m_021ede5c

// ---- merged from ov002_021edf98.cpp
namespace m_021edf98 {
extern "C" {

static inline void func_ov002_021edf98_setC(Ov002Staff *p, s32 v) {
    if (p->clock.next != v) {
        p->clock.next = v;
    }
}
void Ov002Staff_Create(s32 id) {
    Ov002Staff *p = (Ov002Staff *)Heap_Alloc(0x30);
    int i;
    if (p != NULL) {
        p->clock.bits = 0;
        p->clock.state = 0;
        p->clock.next = 0;
        p->clock.sub = 0;
        p->clock.timer = 0;
        p->clock.prevTimer = 0;
        p->clock.step = 0x1000;
        p->id = id;
        p->nextStep = 0x1000;
        p->loader = NULL;
        func_ov002_021edf98_setC(p, 1);
    }
    gOv002Staff = p;
    gOv002StaffPool = NULL;
    data_ov002_021f0fa8 = NULL;
    for (i = 0; i < 9; i++) {
        data_ov002_021f0fac[i] = NULL;
    }
}

}
}  // namespace m_021edf98

// ---- merged from ov002_021ee024.cpp
namespace m_021ee024 {
extern "C" {


void SndMgr_StopStrm_0204a284(SndMgr *mgr, s32 fade);

void Ov002Staff_Delete(void) {
    void *saved;
    Ov002StaffNode *n;
    Ov002StaffNode *next;
    void *s2;
    Ov002Staff *x;
    void *s3;
    HEAP_PUSH(saved);
    x = gOv002Staff;
    if (x != NULL) {
        if (x != NULL) {
            SndMgr_StopStrm_0204a284(gSndMgr, -1);
            for (n = gOv002StaffPool; n != NULL; n = next) {
                s32 k = n->entry->kind;
                Ov002StaffNode *c;
                Ov002StaffNode *prev;
                next = n->next;
                prev = NULL;
                for (c = data_ov002_021f0fac[k]; c != NULL; c = c->link) {
                    if (c == n) {
                        if (prev == NULL) {
                            data_ov002_021f0fac[k] = n->link;
                        } else {
                            prev->link = n->link;
                        }
                        n->link = NULL;
                        break;
                    }
                    prev = c;
                }
                if (n->prev != NULL) {
                    n->prev->next = n->next;
                } else {
                    gOv002StaffPool = n->next;
                }
                if (n->next != NULL) {
                    n->next->prev = n->prev;
                } else {
                    data_ov002_021f0fa8 = n->prev;
                }
                n->prev = NULL;
                n->next = NULL;
                {
                    HEAP_PUSH(s2);
                    if (n != NULL) {
                        if (n != NULL) {
                            n->vfunc_04();
                        }
                    }
                    HEAP_POP(s2);
                }
            }
            {
                HEAP_PUSH(s3);
                DELETE_VOBJ(x->loader);
                HEAP_POP(s3);
            }
            Heap_Free(x);
        }
        gOv002Staff = NULL;
    }
    HEAP_POP(saved);
}

}
}  // namespace m_021ee024

// ---- merged from ov002_021ee1a8.cpp
namespace m_021ee1a8 {
typedef struct ov002_Disp021ee1a8 {
    u8 unk0[0xe];
    u8 unkE_0 : 2;
    u8 mode : 2;
    u8 unkE_4 : 4;
} ov002_Disp021ee1a8;

typedef struct ov002_Fade021ee1a8 {
    u8 unk0[4];
    s32 mode;
} ov002_Fade021ee1a8;

extern "C" {

extern char data_ov002_021f0e06[];
extern ov002_Disp021ee1a8 *gSceneCmd;

int sprintf(char *dst, const char *fmt, ...);
void Tbl_Format_02070874(char *dst, const char *fmt, ...);
void Ov002StaffLoader_Parse(Ov002StaffLoader *self);
BOOL Ov002Staff_SpawnEntries(Ov002Staff *self, u16 start, int count);
void Ov002Staff_UpdateNodes(Ov002Staff *self);

static inline BOOL ov002_Staff_IsPaused(Ov002Staff *s) {
    return s->clock.flags.paused == 1 ? TRUE : FALSE;
}

static inline void ov002_Staff_Update(Ov002Staff *s) {
    if (s->clock.next != 0) {
        s->clock.state = s->clock.next;
        s->clock.next = 0;
        s->clock.sub = 0;
        s->clock.timer = 0;
        s->clock.prevTimer = -1;
        s->clock.step = 0x1000;
    } else if (!ov002_Staff_IsPaused(s)) {
        s->clock.prevTimer = s->clock.timer;
        s->clock.timer += s->clock.step;
    }
}

static inline void ov002_Staff_SetNext(Ov002Staff *s, s32 state) {
    if (s->clock.state != state) {
        s->clock.next = state;
    }
}

void Ov002Staff_Step(void) {
    Ov002StaffLoader *o;
    Ov002Staff *s = (Ov002Staff *)gOv002Staff;

    ov002_Staff_Update(s);
    s->clock.flags.paused = 0;
    switch (s->clock.state) {
    case 1:
        ov002_Staff_SetNext(s, 4);
        break;
    case 4:
        switch (s->clock.sub) {
        case 0:
            s->clock.sub = 3;
            break;
        case 3: {
            char path[0x20];
            char num[8];
            char dir[0x20];
            s32 id;
            o = (Ov002StaffLoader *)Heap_Alloc(0x50);
            if (o != NULL) {
                *(VFunc **)o = (VFunc *)ResHandle_vtbl;
                o->vfunc_08();
                *(VFunc **)o = Ov002Vt_021f0f2c_vtbl;
                o->vfunc_08();
            }
            s->loader = o;
            id = s->id;
            LangData_LocalizePath(dir, data_ov002_021f0d88.dir2);
            sprintf(num, data_ov002_021f0e06, id);
            Tbl_Format_02070874(path, data_ov002_021f0d88.pathFmt, num);
            o->vfunc_24(dir, path);
            s->clock.sub = 4;
        }
        case 4:
            if (!s->loader->vfunc_2c()) {
                break;
            }
            Ov002StaffLoader_Parse(s->loader);
            s->nextStep = 0x1000;
            ov002_Staff_SetNext(s, 6);
            break;
        }
        break;
    case 6:
        switch (s->clock.sub) {
        case 0:
            gSceneCmd->mode = 2;
            GfxSys_StartFadeIn(1, 2, -1);
            s->spawned = 0;
            s->clock.sub++;
        case 1:
            if (!Ov002Staff_SpawnEntries(s, s->spawned, 0x20)) {
                s->spawned += 0x20;
                break;
            }
            ((ov002_Fade021ee1a8 *)gGfxSys)->mode = 2;
            s->clock.sub++;
            break;
        case 5:
            ov002_Staff_SetNext(s, 7);
            break;
        default:
            s->clock.sub++;
            break;
        }
        break;
    case 3:
    case 7:
        Ov002Staff_UpdateNodes(s);
        break;
    case 8:
        switch (s->clock.sub) {
        case 0:
            ((ov002_Fade021ee1a8 *)gGfxSys)->mode = 1;
            s->clock.sub++;
            return;
        case 5:
            GfxSys_StartFadeOut(1, 2, -1);
            ov002_Staff_SetNext(s, 2);
            return;
        default:
            s->clock.sub++;
            return;
        }
    }
    s->clock.step = s->nextStep;
}

}
}  // namespace m_021ee1a8

// ---- merged from ov002_021ee4d0.cpp
namespace m_021ee4d0 {
extern "C" {

void Ov002Staff_Draw(void) {
    Ov002Staff *o4 = gOv002Staff;
    BOOL flag = gGfxSys->unk_a30_4 ? TRUE : FALSE;
    Ov002StaffNode *v;
    if (o4->clock.state != 3 && o4->clock.state != 7) {
        return;
    }
    for (v = gOv002StaffPool; v != NULL; v = v->next) {
        v->vfunc_0c(flag);
    }
    if (o4->clock.state == 3) {
        Ov002Staff_DrawFade(o4);
    }
}

}
}  // namespace m_021ee4d0

// ---- merged from ov002_021ee55c.cpp
namespace m_021ee55c {
extern "C" {

void Ov002StaffNode_Link(Ov002StaffNode *node);

// Construction views of the node classes in StaffRoll.h (each constructor stores its vtable and
// calls the init slot 0x10).
struct N3_55c {
    VFunc *vt;
    Ov002StaffClock clock;
    Ov002StaffEntry *e;
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    N3_55c() {
        vt = Ov002Vt_021f0ef4_vtbl;
        clock.bits = 0; clock.state = 0; clock.next = 0; clock.sub = 0; clock.timer = 0; clock.prevTimer = 0; clock.step = 0x1000;
        ((VObj *)this)->vfunc_10();
    }
};

struct N3b_55c : N3_55c { u8 pad[0x34 - 0x24]; };

struct N4_55c : N3_55c {
    u8 pad[0x58 - 0x24];
    N4_55c() { vt = Ov002Vt_021f0e84_vtbl; ((VObj *)this)->vfunc_10(); }
};

struct N5_55c : N3_55c {
    u8 pad[0x4c - 0x24];
    N5_55c() { vt = Ov002Vt_021f0e4c_vtbl; ((VObj *)this)->vfunc_10(); }
};

struct N6_55c : N5_55c {
    u8 pad6[0x50 - 0x4c];
    N6_55c() { vt = Ov002Vt_021f0ebc_vtbl; ((VObj *)this)->vfunc_10(); }
};

struct N7_55c : N3_55c {
    u8 pad[0x34 - 0x24];
    N7_55c() { vt = Ov002Vt_021f0e14_vtbl; ((VObj *)this)->vfunc_10(); }
};

BOOL Ov002Staff_SpawnEntries(Ov002Staff *self, s32 start, s32 count) {
    Ov002StaffScript *hdr = self->loader->script;
    Ov002StaffEntry *e = (Ov002StaffEntry *)(hdr + 1) + start;
    s32 end = start + count;
    bool clipped = FALSE;
    N3_55c *o;
    s32 i;
    if (end >= hdr->count) {
        clipped = TRUE;
        end = hdr->count;
    }
    for (i = start; i < end; i++, e++) {
        switch (e->kind) {
        case 1:
        case 2:
        case 8:
            continue;
        case 3:
            o = new N3b_55c;
            break;
        case 4:
            o = new N4_55c;
            break;
        case 5:
            o = new N5_55c;
            break;
        case 6:
            o = new N6_55c;
            break;
        case 7:
            o = new N7_55c;
            break;
        }
        o->e = e;
        Ov002StaffNode_Link((Ov002StaffNode *)o);
    }
    return clipped;
}

}
}  // namespace m_021ee55c

// ---- merged from ov002_021ee7c8.cpp
namespace m_021ee7c8 {
extern "C" {

VObj *Ov002Vt_021f0ef4_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov002Vt_021f0ef4_vtbl;
    self->vfunc_14();
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021ee7c8

// ---- merged from ov002_021ee7f8.cpp
namespace m_021ee7f8 {
extern "C" {


static inline void ov002_unlink7f8(Ov002StaffNode *n) {
    s32 k = n->entry->kind;
    Ov002StaffNode *c;
    Ov002StaffNode *prev = NULL;
    for (c = data_ov002_021f0fac[k]; c != NULL; c = c->link) {
        if (c == n) {
            if (prev == NULL) {
                data_ov002_021f0fac[k] = n->link;
            } else {
                prev->link = n->link;
            }
            n->link = NULL;
            break;
        }
        prev = c;
    }
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        gOv002StaffPool = n->next;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        data_ov002_021f0fa8 = n->prev;
    }
    n->prev = NULL;
    n->next = NULL;
    {
        void *s2;
        HEAP_PUSH(s2);
        if (n != NULL) {
            if (n != NULL) {
                n->vfunc_04();
            }
        }
        HEAP_POP(s2);
    }
}

static inline BOOL ov002_flag3_7f8(Ov002Staff *self) {
    return self->clock.flags.done == 1 ? TRUE : FALSE;
}

void Ov002Staff_UpdateNodes(Ov002Staff *self) {
    Ov002StaffNode *n;
    Ov002StaffNode *next;
    switch (self->clock.sub) {
    case 0:
        n = gOv002StaffPool;
        self->text = NULL;
        for (; n != NULL; n = next) {
            next = n->next;
            if (!n->vfunc_08(&self->clock)) {
                ov002_unlink7f8(n);
            }
        }
        if (ov002_flag3_7f8(self) && self->clock.state != 3) {
            self->clock.next = 3;
        }
        if (self->clock.state != 3) {
            return;
        }
        if (self->clock.timer <= 0x78000) {
            return;
        }
        {
            Ov002StaffNode *m;
            Ov002StaffNode *mnext;
            for (m = gOv002StaffPool; m != NULL; m = mnext) {
                mnext = m->next;
                ov002_unlink7f8(m);
            }
        }
        self->clock.sub++;
        break;
    case 5:
        if (self->clock.state != 8) {
            self->clock.next = 8;
        }
        break;
    default:
        self->clock.sub++;
        break;
    }
}

}
}  // namespace m_021ee7f8
