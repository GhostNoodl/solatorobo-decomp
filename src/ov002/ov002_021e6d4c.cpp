#include "types.h"

extern "C" {

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))
extern void *data_02097ce0;
extern void *data_ov002_021f0f98[];
u8 func_0206e8f0(void);
void *func_0203a4c0(void *a);
void func_0203a4e4(void *mgr, void *arg);
int NNSi_G2dFontGetTextWidth(const void *pFont, int hSpace, const void *txt);

static inline BOOL Ov002_IsValidIdx(s32 idx) {
    BOOL r = FALSE;
    if (idx < 0) {
        return r;
    }
    if (idx < FIELD(data_ov002_021f0f98[1], 0xd0, s32)) {
        r = TRUE;
    }
    return r;
}

static inline void Pos_Set(s16 *p, s16 x, s16 y) {
    p[0] = x;
    p[1] = y;
}

void func_ov002_021e6d4c(void *self) {
    s16 x;
    s16 y;
    s16 pal;
    if (Ov002_IsValidIdx(FIELD(self, 0xb8, s32))) {
        return;
    }
    if (!func_0206e8f0()) {
        y = 0x9c;
        pal = 3;
        x = 10;
    } else {
        y = 0x99;
        pal = 1;
        x = 10;
    }
    FIELD(data_02097ce0, 0x4, s32) = FIELD(self, 0x150, s32);
    FIELD(data_02097ce0, 0x8, s32) = 0;
    Pos_Set((s16 *)((u8 *)data_02097ce0 + 0xc), x, y);
    FIELD(data_02097ce0, 0x10, s16) = pal;
    func_0203a4e4(data_02097ce0, (u8 *)self + 0xc4);
    if (FIELD(self, 0x148, s32) == 0xff) {
        return;
    }
    {
        void *txt = FIELD(self, 0x14c, void *);
        void *font = func_0203a4c0(data_02097ce0);
        s32 w = NNSi_G2dFontGetTextWidth(font, 0, txt);
        FIELD(data_02097ce0, 0x4, s32) = FIELD(self, 0x154, s32);
        FIELD(data_02097ce0, 0x8, s32) = 0;
        Pos_Set((s16 *)((u8 *)data_02097ce0 + 0xc), (0x60 - w) >> 1, 0x8d);
        func_0203a4e4(data_02097ce0, FIELD(self, 0x14c, void *));
    }
}

}
