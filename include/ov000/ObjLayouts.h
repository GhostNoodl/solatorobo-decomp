#ifndef OV000_OBJLAYOUTS_H
#define OV000_OBJLAYOUTS_H

// Layouts of ov000 objects whose methods are spread over several files (round svA).
// Field names are offsets; only fields that some method reads or writes are declared.

#include "types.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "ov000/ActorBase.h"
#include "Main/Sys/FieldId.h"
#include "ov000/UiObj.h"
#include "ov000/Task.h"

struct Model;
struct TextWin;
struct Lo021cb5a8;
struct Lo021caac8;
struct Lo021cad50;
struct Menu021ca94c;

// The ov000 actor with resources (ctor ActorEx_Ctor, vtable data_ov000_021cc480, 0xd0
// bytes); the ov003/ov009/ov012-ov014 actor classes in that vtable family derive from it.
// Spawn parameters of an ActorEx (ActorEx::param). The bit fields at 0x02 are the union of
// the splits the methods use.
typedef struct ActorExParam {
    u8 kind;
    u8 unk_01;
    u16 type : 3;
    u16 unk_02_3 : 1;
    u16 unk_02_4 : 3;
    u16 unk_02_7 : 1;
    u16 unk_02_8 : 1;
    u16 unk_02_9_f : 7;
} ActorExParam;

struct ActorEx : public Actor {
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    ActorExParam *param;
    ResSet *res[2];
    u32 unk_bc; // id of the effect that follows the actor (EffectObj::id; killed by the dtor)
    union {
        struct {
            s32 unk_c0;
            s32 unk_c4;
            s32 unk_c8;
        };
        VecFx32 fxOffset; // where unk_bc's effect sits, from pos
    };
    union {
        u16 unk_cc;
        struct {
            u16 unk_cc_0 : 1;
            u16 unk_cc_1 : 1;
            u16 unk_cc_2 : 1;
            u16 unk_cc_3 : 1;
            u16 unk_cc_4 : 1;
            u16 unk_cc_5 : 1;
            u16 unk_cc_6 : 1;
            u16 unk_cc_7 : 1;
            u16 unk_cc_8 : 1;
            u16 unk_cc_9_f : 7;
        };
    };
    union {
        u16 unk_ce;
        struct { // bytes as some ov010/ov011/ov013 classes use them
            u8 unk_ce_0 : 1;
            u8 unk_ce_1 : 1;
            u8 unk_ce_2 : 1;
            u8 unk_ce_3 : 1;
            u8 unk_ce_4 : 4;
            s8 unk_cf;
        };
    };
};
SIZE_ASSERT(ActorEx, 0xd0);

