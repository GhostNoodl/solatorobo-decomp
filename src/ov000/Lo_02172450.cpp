#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {

extern u8 data_0214b105[];
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021cb940[];
extern u8 data_ov000_021cb6d0[];
s32 func_02035b90(void *a, s32 b);
void func_ov000_0216f23c(void *p, s32 a);
BOOL func_ov000_02180900(void *p);
void func_ov000_0216fb14(void *p);
void func_0203df0c(void *p);

typedef struct { u32 lo : 4; } LoNib;

void func_ov000_02172450(MessageQueue *self, u32 mode) {
    if (LBIT(self, 0x114).b1 && mode >= 1) {
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

void func_ov000_02172518(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 0x15, (u16)a | (c << 16), b);
}

void func_ov000_02172544(void *self) {
    LFLD(VObj *, self, 0xc)->vfunc_0c(LFLD(s32, self, 0x20), LFLD(s32, self, 0x24), LFLD(s32, self, 0x28), LFLD(s32, self, 0x2c));
    LBIT(self, 4).b2 = 1;
}

}
