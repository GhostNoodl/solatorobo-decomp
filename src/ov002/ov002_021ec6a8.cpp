#include "ov002/ov002.h"
#include "ov002/StaffRoll.h"

extern "C" {

// The staff roll's .bss (0x021f0fa0..0x021f0fd0) is defined in ov002_021ecb90.cpp as separate
// objects. The ROM reaches all of them from this file's functions through the 0x021f0fa0 pool
// literal too, but this file is cut off from that TU by the unmatched func_ov002_021eca14, so
// it still reads them through this array view: [0] head, [1] staff, [2] tail, [8] the kind-5
// task list (data_ov002_021f0fac[5]).
extern void *data_ov002_021f0fa0[];

BOOL func_ov002_021ec6a8(void) {
    return TRUE;
}

BOOL func_ov002_021ec6b0(void) {
    return TRUE;
}

BOOL func_ov002_021ec6b8(void) {
    return TRUE;
}

void func_ov002_021ec6c0(void) {
}

void func_ov002_021ec6c4(Ov002StaffNode *self, s32 screen) {
    s32 k = self->screen;
    s32 st;
    if (k != 2 && k != screen) {
        return;
    }
    st = self->clock.state;
    if (st == 3 || st == 7) {
        self->vfunc_2c(screen);
    }
}

void Ov002StaffNode_Link(Ov002StaffNode *node) {
    Ov002StaffNode *p = (Ov002StaffNode *)data_ov002_021f0fa0[0];
    Ov002StaffNode *prev;
    if (p == NULL) {
        data_ov002_021f0fa0[2] = node;
        data_ov002_021f0fa0[0] = node;
    } else {
        if (p != NULL) {
            s32 key = node->entry->time;
            do {
                if (key < p->entry->time) {
                    break;
                }
                prev = p;
                p = p->next;
            } while (p != NULL);
        }
        if (p == NULL) {
            node->prev = prev;
            node->next = NULL;
            prev->next = node;
            data_ov002_021f0fa0[2] = node;
        } else {
            node->prev = p->prev;
            node->next = p;
            p->prev = node;
            if (node->prev != NULL) {
                node->prev->next = node;
            } else {
                data_ov002_021f0fa0[0] = node;
            }
        }
    }
    {
        s32 idx = node->entry->kind;
        node->link = data_ov002_021f0fac[idx];
        data_ov002_021f0fac[idx] = node;
    }
}

void func_ov002_021ec7ac(Ov002StaffNode *self) {
    self->entry = NULL;
    self->screen = 3;
    self->prev = NULL;
    self->next = NULL;
    self->link = NULL;
    if (self->clock.state != 1) {
        self->clock.next = 1;
    }
}

void func_ov002_021ec7dc(void) {
}

BOOL func_ov002_021ec7e0(Ov002StaffNode *self) {
    if (self->entry->kind == 3) {
        ((Ov002Staff *)data_ov002_021f0fa0[1])->clock.flags.done = 1;
    }
    return FALSE;
}

void func_ov002_021ec80c(void) {
}

void func_ov002_021ec810(Ov002StaffModel *self) {
    self->res = NULL;
    self->model = NULL;
    self->x = 0;
    self->y = 0;
    self->z = 0;
    self->alpha = 0;
    self->maxAlpha = 0x1e;
}

void func_ov002_021ec838(Ov002StaffModel *self) {
    void *saved;
    HEAP_PUSH(saved);
    {
        Model *p = self->model;
        if (p != NULL) {
            if (p != NULL) {
                TexObj_Release(p);
                PlttRes_Release(&p->pltt);
                Heap_Free(p);
            }
            self->model = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->res);
    HEAP_POP(saved);
}

static inline BOOL func_ov002_021ec8d8_is5(Ov002StaffModel *t) {
    return t->clock.state == 5 ? TRUE : FALSE;
}
static inline BOOL func_ov002_021ec8d8_flag(Ov002StaffModel *t) {
    return t->clock.flags.b4 == 1 ? TRUE : FALSE;
}
BOOL func_ov002_021ec8d8(void) {
    Ov002StaffModel *t;
    int n = 0;
    for (t = (Ov002StaffModel *)data_ov002_021f0fa0[8]; t != NULL; t = (Ov002StaffModel *)t->link) {
        if (func_ov002_021ec8d8_is5(t) || func_ov002_021ec8d8_flag(t)) {
            n++;
        }
    }
    if (n >= data_ov002_021f0d88.w2c) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov002_021ec968(Ov002StaffModel *self) {
    switch (self->clock.sub) {
    case 0: {
        Ov002StaffRes *o = (Ov002StaffRes *)Heap_Alloc(0x4c);
        if (o != NULL) {
            *(VFunc **)o = (VFunc *)data_0208b318;
            o->vfunc_08();
        }
        self->res = o;
        o->type = 2;
        self->res->vfunc_24(data_ov002_021f0d88.dir, self->entry->str);
        self->clock.sub++;
        break;
    }
    case 1:
        if (self->res->vfunc_2c()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

#ifdef NONMATCHING
// Status (round drA): func_ov002_021eca14 is 6 / 3 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: return TRUE's mov r0, #1 is scheduled into the ldrh stall; the ROM has return TRUE
// in a block of its own. History: docs/MATCHING.md rounds bgV, bgX, rgB, mtA, cvA (search for the address); the full
// list is docs/UNMATCHED.md.
// func_ov002_021eca14 (round bgX): 6 raw / 2 register-masked. Rebuilt from the ROM: no in-tree draft
// existed (earlier rounds kept theirs in scratch). It is ec968's sibling: case 0 counts the flagged
// tasks on data_ov002_021f0fa0[8] against data_ov002_021f0d88's limit and creates the model; case 1
// waits for it. This file's .text ends at 0x021eca14, so the function belongs here once it matches.
// The ldrh value read into a local before the 0x49 store gives the ROM's ldrh / strb / str order (the
// plain form stores 0x49 first). Left: `return TRUE`'s `mov r0, #1` is scheduled into the ldrh stall,
// so 0x1f cannot take r0 (ROM: p20 r1, 0x1f r0, value r1, mov r0 #1 last). bgV: the ROM needs
// `return TRUE` in a block of its own (two predecessors at scheduling time); only a dead second
// `p == NULL` test was found to give that. Tried in bgX, all 6: the stores in an `||` block, an inline
// with or without the `return TRUE`, an ed0c0-shaped Start inline, an enum 0x1f, a p20 local,
// honest_search (14 min) found no move.
typedef struct {
    u8 unk_00[0x8];
    void *unk_08;
    u16 unk_0c;
    u16 unk_0e;
} StaffParam_eca14;

typedef struct {
    u8 unk_00[0x6c];
    u32 flags;
} StaffModel_eca14;

struct StaffTask_eca14 : public VObj {
    Bits32 flags;
    u8 unk_08[0x8];
    s32 state;
    u8 unk_14[0xc];
    StaffParam_eca14 *param;
    s32 unk_24;
    u8 unk_28[0x8];
    StaffTask_eca14 *next;
    VObj *res;
    StaffModel_eca14 *model;
    u8 unk_3c[0xd];
    u8 unk_49;
};

static inline BOOL func_ov002_021eca14_flag(StaffTask_eca14 *t) {
    return t->flags.b6 == 1 ? TRUE : FALSE;
}

BOOL func_ov002_021eca14(StaffTask_eca14 *self) {
    switch (self->state) {
    case 0:
        if (self->param->unk_0e != 1) {
            StaffTask_eca14 *t;
            int n = 0;
            StaffModel_eca14 *m;
            for (t = (StaffTask_eca14 *)data_ov002_021f0fa0[8]; t != NULL; t = t->next) {
                if (func_ov002_021eca14_flag(t)) {
                    n++;
                }
            }
            if (n >= data_ov002_021f0d88.w28) {
                return FALSE;
            }
            m = (StaffModel_eca14 *)Heap_Alloc(0x160);
            if (m != NULL) {
                void *r = self->res;
                PlttRes_Init_02041218((PlttRes *)((u8 *)m + 0x88));
                TexObj_Init((Model *)m, (char *)((u8 *)r + 0x24), 0);
                STD_CopyString((char *)((u8 *)m + 0x2c), (char *)((u8 *)r + 4));
            }
            self->model = m;
            TexObj_SetRes((Model *)(self->model), (void *)self->res->vfunc_10());
            self->model->flags |= 2;
            TexObj_SelectImage((Model *)(self->model), 0, 0xffff);
            self->model->flags |= 0x80000;
            self->flags.b6 = 1;
        }
        self->state++;
        break;
    case 1:
        if (self->model != NULL && Model_IsReady(self->model, 0xffff) == 0) {
            break;
        }
        {
            u16 v = self->param->unk_0c;
            self->unk_49 = 0x1f;
            self->unk_24 = v;
        }
        return TRUE;
    }
    return FALSE;
}
#endif

}
