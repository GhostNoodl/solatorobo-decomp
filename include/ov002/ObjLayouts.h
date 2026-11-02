#ifndef OV002_OBJLAYOUTS_H
#define OV002_OBJLAYOUTS_H

// Layouts of ov002 objects with their own vtables (named by vtable, sized by their allocation).
// Slot 0x08 starts the object, 0x0c updates it, 0x10 draws it. Fields are named by offset; only
// fields that some method reads or writes are declared, window members are typed by the vtable
// their constructor stores (ov000/UiObj.h, ov000/ObjLayouts.h).

#include "types.h"
#include "ov000/VObj.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"

#ifdef __cplusplus

// Vtable data_ov002_021efeb8, the base of 021efe9c and 021efed4 (slot 0x08 func_ov002_021d7c04
// fills 0x48..0x5c from the id at 0x48).
struct Obj021efeb8 : public VObj {
    u8 unk_04[0x4];
    s32 unk_08;
    u8 unk_0c[0x4];
    s16 unk_10;
    u16 unk_12;
    s16 unk_14;
    u8 unk_16[0x26];
    s32 unk_3c;
    u8 unk_40[0x4];
    s32 unk_44;
    u16 unk_48;
    u8 unk_4a;
    u8 unk_4b;
    u8 unk_4c[0x8];
    s32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x8];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[0x4];
    void *unk_70;
    void *unk_74;
    void *unk_78;
    void *unk_7c;
    void *unk_80;
    void *unk_84;
    void *unk_88;
    void *unk_8c;
    void *unk_90;
};

// Vtable data_ov002_021efe9c, 0xd4 bytes.
struct Obj021efe9c : public Obj021efeb8 {
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    u8 unk_b0[0x18];
    s32 unk_c8;
    u8 unk_cc;
    u8 unk_cd;
    u8 unk_ce[0x2];
    s32 unk_d0;
};
SIZE_ASSERT(Obj021efe9c, 0xd4);

// Vtable data_ov002_021efed4, 0xb4 bytes.
struct Obj021efed4 : public Obj021efeb8 {
    u8 unk_94;
    u8 unk_95[0x3];
    s32 unk_98;
    u8 unk_9c;
    u8 unk_9d[0x3];
    s32 unk_a0;
    s32 unk_a4;
    u16 unk_a8;
    u8 unk_aa[0x2];
    s32 unk_ac;
    void *unk_b0;
};
SIZE_ASSERT(Obj021efed4, 0xb4);

// Vtable data_ov002_021efef0, 0x138 bytes.
struct Obj021efef0 : public VObj {
    void *unk_04;
    LoBase021ccb54_021ccbe0 *unk_08; // vtable data_ov002_021f0044
    VObj *unk_0c;
    VObj *unk_10;
    VObj *unk_14;
    u16 unk_18;
    u8 unk_1a[0x2];
    s32 unk_1c;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    u8 unk_38[0x100];
};
SIZE_ASSERT(Obj021efef0, 0x138);

// Vtable data_ov002_021eff10, 0x134 bytes.
struct Obj021eff10 : public VObj {
    void *unk_04;
    void *unk_08; // vtable data_ov002_021efe5c object
    LoBase021cafc0_021cb0b8 *unk_0c; // vtable data_ov000_021cb0b8
    void *unk_10;
    VObj *unk_14;
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20;
    u8 unk_21[0x3];
    s32 unk_24;
    s32 unk_28;
    void *unk_2c;
    void *unk_30;
    u8 unk_34[0x100];
};
SIZE_ASSERT(Obj021eff10, 0x134);

// Vtable data_ov002_021eff30, 0x30 bytes.
struct Obj021eff30 : public VObj {
    void *unk_04;
    s32 unk_08;
    void *unk_0c; // vtable data_ov002_021efe5c object
    VObj *unk_10;
    VObj *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c;
    u8 unk_2d[0x3];
};
SIZE_ASSERT(Obj021eff30, 0x30);

// Vtable data_ov002_021eff50, 0x38 bytes.
struct Obj021eff50 : public VObj {
    void *unk_04;
    s32 unk_08;
    s32 unk_0c;
    VObj *unk_10;
    s32 unk_14;
    VObj *unk_18;
    s32 unk_1c;
    Lo021cadcc *unk_20;
    Lo021cae48 *unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x4];
    s32 unk_34;
};
SIZE_ASSERT(Obj021eff50, 0x38);

// Vtable data_ov002_021eff74, 0x24 bytes.
struct Obj021eff74 : public VObj {
    u8 *unk_04;
    s32 unk_08;
    UiList *unk_0c;
    Lo021cadcc *unk_10;
    s32 unk_14;
    s32 unk_18;
    u32 unk_1c;
    u8 unk_20;
    u8 unk_21[0x3];
};
SIZE_ASSERT(Obj021eff74, 0x24);

#endif

#endif
