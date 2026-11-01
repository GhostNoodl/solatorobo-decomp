#include "ov002/ov002.h"

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

void func_ov002_021ec6c4(VObject *self, s32 kind) {
    s32 k = FIELD(self, 0x24, s32);
    s32 st;
    if (k != 2 && k != kind) {
        return;
    }
    st = FIELD(self, 0x8, s32);
    if (st == 3 || st == 7) {
        self->v0x2c(kind);
    }
}

void func_ov002_021ec6fc(void *node) {
    void *p = data_ov002_021f0fa0[0];
    void *prev;
    if (p == NULL) {
        data_ov002_021f0fa0[2] = node;
        data_ov002_021f0fa0[0] = node;
    } else {
        if (p != NULL) {
            s32 key = FIELD(FIELD(node, 0x20, void *), 4, s32);
            do {
                if (key < FIELD(FIELD(p, 0x20, void *), 4, s32)) {
                    break;
                }
                prev = p;
                p = FIELD(p, 0x2c, void *);
            } while (p != NULL);
        }
        if (p == NULL) {
            FIELD(node, 0x28, void *) = prev;
            FIELD(node, 0x2c, void *) = NULL;
            FIELD(prev, 0x2c, void *) = node;
            data_ov002_021f0fa0[2] = node;
        } else {
            FIELD(node, 0x28, void *) = FIELD(p, 0x28, void *);
            FIELD(node, 0x2c, void *) = p;
            FIELD(p, 0x28, void *) = node;
            if (FIELD(node, 0x28, void *) != NULL) {
                FIELD(FIELD(node, 0x28, void *), 0x2c, void *) = node;
            } else {
                data_ov002_021f0fa0[0] = node;
            }
        }
    }
    {
        s32 idx = FIELD(FIELD(node, 0x20, void *), 0, s32);
        FIELD(node, 0x30, void *) = data_ov002_021f0fac[idx];
        data_ov002_021f0fac[idx] = node;
    }
}

void func_ov002_021ec7ac(void *self) {
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 3;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    if (FIELD(self, 0x8, s32) != 1) {
        FIELD(self, 0xc, s32) = 1;
    }
}

void func_ov002_021ec7dc(void) {
}

BOOL func_ov002_021ec7e0(void *self) {
    if (*FIELD(self, 0x20, s32 *) == 3) {
        FIELD(data_ov002_021f0fa0[1], 0x4, u32) |= 8;
    }
    return FALSE;
}

void func_ov002_021ec80c(void) {
}

void func_ov002_021ec810(void *self) {
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x38, s32) = 0;
    FIELD(self, 0x3c, s32) = 0;
    FIELD(self, 0x40, s32) = 0;
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x48, u8) = 0;
    FIELD(self, 0x49, u8) = 0x1e;
}

void func_ov002_021ec838(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0x38, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278((u8 *)p + 0x88);
                func_0203de1c(p);
            }
            FIELD(self, 0x38, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObject *));
    HEAP_POP(saved);
}

static inline BOOL func_ov002_021ec8d8_is5(void *t) {
    return FIELD(t, 8, s32) == 5 ? TRUE : FALSE;
}
static inline BOOL func_ov002_021ec8d8_flag(void *t) {
    return FIELD(t, 4, Bits32).b4 == 1 ? TRUE : FALSE;
}
BOOL func_ov002_021ec8d8(void) {
    void *t;
    int n = 0;
    for (t = data_ov002_021f0fa0[8]; t != NULL; t = FIELD(t, 0x30, void *)) {
        if (func_ov002_021ec8d8_is5(t) || func_ov002_021ec8d8_flag(t)) {
            n++;
        }
    }
    if (n >= data_ov002_021f0d88.w2c) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov002_021ec968(void *self) {
    switch (FIELD(self, 0x10, s32)) {
    case 0: {
        VObject *o = (VObject *)func_0203dd9c(0x4c);
        if (o != NULL) {
            *(VFunc **)o = data_0208b318;
            o->v0x8();
        }
        FIELD(self, 0x34, VObject *) = o;
        FIELD(o, 0x44, s32) = 2;
        FIELD(self, 0x34, VObject *)->v0x24(data_ov002_021f0d88.dir, FIELD(FIELD(self, 0x20, void *), 8, void *));
        FIELD(self, 0x10, s32)++;
        break;
    }
    case 1:
        if (FIELD(self, 0x34, VObject *)->v0x2c()) {
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

struct StaffTask_eca14 : public VObject {
    Bits32 flags;
    u8 unk_08[0x8];
    s32 state;
    u8 unk_14[0xc];
    StaffParam_eca14 *param;
    s32 unk_24;
    u8 unk_28[0x8];
    StaffTask_eca14 *next;
    VObject *res;
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
            m = (StaffModel_eca14 *)func_0203dd9c(0x160);
            if (m != NULL) {
                void *r = self->res;
                func_02041218((u8 *)m + 0x88);
                func_02041440(m, (u8 *)r + 0x24, 0);
                STD_CopyString((u8 *)m + 0x2c, (u8 *)r + 4);
            }
            self->model = m;
            func_020417e0(self->model, (void *)self->res->v0x10());
            self->model->flags |= 2;
            func_02041d9c(self->model, 0, 0xffff);
            self->model->flags |= 0x80000;
            self->flags.b6 = 1;
        }
        self->state++;
        break;
    case 1:
        if (self->model != NULL && func_02054f10(self->model, 0xffff) == 0) {
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
