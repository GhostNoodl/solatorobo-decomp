#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 rest : 7;
} Ba4_0219efc0;

extern "C" {
extern void *data_ov000_021ccd68;
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern void *data_02097dc8;
extern void *data_02097e4c;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void *ActorMgr_GetGroup(void *mgr, u16 key);
u16 Pad_LookupDir(void *pad, void *p);
void func_ov000_021b3738(void *self, void *t);
void func_ov000_021b2d48(void *self);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);
void func_02062764(s32 a, s32 b);
BOOL func_ov000_0219b3b4(void *p);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov000_021b1814(void *self, s32 a, s32 b);
BOOL func_ov000_021b3e90(void *self);
void func_ov000_021b1a54(void *self, s32 a);

static inline Actor *FindActor_0219efc0(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL IsBusy_0219efc0(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_0219efc0(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (IsBusy_0219efc0(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL HasD4_0219efc0(FieldState *g) {
    return ((s32)g->event) != 0;
}

static inline void TogglePad_0219efc0(void) {
    if (data_0214a424->bits18.flag10) {
        data_0214a424->bits18.flag10 = 0;
    } else {
        data_0214a424->bits18.flag10 = 1;
    }
}

static inline void LockKeys_0219efc0(Robo021ca458 *self) {
    u32 m = self->unk_b24_12;
    if (m != 3) {
        if (self->unk_b2c_4 == 0 || m == 1) {
            self->fsm->flags |= 0x80;
        }
    } else {
        self->fsm->flags |= 0x4000;
    }
}

static inline void Gauge_0219efc0(s32 a, s32 b, VecFx32 *p) {
    ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
    if (o == NULL) {
        return;
    }
    if (o->unk_70 == NULL) {
        return;
    }
    func_ov000_02168e18(o->unk_70, a, b, p);
}

struct RgbEq_0219efc0Self {
    u8 unk_00[0x772];
    u8 unk_772;
    u8 unk_773;
    u8 unk_774;
};

static inline BOOL RgbEq_0219efc0(FieldState *g, RgbEq_0219efc0Self *self) {
    BOOL e = FALSE;
    if (g->unk_ca.c[0] == self->unk_772 && g->unk_ca.c[1] == self->unk_773 && g->unk_ca.c[2] == self->unk_774) e = TRUE;
    return e;
}

static inline BOOL Ready_0219efc0(FieldState *g) {
    if (IsBusy_0219efc0(g)) return FALSE;
    if (g->state != 3) return FALSE;
    return TRUE;
}
static inline BOOL IsIdleG_0219efc0(FieldState *g) {
    if (g != NULL) {
        return Ready_0219efc0(g);
    }
    return TRUE;
}

static inline BOOL NotB1_0219efc0(Robo021ca458 *self) {
    return !self->unk_b24_1;
}

static inline BOOL PadB9_0219efc0(void) {
    return data_0214a424->bits18.flag9 ? TRUE : FALSE;
}

static inline BOOL CanMove_0219efc0(Robo021ca458 *self) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = IsIdleG_0219efc0(g);
    if (r) {
        r = !self->unk_b29_1;
    }
    if (r) {
        r = self->unk_b28 == 0;
    }
    if (r) {
        r = self->unk_b2e == 0;
    }
    if (r) {
        r = !self->unk_b24_0;
    }
    if (r) {
        r = !self->unk_b29_3;
    }
    if (r) {
        r = !NotB1_0219efc0(self);
        if (!r) {
            BOOL t = PadB9_0219efc0();
            r = !t;
            if (!t) {
                r = RgbEq_0219efc0(g, (RgbEq_0219efc0Self *)self);
            }
            if (r) {
                r = self->unk_b24_14 == 0;
            }
        }
    }
    return r;
}

void func_ov000_0219efc0(Robo021ca458 *self) {
    u8 *p;
    Actor *t9;
    BOOL x;

    self->padCur = 0;
    self->padTrig = 0;
    self->padRelease = 0;
    self->padDir = 0;
    if (!IsIdle_0219efc0()) {
        return;
    }
    if (HasD4_0219efc0(data_ov000_021ccd54)) {
        return;
    }
    if (self->unk_b24_0 || self->unk_b24_12 == 2) {
        self->target = 0xffff;
        self->unk_b24_4 = 0;
        func_ov000_021b3738(self, NULL);
        return;
    }
    if (!self->unk_b29_1 && !self->unk_b28_2 && self->unk_b2e == 0 &&
        !self->unk_b29_3) {
        self->padCur = LFLD(u16, data_02097dc8, 0x10);
        self->padTrig = LFLD(u16, data_02097dc8, 0x12);
        self->padRelease = LFLD(u16, data_02097dc8, 0x14);
        self->padDir = Pad_LookupDir(data_02097dc8, (u8 *)self + 0xb70);
    }
    if ((self->padCur & 1) && !self->unk_b24_18) {
        self->unk_b36++;
        if (self->unk_b36 > 9999) {
            self->unk_b36 = 9999;
        }
    } else {
        self->unk_b36 = 0;
    }
    if (self->unk_b22_6 == 5) {
        if ((self->padTrig & 1) || ((self->padCur & 1) && self->unk_b36 >= 0xc)) {
            self->fsm->flags |= 0x4000;
        }
        if (self->padCur & 0xf0) {
            self->fsm->flags |= 4;
        }
        if (self->padTrig & 4) {
            TogglePad_0219efc0();
        }
        return;
    }
    func_ov000_021b2d48(self);
    p = self->unk_ba4;
    if (p != NULL && self->unk_b24_1 && self->unk_b24_12 == 0) {
        if (LFLD(Ba4_0219efc0, p, 6).b4) {
            if (self->unk_b1c == 0xffff && (u8)(self->fsm->current + 0xff) <= 1) {
                u16 n = self->unk_b36;
                if (n == 0) {
                    if (self->unk_b2c_4 != 0) {
                        Actor *a = FindActor_0219efc0(self->target);
                        u8 *i = NULL;
                        s32 k;
                        if (a != NULL) {
                            i = ((u8 *)a->targetObj);
                        }
                        k = 0;
                        if (i != NULL) {
                            k = i[0];
                        }
                        switch (k) {
                        default:
                            self->fsm->flags |= 0x80;
                            break;
                        case 0x11:
                        case 0x12:
                        case 0x13:
                        case 0x14:
                            self->fsm->flags |= 0x1000000;
                            break;
                        }
                        if (self->unk_b2c_4 < 2) {
                            self->unk_b2c_4 = 0;
                        } else {
                            self->unk_b2c_4 = 3;
                        }
                    }
                } else {
                    if (n >= 0x28) {
                        self->unk_b2c_4 = 2;
                        n = 0x28;
                    } else if (n >= 10) {
                        self->unk_b2c_4 = 1;
                    }
                    if (self->unk_b2c_4 != 0) {
                        VecFx32 z;
                        z.x = 0;
                        z.y = 0;
                        z.z = 0;
                        Gauge_0219efc0(n - 10, 0x1e, &z);
                    }
                }
            } else if (self->unk_b2c_4 < 3 || (self->fsm->current != 7 && self->fsm->current != 0x18)) {
                self->unk_b2c_4 = 0;
            }
        }
        if (self->unk_93_5 != 2) {
            self->unk_93_5 = 0;
            p = self->unk_ba4;
            if (LFLD(Ba4_0219efc0, p, 6).b8 && self->unk_b36 >= 8 && self->unk_b1c == 0xffff) {
                self->unk_93_5 = 1;
                if (!LFLD(Ba4_0219efc0, p, 6).b4) {
                    self->fsm->flags |= 0x10000000;
                }
            }
        }
    } else {
        self->unk_b2c_4 = 0;
        self->unk_b2c_6 = 0;
        self->unk_93_5 = 0;
    }
    if (self->unk_b22_3 && self->unk_b36 != 0 && data_0214a424->bits18.mode == 1 && self->unk_b1c == 0xffff &&
        self->target == 0xffff && (u8)(self->fsm->current + 0xff) <= 1) {
        self->fsm->flags |= 0x80;
    }
    if (self->padTrig & 1) {
        Actor *a;
        u8 *i;
        t9 = FindActor_0219efc0(self->target);
        if (t9 != NULL) {
            func_02062764(0x3c0, 0x40);
        }
        a = NULL;
        if (self->unk_b24_5 && self->unk_b24_1) {
            u8 *i;
            a = FindActor_0219efc0(self->unk_b1c);
            i = NULL;
            if (a != NULL) {
                i = ((u8 *)a->targetObj);
            }
            if (i == NULL || LFLD(u16, i, 0x1c) != self->id) {
                self->unk_b24_5 = 0;
                self->unk_b1c = 0xffff;
                self->unk_b1e = 0xffff;
                self->unk_b24_7 = self->unk_b24_9;
                a = NULL;
            }
        }
        i = NULL;
        if (a != NULL) {
            u8 *j = ((u8 *)a->targetObj);
            if (j != NULL) {
                switch (j[1]) {
                case 1:
                    self->fsm->flags |= 0x800;
                    break;
                case 2:
                    self->fsm->flags |= 0x1000;
                    break;
                case 4:
                    self->fsm->flags |= 0x2000;
                    break;
                case 5:
                    if (!self->unk_b22_3) {
                        self->fsm->flags |= 0x4000;
                    } else {
                        self->fsm->flags |= 0x800;
                    }
                    break;
                case 6:
                    if (FindActor_0219efc0(self->target) != NULL) {
                        self->fsm->flags |= 0x40;
                    } else {
                        self->fsm->flags |= 0x1000;
                    }
                    break;
                }
            }
        } else {
            if (t9 != NULL) {
                i = ((u8 *)t9->targetObj);
            }
            if (i != NULL) {
                BOOL hold = (self->msg_flags & 0x80) ? TRUE : FALSE;
                switch (i[0]) {
                case 3:
                    if (!hold) {
                        self->fsm->flags |= 0x20;
                    }
                    break;
                case 4:
                case 6:
                case 12:
                case 13:
                    if (!hold) {
                        self->fsm->flags |= 0x40;
                    }
                    break;
                case 5:
                    if (self->unk_b24_1) {
                        LockKeys_0219efc0(self);
                    } else if (!hold) {
                        self->fsm->flags |= 0x100;
                    }
                    break;
                case 7:
                    if (!hold) {
                        self->fsm->flags |= 0x100;
                    }
                    break;
                case 14:
                case 15:
                    if (!self->unk_b24_1 && ((t9->kind >> 12) == 5 || i[2] == 1 || func_ov000_0219b3b4(i))) {
                        self->fsm->flags |= 0x10000;
                    } else if (self->unk_b24_12 != 3) {
                        if (self->unk_b2c_4 == 0) {
                            self->fsm->flags |= 0x80;
                        }
                    } else {
                        self->fsm->flags |= 0x4000;
                    }
                    break;
                case 17:
                case 19:
                    if (!self->unk_b24_1 && ((t9->kind >> 12) == 5 || func_ov000_0219b3b4(i))) {
                        self->fsm->flags |= 0x10000;
                        break;
                    }
                case 18:
                case 20:
                    if (self->unk_b24_12 == 0 && self->unk_b2c_4 == 0) {
                        self->fsm->flags |= 0x1000000;
                    }
                    break;
                case 11:
                    self->fsm->flags |= 0x10000;
                    break;
                case 8:
                case 16:
                    self->fsm->flags |= 0x20000000;
                    break;
                case 9:
                case 10:
                    self->fsm->flags |= 0x40000000;
                    break;
                }
            } else if (self->unk_b24_1) {
                LockKeys_0219efc0(self);
            } else if (!(self->hit->unk_54 & 0x400)) {
                if (self->unk_93_4 || LFLD(u16, ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000), 0x16) != 0) {
                    self->fsm->flags |= 0x10000;
                }
            }
        }
    }
    if (self->padCur & 2) {
        if (self->unk_b24_12 != 3) {
            self->unk_b38++;
            if (self->unk_b38 > 9999) {
                self->unk_b38 = 9999;
            }
            if (self->padTrig & 2) {
                self->fsm->flags |= 8;
            }
            if (self->unk_b24_1) {
                if (self->unk_b22_0 != 0 && !self->unk_b24_18) {
                    self->fsm->flags |= 0x2000000;
                }
                p = self->unk_ba4;
                if (p != NULL && self->unk_b24_12 == 0) {
                    if ((LFLD(Ba4_0219efc0, p, 6).b7 && self->fsm->current == 4 &&
                         !(self->hit->unk_50 & 0x20000000) && self->unk_b38 >= 10) ||
                        (LFLD(Ba4_0219efc0, p, 6).b6 && self->fsm->current != 3 && self->unk_b38 > 6 &&
                         (self->hit->unk_50 & 0x20000000))) {
                        self->fsm->flags |= 8;
                    }
                }
            }
        }
    } else {
        self->unk_b38 = 0;
    }
    if (self->padTrig & 0x800) {
        if (self->unk_b24_1) {
            if (self->unk_b24_5 == 0 && self->unk_b24_12 == 0 && !self->unk_b22_3 && self->unk_b22_9 == 0) {
                self->fsm->flags |= 0x8000000;
            }
        } else if (self->unk_b24_4) {
            self->fsm->flags |= 0x4000000;
        }
    }
    if ((self->padCur & 0x200) && (self->padTrig & 0x100) && data_0214a424->bits18.mode == 1 && !self->unk_b22_3 &&
        self->unk_b22_9 == 0 && self->unk_b24_1 && self->unk_93_4 && !self->unk_b29_3 && self->unk_b22_0 == 0 &&
        self->unk_b24_12 == 0 && self->fsm->current != 0x11 && (self->fsm->current != 0xb || !self->unk_b24_26) &&
        data_0214a424->unk_026 >= 0x2d0) {
        func_02049a48(data_02097e4c, 0x30b, -1, -1, -1);
        func_ov000_021b1814(self, 1, 0);
    }
    x = FALSE;
    if (self->unk_b22_0 != 0 && CanMove_0219efc0(self)) {
        if ((self->padTrig & 4) && self->unk_b24_1) {
            TogglePad_0219efc0();
        }
        if (self->unk_b22_0 != 3 && self->unk_b22_0 != 4) {
            x = func_ov000_021b3e90(self);
        }
    }
    if (!x && self->unk_b24_12 == 0 && (self->padCur & 0xf0)) {
        self->fsm->flags |= 4;
    }
    if (!self->unk_b22_3) {
        return;
    }
    if (self->unk_b22_4) {
        return;
    }
    if (self->unk_b29_3) {
        return;
    }
    if (self->unk_b24_0) {
        return;
    }
    if (self->fsm->current == 0xb && self->unk_b24_26) {
        return;
    }
    {
        u16 v = data_0214a424->unk_026;
        if (v != 0) {
            v--;
            data_0214a424->unk_026 = v;
        }
        if (v != 0 && self->unk_93_4) {
            return;
        }
    }
    func_ov000_021b1a54(self, 1);
}
}
