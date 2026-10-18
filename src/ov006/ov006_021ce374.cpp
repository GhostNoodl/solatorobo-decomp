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

void func_ov006_021ce374(void) {
}

BOOL func_ov006_021ce378(void) {
    return TRUE;
}

void func_ov006_021ce380(ov006_Emblem *self) {
    self->unk4_1 = 0;
    if (VCALL(self, 28)) {
        return;
    }
    func_ov006_021ce3f0(self);
    self->unk44 = 1;
    self->unk2C = 0;
    func_ov000_02173648(self);
}

static inline BOOL ov006_Emblem_Bit4(ov006_Emblem *self) {
    return self->unk4_4 != 0;
}

BOOL func_ov006_021ce3cc(ov006_Emblem *self) {
    return ov006_Emblem_Bit4(self) ? TRUE : FALSE;
}

}