// The robot actor (ctor Robo021ca458_Ctor, vtable data_ov000_021cc774, 0xbb0 bytes; its state
// handlers are the pointer-to-member table data_ov000_021ca458). Methods in Robo_*.cpp and others.
// The bit fields at 0xae4 and 0xb22..0xb2c are the union of the members the methods use.
struct Robo021ca458 : public Actor {
    // Built in place by Robo021ca458_Ctor: three models with their resources and two hit spheres.
    Model0218fe1c mdl0; // 0xac
    ActorRes res0; // 0x194
    ActorSub48 hit0; // 0x2cc
    Model0218fe1c mdl1; // 0x368
    ActorRes res1; // 0x450
    ActorRes res2; // 0x588
    ActorSub48 hit1; // 0x6c0
    VecFx32 unk_75c;
    s32 unk_768;
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    union {
        FieldId fieldId; // copied from FieldState::unk_ca
        struct {
            u8 unk_772;
            u8 unk_773;
            u8 unk_774;
        };
    };
    u8 unk_775[0x3];
    Model0218fe1c mdl2; // 0x778
    ActorRes res3; // 0x860
    // Optional extra model (a Model0218fe1c, 0xe8 bytes, func_ov000_0218fe1c) and its resources
    // (an ActorRes, 0x138 bytes). Kept void *: with the class types Robo_021afaf8 allocates
    // registers differently.
    void *unk_998;
    void *unk_99c;
    u16 unk_9a0;
    u16 unk_9a2;
    u16 unk_9a4;
    u16 unk_9a6;
    u16 unk_9a8;
    u16 unk_9aa;
    u16 unk_9ac;
    u16 unk_9ae;
    void *unk_9b0;
    void *unk_9b4;
    u8 unk_9b8[0x24];
    VecFx32 unk_9dc;
    u8 unk_9e8[0x60];
    u8 unk_a48;
    u8 unk_a49[0x2];
    u8 unk_a4b;
    u8 unk_a4c;
    u8 unk_a4d[0x27];
    VecFx32 unk_a74;
    u8 unk_a80[0x24];
    VecFx32 unk_aa4;
    u8 unk_ab0[0x24];
    VecFx32 unk_ad4;
    u8 unk_ae0; // animation indices from func_ov000_021909a8
    u8 unk_ae1;
    u8 unk_ae2;
    u8 unk_ae3;
    union {
        u8 unk_ae4;
        struct {
            u8 unk_ae4_0 : 1;
            u8 unk_ae4_1_f : 7;
        };
    };
    u8 unk_ae5[0x3];
    u16 unk_ae8;
    u16 unk_aea;
    u16 unk_aec;
    u8 unk_aee[0x2];
    VecFx32 unk_af0;
    VecFx32 unk_afc;
    s32 unk_b08;
    s32 unk_b0c;
    VecFx32 unk_b10;
    u16 unk_b1c;
    u16 unk_b1e;
    u16 unk_b20;
    union {
        u16 unk_b22;
        struct {
            u16 unk_b22_0 : 3;
            u16 unk_b22_3 : 1;
            u16 unk_b22_4 : 1;
            u16 unk_b22_5 : 1;
            u16 unk_b22_6 : 3;
            u16 unk_b22_9 : 2;
            u16 unk_b22_11 : 1;
            u16 unk_b22_12 : 1;
            u16 unk_b22_13 : 1;
            u16 unk_b22_14_f : 2;
        };
    };
    union {
        u32 unk_b24;
        struct {
            u32 unk_b24_0 : 1;
            u32 unk_b24_1 : 1;
            u32 unk_b24_2 : 2;
            u32 unk_b24_4 : 1;
            u32 unk_b24_5 : 2;
            u32 unk_b24_7 : 2;
            u32 unk_b24_9 : 1;
            u32 unk_b24_10_f : 2;
            u32 unk_b24_12 : 2;
            u32 unk_b24_14 : 2;
            u32 unk_b24_16 : 1;
            u32 unk_b24_17 : 1;
            u32 unk_b24_18 : 1;
            u32 unk_b24_19 : 1;
            u32 unk_b24_20_f : 1;
            u32 unk_b24_21 : 1;
            u32 unk_b24_22 : 2;
            u32 unk_b24_24 : 1;
            u32 unk_b24_25 : 1;
            u32 unk_b24_26 : 1;
            u32 unk_b24_27 : 1;
            u32 unk_b24_28_f : 4;
        };
    };
    union {
        u8 unk_b28;
        struct {
            u8 unk_b28_0 : 2;
            u8 unk_b28_2 : 1;
            u8 unk_b28_3 : 1;
            u8 unk_b28_4_f : 4;
        };
    };
    union {
        u8 unk_b29;
        struct {
            u8 unk_b29_0 : 1;
            u8 unk_b29_1 : 1;
            u8 unk_b29_2 : 1;
            u8 unk_b29_3 : 1;
            u8 unk_b29_4 : 1;
            u8 unk_b29_5_f : 3;
        };
    };
    union {
        u8 unk_b2a;
        struct {
            u8 unk_b2a_0 : 1;
            u8 unk_b2a_1_f : 2;
            u8 unk_b2a_3 : 1;
            u8 unk_b2a_4_f : 4;
        };
    };
    u8 unk_b2b;
    union {
        u16 unk_b2c;
        struct {
            u16 unk_b2c_0 : 1;
            u16 unk_b2c_1 : 1;
            u16 unk_b2c_2 : 1;
            u16 unk_b2c_3_f : 1;
            u16 unk_b2c_4 : 2;
            u16 unk_b2c_6 : 1;
            u16 unk_b2c_7 : 3;
            u16 unk_b2c_10_f : 6;
        };
    };
    u8 unk_b2e;
    u8 unk_b2f;
    u8 unk_b30;
    u8 unk_b31;
    u16 unk_b32;
    u16 unk_b34;
    u16 unk_b36;
    u16 unk_b38;
    u16 unk_b3a;
    u16 unk_b3c;
    u8 unk_b3e[0x2];
    u32 unk_b40; // effect handles
    u32 unk_b44;
    u32 unk_b48;
    s32 unk_b4c;
    s32 unk_b50;
    s32 unk_b54;
    u16 unk_b58;
    u16 unk_b5a;
    u16 unk_b5c;
    u16 unk_b5e;
    s32 unk_b60;
    s16 seSlot; // looping sound (func_02049afc / SndMgr_StopSeqArc), -1: none
    s16 unk_b66;
    u16 padCur; // copies of Pad cur / trig / release taken each frame (func_ov000_0219efc0)
    u16 padTrig;
    u16 padRelease;
    u16 padDir; // Pad_LookupDir angle, added to the camera yaw for movement
    u8 unk_b70[0x20];
    VecFx32 unk_b90;
    s32 unk_b9c;
    u8 *unk_ba0;
    u8 *unk_ba4;
    s32 unk_ba8;
    u16 unk_bac;
};
SIZE_ASSERT(Robo021ca458, 0xbb0);

