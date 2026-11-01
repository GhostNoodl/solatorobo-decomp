#ifndef OV010_OBJLAYOUTS_H
#define OV010_OBJLAYOUTS_H

// Layouts of ov010 objects whose methods are spread over several files (round svA).
// Field names are offsets; only fields that some method reads or writes are declared.

#include "types.h"
#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov010/ov010.h"


// Vtable data_ov010_0220ffe4; methods in ov010_02207520.cpp, ov010_022085d0.cpp, ov010_02208898.cpp.
struct Ov010Obj0220ffe4 {
    void *unk_00;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x8];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *unk_38;
    u8 unk_3c[0x4];
    u16 *unk_40;
    u8 unk_44[0xc];
    u16 *unk_50;
    u8 unk_54[0x1c];
    Ov010Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x16];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0xc];
    Ov010Vec unk_b8;
    u8 unk_c4[0x2f];
    u8 unk_f3;
    u8 unk_f4[0x5c];
    Ov010Vec unk_150;
    u8 unk_15c[0xa0];
    u8 unk_1fc;
    u8 unk_1fd[0x3];
    s32 unk_200;
};

// Vtable data_ov010_0220ffe4, data_ov010_0221009c, data_ov010_02210154; methods in ov010_02204204.cpp, ov010_0220f958.cpp.
struct Ov010ObjBase0220ffe4_0221009c {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    void *unk_38;
    u8 unk_3c[0x4];
    u16 *unk_40;
    void *unk_44;
    void *unk_48;
    u8 *unk_4c;
    void *unk_50;
    u8 unk_54[0x14];
    s32 unk_68;
    u8 unk_6c[0x4];
    Ov010Vec unk_70;
    u8 unk_7c[0x2];
    u16 unk_7e;
    u8 unk_80[0x10];
    u16 unk_90;
    u8 unk_92;
    Ov010Flags8 unk_93;
    u8 unk_94[0x2];
    u16 unk_96;
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x4];
    s16 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov010Vec unk_b8;
    s32 unk_c4;
    u8 unk_c8[0x16];
    u16 unk_de;
    u8 unk_e0[0xc];
    Ov010Flags8 unk_ec;
    u8 unk_ed[0x3];
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u8 unk_f4[0x4];
    Ov010Vec *unk_f8;
    s32 unk_fc;
    s32 unk_100;
    void *unk_104;
    void *unk_108;
    void *unk_10c;
    void *unk_110;
    u8 unk_114[0x4];
    void *unk_118;
    u8 unk_11c[0xc];
    s32 unk_128;
    u8 unk_12c[0x4];
    s32 unk_130;
    s32 unk_134;
    s32 unk_138;
    s32 unk_13c;
    s32 unk_140;
    u8 unk_144[0x4];
    s32 unk_148;
    u8 unk_14c[0x4];
    Ov010Vec unk_150;
    s32 unk_15c;
    u8 unk_160[0x11];
    u8 unk_171;
};

// Vtable data_ov010_0221009c; methods in ov010_02208898.cpp, ov010_022089d8.cpp, ov010_02208c3c.cpp.
struct Ov010Obj0221009c {
    u8 unk_00[0x18];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *unk_38;
    u8 unk_3c[0x4];
    u16 *unk_40;
    u8 unk_44[0xc];
    u16 *unk_50;
    u8 unk_54[0x1c];
    Ov010Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x16];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x47];
    u8 unk_f3;
};

#endif
