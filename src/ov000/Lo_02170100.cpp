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

s32 func_ov000_02170100(void *self) {
    if (LFLD(void *, self, 0x28) == NULL) {
        Message *m = MessageQueue_FindById(LFLD(MessageQueue *, self, 0xc), 6);
        return m != NULL ? (s32)(m->unk_0c >> 16) : -1;
    }
    return LFLD(LoNib, LFLD(void *, self, 0x28), 0xb8).lo;
}

}
