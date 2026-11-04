#include "ov002/ov002.h"

extern "C" {

void Lo021cae48_SetValue(void *a, u32 b, int c);

BOOL ComposeMenu_ConfirmOnDecide(UiList *self, UiListItem *ev) {
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
            Lo021cae48_SetValue(c, cost, 0);
            { StageFlags *g = gStageFlags; if (cost > 9999) { cost = 9999; } g->unk_614 = cost; }
            list->vfunc_70(item);
            Item_Set_0206f5e4(item->id, 1);
            SndMgr_PlayVolume(gSndMgr, 0x31, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        }
        return FALSE;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    return FALSE;
}

BOOL ComposeMenu_List3cOnDecide(UiList *self, UiListItem *ev) {
    Task021ef81c *o = (Task021ef81c *)self->owner;
    UiList021cb4a8 *a = o->unk_3c;
    Lo021cae48 *c = o->unk_44;
    if (ev != NULL) {
        if (c->value >= ev->unk_0c) {
            UiObj_OpenChoice(a, 0xf5, 0x18, (EvCallback)ComposeMenu_ConfirmOnDecide);
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        } else {
            Lo021cadcc *b = o->unk_40;
            Obj0215bb14_SetText(b, MsgRes_GetString(gMsgRes, 0x9c));
            b->vfunc_70();
            o->unk_4c = 0;
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        }
    } else {
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        o->unk_3c->flags |= 2;
        o->unk_40->flags |= 2;
        o->unk_44->flags |= 2;
        o->unk_48->flags |= 2;
    }
    return TRUE;
}

}
