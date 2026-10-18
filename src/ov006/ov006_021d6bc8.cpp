#include "ov006/ov006.h"

typedef struct ov006_Game021d6bc8 {
    u8 unk0[0xf4];
    VObj sub;
} ov006_Game021d6bc8;

typedef struct ov006_Scene021d6bc8 {
    u8 unk0[0x1c];
    void *unk1C;
    void *unk20;
    u8 unk24[4];
    void *unk28;
    void *unk2C;
    void *unk30;
    int unk34;
    u8 unk38[0x35];
    u8 unk6D;
} ov006_Scene021d6bc8;

extern "C" {

extern ov006_Game021d6bc8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern void *data_0214a420;

u8 func_ov006_021d8790(ov006_Scene021d6bc8 *self);
void func_ov006_021db0d8(void);
void func_ov006_021de2e0(void *p);
void func_ov006_021e000c(void *p);
void func_ov006_021e1af0(void *p);
void func_ov006_021e2430(void *p);
void func_ov006_021e2878(void *p);
void func_ov000_021b5110(void *p);
void func_ov000_0218be54(void *p);
void func_ov000_0218e338(void *p);
void func_02065ac0(void *p);
int func_ov006_021d6ff0(ov006_Scene021d6bc8 *self);
void *func_ov000_0218e4cc(void *mgr, u16 kind);
void func_ov000_0218e0bc(void *p);
void func_ov006_021d8914(void);
void func_ov006_021db1b8(u16 a);

int func_ov006_021d6bc8(ov006_Scene021d6bc8 *self) {
    int r = 0;
    u8 state = 0;

    if (data_ov006_021ec860->unk1C) {
        state = func_ov006_021d8790(self);
        if (state == 4) {
            return r;
        }
        if (state == 0 && data_ov006_021ec888->unk15F == 0) {
            return 1;
        }
    }
    if (state == 0) {
        func_ov006_021db0d8();
    }
    if (self->unk34 == 0) {
        func_ov006_021de2e0(self->unk1C);
        if (self->unk20 != NULL) {
            func_ov006_021e000c(self->unk20);
        }
        func_ov006_021e1af0(self->unk28);
        func_ov006_021e2430(self->unk2C);
        func_ov006_021e2878(self->unk30);
        {
            VObj *sub = &data_ov000_021ccd54->sub;
            if (sub != NULL) {
                sub->v00();
            }
        }
        if (data_ov000_021ccd6c != NULL) {
            func_ov000_021b5110(data_ov000_021ccd6c);
        }
        if (data_ov000_021ccd64 != NULL) {
            func_ov000_0218be54(data_ov000_021ccd64);
        }
        if (data_ov000_021ccd68 != NULL) {
            func_ov000_0218e338(data_ov000_021ccd68);
        }
        func_02065ac0(data_0214a420);
    }
    r = func_ov006_021d6ff0(self);
    if (state == 0 && data_ov006_021ec888->unk8 != 9) {
        void *obj = func_ov000_0218e4cc(data_ov000_021ccd68, 0x7000);
        if (obj != NULL) {
            func_ov000_0218e0bc(obj);
        }
        func_ov006_021d8914();
        func_ov006_021db1b8(self->unk6D);
    }
    return r;
}

}
