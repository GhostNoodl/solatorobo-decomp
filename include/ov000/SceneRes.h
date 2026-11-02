#ifndef OV000_SCENERES_H
#define OV000_SCENERES_H

#include "types.h"
#include "ov000/VObj.h"

// A stage script resource as the scene reaches it: a StageRes (Main/Res/StageRes.h, 0xc4 bytes,
// vtables data_0208b318 -> data_0208bf54), called through its vtable slots. The scene's resource
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

// A stage script (vtable data_ov000_021cc158, 0xd8 bytes): the StageRes plus its id, its four
// arguments and the list links. func_ov000_02181f54 makes the main one (SceneStage::main),
// func_ov000_02182190 inserts the others into SceneStage::scripts by descending order.
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

// data_ov000_021ccd24 (0xc bytes of .bss): a flag and two stage script resources, unk_04 made by
// func_ov000_0214ba18 and unk_08 by func_ov000_0214e7f0.
typedef struct SceneResSet {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ SceneRes *unk_04;
    /* 0x08 */ SceneRes *unk_08;
} SceneResSet;

#ifdef __cplusplus
extern "C" {
#endif
extern SceneResSet data_ov000_021ccd24;
#ifdef __cplusplus
}
#endif

#endif
