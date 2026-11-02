#ifndef OV006_LABEL_H
#define OV006_LABEL_H

#include "ov006/Model.h"
#include "ov000/VObj.h"
#include "nitro/std.h"

// Main's base resource handle (vtable data_0208b318, 0x4c bytes): the head that DataRes and MsgRes
// extend (Main/Res/DataRes.h). Slot 0x08 clears it, 0x0c unloads, 0x10 returns the data,
// 0x1c/0x24 open a file and 0x2c tests that it is loaded.
struct ov006_ResHandle : public VObj {
    char arcName[0x20]; // 0x04
    char name[0x20];    // 0x24
    s32 type;           // 0x44
    u8 loaded;          // 0x48
};

// A file loader (vtable data_ov006_021ec25c, 0x98 bytes): ov006_ResLoader_Update opens arcName/name
// through res once request is set.
struct ov006_ResLoader : public VObj {
    u8 step;              // 0x04
    ov006_ResHandle res;  // 0x08
    char arcName[0x20];   // 0x54
    char name[0x20];      // 0x74
    u8 request;           // 0x94
};

// A model part loaded from a file and slid into place (vtable data_ov006_021ec2fc, 0xec bytes,
// ctor Ov006Vt_021ec2fc_Ctor). ov006_Label_Set names the file and the part; ov006_Label_Update
// runs it and ov006_Label_Draw draws the part at origin + pos.
struct ov006_Label : public VObj {
    s32 state;            // 0x04
    s16 timer;            // 0x08
    ov006_ResLoader loader; // 0x0c
    u16 partId;           // 0xa4 the part to show next (0xffff: none)
    Model *model;         // 0xa8
    u16 part;             // 0xac the part shown
    VecFx32 origin;       // 0xb0
    VecFx32 pos;          // 0xbc
    VecFx32 dir;          // 0xc8
    fx32 speed;           // 0xd4
    fx32 unkD8;
    s32 alpha;            // 0xdc
    s32 unkE0;
    s32 unkE4;
    u8 unkE8;
};

static inline void ov006_Label_Set(ov006_Label *self, const char *a, const char *b, u16 c) {
    self->loader.request = 1;
    if (a == NULL) {
        self->loader.arcName[0] = 0;
    } else {
        STD_CopyLString(self->loader.arcName, a, 0x20);
    }
    if (b == NULL) {
        self->loader.name[0] = 0;
    } else {
        STD_CopyLString(self->loader.name, b, 0x20);
    }
    self->partId = c;
    if (self->state == 0) {
        self->state = 5;
        self->timer = 0;
    } else if ((u32)(self->state - 1) <= 1) {
        self->state = 3;
        self->timer = 0;
    }
}

#endif
