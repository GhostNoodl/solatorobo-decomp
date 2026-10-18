#include "ov000/LoCommon.h"

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
void STD_CopyString(void *dst, void *src);
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);

class Model0215aa78 {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Model0215aa78(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

typedef struct {
    u32 b0 : 1;
    u32 b1 : 2;
    u32 b3 : 1;
    u32 rest : 28;
} PFlags0215aa78;

typedef struct {
    u32 lo : 2;
    u32 f2 : 5;
    u32 rest : 25;
} MFlags0215aa78;

class Panel0215aa78 {
public:
    PFlags0215aa78 flags;
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
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    void SetOfs(s32 x, s32 y) {
        unk_18 = x;
        unk_1c = y;
    }
    Panel0215aa78() {
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

void func_ov000_0215e8b0(Panel0215aa78 *p);

void func_ov000_0215aa78(VObj *self) {
    u8 *node;
    s32 maxw;

    node = LFLD(u8 *, self, 0x94);
    maxw = 0;
    while (node != NULL) {
        func_ov000_02153c48(node, LFLD(void *, self, 0x1c), 0, 0, 0);
        if (LFLD(s32, LFLD(u8 *, node, 0x1c), 0x44) > maxw) {
            maxw = LFLD(s32, LFLD(u8 *, node, 0x1c), 0x44);
        }
        node = LFLD(u8 *, node, 0x2c);
    }
    LFLD(s32, self, 0x20) = LFLD(s16, self, 0x9c);
    if (LFLD(s32, self, 0x24) == -1) {
        if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
            LFLD(s32, self, 0x24) = 0x100;
        } else {
            LFLD(s32, self, 0x24) = maxw + 0x40;
            if (LFLD(s32, self, 0x24) < 0x98) {
                LFLD(s32, self, 0x24) = 0x98;
            }
        }
    }
    LFLD(s32, self, 0x28) = self->vfunc_44();
    if (LFLD(u8 *, self, 0x10) == NULL) {
        if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
            LFLD(Model0215aa78 *, self, 0x10) = new Model0215aa78(data_0208cb84, data_0208cc8c);
        } else {
            LFLD(Model0215aa78 *, self, 0x10) = new Model0215aa78(data_0208cb74, data_0208cca0);
        }
        {
            void *a = func_02035d5c(LFLD(u8 *, self, 0x10) + 0x2c);
            func_020417e0(LFLD(u8 *, self, 0x10), func_02034d88(a, LFLD(u8 *, self, 0x10) + 0x4c));
        }
        LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 2;
        func_02041d9c(LFLD(u8 *, self, 0x10), 0, 7);
    }
    if (LFLD(Panel0215aa78 *, self, 0xac) == NULL) {
        LFLD(Panel0215aa78 *, self, 0xac) = new Panel0215aa78();
        if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
            LFLD(Panel0215aa78 *, self, 0xac)->flags.b3 = 1;
            LFLD(Panel0215aa78 *, self, 0xac)->SetOfs((maxw >> 1) + 0x10, 0);
        } else {
            LFLD(Panel0215aa78 *, self, 0xac)->flags.b1 = 3;
            LFLD(Panel0215aa78 *, self, 0xac)->flags.b0 = 1;
        }
        func_ov000_0215e8b0(LFLD(Panel0215aa78 *, self, 0xac));
        LFLD(Panel0215aa78 *, self, 0xac)->unk_10 = (LFLD(s32, self, 0x24) - 0x20) << 12;
        LFLD(u32, LFLD(Panel0215aa78 *, self, 0xac)->model, 0x6c) |= 0x200000;
        LFLD(u32, LFLD(Panel0215aa78 *, self, 0xac)->model, 0x6c) |= 0x100000;
        LFLD(u32, LFLD(Panel0215aa78 *, self, 0xac)->model, 0x6c) |= 0x80000;
        LFLD(MFlags0215aa78, LFLD(Panel0215aa78 *, self, 0xac)->model, 0x6c).f2 = 0x1e;
    }
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s16, self, 0x64) = 0x80 - (LFLD(s32, self, 0x24) >> 1);
    LFLD(s16, self, 0x66) = 0x60 - (LFLD(s32, self, 0x28) >> 1);
    LBIT(self, 0xc).b0 = 1;
}

}
