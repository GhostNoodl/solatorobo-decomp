#include "ov006/Tasks.h"

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

extern "C" {

extern void *data_ov006_021ebdc0;
extern char data_ov006_021ebc0a[];
extern char data_ov006_021ebc1c[];
extern char data_ov006_021ebc2d[];
extern char data_ov006_021ebc37[];
extern char data_ov006_021ebc3e[];
extern char data_ov006_021ebc4a[];

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_0204b370(void *self);
void func_0204b420(void *self);
void func_ov000_0218ea20(void *self);
void func_ov000_0218fee4(void *self);
ov006_Model60 *func_ov000_0218e9c4(void *self);
void func_0203df0c(void *p);
void func_02035acc(const char *a, const char *b, int c);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
int func_ov000_0218f110(ov006_Model60 *self);

BOOL func_ov006_021d40a8(ov006_TaskD37 *self) {
    BOOL r = TRUE;
    if (self->unk60->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk60)) ? TRUE : FALSE;
    }
    if (self->unk68->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk68)) ? TRUE : FALSE;
    }
    if (self->unk70->unk0 >= 0) {
        r = (r & func_ov000_0218f110(self->unk70)) ? TRUE : FALSE;
    }
    return r;
}

}
