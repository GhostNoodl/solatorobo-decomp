#ifndef OV002_STAGEOBJ_H
#define OV002_STAGEOBJ_H

#include "types.h"
#include "ov000/VObj.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/Gfx3D.h"

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

// Message reader (0x28, vtable data_ov002_021f0ce8; Ov002Vt_021f0ce8_Ctor, reset func_ov002_021ebfd0):
// func_ov002_021ec010 points it at a loaded message file, func_ov002_021ec0cc steps to the next record.
// Each record is a 0xe-byte header (copied to unk_10) followed by a name and a text string.
typedef struct Ov002MsgRes {
    u8 *data;
} Ov002MsgRes;

struct Ov002Msg021f0ce8 : public VObj {
    const Ov002MsgRes *res;
    s16 index;  // records read
    s16 count;
    u8 *body;   // current record
    s16 unk_10;
    s16 unk_12; // start time (<< 12)
    s16 unk_14;
    s16 unk_16;
    s16 unk_18; // offset of the name
    s16 unk_1a; // size of the strings
    u8 unk_1c;
    u8 unk_1d[3];
    char *name;
    char *text;
};
SIZE_ASSERT(Ov002Msg021f0ce8, 0x28);

// Sound command reader (0x18, vtable data_ov002_021f0cf8; Ov002Vt_021f0cf8_Ctor, reset
// func_ov002_021ec1c4): func_ov002_021ec1e0 points it at a list of 0x10-byte commands,
// func_ov002_021ec2ac steps to the next one.
struct Ov002Snd021f0cf8 : public VObj {
    void *src;
    s16 index;
    u8 unk_0a[2];
    u32 mask;   // bit (command[2] >> 8) of each type 6 or 8 command
    s16 count;
    u8 unk_12[2];
    s16 *cur;   // current command (its first s16 is the start time)
};
SIZE_ASSERT(Ov002Snd021f0cf8, 0x18);

// The subclasses, named by vtable and sized by the allocation in their factory (func_ov002_021e91c8 ..
// func_ov002_021e9bd8). Fields are named by offset unless the code shows what they hold.

// File names of a stage object's resource, pointing into the stage file (or ov015's tables).
typedef struct Ov002ResName {
    char *arc;  // archive, NULL: a loose file
    char *name; // file name
    char *item; // name of the model or animation inside it, NULL: name
} Ov002ResName;

// Texture link record (0x1c bytes) appended by func_ov002_021e50a8 / func_ov002_021e50d8: a texture
// file bound to the model of the object whose unk_4c matches id (func_ov002_021e534c loads it).
typedef struct Ov002ObjLink {
    s32 id;
    char *arc;  // archive, NULL: a loose file
    char *name; // file name
    u32 task;   // texture upload (func_0203ebf8 / func_0203e63c)
    u32 *res;   // loaded file
    u8 loaded;
    u8 alt;     // not found in the archive: loaded as its own file into res2
    u32 *res2;
} Ov002ObjLink;

