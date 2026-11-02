#include "ov006/Tasks.h"
#include "ov006/Racer.h"

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
void func_ov006_021e7004(Ov006Racer *self, ov006_SlotSubBits *sub);
void func_ov006_021daba0(ov006_Slot *self, const ov006_SlotSubBits *src);

static inline void Ov006Racer_Commit(Ov006Racer *self, ov006_Slot *slot, ov006_SlotSubBits *sub) {
    sub->unk2.bits.b0 = self->unk_1ab;
    sub->unk2.bits.b4 = self->toggle;
    sub->unk4 = self->unk_1c0.x;
    sub->unk8 = self->unk_1c0.y;
    sub->unkC = self->unk_1c0.z;
    func_ov006_021daba0(slot, sub);
}

void func_ov006_021e6210(Ov006Racer *self) {
    ov006_Slot *slot = func_ov006_021db060(data_ov006_021ec884, self->idx);
    ov006_SlotSubBits sub;
    sub.unk0 = 0;
    sub.unk2.raw = 0;
    sub.unk3 = 0;
    sub.unk4 = 0;
    sub.unk8 = 0;
    sub.unkC = 0;
    if (slot->type != 0) {
        ov006_SlotManager *mgr = data_ov006_021ec884;
        ov006_SlotManagerInfo *info;
        BOOL over;
        if (self->idx != mgr->unk5) {
            return;
        }
        info = mgr->info;
        over = FALSE;
        if (self->unk_19f > info->unkB) {
            over = TRUE;
        }
        if (over || func_ov006_021d8cb8() <= 1) {
            if (info->unkB != 0) {
                func_ov006_021e7004(self, &sub);
            }
        } else {
            sub.unk0 = data_02097dc8->cur;
        }
        Ov006Racer_Commit(self, slot, &sub);
    } else {
        if (data_ov006_021ec884->unk5 != 0) {
            return;
        }
        func_ov006_021e7004(self, &sub);
        Ov006Racer_Commit(self, slot, &sub);
    }
}

}
