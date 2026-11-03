#ifndef OV002_OV002TASK_H
#define OV002_OV002TASK_H

// The ov002 task classes. Each derives from the ov000 task base (ov000/Task.h); the class name is its
// vtable, the size the allocation in its New. All share the base slots of Task_vtbl and the
// ov002 slots 0x1c (Ov002Task_IsReady), 0x20..0x44 (Ov002Task_SetFlag4 .. Ov002Task_TestFlags) and
// 0x48..0x54, which only touch the base. Slot 0x18 (Start) builds the task's windows; the window members
// are typed by the vtable their constructor stores (ov000/UiObj.h, ov000/ObjLayouts.h). Fields are named
// by offset unless the code shows what they hold.

#include "ov000/Task.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"
#include "ov002/ObjLayouts.h"

#ifdef __cplusplus

struct Model;

// Vtable Ov002TaskVt_021ef430_vtbl, 0x50 bytes.
class Task021ef430 : public Task {
public:
    Model *unk_3c;
    void *unk_40;
    void *unk_44;
    s32 unk_48;
    u8 unk_4c;
    u8 unk_4d;
    s8 unk_4e; // load state (Task021ef430_PreUpdate)
    u8 unk_4f;
};
SIZE_ASSERT(Task021ef430, 0x50);

// Vtable Ov002TaskVt_021ef4b0_vtbl, 0x4c bytes.
class Task021ef4b0 : public Task {
public:
    UiList *unk_3c;
    Lo021cadcc *unk_40;
    u32 unk_44; // current list item id (Task021ef4b0_UpdateActive)
    union {
        u32 unk_48;
        struct {
            u32 unk_48_0 : 1; // set by func_ov002_021ce7b8, each enables one list entry
            u32 unk_48_1 : 1;
            u32 unk_48_2 : 1;
            u32 unk_48_3 : 1;
            u32 unk_48_4 : 1;
            u32 unk_48_5 : 1;
            u32 unk_48_6 : 1;
            u32 unk_48_7 : 25;
        };
    };
};
SIZE_ASSERT(Task021ef4b0, 0x4c);

// Vtable Ov002TaskVt_021ef530_vtbl, 0x50 bytes (Task021ef530_New); its own Init (0x58) and Release (0x5c).
class Task021ef530 : public Task {
public:
    Model *unk_3c;
    UiList *unk_40;
    Lo021cadcc *unk_44;
    union {
        s32 unk_48;
        struct {
            u32 unk_48_0 : 1;
            u32 unk_48_1 : 1;
            u32 unk_48_2 : 1;
            u32 unk_48_3 : 29;
        };
    };
    s8 unk_4c;
    s8 unk_4d;
    u8 unk_4e[0x2];
};
SIZE_ASSERT(Task021ef530, 0x50);

// Vtable Ov002TaskVt_021ef69c_vtbl, 0x68 bytes.
class Task021ef69c : public Task {
public:
    TextList *unk_3c;
    Lo021cb5a8 *unk_40;
    ListRow021cca70 *unk_44; // the decided row while it is raised (Task021ef69c_List3cOnDecide)
    Model *unk_48; // number drawing (func_ov002_021d1f70)
    Model *unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
};
SIZE_ASSERT(Task021ef69c, 0x68);

// Vtable Ov002TaskVt_021ef71c_vtbl, 0x70 bytes.
class Task021ef71c : public Task {
public:
    u8 unk_3c[0x20];
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    u8 unk_68;
    u8 unk_69;
    u8 unk_6a[0x2];
    u32 unk_6c; // list item of task 0x12 (Task021ef4b0::unk_44), kept while its windows are freed
};
SIZE_ASSERT(Task021ef71c, 0x70);

// Vtable Ov002TaskVt_021ef79c_vtbl, 0x48 bytes.
class Task021ef79c : public Task {
public:
    UiList *unk_3c;
    Lo021cadcc *unk_40;
    u16 unk_44;
    u8 unk_46[0x2];
};
SIZE_ASSERT(Task021ef79c, 0x48);

// Vtable Ov002TaskVt_021ef81c_vtbl, 0x50 bytes.
class Task021ef81c : public Task {
public:
    UiList021cb4a8 *unk_3c;
    Lo021cadcc *unk_40;
    Lo021cae48 *unk_44;
    Lo021cb5a8 *unk_48;
    u8 unk_4c; // set while unk_40 shows the row's message (Task021ef81c_List3cOnCursor)
    u8 unk_4d[0x3];
};
SIZE_ASSERT(Task021ef81c, 0x50);

