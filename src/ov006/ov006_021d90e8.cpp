#include "ov006/Model.h"

typedef struct ov006_Unk021d90e8 {
    void *vtbl;
    u8 unk4[0xc];
    Object *unk10;
    Object *unk14;
    Object *unk18;
    Object *unk1C;
    Object *unk20;
    Object *unk24;
    Object *unk28;
} ov006_Unk021d90e8;

extern "C" {

extern u8 data_ov006_021ec040[];
extern void *data_02097cdc;
extern void *data_0208cc94;
extern u8 data_ov006_021ec864[];
void func_ov000_02180754(void);
void func_02036838(void *a, void *b, int c, int d);
void func_ov006_021ccddc(void *self);

static inline void ov006_Unk021d90e8_dtor(ov006_Unk021d90e8 *self) {
    self->vtbl = data_ov006_021ec040;
    OV006_DELETE_OBJECT(self->unk10);
    OV006_DELETE_OBJECT(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
    OV006_DELETE_OBJECT(self->unk24);
    OV006_DELETE_OBJECT(self->unk28);
    func_ov000_02180754();
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_02036838(data_02097cdc, data_ov006_021ec864, 7, 0);
    func_ov006_021ccddc(self);
}

ov006_Unk021d90e8 *func_ov006_021d90e8(ov006_Unk021d90e8 *self) {
    ov006_Unk021d90e8_dtor(self);
    return self;
}

ov006_Unk021d90e8 *func_ov006_021d92e4(ov006_Unk021d90e8 *self) {
    ov006_Unk021d90e8_dtor(self);
    func_0203de1c(self);
    return self;
}

}
