#include "ov006/Model.h"

typedef struct ov006_Unk021dfa60 {
    void *vtbl;
    u8 unk4[0x10];
    int unk14;
    int unk18;
    Object *unk1C;
    Object *unk20;
} ov006_Unk021dfa60;

extern "C" {

extern u8 data_ov006_021ec23c[];
extern void *data_0214a420;
Object *func_020657b0(void *a, int id);

static inline void ov006_Unk021dfa60_Kill(int id) {
    if (id != -1) {
        Object *o = func_020657b0(data_0214a420, id);
        if (o != NULL) {
            void *saved = data_02097dd0->current;
            data_02097dd0->current = data_02097dd0->unk8;
            if (o != NULL) {
                if (o != NULL) {
                    o->vtbl->dtor(o);
                }
            }
            data_02097dd0->current = saved;
        }
    }
}

static inline void ov006_Unk021dfa60_dtor(ov006_Unk021dfa60 *self) {
    self->vtbl = data_ov006_021ec23c;
    ov006_Unk021dfa60_Kill(self->unk14);
    ov006_Unk021dfa60_Kill(self->unk18);
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
}

ov006_Unk021dfa60 *func_ov006_021dfa60(ov006_Unk021dfa60 *self) {
    ov006_Unk021dfa60_dtor(self);
    return self;
}

ov006_Unk021dfa60 *func_ov006_021dfba0(ov006_Unk021dfa60 *self) {
    ov006_Unk021dfa60_dtor(self);
    func_0203de1c(self);
    return self;
}

}
