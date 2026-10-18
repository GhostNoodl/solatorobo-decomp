#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_020927f8[];
extern u8 data_02092844[];
extern u8 data_02092800[];
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097dc8;
void func_02011ff0(void *a, void *b, void *c, void *d);
void func_02016d68(void *a, void *b, s32 c);
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

void func_ov000_0215c0c4(VObj *self, void *a, s32 *pos, s32 d) {
    if (a == NULL) {
        return;
    }
    self->vfunc_64(a, pos, d);
    if (LFLD(u32, self, 0xc) & 0x80000) {
        if (LFLD(VObj *, self, 0x84)) {
            s32 py;
            s32 px;
            px = pos[0];
            py = pos[1];
            s32 x = self->vfunc_30();
            s32 y = self->vfunc_34();
            LFLD(VObj *, self, 0x84)->vfunc_20(x + (px >> 12), y + (py >> 12));
            LFLD(VObj *, self, 0x84)->vfunc_90();
        }
    } else if (LFLD(s32, self, 4) == 2 && LFLD(VObj *, self, 0x84)) {
        LFLD(VObj *, self, 0x84)->vfunc_90();
    }
    if (LFLD(void *, self, 0x14)) {
        self->vfunc_60(a, pos, d);
    }
    LFLD(u32, self, 0xc) |= 0x200;
}

}
