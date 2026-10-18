#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {

extern void *data_02149ef8;
extern char data_ov006_021ebc01[];
extern ov006_DataRes *data_02fe152c;

void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021cf7c8(ov006_TaskCE *self);
void func_ov006_021cf89c(ov006_TaskCE *self);
void func_ov006_021cfa80(ov006_TaskCE *self);
void func_ov006_021cfc60(ov006_TaskCE *self);
void func_ov006_021db65c(void);
void *func_0205976c(ov006_DataRes *res, u32 idx);
u32 func_0205975c(ov006_DataRes *res, u32 idx);
BOOL func_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov006_021e2f3c(Object *a);

void func_ov006_021cf360(ov006_TaskCE *self, u16 id) {
    const void *str;
    void *res = data_02149ef8;
    switch (id) {
    case 0:
        str = func_0204c0e8(res, 0x125);
        break;
    case 1:
        str = func_0204c0e8(res, 0x127);
        break;
    case 2:
        str = func_0204c0e8(res, 0x141);
        break;
    case 3:
        str = func_0204c0e8(res, 0x143);
        break;
    case 4:
        str = func_0204c0e8(res, 0x145);
        break;
    case 5:
        str = func_0204c0e8(res, 0x147);
        break;
    default:
        str = data_ov006_021ebc01;
        break;
    }
    if (self->unk48 != NULL) {
        func_ov000_0215bb14(self->unk48, str);
        VCALL(self->unk48, 70);
    }
}

}
