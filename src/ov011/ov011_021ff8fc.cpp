#include "ov011/ov011.h"
#include "Main/Gfx/SlidePanel.h"

#ifdef NONMATCHING
// Status (round drA): Ov011SceneActor_Update is 26 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: register colouring of the ring loop only (head, p and pos share r3 in the ROM).
// History: docs/MATCHING.md rounds qpJ, raD, raF, svC, mtA, cvA (search for the address); the full list is
// docs/UNMATCHED.md.
// Ov011SceneActor_Update: 26 / 0 (raw / aligned register-masked, round raF; 56 / 0 in round raD; 61 / 4 at the
// end of ov011_021fef00.cpp in round qpJ, 114 / 4 in round ovreg).
// The read-only list and ring accessors take const pointers (F24c_Count, F24c_Active,
// F24c_CountBusy, the ring readers and F24c_GetRing), so their b0 tests are const reads, and the final
// `F24c_SetState(..., 5)` reloads self->unk_100 instead of reusing `l`. Then SetState's plain b0 read is not CSE'd
// with Count's const read across the count loop (jkF/jkG), the flag byte is re-read as in the ROM, `l` is not live
// across the search loop, and the &data_ov000_021ccd68 pool load is hoisted into fp. All three are needed: a
// non-const Count, a plain GetRing read or `F24c_SetState(l, 5)` gives 360+ / 53+. `cnt` declared before `nd`.
// Round raD moved the draft here from the end of ov011_021fef00.cpp: Ov011SceneActor_HandleMsg there needs a const view
// of the 0x02207258 block (its name-pointer load is hoisted above the `s->a = 0` store; non-const gives 6 / 6),
// while this function needs a non-const one (the ROM interleaves the three +0x20 loads with their stores; const
// gives 61 / 4). MWCC decides this per declared object, not per lvalue (a const member, a const-struct cast, CFLD
// or `*(const char *const *)&...` in 021ff084 all stay at 6), so no single declaration in one TU gives both.
// Round raF: 26 / 0. The busy-count walk keeps its flag in a CountBusy local set in both arms of an if/else
// (it was a nested F24c_NodeBusy inline returning TRUE/FALSE). The nested inline's result is numbered after
// CountBusy's n/nd; the ROM's flag comes before them, as an outer-inline local does (56 -> 29). Declaring
// RingAt's head first gives k the ROM's sb (28). The same rule for RingSize: its count read is written in place
// (an outer-inline local) instead of a nested F24c_RingCount call, which gives the count the ROM's r2 (26).
// Left: register colouring of the ring loop only (head, p and pos share r3 in the ROM; ours r8/fp). The
// colour model wants the head load numbered after the late u16 narrowing temps, which no @ object can be.
struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011Small6 {
    Ov011Bit01 f;
    u8 pad;
    u16 a;
    u16 b;
};

// The .rodata block at 0x02207258 (defined in ov011_022077c0.cpp): four resource-name pointers, a zero
// rotation, a scale and a zero position. Read here through a non-const view, as in ov011_021ffb58.cpp and
// ov011_0220068c.cpp.
struct Ov011ResTbl {
    const char *name[4];
    s16 rot[3];
    s16 scale[4];
    u16 pad;
    VecFx32 pos;
};

extern "C" {
extern Ov011ResTbl data_ov011_02207258;
}

struct F24cRing {
    Ov011Bit01 f;
    u8 pad;
    u16 head;
    u16 cap;
    u16 pad2;
    s32 *data;
    u32 count;
};

struct F24cList {
    Ov011Bit01 f;
    u8 pad[3];
    s32 state;
    u8 pad8[4];
    Ov011Node *head;
    F24cRing ring;
};

