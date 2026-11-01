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

struct Obj02172bb4 {
    u8 unk_00[0x20];
    s32 unk_20;
    u8 unk_24[0xc];
    VObj *unk_30;
};

BOOL func_ov000_02172bb4(Obj02172bb4 *self) {
    if (self->unk_20 == 0) {
        return TRUE;
    }
    if (self->unk_30 == NULL) {
        return FALSE;
    }
    return self->unk_30->vfunc_08();
}

}
