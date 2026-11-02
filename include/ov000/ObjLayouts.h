#ifndef OV000_OBJLAYOUTS_H
#define OV000_OBJLAYOUTS_H

// Layouts of ov000 objects whose methods are spread over several files (round svA).
// Field names are offsets; only fields that some method reads or writes are declared.

#include "types.h"
#include "ov000/Vec.h"
#include "ov000/VObj.h"
#include "ov000/ActorBase.h"

struct Model;
struct TextWin;

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
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
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
};
SIZE_ASSERT(ActorEx, 0xd0);

// The robot actor (ctor Robo021ca458_Ctor, vtable data_ov000_021cc774, 0xbb0 bytes; its state
// handlers are the pointer-to-member table data_ov000_021ca458). Methods in Robo_*.cpp and others.
// The bit fields at 0xae4 and 0xb22..0xb2c are the union of the members the methods use.
struct Robo021ca458 : public Actor {
    u8 *unk_ac;
    u8 unk_b0[0x4c];
    void *unk_fc;
    u8 unk_100[0x24];
    s32 unk_124;
    s32 unk_128;
    s32 unk_12c;
    u8 unk_130[0x30];
    u16 unk_160;
    u8 unk_162[0xb];
    u8 unk_16d;
    u16 unk_16e_0 : 1;
    u16 unk_16e_1 : 15;
    u8 unk_170[0x8];
    s16 unk_178;
    u8 unk_17a[0x2];
    u8 *unk_17c;
    u8 *unk_180;
    u8 unk_184[0x8];
    void *unk_18c;
    u8 unk_190[0x4];
    s16 unk_194;
    u8 unk_196[0xbe];
    u32 *unk_254;
    u8 unk_258[0x9c];
    s32 unk_2f4;
    u8 unk_2f8[0xc];
    s32 unk_304;
    u8 unk_308[0x14];
    u32 unk_31c;
    s32 unk_320;
    s32 unk_324;
    u8 unk_328[0x4];
    s32 unk_32c;
    u8 unk_330[0x8];
    s32 unk_338;
    u8 unk_33c[0x2a];
    u16 unk_366_0 : 1;
    u16 unk_366_1 : 1;
    u16 unk_366_2 : 1;
    u16 unk_366_3 : 1;
    u16 unk_366_4 : 12;
    u8 unk_368[0x1c];
    u8 *unk_384;
    u8 unk_388[0x30];
    void *unk_3b8;
    u8 unk_3bc[0x6a];
    u8 unk_426;
    u8 unk_427[0x2];
    u8 unk_429;
    u16 unk_42a_0 : 1;
    u16 unk_42a_1 : 15;
    u8 unk_42c[0x24];
    s16 unk_450;
    u8 unk_452[0x1];
    u8 unk_453_0 : 1;
    u8 unk_453_1 : 1;
    u8 unk_453_2 : 1;
    u8 unk_453_3 : 1;
    u8 unk_453_4 : 1;
    u8 unk_453_5 : 3;
    u8 unk_454[0x134];
    s16 unk_588;
    u8 unk_58a[0x1];
    u8 unk_58b_0 : 1;
    u8 unk_58b_1 : 1;
    u8 unk_58b_2 : 1;
    u8 unk_58b_3 : 1;
    u8 unk_58b_4 : 1;
    u8 unk_58b_5 : 3;
    u8 unk_58c[0x15c];
    s32 unk_6e8;
    u8 unk_6ec[0xc];
    s32 unk_6f8;
    u8 unk_6fc[0xc];
    s32 unk_708;
    s32 unk_70c;
    u32 unk_710;
    u32 unk_714;
    s32 unk_718;
    u8 unk_71c[0x4];
    s32 unk_720;
    u8 unk_724[0x8];
    s32 unk_72c;
    u8 unk_730[0x2a];
    u16 unk_75a_0 : 1;
    u16 unk_75a_1 : 1;
    u16 unk_75a_2 : 1;
    u16 unk_75a_3 : 1;
    u16 unk_75a_4 : 12;
    VecFx32 unk_75c;
    s32 unk_768;
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772;
    u8 unk_773;
    u8 unk_774;
    u8 unk_775[0xb7];
    u16 unk_82c;
    u16 unk_82e;
    u16 unk_830;
    u16 unk_832;
    u16 unk_834;
    u8 unk_836;
    u8 unk_837[0x2];
    u8 unk_839;
    u8 unk_83a[0x26];
    s16 unk_860;
    u8 unk_862[0x1];
    u8 unk_863_0 : 1;
    u8 unk_863_1 : 1;
    u8 unk_863_2 : 1;
    u8 unk_863_3 : 1;
    u8 unk_863_4 : 1;
    u8 unk_863_5 : 3;
    u8 unk_864[0x134];
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
    u8 unk_9b8[0x90];
    u8 unk_a48;
    u8 unk_a49[0x2];
    u8 unk_a4b;
    u8 unk_a4c;
    u8 unk_a4d[0x27];
    s32 unk_a74;
    s32 unk_a78;
    s32 unk_a7c;
    u8 unk_a80[0x24];
    VecFx32 unk_aa4;
    u8 unk_ab0[0x34];
    union {
        u8 unk_ae4;
        struct {
            u8 unk_ae4_0 : 1;
            u8 unk_ae4_1_f : 7;
        };
    };
    u8 unk_ae5[0x5];
    u16 unk_aea;
    u16 unk_aec;
    u8 unk_aee[0x2];
    s32 unk_af0;
    s32 unk_af4;
    s32 unk_af8;
    s32 unk_afc;
    s32 unk_b00;
    s32 unk_b04;
    s32 unk_b08;
    s32 unk_b0c;
    s32 unk_b10;
    u8 unk_b14[0x4];
    s32 unk_b18;
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
    s32 unk_b40;
    s32 unk_b44;
    s32 unk_b48;
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
struct Menu021ca94c : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    void *unk_10;
    u8 unk_14[0x10];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x8];
    void *unk_38;
    u8 unk_3c[0x1c];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 posZ;
    u8 unk_6a[0x1a];
    void *unk_84;
    u8 *unk_88;
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