extern "C" {

void func_ov011_02202a38(void);
void Ov011Scene_Update(void *p);

static inline u32 F24c_Active(const F24cList *l) {
    u32 r = 0;
    if (l->f.b0) {
        r = l->f.b2;
    }
    return r;
}

static inline void F24c_SetState(F24cList *l, s32 st) {
    if (l->f.b0 && l->f.b2) {
        l->state = st;
        l->f.b2 = 0;
    }
}

static inline u32 F24c_Count(const F24cList *l) {
    u32 n = 0;
    if (l->f.b0) {
        Ov011Node *nd;
        for (nd = l->head; nd != NULL; nd = nd->next) {
            n++;
        }
    }
    return n;
}

static inline u16 F24c_RingCap(const F24cRing *r) {
    u16 c = 0;
    BOOL e = !r->f.b0;
    if (!e) {
        c = r->cap;
    }
    return c;
}

static inline u16 F24c_Idx(F24cRing *r, u16 k) {
    if (r->head < k) {
        return r->cap + (r->head - k);
    }
    return r->head - k;
}
static inline const s32 *F24c_RingAt(const F24cRing *r, u16 i) {
    u16 head;
    u16 k = i;
    const s32 *p = NULL;
    if (r->f.b0 && r->count > i) {
        u16 pos;
        head = r->head;
        if (i >= r->cap) {
            k = r->cap - 1;
        }
        if (head < k) {
            pos = r->cap + (head - k);
        } else {
            pos = head - k;
        }
        p = &r->data[pos];
    }
    return p;
}

static inline BOOL F24c_Valid(Actor *a) {
    Robo021ca458 *pl;
    if (a == NULL) {
        return FALSE;
    }
    pl = (Robo021ca458 *)func_ov000_0219bf90();
    if (pl == NULL) {
        return FALSE;
    }
    if (pl->unk_b1c == a->id) {
        return FALSE;
    }
    if (!(a->hit->unk_50 & 0x20000000)) {
        return FALSE;
    }
    return TRUE;
}

static inline u32 F24c_CountBusy(const F24cList *l) {
    u32 n = 0;
    if (l->f.b0) {
        Ov011Node *nd;
        for (nd = l->head; nd != NULL; nd = nd->next) {
            BOOL busy;
            Ov011Npc *a;
            if (nd != NULL && (a = Ov011_FindNpc(nd->id)) != NULL && Ov011Npc_IsTracking(a)) {
                busy = TRUE;
            } else {
                busy = FALSE;
            }
            if (busy) {
                n++;
            }
        }
    }
    return n;
}

static inline const F24cRing *F24c_GetRing(const F24cList *l) {
    const F24cRing *r = NULL;
    if (l->f.b0) {
        r = &l->ring;
    }
    return r;
}

static inline BOOL F24c_Mode1(Ov003Actor *self) {
    BOOL r = FALSE;
    if (self->fsm->current == 1) {
        r = TRUE;
    }
    return r;
}

static inline u32 F24c_RingSize(const F24cRing *r) {
    u32 c = F24c_RingCap(r);
    u32 n = 0;
    if (r->f.b0) {
        n = r->count;
    }
    if (n <= c) {
        c = n;
    }
    return c;
}

static inline BOOL F24c_IsMove(s32 e) {
    if (e == 2) {
        return TRUE;
    }
    if (e == 3) {
        return TRUE;
    }
    return FALSE;
}

void Ov011SceneActor_Update(Ov011SceneActor *self) {
    VecFx32 v;
    if (!Ov003Actor_CanAct(self)) {
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->unk_f2 = 0;
    } else {
        self->unk_93_4 = 1;
        self->unk_c4 = 0;
        BOOL ok = F24c_Mode1(self);
        if (ok) {
            ok = F24c_Active(((F24cList *)self->scene));
        }
        if (ok) {
            F24cList *l = ((F24cList *)self->scene);
            const F24cRing *r;
            u16 lim;
            r = F24c_GetRing(l);
            lim = self->unk_f0_0 ? 0x78 : 0;
            if (F24c_Count(l) == 0) {
                self->unk_b6 = 0;
                self->unk_f0_0 = 0;
                self->unk_f2 = 0;
                F24c_SetState(((F24cList *)self->scene), 5);
                self->unk_f0_1 = 0;
            } else if (self->unk_f2 >= lim) {
                u16 i;
                s16 found;
                s32 cnt = 0;
                Ov011Node *nd;
                for (i = 0; i < F24c_RingSize(r); i++) {
                    s32 e = *F24c_RingAt(r, i);
                    if (F24c_IsMove(e)) {
                        cnt++;
                    } else if (e == 4) {
                        break;
                    }
                }
                found = FALSE;
                self->unk_f0_0 = 0;
                self->unk_f2 = 0;
                l = ((F24cList *)self->scene);
                if (l->f.b0) {
                    for (nd = l->head; nd != NULL; nd = nd->next) {
                        Ov011Npc *a = Ov011_FindNpc(nd->id);
                        if (a != NULL && !Ov011Npc_IsTracking(a) && F24c_Valid(a)) {
                            found = TRUE;
                            break;
                        }
                    }
                }
                if (found) {
                    Ov011Sa108 *s;
                    if (cnt == 0 || cnt >= 2) {
                        F24c_SetState(((F24cList *)self->scene), 7);
                        self->unk_f0_1 = 0;
                    } else {
                        F24c_SetState(((F24cList *)self->scene), 6);
                        self->unk_f0_1 = 1;
                    }
                    s = self->unk_108;
                    s->b0 = 0;
                    s->b1 = 1;
                    s->unk_02 = 0x1000;
                    s->unk_04 = 0x1000;
                } else if (F24c_CountBusy(((F24cList *)self->scene)) == 0 ||
                           (cnt == 0 && F24c_CountBusy(((F24cList *)self->scene)) != 5)) {
                    F24c_SetState(((F24cList *)self->scene), 5);
                    self->unk_f0_1 = 0;
                } else if (cnt < 2) {
                    self->fsm->flags |= 0x8000;
                    self->unk_f0_0 = 1;
                } else if (F24c_Count(((F24cList *)self->scene)) != 5) {
                    F24c_SetState(((F24cList *)self->scene), 5);
                    self->unk_f0_1 = 0;
                } else {
                    self->fsm->flags |= 0x10000;
                }
            }
            self->unk_f2++;
        }
    }
    func_ov011_021fff38(self);
    func_ov011_0220023c(self);
    func_ov011_02200310(self);
    func_ov011_02202a38();
    {
        Robo021ca458 *pl = (Robo021ca458 *)func_ov000_0219bf90();
        if (pl != NULL) {
            VEC_Add(&self->pos, &self->unk_f4, &v);
            pl->unk_b90 = v;
            pl->unk_b9c = 0x4b8;
        }
    }
    self->unk_f4.x = data_ov011_02207258.pos.x;
    self->unk_f4.y = data_ov011_02207258.pos.y;
    self->unk_f4.z = data_ov011_02207258.pos.z;
    Ov011Scene_Update(self->scene);
}
}
#endif

