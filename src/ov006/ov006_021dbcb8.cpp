#include "ov006/Label.h"

extern "C" {

extern u8 Ov006Vt_021ec2fc_vtbl[];
extern u8 Ov006Vt_021ec25c_vtbl[];
extern u8 ResHandle_vtbl[];

static inline void ov006_ResHandle_Close(ov006_ResHandle *res) {
    if (res->name[0] != 0 || res->arcName[0] != 0) {
        res->vfunc_0c();
    }
    res->vfunc_08();
}

static inline void ov006_ResLoader_dtor(ov006_ResLoader *self) {
    *(void **)self = Ov006Vt_021ec25c_vtbl;
    ov006_ResHandle_Close(&self->res);
    *(void **)&self->res = ResHandle_vtbl;
    self->res.vfunc_0c();
}

static inline void ov006_Label_dtor(ov006_Label *self) {
    *(void **)self = Ov006Vt_021ec2fc_vtbl;
    ov006_ResHandle_Close(&self->loader.res);
    OV006_DELETE_MODEL(self->model);
    ov006_ResLoader_dtor(&self->loader);
}

ov006_Label *Ov006Vt_021ec2fc_Ctor(ov006_Label *self) {
    *(void **)self = Ov006Vt_021ec2fc_vtbl;
    *(void **)&self->loader = Ov006Vt_021ec25c_vtbl;
    *(void **)&self->loader.res = ResHandle_vtbl;
    self->loader.res.vfunc_08();
    self->loader.step = 0;
    self->loader.res.vfunc_08();
    MI_CpuFill8(self->loader.arcName, 0, 0x20);
    MI_CpuFill8(self->loader.name, 0, 0x20);
    self->loader.request = 0;
    self->timer = 0;
    self->state = 2;
    self->loader.res.vfunc_08();
    self->model = NULL;
    self->origin.x = 0;
    self->origin.y = 0;
    self->origin.z = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->dir.y = 0;
    self->dir.z = 0;
    self->alpha = 0;
    self->unkE0 = 0;
    self->unkE4 = 0;
    self->unkE8 = 0;
    self->partId = 0xffff;
    self->dir.x = 0x1000;
    self->speed = 0x20000;
    self->unkD8 = 0xc000;
    return self;
}

ov006_Label *Ov006Vt_021ec2fc_Dtor(ov006_Label *self) {
    ov006_Label_dtor(self);
    return self;
}

ov006_Label *Ov006Vt_021ec2fc_DtorDelete(ov006_Label *self) {
    ov006_Label_dtor(self);
    Heap_Free(self);
    return self;
}

}
