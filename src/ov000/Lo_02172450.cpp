#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_0214b105[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb6d0[];
void func_ov000_0216f23c(void *p, s32 a);
BOOL func_ov000_02180900(void *p);
void ListBuffer021cb940_Release(void *p);

typedef struct { u32 lo : 4; } LoNib;

void MessageQueue021cb980_Push14(MessageQueue021cb980 *self, u32 mode) {
    if (self->flag1 && mode >= 1) {
        return;
    }
    if (mode == 1) {
        Message *m = MessageQueue_Find(self, 0x14, 2, 0);
        if (m != NULL) {
            m->id = 0;
            return;
        }
    }
    self->vfunc_0c(0, 0x14, mode, 0);
}

void MessageQueue021cb980_Push15(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 0x15, (u16)a | (c << 16), b);
}

struct Obj02172544 {
    u8 unk_00[0xc];
    VObj *unk_0c;
    u8 unk_10[0x10];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
};

void func_ov000_02172544(Obj02172544 *self) {
    self->unk_0c->vfunc_0c(self->unk_20, self->unk_24, self->unk_28, self->unk_2c);
    LBIT(self, 4).b2 = 1;
}

}
