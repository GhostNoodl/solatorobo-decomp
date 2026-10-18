#ifndef OV006_EMBLEM_H
#define OV006_EMBLEM_H

#include "ov006/Model.h"

typedef struct ov006_Emblem {
    void *vtbl;
    u32 unk4_0 : 1;
    u32 unk4_1 : 1;
    u32 unk4_2 : 2;
    u32 unk4_4 : 1;
    u32 unk4_5 : 27;
    u8 unk8[0x24];
    int unk2C;
    u8 unk30[0xc];
    ov006_Model *unk3C;
    ov006_Model *unk40;
    u8 unk44;
    int unk48;
    int unk4C;
} ov006_Emblem;

#endif
