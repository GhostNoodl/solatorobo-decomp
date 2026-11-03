#ifndef OV000_SCENERES_H
#define OV000_SCENERES_H

#include "types.h"
#include "ov000/VObj.h"

// A stage script resource as the scene reaches it: a StageRes (Main/Res/StageRes.h, 0xc4 bytes,
// vtables ResHandle_vtbl -> StageRes_vtbl), called through its vtable slots. The scene's resource
// group (SceneStage::res, func_ov000_02181d70) is one of these.
class SceneRes : public VObj {
public:
    /* 0x04 */ u8 unk_04[0x56];
    /* 0x5a */ u8 unk_5a; // StageRes::unk_5a: still running (the stage step tests it)
    /* 0x5b */ u8 unk_5b[0x61];
    /* 0xbc */ void *sub;   // StageRes::sub (its message data, MsgRes_GetString)
    /* 0xc0 */ void *posEv; // StageRes::posEv
};
SIZE_ASSERT(SceneRes, 0xc4);

// A stage script (vtable Ov000Vt_021cc158_vtbl, 0xd8 bytes): the StageRes plus its id, its four
// arguments and the list links. func_ov000_02181f54 makes the main one (SceneStage::main),
// SceneStage_AddScript inserts the others into SceneStage::scripts by descending order.
class SceneScript : public SceneRes {
public:
    /* 0xc4 */ u16 order;
    /* 0xc6 */ u16 id;
    /* 0xc8 */ u16 unk_c8;
    /* 0xca */ u16 unk_ca;
    /* 0xcc */ u16 unk_cc;
    /* 0xce */ u16 unk_ce;
    /* 0xd0 */ SceneScript *prev;
    /* 0xd4 */ SceneScript *next;
};
SIZE_ASSERT(SceneScript, 0xd8);

// gSceneResSet (0xc bytes of .bss): a flag and two stage script resources, unk_04 made by
// func_ov000_0214ba18 and unk_08 by Lo021caa44_Load.
typedef struct SceneResSet {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ SceneRes *unk_04;
    /* 0x08 */ SceneRes *unk_08;
} SceneResSet;

#ifdef __cplusplus
extern "C" {
#endif
extern SceneResSet gSceneResSet;
#ifdef __cplusplus
}
#endif

#endif
