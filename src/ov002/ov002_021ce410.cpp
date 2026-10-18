#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021ce410(Task50 *self) {
    if (VC(self, 0x54)() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
    return TRUE;
}

void func_ov002_021ce464(Task50 *self) {
    if (self->unk_08 != 0) {
        return;
    }
    if (!self->flag2) {
        return;
    }
    FIELD(func_ov000_0218084c(data_ov000_021ccd44, 0x10, 0), 0x2c, s32) = 0;
    data_ov000_021ccd34 = 1;
    data_ov000_021ccd44->flag0 = 0;
}

void func_ov002_021ce4c8(Task50 *self) {
    void *model = self->unk_3c;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (model == NULL || (res = FIELD(model, 0x28, void *)) == NULL) {
        return;
    }
    anim = NULL;
    if (FIELD(model, 0x80, s32) > 0) {
        anim = FIELD(model, 0x78, void *);
    }
    if (anim != NULL && (t = FIELD(anim, 0x4, void *)) != NULL) {
        arg = FIELD(t, 0x30, void *);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), 0);
        arg = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(e, 0xc, void *));
    }
    func_02042628(model, arg, anim, 0);
}

Task50 *func_ov002_021ce53c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x4c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef4b0;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
    }
    p->v0x8(0x12, 0);
    return p;
}

void func_ov002_021ce5a8(void *self, int arg) {
    func_ov000_0218084c(data_ov000_021ccd44, arg, 0);
}

void func_ov002_021ce5c4(Task50 *self) {
    self->flag1 = 0;
    if (VC(self, 0x28)() != 0) {
        return;
    }
    func_ov002_021ce7b8(self);
    if (func_ov002_isMode4()) {
        func_0203cb78(self->unk_20, 0, -1);
    }
    VC(self, 0x3c)();
    func_ov000_02173648(self);
}

void func_ov002_021ce650(Task50 *self) {
    self->flag7 = 1;
}

void func_ov002_021ce660(Task50 *self, void *arg) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    FIELD(self, 0x44, void *) = arg;
    func_ov002_021ce7b8(self);
    FIELD(self->unk_3c, 0xc, u32) |= 2;
    FIELD(self->unk_40, 0xc, u32) |= 2;
}

void func_ov002_021ce724(Task50 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
}

}
