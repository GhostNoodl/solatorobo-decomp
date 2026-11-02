#ifndef OV006_GAUGE_H
#define OV006_GAUGE_H

#include "ov006/Model.h"
#include "Main/Gfx/TextWin.h"

/* A gauge (vtable data_ov006_021ec20c, 0x24 bytes, ctor Ov006Vt_021ec20c_Ctor; func_ov006_021e0f00
   builds its model and text). func_ov006_021e139c sets its ratio unkC = a / b, func_ov006_021e10d0
   eases unk8 toward it (at once when unk5 is clear) and func_ov006_021e1180 draws it at x, y. */
typedef struct ov006_Gauge {
    void *vtbl;
    u8 unk4;            // set once the model is loaded
    u8 unk5;
    u8 unk6[2];
    fx32 unk8;
    fx32 unkC;
    int unk10;
    int x;
    int y;
    Model *model;
    TextWin *text;      // func_ov006_021e13c8 sets its string
} ov006_Gauge;

#endif
