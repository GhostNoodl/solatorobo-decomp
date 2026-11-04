#include "ov006/Tasks.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

extern "C" {

extern u8 Ov006Vt_021ec040_vtbl[];
extern char data_ov006_021ec864[];
void TaskHost_Destroy(void);
void func_ov006_021ccddc(ov006_Task *self);

static inline void ov006_Task021ec040_dtor(ov006_Task021ec040 *self) {
    *(void **)self = Ov006Vt_021ec040_vtbl;
    OV006_DELETE_OBJECT(self->unk10);
    OV006_DELETE_OBJECT(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
    OV006_DELETE_OBJECT(self->unk24);
    OV006_DELETE_OBJECT(self->unk28);
    TaskHost_Destroy();
    ResMgr_ReleaseByName(gResMgr, ArcPath_MenuBattle, 7, 0);
    ResMgr_ReleaseByName(gResMgr, data_ov006_021ec864, 7, 0);
    func_ov006_021ccddc(self);
}

ov006_Task021ec040 *Ov006Vt_021ec040_Dtor(ov006_Task021ec040 *self) {
    ov006_Task021ec040_dtor(self);
    return self;
}

ov006_Task021ec040 *Ov006Vt_021ec040_DtorDelete(ov006_Task021ec040 *self) {
    ov006_Task021ec040_dtor(self);
    Heap_Free(self);
    return self;
}

}