extern "C" {

extern const char data_ov011_022078e1[];
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
s32 Rand_PlusMinus(s32 max);

void Ov011SceneActor_State20(Ov011SceneActor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov011_022078e1, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->model->visible = 0;
        self->fsm->st++;
        break;
    case 1: {
        EffectObj *p;
        if (++s->timer > 100) {
            func_02049a48(data_02097e4c, 50, 100, -1, -1);
            p = func_02065f88(50 + 0x358, &self->pos);
            p->SetScaleXYZ(0x1666, 0x1666, 0x1666);
            p->AddPosXYZ(0, 0x1000, 0);
            self->model->visible = 1;
            self->model->alpha = 0;
            self->fsm->timer = 0;
            self->fsm->st++;
        } else {
            u16 t = self->fsm->timer;
            if (t <= 75 && t % 15 == 0) {
                s32 x;
                s32 z;
                s32 a;
                s32 b;
                p = func_02065f88(0x398 - 15, &self->pos);
                p->SetScaleXYZ(0x1666, 0x1666, 0x1666);
                x = self->radius;
                z = self->centerY;
                a = Rand_PlusMinus(x);
                b = Rand_PlusMinus(z);
                p->AddPosXYZ(a, z + 0x1000 + b, x);
            }
        }
        break;
    }
    case 2:
        if (++s->timer > 60) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            self->model->alpha = 0x1f;
            func_ov000_02198360(self->fsm, 1, 0);
        } else if (self->fsm->timer > 30) {
            u8 v = self->model->alpha + 1;
            if (v > 0x1f) {
                v = 0x1f;
            }
            self->model->alpha = v;
        }
        break;
    }
}

}
