#ifndef OV002_STAGEOBJ_H
#define OV002_STAGEOBJ_H

#include "types.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"

// Base of the ov002 stage objects (0x4c; ctor func_ov002_021e4cd8, dtor func_ov002_021e4d4c).
// The ctor appends the object to the list in data_ov002_021f0f9c (head at 0xdc, tail at 0xe0,
// linked through next); an object can own up to eight others (children, each pointing back
// through owner). Vtable data_ov002_021f0734: slot 0x08 func_ov002_021e8b28 (loaded: unk_0c >= 3),
// 0x0c..0x18 the load steps func_ov002_021e4dd4 runs while unk_0c goes 0..3.
struct Ov002Obj : public VObj {
    s32 unk_04; // kind, -1 until set
    s32 unk_08;
    s32 unk_0c; // 3 and above: loaded (func_ov015_0220e55c)
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    struct Ov002Obj *next;
    struct Ov002Obj *children[8];
    struct Ov002Obj *owner;
};
SIZE_ASSERT(Ov002Obj, 0x4c);

// The subclasses, named by vtable and sized by the allocation in their factory (func_ov002_021e91c8 ..
// func_ov002_021e9bd8). Fields are named by offset unless the code shows what they hold.

// Link record (0x1c bytes) appended by func_ov002_021e50a8 / func_ov002_021e50d8.
typedef struct Ov002ObjLink {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Ov002ObjLink;

// Vtable data_ov002_021f07d4, 0x1f4 bytes (func_ov002_021e91c8, ctor func_ov002_021e5140).
struct Ov002Obj021f07d4 : public Ov002Obj {
    s32 unk_4c; // id matched against the link records
    void *unk_50;
    void *unk_54;
    void *unk_58;
    void *unk_5c;
    void *unk_60;
    void *unk_64;
    u8 unk_68[0x54];
    u32 unk_bc;
    Ov002ObjLink links[8];
    s32 linkCount;
    VecFx32 unk_1a4;
    VecFx32 unk_1b0;
    u8 unk_1bc[0x24];
    VObj *unk_1e0;
    VObj *unk_1e4;
    struct Ov002Obj021f075c *unk_1e8; // kind 2 child picked by func_ov002_021e5a10
    struct Ov002Obj021f075c *unk_1ec; // kind 3 child
    union {
        u8 unk_1f0;
        struct {
            u8 unk_1f0_0 : 1;
            u8 unk_1f0_1 : 1;
            u8 unk_1f0_2 : 6;
        };
    };
    u8 unk_1f1[0x3];
};
SIZE_ASSERT(Ov002Obj021f07d4, 0x1f4);

// Vtable data_ov002_021f075c, 0xec bytes (func_ov002_021e92b0, ctor func_ov002_021e5d0c).
struct Ov002Obj021f075c : public Ov002Obj {
    void *unk_4c;
    void *unk_50;
    u8 unk_54[0xc];
    void *unk_60;
    void *unk_64;
    void *unk_68;
    void *unk_6c;
    void *unk_70;
    void *unk_74;
    s32 unk_78;
    s32 unk_7c; // animation frame (Ov002Anm_Frame)
    u8 unk_80[0x4];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u32 unk_90;
    VecFx32 scale;
    u8 unk_a0[0x18];
    MtxFx33 rot;
    VecFx32 trans;
    u8 unk_e8;
    u8 unk_e9[0x3];
};
SIZE_ASSERT(Ov002Obj021f075c, 0xec);

// Vtable data_ov002_021f070c, 0x70 bytes (func_ov002_021e9380).
struct Ov002Obj021f070c : public Ov002Obj {
    s32 unk_4c;
    u8 unk_50[0x10];
    struct Ov002Obj021f075c *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
};
SIZE_ASSERT(Ov002Obj021f070c, 0x70);

// Vtable data_ov002_021f0784, 0x60 bytes (func_ov002_021e9478).
struct Ov002Obj021f0784 : public Ov002Obj {
    s32 unk_4c; // mode 0..2
    u16 unk_50;
    u8 unk_52[0x2];
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
};
SIZE_ASSERT(Ov002Obj021f0784, 0x60);

// Vtable data_ov002_021f06e4, 0x54 bytes (func_ov002_021e9974).
struct Ov002Obj021f06e4 : public Ov002Obj {
    s16 unk_4c;
    u8 unk_4e[0x2];
    void *unk_50;
};
SIZE_ASSERT(Ov002Obj021f06e4, 0x54);

// Vtable data_ov002_021f06bc, 0xac bytes (func_ov002_021e9bd8); 0x94 is a data_ov002_021f0cf8 object.
struct Ov002Obj021f06bc : public Ov002Obj {
    char unk_4c[0x20];
    char unk_6c[0x20];
    s32 unk_8c;
    s32 unk_90;
    u8 unk_94[0x14];
    s16 *unk_a8;
};
SIZE_ASSERT(Ov002Obj021f06bc, 0xac);

// Vtable data_ov002_021f07ac, 0x160 bytes (func_ov002_021e9a50, ctor func_ov002_021e6a14); 0x8c is a
// data_ov002_021f0ce8 object.
struct Ov002Obj021f07ac : public Ov002Obj {
    char unk_4c[0x20];
    char unk_6c[0x20];
    u8 unk_8c[0x38];
    char unk_c4[0x80];
    u8 *unk_144;
    s32 unk_148;
    u8 unk_14c[0x4];
    s32 unk_150;
    s32 unk_154;
    u8 unk_158[0x8];
};
SIZE_ASSERT(Ov002Obj021f07ac, 0x160);

// Camera objects: vtable data_ov002_021f0854 (0xb4 bytes) with the eye/at/up block of a camera
// (GfxCamPos_Init) and a projection matrix (MTX_Identity44_, MTX_OrthoW).
struct Ov002Cam021f0854 : public Ov002Obj {
    s32 unk_4c;
    VecFx32 eye;
    VecFx32 at;
    VecFx32 up;
    MtxFx44 proj;
};
SIZE_ASSERT(Ov002Cam021f0854, 0xb4);

// Vtable data_ov002_021f07fc, 0xb8 bytes (func_ov002_021e97e8): orthographic.
struct Ov002Cam021f07fc : public Ov002Cam021f0854 {
    struct Ov002Obj021f075c *unk_b4; // kind 3 child (func_ov002_021e7900)
};
SIZE_ASSERT(Ov002Cam021f07fc, 0xb8);

// Vtable data_ov002_021f0828, 0xcc bytes (func_ov002_021e95c4): perspective.
struct Ov002Cam021f0828 : public Ov002Cam021f0854 {
    s32 unk_b4;
    u16 unk_b8;
    s16 fovySin; // FX_SinCosTable_ pair
    s16 fovyCos;
    u16 unk_be;
    s32 unk_c0;
    s32 unk_c4;
    struct Ov002Obj021f075c *unk_c8; // kind 3 child (func_ov002_021e75f0)
};
SIZE_ASSERT(Ov002Cam021f0828, 0xcc);

#endif
