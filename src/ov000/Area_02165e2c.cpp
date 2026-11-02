#include "types.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);

static inline BOOL Active02165e2c(LoAnimC *c) {
    if (c == NULL || c->state == 0) {
        return FALSE;
    }
    return TRUE;
}

Item0216607c *func_ov000_02165e2c(Lo021cb6b0 *self, Node0216607c *area) {
    LoAnimC *c;
    u8 j;
    u8 i;
    c = self->unk_30->anim;
    j = 0;
    if (!Active02165e2c(c)) {
        Robo021ca458 *pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return NULL;
        } else {
            Item0216607c *e;
            u8 k;
            s32 v;
            e = area->items;
            v = pl->pos.y;
            for (k = 0; k < area->count; k++, e++) {
                if (e->lo <= v && v < e->hi) {
                    return e;
                }
            }
        }
    } else {
        Node0216607c *next;
        Item0216607c *ents;
        s32 idx;
        ents = area->items;
        next = NULL;
        for (i = 0; i < area->count; i++) {
            if (c->key == ents[i].key) {
                return &ents[i];
            }
        }
        idx = c->idx + 1;
        if (idx < self->unk_30->anim->cnt) {
            next = c->frames[idx];
        }
        if (next == NULL) {
            return ents;
        }
        for (i = 0; i < area->count; i++) {
            for (j = 0; j < next->count; j++) {
                if (ents[i].key == next->items[i].key) {
                    return &ents[i];
                }
            }
        }
        return ents;
    }
    return NULL;
}

}
