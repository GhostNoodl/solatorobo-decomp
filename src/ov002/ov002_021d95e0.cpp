#include "ov002/ov002.h"

extern "C" {

typedef struct Bits021d95e0 {
    u16 b0 : 1;
    u16 mode : 2;
    u16 rest : 13;
} Bits021d95e0;

void *GfxCamPos_Init(void *p);
void StageFlags_ChangeShape(void *a, u16 b);

static inline void ov002_Vec_Copy(s32 *src, s32 *dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

static inline void ov002_Vec_Set(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline void ov002_Hud_Set(Ov002Hud *hud, u8 k) {
    if (hud != NULL) {
        Ov002Hud_SetRow(hud, k, 0);
    }
}

void func_ov002_021d95e0(Obj021efe6c *self) {
    void *cam;
    Task021efba4 *t;
    if (gStageFlags->shapeId == 0x9000 && gStageFlags->bits18.mode != 0) {
        StageFlags_ChangeShape(gStageFlags, 0x9001);
    }
    self->field->unk_68 = gStageFlags->shapeId;
    Obj021efe4c_SetupBoxModels(self->field);
    cam = Heap_Alloc(0x24);
    if (cam != NULL) {
        cam = GfxCamPos_Init(cam);
    }
    self->cam = (struct Ov002CamPos *)cam;
    ov002_Vec_Copy((s32 *)(data_ov002_021eef74 + 0x70), (s32 *)cam);
    ov002_Vec_Set((s32 *)((u8 *)((void *)self->cam) + 0xc), -0x2b8, 0, 0x2b8);
    ov002_Vec_Set((s32 *)((u8 *)((void *)self->cam) + 0x18), 0, 0x1000, 0);
    self->unk_90 = -1;
    self->unk_94 = 0x14;
    func_ov002_021d98ac(self);
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && self->unk_75 != 0) {
        ov002_Hud_Set(t->hud, self->unk_74);
        self->unk_75 = 0;
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && t->hud != NULL) {
        MI_CpuCopy8((u8 *)self + 0x76, t->hud->unk_2c, 0x14);
    }
}

}
