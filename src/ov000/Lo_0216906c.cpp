#include "ov000/LoCommon.h"

typedef struct {
    s32 v[4];
} LoFadeP;

typedef struct {
    u16 lo : 12;
    u16 hi : 4;
} LoU16Hi;
typedef struct { u32 a : 28; u32 k : 4; } LoW28;
typedef struct { u32 a : 12; u32 k : 16; } LoW12;

extern "C" {

extern u8 data_ov000_021ccd24[];
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021c9b28[];
void func_020708fc(s32 a, LoFadeP *out);
void func_02070b98(s32 a, LoFadeP *out, s32 b, s32 c);
BOOL func_02035bd4(LoFadeP *a, LoFadeP *b, s32 c);
BOOL func_0205a9c8(void *p);
s32 func_ov000_02180838(void *a);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
void func_02041c5c(void *obj, void *value);
void func_02041c18(void *obj, s32 value);
u8 *func_0206ede8(u16 id);
void func_ov000_021566c0(void *self, void *msg, s32 c, s32 d, u8 e, u8 f);
void *func_ov000_02161bc4(void);

static inline BOOL LoFadeDone(void) {
    LoFadeP a;
    LoFadeP b;
    BOOL ret = TRUE;
    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    if (!func_02035bd4(&a, &b, 2)) {
        ret = FALSE;
    }
    return ret;
}

static inline BOOL LoResReady(void) {
    BOOL ret = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        ret = FALSE;
    }
    return ret;
}

static inline u32 LoIdKind(u32 id) { return (id << 4) >> 16; }
static inline u32 LoIdKind2(u16 id) { u32 r = (u32)(id << 4) >> 16; return r; }
void func_ov000_0216906c(void *self) {
    s32 s = LFLD(s32, self, 4);
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 2;
        }
    }
    if (LFLD(s32, self, 4) == 0xa) {
        if (!((LFLD(u32, self, 0xc) & 0x10000) ? TRUE : FALSE)) {
            LBIT(self, 0xc).b1 = 1;
        }
        LBIT(self, 0xc).b16 = 0;
    }
    if (LFLD(s32, self, 0xa8) >= 3) {
        return;
    }
    func_ov000_0215fdfc(self, 1, data_ov000_021c9b28 + LFLD(s32, self, 0xa8) * 6);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9b28 + (LFLD(s32, self, 0xa8) + 1) * 6);
}

}
