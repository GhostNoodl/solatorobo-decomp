#include "ov000/LoCommon.h"

extern "C" {

extern u8 NNS_G3dGlb[];
extern u8 data_02092844[];
extern u8 data_02092800[];
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097dc8;
void MTX_LookAt(void *a, void *b, void *c, void *d);
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

typedef struct Item0216607c Item0216607c;

typedef struct {
    u8 pad_00[0xb];
    u8 count;
    u8 pad_0c[0xc];
    Item0216607c *items;
} Node0216607c;

struct Item0216607c {
    Node0216607c *node;
    u8 pad_04[8];
    s32 a;
    s32 b;
    u8 key;
    u8 pad_15[3];
};

typedef struct {
    u32 unk_00;
    Item0216607c **list;
} Slot0216607c;

typedef struct {
    u8 pad_00[8];
    u8 count;
    u8 pad_09[0xc7f];
    Slot0216607c *slots;
    u8 pad_c8c[0x28];
    Item0216607c *cur;
} Ctx0216607c;

Node0216607c *func_ov000_0216607c(void *self, Node0216607c *node, u8 *outIdx, BOOL deep) {
    Ctx0216607c *ctx = LFLD(Ctx0216607c *, self, 0x30);
    Item0216607c **lst;
    u8 i;
    u8 k;
    for (i = 0; i < node->count; i++) {
        if (ctx->cur->key == node->items[i].key) {
            *outIdx = i;
            return node;
        }
    }
    if (deep) {
        Slot0216607c *slot = &ctx->slots[ctx->cur->key];
        u8 n = ctx->count;
        // A hand-rotated loop: the list load sits after the entry check, as in the target.
        i = 0;
        if (i < n) {
            lst = slot->list;
            do {
                Item0216607c *it = lst[i];
                if (it != NULL && it->a == node->items->a && it->b == node->items->b) {
                    Node0216607c *nd = it->node;
                    for (k = 0; k < nd->count; k++) {
                        if (&nd->items[k] == it) {
                            *outIdx = k;
                            return it->node;
                        }
                    }
                }
            } while (++i < n);
        }
    }
    return NULL;
}

}
