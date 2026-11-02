#include "ov000/LoCommon.h"
#include "ov000/SceneRes.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g2d/g2d_Font.h"

extern "C" {

extern void *data_02fe152c;
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void func_0204c7d0(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *func_ov000_0219bf90(void);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd24.unk_08)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_0215123c(Lo021ca9c4 *self) {
    s32 s;
    if (self->fadeRatio == 0 || (s = self->state) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->vfunc_20();
    }
    if (self->unk_50 != NULL) {
        self->unk_50->vfunc_20();
    }
    if (self->unk_58 != NULL) {
        self->unk_58->vfunc_20();
    }
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov000_021512b4 is 23 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: register-only: the -0x191a depth constant swaps with bx (bx lives across the
// virtual calls, so it stays an object). History: docs/MATCHING.md rounds smW, qpH, raC, raE, mtA, cvA (search for
// the address); the full list is docs/UNMATCHED.md.
// func_ov000_021512b4 (0x2d8 bytes, the status-window text layout): 23 / 0 (raw / register-masked), round
// smW's b2 draft. The real signature is (obj, a, pos, c) (round smV; a and c are unused). Left: the -0x191a
// text-depth constant (ROM r6, ours r5) swaps with bx and the first (0x100 - w) >> 1 (ROM r5, ours r6).
// ramerge (round qpH, multi-target 34:6 47:5 71:5 76:6 151:6) finds exactly two fixes: bx (node 47) numbered
// after the first constant (node 76), or that constant numbered between h and bx in the named-local band.
// Neither is reachable: bx must outlive the virtual calls, so it is an object; reusing x for it, or a dead x
// with (x >> 12) at every use, turns it into an @ object, which is numbered even lower (30 / 0 both). A
// constant local (s32 z, also assigned twice) is propagated (23 / 0); an enum local is 115 / 62.
// Round raC: the depth store and text call in a PutText/SetDepth inline (23), PosX/PosY/CenterX getters
// (23; on bx 30), Model_SetPos written in place (77-174). The PlayPart(0xb) model read into a local m
// makes it a user variable (23, now m/bx swap); ramerge then wants bx numbered before self or the
// constant between m and bx, neither reachable.
// Round raE: ramerge on this draft: bx renumbered past the backend constant (node 76) or before self, or
// the constant between h and bx; bx lives across calls so it stays an object. A Model_PlayPartR with the
// resource held by the caller (the 021d1f70 fix) gives 26 (PlayPart(0xb)), 31 (PlayPart(0)), 42 (both).
// Round rgB: to get the depth constant between h and bx, all three go into one local struct ({bx, z, h} with z
// written after bx): z is still propagated (only bx and h are scalarized), so the result is 30 / 0, the same as an @ bx.
extern "C" {

u32 func_ov000_0214bf2c(u16 a);

}

#include "ov000/ModelPart.h"
#include "ov000/Task.h"

extern "C" {

struct LoTextWin {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual char *unk_vf24(char *p);
    virtual char *unk_vf28(char *p);
    virtual char *unk_vf2c(char *p);
    virtual char *unk_vf30(char *p);
    virtual char *unk_vf34(char *p);
    virtual char *unk_vf38(char *p);
    virtual char *unk_vf3c(char *p);
    virtual char *unk_vf40(char *p);
    virtual char *unk_vf44(char *p);
    virtual char *unk_vf48(char *p);
    virtual char *ParseEscape(char *p);
    virtual char *unk_vf50(char *p);
    virtual char *unk_vf54(char *p);
    virtual char *unk_vf58(char *p);
    virtual char *unk_vf5c(char *p);
    virtual char *unk_vf60(char *p);
    virtual char *unk_vf64(char *p);
    virtual char *unk_vf68(char *p);
    virtual char *unk_vf6c(char *p);
    virtual char *unk_vf70(char *p);
    virtual char *unk_vf74(char *p);
    virtual char *unk_vf78(char *p);
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
    u8 unk_04[0x24];
    s32 unk_28;
    u8 unk_2c[0xc];
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 width;
    u8 unk_48[0x28];
    s32 depth;
    u8 unk_74[0x44];
};

struct LoStatusWin {
    u8 unk_00[0x44];
    Model *unk_44;
    Model *unk_48;
    u8 unk_4c[0x8];
    u8 *unk_54;
    u8 unk_58[0x8];
    LoTextWin unk_60;
    LoTextWin unk_118;
    LoTextWin unk_1d0;
    LoTextWin unk_288;
    LoTextWin unk_340;
    LoTextWin unk_3f8;
};

void func_ov000_021512b4(LoStatusWin *self, s32 a, s32 *pos, s32 c) {
    s32 bx;
    s32 h;
    s32 x;
    s32 y;
    x = pos[0];
    y = pos[1];
    self->unk_44->unk_150 = -0x199a;
    Model_SetPos(self->unk_44, x, y);
    Model_PlayPart(self->unk_44, 0);
    {
        s32 px = pos[0] >> 12;
        s32 cx = (0x100 - self->unk_60.width) >> 1;
        s32 py = pos[1] >> 12;
        self->unk_60.depth = -0x191a;
        self->unk_60.unk_vf20(cx + px, py + 0x22);
    }
    self->unk_60.Render();
    bx = pos[0] >> 12;
    y = (pos[1] >> 12) + 0x34;
    self->unk_118.depth = -0x191a;
    self->unk_118.unk_vf20(bx + 0x19, y);
    self->unk_118.Render();
    data_02097ce0->unk_004 = self->unk_118.unk_28;
    h = self->unk_118.unk_38 + ((NNSG2dFont *)GfxMgr_GetFont(data_02097ce0))->pRes->pGlyph->cellHeight;
    y += h * 5 + 1;
    if (func_ov000_0214bf2c(LFLD(u16, self->unk_54, 6)) & 0x10) {
        self->unk_340.depth = -0x191a;
        self->unk_340.unk_vf20(bx + 0x19, y);
        self->unk_340.Render();
        self->unk_3f8.depth = -0x191a;
        self->unk_3f8.unk_vf20(bx + 0xe7 - self->unk_3f8.width, y);
        self->unk_3f8.Render();
        {
            s32 ox = bx + 0xdf - self->unk_3f8.width;
            self->unk_48->unk_150 = -0x191a;
            Model_SetPos(self->unk_48, (ox - 0x80) << 12, (y - 0x5a) << 12);
        }
        Model_PlayPart(self->unk_48, 0xb);
    }
    self->unk_1d0.depth = -0x191a;
    self->unk_1d0.unk_vf20(bx + 0x19, y + h);
    self->unk_1d0.Render();
    self->unk_288.depth = -0x191a;
    self->unk_288.unk_vf20(bx + 0xe7 - self->unk_288.width, y + h);
    self->unk_288.Render();
}

}
#endif
