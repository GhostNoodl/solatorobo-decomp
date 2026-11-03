#include "ov002/ov002.h"

extern "C" {

void func_ov000_0215d980(void *a, u32 b, int c);

BOOL func_ov002_021d39ec(UiList *self, UiListItem *ev) {
    Task021ef81c *o;
    Lo021cae48 *c;
    UiListItem *item;
    UiList021cb4a8 *list;
    u32 cost;
    o = (Task021ef81c *)self->owner;
    if (ev != NULL) {
        if (ev->id == 0) {
            list = o->unk_3c;
            c = o->unk_44;
            item = list->topItem;
            if (item == NULL) {
                item = NULL;
            } else {
                s32 n = list->cursor;
                while (n-- != 0) {
                    item = item->next;
                }
            }
            cost = c->value - item->unk_0c;
            func_ov000_0215d980(c, cost, 0);
            { StageFlags *g = data_0214a424; if (cost > 9999) { cost = 9999; } g->unk_614 = cost; }
            list->vfunc_70(item);
            Item_Set_0206f5e4(item->id, 1);
            SndMgr_PlayVolume(data_02097e4c, 0x31, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
        }
        return FALSE;
    }
    SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    return FALSE;
}

BOOL func_ov002_021d3b10(UiList *self, UiListItem *ev) {
    Task021ef81c *o = (Task021ef81c *)self->owner;
    UiList021cb4a8 *a = o->unk_3c;
    Lo021cae48 *c = o->unk_44;
    if (ev != NULL) {
        if (c->value >= ev->unk_0c) {
            func_ov000_02152294(a, 0xf5, 0x18, (EvCallback)func_ov002_021d39ec);
            SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            Lo021cadcc *b = o->unk_40;
            Obj0215bb14_SetText(b, MsgRes_GetString(data_02149ef8, 0x9c));
            b->vfunc_70();
            o->unk_4c = 0;
            SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
        }
    } else {
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
        o->unk_3c->flags |= 2;
        o->unk_40->flags |= 2;
        o->unk_44->flags |= 2;
        o->unk_48->flags |= 2;
    }
    return TRUE;
}

}