// Vtable data_ov000_021ca94c, data_ov000_021caac8, data_ov000_021cac60, data_ov000_021cacd8, data_ov000_021cad50, data_ov000_021cadcc, data_ov000_021cae48, data_ov000_021caec8, data_ov000_021cafc0, data_ov000_021cb0b8, data_ov000_021cb1b0, data_ov000_021cb2a8, data_ov000_021cb3a8, data_ov000_021cb4a8, data_ov000_021cb5a8, data_ov000_021ccadc, data_ov000_021ccb54, data_ov000_021ccbe0, data_ov002_021efca4, data_ov002_021f0044, data_ov006_021ec30c, data_ov008_021d0368, data_ov015_02212d3c; methods in G3_02153804.cpp, Lo_02152690.cpp, Lo_02152740.cpp, Text_021523a8.cpp.
struct LoBase021ca94c_021caac8 : public VObj {
    s32 unk_04;
    u8 unk_08[0x10];
    u8 *unk_18;
    u8 unk_1c[0x8];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    u16 unk_48;
    u8 unk_4a[0x2];
    s32 unk_4c;
    s32 unk_50;
    u8 unk_54[0x4];
    s32 unk_58;
    s32 unk_5c;
    u8 unk_60[0x8];
    s16 unk_68;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    VObj *unk_74;
};

// Vtable data_ov000_021ca9c4; methods in 8 files, Lo_021501e4.cpp .. Lo_0215123c.cpp.
struct Lo021ca9c4 : public VObj {
    u32 unk_04;
    s32 unk_08;
    u8 unk_0c[0x14];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x14];
    VObj *unk_3c;
    u16 unk_40;
    u16 unk_42;
    void *unk_44;
    void *unk_48;
    VObj *unk_4c;
    VObj *unk_50;
    void *unk_54;
    VObj *unk_58;
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
struct Lo021caa44 : public VObj {
    u32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10[0x14];
    s32 unk_24;
    u8 unk_28[0x14];
    VObj *unk_3c;
    void *unk_40;
    u8 *unk_44;
    u8 unk_48[0x4];
    VObj *unk_4c;
    void *unk_50;
    u8 unk_54[0x8];
    VObj *unk_5c;
    VObj *unk_60;
    u16 unk_64;
};