// Vtable Ov002TaskVt_021ef89c_vtbl, 0x44 bytes.
class Task021ef89c : public Task {
public:
    Ov002RowList *unk_3c;
    Lo021cb5a8 *unk_40;
};
SIZE_ASSERT(Task021ef89c, 0x44);

// Level table read from a data file (0x18 bytes, vtable Ov002Vt_021f00fc_vtbl; ctor
// Ov002LevelTable_Ctor, load Ov002LevelTable_Load, clear func_ov002_021e4904). The file holds a
// count, `count` thresholds and two strings; Ov002LevelTable_GetLevel gives the level of a value.
struct Ov002LevelTable : public VObj {
    /* 0x04 */ u8 *src; // the file data
    /* 0x08 */ u32 count;
    /* 0x0c */ s32 *thresholds; // heap copy
    /* 0x10 */ char *label; // in the file; the list row's text
    /* 0x14 */ char *desc; // in the file; shown when the row is selected
};
SIZE_ASSERT(Ov002LevelTable, 0x18);

// One string pair of an Ov002StrTable (0xc bytes).
typedef struct Ov002StrPair {
    /* 0x00 */ u16 index;
    /* 0x04 */ char *label; // in the file
    /* 0x08 */ char *desc; // in the file
} Ov002StrPair;

// String-pair table read from a data file (0x10 bytes, vtable Ov002Vt_021f00ec_vtbl; ctor
// Ov002StrTable_Ctor, load Ov002StrTable_Load, clear Ov002StrTable_Clear).
struct Ov002StrTable : public VObj {
    /* 0x04 */ u8 *src; // the file data
    /* 0x08 */ u32 count;
    /* 0x0c */ Ov002StrPair *pairs; // heap array
};
SIZE_ASSERT(Ov002StrTable, 0x10);

// Vtable Ov002TaskVt_021ef91c_vtbl, 0xd0 bytes.
class Task021ef91c : public Task {
public:
    TextList *unk_3c;
    Lo021cb5a8 *unk_40;
    char unk_44[0x20];
    char unk_64[0x18];
    char unk_7c[0x18];
    Ov002LevelTable unk_94;
    Ov002StrTable unk_ac;
    s32 unk_bc;
    s32 unk_c0;
    Model *unk_c4;
    VObj *unk_c8;
    s32 unk_cc;
};
SIZE_ASSERT(Task021ef91c, 0xd0);

// Vtable Ov002TaskVt_021ef99c_vtbl, 0x118 bytes.
class Task021ef99c : public Task {
public:
    Ov002RowList *unk_3c;
    Lo021cadcc *unk_40;
    Lo021cb5a8 *unk_44;
    UiObj *unk_48; // vtable Lo021cad50_vtbl (0xe8 bytes)
    Ov002LevelTable unk_4c[7];
    char unk_f4[0x20];
    u8 unk_114;
};
SIZE_ASSERT(Task021ef99c, 0x118);

// Vtable Ov002TaskVt_021efa1c_vtbl, 0x44 bytes.
class Task021efa1c : public Task {
public:
    Ov002RowList *unk_3c;
    Lo021cb5a8 *unk_40;
};
SIZE_ASSERT(Task021efa1c, 0x44);

// Vtable Ov002TaskVt_021efb24_vtbl, 0x3c bytes (no fields of its own).
class Task021efb24 : public Task {
};
SIZE_ASSERT(Task021efb24, 0x3c);

// Vtable Ov002TaskVt_021efba4_vtbl, 0x40 bytes.
class Task021efba4 : public Task {
public:
    struct Ov002Hud *hud; // built by Task021efba4_Start (ov002/ObjLayouts.h)
};
SIZE_ASSERT(Task021efba4, 0x40);

// Vtable Ov002TaskVt_021efc24_vtbl, 0x78 bytes.
class Task021efc24 : public Task {
public:
    Model *unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    Lo021cadcc *unk_4c;
    UiList *unk_50; // vtable Ov002Vt_021efca4_vtbl
    Lo021cadcc *unk_54;
    VObj *unk_58;
    VObj *unk_5c;
    s16 unk_60[5]; // per-stat values; func_ov002_021d5f60 stores unk_60[i] + unk_6a[i], clamped to 0..99
    s16 unk_6a[5];
    u16 unk_74;    // id of the current list item
    u8 unk_76[0x2];
};
SIZE_ASSERT(Task021efc24, 0x78);

#endif

#endif