// Vtable data_ov000_021ca94c; methods in G3_0214cff4.cpp, Lo_0214cb44.cpp, Menu_0214c2d0.cpp.
struct Menu021ca94c : public UiObj {
    Model *unk_84;
    Model *unk_88;
    VObj *unk_8c;
    u32 unk_90;  // bit fields, read through per-file views
    u32 unk_94;
    u8 unk_98[0x1c];
    s32 unk_b4;
    s32 unk_b8;
    u8 unk_bc[0xb];
    s8 unk_c7;
    s32 unk_c8;
    u8 unk_cc[0x8];
    s32 unk_d4;
    u8 unk_d8[0x4];
    s32 unk_dc;
    u8 unk_e0[0x20];
    s32 unk_100;
    u16 unk_104;
    u16 unk_106;
    s32 unk_108;
    u8 unk_10c[0x40];
    u32 unk_14c;
    u8 unk_150[0x1c];
    s32 unk_16c;
    s32 unk_170;
    u8 unk_174[0xb];
    s8 unk_17f;
    s32 unk_180;
    u8 unk_184[0x10];
    s32 unk_194;
    u8 unk_198[0x68];
    VObj *unk_200;
};


// Vtable data_ov000_021ca9c4; methods in 8 files, Lo_021501e4.cpp .. Lo_0215123c.cpp.
struct Lo021ca9c4 : public Task {
    VObj *unk_3c;
    u16 unk_40;
    u16 unk_42;
    Model *unk_44;
    Model *unk_48;
    Lo021cb5a8 *unk_4c;
    Lo021caac8 *unk_50;
    void *unk_54;
    Lo021cad50 *unk_58;
    s32 unk_5c;
    u32 unk_60;  // bit fields, read through per-file views
    u32 unk_64;
    u8 unk_68[0x1c];
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0x48];
    u16 unk_d4;
    u16 unk_d6;
    s32 unk_d8;
    u8 unk_dc[0x3c];
    u32 unk_118;  // bit fields, read through per-file views
    u32 unk_11c;
    u8 unk_120[0x1c];
    void *unk_13c;
    s32 unk_140;
    u8 unk_144[0xc];
    s32 unk_150;
    u8 unk_154[0x7c];
    u32 unk_1d0;  // bit fields, read through per-file views
    u32 unk_1d4;
    u8 unk_1d8[0x1c];
    void *unk_1f4;
    s32 unk_1f8;
    u8 unk_1fc[0x48];
    u16 unk_244;
    u16 unk_246;
    s32 unk_248;
    u8 unk_24c[0x3c];
    u32 unk_288;  // bit fields, read through per-file views
    u32 unk_28c;
    u8 unk_290[0x1c];
    char *unk_2ac;
    s32 unk_2b0;
    u8 unk_2b4[0x8c];
    u32 unk_340;  // bit fields, read through per-file views
    u32 unk_344;
    u8 unk_348[0x1c];
    void *unk_364;
    s32 unk_368;
    u8 unk_36c[0x48];
    u16 unk_3b4;
    u16 unk_3b6;
    s32 unk_3b8;
    u8 unk_3bc[0x3c];
    u32 unk_3f8;  // bit fields, read through per-file views
    u32 unk_3fc;
    u8 unk_400[0x1c];
    char *unk_41c;
    s32 unk_420;
};