// Vtable data_ov000_021caac8; methods in Lo_0214e074.cpp, Lo_0214e3b4.cpp.
struct Lo021caac8 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    void *unk_10;
    u8 unk_14[0x54];
    s16 unk_68;
    u8 unk_6a[0x4a];
    Model *unk_b4;
    Model *unk_b8;
};

// Vtable data_ov000_021caac8, data_ov000_021caec8, data_ov000_021cafc0, data_ov000_021cb0b8, data_ov000_021cb1b0, data_ov000_021cb2a8, data_ov000_021cb3a8, data_ov000_021cb4a8, data_ov000_021cb5a8, data_ov002_021efca4, data_ov006_021ec30c, data_ov008_021d0368; methods in 6 files, Lo_02155ac4.cpp .. Lo_02156d48.cpp.
struct LoBase021caac8_021caec8 : public VObj {
    u8 unk_04[0x4];
    void *unk_08;
    u32 unk_0c;
    void *unk_10;
    u8 unk_14[0xc];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x8];
    s32 unk_34;
    u8 unk_38[0x2c];
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0x4];
    void *unk_78;
    u8 unk_7c[0x8];
    void *unk_84;
    u8 unk_88[0xc];
    void *unk_94;
    u8 *unk_98;
    s16 unk_9c;
    s16 unk_9e;
    s16 unk_a0;
    s16 unk_a2;
    u8 *unk_a4;
    u8 unk_a8[0xa];
    s8 unk_b2;
    s8 unk_b3;
    u8 unk_b4[0x8];
    Model *unk_bc;
    u8 unk_c0[0x2];
    s8 unk_c2;
    s8 unk_c3;
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    s32 unk_d0;
};

// Vtable data_ov000_021caac8, data_ov000_021cb2a8, data_ov000_021cb4a8; methods in 6 files, Lo_02157fc0.cpp .. Menu_021581d4.cpp.
struct LoBase021caac8_021cb2a8 : public VObj {
    u8 unk_04[0x4];
    void *unk_08;
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x18];
    u16 color;
    u8 unk_4a[0xa];
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 posZ;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0xc];
    void *unk_80;
    void *unk_84;
    void *unk_88;
    u8 unk_8c[0x8];
    void *unk_94;
    void *unk_98;
    s16 unk_9c;
    s16 unk_9e;
    s16 unk_a0;
    s16 unk_a2;
    u8 unk_a4[0x4];
    void *unk_a8;
    void *unk_ac;
    s8 unk_b0;
    s8 unk_b1;
    u8 unk_b2[0xe];
    u8 unk_c0;
    u8 unk_c1;
    u8 unk_c2[0x12];
    u8 *unk_d4;
    u8 *unk_d8;
};

// Vtable data_ov000_021cac0c, data_ov000_021cb6f0, data_ov000_021cb744, data_ov000_021cb798, data_ov000_021cb7ec, data_ov000_021cb840, data_ov000_021cb894, data_ov000_021cca88; methods in Lo_021601c4.cpp, Obj_0215fe60.cpp.
struct ObjBase021cac0c_021cb6f0 : public VObj {
    s32 unk_04;
    u8 unk_08[0x20];
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    u8 unk_40[0x4];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    u8 unk_54[0x8];
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    u8 unk_70[0x4];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
};

// Vtable data_ov000_021cacd8; methods in 5 files, Lo_02160ff8.cpp .. Lo_0216150c.cpp.
struct Lo021cacd8 : public VObj {
    s32 unk_04;
    void *unk_08;
    u32 unk_0c;
    u8 *unk_10;
    u8 unk_14[0x10];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x18];
    u16 color;
    u8 unk_4a[0x1a];
    s16 posX;
    s16 posY;
    s16 posZ;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0x10];
    u8 *unk_84;
    u16 unk_88;
    u16 unk_8a;
    u8 unk_8c[0x4];
    u32 unk_90;  // bit fields, read through per-file views
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
};

// Vtable data_ov000_021cad50; methods in G3_0215d4b4.cpp, Lo_0215d30c.cpp, Lo_0215d3bc.cpp.
struct Lo021cad50 : public VObj {
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x14];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0xc];
    u16 color;
    u8 unk_4a[0x1e];
    s16 posZ;
    u8 unk_6a[0x2e];
    VObj *unk_98;
};

