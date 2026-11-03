#include "ov000/VObj.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"
#include "ov000/SceneRes.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 ResHandle_vtbl[];
extern u8 StageRes_vtbl[];
extern char data_ov000_021ca8f7[];
extern char data_ov000_021ca8ff[];
extern char data_ov000_021ca917[];
extern void *data_ov000_021ca8d8;
void *Heap_Alloc(u32 size);
void func_020708fc(s32 a, void *out);
void func_02070b98(s32 a, void *out, s32 b, s32 c);
void ResMgr_LoadArchive(void *a, void *b, s32 c, s32 d);
void StageRes_Init(void *res);
void StageRes_Open(void *res, char *name, char *path);

void Lo021caa44_Load(Lo021caa44 *self) {
    u8 b[0x10];
    u8 a[0x10];
    char name[0x20];
    VObj *o;

    func_020708fc(0x1000, a);
    func_02070b98(0x1000, b, 1, 2);
    ResMgr_LoadArchive(a, b, 2, 0);
    gSceneResSet.unk_00 = 1;
    o = (VObj *)Heap_Alloc(0xc4);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, ResHandle_vtbl);
        o->vfunc_08();
        VOBJ_SET_VTABLE(o, StageRes_vtbl);
        StageRes_Init(o);
    }
    gSceneResSet.unk_08 = (SceneRes *)o;
    STD_CopyString(name, data_ov000_021ca8f7);
    STD_ConcatenateString(name, data_ov000_021ca8ff);
    StageRes_Open(gSceneResSet.unk_08, name, data_ov000_021ca917);
    o = (VObj *)Heap_Alloc(0x4c);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, ResHandle_vtbl);
        o->vfunc_08();
    }
    self->unk_3c = o;
    LFLD(s32, o, 0x44) = 7;
    self->unk_3c->vfunc_1c(data_ov000_021ca8d8);
}
}
