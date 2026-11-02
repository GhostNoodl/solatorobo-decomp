#ifndef OV002_OBJLAYOUTS_H
#define OV002_OBJLAYOUTS_H

// Layouts of ov002 objects with their own vtables (named by vtable, sized by their allocation).
// Slot 0x08 starts the object, 0x0c updates it, 0x10 draws it. Fields are named by offset; only
// fields that some method reads or writes are declared, window members are typed by the vtable
// their constructor stores (ov000/UiObj.h, ov000/ObjLayouts.h).

#include "types.h"
#include "ov000/VObj.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/Model.h"
#include "Main/Effect/Effect.h"

#ifdef __cplusplus

// ov002's row list (vtable data_ov002_021f0044 over ov000's LoBase021ccb54_021ccbe0, the same 0xf4
// bytes). onDecide is func_ov002_021d2410 and onCursor func_ov002_021d2390 for the level list.
struct Ov002RowList : public LoBase021ccb54_021ccbe0 {
};
SIZE_ASSERT(Ov002RowList, 0xf4);

// Text list (0xd4 bytes; vtable data_ov000_021ccadc, init func_ov000_021c6140; rows are appended by
// List021c6474_Append). onDecide gets the chosen row (func_ov002_021d18e8), onCursor the row under
// the cursor (func_ov002_021d18d4).
struct Ov002TextList : public UiObj {
    ListRow *unk_84; // the first row (List021c6474_Append appends)
    ListRow *unk_88; // the row under the cursor; Task021ef69c_Start's rows are ListRow021cca70s
    u8 unk_8c[0x8];
    s32 unk_94;   // index of the row under the cursor (Task021ef91c_PostUpdate)
    u8 unk_98[0xc];
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x18];
    union {
        u32 unk_c4;
        struct {
            s32 unk_c4_0 : 1;
            u32 unk_c4_1 : 1;
            u32 unk_c4_2 : 30;
        };
    };
    void *onDecide;
    void *onCursor;
    s32 unk_d0;
};
SIZE_ASSERT(Ov002TextList, 0xd4);

// Animated model (0x70, vtable data_ov002_021efe3c; Ov002Vt_021efe3c_Ctor, Ov002Vt_021efe3c_Dtor).
// Ov002Mdl021efe3c_Load loads model file `name` and animation file `anmName` from archive `arc`;
// each animation is bound to the render object, and frameCount is the first one's length.
// The owners step frame by 0x1000 each tick (Obj021efe8c_SyncAnmFrame) and draw renderObj at
// trans/scale/rot once the texture upload `texTask` is done.
struct Ov002Mdl021efe3c : public VObj {
    const char *arc;
    const char *name;
    const char *anmName;
    EffectFile *file;           // the model file (Vram_FreeRes releases it)
    NNSG3dResMdl *mdl;
    NNSG3dRenderObj *renderObj; // Heap_Alloc, freed on the alternate heap
    u32 texTask;                // texture upload (func_0203ebf8 / Vram_IsTransferDone)
    NNSG3dAnmObj *anm[3];       // Heap_AllocHi
    s32 frame;
    s32 frameCount;
    VecFx32 trans;
    VecFx32 scale;              // 0x1000 after the ctor
    MtxFx33 rot;                // identity after the ctor
};
SIZE_ASSERT(Ov002Mdl021efe3c, 0x70);

// Board cursor (0x8c, vtable data_ov002_021efe8c): an Ov002Mdl021efe3c placed on the map cell
// unk_74/unk_78 (Ov002_CellXZToPos), with the map size at unk_7c/unk_80 and its height at unk_84.
// mode selects the model (0 or 1).
struct Obj021efe8c : public VObj {
    Ov002Mdl021efe3c mdl;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    u8 mode;
    u8 unk_89;
    u16 unk_8a;
};
SIZE_ASSERT(Obj021efe8c, 0x8c);

// Vtable data_ov002_021efe5c, 0x1e8 bytes: an Ov002Mdl021efe3c and a 2D Model drawn over it
// (func_ov002_021d7988). unk_1d8 counts ticks (Obj021efe5c_SyncAnmFrame).
struct Obj021efe5c : public VObj {
    Ov002Mdl021efe3c mdl;
    Model model;
    u8 unk_1d4;
    u8 unk_1d5[3];
    u32 unk_1d8;
    VecFx32 pos;
};
SIZE_ASSERT(Obj021efe5c, 0x1e8);

// Camera position block (0x24, GfxCamPos_Init).
typedef struct Ov002CamPos {
    VecFx32 eye;
    VecFx32 at;
    VecFx32 up;
} Ov002CamPos;

