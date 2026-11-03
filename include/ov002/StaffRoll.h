#ifndef OV002_STAFFROLL_H
#define OV002_STAFFROLL_H

#include "types.h"
#include "ov000/VObj.h"
#include "Main/Gfx/Model.h"
#include "ov002/ObjLayouts.h"

// The staff roll: a script file of timed entries, one node object per entry, all driven by the
// clock of the staff object (data_ov002_021f0fa4).

// One script entry (0x14 bytes). Ov002StaffLoader_Parse fixes it up after loading.
typedef struct Ov002StaffEntry {
    /* 0x00 */ s32 kind; // node class: 3 base, 4 text, 5 model, 6 photo, 7 sound (1, 2, 8 make no node)
    /* 0x04 */ s32 time; // start time on the staff clock: frames in the file, fx32 once loaded
    /* 0x08 */ union {
        char *str; // a string-pool offset in the file, a pointer once loaded
        s32 seq;   // bit 31 set in the file: a plain number (the sound node's sequence)
    };
    // Per-kind parameters.
    //   text:  0c layout style (0..4), 0e hold time for style 2 (frames, 0: the config's)
    //   model: 0c screen, 0e behaviour (0 fade, 1 end the active model with the same string),
    //          10 end rule (0: after 12 frames, 12 = 0 meaning the config's; 2: when another
    //          model is still showing; 3: the same on this screen)
    //   photo: 0c screen
    //   sound: 0c command (0 load and fade in, 1 stop, 2, 3), 0e fade frames
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} Ov002StaffEntry;

// Script file header; `count` entries follow it, then the string pool at `poolOfs`.
typedef struct Ov002StaffScript {
    /* 0x00 */ u8 unk_00[0x8];
    /* 0x08 */ u16 poolOfs;
    /* 0x0a */ u16 count;
} Ov002StaffScript;

typedef struct Ov002StaffFlags {
    u32 active : 1; // the clock has reached the entry's time
    u32 b1 : 1;
    u32 paused : 1; // a node is not ready yet: hold the staff clock this frame
    u32 done : 1;   // ask for state 3 (leave)
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 rest : 25;
} Ov002StaffFlags;

// State machine and clock, shared by the staff object (at +0x04) and every node (at +0x04).
// A node's step function (func_ov002_021ec390) reads the staff's clock through it.
typedef struct Ov002StaffClock {
    /* 0x00 */ union {
        u32 bits;
        Ov002StaffFlags flags;
    };
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 next;
    /* 0x0c */ s32 sub;
    /* 0x10 */ s32 timer;
    /* 0x14 */ s32 prevTimer;
    /* 0x18 */ s32 step;
} Ov002StaffClock;

// Resource handle (0x4c bytes, base vtable ResHandle_vtbl, whose leading layout DataRes shows).
struct Ov002StaffRes : public VObj {
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ s32 type;
    /* 0x48 */ u8 loaded;
};

// Base node (0x34 bytes, vtable Ov002Vt_021f0ef4_vtbl; entry kind 3).
struct Ov002StaffNode : public VObj {
    /* 0x04 */ Ov002StaffClock clock;
    /* 0x20 */ Ov002StaffEntry *entry;
    /* 0x24 */ s32 screen; // 0 or 1; 2 draws on both
    /* 0x28 */ Ov002StaffNode *prev; // run list (data_ov002_021f0fa0 .. data_ov002_021f0fa8), by time
    /* 0x2c */ Ov002StaffNode *next;
    /* 0x30 */ Ov002StaffNode *link; // per-kind list (data_ov002_021f0fac[kind])
};

// Model node (0x4c bytes, vtable Ov002Vt_021f0e4c_vtbl; entry kind 5).
struct Ov002StaffModel : public Ov002StaffNode {
    /* 0x34 */ Ov002StaffRes *res; // holds the model file
    /* 0x38 */ Model *model;
    /* 0x3c */ s32 x;
    /* 0x40 */ s32 y;
    /* 0x44 */ s32 z;
    /* 0x48 */ u8 alpha;
    /* 0x49 */ u8 maxAlpha;
};

// Photo node (0x50 bytes, vtable Ov002Vt_021f0ebc_vtbl over the model node's; entry kind 6).
struct Ov002StaffPhoto : public Ov002StaffModel {
    /* 0x4c */ void *photo; // built by Twl0214b6d8_Init (0x3c bytes)
};

typedef struct Ov002StaffLine {
    /* 0x00 */ Ov002Text2 *text;
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0c */ s32 z;
} Ov002StaffLine;

// Text node (0x58 bytes, vtable Ov002Vt_021f0e84_vtbl; entry kind 4). A '/' in the entry's string
// splits it into a second line.
struct Ov002StaffText : public Ov002StaffNode {
    /* 0x34 */ Ov002StaffLine line[2];
    /* 0x54 */ u8 alpha;
};

// Sound node (0x34 bytes, vtable Ov002Vt_021f0e14_vtbl; entry kind 7): the base node.

// The script file handle (0x50 bytes, vtable Ov002Vt_021f0f2c_vtbl over ResHandle_vtbl).
struct Ov002StaffLoader : public Ov002StaffRes {
    /* 0x4c */ Ov002StaffScript *script;
};

// The staff object (0x30 bytes, Ov002Staff_Create).
typedef struct Ov002Staff {
    /* 0x00 */ s32 id; // picks the script file
    /* 0x04 */ Ov002StaffClock clock;
    /* 0x20 */ s32 nextStep; // clock step for the next frame
    /* 0x24 */ Ov002StaffLoader *loader;
    /* 0x28 */ Ov002StaffText *text; // the text node that updated last
    /* 0x2c */ u16 spawned; // entries turned into nodes so far
} Ov002Staff;

extern "C" {

// The run list's head and tail and the staff object (data_ov002_021f0fa0 / 021f0fa8 / 021f0fa4)
// are defined in ov002_021ecb90.cpp next to their users.
extern Ov002StaffNode *data_ov002_021f0fac[9];

void func_ov002_021eea74(Ov002Staff *self);

}

#endif