// Vtable data_ov000_021caa44; methods in 6 files, Lo_0214e7f0.cpp .. Lo_0214f9ec.cpp.
struct Lo021caa44 : public Task {
    VObj *unk_3c;
    Model *unk_40;
    TextWin *unk_44;
    u8 unk_48[0x4];
    Lo021cb5a8 *unk_4c;
    Lo021caac8 *unk_50;
    u8 unk_54[0x8];
    VObj *unk_5c;
    Menu021ca94c *unk_60;
    u16 unk_64;
};

// Vtable data_ov000_021caac8; methods in Lo_0214e074.cpp, Lo_0214e3b4.cpp.
struct Lo021caac8 : public UiList021cb4a8 {
    Model *unk_e0; // cleared by slot 0x28, freed by slot 0x2c
};



// Bar display base (vtable data_ov000_021cac0c, 0x9c bytes; slot 0x14 func_ov000_02160344 clears
// it). Subclass vtables data_ov000_021cb6f0, 021cb744, 021cb798, 021cb7ec, 021cb840, 021cb894
// (all built by func_ov000_02170a58) and 021cca88 (func_ov000_021c2d48) keep its slots 0x08..0x10
// and 0x40..0x44. Methods in Obj_0215fe60.cpp, Lo_021601c4.cpp, Obj_02160344.c, Obj_0215fdfc.c,
// Cam_02160414.cpp, ov000_02160534.cpp, Lo_021609ec.cpp, Lo_02160c7c.cpp.
struct ObjBase021cac0c_021cb6f0 : public VObj {
    s32 unk_04; // state (func_ov000_0215fe60)
    u32 unk_08;
    union {
        u32 unk_0c;
        struct {
            u32 unk_0c_0 : 1;
            u32 unk_0c_1 : 1;
            u32 unk_0c_2 : 1;
            u32 unk_0c_3 : 1; // cleared by the subclasses' slot 0x28
            u32 unk_0c_4 : 1;
            u32 unk_0c_5 : 1;
            u32 unk_0c_6 : 1;
            u32 unk_0c_7 : 1; // unk_5c follows unk_64 (func_ov000_0215fe60, 0215fe1c)
            u32 unk_0c_8 : 1;
            u32 unk_0c_9 : 1;
            u32 unk_0c_10 : 1; // set by slot 0x14
            u32 unk_0c_11 : 5;
            u32 unk_0c_16 : 1;
            u32 unk_0c_17 : 15;
        };
    };
    u16 *colors[6]; // three RGB555 colours each (default data_ov000_021c9912; func_ov000_0215fdfc)
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c; // shown value
    s32 unk_60; // maximum (func_ov000_0215fe1c)
    s32 unk_64; // target value
    s32 unk_68;
    s32 unk_6c;
    u16 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    VecFx32 unk_80;
    s32 unk_8c;
    s32 unk_90;
    s32 unk_94;
    u8 unk_98;
};
SIZE_ASSERT(ObjBase021cac0c_021cb6f0, 0x9c);

