#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {

extern ov006_DataRes *data_02fe152c;
void func_ov006_021cf7c8(ov006_TaskCE *self);
void func_ov006_021cf89c(ov006_TaskCE *self);
void func_ov006_021cfa80(ov006_TaskCE *self);
void func_ov006_021cfc60(ov006_TaskCE *self);
void func_ov006_021db65c(void);
void *func_0205976c(ov006_DataRes *res, u32 idx);
u32 func_0205975c(ov006_DataRes *res, u32 idx);
BOOL func_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov006_021e2f3c(Object *a);

void func_ov006_021cf420(ov006_TaskCE *self) {
    u8 *block;
    u16 n;
    u16 i;
    void *ent;
    switch (self->base.state) {
    case 0:
        func_ov006_021cf7c8(self);
        break;
    case 1:
        switch (self->base.subState) {
        case 0:
            OV006_DELETE_OBJECT(self->unk4C);
            self->unk4C = ov006_MsgBox_New();
            func_ov000_021632f0(self->unk4C, 1, data_ov006_021ebbd1, data_ov006_021ebbde, 0);
            self->unk44->flags |= 4;
            self->unk48->flags |= 2;
            self->unk44->flags |= 4;
            self->unk44->flags |= 2;
            self->unk48->flags |= 2;
            self->base.subState++;
            break;
        case 1:
            if (!func_ov000_021633ac(self->unk4C)) {
                OV006_DELETE_OBJECT(self->unk4C);
                self->unk44->flags &= ~4;
                self->unk48->flags &= ~2;
                if (self->unk50 == NULL) {
                    self->base.state = 3;
                    self->base.subState = 0;
                } else {
                    self->base.state = 2;
                    self->base.subState = 0;
                }
            }
            break;
        }
        break;
    case 2:
        func_ov006_021cf89c(self);
        break;
    case 3:
        func_ov006_021cfa80(self);
        break;
    case 4: {
        func_ov006_021db65c();
        block = data_02fe152c->unk4C + 0x1d0;
        ent = func_0205976c(data_02fe152c, 0xe);
        n = func_0205975c(data_02fe152c, 0xe);
        for (i = 0; i < n; i++) {
            if (func_02059544(data_02fe152c, block, ent, 1, i)) {
                func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC = i | 0x7000;
                break;
            }
        }
        func_ov000_0218084c(data_ov000_021ccd44, 0x29, 0);
        data_ov006_021ec860->unk1C = 0;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->base.state = 7;
        self->base.flags |= 6;
        self->base.subState = 0;
        break;
    }
    case 5:
        func_ov000_0218084c(data_ov000_021ccd44, 0x27, TRUE);
        data_ov006_021ec860->unk1C = TRUE;
        self->unk44->flags |= 4;
        self->unk44->flags |= 2;
        self->unk48->flags |= 2;
        self->base.flags |= 6;
        self->base.state = 7;
        self->base.subState = 0;
        break;
    case 6:
        func_ov006_021cfc60(self);
        break;
    case 7:
        break;
    }
    VCALL(self->unk44, 1C);
    VCALL(self->unk48, 1C);
    if (self->unk50 != NULL) {
        VCALL(self->unk50, 1C);
    }
    func_ov006_021e2f3c(self->unk54);
}

}
