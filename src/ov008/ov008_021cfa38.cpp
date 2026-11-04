#include "ov008/ov008.h"
#include "Main/Res/ArcName.h"
#include "Main/Sys/FieldState.h"
#include "Main/Gfx/ObjPool.h"
typedef struct Ov008Tag { u8 unk_00[0x30]; u16 id; u16 unk_32; u16 unk_34; u16 unk_36; } Ov008Tag;
typedef struct Ov008SaveEnt { u16 unk_00; u16 id; } Ov008SaveEnt;
extern "C" {
extern Ov008Save *gDataRes;
Ov008Def *Lang_GetGroup(u8 id);
u16 DataRes_ReadEntry(void *a, int b, int c, int d);
Ov008Item *UiList_GetItemById(void *a, u32 id);
BOOL Ov008WorldMap_MenuOnDecide(Ov008Menu *self, Ov008Sel *sel);
BOOL Ov008WorldMap_MenuOnCursor(Ov008Menu *self, Ov008Sel *sel);
extern void *gMsgRes;
extern void *UiObj_vtbl;
extern void *UiList_vtbl;
extern void *Ov008Menu_vtbl;
extern char gCommonTextPath[];
extern u8 *gStageFlags;
s32 MsgRes_GetString(void *p, s32 id);
BOOL func_020624d8(void);
void UiList_SetMarkModel(void *list, const char *arc, const char *file, int part);
Ov008SaveEnt *DataRes_GetTable(void *res, u32 idx);
u32 DataRes_GetCount(void *res, u32 idx);
u16 DataRes_ReadBitsAt_02059544(void *res, void *block, Ov008SaveEnt *entries, int packed, u32 id);
Ov008Chr *SceneStage_GetScript(void *p, s32 a);
void MsgEntry_Init(Ov008Tag *t);
void MsgEntry_Release(Ov008Tag *t);
u32 func_ov000_0214c01c(u16 a);
u32 Quest_GetOptFlags(u16 id);
const char *SceneRes_GetString(u16 id);
void Text_ScanTags(const char *str, s32 maxLines, void *arg, void (*cb)(void *arg, s32 *tag));
void func_ov000_0214dc20(void *arg, s32 *tag);
void func_ov008_021cf5c8(s32 type, void *list, void *info);
static inline void Ov008_AddEntry(Ov008Mgr *m, u32 id) {
    Ov008Def *e = Lang_GetGroup(id);
    Ov008Item *p;
    m->menu->v74(e->unk_00, id, 0xffff, 0xffff);
    if (!DataRes_ReadEntry(gDataRes, 0, 0x201, id)) {
        return;
    }
    p = UiList_GetItemById(m->menu, id);
    if (p != NULL) {
        p->unk_0a = 10;
    }
}
static inline BOOL Ov008Entry_Flag(Ov008Item *e) {
    return e->flags.b0 ? TRUE : FALSE;
}

static inline BOOL Ov008Entry_IsSet(Ov008Item *e) {
    return Ov008Entry_Flag(e) ? TRUE : FALSE;
}

// Whether a save entry counts as already known: hidden entries (flag 0x20) are new, others
// take the save's 0x301 bit, and the entry under the cursor is always known.
typedef enum Ov008EntState {
    OV008_ENT_NEW = 0,
    OV008_ENT_KNOWN = 1
} Ov008EntState;

void Ov008WorldMap_BuildMenu(Ov008Mgr *m) {
    u16 i;
    Ov008Menu *p;
    void *res;
    Ov008Item *it;
    u8 *base;
    u32 cnt;
    Ov008Chr *cur;
    u32 flags;
    Ov008EntState ok;
    Ov008Tag tag;
    Ov008Item *e;
    Ov008SaveEnt *ents;
    res = gMsgRes;
    p = (Ov008Menu *)Heap_Alloc(0xd4);
    if (p != NULL) {
        OV008_SET_VT(p, &UiObj_vtbl);
        p->v28();
        OV008_SET_VT(p, &UiList_vtbl);
        p->v28();
        OV008_SET_VT(p, &Ov008Menu_vtbl);
    }
    m->menu = p;
    m->menu->v10(MsgRes_GetString(res, 0x96));
    m->menu->v14(MsgRes_GetString(res, 0x97));
    m->menu->owner = m;
    m->menu->width = 0x7a;
    m->menu->rows = 5;
    {
        Ov008Menu *q = m->menu;
        q->posX = 0;
        q->posY = 0x14;
        q->posZ = -0x1000;
    }
    m->menu->onDrawItem = (Ov008Cb)func_ov008_021cf5c8;
    m->menu->onDecide = (Ov008Cb)Ov008WorldMap_MenuOnDecide;
    m->menu->onCursor = (Ov008Cb)Ov008WorldMap_MenuOnCursor;
    data_02fe1534.unk_44 = 1;
    m->unk_fc->v38(1);
    data_02fe1534.unk_44 = 0;
    m->unk_110 = data_02fe1534.unk_68;
    if (m->menu->serial == 0) {
        Ov008_AddEntry(m, 0);
    }
    if (func_020624d8()) {
        Ov008Menu *u = m->menu;
        u->va8(UiList_GetItemById(u, data_02fe1534.unk_52));
    } else {
        Ov008Menu *u = m->menu;
        for (it = u->topItem; it != NULL; it = it->next) {
            if (it->unk_0a == 10) {
                u->va8(UiList_GetItemById(u, it->id));
                break;
            }
        }
        if (it != NULL) {
            m->menu->va8(it);
        } else {
            m->menu->va8(m->menu->topItem);
        }
    }
    m->menu->v08();
    UiList_SetMarkModel(m->menu, gCommonTextPath, ResName_TextCells, 10);
    base = gDataRes->unk_4c;
    ents = DataRes_GetTable(gDataRes, 1);
    cnt = DataRes_GetCount(gDataRes, 1);
    i = 0;
    cur = SceneStage_GetScript((u8 *)gSceneCmd + 0xac, 0);
    MsgEntry_Init(&tag);
    tag.id = 0;
    tag.unk_32 = 0;
    tag.unk_34 = 0;
    tag.unk_36 = 0;
    func_ov000_0214c01c(gStageFlags[0x639]);
    for (; i < cnt; i++) {
        flags = Quest_GetOptFlags(ents[i].id);
        if (flags & 0x20) {
            ok = OV008_ENT_NEW;
        } else {
            ok = (Ov008EntState)DataRes_ReadBitsAt_02059544(gDataRes, base + 0x30, ents, 0x301, i);
        }
        if (cur != NULL && cur->unk_c6 == ents[i].id) {
            ok = OV008_ENT_KNOWN;
        }
        if (DataRes_ReadBitsAt_02059544(gDataRes, base + 0x30, ents, 1, i) == 1 && ok == OV008_ENT_NEW) {
            tag.id = 0xffff;
            Text_ScanTags(SceneRes_GetString(ents[i].id), 1, &tag, func_ov000_0214dc20);
            ok = OV008_ENT_NEW;
            if (tag.id != 0xffff) {
                if (flags & 0x80) {
                    if (DataRes_ReadEntry(gDataRes, 5, 1, 0x29)) {
                        ok = OV008_ENT_KNOWN;
                    }
                }
                if (ok == OV008_ENT_NEW) {
                    e = UiList_GetItemById(m->menu, tag.id);
                    if (e != NULL) {
                        e->unk_32++;
                        if (!Ov008Entry_IsSet(e)) {
                            if (DataRes_ReadBitsAt_02059544(gDataRes, base + 0x30, ents, 0x101, i) == 1 && e->unk_0a == 0xffff) {
                                e->flags.b0 = 1;
                            }
                        }
                        if (tag.unk_36 != 0) {
                            e->unk_30 |= (u16)(2 << (tag.unk_36 - 1));
                        }
                    }
                }
            }
        }
    }
    MsgEntry_Release(&tag);
}
}
