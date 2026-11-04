#include "Main/Res/StageCmd.h"

extern "C" {

extern u8 *Param_GetEntry(u16 id);

#define STAGE_ITEM_NONE 0xffff

typedef struct StageItemShape {
    /* 0x0 */ u8 *grid;
    /* 0x4 */ u16 unk_4 : 8;
    /* 0x4 */ u16 w : 4;
    /* 0x4 */ u16 h : 4;
    /* 0x6 */ u16 ox : 4;
    /* 0x6 */ u16 oy : 4;
    /* 0x6 */ u16 rot : 2;
    /* 0x6 */ u16 unk_6_10 : 6;
} StageItemShape;

typedef struct StageItemPos {
    s32 x;
    s32 y;
} StageItemPos;

extern u8 *Param_GetSlotInfo(u16 id);
extern StageItemShape *ParamKind_GetShape(int kind);
extern int Ov002Shape_FitInMap(StageItemPos *pos, StageItemShape *a, StageItemShape *b, StageItemPos *out);
extern BOOL StageFlags_AddEntry(StageFlags *f, u16 id, u8 x, u8 y, u8 rot, int used);
extern s32 StageFlags_AddItem(StageFlags *f, u16 id, u32 n);
u16 StageFlags_CountItems(StageFlags *f);

static inline void StageFlags_ClearEntries(StageFlags *f) {
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        f->entries[i].id = STAGE_ITEM_NONE;
        f->entries[i].info = 0;
    }
}

static inline BOOL StageFlags_TestCell(StageFlags *f, StageItemShape *shape, u8 x, u8 y) {
    s32 bx = x + (3 - shape->ox);
    s32 by = y + (3 - shape->oy);
    return f->bits[by] & (1 << bx);
}

void StageFlags_SetShape(StageFlags *f, u16 id) {
    StageItemShape *shape;
    u8 *grid;
    u16 w;
    u16 h;
    u16 y;
    u16 x;
    StageFlags_ClearEntries(f);
    shape = ParamKind_GetShape((s8)Param_GetSlotInfo(id)[1]);
    grid = shape->grid;
    w = shape->w;
    h = shape->h;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            u8 c = grid[y * h + x];
            u16 item;
            if (c == 1 || c == 2 || c == 0) {
                continue;
            }
            if (StageFlags_TestCell(f, shape, x, y)) {
                continue;
            }
            switch (c) {
            case 0x80:
                item = 0x204f;
                break;
            case 0x81:
                item = 0x2050;
                break;
            case 0x82:
                item = 0x2051;
                break;
            case 0x83:
                item = 0x2052;
                break;
            default:
                item = STAGE_ITEM_NONE;
                break;
            }
            StageFlags_AddEntry(gStageFlags, item, x, y, 0, 0);
        }
    }
    f->shapeId = id;
}

void StageFlags_ChangeShape(StageFlags *f, u16 id) {
    StageItemEntry entries[STAGE_ITEM_ENTRY_MAX];
    StageItemPos pos;
    StageItemShape shape;
    StageItemShape *oldShape;
    StageItemShape *newShape;
    s32 i;
    oldShape = ParamKind_GetShape(Param_GetSlotInfo(f->shapeId)[0]);
    newShape = ParamKind_GetShape(Param_GetSlotInfo(id)[0]);
    MI_CpuCopy8(f->entries, entries, sizeof(entries));
    StageFlags_SetShape(f, id);
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        StageItemEntry *e = &entries[i];
        u8 *info = Param_GetEntry(e->id);
        if (e->id != STAGE_ITEM_NONE && info[0] != 0x80) {
            BOOL used;
            pos.x = newShape->ox - oldShape->ox + e->bits.a;
            pos.y = newShape->oy - oldShape->oy + e->bits.b;
            MI_CpuCopy8(ParamKind_GetShape(info[1]), &shape, sizeof(shape));
            shape.rot = e->bits.c;
            used = e->bits.used ? TRUE : FALSE;
            if (Ov002Shape_FitInMap(&pos, newShape, &shape, NULL) == 0) {
                StageFlags_AddEntry(gStageFlags, e->id, pos.x, pos.y, shape.rot, used);
            } else if (!used) {
                StageFlags_AddItem(gStageFlags, e->id, 1);
            }
        }
    }
    StageFlags_CountItems(f);
}

u16 StageFlags_CountItems(StageFlags *f) {
    u16 total = 0;
    s32 i;
    for (i = 0; i < 100; i++) {
        total += f->items[i];
    }
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        if (f->entries[i].id != STAGE_ITEM_NONE) {
            if (*Param_GetEntry(f->entries[i].id) != 0x80) {
                total++;
            }
        }
    }
    f->itemTotal = total;
    return total;
}

void StageFlags_ClearEntries_0206d0a8(StageFlags *f) {
    s32 i;
    for (i = 0; i < STAGE_ITEM_ENTRY_MAX; i++) {
        f->entries[i].id = STAGE_ITEM_NONE;
        f->entries[i].info = 0;
    }
}

}
