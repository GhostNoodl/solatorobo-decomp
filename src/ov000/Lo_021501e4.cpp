#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/SceneRes.h"

extern "C" {

extern u8 ResHandle_vtbl[];
extern u8 StageRes_vtbl[];
extern char data_ov000_021ca8f7[];
extern char data_ov000_021ca8ff[];
extern u8 data_ov000_021ca917[];
extern s32 data_ov000_021ca8d8;
void StageRes_Init(void *p);
void StageRes_Open(void *p, void *buf, const void *s);

void QuestWin_Load(Lo021ca9c4 *self) {
    char buf[0x20];
    VObj *obj;
    if (self->unk_42 == 0xffff) {
        obj = (VObj *)Heap_Alloc(0xc4);
        if (obj != NULL) {
            VOBJ_SET_VTABLE(obj, ResHandle_vtbl);
            obj->vfunc_08();
            VOBJ_SET_VTABLE(obj, StageRes_vtbl);
            StageRes_Init(obj);
        }
        gSceneResSet.unk_08 = (SceneRes *)obj;
        STD_CopyString(buf, data_ov000_021ca8f7);
        STD_ConcatenateString(buf, data_ov000_021ca8ff);
        StageRes_Open(gSceneResSet.unk_08, buf, data_ov000_021ca917);
    }
    obj = (VObj *)Heap_Alloc(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, ResHandle_vtbl);
        obj->vfunc_08();
    }
    self->unk_3c = obj;
    LFLD(s32, obj, 0x44) = 7;
    self->unk_3c->vfunc_1c(data_ov000_021ca8d8);
}
}
