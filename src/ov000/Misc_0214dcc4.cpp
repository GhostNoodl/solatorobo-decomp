#include "types.h"
#include "Main/Res/StageVars.h"
#include "Main/Sys/FieldState.h"
#include "Main/Gfx/Model.h"

typedef struct {
    u8 unk_00[0x10];
    Model *unk_10;
    u8 unk_14[0xa0];
    Model *unk_b4;
} Obj0214dcc4;

extern "C" {

void UiList021cb4a8_Setup(Obj0214dcc4 *self);
BOOL Obj02152e5c_LoadModel(Obj0214dcc4 *self);
void TexObj_SetOamFunc(void *obj, s32 a, void (*cb)(void), void *arg);
void *Lo021caac8_OamCallback(u8 *self, u16 *cmd, void *arr, u16 *count);

void Lo021caac8_Setup(Obj0214dcc4 *self) {
    UiList021cb4a8_Setup(self);
    if (Obj02152e5c_LoadModel(self)) {
        TexObj_SelectImage(self->unk_10, 0, 0xc);
        TexObj_SelectImage(self->unk_10, 0, 0xd);
    }
    if (self->unk_b4 != NULL) {
        TexObj_SelectImage(self->unk_b4, 0, 0x1e);
        TexObj_SetOamFunc(self->unk_b4, 0x1e, (void (*)(void))Lo021caac8_OamCallback, self);
    }
}

}

#ifdef NONMATCHING
// Status (round drA): Lo021caac8_AddItem is 26 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: register-only: the first walk's p and the new node lose r6; no declaration order or
// Insert inline moves it. History: docs/MATCHING.md rounds tmA, raE, rgB, nmA, mtA, cvA (search for the address);
// the full list is docs/UNMATCHED.md.
// Lo021caac8_AddItem (round tmA): 28 / 0 (register-only), honest. Now 26 / 0 (round raE, below). The old 28 / 0 draft
// (ovlo12/d/dd3c/m2.cpp) read the game-state pointer through a one-element array g[1]; reading
// it through a getter inline (GetG0214dd3c) numbers the two g temps the same way. Without either
// (plain `u8 *g = gSceneCmd;`) it is 70 / 0. Left: key / Key(p) / insert-walk p colouring.
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
// Round rgB: tools/vnum.sh: the second and third walks' p are split webs (nodes 28/29, band 3), Key's k/g and the
// new result are inline temps (33-38), and only fl / i / last / p are user objects. ramerge's model still differs, so it
// cannot say which band each of key / p / g / k has to move to.
#include "ov000/LoCommon.h"
#include "ov000/SceneRes.h"

extern "C" {
extern void *gDataRes;
void MsgEntry_Init(void *p);
s32 MsgRes_GetLines(void *res, u16 id, s32 *out, s32 d);
void Text_ScanTags(s32 a, s32 b, void *c, void *d);
void func_ov000_0214dc20(void *self, s32 *msg);
u32 Quest_GetOptFlags(u16 a);
u16 DataRes_ReadById(void *a, s32 b, s32 c, u16 d);
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
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Node0214dd3c() {
        MsgEntry_Init(this);
        unk_30 = 0;
        unk_32 = 0;
        unk_34 = 0;
        unk_36 = 0;
    }
};

static inline u8 *GetG0214dd3c(void) {
    return (u8 *)gSceneCmd;
}

static inline u16 KeyR0214dd3c(Node0214dd3c *p, u8 *&g) {
    u16 k = p->unk_36 & 0xf;
    g = GetG0214dd3c();
    if (Quest_GetOptFlags(p->id) & 0x10) {
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

struct List0214dd3c {
    u8 unk_00[0x94];
    Node0214dd3c *tail;
    Node0214dd3c *head;
    s16 count;
};

extern "C" {
Node0214dd3c *Lo021caac8_AddItem(List0214dd3c *self, s32 a, u16 id, u16 c, s32 d) {
    Node0214dd3c *p;
    Node0214dd3c *last;
    u16 key;
    s16 i;
    u32 fl;
    s32 out;
    u8 *g;
    for (p = self->head; p != NULL; p = p->next) {
        if (p->id == id) {
            return NULL;
        }
    }
    Node0214dd3c *m = new Node0214dd3c;
    last = NULL;
    self->count++;
    m->unk_00 = a;
    m->idx = 0;
    m->id = id;
    m->unk_08 = c;
    m->unk_0c = d;
    Text_ScanTags(out, MsgRes_GetLines(LFLD(void *, gSceneResSet.unk_08, 0xbc), id, &out, 1), m, (void *)func_ov000_0214dc20);
    if (self->tail == NULL) {
        self->tail = m;
        self->head = m;
    } else {
        p = self->head;
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
                self->tail = m;
                self->head = m;
            }
        }
        i = 0;
        for (p = self->head; p != NULL; p = p->next) {
            p->idx = i;
            i++;
        }
    }
    fl = Quest_GetOptFlags(id);
    if (fl & 0x10) {
        m->unk_08 = 0xb;
        if (data_02fe1534.unk_46 == m->unk_30) {
            m->unk_24 = 4;
        } else {
            m->unk_24 = 0xd;
        }
    }
    if (fl & 0x20) {
        if (data_02fe1534.unk_46 == m->unk_30) {
            if (DataRes_ReadById(gDataRes, 1, 0x301, id) == 1) {
                m->unk_24 = 7;
            }
        } else {
            if (DataRes_ReadById(gDataRes, 1, 0x301, id) == 1) {
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
