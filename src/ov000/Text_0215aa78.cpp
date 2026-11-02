#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 2;
    u32 b3 : 1;
    u32 rest : 28;
} PFlags0215aa78;


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
    Model *model;
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
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

struct Obj0215aa78 : public VObj {
    u8 unk_04[0xc];
    Model *unk_10;
    u8 unk_14[0x8];
    void *unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x34];
    s16 unk_64;
    s16 unk_66;
    u8 unk_68[0x2c];
    u8 *unk_94;
    u8 unk_98[0x4];
    s16 unk_9c;
    u8 unk_9e[0xe];
    Panel0215aa78 *unk_ac;
};

void func_ov000_0215aa78(Obj0215aa78 *self) {
    u8 *node;
    s32 maxw;

    node = self->unk_94;
    maxw = 0;
    while (node != NULL) {
        func_ov000_02153c48(node, self->unk_1c, 0, 0, 0);
        if (LFLD(s32, LFLD(u8 *, node, 0x1c), 0x44) > maxw) {
            maxw = LFLD(s32, LFLD(u8 *, node, 0x1c), 0x44);
        }
        node = LFLD(u8 *, node, 0x2c);
    }
    self->unk_20 = self->unk_9c;
    if (self->unk_24 == -1) {
        if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
            self->unk_24 = 0x100;
        } else {
            self->unk_24 = maxw + 0x40;
            if (self->unk_24 < 0x98) {
                self->unk_24 = 0x98;
            }
        }
    }
    self->unk_28 = self->vfunc_44();
    if (self->unk_10 == NULL) {
        if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
            self->unk_10 = new ModelObj(data_0208cb84, data_0208cc8c);
        } else {
            self->unk_10 = new ModelObj(data_0208cb74, data_0208cca0);
        }
        {
            ResList *a = func_02035d5c(self->unk_10->name);
            func_020417e0(self->unk_10, func_02034d88(a, self->unk_10->unk_04c));
        }
        self->unk_10->flags |= 2;
        func_02041d9c(self->unk_10, 0, 7);
    }
    if (self->unk_ac == NULL) {
        self->unk_ac = new Panel0215aa78();
        if (LBIT(self, 0xc).b3 ? TRUE : FALSE) {
            self->unk_ac->flags.b3 = 1;
            self->unk_ac->SetOfs((maxw >> 1) + 0x10, 0);
        } else {
            self->unk_ac->flags.b1 = 3;
            self->unk_ac->flags.b0 = 1;
        }
        func_ov000_0215e8b0(self->unk_ac);
        self->unk_ac->unk_10 = (self->unk_24 - 0x20) << 12;
        self->unk_ac->model->flags |= 0x200000;
        self->unk_ac->model->flags |= 0x100000;
        self->unk_ac->model->flags |= 0x80000;
        MODEL_FLAGS(self->unk_ac->model)->alpha = 0x1e;
    }
    self->unk_2c = 0;
    self->unk_64 = 0x80 - (self->unk_24 >> 1);
    self->unk_66 = 0x60 - (self->unk_28 >> 1);
    LBIT(self, 0xc).b0 = 1;
}

}
