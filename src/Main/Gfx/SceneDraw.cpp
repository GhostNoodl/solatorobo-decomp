#include "Main/Sys/GameScene.h"
#include "nitro/fx.h"

extern "C" {

typedef struct SceneObjPart {
    u8 unk_00[0x4c];
} SceneObjPart;

typedef struct SceneObj {
    /* 0x00 */ SceneObjPart parts[3];
    /* 0xe4 */ u8 unk_e4[0x64];
} SceneObj; // size 0x148

typedef struct SceneDrawData {
    /* 0x000 */ u8 unk_000[0x3d8];
    /* 0x3d8 */ SceneObjPart mainParts[3];
    /* 0x4bc */ u8 unk_4bc[0x44];
    /* 0x500 */ SceneObj objs[5];
} SceneDrawData;

typedef struct SceneG3dGlb {
    /* 0x00 */ u8 unk_00[0xfc];
    /* 0xfc */ u32 flag;
} SceneG3dGlb;

extern SceneG3dGlb NNS_G3dGlb;
extern MtxFx44 data_02092800;
extern MtxFx43 data_02092844;

extern void NNS_G3dGeFlushBuffer(void);
extern void MI_Copy64B(const void *src, void *dst);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);
extern void func_02053254(GameScene *scene, int a, void *obj, int b);

static inline void Scene_SetProjectionMtx(const MtxFx44 *mtx) {
    MIi_CpuCopyFast(mtx, &data_02092800, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~0x50;
}

void func_0205311c(GameScene *scene) {
    MtxFx44 proj;
    MtxFx43 cam;
    MtxFx44 ortho;
    MtxFx43 *glbCam;
    int i;
    NNS_G3dGeFlushBuffer();
    glbCam = &data_02092844;
    MI_Copy64B(&data_02092800, &proj);
    MI_Copy48B(glbCam, &cam);
    MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, &ortho);
    Scene_SetProjectionMtx(&ortho);
    MTX_Identity43_(glbCam);
    glbCam->m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    func_02053254(scene, 2, &((SceneDrawData *)scene)->mainParts[2], 0);
    for (i = 0; i < 5; i++) {
        SceneObj *o = &((SceneDrawData *)scene)->objs[i];
        func_02053254(scene, 2, &o->parts[2], 1);
    }
    NNS_G3dGeFlushBuffer();
    Scene_SetProjectionMtx(&proj);
    MI_Copy48B(&cam, glbCam);
}

}
