#ifndef OV010_OBJLAYOUTS_H
#define OV010_OBJLAYOUTS_H

// Layouts of ov010 objects whose methods are spread over several files (round svA).
// Field names are offsets; only fields that some method reads or writes are declared.

#include "types.h"
#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov010/ov010.h"


// Vtable data_ov010_0220ffe4; methods in ov010_02207520.cpp, ov010_022085d0.cpp, ov010_02208898.cpp.
struct Ov010Obj0220ffe4 : public Ov003Actor {
    u8 unk_f0[0x3];
    u8 unk_f3;
    u8 unk_f4[0x24];
    VObj *unk_118;
    u8 unk_11c[0x8];
    s16 *unk_124;
    u8 unk_128[0x28];
    VecFx32 unk_150;
    u8 unk_15c[0xa0];
    u8 unk_1fc;
    u8 unk_1fd[0x3];
    s32 unk_200;
};

// Vtable data_ov010_0220ffe4, data_ov010_0221009c, data_ov010_02210154; methods in ov010_02204204.cpp, ov010_0220f958.cpp.
struct Ov010ObjBase0220ffe4_0221009c : public Ov003Actor {
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u8 unk_f4[0x4];
    VecFx32 *unk_f8;
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
    VecFx32 unk_150;
    s32 unk_15c;
    u8 unk_160[0x11];
    u8 unk_171;
};

// Vtable data_ov010_0221009c; methods in ov010_02208898.cpp, ov010_022089d8.cpp, ov010_02208c3c.cpp.
struct Ov010Obj0221009c : public Ov003Actor {
    u8 unk_f0[0x3];
    u8 unk_f3;
};

#endif
