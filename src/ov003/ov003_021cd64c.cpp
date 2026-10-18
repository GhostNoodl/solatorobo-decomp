#include "types.h"

typedef struct {
    u8 unk_00[0x3c];
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u16 unk_58;
    u32 unk_5c;
    u8 unk_60[0xc];
    u32 unk_6c;
    u32 unk_70;
    u32 unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    u32 unk_84;
    u32 unk_88;
    u8 unk_8c[0x40];
} Ov003Title;

class Ov003VObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Draw();
};

typedef struct {
    u8 unk_00[0x4c];
    u8 *unk_4c;
} Ov003Sys;

typedef struct {
    u8 unk_00[8];
    s32 state;
    u8 unk_0c[0x30];
    Ov003VObj *unk_3c;
    u8 unk_40[0x24];
    u16 unk_64;
    u8 unk_66[2];
    u8 unk_68;
    u8 unk_69;
} Ov003Menu;

typedef struct {
    u32 unk_00;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Ov003FlagSet;

extern "C" {

extern void *data_02097e4c;
extern Ov003Sys *data_02fe152c;
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern s32 func_0205976c(Ov003Sys *sys, s32 a);
extern void func_02059360(Ov003Sys *sys, void *p, s32 a, s32 b, u16 c, s32 d);
extern void func_ov003_021cd91c(Ov003Menu *self);

extern char data_ov003_021f78c4[];
extern char data_ov003_021f78cd[];
extern void func_ov000_021c8408(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f, u32 g, u32 h, u32 i, u32 j, u32 k);
extern void func_ov000_021c2208(void *p);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern u32 func_02035bd4(const void *a, const void *b, s32 c);

bool func_ov003_021cd64c(Ov003FlagSet *self) {
    BOOL r = self->b4 ? TRUE : FALSE;
    return r;
}

void func_ov003_021cd670(void) {
}

void func_ov003_021cd674(Ov003Menu *self) {
    switch (self->state) {
    case 0xc:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 0xa:
        if (self->unk_68 == self->unk_69) {
            u8 *base = data_02fe152c->unk_4c;
            s32 v = func_0205976c(data_02fe152c, 0xb);
            func_02059360(data_02fe152c, base + 0x170, v, 1, self->unk_64, 1);
            func_02059360(data_02fe152c, base + 0x170, v, 0x101, self->unk_64, 1);
        }
        break;
    }
    self->unk_3c->Draw();
    func_ov003_021cd91c(self);
}

void func_ov003_021cd740(void) {
}

}
