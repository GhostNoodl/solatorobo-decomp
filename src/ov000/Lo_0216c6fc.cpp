#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
BOOL func_02054f10(void *a, s32 b);
extern void *data_0208cc94;
extern void *data_0208cc88;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9ab0[];
extern s32 data_ov000_021c9bb4[];

typedef struct {
    s32 a;
    u8 **list;
} LoPair;

typedef struct {
    s32 a;
    s32 b;
} LoIdx2;

static inline BOOL LoGBusy(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

void func_ov000_0216c6fc(u8 *self) {
    LoIdx2 *tbl = (LoIdx2 *)data_ov000_021c9bb4;
    u8 *n = LFLD(u8 *, self, 0x24c);
    if (n == NULL) {
        return;
    }
    do {
        s32 k = LFLD(s32, n, 4);
        s32 x = LFLD(s32, n, 0x14);
        s32 y;
        VObj *o1;
        VObj *o2;
        o1 = LFLD(VObj *, self + tbl[k].a * 0xc, 0x368);
        y = LFLD(s32, n, 0x18);
        o2 = LFLD(VObj *, self + tbl[k].b * 0xc, 0x368);
        if (o1) {
            o1->vfunc_20(x, y);
            o1->vfunc_90();
            x = x + LFLD(s32, o1, 0x44) + 8;
        }
        if (LFLD(VObj *, n, 8)) {
            LFLD(VObj *, n, 8)->vfunc_20(x, y);
            LFLD(VObj *, n, 8)->vfunc_90();
            x += LFLD(s32, LFLD(VObj *, n, 8), 0x44);
        }
        if (o2) {
            o2->vfunc_20(x + 4, y);
            o2->vfunc_90();
        }
        n = LFLD(u8 *, n, 0x28);
    } while (n);
}

}