// Board shape (8 bytes): a grid of w x h cells (grid[y * w + x]), its origin cell (ox, oy) and its
// rotation. func_02070dcc returns the shape of a kind (Main's StageFlags_3 reads it the same way).
typedef struct Ov002Shape {
    u8 *grid;
    u16 unk_4 : 8;
    u16 w : 4;
    u16 h : 4;
    u16 ox : 4;
    u16 oy : 4;
    u16 rot : 2;
    u16 unk_6_10 : 6;
} Ov002Shape;

// Vtable data_ov002_021efeb8, the base of 021efe9c and 021efed4 (slot 0x08 func_ov002_021d7c04
// fills 0x48..0x5c from the id at 0x48: kind, shape and its origin). The board (Obj021efe6c)
// keeps its pieces in a list through next/prev.
struct Obj021efeb8 : public VObj {
    VecFx32 trans; // from the cell unk_54/unk_58 (Ov002_CellToPos)
    s16 unk_10;
    u16 unk_12;
    s16 unk_14;
    u8 unk_16[0x2];
    MtxFx33 rot;
    VecFx32 scale;
    u16 unk_48;
    u8 unk_4a;
    u8 unk_4b;
    Ov002Shape shape;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c[2];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c;
    u8 unk_6d[0x3];
    struct Obj021efeb8 *next;
    struct Obj021efeb8 *prev;
    u32 *unk_78;                 // resource handle: *unk_78 is the model file
    NNSG3dResMdl *unk_7c;        // the model in that file
    NNSG3dRenderObj *unk_80;     // Heap_Alloc
    u32 unk_84;                  // texture upload (func_0203ebf8 / Vram_IsTransferDone)
    NNSG3dAnmObj *unk_88;        // Heap_AllocHi
    NNSG3dAnmObj *unk_8c;
    void *unk_90;                // an animation object (021efe9c) or a Model (021efed4)
};

// A board cell (0xc): the piece covering it (NULL and id 0xffff when empty).
typedef struct Ov002Cell {
    u16 id;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5[3];
    Obj021efeb8 *obj;
} Ov002Cell;

// Sound cue of the field animation (6 bytes; table data_ov002_021eeffc, ended by a negative time):
// func_ov002_021d7320 plays sound id when the animation frame passes time.
typedef struct Ov002SndCue {
    s16 time;
    s16 unk_02;
    u16 id;
} Ov002SndCue;

// Vtable data_ov002_021efe4c, 0x70 bytes (ctor Obj021efe4c_Init, dtor Obj021efe4c_Release): the
// board's field. func_ov002_021d7238 sets map to the shape of field id unk_68. func_ov002_021d7058
// builds the two models unk_08/unk_10 from the resource blocks unk_0c/unk_14; Obj021efe7c_Draw
// copies trans, rot and scale into both before drawing them while visible is set.
struct Obj021efe4c : public VObj {
    ActorRes *unk_04;       // dtor ResSet_ReleaseAll
    Model0218fe1c *unk_08;  // dtor Model0218fe1c_FreeAnims
    ActorRes *unk_0c;
    Model0218fe1c *unk_10;
    ActorRes *unk_14;
    VecFx32 trans;
    s16 unk_24;
    s16 unk_26;
    s16 unk_28;
    u8 unk_2a[0x2];
    MtxFx33 rot;            // identity after the ctor
    VecFx32 scale;          // 0x1000 after the ctor
    u8 visible;
    u8 unk_5d;              // set: the cues are played forward (func_ov002_021d7320)
    u8 unk_5e[0x2];
    Ov002SndCue *cues;      // data_ov002_021eeffc
    Ov002SndCue *cue;       // next cue for the animation frame
    u16 unk_68;
    u8 unk_6a[0x2];
    Ov002Shape *map;
};
SIZE_ASSERT(Obj021efe4c, 0x70);

// Vtable data_ov002_021efe6c, 0xc8 bytes (ctor Obj021efe6c_Init): the board. pieces heads the
// piece list, cells is the field's w x h cell array (func_ov002_021da054), unk_08 counts per item id.
// unk_90.. move the camera from unk_98/unk_a4 to unk_b0/unk_bc.
struct Obj021efe6c : public VObj {
    Obj021efe4c *field;
    u8 unk_08[0x64];
    Obj021efeb8 *pieces;
    Ov002Cell *cells;
    u8 unk_74;
    u8 unk_75;
    u8 unk_76[0xa];
    u8 unk_80[0xa];
    s16 unk_8a;
    struct Ov002CamPos *cam;
    s32 unk_90;
    s32 unk_94;
    VecFx32 unk_98;
    VecFx32 unk_a4;
    VecFx32 unk_b0;
    VecFx32 unk_bc;
};
SIZE_ASSERT(Obj021efe6c, 0xc8);