// Vtable data_ov002_021f07d4, 0x1f4 bytes (func_ov002_021e91c8, ctor func_ov002_021e5140).
struct Ov002Obj021f07d4 : public Ov002Obj {
    s32 unk_4c; // id matched against the link records
    Ov002ResName res; // its model
    u32 *unk_5c;  // loaded file (*unk_5c: its NNSG3dResFileHeader)
    NNSG3dResMdl *unk_60;
    NNSG3dResTex *unk_64;
    NNSG3dRenderObj renderObj;
    u32 unk_bc;   // texture upload (func_0203ebf8 / func_0203e63c)
    Ov002ObjLink links[8];
    s32 linkCount;
    VecFx32 trans; // NNS_G3dGlbSetBaseTrans (func_ov002_021e5b08)
    VecFx32 scale; // NNS_G3dGlbSetBaseScale
    MtxFx33 rot;
    struct Ov002Cam021f0854 *unk_1e0; // camera (kind 7, or 8 when unk_1f0_0) for screen 1
    struct Ov002Cam021f0854 *unk_1e4; // for screen 2
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
// Kind 2 while it animates its owner's model with up to five NNSG3dAnmObjs, kind 3 when it drives
// a single joint animation (func_ov002_021e61b4).
struct Ov002Obj021f075c : public Ov002Obj {
    Ov002ResName res; // its animations
    s32 unk_58;
    s32 unk_5c;   // id of the model object (Ov002Obj021f07d4::unk_4c) it attaches to
    void **unk_60; // loaded animation sets
    NNSG3dAnmObj *unk_64;
    NNSG3dAnmObj *unk_68;
    NNSG3dAnmObj *unk_6c;
    NNSG3dAnmObj *unk_70;
    NNSG3dAnmObj *unk_74;
    s32 unk_78;
    s32 unk_7c; // animation frame (Ov002Anm_Frame)
    s32 unk_80; // last frame
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    NNSG3dJntAnmResult jnt; // the joint animation's result (func_ov002_021e63f0)
    union {
        u32 unk_e8;
        struct {
            u8 started : 1; // set by func_ov002_021e6290
            u8 done : 1;    // frame passed unk_8c
            u8 stopped : 1; // func_ov002_021e6360 on a kind 3 object
            u8 unk_e8_3 : 5;
        };
    };
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
    union {
        s16 unk_4c; // passed to func_0206e3a0 with unk_50
        struct {
            u16 unk_4c_0 : 2;
            u16 unk_4c_2 : 1; // keep edge marking
            u16 unk_4c_3 : 1; // keep the fog
            u16 unk_4c_4 : 2;
            u16 unk_4c_6 : 1;
            u16 unk_4c_7 : 9;
        };
    };
    u8 unk_4e[0x2];
    void *unk_50;
};
SIZE_ASSERT(Ov002Obj021f06e4, 0x54);

// Vtable data_ov002_021f06bc, 0xac bytes (func_ov002_021e9bd8): plays the sound commands of a file.
struct Ov002Obj021f06bc : public Ov002Obj {
    char unk_4c[0x20]; // archive
    char unk_6c[0x20]; // file name
    s32 unk_8c;
    s32 unk_90;
    Ov002Snd021f0cf8 snd;
};
SIZE_ASSERT(Ov002Obj021f06bc, 0xac);

typedef s32 (*Ov002GetChar)(char **cursor);

// Vtable data_ov002_021f07ac, 0x160 bytes (func_ov002_021e9a50, ctor func_ov002_021e6a14): shows the
// messages of a file, typing each text out into unk_c4 (func_ov002_021e6e40).
struct Ov002Obj021f07ac : public Ov002Obj {
    char unk_4c[0x20]; // archive
    char unk_6c[0x20]; // file name
    Ov002Msg021f0ce8 msg;
    s32 unk_b4;   // time until the next character
    s32 unk_b8;   // time the message starts
    s16 unk_bc;   // typing delay, 0: all at once
    u8 unk_be[2];
    char *unk_c0; // next character of msg.text
    char unk_c4[0x80];
    char *unk_144; // end of the text typed into unk_c4
    s32 unk_148;  // 0xff: no name, else its layout
    char *unk_14c; // msg.name
    s32 unk_150;
    s32 unk_154;
    s8 **unk_158; // the font (GfxMgr_GetFont)
    Ov002GetChar unk_15c; // its character reader
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
    s32 unk_b4;   // field of view in degrees (fx32, func_ov002_021e772c)
    u16 unk_b8;   // as an angle; fovySin/fovyCos are of its half
    s16 fovySin; // FX_SinCosTable_ pair
    s16 fovyCos;
    u16 unk_be;
    s32 unk_c0;
    s32 unk_c4;
    struct Ov002Obj021f075c *unk_c8; // kind 3 child (func_ov002_021e75f0)
};
SIZE_ASSERT(Ov002Cam021f0828, 0xcc);

// Texture pair node (0x50) the stage reader can collect (func_ov002_021eb298, func_ov002_021eb448,
// func_ov002_021ebcf8): two names and the kind of the record that named them.
typedef struct Ov002ResNode {
    char a[0x20];
    char b[0x20];
    s32 kind;
    u8 unk_44;
    u8 unk_45[3];
    s32 unk_48;
    struct Ov002ResNode *next;
} Ov002ResNode;

// List of Ov002ResNode; only its head is read.
typedef struct Ov002ResList {
    u32 unk_00;
    Ov002ResNode *head;
} Ov002ResList;

// Stage file reader (0x64, vtable data_ov002_021f0684; init func_ov002_021eacd0, release
// func_ov002_021eae48), embedded in the stage context. func_ov002_021ead1c points it at a loaded
// stage file and func_ov002_021eb964 finds the file's sections; func_ov002_021eaf20 builds the
// stage objects from them.
struct Ov002StageFile : public VObj {
    char *unk_04; // stage name (the context's unk_44)
    u8 *data;     // the file
    u8 unk_0c;
    u8 unk_0d[3];
    u8 *unk_10;   // camera records (func_ov002_021eb0f8)
    u8 *unk_14;   // model records (func_ov002_021eb448)
    u8 *unk_18;   // texture link records (func_ov002_021eb298)
    u8 *unk_1c;   // kind 2 animation records (func_ov002_021ebcf8)
    u8 *unk_20;   // kind 3 animation records
    u8 *unk_24;   // kind 3 animation records
    u8 *unk_28;   // kind 6 records
    u8 *unk_2c;   // kind 10 records (func_ov002_021eb7c0)
    u8 *unk_30;   // effect records (func_ov002_021eb870)
    u8 unk_34[0xc];
    Ov002ObjLink *links;
    struct Ov002Obj021f075c **unk_44; // built from unk_1c
    struct Ov002Obj021f075c **unk_48; // from unk_20
    struct Ov002Obj021f075c **unk_4c; // from unk_24
    s32 linkCount;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    Ov002ResList *unk_60;
};
SIZE_ASSERT(Ov002StageFile, 0x64);

// Stage context (0x2cc, vtable data_ov002_021f0674), data_ov002_021f0f9c, built by
// func_ov002_021e7b58 / func_ov002_021e8f04 (ctor func_ov002_021e7cb4, dtor func_ov002_021e7dac).
// It loads the stage file, runs the stage objects in its list and fades the screens in and out
// (func_ov002_021e7ea8).
struct Ov002Stage : public VObj {
    s32 state;    // func_ov002_021e7ea8: 0..7
    s32 step;     // the state's sub-step (func_ov002_021e828c, func_ov002_021e86a0)
    s32 unk_0c;   // screen being drawn: 1, or 2 (compared with Ov002Obj::unk_08)
    u8 unk_10;    // objects still running
    u8 unk_11[3];
    s32 unk_14;   // time from which the unk_18 buttons skip
    u16 unk_18;   // buttons that skip
    u8 unk_1a;
    u8 unk_1b;
    s32 unk_1c;   // stage index (func_ov002_021e9e40)
    char *unk_20; // archive name, NULL: a loose file
    char unk_24[0x20]; // archive path
    char *unk_44; // stage name
    char unk_48[0x20]; // stage file name
    u8 **unk_68;  // loaded stage file
    Ov002StageFile file;
    s32 unk_d0;   // stage time
    s32 unk_d4;   // previous stage time
    s32 unk_d8;   // time step
    Ov002Obj *head; // stage objects (linked through Ov002Obj::next)
    Ov002Obj *tail;
    MtxFx44 unk_e4; // orthographic projection (func_ov002_021e8cc4)
    struct Model *unk_124;
    u32 unk_128;  // screens drawn (bit mask of unk_0c)
    s32 unk_12c;
    s32 unk_130;  // fade-in: 0 keep, 1 from white, 2 from black
    s32 unk_134;  // fade-out: 0 by unk_138, 1 to white, 2 to black
    u16 unk_138;
    u8 unk_13a[2];
    s32 unk_13c;  // brightness from (fx32)
    s32 unk_140;  // brightness to
    s32 unk_144;  // fade timer
    u8 unk_148;   // unk_14c holds the saved 3D state
    u8 unk_149[3];
    Gfx3DState unk_14c;
};
SIZE_ASSERT(Ov002Stage, 0x2cc);

#ifdef __cplusplus
extern "C" {
#endif

extern Ov002Stage *data_ov002_021f0f9c;

void func_ov002_021e4cd8(Ov002Obj *self);
void func_ov002_021e4d4c(Ov002Obj *self);
void func_ov002_021e4dac(Ov002Obj *self, Ov002Obj *item);
Ov002Obj *func_ov002_021e4ee4(Ov002Obj *self, s32 kind, s32 min);
void func_ov002_021e50d8(Ov002Obj021f07d4 *self, char *arc, char *name);
void func_ov002_021e61b4(Ov002Obj021f075c *self);
void func_ov002_021e6360(Ov002Obj021f075c *self);
void func_ov002_021e7b58(void);
void func_ov002_021e7c1c(void);
BOOL func_ov002_021e7ea8(Ov002Stage *self);
void func_ov002_021e8b3c(Ov002Stage *self);
Ov002Obj *func_ov002_021e91c8(s32 start, s32 end, s32 screen, bool b, u8 a);
Ov002Obj *func_ov002_021e92b0(s32 start, s32 end, s32 screen, s32 d, s32 e);
Ov002Obj *func_ov002_021e9b28(s32 end);
void func_ov002_021e9e40(s32 idx);

#ifdef __cplusplus
}
#endif

#endif
