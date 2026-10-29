#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0214d304;

#define MF(m) LFLD(LoMdlFlags0214d304, m, 0x6c)
#define M10 LFLD(u8 *, self, 0x10)
#define M88 LFLD(u8 *, self, 0x88)

extern "C" {

extern u8 *data_02097d48;
extern u8 data_02fe1534[];
int func_02043d48(void *p);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02041774(void *a, int b);
void func_02041c20(void *a, int b, int c);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPartF(void *model, int idx, int f) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, f);
}

static inline void LoModelPlayPart(void *model, int idx) {
    LoModelPlayPartF(model, idx, 0);
}

static inline void LoSetPos(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

void func_ov000_0214d304(VObj *self, s32 a, s32 *pos, s32 d) {
    s32 i;
    s32 y;
    s32 s;
    u8 *g;
    s32 x;
    s32 py;
    s16 z;
    g = data_02097d48;
    z = LFLD(s16, self, 0x68) - 0x110;
    x = (pos[0] >> 12) - 0x80;
    y = (pos[1] >> 12) - 0x51;
    MF(M10).b19 = 1;
    MF(M10).f2 = 0x1e;
    MF(M10).b20 = 1;
    MF(M10).b21 = 1;
    MF(M10).f7 = func_02043d48(g + 0x8b0);
    LoSetPos(M10, x << 12, y << 12);
    LFLD(s32, M10, 0x150) = z;
    LoModelPlayPart(M10, 0xe);
    func_02041774(M10, 0xffff);
    LFLD(s32, self, 0x1b8) = LFLD(s16, self, 0x68);
    LFLD(VObj, self, 0x148).vfunc_20(x + 0xb2 - (LFLD(s32, self, 0x18c) >> 1), y + 0x62);
    LFLD(VObj, self, 0x148).vfunc_90();
    MF(M10).f7 = g[0x8b1];
    LoSetPos(M10, (x + 0x74) << 12, (y + 8) << 12);
    LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68);
    LoModelPlayPart(M10, 0xb);
    MF(M88).b19 = 1;
    MF(M88).f2 = 0x1e;
    LoSetPos(M88, (x + 0x7e) << 12, (y + 3) << 12);
    LFLD(s32, M88, 0x150) = LFLD(s16, self, 0x68);
    func_02041c20(M88, 6, LFLD(u16, data_02fe1534, 0x58));
    s = LFLD(s32, self, 0x218);
    if (s != 0) {
        {
            u8 *m = M88;
            LFLD(s32, m, 0x144) = 0x800;
            LFLD(s32, m, 0x148) = 0x400;
            LFLD(s32, m, 0x14c) = 0x800;
        }
        MTX_Identity22_((MtxFx22 *)(M88 + 0x114));
        MTX_ScaleApply22((MtxFx22 *)(M88 + 0x114), (MtxFx22 *)(M88 + 0x114), s + 0x1000, s + 0x1000);
        LoModelPlayPartF(M88, 6, 1);
    } else {
        LoModelPlayPart(M88, 6);
    }
    LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68);
    py = (y + 0x14) << 12;
    y = x + 0x10;
    for (i = 0; i < 10; i++) {
        y += 0xb;
        LoSetPos(M10, y << 12, py);
        if (LFLD(u32, self, 0xc) & 0x10000) {
            if (i > LFLD(u16, self, 0x208)) {
            } else if (i == LFLD(u16, self, 0x208)) {
                u8 al = LO_FX_MUL(LFLD(s32, self, 0x210), 0x1f000) >> 12;
                if (al != 0) {
                    MF(M10).b19 = 1;
                    MF(M10).f2 = al;
                    MF(M10).f7 = func_02043d48(g + 0x8b0);
                    LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68);
                    LoModelPlayPart(M10, 0xd);
                    func_02041774(M10, 0xffff);
                }
            } else {
                LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68);
                LoModelPlayPart(M10, 0xd);
            }
        } else if (i + 1 <= LFLD(u16, self, 0x208)) {
            LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68);
            LoModelPlayPart(M10, 0xd);
        }
        LFLD(s32, M10, 0x150) = LFLD(s16, self, 0x68) - 0x20;
        LoModelPlayPart(M10, 0xc);
    }
}

}