// Vtable data_ov000_021cadcc; methods in Lo_0215bd88.cpp, Lo_0215bf60.cpp, Lo_0215c05c.cpp, Lo_0215c0c4.cpp.
struct Lo021cadcc : public VObj {
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    Model *unk_10;
    void *unk_14;
    u8 unk_18[0x8];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0xc];
    s16 unk_48;
    u8 unk_4a[0xe];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0x10];
    VObj *unk_84;
};

// Vtable data_ov000_021cae48; methods in Lo_0215dae0.cpp, Lo_0215deb4.cpp, TextWin_0215d758.cpp, Win_0215db70.cpp.
struct Lo021cae48 : public VObj {
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x14];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0xc];
    u16 color;
    u8 unk_4a[0xa];
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 posZ;
    u8 unk_6a[0x1a];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    Model *unk_90;
    TextWin *unk_94;
};

// Vtable data_ov000_021caec8, data_ov000_021cb5a8, data_ov002_021efca4, data_ov008_021d0368; methods in Lo_02155f68.cpp, Lo_02156ca0.cpp.
struct LoBase021caec8_021cb5a8 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    s32 unk_20;
    u8 unk_24[0x40];
    s16 unk_64;
    u8 unk_66[0x2];
    s16 unk_68;
    u8 unk_6a[0x16];
    void *unk_80;
    u8 unk_84[0x10];
    void *unk_94;
    void *unk_98;
    u8 unk_9c[0x2];
    s16 unk_9e;
    s16 unk_a0;
    u8 unk_a2[0x6];
    void *unk_a8;
    void *unk_ac;
    u8 unk_b0[0x1];
    s8 unk_b1;
};

// Vtable data_ov000_021caec8, data_ov002_021efca4, data_ov008_021d0368; methods in Lo_02154c34.cpp, Lo_02155f68.cpp, Menu_0215429c.cpp.
struct LoBase021caec8_021efca4 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 *unk_10;
    u8 unk_14[0xc];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x18];
    u16 color;
    u8 unk_4a[0xa];
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x4];
    s16 posZ;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0x20];
    void *unk_94;
    u8 unk_98[0x4];
    s16 unk_9c;
    u8 unk_9e[0xe];
    void *unk_ac;
    u8 unk_b0[0x4];
    u8 *unk_b4;
};

// Vtable data_ov000_021cafc0, data_ov000_021cb0b8, data_ov000_021cb1b0, data_ov006_021ec30c; methods in 6 files, G3_0215b2e4.cpp .. Text_0215b8f0.cpp.
struct LoBase021cafc0_021cb0b8 : public VObj {
    s32 unk_04;
    void *unk_08;
    u32 unk_0c;
    void *unk_10;
    u8 unk_14[0x8];
    void *unk_1c;
    u8 unk_20[0x4];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u8 unk_3c[0xc];
    u16 color;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0x10];
    s16 posZ;
    u8 unk_6a[0x1a];
    void *unk_84;
    u8 unk_88[0xc];
    u8 *unk_94;
    u8 unk_98[0x14];
    u8 *unk_ac;
    u8 unk_b0[0x1];
    s8 unk_b1;
    u8 unk_b2[0x22];
    s32 unk_d4;
};

// Vtable data_ov000_021cb2a8, data_ov000_021cb4a8; methods in Lo_02157c28.cpp, Lo_02157df0.cpp.
struct LoBase021cb2a8_021cb4a8 {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x14];
    s32 unk_24;
    u8 unk_28[0x4];
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    u8 unk_66[0x46];
    void *unk_ac;
    u8 unk_b0[0x24];
    u8 *unk_d4;
    u8 *unk_d8;
};

// Vtable data_ov000_021cb3a8; methods in 8 files, Hp_02158ed4.cpp .. Text_02158b48.cpp.
struct Lo021cb3a8 : public VObj {
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x1c];
    u16 color;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0xc];
    s16 unk_64;
    u8 unk_66[0x2];
    s16 posZ;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0xc];
    void *unk_80;
    u8 unk_84[0x10];
    void *unk_94;
    void *unk_98;
    s16 unk_9c;
    s16 unk_9e;
    u8 unk_a0[0x2];
    u16 unk_a2;
    void *unk_a4;
    u8 unk_a8[0x4];
    u8 *unk_ac;
    s8 unk_b0;
    s8 unk_b1;
    s8 unk_b2;
    s8 unk_b3;
    u8 unk_b4[0x2c];
    char *srcStr;
    char *str;
    s32 strSize;
    VObj *unk_ec;
};

