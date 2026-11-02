#include "ov006/Label.h"

extern "C" {

static inline void ov006_ResHandle_Close(ov006_ResHandle *res) {
    if (res->name[0] != 0 || res->arcName[0] != 0) {
        res->vfunc_0c();
    }
    res->vfunc_08();
}

void func_ov006_021dbbac(ov006_ResLoader *self) {
    switch (self->step) {
    case 0:
        if (!self->request) {
            return;
        }
        ov006_ResHandle_Close(&self->res);
        self->res.type = 2;
        if (self->name[0] != 0) {
            self->res.vfunc_24(self->arcName, self->name);
        } else {
            self->res.vfunc_1c(self->arcName);
        }
        self->request = 0;
        self->step++;
        break;
    case 1:
        if (self->res.vfunc_2c()) {
            self->step++;
        }
        break;
    case 2:
        if (!self->request) {
            self->res.vfunc_30();
        }
        self->step = 0;
        break;
    }
}

}