// Vtable data_ov000_021cacd8; methods in 5 files, Lo_02160ff8.cpp .. Lo_0216150c.cpp.
struct Lo021cacd8 : public UiObj {
    Model *unk_84;
    u16 unk_88;
    u16 unk_8a;
    u8 unk_8c[0x4];
    u32 unk_90;  // bit fields, read through per-file views
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
};

// Vtable data_ov000_021cad50; methods in G3_0215d4b4.cpp, Lo_0215d30c.cpp, Lo_0215d3bc.cpp.
struct Lo021cad50 : public UiObj {
    s32 unk_84;
    u16 unk_88;
    void *unk_8c;      // Heap_FreeHi'd by slot 0x2c
    void *unk_90;      // Heap_FreeHi'd by slot 0x2c
    s32 unk_94;
    VObj *unk_98[12];  // freed by slot 0x2c; slot 0x70 sets bit 2 of each one's word 4
};

// Vtable data_ov000_021cadcc; methods in Lo_0215bd88.cpp, Lo_0215bf60.cpp, Lo_0215c05c.cpp, Lo_0215c0c4.cpp.
struct Lo021cadcc : public UiObj {
    VObj *unk_84;
    s32 unk_88;
};

// Vtable data_ov000_021cae48; methods in Lo_0215dae0.cpp, Lo_0215deb4.cpp, TextWin_0215d758.cpp, Win_0215db70.cpp.
struct Lo021cae48 : public UiObj {
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    Model *unk_90;
    TextWin *unk_94;
};



// Vtable data_ov000_021cafc0, data_ov000_021cb0b8, data_ov000_021cb1b0, data_ov006_021ec30c; methods in 6 files, G3_0215b2e4.cpp .. Text_0215b8f0.cpp.
struct LoBase021cafc0_021cb0b8 : public UiList {
    s32 unk_d4;
};


// Vtable data_ov000_021cb3a8; methods in 8 files, Hp_02158ed4.cpp .. Text_02158b48.cpp.
struct Lo021cb3a8 : public UiList021cb4a8 {
    char *srcStr;
    char *str;
    s32 strSize;
    VObj *unk_ec;
};

// Vtable data_ov000_021cb5a8; methods in 6 files, Lo_02159aac.cpp .. Lo_0215a7d8.cpp.
struct Lo021cb5a8 : public UiList {
    s32 unk_d4;
    void *dl;     // frame display list (func_ov000_0215a088, G3_BeginMakeDL), Heap_FreeHi'd by slot 0x2c
    u32 dlSize;
};

// Vtable data_ov000_021cb6b0; methods in Lo_021645b8.cpp, Lo_02164708.cpp.
struct Lo021cb6b0 : public VObj {
    u8 unk_04[0x1c];
    s32 unk_20;
    Model *unk_24;
    Model *unk_28;
    Model *unk_2c;
    u8 *unk_30;
    s32 unk_34;
    u8 unk_38[0x8];
    VObj *unk_40;
    u8 unk_44[0x8];
    s32 unk_4c;
    s32 unk_50;
};

// Vtable data_ov000_021cb6f0; methods in Lo_021680b4.cpp, Lo_021681c4.cpp, Lo_021681fc.cpp, Lo_021682fc.cpp.
struct Lo021cb6f0 : public ObjBase021cac0c_021cb6f0 {
    Model *unk_9c;
};

// Vtable data_ov000_021cb744; methods in Lo_0216a608.cpp, Lo_0216a7dc.cpp.
struct Lo021cb744 : public ObjBase021cac0c_021cb6f0 {
    Model *unk_9c;
    Model *unk_a0;
    u8 unk_a4;
    u8 unk_a5[0x1];
    u16 unk_a6;
    s32 unk_a8;
    u8 unk_ac; // func_ov000_0216a438
};

