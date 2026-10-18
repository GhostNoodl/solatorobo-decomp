#include "ov006/Emblem.h"

extern "C" {

extern char data_ov006_021ebbc5[];
extern char data_ov006_021ec864[];
extern char *data_0208ccc0;
extern char *data_0208cca0;

void func_ov006_021ce3f0(ov006_Emblem *self);
void func_ov006_021ce048(void);
void func_ov000_02173648(ov006_Emblem *self);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c20(ov006_Model *self, int a, void *b);
BOOL func_02054f10(ov006_Model *a, int b);

void func_ov006_021ce560(void) {
}

void func_ov006_021ce564(ov006_Emblem *self) {
    int v = 0;
    if (self->unk48 < 0x1000000) {
        v = self->unk48 + 0x8000;
    }
    self->unk48 = v;
    self->unk4C = self->unk4C >= 0x1000000 ? 0 : self->unk4C + 0x8000;
}

void func_ov006_021ce590(ov006_Emblem *self) {
    if (!self->unk44) {
        return;
    }
    if (self->unk40 != NULL && func_02054f10(self->unk40, 0xffff)) {
        ov006_Model_PlayPart(self->unk40, 0);
    }
    if (self->unk3C != NULL && func_02054f10(self->unk3C, 0xffff)) {
        ov006_Model_PlayPart(self->unk3C, 0);
    }
}

BOOL func_ov006_021ce6ac(void) {
    return FALSE;
}

BOOL func_ov006_021ce6b4(void) {
    return FALSE;
}

}
