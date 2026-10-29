#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
BOOL func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void *p);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_0215123c(void *self) {
    s32 s;
    if (LFLD(s32, self, 0x24) == 0 || (s = LFLD(s32, self, 8)) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (LFLD(VObj *, self, 0x4c) != NULL) {
        LFLD(VObj *, self, 0x4c)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x50) != NULL) {
        LFLD(VObj *, self, 0x50)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x58) != NULL) {
        LFLD(VObj *, self, 0x58)->vfunc_20();
    }
}

}

#ifdef NONMATCHING
// func_ov000_021512b4 (0x2d8 bytes, the status-window text layout): 23 / 0 (raw / register-masked), round
// smW's b2 draft. The real signature is (obj, a, pos, c) (round smV; a and c are unused). Left: the -0x191a
// text-depth constant (ROM r6, ours r5) swaps with bx and the first (0x100 - w) >> 1 (ROM r5, ours r6).
// ramerge (round qpH, multi-target 34:6 47:5 71:5 76:6 151:6) finds exactly two fixes: bx (node 47) numbered
// after the first constant (node 76), or that constant numbered between h and bx in the named-local band.
// Neither is reachable: bx must outlive the virtual calls, so it is an object; reusing x for it, or a dead x
// with (x >> 12) at every use, turns it into an @ object, which is numbered even lower (30 / 0 both). A
// constant local (s32 z, also assigned twice) is propagated (23 / 0); an enum local is 115 / 62.
extern "C" {

extern u8 *data_02097ce0;
u8 **func_0203a4c0(void *p);
u32 func_ov000_0214bf2c(u16 a);

}

#include "ov000/ModelPart.h"

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
};

#define TEXT(off) ((LoTextWin *)((u8 *)self + (off)))

void func_ov000_021512b4(u8 *self, s32 a, s32 *pos, s32 c) {
    s32 bx;
    s32 h;
    s32 x;
    s32 y;
    x = pos[0];
    y = pos[1];
    LFLD(Model *, self, 0x44)->unk_150 = -0x199a;
    Model_SetPos(LFLD(Model *, self, 0x44), x, y);
    Model_PlayPart(LFLD(Model *, self, 0x44), 0);
    {
        s32 px = pos[0] >> 12;
        s32 cx = (0x100 - LFLD(s32, self, 0xa4)) >> 1;
        s32 py = pos[1] >> 12;
        LFLD(s32, self, 0xd0) = -0x191a;
        TEXT(0x60)->unk_vf20(cx + px, py + 0x22);
    }
    TEXT(0x60)->Render();
    bx = pos[0] >> 12;
    y = (pos[1] >> 12) + 0x34;
    LFLD(s32, self, 0x188) = -0x191a;
    TEXT(0x118)->unk_vf20(bx + 0x19, y);
    TEXT(0x118)->Render();
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, self, 0x140);
    h = LFLD(s32, self, 0x150) + LFLD(u8, LFLD(u8 *, *func_0203a4c0(data_02097ce0), 8), 1);
    y += h * 5 + 1;
    if (func_ov000_0214bf2c(LFLD(u16, LFLD(u8 *, self, 0x54), 6)) & 0x10) {
        LFLD(s32, self, 0x3b0) = -0x191a;
        TEXT(0x340)->unk_vf20(bx + 0x19, y);
        TEXT(0x340)->Render();
        LFLD(s32, self, 0x468) = -0x191a;
        TEXT(0x3f8)->unk_vf20(bx + 0xe7 - LFLD(s32, self, 0x43c), y);
        TEXT(0x3f8)->Render();
        {
            s32 ox = bx + 0xdf - LFLD(s32, self, 0x43c);
            LFLD(Model *, self, 0x48)->unk_150 = -0x191a;
            Model_SetPos(LFLD(Model *, self, 0x48), (ox - 0x80) << 12, (y - 0x5a) << 12);
        }
        Model_PlayPart(LFLD(Model *, self, 0x48), 0xb);
    }
    LFLD(s32, self, 0x240) = -0x191a;
    TEXT(0x1d0)->unk_vf20(bx + 0x19, y + h);
    TEXT(0x1d0)->Render();
    LFLD(s32, self, 0x2f8) = -0x191a;
    TEXT(0x288)->unk_vf20(bx + 0xe7 - LFLD(s32, self, 0x2cc), y + h);
    TEXT(0x288)->Render();
}

}
#endif
