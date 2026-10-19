#include "ov006/Tasks.h"

typedef struct ov006_Prop6210 {
    u8 unk0[0x19c];
    u16 unk19C_0 : 9;
    u16 unk19C_9 : 1;
    u16 unk19C_10 : 6;
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0[0xb];
    u8 unk1AB;
    u8 unk1AC[0x14];
    int unk1C0;
    int unk1C4;
    int unk1C8;
} ov006_Prop6210;

typedef struct ov006_SlotSubBits {
    u16 unk0;
    union {
        u8 raw;
        struct {
            u8 b0 : 3;
            u8 b3 : 1;
            u8 b4 : 1;
            u8 b5 : 3;
        } bits;
    } unk2;
    u8 unk3;
    int unk4;
    int unk8;
    int unkC;
} ov006_SlotSubBits;

extern "C" {

u8 func_ov006_021d8cb8(void);
void func_ov006_021e7004(ov006_Prop6210 *self, ov006_SlotSubBits *sub);
void func_ov006_021daba0(ov006_Slot *self, const ov006_SlotSubBits *src);

static inline void ov006_Prop6210_Commit(ov006_Prop6210 *self, ov006_Slot *slot, ov006_SlotSubBits *sub) {
    sub->unk2.bits.b0 = self->unk1AB;
    sub->unk2.bits.b4 = self->unk19C_9;
    sub->unk4 = self->unk1C0;
    sub->unk8 = self->unk1C4;
    sub->unkC = self->unk1C8;
    func_ov006_021daba0(slot, sub);
}

void func_ov006_021e6210(ov006_Prop6210 *self) {
    ov006_Slot *slot = func_ov006_021db060(data_ov006_021ec884, self->unk19E);
    ov006_SlotSubBits sub;
    sub.unk0 = 0;
    sub.unk2.raw = 0;
    sub.unk3 = 0;
    sub.unk4 = 0;
    sub.unk8 = 0;
    sub.unkC = 0;
    if (slot->unk8 != 0) {
        ov006_SlotManager *mgr = data_ov006_021ec884;
        ov006_SlotManagerInfo *info;
        BOOL over;
        if (self->unk19E != mgr->unk5) {
            return;
        }
        info = mgr->unk8;
        over = FALSE;
        if (self->unk19F > info->unkB) {
            over = TRUE;
        }
        if (over || func_ov006_021d8cb8() <= 1) {
            if (info->unkB != 0) {
                func_ov006_021e7004(self, &sub);
            }
        } else {
            sub.unk0 = data_02097dc8->unk10;
        }
        ov006_Prop6210_Commit(self, slot, &sub);
    } else {
        if (data_ov006_021ec884->unk5 != 0) {
            return;
        }
        func_ov006_021e7004(self, &sub);
        ov006_Prop6210_Commit(self, slot, &sub);
    }
}

}