// Vtable data_ov002_021efe7c, 0x14 bytes (Obj021efe7c_Create, kept in data_ov002_021f0f90[1]):
// the board and its current mode object (func_ov002_021dab58 builds mode unk_0c: 021eff74, 021eff50, ...).
struct Obj021efe7c : public VObj {
    Obj021efe6c *board;
    VObj *unk_08;
    s32 unk_0c;
    u8 unk_10;
    u8 unk_11[0x3];
};
SIZE_ASSERT(Obj021efe7c, 0x14);

// Vtable data_ov002_021efe9c, 0xd4 bytes.
struct Obj021efe9c : public Obj021efeb8 {
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    VecFx32 unk_b0;
    VecFx32 unk_bc;
    s32 unk_c8;
    u8 unk_cc;
    u8 unk_cd;
    u8 unk_ce[0x2];
    s32 unk_d0;
};
SIZE_ASSERT(Obj021efe9c, 0xd4);

// Vtable data_ov002_021efed4, 0xb4 bytes.
struct Obj021efed4 : public Obj021efeb8 {
    u8 unk_94;
    u8 unk_95[0x3];
    s32 unk_98;
    u8 unk_9c;
    u8 unk_9d[0x3];
    s32 unk_a0;
    s32 unk_a4;
    u16 unk_a8;
    u8 unk_aa[0x2];
    s32 unk_ac;
    void *unk_b0;
};
SIZE_ASSERT(Obj021efed4, 0xb4);

// Vtable data_ov002_021efef0, 0x138 bytes.
struct Obj021efef0 : public VObj {
    struct Obj021eff50 *owner;
    Ov002RowList *unk_08; // vtable data_ov002_021f0044
    Ov002RowList *unk_0c; // vtable data_ov002_021f0044 (func_ov002_021def98)
    Obj021efe8c *unk_10;
    Obj021efe8c *unk_14;
    u16 unk_18;
    u8 unk_1a[0x2];
    s32 unk_1c;
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    u8 unk_38[0x100];
};
SIZE_ASSERT(Obj021efef0, 0x138);

// Vtable data_ov002_021eff10, 0x134 bytes.
struct Obj021eff10 : public VObj {
    struct Obj021eff50 *owner;
    Obj021efe5c *unk_08;
    LoBase021cafc0_021cb0b8 *unk_0c; // vtable data_ov000_021cb0b8
    Model *unk_10;
    Obj021efe8c *unk_14;
    s32 unk_18;
    s32 unk_1c;
    u8 unk_20;
    u8 unk_21[0x3];
    s32 unk_24;
    s32 unk_28;
    Obj021efed4 *unk_2c; // piece on a kind 2 cell
    Obj021efe9c *unk_30; // piece on a kind 1 cell
    u8 unk_34[0x100];
};
SIZE_ASSERT(Obj021eff10, 0x134);

// Vtable data_ov002_021eff30, 0x30 bytes.
struct Obj021eff30 : public VObj {
    struct Obj021eff50 *owner;
    s32 unk_08;
    Obj021efe5c *unk_0c;
    Obj021efe9c *unk_10;
    Obj021efe8c *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c;
    u8 unk_2d[0x3];
};
SIZE_ASSERT(Obj021eff30, 0x30);

// Vtable data_ov002_021eff50, 0x38 bytes.
struct Obj021eff50 : public VObj {
    Obj021efe6c *board;
    s32 unk_08;
    s32 unk_0c;
    VObj *unk_10;
    s32 unk_14;
    VObj *unk_18;
    s32 unk_1c;
    Lo021cadcc *unk_20;
    Lo021cae48 *unk_24;
    s32 unk_28;
    s32 unk_2c;
    u16 unk_30;
    u8 unk_32[0x2];
    s32 unk_34;
};
SIZE_ASSERT(Obj021eff50, 0x38);

// Vtable data_ov002_021eff74, 0x24 bytes.
struct Obj021eff74 : public VObj {
    Obj021efe6c *board;
    s32 unk_08;
    UiList *unk_0c;
    Lo021cadcc *unk_10;
    s32 unk_14;
    s32 unk_18;
    u32 unk_1c;
    u8 unk_20;
    u8 unk_21[0x3];
};
SIZE_ASSERT(Obj021eff74, 0x24);

