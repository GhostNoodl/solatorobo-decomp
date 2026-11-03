#include "ov000/VObj.h"
#include "Main/Res/ResMgr.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern u8 Ov000TaskVt_021ccc94_vtbl[];
extern u8 Task_vtbl[];
extern const char *data_0208cc94;
extern char data_ov000_021ccc68[];
extern char data_ov000_021ccc72[];
extern char data_ov000_021ccc7e[];
void ResMgr_ReleaseArchive(void *a, void *b, s32 c);
void Heap_Free(void *ptr);

static inline void Obj021ccc94_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Ov000TaskVt_021ccc94_vtbl);
    ResMgr_ReleaseByName(gResMgr, data_0208cc94, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_ov000_021ccc68, 7, 0);
    ResMgr_ReleaseArchive(data_ov000_021ccc72, data_ov000_021ccc7e, 2);
    VOBJ_SET_VTABLE(self, Task_vtbl);
    self->vfunc_5c();
}

VObj *Ov000TaskVt_021ccc94_DtorDelete(VObj *self) {
    Obj021ccc94_Dtor(self);
    Heap_Free(self);
    return self;
}

VObj *Ov000TaskVt_021ccc94_Dtor(VObj *self) {
    Obj021ccc94_Dtor(self);
    return self;
}

}
