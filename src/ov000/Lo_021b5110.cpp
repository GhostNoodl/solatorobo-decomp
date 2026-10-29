#include "types.h"
#include "ov000/Vec.h"

class Mgr021b5110Cls;
typedef void (Mgr021b5110Cls::*Mgr021b5110Pmf)();

typedef struct Node021b5110 {
    struct Node021b5110 *prev;
    struct Node021b5110 *next;
} Node021b5110;

typedef struct {
    u8 unk_00[0xc];
    s16 hx, hy, hz;
    u16 rot;
    u8 unk_14[0xc];
    u8 c[3];
    u8 sel;
} Item021b5110;

typedef struct {
    u8 unk_00[0x14];
    u8 count;
} Def021b5110;

typedef struct {
    u16 x, y, z;
} Rot021b5110;

typedef struct {
    u8 c[3];
} Col021b5110;

typedef struct {
    u8 pad_00[8];
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    u8 pad_0c[8];
    Def021b5110 *def;
    Item021b5110 *items;
    Node021b5110 *head;
    u8 pad_20[4];
    u8 unk_24[0x268];
    Mgr021b5110Pmf unk_28c;
} Mgr021b5110;

typedef struct {
    u8 pad_00[0x10];
    s32 cmd[0x10];
    s32 arg[0x10];
    s32 head;
    s32 tail;
    u8 pad_98[0x32];
    u8 col[3];
} Game021b5110;

typedef struct {
    u8 pad_00[0x15];
    u8 unk_15;
} Player021b5110;

extern "C" {

extern void *data_02149efc;
extern Game021b5110 *data_ov000_021ccd54;
extern void *data_02097e4c;
BOOL func_0203dbb0(void *node, s32 a);
s32 func_ov000_021b7b50(Node021b5110 *n);
Player021b5110 *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(Player021b5110 *pl);
BOOL func_01ffc318(void *a, Item021b5110 *item, VecFx32 *min, VecFx32 *max, Rot021b5110 *rot);
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_02188ca0(Col021b5110 *c, s32 a);

static inline void SetRot(Rot021b5110 *r, u16 x, u16 y, u16 z) {
    r->x = x;
    r->y = y;
    r->z = z;
}

static inline BOOL QueueBusy(void) {
    Game021b5110 *g = data_ov000_021ccd54;
    s32 t = g->tail;
    return g->head != t;
}

static inline void Push(s32 cmd, s32 arg) {
    Game021b5110 *g = data_ov000_021ccd54;
    g->cmd[g->tail] = cmd;
    g->arg[g->tail] = arg;
    if (++g->tail >= 0x10) {
        g->tail = 0;
    }
}

void func_ov000_021b5110(Mgr021b5110 *self) {
    Node021b5110 *n;
    Player021b5110 *pl;
    Item021b5110 *item;
    u8 i;
    u8 hit;
    if (func_0203dbb0(self, 1)) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        func_ov000_021b7b50(n);
    }
    if (*(void **)&self->unk_28c != NULL) {
        (((Mgr021b5110Cls *)self)->*self->unk_28c)();
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL || pl->unk_15 == 3) {
        return;
    }
    if (func_ov000_021b4738(pl)) {
        return;
    }
    if (self->def == NULL) {
        return;
    }
    if (self->unk_0a != 0xff || self->unk_0b != 0xff) {
        return;
    }
    item = self->items;
    hit = 0xff;
    for (i = 0; i < self->def->count; i++, item++) {
        VecFx32 max;
        VecFx32 min;
        Rot021b5110 rot;
        max.x = item->hx << 4;
        max.y = item->hy << 4;
        max.z = item->hz << 4;
        min.x = -max.x;
        min.y = -max.y;
        min.z = -max.z;
        SetRot(&rot, 0, item->rot, 0);
        if (func_01ffc318(self->unk_24, item, &min, &max, &rot)) {
            hit = i;
            if (self->unk_09 == i) {
                break;
            }
            self->unk_0b = i;
            self->unk_0a = item->sel;
            if (self->unk_0a == 0xff) {
                BOOL busy = FALSE;
                if (data_02149efc != NULL) {
                    busy = TRUE;
                }
                if (busy || QueueBusy()) {
                    func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                } else {
                    Push(0x1d, 0);
                }
            } else {
                Col021b5110 c;
                Game021b5110 *gm = data_ov000_021ccd54;
                u8 r = item->c[0];
                u8 g = item->c[1];
                u8 b = item->c[2];
                if (r == 0xff) r = gm->col[0];
                if (g == 0xff) g = gm->col[1];
                if (b == 0xff) b = gm->col[2];
                c.c[0] = r;
                c.c[1] = g;
                c.c[2] = b;
                func_ov000_02188ca0(&c, 1);
            }
            break;
        }
    }
    if (hit == 0xff) {
        self->unk_09 = 0xff;
    }
}
}
