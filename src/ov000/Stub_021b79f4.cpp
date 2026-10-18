#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s16 unk_10;
    u16 unk_12;
    u8 unk_14[0x8];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0xc0];
    s32 unk_ec;
    s32 unk_f0;
    u8 unk_f4;
    u8 unk_f5;
    u8 unk_f6;
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
    s32 unk_110;
} Obj021b79f4;

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x6];
    u16 unk_12_0 : 1;
    u16 unk_12_1 : 1;
    u16 unk_12_2 : 14;
    u8 unk_14[0x8];
    void **unk_1c;
    void **unk_20;
    u8 unk_24[0x8];
    u8 unk_2c[0xc0];
    void *unk_ec;
} Obj021b7a7c;

extern "C" {

extern HeapState *data_02097dd0;
extern void *data_02097cdc;
void func_0203f920(void *p);
void func_0203f864(void *p);
void func_0203de1c(void *p);
void func_0203f0b4(void *p);
void func_ov000_021b700c(void *p);
void func_02036838(void *p, s32 a, s32 b, s32 c);

void func_ov000_021b6f94(void *p);

Obj021b79f4 *func_ov000_021b79f4(Obj021b79f4 *self) {
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = -1;
    self->unk_12 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    func_ov000_021b6f94(self->unk_2c);
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_ec = 0;
    self->unk_f0 = 0;
    self->unk_f4 = 0;
    self->unk_f5 = 0;
    self->unk_f6 = 0;
    self->unk_f8 = 0;
    self->unk_fc = -0xc3000;
    self->unk_100 = -0x4e000;
    self->unk_104 = -0xc3000;
    self->unk_108 = 0xc3000;
    self->unk_10c = 0x4e000;
    self->unk_110 = 0xc3000;
    return self;
}

Obj021b7a7c *func_ov000_021b7a7c(Obj021b7a7c *self) {
    if (self->unk_ec != NULL) {
        void *saved;
        void *p;
        func_0203f920(self->unk_ec);
        saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        p = self->unk_ec;
        if (p != NULL) {
            if (p != NULL) {
                func_0203f864(p);
                func_0203de1c(p);
            }
            self->unk_ec = NULL;
        }
        data_02097dd0->current = saved;
    }
    func_ov000_021b700c(self->unk_2c);
    if (self->unk_1c != NULL) {
        func_0203f0b4(*self->unk_1c);
    }
    if (self->unk_20 != NULL) {
        func_0203f0b4(*self->unk_20);
    }
    if (self->unk_12_0 && self->unk_12_1) {
        func_02036838(data_02097cdc, self->unk_08, 7, 0);
    }
    return self;
}

}
