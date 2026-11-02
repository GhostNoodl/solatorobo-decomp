#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void *STD_CopyString(void *dst, void *src);
extern void *data_0208cc88;
extern void *data_0208cc94;
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *func_ov000_021540b0(void *self, u16 *msg, void *g, u16 *count);
void *func_ov000_02154128(u8 *self, void *req, void *buf, u16 *count);

class Model0215429c {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Model0215429c(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

typedef struct {
    u32 b0 : 1;
    u32 b1 : 2;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
} PFlags0215429c;

class Panel0215429c {
public:
    PFlags0215429c flags;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 *model;
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Panel0215429c() {
        *(u32 *)&flags = 0;
        unk_04 = 0;
        unk_08 = 0;
        unk_0c = 0;
        unk_1c = 0;
        unk_18 = 0;
        unk_10 = 0x80000;
        unk_14 = 0xf000;
        unk_20 = 0;
        unk_24 = 0;
        model = NULL;
    }
};

void func_ov000_0215e8b0(Panel0215429c *p);

static inline BOOL LoadModel0215429c(LoBase021caec8_021efca4 *self) {
    if (self->unk_10 != NULL) {
        return TRUE;
    }
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        self->unk_10 = (u8 *)(new Model0215429c(data_0208cb84, data_0208cc8c));
    } else {
        self->unk_10 = (u8 *)(new Model0215429c(data_0208cb74, data_0208cca0));
    }
    {
        void *a = func_02035d5c(self->unk_10 + 0x2c);
        func_020417e0(self->unk_10, func_02034d88(a, self->unk_10 + 0x4c));
    }
    LFLD(u32, self->unk_10, 0x6c) |= 2;
    func_02041d9c(self->unk_10, 0, 7);
    return TRUE;
}

void func_ov000_0215429c(LoBase021caec8_021efca4 *self) {
    if (!(self->unk_0c & 0x20000)) {
        self->unk_20 = self->unk_9c;
    }
    self->unk_28 = self->vfunc_44();
    if (LoadModel0215429c(self)) {
        if (self->unk_0c & 0x40000) {
            func_02041d9c(self->unk_10, 0, 2);
            func_02041d9c(self->unk_10, 0, 10);
            func_02041d9c(self->unk_10, 0, 6);
        }
        func_02041c5c(self->unk_10, (void *)func_ov000_021540b0);
        func_02041c20(self->unk_10, 2, self);
        func_02041c20(self->unk_10, 6, self);
    }
    if (self->unk_0c & 0x400000) {
        Model0215429c *m = (Model0215429c *)Heap_Alloc(0x160);
        if (m) {
            void *arc;
            void *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            func_02041218(m->data + 0x88);
            func_02041440(m->data, name, 0);
            STD_CopyString(m->data + 0x2c, arc);
        }
        self->unk_b4 = (u8 *)(m);
        {
            void *a = func_02035d5c(m->data + 0x2c);
            func_020417e0(self->unk_b4, func_02034d88(a, self->unk_b4 + 0x4c));
        }
        LFLD(u32, self->unk_b4, 0x6c) |= 2;
        func_02041d9c(self->unk_b4, 0, 6);
        func_02041c20(self->unk_b4, 6, self);
        if (self->unk_0c & 0x800000) {
            func_02041d9c(self->unk_b4, 0, 7);
        }
        func_02041c5c(self->unk_b4, (void *)func_ov000_02154128);
    }
    if ((Panel0215429c *)self->unk_ac == NULL) {
        self->unk_ac = new Panel0215429c();
        if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
            ((Panel0215429c *)self->unk_ac)->flags.b4 = 1;
        }
        func_ov000_0215e8b0((Panel0215429c *)self->unk_ac);
        if (self->unk_0c & 0x1000000) {
            ((Panel0215429c *)self->unk_ac)->unk_10 = (self->unk_24 + 0x10) << 12;
            ((Panel0215429c *)self->unk_ac)->flags.b0 = 1;
        } else {
            ((Panel0215429c *)self->unk_ac)->unk_10 = (self->unk_24 + 0x10) << 12;
        }
    }
    self->unk_2c = 1;
    self->unk_5c = 0;
    self->unk_60 = 0;
    self->unk_58 = -(self->unk_24 + 0x10);
    LBIT(self, 0xc).b0 = 1;
    self->vfunc_48(0, 0);
}

}
