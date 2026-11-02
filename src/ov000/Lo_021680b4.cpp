#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern char data_0214b105[];
extern void *data_0208cb7c;
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9aec[];
extern u8 data_ov000_021c9af2[];

void func_ov000_021680b4(Lo021cb6f0 *self) {
    void *res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    u8 *m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        void *nm = data_0208cb7c;
        func_02041218((struct PlttRes *)(m + 0x88));
        func_02041440(m, nm, 0);
    }
    self->unk_9c = m;
    func_020417e0(m, res);
    LFLD(u32, self->unk_9c, 0x6c) |= 2;
    LFLD(u32, self->unk_9c, 0x6c) |= 0x200000;
    LFLD(u32, self->unk_9c, 0x6c) |= 0x80000;
    func_02041d9c(self->unk_9c, 0, 3);
    self->unk_30 = 0xc000;
    self->unk_50 = 0x44;
    self->unk_54 = 4;
    self->unk_28 = 0;
    self->unk_0c |= 0x240;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9aec);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9af2);
}

}
