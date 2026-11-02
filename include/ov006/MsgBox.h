#ifndef OV006_MSGBOX_H
#define OV006_MSGBOX_H

#include "types.h"

/* A message box object built by func_ov000_02163224 (vtable data_ov006_021ebc70, 0x2c bytes);
   func_ov000_021632f0 opens a message of a script file in it, func_ov000_021633ac tests it and
   func_ov000_02163254 is its dtor. */
typedef struct ov006_MsgBox {
    void *vtbl;
    u8 unk4[0x28];
} ov006_MsgBox;

#ifdef __cplusplus
extern "C" {
#endif

void func_ov000_02163224(ov006_MsgBox *self);
void func_ov000_02163254(ov006_MsgBox *self);
void func_ov000_021632f0(ov006_MsgBox *self, int a, const char *b, const char *c, u8 d);
BOOL func_ov000_021633ac(ov006_MsgBox *self);
void func_ov000_02163594(ov006_MsgBox *self);

#ifdef __cplusplus
}
#endif

#endif
