#ifndef OV000_MENUTASK_H
#define OV000_MENUTASK_H

// The menu task classes of Menu_021763c8.cpp. Each derives from the task base (ov000/TaskList.h);
// the class name is its vtable, the size the allocation in its <Class>_New. The vtables share the
// base slots (0x08..0x0c, 0x1c..0x54, 0x60, 0x68); slot 0x58 (Init) is called by New after each
// vtable store and clears the class's fields, slot 0x5c (Release) is called by the Dtor at each
// level and frees what the task owns. Slot 0x18 builds the task's windows and links the task
// (TaskList_Insert). Fields are named by offset unless the code shows what they hold. The task kind
// is the index of the class's New in the creator table Task_NewTable (LoSwitchTaskC, LoFindTask).

#include "ov000/TaskList.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"

struct GameSave;
struct GameSave0208c994;

// Vtable Task021cbae0_vtbl, task kind 0x9 (Task_NewTable[0x9] is its New), 0x58 bytes.
class Task021cbae0 : public Task {
public:
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    VObj *unk_48;
    Model *unk_4c;
    VObj *unk_50;
    Model *unk_54;
};
SIZE_ASSERT(Task021cbae0, 0x58);

// Vtable Task021cbb60_vtbl, task kind 0x8 (Task_NewTable[0x8] is its New), 0xc4 bytes.
class Task021cbb60 : public Task {
public:
    VObj *unk_3c;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    GameSave *unk_5c; // save object (data_ov000_021ccd4c)
    GameSave0208c994 *unk_60;
    Lo021cad50 *unk_64; // message window (Task021cbb60_ShowMsg)
    s32 unk_68; // frames before the message window can be closed
    void *unk_6c;
    u8 unk_70;
    u8 unk_71;
    u8 unk_72[0x2];
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    Model *unk_a0;
    s32 unk_a4;
    u8 unk_a8[0x10];
    s16 unk_b8;
    s16 unk_ba;
    void (*unk_bc)(void *self, void *arg); // called with unk_c0 when the task closes (Task021cbb60_PostUpdate)
    void *unk_c0;
};
SIZE_ASSERT(Task021cbb60, 0xc4);

// Vtable PauseMenu_vtbl, task kind 0x2 (Task_NewTable[0x2] is its New), 0x4b0 bytes. 0x60..0x4b0 holds six text windows of 0xb8 bytes
// (vtable TextWin_vtbl, reset by the Dtor); unk_a4 is the first one's TextWin::width.
class Task021cbbe0 : public Task {
public:
    s32 unk_3c;
    UiList *unk_40;
    Lo021cb5a8 *unk_44;
    UiObj *unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    Model *unk_58;
    Model *unk_5c;
    u8 unk_60[0x44];
    s32 unk_a4;
    u8 unk_a8[0x408];
};
SIZE_ASSERT(Task021cbbe0, 0x4b0);

// Vtable Task021cbc60_vtbl, task kind 0x7 (Task_NewTable[0x7] is its New), 0x50 bytes.
class Task021cbc60 : public Task {
public:
    s32 unk_3c;
    s32 unk_40;
    GameSave *unk_44; // save object (data_ov000_021ccd4c)
    Lo021cad50 *unk_48;
    s32 unk_4c;
};
SIZE_ASSERT(Task021cbc60, 0x50);

// Vtable Task021cbce0_vtbl, task kind 0x1 (Task_NewTable[0x1] is its New), 0x90 bytes.
class Task021cbce0 : public Task {
public:
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    u32 unk_48;
    Model *unk_4c;
    MtxFx44 unk_50;
};
SIZE_ASSERT(Task021cbce0, 0x90);

// Vtable ObjectiveMenu_vtbl, task kind 0x6 (Task_NewTable[0x6] is its New), 0x48 bytes.
class Task021cbd60 : public Task {
public:
    VObj *unk_3c;
    Lo021cadcc *unk_40;
    Lo021cb5a8 *unk_44;
};
SIZE_ASSERT(Task021cbd60, 0x48);

// Vtable HelpMenu_vtbl, task kind 0x5 (Task_NewTable[0x5] is its New), 0x54 bytes.
class Task021cbde0 : public Task {
public:
    VObj *unk_3c;
    Lo021cb5a8 *unk_40;
    LoBase021ccb54_021ccbe0 *unk_44;
    s32 unk_48;
    u16 unk_4c;
    u8 unk_4e[0x2];
    VObj *unk_50;
};
SIZE_ASSERT(Task021cbde0, 0x54);

// Vtable SellMenu_vtbl, task kind 0xa (Task_NewTable[0xa] is its New), 0x158 bytes.
class Task021cbe60 : public Task {
public:
    UiList021cb4a8 *unk_3c;
    Lo021cadcc *unk_40;
    Lo021cae48 *unk_44;
    Lo021cae48 *unk_48;
    Lo021cae48 *unk_4c;
    Lo021cb5a8 *unk_50;
    Lo021cacd8 *unk_54;
    u8 unk_58[0x100]; // text buffer, filled by Param_FormatName(0x100, ...)
};
SIZE_ASSERT(Task021cbe60, 0x158);

// Vtable StoreMenu_vtbl, task kind 0x4 (Task_NewTable[0x4] is its New), 0x15c bytes.
class Task021cbee0 : public Task {
public:
    Lo021cb5a8 *unk_3c;
    Lo021cae48 *unk_40;
    Lo021cae48 *unk_44;
    Lo021cae48 *unk_48;
    UiList021cb4a8 *unk_4c;
    Lo021cadcc *unk_50;
    s32 unk_54;
    Lo021cad50 *unk_58; // message window (vtable Lo021cad50_vtbl)
    u8 unk_5c[0x100]; // text buffer, filled by Param_FormatName(0x100, ...)
};
SIZE_ASSERT(Task021cbee0, 0x15c);

// Vtable DiscardMenu_vtbl, task kind 0xc (Task_NewTable[0xc] is its New), 0x160 bytes.
class Task021cbf60 : public Task {
public:
    UiList021cb4a8 *unk_3c;
    Lo021cadcc *unk_40;
    LoBase021cafc0_021cb0b8 *unk_44;
    Lo021cb5a8 *unk_48;
    Model *unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    u16 unk_5c;
    u8 unk_5e;
    u8 unk_5f[0x100]; // text buffer, filled by Param_FormatName(0x100, ...)
    u8 unk_15f;
};
SIZE_ASSERT(Task021cbf60, 0x160);

// Vtable Task021cbfe0_vtbl, task kind 0x3 (Task_NewTable[0x3] is its New), 0x48 bytes.
class Task021cbfe0 : public Task {
public:
    VObj *unk_3c;
    VObj *unk_40;
    u16 unk_44; // set from the closing message (func_ov000_02175e6c)
    u8 unk_46[0x2];
};
SIZE_ASSERT(Task021cbfe0, 0x48);

#endif
