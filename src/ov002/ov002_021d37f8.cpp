#include "ov002/ov002.h"

extern "C" {

static inline BOOL ov002_021d37f8_fade(void) {
    return (gFadeState[3] == 4 || gFadeState[1] == 4) ? TRUE : FALSE;
}
static inline bool ov002_021d37f8_idle(void) {
    BOOL r;
    if (gFadeState[3] == 0 && gFadeState[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}
static inline BOOL ov002_021d37f8_on(void *p) {
    BOOL r;
    if (FIELD(p, 0x28, s32) != 1) {
        r = FALSE;
    } else {
        r = FIELD(p, 0x30, s32);
    }
    return r ? TRUE : FALSE;
}
static inline BOOL ov002_021d37f8_busy(FieldPlayer *t) {
    void *p = t->unk_118;
    if (p == NULL) {
        return FALSE;
    }
    return ov002_021d37f8_on(p) ? TRUE : FALSE;
}

static inline void ov002_021d37f8_stop(FieldPlayer *t) {
    if (t->unk_118 != NULL) {
        func_ov000_0216f844(t->unk_118, 0);
    }
}

void LibraryViewer_ShowPage(Task021ef91c *self) {
    void *res;
    void *m;
    if (self->unk_c4 != NULL) {
        return;
    }
    if (self->unk_c8 == NULL) {
        return;
    }
    res = (void *)self->unk_c8->vfunc_10();
    if (res == NULL) {
        return;
    }
    if (!func_ov002_isMode4b() && !ov002_021d37f8_idle()) {
        return;
    }
    if (gMessageQueue != NULL && ov002_021d37f8_busy(gMessageQueue)) {
        ov002_021d37f8_stop(gMessageQueue);
        return;
    }
    GfxSys_StartFadeOut(0, 0, 1);
    GfxSys_StartFadeIn(0xc000, 0, 1);
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        PlttRes_Init_02041218((PlttRes *)((u8 *)m + 0x88));
        TexObj_Init((Model *)m, NULL, 0);
    }
    self->unk_c4 = (Model *)m;
    TexObj_SetRes((Model *)m, res);
    self->unk_c4->flags |= 2;
    self->unk_c4->unk_150 = -0x2000;
    TexObj_SelectImage((Model *)self->unk_c4, 2, 0);
}

}
