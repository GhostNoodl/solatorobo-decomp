#ifndef MAIN_SYS_FIELDSTATE_H
#define MAIN_SYS_FIELDSTATE_H

#include "types.h"
#include "nitro/fx.h"
#include "Main/Gfx/Camera.h"

#ifdef __cplusplus
extern "C" {
#endif

// A 3-byte id (compared and copied as a whole by the field code).
typedef struct FieldId {
    u8 c[3];
} FieldId;

// The field camera (ctor Ov000Vt_021cc3a0_Ctor, vtable data_ov000_021cc3a0): a Camera with
// an overlay 0 extension, 0x120 bytes.
typedef struct FieldCam {
    /* 0x00 */ Camera base;
    /* 0xbc */ VecFx32 unk_bc;
    /* 0xc8 */ s32 unk_c8;
    /* 0xcc */ s32 unk_cc;
    /* 0xd0 */ u8 unk_d0[4];
    /* 0xd4 */ s16 unk_d4;
    /* 0xd6 */ s16 unk_d6;
    /* 0xd8 */ union {
        u8 unk_d8;
        struct {
            u8 unk_d8_0 : 1;
            u8 unk_d8_1_f : 7;
        };
    };
    /* 0xd9 */ u8 unk_d9;
    /* 0xda */ union {
        u8 unk_da;
        struct {
            u8 unk_da_0 : 1;
            u8 unk_da_1 : 1;
            u8 unk_da_2 : 2;
            u8 unk_da_4_f : 4;
        };
    };
    /* 0xdb */ u8 unk_db;
    /* 0xdc */ VecFx32 unk_dc;
    /* 0xe8 */ u8 unk_e8[0xc];
    /* 0xf4 */ s32 unk_f4;
    /* 0xf8 */ u8 unk_f8[0x28];
} FieldCam;
SIZE_ASSERT(FieldCam, 0x120);

// The field state data_ov000_021ccd54 (ctor func_ov000_02188ba0, 0x214 bytes, built by
// func_ov000_021814dc). It starts with the event command runner that ov000/CmdObj.h declares
// (state, the 16-entry event ring, the step callback) and holds the field camera.
typedef struct FieldState {
    /* 0x000 */ s32 state;
    /* 0x004 */ u16 unk_04;
    /* 0x006 */ u8 unk_06;
    /* 0x007 */ u8 unk_07;
    /* 0x008 */ u8 pause[8]; // pause node (PauseNode_Init)
    /* 0x010 */ s32 queue[0x10];
    /* 0x050 */ s32 queueArg[0x10];
    /* 0x090 */ s32 head;
    /* 0x094 */ s32 tail;
    /* 0x098 */ s32 unk_98;
    /* 0x09c */ u32 unk_9c[2]; // step callback (CmdObj::unk_9c, a pointer to member)
    /* 0x0a4 */ u16 unk_a4;
    /* 0x0a6 */ u16 unk_a6;
    /* 0x0a8 */ u16 unk_a8;
    /* 0x0aa */ u8 unk_aa[2];
    // 0xac..0xc7: the stage flag sub-object of func_ov000_021819a4 / func_ov000_02182590
    /* 0x0ac */ u8 stageFlags; // start of the stage flag block (StageFlags_SaveBuf / LoadBuf)
    /* 0x0b0 */ s32 unk_b0;
    /* 0x0b4 */ u16 unk_b4;
    /* 0x0b8 */ void *unk_b8;
    /* 0x0bc */ void *unk_bc;
    /* 0x0c0 */ void *unk_c0;
    /* 0x0c4 */ u8 unk_c4;
    /* 0x0c5 */ u8 unk_c5[3];
    /* 0x0c8 */ u8 unk_c8;
    /* 0x0c9 */ u8 unk_c9;
    /* 0x0ca */ FieldId unk_ca;
    /* 0x0cd */ FieldId unk_cd;
    /* 0x0d0 */ FieldId unk_d0;
    /* 0x0d3 */ u8 unk_d3;
    /* 0x0d4 */ u32 event; // pending event (Field_HasEvent: != 0)
    /* 0x0d8 */ s32 unk_d8;
    /* 0x0dc */ s32 unk_dc;
    /* 0x0e0 */ s32 unk_e0;
    /* 0x0e4 */ u16 unk_e4;
    /* 0x0e6 */ u16 unk_e6;
    /* 0x0e8 */ u16 unk_e8;
    /* 0x0ec */ s32 unk_ec;
    /* 0x0f0 */ u16 unk_f0;
    /* 0x0f4 */ FieldCam cam;
} FieldState;
SIZE_ASSERT(FieldState, 0x214);

// Screen fade state data_ov000_021ccd70: func_ov000_021bc3ec starts a fade (state 1, mode,
// duration), func_ov000_021bc458 ends it (state 2); state 0 is idle.
typedef struct FieldFade {
    /* 0x00 */ u32 flag0 : 1;
    /* 0x00 */ u32 flag1 : 1;
    /* 0x00 */ u32 unk_00_2 : 30;
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 mode;
    /* 0x0c */ s32 unk_0c;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 duration;
} FieldFade;

extern FieldState *data_ov000_021ccd54;
extern FieldFade *data_ov000_021ccd70;

#ifdef __cplusplus
}
#endif

#endif
