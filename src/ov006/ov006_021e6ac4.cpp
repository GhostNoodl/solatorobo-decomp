#include "ov006/Tasks.h"

typedef struct ov006_Msg6ac4 {
    u8 unk0[5];
    u8 unk5;
    u16 unk6;
    u8 unk8[2];
    u8 unkA;
} ov006_Msg6ac4;

typedef struct ov006_Flags6ac4 {
    u8 unk0[4];
    u32 unk4;
    u32 unk8;
} ov006_Flags6ac4;

typedef struct ov006_Color6ac4 {
    u8 unk0[0xb6];
    u16 unkB6;
    u16 unkB8;
    u16 unkBA;
    u16 unkBC;
} ov006_Color6ac4;

typedef struct ov006_Effect6ac4 {
    u8 unk0[0x24];
    int unk24;
    u8 unk28[0x14];
    int unk3C;
} ov006_Effect6ac4;

typedef struct ov006_Prop6ac4 {
    void *vtbl;
    u8 unk4[8];
    u16 unkC;
    u8 unkE[0x22];
    u32 unk30;
    u8 unk34[4];
    ov006_Color6ac4 *unk38;
    u8 unk3C[4];
    ov006_Flags6ac4 *unk40;
    u8 unk44[0x2c];
    u8 unk70[0x12e];
    u8 unk19E;
    u8 unk19F[0xe];
    u8 unk1AD;
    u8 unk1AE[0x3e];
    int unk1EC;
    u8 unk1F0[5];
    u8 unk1F5;
    u8 unk1F6[2];
    u16 unk1F8;
    u16 unk1FA;
} ov006_Prop6ac4;

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;
extern const u16 data_ov006_021eb89c[];

BOOL func_ov000_0218d494(ov006_Prop6ac4 *self, ov006_Msg6ac4 *msg);
ov006_Effect6ac4 *func_02065f88(int id, void *pos);
void *func_020657b0(void *a, int b);
void func_02063a14(void *p);
void *func_02049f44(void *a, int b, void *c, int d);

static inline void ov006_Prop6ac4_Ack(ov006_Prop6ac4 *self, ov006_Msg6ac4 *msg) {
    self->unk30 |= 1 << msg->unk5;
    msg->unk5 = 0;
}

BOOL func_ov006_021e6ac4(ov006_Prop6ac4 *self, ov006_Msg6ac4 *msg) {
    BOOL pass;
    if (!VCALL(self, 14)) {
        ov006_Prop6ac4_Ack(self, msg);
        return TRUE;
    }
    pass = TRUE;
    switch (msg->unk5) {
    case 9:
        pass = FALSE;
        if (self->unk1F5 == 0 && self->unk1F8 == 0) {
            ov006_Color6ac4 *c;
            *(u64 *)&self->unk40->unk4 |= 0x40000;
            c = self->unk38;
            self->unk1F5 = msg->unkA == 0x10 ? 0x37 : 0x64;
            c->unkB6 = 0x14bf;
            c->unkB8 = 0x739f;
            c->unkBA = 0xb;
            c->unkBC = 0xa;
        }
        break;
    case 11:
        pass = FALSE;
        if (msg->unk6 != self->unkC) {
            u16 v = data_ov006_021eb89c[self->unk1AD];
            if (self->unk1FA < v) {
                self->unk1FA = v;
            }
            if (self->unk19E == data_ov006_021ec884->unk5) {
                ov006_Effect6ac4 *e = func_02065f88(0x648, self->unk70);
                if (e != NULL) {
                    void *old;
                    VCALL(e, 0C, 0x1800);
                    e->unk3C = 0x1800;
                    old = func_020657b0(data_0214a420, self->unk1EC);
                    if (old != NULL) {
                        func_02063a14(old);
                        *(int *)((u8 *)old + 0x1c) = 4;
                    }
                    self->unk1EC = e->unk24;
                }
                func_02049f44(data_02097e4c, 0x41, self->unk70, 0);
            }
        }
        break;
    }
    if (pass && func_ov000_0218d494(self, msg)) {
        return TRUE;
    }
    ov006_Prop6ac4_Ack(self, msg);
    return TRUE;
}

}
