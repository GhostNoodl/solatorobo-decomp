#include "types.h"

typedef struct {
    u8 unk_00[0x10];
    void *unk_10;
    u8 unk_14[0xa0];
    void *unk_b4;
} Obj0214dcc4;

extern "C" {

void func_ov000_02157c28(Obj0214dcc4 *self);
BOOL func_ov000_02152e5c(Obj0214dcc4 *self);
void func_02041d9c(void *obj, s32 a, s32 b);
void func_02041c34(void *obj, s32 a, void (*cb)(void), void *arg);
void *func_ov000_0214db04(u8 *self, u16 *cmd, void *arr, u16 *count);

void func_ov000_0214dcc4(Obj0214dcc4 *self) {
    func_ov000_02157c28(self);
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 0xc);
        func_02041d9c(self->unk_10, 0, 0xd);
    }
    if (self->unk_b4 != NULL) {
        func_02041d9c(self->unk_b4, 0, 0x1e);
        func_02041c34(self->unk_b4, 0x1e, (void (*)(void))func_ov000_0214db04, self);
    }
}

}

#ifdef NONMATCHING
// func_ov000_0214dd3c (round tmA): 28 / 0 (register-only), honest. Now 26 / 0 (round raE, below). The old 28 / 0 draft
// (ovlo12/d/dd3c/m2.cpp) read the game-state pointer through a one-element array g[1]; reading
// it through a getter inline (GetG0214dd3c) numbers the two g temps the same way. Without either
// (plain `u8 *g = data_ov000_021ccd54;`) it is 70 / 0. Left: key / Key(p) / insert-walk p colouring.
// Round raB: address accessors for the list head, next and unk_36, a for walk and O1-O3 give 28 or
// worse; the ramerge colour model does not reproduce this graph (13 nodes differ).
// Round qpH, all 28 / 0 unless noted: k and g in Key split into their own statements (declared first,
// assigned later, either order), Key as a Node member function (with or without this->), a pk local for
// Key(p), key as u32 (28) or s32 (29 / 1), the walk as a for with last = p in the step, Key(p) < key,
// a const Node * for Key. u32/s32 k is 115 / 106, key before the head load 38 / 15, the && walk 129.
// Round raC: Key(m) written in place into key (28), a separate q for the insert walk (70; p must stay
// the shared @ web). Only Key(p) written in place in the walk with u8 *g / u16 k locals gives 26 / 0,
// but that duplicates Key's body, so it is not kept.
// Round raE: 26 / 0 without the copy. Key is now a wrapper of KeyR(p, u8 *&g), which takes the game-state
// pointer by reference (round raE's 021d1f70 / SlidePanel 02054bb4 shape), and the insert walk calls
// KeyR(p, g) with a function-level g, so g is a user variable there. A caller-held k (KeyR(p, u16 &k)) or
// both give 26 too, at every declaration slot; also passing g to Key(m) gives 28. Left: key / p / g / k
// are r5 / r8 / r7 / r4 here and r7 / r5 / r4 / r8 in the ROM (the colour model still differs by 13 nodes).
// Round bgZ: bgY's observation (the ROM's g is r4 in both Key(m) and the walk) is two webs that happen to share
// a colour, not one variable: with a shared function-level g passed to both KeyR calls, our two g webs still get
// r5 / r7. A KeyRR(p, u8 *&g, u16 &k) taking both g and k from the caller, for Key(m) (into key) and the walk,
// gives 26 or 28 in all 120 declaration orders of p / last / key / g / k.
#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_ov000_021ccd24[];
extern u8 *data_ov000_021ccd54;
extern u8 data_02fe1534[];
extern void *data_02fe152c;
void func_ov000_02153f90(void *p);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_0204c6bc(s32 a, s32 b, void *c, void *d);
void func_ov000_0214dc20(void *self, s32 *msg);
u32 func_ov000_0214bf2c(u16 a);
u16 func_020595c4(void *a, s32 b, s32 c, u16 d);
}

