#include "ov000/LoCommon.h"
#include "nitro/mi.h"
#include "ov000/ModelViewer.h"

extern "C" {

extern u8 data_ov000_021cabc8[];
extern u8 data_ov000_021cabd8[];
extern const char data_ov000_021cac02[];
void *ResSet_Init(void *p);
void *ResSet_ReleaseAll(void *p);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *Model0218fe1c_Init(void *p);
void *GfxCamPos_Init(void *p);

u8 *ModelViewer_Ctor(ModelViewer *self) {
    self->vtbl = data_ov000_021cabc8;
    self->res.vtbl = data_ov000_021cabd8;
    __cxa_vec_ctor(self->res.a, 2, sizeof(ActorRes), (void (*)(void *))ResSet_Init, (void (*)(void *))ResSet_ReleaseAll);
    __cxa_vec_ctor(self->res.b, 2, sizeof(ActorRes), (void (*)(void *))ResSet_Init, (void (*)(void *))ResSet_ReleaseAll);
    self->res.state = 20;
    self->res.cur = 0;
    self->res.reload = 0;
    MI_CpuFill8(self->res.mdlArc, 0, sizeof(self->res.mdlArc));
    MI_CpuFill8(self->res.mdlName, 0, sizeof(self->res.mdlName));
    MI_CpuFill8(self->res.anmArc, 0, sizeof(self->res.anmArc));
    MI_CpuFill8(self->res.anmName, 0, sizeof(self->res.anmName));
    self->res.useMdlForB = 0;
    Model0218fe1c_Init(&self->model);
    GfxCamPos_Init(&self->eye);
    MTX_Identity44_(&self->proj);
    self->projOfs.x = 0;
    self->projOfs.y = 0;
    self->projOfs.z = 0;
    self->projScale = 0x1000;
    self->state = 0;
    self->request = 0;
    self->anim = data_ov000_021cac02;
    self->frame = 0;
    self->speed = 0x1000;
    self->home.x = 0;
    self->home.y = 0;
    self->home.z = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rot[0] = 0;
    self->rot[1] = 0;
    self->rot[2] = 0;
    self->unk_6ec.x = 0;
    self->unk_6ec.y = 0;
    self->unk_6ec.z = 0;
    self->unk_6f8.x = 0;
    self->unk_6f8.y = 0;
    self->unk_6f8.z = 0;
    self->timer = 0;
    return (u8 *)self;
}

void ResSet_SetName0(void *p, s32 a, s32 b, s32 c, s32 d);
void ResSet_SetName1(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
void *Model0218fe1c_FreeAnims(void *p);

// Same slot helpers as Slot_02161cd4.cpp (the camera's sub-object at +4).
static inline void StopSlot02162294(u8 *self, u8 i) {
    if (i > 2) {
        return;
    }
    ResSet_SetName0(self + 0x78 + i * 0x138, 0, 0, 1, 0);
    ResSet_SetName1((u8 *)self + 0x78 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, self + i * 0x138, 0x78) = 0;
    ResSet_SetName1(self + 0x2e8 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, (u8 *)self + i * 0x138, 0x2e8) = 0;
}

static inline void SlotDtor02162294(u8 *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cabd8);
    StopSlot02162294(self, LFLD(u8, self, 5));
    StopSlot02162294(self, (LFLD(u8, self, 5) & 1) ^ 1);
    __cxa_vec_cleanup(self + 0x2e8, 2, 0x138, (void (*)(void *))ResSet_ReleaseAll);
    __cxa_vec_cleanup(self + 0x78, 2, 0x138, (void (*)(void *))ResSet_ReleaseAll);
}

static inline void CamDtor02162294(u8 *self) {
    u8 *sub;
    VOBJ_SET_VTABLE(self, data_ov000_021cabc8);
    StopSlot02162294(self + 4, LFLD(u8, self + 4, 5));
    StopSlot02162294(self + 4, (LFLD(u8, self + 4, 5) & 1) ^ 1);
    Model0218fe1c_FreeAnims(self + 0x55c);
    sub = self + 4;
    SlotDtor02162294(sub);
}

u8 *ModelViewer_Dtor(ModelViewer *self) {
    CamDtor02162294((u8 *)self);
    return (u8 *)self;
}

u8 *ModelViewer_DtorDelete(ModelViewer *self) {
    CamDtor02162294((u8 *)self);
    Heap_Free(self);
    return (u8 *)self;
}

}
