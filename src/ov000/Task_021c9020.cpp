#include "ov000/VObj.h"
#include "ov002/BoardRef.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Res/ResArc.h"

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Sub021c9198;

typedef struct {
    u8 pad_00[0x118];
    Sub021c9198 *unk_118;
} Mgr021c9198;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Bits021c9198;

typedef struct {
    fx32 n;
    fx32 f;
    s16 fovySin;
    s16 fovyCos;
    s16 aspect;
    u16 fovyIdx;
    s32 fovyDeg;
    u8 pad_14[2];
    u8 dirty;
} Persp021c930c;

typedef struct {
    u8 pad_00[0xf8];
    VecFx32 pos;
    VecFx32 target;
    VecFx32 up;
    Persp021c930c persp;
} Cam021c930c;

typedef struct {
    u32 b0 : 1;
} Flags021ccd44;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
} Flags021c930c;

typedef struct {
    u8 pad_00[0x2c];
    s32 unk_2c;
} Obj0218084c;

extern "C" {

extern u8 Task_vtbl[];
extern u8 Ov000TaskVt_021ccc94_vtbl[];
extern const char *data_0208cc94;
extern char data_ov000_021ccc68[];
extern char data_ov000_021ccc72[];
extern char data_ov000_021ccc7e[];
void *Heap_Alloc(u32 size);
void Gfx3DState_Init(void *p);
void ResMgr_LoadArchive(void *p, void *q, s32 a, s32 b);
BOOL ResMgr_IsArchiveLoaded(void *p, void *q, s32 a);
void TaskList_Insert(void *self);
extern u8 *gSceneMgr;
extern Mgr021c9198 *gMessageQueue;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_3_ID[];
void Scene_SetSubOverlay_0204b270(void *p, s32 a, s32 b);
void func_ov000_0216f844(void *p, s32 a);
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);
extern Flags021ccd44 *gTaskHost;
extern u8 gTaskSwitchPending;
extern Cam021c930c *gSceneCmd;
Obj0218084c *TaskHost_RequestSwitch(void *a, s32 b, s32 c);

VObj *Ov000TaskVt_021ccc94_New(void) {
    VObj *obj = (VObj *)Heap_Alloc(0x1c4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, Task_vtbl);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, Ov000TaskVt_021ccc94_vtbl);
        Gfx3DState_Init((u8 *)obj + 0x40);
        *(s32 *)((u8 *)obj + 0x3c) = 0;
        *((u8 *)obj + 0x1c0) = 0;
    }
    obj->vfunc_08(0x1a, 0xc8);
    return obj;
}

void Ov000TaskVt_021ccc94_Load(void) {
    ResMgr_Load(data_0208cc94, 7, 0);
    ResMgr_Load(data_ov000_021ccc68, 7, 0);
    ResMgr_LoadArchive(data_ov000_021ccc72, data_ov000_021ccc7e, 2, 0);
}

BOOL Ov000TaskVt_021ccc94_IsLoaded(void) {
    BOOL ok = ResMgr_IsLoaded(data_0208cc94, 7) ? TRUE : FALSE;
    ok = (ok & ResMgr_IsLoaded(data_ov000_021ccc68, 7)) ? TRUE : FALSE;
    return (ok & ResMgr_IsArchiveLoaded(data_ov000_021ccc72, data_ov000_021ccc7e, 2)) ? TRUE : FALSE;
}

void Ov000TaskVt_021ccc94_Start(VObj *self) {
    *(u32 *)((u8 *)self + 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    *(s32 *)((u8 *)self + 0x20) = 0x1000;
    data_ov002_021f0f90.unk_00 = 0;
    TaskList_Insert(self);
}

static inline BOOL SubActive(Sub021c9198 *p) {
    s32 v = 0;
    BOOL r;
    if (p->unk_28 == 1) {
        v = p->unk_30;
    }
    r = TRUE;
    if (v == 0) {
        r = FALSE;
    }
    return r;
}

void Ov000TaskVt_021ccc94_PreUpdate(VObj *self) {
    switch (*(s32 *)((u8 *)self + 0x8)) {
    case 8:
        Scene_SetSubOverlay_0204b270(gSceneMgr, (s32)OVERLAY_2_ID, 0);
        break;
    case 0xc: {
        GfxSys *g;
        u8 flag = FALSE;
        TaskHost_RequestSwitch(gTaskHost, 0x1b, 0);
        self->vfunc_4c();
        if (gMessageQueue != NULL) {
            Sub021c9198 *sub = gMessageQueue->unk_118;
            if (sub != NULL) {
                flag = SubActive(sub) != FALSE;
            }
            if ((*((u8 *)self + 0x1c0) = flag) != 0 && gMessageQueue->unk_118 != NULL) {
                func_ov000_0216f844(gMessageQueue->unk_118, 0);
            }
        }
        g = gGfxSys;
        MIi_CpuCopy32(g->unk_8b0, (u8 *)self + 0x40, 0x180);
        Gfx3DState_SetDefaults(g->unk_8b0);
        ((Bits021c9198 *)(g->unk_8b0))->b4 = 0;
        ((Bits021c9198 *)(g->unk_8b0))->b5 = 1;
        *(vu16 *)0x4000060 &= 0xcfdf;
        Gfx3DState_Apply(g->unk_8b0);
        break;
    }
    case 0xd:
        if (self->vfunc_54()) {
            *(u32 *)((u8 *)self + 0x4) |= 2;
            self->vfunc_0c(0);
        }
        break;
    }
}

void Ov000TaskVt_021ccc94_PostUpdate(VObj *self) {
    GfxSys *g;
    Cam021c930c *cam;
    if (*(s32 *)((u8 *)self + 0x8) != 0) {
        return;
    }
    if (!((Flags021c930c *)((u8 *)self + 0x4))->b2) {
        return;
    }
    TaskHost_RequestSwitch(gTaskHost, *(s32 *)((u8 *)self + 0x3c), 0)->unk_2c = 0;
    gTaskSwitchPending = 1;
    gTaskHost->b0 = 0;
    if (*((u8 *)self + 0x1c0) && gMessageQueue->unk_118 != NULL) {
        func_ov000_0216f844(gMessageQueue->unk_118, 1);
    }
    g = gGfxSys;
    MIi_CpuCopy32((u8 *)self + 0x40, g->unk_8b0, 0x180);
    Gfx3DState_Apply(g->unk_8b0);
    cam = gSceneCmd;
    if (cam != NULL) {
        Persp021c930c *p = &cam->persp;
        u16 idx;
        NNS_G3dGlbLookAt(&cam->pos, &cam->up, &cam->target);
        p->fovyIdx = (u16)(((s64)p->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
        idx = (u16)(p->fovyIdx >> 1);
        p->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
        p->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
        p->dirty = 1;
        if (p->dirty == 1) {
            NNS_G3dGlbPerspectiveW(p->fovySin, p->fovyCos, p->aspect, p->n, p->f, 0x1000);
            p->dirty = 0;
        }
    }
    if (*(s32 *)((u8 *)self + 0x3c) == 2) {
        Scene_SetSubOverlay_0204b270(gSceneMgr, (s32)OVERLAY_3_ID, 0);
    }
}

}