// Vtable data_ov000_021cb798; methods in Lo_021699f0.cpp, Lo_02169c14.cpp, Lo_02169d40.cpp.
struct Lo021cb798 : public ObjBase021cac0c_021cb6f0 {
    s32 unk_9c;
    Model *unk_a0;
    Model *unk_a4;
    u8 unk_a8;
    u8 unk_a9;
    u16 unk_aa;
    u32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
};

// Vtable data_ov000_021cb7ec; methods in Lo_0216926c.cpp, Lo_021692e0.cpp, Lo_021694e0.cpp.
struct Lo021cb7ec : public ObjBase021cac0c_021cb6f0 {
    Model *unk_9c;
    s32 unk_a0;
    u16 unk_a4;
    u8 unk_a6[0x2];
    u32 unk_a8;
    s32 unk_ac;
};

// Vtable data_ov000_021cb840; methods in Lo_02168ee0.cpp, Lo_02168f50.cpp, Lo_02168f90.cpp, Lo_0216906c.cpp.
struct Lo021cb840 : public ObjBase021cac0c_021cb6f0 {
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

// Vtable data_ov000_021cb894; methods in 5 files, Lo_021685f4.cpp .. Lo_021688c4.cpp.
struct Lo021cb894 : public ObjBase021cac0c_021cb6f0 {
    Model *unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
    s32 unk_b8;
};

// Vtable data_ov000_021cc938; methods in 9 files, Lo_021befc0.cpp .. ov000_021c14f4.cpp.
struct Lo021cc938 {
    u8 unk_00[0x4];
    void *unk_04;
    u8 unk_08[0x3c];
    s32 unk_44;
    u8 unk_48[0x8];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5c[0xc];
    s32 unk_68;
    u8 unk_6c[0xc];
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    Model *unk_8c;
    Model *unk_90;
    Model *unk_94;
    s32 unk_98;
};

// Vtable data_ov000_021cca10; methods in Hud_021c2450.cpp, Hud_021c28cc.cpp.
struct Hud021cca10 {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1c[0x4];
    u8 unk_20;  // bit fields, read through per-file views
    u8 unk_21[0xf];
    Model *unk_30;
    Model *unk_34;
    TextWin *unk_38;
    void *unk_3c;
    char *unk_40;
    u8 unk_44;
};

// Vtable data_ov000_021cca40; methods in Lo_021c5bd4.cpp, Win_021c5d9c.cpp.
struct Lo021cca40 {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x18];
    TextWin *unk_30;
    Model *unk_34;
    void *unk_38;
    u16 unk_3c;
    u8 unk_3e[0x2];
    u32 unk_40;
    u8 unk_44;
};

// Vtable data_ov000_021ccb54, data_ov000_021ccbe0; methods in Text_021c524c.cpp, Unit_021c3d20.cpp.
struct UnitBase021ccb54_021ccbe0 : public UiObj {
    Model *unk_84;
    u8 unk_88[0x8];
    u8 *unk_90;
    void *unk_94;
    s32 unk_98;
    s32 unk_9c;
    void *unk_a0;
    u8 unk_a4[0xc];
    s32 unk_b0;
    s32 unk_b4;
    s32 unk_b8;
    u8 unk_bc[0x4];
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
};

// Vtable data_ov000_021ccb54, data_ov000_021ccbe0, data_ov002_021f0044; methods in Lo_021c4d90.cpp, Lo_021c5028.cpp, Lo_021c5128.cpp, Text_021c524c.cpp.
struct LoBase021ccb54_021ccbe0 : public UiObj {
    u8 unk_84[0x10];
    VObj *unk_94;
    u8 unk_98[0x4];
    s32 unk_9c;
    VObj *unk_a0; // a row (ov002 reads its id and texts)
    VObj *unk_a4; // a row (ov002 reads its index)
    u8 unk_a8[0x10];
    s32 unk_b8;
    u8 unk_bc[0x4];
    s32 unk_c0;
    u8 unk_c4[0x8];
    s8 unk_cc;
    s8 unk_cd;
    u8 unk_ce[0x2];
    s32 unk_d0;
    u8 unk_d4[0xb];
    u8 unk_df;
    s32 unk_e0;
};

#endif
