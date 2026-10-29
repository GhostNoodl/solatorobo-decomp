#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
    u32 rest : 28;
} Flags0216b1b4;

extern "C" {
extern u8 *data_ov000_021ccd30;
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02041c34(void *a, int b, void *c, void *d);
void *func_ov000_0216ac14(void);

static inline void *Model_GetPart0216b1b4(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void Model_PlayPart0216b1b4(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart0216b1b4(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void *GetObj0216b1b4(void) {
    void *o = LFLD(void *, data_ov000_021ccd30, 0x11c);
    return o != NULL ? LFLD(void *, o, 0x58) : NULL;
}

static inline BOOL SubFlag0216b1b4(void *s) {
    return LFLD(Flags0216b1b4, s, 0xc).b3 ? TRUE : FALSE;
}

static inline BOOL IsFlag0216b1b4(u8 *g) {
    void *s;
    if (LFLD(void *, g, 0x11c) == NULL) {
        return FALSE;
    }
    s = LFLD(void *, LFLD(void *, g, 0x11c), 0x64);
    if (s != NULL) {
        return SubFlag0216b1b4(s) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

static inline void SetPos0216b1b4(void *o, s32 x, s32 y) {
    LFLD(s32, o, 0xfc) = x;
    LFLD(s32, o, 0x100) = y;
}

void func_ov000_0216b1b4(u8 *self) {
    s32 base;
    if (GetObj0216b1b4() == NULL) {
        return;
    }
    if (LFLD(s32, self, 0x4) != 7 && LFLD(s32, self, 0x4) != 8) {
        return;
    }
    base = IsFlag0216b1b4(data_ov000_021ccd30) ? 0xae000 : 0xb6000;
    SetPos0216b1b4(LFLD(void *, self, 0xc), -0x53000, (base + (s32)(((s64)LFLD(s32, self, 0x1c) * 0x40000 + 0x800) >> 12) - 0x61000) & ~0xfff);
    func_02041c34(LFLD(void *, self, 0xc), 6, (void *)func_ov000_0216ac14, self);
    LFLD(s32, LFLD(void *, self, 0xc), 0x150) = -0x1f80;
    Model_PlayPart0216b1b4(LFLD(void *, self, 0xc), 6);
    Model_PlayPart0216b1b4(LFLD(void *, self, 0xc), 7);
    Model_PlayPart0216b1b4(LFLD(void *, self, 0xc), LFLD(u16, self, 0x14));
    LFLD(s32, LFLD(void *, self, 0xc), 0x150) = -0x2000;
    Model_PlayPart0216b1b4(LFLD(void *, self, 0xc), 0xb);
}
}
