#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s32 x;
    s32 y;
} Lim0216b880;

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
    u32 b4 : 28;
} Bits0216b880;

extern "C" {
extern u8 *data_ov000_021ccd30;
extern u8 data_ov000_021c9a9c[];

static inline void Model_PlayPartEx(Model *model, s32 idx, s32 flag) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, anim, part, flag);
}

static inline BOOL IsShown(u8 *p) {
    return LFLD(Bits0216b880, p, 0xc).b3 ? TRUE : FALSE;
}

static inline u8 *GetA0216b880(u8 *mgr) {
    return LFLD(u8 *, mgr, 0x11c) != NULL ? LFLD(u8 *, LFLD(u8 *, mgr, 0x11c), 0x58) : NULL;
}

static inline u8 *GetB0216b880(u8 *mgr) {
    return LFLD(u8 *, mgr, 0x11c) != NULL ? LFLD(u8 *, LFLD(u8 *, mgr, 0x11c), 0x64) : NULL;
}

void func_ov000_0216b880(u8 *self) {
    s32 off;
    u8 *m;
    u8 *a;
    u8 *b;
    s32 y;
    s32 v;
    if (LFLD(s32, self, 4) != 7 && LFLD(s32, self, 4) != 8) {
        return;
    }
    v = LFLD(s32, self, 0x18);
    y = LO_FX_MUL(v, 0x40000) + 0x55000;
    y -= 0xb000;
    a = GetA0216b880(data_ov000_021ccd30);
    b = GetB0216b880(data_ov000_021ccd30);
    Lim0216b880 lim = LFLD(Lim0216b880, data_ov000_021c9a9c, 0x20);
    off = 0;
    if (b != NULL && IsShown(b) && (m = LFLD(u8 *, b, 0x9c)) != NULL) {
        lim.x = LFLD(s32, m, 0xfc);
        lim.y = LFLD(s32, m, 0x100) - 0x15000;
        off = -0x12000;
    } else if (a != NULL && IsShown(a) && (m = LFLD(u8 *, a, 0xa4)) != NULL) {
        lim.x = LFLD(s32, m, 0xfc);
        lim.y = LFLD(s32, m, 0x100) - 0x15000;
        off = -0xa000;
    }
    if (v == 0) {
        if (y > lim.y) {
            y = lim.y;
        }
    } else if (y > lim.y) {
        y += off;
    }
    Model_SetPos(LFLD(Model *, self, 8), -0x7d000, y & ~0xfff);
    LFLD(Model *, self, 8)->unk_150 = -0x2000;
    if (LFLD(Bits0216b880, self, 0).b3) {
        Model_PlayPartEx(LFLD(Model *, self, 8), 0x22, 0);
    } else {
        Model_PlayPartEx(LFLD(Model *, self, 8), 0x23, 0);
    }
}

}