struct Node0214dd3c {
    s32 unk_00;
    s16 idx;
    u16 id;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    s32 unk_10[5];
    s32 unk_24;
    Node0214dd3c *prev;
    Node0214dd3c *next;
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Node0214dd3c() {
        func_ov000_02153f90(this);
        unk_30 = 0;
        unk_32 = 0;
        unk_34 = 0;
        unk_36 = 0;
    }
};

static inline u8 *GetG0214dd3c(void) {
    return data_ov000_021ccd54;
}

static inline u16 KeyR0214dd3c(Node0214dd3c *p, u8 *&g) {
    u16 k = p->unk_36 & 0xf;
    g = GetG0214dd3c();
    if (func_ov000_0214bf2c(p->id) & 0x10) {
        k |= 0x3f0;
    } else {
        k |= (u16)((p->unk_34 & 0x3f) << 4);
    }
    k |= (u16)((0x1f - (p->unk_30 & 0x1f)) << 10);
    if (LFLD(u8, g, 0xca) == p->unk_30) {
        k |= 0x8000;
    }
    return k;
}

static inline u16 Key0214dd3c(Node0214dd3c *p) {
    u8 *g;
    return KeyR0214dd3c(p, g);
}

extern "C" {
Node0214dd3c *func_ov000_0214dd3c(u8 *self, s32 a, u16 id, u16 c, s32 d) {
    Node0214dd3c *p;
    Node0214dd3c *last;
    u16 key;
    s16 i;
    u32 fl;
    s32 out;
    u8 *g;
    for (p = LFLD(Node0214dd3c *, self, 0x98); p != NULL; p = p->next) {
        if (p->id == id) {
            return NULL;
        }
    }
    Node0214dd3c *m = new Node0214dd3c;
    last = NULL;
    LFLD(s16, self, 0x9c)++;
    m->unk_00 = a;
    m->idx = 0;
    m->id = id;
    m->unk_08 = c;
    m->unk_0c = d;
    func_0204c6bc(out, func_0204c08c(LFLD(void *, LFLD(u8 *, data_ov000_021ccd24, 8), 0xbc), id, &out, 1), m, (void *)func_ov000_0214dc20);
    if (LFLD(Node0214dd3c *, self, 0x94) == NULL) {
        LFLD(Node0214dd3c *, self, 0x94) = m;
        LFLD(Node0214dd3c *, self, 0x98) = m;
    } else {
        p = LFLD(Node0214dd3c *, self, 0x98);
        key = Key0214dd3c(m);
        while (p != NULL) {
            if (key > KeyR0214dd3c(p, g)) {
                break;
            }
            last = p;
            p = p->next;
        }
        if (p == NULL) {
            m->prev = last;
            m->next = NULL;
            last->next = m;
        } else {
            m->prev = p->prev;
            m->next = p;
            p->prev = m;
            if (m->prev != NULL) {
                m->prev->next = m;
            } else {
                LFLD(Node0214dd3c *, self, 0x94) = m;
                LFLD(Node0214dd3c *, self, 0x98) = m;
            }
        }
        i = 0;
        for (p = LFLD(Node0214dd3c *, self, 0x98); p != NULL; p = p->next) {
            p->idx = i;
            i++;
        }
    }
    fl = func_ov000_0214bf2c(id);
    if (fl & 0x10) {
        m->unk_08 = 0xb;
        if (LFLD(u16, data_02fe1534, 0x46) == m->unk_30) {
            m->unk_24 = 4;
        } else {
            m->unk_24 = 0xd;
        }
    }
    if (fl & 0x20) {
        if (LFLD(u16, data_02fe1534, 0x46) == m->unk_30) {
            if (func_020595c4(data_02fe152c, 1, 0x301, id) == 1) {
                m->unk_24 = 7;
            }
        } else {
            if (func_020595c4(data_02fe152c, 1, 0x301, id) == 1) {
                m->unk_24 = 0xb;
            } else {
                m->unk_24 = 0xe;
            }
        }
    }
    m->unk_0c = m->unk_36;
    return m;
}
}
#endif
