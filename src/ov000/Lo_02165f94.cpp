#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_020927f8[];
extern u8 data_02092844[];
extern u8 data_02092800[];
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097dc8;
void func_02011ff0(void *a, void *b, void *c, void *d);
void MIi_CpuCopyFast(void *a, void *b, s32 c);
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

typedef struct LoAnimC {
    u8 rgb[4];
    u8 pad[0x84];
    u8 *frames[0x20];
    u8 cnt;
    u8 pad2;
    u16 state;
    u16 idx;
    u16 timer;
    u16 period;
} LoAnimC;

static inline BOOL LoAnimValid(LoAnimC *p) {
    if (p == NULL || p->state == 0) {
        return FALSE;
    }
    return TRUE;
}

u8 *func_ov000_02165f94(void *self) {
    LoAnimC *p = LFLD(LoAnimC *, LFLD(u8 *, self, 0x30), 0xcdc);
    u8 *g = data_ov000_021ccd54;
    if (!LoAnimValid(p)) {
        return g + 0xca;
    }
    if (LFLD(u16, data_02097dc8, 0x12) & 2) {
        p->timer = p->period;
        p->idx = 0;
    }
    p->timer++;
    if (p->timer >= p->period) {
        p->timer = 0;
        u16 i = p->idx;
        if ((u16)(i - 2) < p->cnt) {
            p->idx -= 2;
        } else if (i != 0) {
            p->idx = 0;
        } else {
            p->state = 0xffff;
        }
    }
    p->rgb[0] = g[0xca];
    p->rgb[1] = g[0xcb];
    p->rgb[2] = p->frames[p->idx][8];
    return p->rgb;
}

}
