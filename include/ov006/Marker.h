#ifndef OV006_MARKER_H
#define OV006_MARKER_H

#include "ov006/Model.h"
#include "nitro/fx.h"

/* One slot marker (vtable data_ov006_021ec2ec, 0x24 bytes; ctor Ov006Vt_021ec2ec_Ctor,
   updated by func_ov006_021e1f80). state 0 is idle; the update slides pos from slot unkA to
   slot unkB over 10 frames (timer) until unkA reaches unkC. */
typedef struct ov006_Marker {
    void *vtbl;
    u16 state;
    u16 unk6;
    s16 timer;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    s32 unk10;
    s32 unk14;
    VecFx32 pos;
} ov006_Marker;

/* Four markers drawn with one model (vtable data_ov006_021ec2cc, 0xa4 bytes; ctor
   Ov006Vt_021ec2cc_Ctor, built by func_ov006_021e22e4, updated by func_ov006_021e2430,
   drawn at (unk8, unkC) by func_ov006_021e2490). */
typedef struct ov006_MarkerSet {
    void *vtbl;
    u8 unk4;
    s32 unk8;
    s32 unkC;
    ov006_Marker markers[4];
    Model *model;
} ov006_MarkerSet;

#ifdef __cplusplus
extern "C" {
#endif

ov006_Marker *Ov006Vt_021ec2ec_Ctor(ov006_Marker *self);
void func_ov006_021e1f68(ov006_Marker *self);
void func_ov006_021e1f80(ov006_Marker *self);

#ifdef __cplusplus
}
#endif

#endif
