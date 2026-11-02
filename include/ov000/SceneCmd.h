#ifndef OV000_SCENECMD_H
#define OV000_SCENECMD_H

#include "types.h"
#include "ov000/VObj.h"
#include "ov000/SceneRes.h"
#include "ov000/CmdObj.h"
#include "Main/Sys/FieldState.h"
#include "Main/Math/Rot16.h"

// The C++ view of the scene command object data_ov000_021ccd54 (Main/Sys/FieldState.h is the C
// view of the same 0x214 bytes: ctor func_ov000_02188ba0, allocated by func_ov000_021814dc, freed
// by func_ov000_02181624). Its event runner is the CmdObj base, so the overlay 0 command
// handlers (the pointer-to-member callbacks of data_ov000_021cc1a0) take it as `self`.

// The stage script block at SceneCmd 0xac (FieldState::stageFlags): cleared by
// SceneStage_FreeScripts, saved/loaded by SceneStage_Serialize/02181c4c and stepped by
// func_ov000_02182590.
typedef struct SceneStage {
    /* 0x00 */ u8 pending;           // set to ask for a step, cleared by func_ov000_02182590
    /* 0x04 */ SceneRes *res;       // the resource group `group` (func_ov000_02181d70)
    /* 0x08 */ u16 group;           // Lang_GetGroup id, 0xfe for the special group, 0xffff for none
    /* 0x0c */ SceneScript *main;   // func_ov000_02181f54
    /* 0x10 */ SceneScript *scripts; // SceneStage_AddScript / 02182374
    /* 0x14 */ SceneRes *cur;       // the script that is running (func_ov000_02182590)
    /* 0x18 */ u8 unk_18;           // cur is a SceneScript or the main script
} SceneStage;
SIZE_ASSERT(SceneStage, 0x1c);

class SceneCmd : public CmdObj {
public:
    /* 0x0ac */ SceneStage stage;
    /* 0x0c8 */ u8 unk_c8;
    /* 0x0c9 */ u8 unk_c9;
    /* 0x0ca */ FieldId unk_ca;
    /* 0x0cd */ FieldId unk_cd;
    /* 0x0d0 */ FieldId unk_d0;
    /* 0x0d3 */ u8 unk_d3;
    /* 0x0d4 */ u32 event; // FieldState::event
    // 0xd3..0xf0: the camera target that func_ov000_02188ed0 hands to the field camera
    // (func_ov000_0218a358: position, rotation, distance and the two s16 rates).
    /* 0x0d8 */ VecFx32 unk_d8;
    /* 0x0e4 */ Rot16 unk_e4;
    /* 0x0ea */ u8 unk_ea[2];
    /* 0x0ec */ s32 unk_ec;
    /* 0x0f0 */ s16 unk_f0;
    /* 0x0f4 */ FieldCam cam; // vtable data_ov000_021cc3a0
};
SIZE_ASSERT(SceneCmd, 0x214);

// data_ov000_021ccd54 (declared with its C type in Main/Sys/FieldState.h) as its C++ class.
static inline SceneCmd *SceneCmd_Get(void) {
    return (SceneCmd *)data_ov000_021ccd54;
}

#endif
