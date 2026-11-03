#include "ov002/ov002.h"

extern "C" {


extern const char data_ov002_021efaa0[];
extern const char data_ov002_021efaad[];

typedef struct Pair021efa94 { const char *a; const char *b; s32 scale; } Pair021efa94;

extern const Pair021efa94 data_ov002_021efa94;
const Pair021efa94 data_ov002_021efa94 = { data_ov002_021efaa0, data_ov002_021efaad, FX_Div(256 << 12, 15 << 12) };

void MsgBox_Init(void *o);

void MsgBox_Open(void *o, u16 id, const char *a, const char *b, int z);

static inline BOOL ov002_isIdle637c(void) {
    return FIELD(data_ov000_021ccd70, 4, void *) == NULL;
}

static inline BOOL ov002_moving637c(void *g) {
    return !(FIELD(g, 0x98, s32) == FIELD(g, 0xa4, s32) && FIELD(g, 0xb3, s8) == 0);
}

static inline BOOL ov002_has74_637c(void *g) {
    return FIELD(g, 0x74, void *) != NULL;
}

static inline BOOL ov002_busy637c(void *g) {
    return ov002_has74_637c(g) != FALSE;
}

static inline BOOL ov002_unsel637c(void *g) {
    return FIELD(g, 0xc, Bits32).b0 == 0;
}

static inline void *ov002_cursor637c(void *g) {
    u8 *p = FIELD(g, 0x98, u8 *);
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = FIELD(g, 0xb1, s8);
        while (n-- != 0) {
            p = FIELD(p, 0x2c, u8 *);
        }
    }
    return p;
}

static inline void *ov002_new637c(void) {
    void *o = Heap_Alloc(0x2c);
    if (o != NULL) {
        *(VFunc **)o = data_ov002_021efb04;
        MsgBox_Init(o);
    }
    return o;
}

void Task021efc24_UpdateActive(Task021efc24 *self) {
    s32 z = 0;
    void *g;
    u16 keys;
    u8 *p;
    void *o;
    Task021efba4 *x;
    if (self->unk_5c != NULL) {
        return;
    }
    if (!ov002_isIdle637c()) {
        return;
    }
    g = self->unk_50;
    if (g != NULL) {
        if (ov002_moving637c(g)) {
            return;
        }
        if (!((VObj *)g)->vfunc_0c()) {
            return;
        }
    }
    g = self->unk_50;
    keys = data_02097dc8->trig;
    if (ov002_unsel637c(g) && (keys & 2)) {
        z = -1;
        SndMgr_PlayVolume(data_02097e4c, 0x1f, z, z, z);
        self->unk_4c->flags |= 2;
        self->unk_50->flags |= 2;
        self->unk_54->flags |= 2;
        GfxSys_StartFadeOut(self->unk_50->openLen, 2, z);
        self->unk_04_0 = 1;
        return;
    }
    if (!(keys & 0x800)) {
        return;
    }
    if (ov002_busy637c(g)) {
        return;
    }
    p = (u8 *)ov002_cursor637c(g);
    if (p == NULL) {
        return;
    }
    self->unk_5c = (VObj *)(ov002_new637c());
    MsgBox_Open(self->unk_5c, FIELD(p, 6, u16) & 0xfff, data_ov002_021efa94.a, data_ov002_021efa94.b, z);
    self->unk_50->flags |= 4;
    self->unk_54->flags |= 4;
    self->unk_54->flags |= 2;
    x = (Task021efba4 *)Task_FindById(0x1b);
    if (x != NULL && x->hud != NULL) {
        Ov002Hud_SetRow(x->hud, z, z);
    }
}

}
