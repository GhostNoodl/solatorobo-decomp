#include "ov000/SceneCmd.h"

// The 0x021ccd50 pool of the scene command TU: gSceneCmd is four bytes in.
typedef struct {
    u8 unk_00[0x4];
    SceneCmd *scene;
} Data021ccd50;

typedef struct {
    u16 flags;
} Obj02097e48;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *gSndQueue;

void func_ov000_02188ca0(FieldId *id, s32 arg) {
    gSndQueue->flags |= 2;
    CmdObj_Push(data_ov000_021ccd50.scene, 9, arg);
    if (id != NULL) {
        data_ov000_021ccd50.scene->unk_cd = *id;
    }
}
}
