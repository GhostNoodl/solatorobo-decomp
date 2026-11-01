#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"

extern "C" {

extern u8 data_ov000_021cc774[];
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_ov000_021bd228(void *p);
void func_0203f2b8(void *p);
void *func_ov000_0218c928(void *p);

struct Obj0219c24c {
    void *unk_00;
    u8 unk_04[0x30];
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0xc];
    s32 unk_48;
    u8 unk_4c[0x94c];
    void *unk_998;
    void *unk_99c;
    u8 unk_9a0[0x10];
    void *unk_9b0;
    void *unk_9b4;
};

u8 *func_ov000_0219c24c(Obj0219c24c *self) {
    self->unk_00 = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, func_ov000_0218fee4);
    HEAP_DELETE_FN(self->unk_99c, func_ov000_0218ea20);
    HEAP_DELETE_FN(self->unk_9b0, func_ov000_021bd228);
    HEAP_DELETE_FN(self->unk_9b4, func_ov000_021bd228);
    self->unk_38 = 0;
    self->unk_34 = 0;
    self->unk_48 = 0;
    func_ov000_0218ea20((u8 *)self + 0x860);
    func_ov000_0218fee4((u8 *)self + 0x778);
    func_0203f2b8((u8 *)self + 0x6c0);
    func_ov000_0218ea20((u8 *)self + 0x588);
    func_ov000_0218ea20((u8 *)self + 0x450);
    func_ov000_0218fee4((u8 *)self + 0x368);
    func_0203f2b8((u8 *)self + 0x2cc);
    func_ov000_0218ea20((u8 *)self + 0x194);
    func_ov000_0218fee4((u8 *)self + 0xac);
    func_ov000_0218c928(self);
    return (u8 *)self;
}

u8 *func_ov000_0219c3c8(Obj0219c24c *self) {
    self->unk_00 = data_ov000_021cc774;
    HEAP_DELETE_FN(self->unk_998, func_ov000_0218fee4);
    HEAP_DELETE_FN(self->unk_99c, func_ov000_0218ea20);
    HEAP_DELETE_FN(self->unk_9b0, func_ov000_021bd228);
    HEAP_DELETE_FN(self->unk_9b4, func_ov000_021bd228);
    self->unk_38 = 0;
    self->unk_34 = 0;
    self->unk_48 = 0;
    func_ov000_0218ea20((u8 *)self + 0x860);
    func_ov000_0218fee4((u8 *)self + 0x778);
    func_0203f2b8((u8 *)self + 0x6c0);
    func_ov000_0218ea20((u8 *)self + 0x588);
    func_ov000_0218ea20((u8 *)self + 0x450);
    func_ov000_0218fee4((u8 *)self + 0x368);
    func_0203f2b8((u8 *)self + 0x2cc);
    func_ov000_0218ea20((u8 *)self + 0x194);
    func_ov000_0218fee4((u8 *)self + 0xac);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return (u8 *)self;
}

}