// Text window as ov002 uses it (vtable data_0208ba70, TextWin_Init; 0xb8 bytes). It is the
// object TextWin (Main/Gfx/TextWin.h) describes; this view keeps width and height signed, as
// Text_Measure writes them and func_ov002_021ed270 and Ov002HudInfo_Draw halve them.
struct Ov002Text2 : public VObj {
    union {
        u32 flags;
        struct {
            u32 unk_4_0 : 2;
            u32 unk_4_2 : 1;
            u32 unk_4_3 : 5;
            u32 alpha : 5;
            u32 polyId : 8;
            u32 unk_4_21 : 11;
        };
    };
    u8 pad08[0x1c];
    s32 str;
    s32 font;
    s32 unk_2c;
    u8 pad30[0x4];
    s16 unk_34;
    u8 pad36;
    s8 unk_37;
    s32 spacing;
    u8 pad3c[0x8];
    s32 width;
    s32 height;
    s32 unk_4c;
    u8 pad50[0x20];
    s32 posZ;
    u16 color0;
    u16 color1;
    s32 unk_78;
};

// The rows of ov000's row lists are ov000/ListRow.h's ListRow classes; ov002 builds them over its own
// copy of the row base vtable, data_ov002_021ef684.

// Board item row (vtable data_ov002_021f002c, 0x4c bytes; ctor Obj021f002c_Init, dtors
// Ov002Vt_021f002c_Dtor/DtorDelete). Slot 0x08 (func_ov002_021e2fb4) steps state: 0 builds the
// item model (when hasModel is set) and the name text, 1 frees them once the row is hidden, 2 waits
// to be shown again. Slot 0x0c (func_ov002_021e31fc) draws both at the row's position.
struct Obj021f002c : public ListRow {
    Model *model;
    Ov002Text2 *text; // Obj021f002c_CreateText builds it from str
    u16 id;           // item id (0xffff: none)
    u16 part;         // model part shown (the shape's unk_4 of the item)
    void *str;    // name text (a string)
    void *unk_40; // description text (a string)
    u8 unk_44;
    u8 hasModel;
    u8 unk_46[0x2];
    s32 state;
};
SIZE_ASSERT(Obj021f002c, 0x4c);

// Caption of the board HUD (vtable data_ov002_021f001c, 0x38 bytes): a text window that
// Ov002Caption_Update slides from (fromX, fromY) to (toX, toY) while timer counts down from 8.
// Mode 3 slides it out, swaps in text and slides back to (nextX, nextY).
struct Ov002Caption : public VObj {
    /* 0x04 */ Ov002Text2 *anim;
    /* 0x08 */ s32 text; // string shown once the slide-out ends (a const char *)
    /* 0x0c */ s32 x;
    /* 0x10 */ s32 y;
    /* 0x14 */ s32 nextX;
    /* 0x18 */ s32 nextY;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 fromX;
    /* 0x24 */ s32 fromY;
    /* 0x28 */ s32 toX;
    /* 0x2c */ s32 toY;
    /* 0x30 */ s32 timer;
    /* 0x34 */ u8 mode;
    /* 0x35 */ u8 unk_35[3];
};
SIZE_ASSERT(Ov002Caption, 0x38);

// Info box of the board HUD (vtable data_ov002_021f000c, 0x2c bytes; built by
// Ov002Hud_SetInfo). Ov002HudInfo_SetId fills its texts for id, Ov002HudInfo_Draw draws it.
struct Ov002HudInfo : public VObj {
    /* 0x04 */ Ov002Text2 *unk_04;
    /* 0x08 */ Ov002Text2 *lines[4]; // filled in order by Ov002HudInfo_SetId
    /* 0x18 */ VecFx32 pos; // fx32 screen position
    /* 0x24 */ u16 id; // requested id (0xffff: none)
    /* 0x26 */ u16 shownId; // id the texts were last built for
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 delay; // frames left before the texts are drawn
    /* 0x2a */ u8 unk_2a[2];
};
SIZE_ASSERT(Ov002HudInfo, 0x2c);

// Board HUD of Task021efba4 (vtable data_ov002_021efb14, 0x44 bytes). Ov002Hud_Init clears
// it, Ov002Hud_Load builds its models and captions, Ov002Hud_Release frees them.
struct Ov002Hud : public VObj {
    /* 0x04 */ Model *unk_04;
    /* 0x08 */ Model *unk_08;
    /* 0x0c */ Model *unk_0c;
    /* 0x10 */ Model *unk_10;
    /* 0x14 */ Ov002Caption *captions[5];
    /* 0x28 */ Ov002HudInfo *info;
    /* 0x2c */ s16 unk_2c[2][5]; // func_ov002_021e28b0 draws unk_2c[0][i] + unk_2c[1][i], clamped to 0..99
    /* 0x40 */ u8 row; // row of data_ov002_021ef058 the captions show
    /* 0x41 */ u8 pending; // bit n: model n (unk_04..unk_10) still waits on Model_IsReady
    /* 0x42 */ u8 unk_42[2];
};
SIZE_ASSERT(Ov002Hud, 0x44);

#endif

#endif
