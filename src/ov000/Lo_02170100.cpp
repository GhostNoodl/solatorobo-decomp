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
void func_ov000_0216fb14(void *p);

typedef struct { u32 lo : 4; } LoNib;

struct Obj02170100 {
    u8 unk_00[0xc];
    MessageQueue *unk_0c;
    u8 unk_10[0x18];
    void *unk_28;
};

s32 func_ov000_02170100(Obj02170100 *self) {
    if (self->unk_28 == NULL) {
        Message *m = MessageQueue_FindById(self->unk_0c, 6);
        return m != NULL ? (s32)(m->unk_0c >> 16) : -1;
    }
    return LFLD(LoNib, self->unk_28, 0xb8).lo;
}

}
