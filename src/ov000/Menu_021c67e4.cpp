#include "types.h"
#include "nitro/fx.h"
#include "ov000/TextList.h"
#include "Main/Sys/Pad.h"

extern "C" {

extern void *data_02097e4c;
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);

static inline ListRow *At021c67e4(TextList *self, s32 i) {
    ListRow *n;
    s32 k = 0;
    for (n = self->rows; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}

static inline void Body(TextList *self) {
    s32 zero;
    s32 cur;
    s32 d;
    u16 trg;
    u16 rep;
    zero = 0;
    if (self->flag2) {
        return;
    }
    if (self->timer > 0) {
        return;
    }
    d = zero;
    cur = d;
    trg = data_02097dc8->trig;
    rep = data_02097dc8->repeat;
    if (trg & 1) {
        if (self->onDecide != NULL) {
            self->onDecide(self, self->cur);
        }
        self->decided = 1;
    } else if (rep & 0x20) {
        d--;
    } else if (rep & 0x10) {
        d = 1;
    }
    if (d != 0) {
        BOOL wrap;
        s32 nx;
        self->prevIndex = self->index;
        wrap = self->listFlags.wrap ? TRUE : FALSE;
        cur = self->index;
        if (d > 0) {
            if (wrap) {
                s32 n = self->count;
                nx = (cur + d % n) % n;
            } else {
                nx = cur + d;
                if (nx >= self->count) {
                    nx = self->count - 1;
                }
            }
        } else {
            if (wrap) {
                s32 n = self->count;
                s32 m = (d < 0 ? -d : d) % n;
                nx = cur - m;
                if (nx < 0) {
                    nx = n - m;
                }
            } else {
                if (cur - (d < 0 ? -d : d) < 0) {
                    nx = 0;
                } else {
                    nx = cur - (d < 0 ? -d : d);
                }
            }
        }
        cur = cur != nx;
        self->index = nx;
    }
    if (cur) {
        ListRow *node;
        SndMgr_PlayVolume(data_02097e4c, 0x1d, -1, -1, -1);
        node = At021c67e4(self, self->index);
        self->cur = node;
        if (node != NULL) {
            self->rowWidth = node->width;
        }
        if (self->onCursor != NULL) {
            self->onCursor(self, self->cur);
        }
        self->decided = zero;
        self->timer = 15;
        self->dir = d;
    } else {
        self->timer = zero;
        self->dir = zero;
    }
}

void func_ov000_021c67e4(TextList *self) {
    Body(self);
}

// Marks the selected item and its two neighbours (wrapping if the menu wraps),
// then counts down the input repeat timer.
void func_ov000_021c69e4(TextList *self) {
    s32 next;
    BOOL wrap;
    ListRow *node;
    s32 i;
    s32 cur;
    s32 prev;
    wrap = self->listFlags.wrap ? TRUE : FALSE;
    cur = self->index;
    if (wrap) {
        s32 n = self->count;
        s32 m = 1 % n;
        prev = cur - m;
        if (prev < 0) {
            prev = n - m;
        }
    } else {
        prev = cur - 1;
        if (prev < 0) {
            prev = 0;
        }
    }
    if (wrap) {
        s32 n = self->count;
        next = (cur + 1 % n) % n;
    } else {
        next = cur + 1;
        if (next >= self->count) {
            next = self->count - 1;
        }
    }
    node = self->rows;
    i = 0;
    while (node != NULL) {
        if (i == cur) {
            node->shown = 1;
            node->focus = 1;
        } else if (i == prev) {
            node->shown = 1;
            node->focus = 0;
        } else if (i == next) {
            node->shown = 1;
            node->focus = 0;
        } else {
            node->shown = 0;
            node->focus = 0;
        }
        node->dir = self->dir;
        node->vfunc_08();
        node = node->next;
        i++;
    }
    self->timer = self->timer > 0 ? self->timer - 1 : 0;
}

extern s32 data_ov000_021cc994;
void Obj0215eab4_Draw(UiPanel *p);
void func_ov000_021c6d64(TextList *self, s32 a, VecFx32 *pos, s32 b);

static inline ListRow *At6b28(TextList *self, s32 i) {
    // u32 counter: swaps the registers of i and k in the loop compare.
    ListRow *n;
    u32 k = 0;
    for (n = self->rows; n != NULL; n = n->next) {
        if (k == i) {
            break;
        }
        k++;
    }
    return n;
}
static inline void Place021c6b28(TextList *self, ListRow *n, VecFx32 *p, s32 ofs) {
    if (n != NULL) {
        s32 x = p->x + ofs;
        s32 z = self->posZ;
        s32 y = p->y;
        n->x = x;
        n->y = y;
        n->z = z;
        n->vfunc_0c();
    }
}

void Ov000Vt_021ccadc_DrawBody(TextList *self, s32 a, VecFx32 *pos, s32 b) {
    VecFx32 p;
    s32 cur;
    s32 prev;
    p = *pos;
    p.z = self->posZ;
    self->vfunc_60(a, &p, b);
    prev = cur = 0;
    if (self->timer > 0) {
        s32 step = data_ov000_021cc994;
        prev = (0xf - self->timer) * (step * -self->dir);
        cur = self->timer * (step * self->dir);
    }
    Place021c6b28(self, At6b28(self, self->index), &p, cur);
    if (self->timer > 0) {
        Place021c6b28(self, At6b28(self, self->prevIndex), &p, prev);
    }
    if (self->listFlags.showCursor) {
        s32 x = p.x;
        s32 y = p.y;
        s32 z = p.z;
        UiPanel *c;
        x += (0x100 - self->panelWidth) << 11;
        y += (self->panelY << 12) - (self->lift << 15);
        c = self->panel;
        c->x = x;
        c->y = y;
        c->z = z + 0x20;
        Obj0215eab4_Draw(self->panel);
        self->panelText->unk_vf20(((self->panelWidth - (s32)self->panelText->width) >> 1) + (x >> 12), (y >> 12) + 2);
        self->panelText->posZ = z + 0x20;
        self->panelText->Render();
    }
    func_ov000_021c6d64(self, a, &p, b);
}

}
