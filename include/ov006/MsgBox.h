#ifndef OV006_MSGBOX_H
#define OV006_MSGBOX_H

#include "types.h"

/* A message box object built by MsgBox_Init (vtable ov006_MsgBox_vtbl, 0x2c bytes);
   MsgBox_Open opens a message of a script file in it, MsgBox_Update tests it and
   MsgBox_Release is its dtor. */
typedef struct ov006_MsgBox {
    void *vtbl;
    u8 unk4[0x28];
} ov006_MsgBox;

#ifdef __cplusplus
extern "C" {
#endif

void MsgBox_Init(ov006_MsgBox *self);
void MsgBox_Release(ov006_MsgBox *self);
void MsgBox_Open(ov006_MsgBox *self, int a, const char *b, const char *c, u8 d);
BOOL MsgBox_Update(ov006_MsgBox *self);
void MsgBox_Render(ov006_MsgBox *self);

#ifdef __cplusplus
}
#endif

#endif
