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

void *func_ov000_021729d0(ListBuffer *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb940);
    func_ov000_0216fb14(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cb6d0);
    if ((self->flags & 0x20) && self->unk_0c != 0) {
        func_0203df0c((void *)self->unk_0c);
    }
    self->flags = 0;
    self->priority = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->prev = NULL;
    self->next = NULL;
    func_0203de1c(self);
    return self;
}

}
