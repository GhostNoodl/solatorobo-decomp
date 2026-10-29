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
void func_ov000_0214db04(void);

void func_ov000_0214dcc4(Obj0214dcc4 *self) {
    func_ov000_02157c28(self);
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(self->unk_10, 0, 0xc);
        func_02041d9c(self->unk_10, 0, 0xd);
    }
    if (self->unk_b4 != NULL) {
        func_02041d9c(self->unk_b4, 0, 0x1e);
        func_02041c34(self->unk_b4, 0x1e, func_ov000_0214db04, self);
    }
}

}

#ifdef NONMATCHING
// func_ov000_0214dd3c (round tmA): 28 / 0 (register-only), honest. The old 28 / 0 draft
// (ovlo12/d/dd3c/m2.cpp) read the game-state pointer through a one-element array g[1]; reading
// it through a getter inline (GetG0214dd3c) numbers the two g temps the same way. Without either
// (plain `u8 *g = data_ov000_021ccd54;`) it is 70 / 0. Left: key / Key(p) / insert-walk p colouring.
// Round raB: address accessors for the list head, next and unk_36, a for walk and O1-O3 give 28 or
// worse; the ramerge colour model does not reproduce this graph (13 nodes differ).
#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_ov000_021ccd24[];
extern u8 *data_ov000_021ccd54;
extern u8 data_02fe1534[];
extern void *data_02fe152c;
void func_ov000_02153f90(void *p);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_0204c6bc(s32 a, s32 b, void *c, void *d);
void func_ov000_0214dc20(void);
u32 func_ov000_0214bf2c(u16 a);
s32 func_020595c4(void *a, s32 b, s32 c, u16 d);
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

static inline u16 Key0214dd3c(Node0214dd3c *p) {
    u16 k = p->unk_36 & 0xf;
    u8 *g = GetG0214dd3c();
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

extern "C" {
Node0214dd3c *func_ov000_0214dd3c(u8 *self, s32 a, u16 id, u16 c, s32 d) {
    Node0214dd3c *p;
    Node0214dd3c *last;
    u16 key;
    s16 i;
    u32 fl;
    s32 out;
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
            if (key > Key0214dd3c(p)) {
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
