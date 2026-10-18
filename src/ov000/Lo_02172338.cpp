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
void func_ov000_02180900(void *p);
void func_ov000_0216fb14(void *p);
void func_0203df0c(void *p);

typedef struct { u32 lo : 4; } LoNib;

void func_ov000_02172338(VObj *self, s32 flag, s32 a, s32 b, s32 c) {
    u32 x = (u8)a | (c << 8);
    if (flag) {
        self->vfunc_0c(0, 0xd, x, b);
    } else {
        self->vfunc_0c(0, 0xe, 0, 0);
    }
}

}
