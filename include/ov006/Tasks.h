#ifndef OV006_TASKS_H
#define OV006_TASKS_H

#include "ov006/Window.h"
#include "ov006/SlotManager.h"

/* Holds a message box object built by func_ov000_02163224 (vtable data_ov006_021ebc70, 0x2c bytes). */
typedef struct ov006_MsgBox {
    void *vtbl;
    u8 unk4[0x28];
} ov006_MsgBox;

/* Task with vtable data_ov006_021ebd40 (0x58 bytes). */
typedef struct ov006_TaskCE {
    ov006_TaskBase base;
    ov006_Window *unk44;
    ov006_Window *unk48;
    ov006_MsgBox *unk4C;
    ov006_Window *unk50;
    Object *unk54;
} ov006_TaskCE;

/* Task with vtable data_ov006_021ebcc0 (0x114 bytes). */
typedef struct ov006_TaskD0 {
    ov006_TaskBase base;
    char names[4][0x30];
    ov006_Window *unk104;
    ov006_Window *unk108;
    ov006_Window *unk10C;
    u8 unk110;
} ov006_TaskD0;

/* Task with vtable data_ov006_021ebf40 (0x128 bytes). */
typedef struct ov006_TaskD0C {
    void *vtbl;
    u32 flags;
    int unk8;
    int unkC;
    u8 unk10[0x2c];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E[2];
    u8 unk40;
    char names[4][0x30];
    u8 unk101;
    struct ov006_SlotPacked unk102;
    u8 unk11A[2];
    ov006_Window *unk11C;
    ov006_Window *unk120;
    ov006_Window *unk124;
} ov006_TaskD0C;

typedef struct ov006_Unk021e139c ov006_Unk021e139c;

typedef struct ov006_Vec32 {
    s32 x, y, z;
} ov006_Vec32;

typedef struct ov006_Vec16 {
    s16 x, y, z;
} ov006_Vec16;

typedef struct ov006_Actor58 {
    u8 unk0[0x6b8];
    int unk6B8;
    u8 unk6BC[0x10];
    ov006_Vec32 pos;
    u8 unk6D8[0xc];
    ov006_Vec16 rot;
} ov006_Actor58;

typedef struct ov006_Unk68 {
    void *vtbl;
    u8 unk4;
} ov006_Unk68;

/* Task with vtable data_ov006_021ebec0 (0x7c bytes). */
typedef struct ov006_TaskD1F {
    ov006_TaskBase base;
    int unk44;
    u8 unk48;
    u8 unk49;
    u16 unk4A;
    int unk4C;
    int unk50;
    ov006_Window *unk54;
    struct ov006_Actor58 *unk58;
    ov006_Window *unk5C;
    ov006_Window *unk60;
    ov006_Window *unk64;
    struct ov006_Unk68 *unk68;
    ov006_Unk021e139c *gauges[4];
} ov006_TaskD1F;

typedef struct ov006_TaskHead {
    void *vtbl;
    union {
        u32 flags;
        ov006_TaskFlags f;
    };
    int unk8;
    int unkC;
    u8 unk10[0x10];
    int unk20;
    u8 unk24[0x18];
} ov006_TaskHead;

typedef struct ov006_Model60 {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4[0xc];
    char unk10[0x20];
    char unk30[0x18];
    void **unk48;
    char unk4C[0x20];
    char unk6C[0x20];
} ov006_Model60;
typedef struct ov006_Model64 ov006_Model64;
typedef struct ov006_Obj58 ov006_Obj58;
typedef struct ov006_Obj13C ov006_Obj13C;

typedef struct ov006_Anm74 {
    int frame;
    int speed;
    struct {
        u8 unk0[4];
        u16 numFrame;
    } *res;
    void *func;
    int unk10;
    int unk14;
    u8 unk18;
    u8 unk19;
} ov006_Anm74;

/* Task with vtable data_ov006_021ebdc0 (0x140 bytes). */
typedef struct ov006_TaskD37 {
    ov006_TaskHead head;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E[6];
    u8 unk44;
    u8 unk45;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u8 unk4E[2];
    ov006_Window *unk50;
    ov006_Window *unk54;
    ov006_Obj58 *unk58;
    ov006_Window *unk5C;
    ov006_Model60 *unk60;
    ov006_Model64 *unk64;
    ov006_Model60 *unk68;
    ov006_Model64 *unk6C;
    ov006_Model60 *unk70;
    ov006_Anm74 *unk74;
    u8 unk78;
    u8 unk79;
    s16 unk7A;
    u8 unk7C[0xbc];
    ov006_Unk68 *unk138;
    ov006_Obj13C *unk13C;
} ov006_TaskD37;

typedef struct ov006_TaskOwner {
    u8 unk0[8];
    void *task;
} ov006_TaskOwner;

#ifdef __cplusplus
extern "C" {
#endif

extern void *data_ov006_021ebc70;
extern void *data_02097e4c;
extern char data_ov006_021ebbd1[];
extern char data_ov006_021ebbde[];

void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void func_ov000_02163224(void *self);
void func_ov000_02163254(void *self);
void func_ov000_021632f0(void *self, int a, const char *b, const char *c, u8 d);
BOOL func_ov000_021633ac(void *self);
void func_ov000_02163594(void *self);

typedef struct ov006_Pad {
    u8 unk0[0x10];
    u16 unk10;
    u16 unk12;
} ov006_Pad;
extern ov006_Pad *data_02097dc8;

typedef struct ov006_Unk0214a424 {
    u8 unk0[0x620];
    u32 unk620_0 : 1;
    u32 unk620_1 : 31;
} ov006_Unk0214a424;
extern ov006_Unk0214a424 *data_0214a424;

extern void *data_ov000_021ccd44;
extern void *data_ov000_021ccd40;
extern void *data_ov000_021ccd38;
extern s32 data_02097d78[];

void func_ov000_0218084c(void *a, int b, int c);
void func_0203cc58(int a, int b, int c);
void func_0203cb78(int a, int b, int c);
int func_ov000_02154b58(void *a, u16 b);

#ifdef __cplusplus
}
#endif

static inline void ov006_TaskCE_ShowMenus(ov006_TaskCE *self) {
    self->unk44->flags |= 4;
    self->unk44->flags |= 2;
    self->unk48->flags |= 2;
}

static inline void ov006_TaskCE_HideMenus(ov006_TaskCE *self) {
    self->unk44->flags &= ~4;
    self->unk44->flags &= ~2;
    self->unk48->flags &= ~2;
}

static inline BOOL ov006_IsMode4b(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[1] == 4;
    }
    return r;
}

static inline BOOL ov006_IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

static inline void ov006_SetCurrent021ccd40(void *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = *(void **)((u8 *)data_ov000_021ccd40 + 0x14);
    } else {
        data_ov000_021ccd38 = NULL;
    }
    data_ov000_021ccd40 = p;
}

static inline ov006_MsgBox *ov006_MsgBox_New(void) {
    ov006_MsgBox *p = (ov006_MsgBox *)func_0203dd9c(sizeof(ov006_MsgBox));
    if (p != NULL) {
        p->vtbl = &data_ov006_021ebc70;
        func_ov000_02163224(p);
    }
    return p;
}

#endif
