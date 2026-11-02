#ifndef OV006_TASKS_H
#define OV006_TASKS_H

#include "ov006/Window.h"
#include "ov006/SlotManager.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Sys/Pad.h"
#include "Main/Res/StageCmd.h"
#include "Main/Gfx/Camera.h"
#include "ov000/Model0218fe1c.h"
#include "ov006/MsgBox.h"
#include "ov006/Caption.h"

/* Task with vtable data_ov006_021ebd40 (0x58 bytes). */
struct ov006_TaskCE : public ov006_TaskBase {
    UiList *unk44;
    Lo021cadcc *unk48;
    ov006_MsgBox *unk4C;
    ov006_HudList *unk50;
    ov006_CaptionPanel *unk54;
};

/* Task with vtable data_ov006_021ebcc0 (0x114 bytes). */
struct ov006_TaskD0 : public ov006_TaskBase {
    char names[4][0x30];
    UiList021cb4a8 *unk104;
    Lo021cadcc *unk108;
    Lo021cad50 *unk10C;
    u8 unk110;
};

/* Task with vtable data_ov006_021ebf40 (0x128 bytes). */
struct ov006_TaskD0C : public Task {
    u8 unk3C;
    u8 unk3D;
    u8 unk3E[2];
    u8 unk40;
    char names[4][0x30];
    u8 unk101;
    struct ov006_SlotPacked unk102;
    u8 unk11A[2];
    UiList021cb4a8 *unk11C;
    Lo021cadcc *unk120;
    Lo021cad50 *unk124;
};

/* A gauge (vtable data_ov006_021ec20c, 0x24 bytes, ctor Ov006Vt_021ec20c_Ctor): func_ov006_021e139c
   sets its ratio unkC = a / b. */
typedef struct ov006_Unk021e139c {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[2];
    int unk8;
    int unkC;
    int unk10;
    int x;
    int y;
    int unk1C;
    int unk20;
} ov006_Unk021e139c;

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

/* Task with vtable data_ov006_021ebec0 (0x7c bytes). */
struct ov006_TaskD1F : public ov006_TaskBase {
    int unk44;
    u8 unk48;
    u8 unk49;
    u16 unk4A;
    int unk4C;
    int unk50;
    UiList *unk54;
    struct ov006_Actor58 *unk58;
    Lo021cadcc *unk5C;
    Lo021cb0b8 *unk60;
    Lo021cad50 *unk64;
    ov006_Caption *unk68;
    ov006_Unk021e139c *gauges[4];
};

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
typedef struct ov006_Obj58 ov006_Obj58;
/* Vtable data_ov006_021ec1fc (0x30 bytes, ctor Ov006Vt_021ec1fc_Ctor). */
typedef struct ov006_Obj13C {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    u16 unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} ov006_Obj13C;

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
struct ov006_TaskD37 : public Task {
    u8 step;
    u8 unk3D;
    u8 unk3E[2];
    int unk40; // written by the unk5C window's decide callback (its owner points here)
    u8 unk44;
    u8 unk45;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u8 unk4E[2];
    UiList *unk50;
    Lo021cadcc *unk54;
    ov006_Obj58 *unk58;
    Lo021cb0b8 *unk5C;
    ov006_Model60 *unk60;
    Model0218fe1c *unk64;
    ov006_Model60 *unk68;
    Model0218fe1c *unk6C;
    ov006_Model60 *unk70;
    ov006_Anm74 *anm;
    u8 animLoop;
    u8 unk79;
    s16 animSpeed;
    Camera cam;
    ov006_Caption *unk138;
    ov006_Obj13C *unk13C;
};

#ifdef __cplusplus
extern "C" {
#endif

extern void *data_ov006_021ebc70;
extern char data_ov006_021ebbd1[];
extern char data_ov006_021ebbde[];

ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);

extern void *data_ov000_021ccd44;
extern void *data_ov000_021ccd40;
extern s32 data_ov000_021ccd38;
extern s32 data_02097d78[];

void *func_ov000_0218084c(void *a, int b, int c);
void func_0203cc58(int a, int b, int c);
void func_0203cb78(int a, int b, int c);

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
        data_ov000_021ccd38 = *(s32 *)((u8 *)data_ov000_021ccd40 + 0x14);
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = p;
}

static inline ov006_MsgBox *ov006_MsgBox_New(void) {
    ov006_MsgBox *p = (ov006_MsgBox *)Heap_Alloc(sizeof(ov006_MsgBox));
    if (p != NULL) {
        p->vtbl = &data_ov006_021ebc70;
        func_ov000_02163224(p);
    }
    return p;
}

#endif
