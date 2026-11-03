#ifndef OV006_GAUGE_H
#define OV006_GAUGE_H

#include "ov006/Model.h"
#include "Main/Gfx/TextWin.h"

/* A gauge (vtable Ov006Vt_021ec20c_vtbl, 0x24 bytes, ctor Ov006Vt_021ec20c_Ctor; ov006_Gauge_Load
   builds its model and text). ov006_Gauge_SetRatio sets its ratio unkC = a / b, ov006_Gauge_Update
   eases unk8 toward it (at once when unk5 is clear) and ov006_Gauge_Draw draws it at x, y. */
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
    TextWin *text;      // ov006_Gauge_SetText sets its string
} ov006_Gauge;

#endif
