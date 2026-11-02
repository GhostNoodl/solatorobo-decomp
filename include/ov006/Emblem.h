#ifndef OV006_EMBLEM_H
#define OV006_EMBLEM_H

#include "ov006/Model.h"
#include "ov000/Task.h"

// The emblem task (vtable data_ov006_021ebe40, 0x5c bytes, created by ov006_Emblem_New):
// ov006_Emblem_LoadModels builds its two models, func_ov006_021ce590 plays them.
struct ov006_Emblem : public Task {
    Model *unk3C;
    Model *unk40;
    u8 unk44;
    int unk48; // the unk40 model's render argument (func_02041c20)
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
};

#endif