// Vtable data_ov000_021cb5a8; methods in 6 files, Lo_02159aac.cpp .. Lo_0215a7d8.cpp.
struct Lo021cb5a8 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    Model *unk_10;
    u8 unk_14[0x8];
    void *unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 posZ;
    u8 unk_6a[0x2a];
    u8 *unk_94;
    u8 *unk_98;
    s16 unk_9c;
    u8 unk_9e[0x36];
    s32 unk_d4;
};

// Vtable data_ov000_021cb6b0; methods in Lo_021645b8.cpp, Lo_02164708.cpp.
struct Lo021cb6b0 : public VObj {
    u8 unk_04[0x1c];
    s32 unk_20;
    void *unk_24;
    void *unk_28;
    void *unk_2c;
    u8 *unk_30;
    s32 unk_34;
    u8 unk_38[0x8];
    VObj *unk_40;
    u8 unk_44[0x8];
    s32 unk_4c;
    s32 unk_50;
};

// Vtable data_ov000_021cb6f0; methods in Lo_021680b4.cpp, Lo_021681c4.cpp, Lo_021681fc.cpp, Lo_021682fc.cpp.
struct Lo021cb6f0 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x1c];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x18];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0x10];
    void *unk_9c;
};

// Vtable data_ov000_021cb744; methods in Lo_0216a608.cpp, Lo_0216a7dc.cpp.
struct Lo021cb744 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    u8 unk_44[0xc];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x18];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    u8 unk_80[0x1c];
    void *unk_9c;
    void *unk_a0;
    u8 unk_a4;
    u8 unk_a5[0x1];
    u16 unk_a6;
    s32 unk_a8;
};

// Vtable data_ov000_021cb798; methods in Lo_021699f0.cpp, Lo_02169c14.cpp, Lo_02169d40.cpp.
struct Lo021cb798 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u8 unk_50[0x4];
    s32 unk_54;
    u8 unk_58[0x4];
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x10];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    u8 unk_80[0x1c];
    s32 unk_9c;
    void *unk_a0;
    void *unk_a4;
    u8 unk_a8;
    u8 unk_a9;
    u16 unk_aa;
    u32 unk_ac;
};

// Vtable data_ov000_021cb7ec; methods in Lo_0216926c.cpp, Lo_021692e0.cpp, Lo_021694e0.cpp.
struct Lo021cb7ec {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x1c];
    s32 unk_50;
    s32 unk_54;
    u8 unk_58[0x1c];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    u8 unk_80[0x1c];
    void *unk_9c;
    s32 unk_a0;
    u16 unk_a4;
    u8 unk_a6[0x2];
    u32 unk_a8;
};

// Vtable data_ov000_021cb840; methods in Lo_02168ee0.cpp, Lo_02168f50.cpp, Lo_02168f90.cpp, Lo_0216906c.cpp.
struct Lo021cb840 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x1c];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u8 unk_5c[0x18];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0x1c];
    s32 unk_a8;
};

// Vtable data_ov000_021cb894; methods in 5 files, Lo_021685f4.cpp .. Lo_021688c4.cpp.
struct Lo021cb894 : public VObj {
    s32 unk_04;
    u8 unk_08[0x4];
    u32 unk_0c;
    u8 unk_10[0x18];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x1c];
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x10];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    u8 unk_8c[0x10];
    Model *unk_9c;
    u8 unk_a0[0xc];
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0x4];
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
struct UnitBase021ccb54_021ccbe0 {
    u8 unk_00[0xc];
    u32 unk_0c;
    Model *unk_10;
    u8 unk_14[0xc];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 unk_64[0x4];
    s16 unk_68;
    u8 unk_6a[0x1a];
    u8 *unk_84;
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
struct LoBase021ccb54_021ccbe0 {
    u8 unk_00[0x10];
    Model *unk_10;
    u8 unk_14[0xc];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x3c];
    s16 unk_68;
    u8 unk_6a[0x2];
    void *unk_6c;
    s32 unk_70;
    u8 unk_74[0x20];
    VObj *unk_94;
    u8 unk_98[0x4];
    s32 unk_9c;
    u8 unk_a0[0x18];
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
