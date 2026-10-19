#include "ov000/CmdObj.h"
#include "ov000/VObj.h"

typedef struct {
    u8 c[3];
} Id3;

typedef struct {
    u8 b0 : 2;
    u8 mode : 2;
    u8 b4 : 4;
} Bits0e;

class Item : public VObj {
public:
    u8 pad_04[0xc2];
    u16 unk_c6;
    u8 pad_c8[2];
    u16 unk_ca;
    u8 pad_cc[8];
    Item *unk_d4;
};

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[7];
    u16 unk_b4;
    u8 pad_b6[6];
    Item *unk_bc;
    u8 pad_c0[0xa];
    Id3 unk_ca;
    Id3 unk_cd;
    Id3 unk_d0;
    u8 pad_d3;
    s32 unk_d4;
    u8 pad_d8[0xb4];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
};

#define BITS0E(self) (*(Bits0e *)((u8 *)(self) + 0xe))

class Player : public VObj {
public:
    u8 pad_04[0x11];
    u8 unk_15;
    u8 pad_16[0xb12];
    u8 f0 : 2;
    u8 f2 : 1;
    u8 f3 : 5;
    u8 pad_b29[5];
    u8 unk_b2e;
};

typedef struct {
    u8 pad_00[4];
    CmdEx *obj;
} State021ccd50;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Task118;

typedef struct {
    u8 pad_00[0x7c];
    void *unk_7c;
} Task11c;

typedef struct {
    u8 pad_00[0x118];
    Task118 *unk_118;
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x8b0];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Obj02097d48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 31;
} Obj021ccd70;

typedef struct {
    u8 pad_00[0x12];
    u16 unk_12;
} Obj02097dc8;

typedef struct {
    CmdPmf fn;
    s32 unk_08;
} CmdEntry;

extern "C" {
extern State021ccd50 data_ov000_021ccd50;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern s32 data_02097d78[];
extern Obj021ccd70 *data_ov000_021ccd70;
extern CmdEntry data_ov000_021cc1a4[];
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern Obj02097dc8 *data_02097dc8;
extern void *data_0214a420;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern Obj02097d48 *data_02097d48;

void func_0203cb78(s32 a, s32 b, s32 c);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_021705a0(void *p, s32 a);
Player *func_ov000_0219bf90(void);
void func_ov000_02188ed0(CmdEx *self);
void func_02049564(void *p, s32 a, s32 b);
void func_ov000_021721f4(void *p);
BOOL func_ov000_02181d70(u8 *p, s32 a);
void func_02062424(Id3 *id);
void func_0204aa10(void *p);
void func_ov000_0216bcbc(void *p);
void func_ov000_021645a4(s32 a);
void func_020656b4(void *p);
void func_ov000_021b53f4(void *p);
void func_ov000_0218be9c(void *p);
void func_ov000_0218e894(void *p);

static inline BOOL IsMode(s32 m) {
    BOOL r;
    if (data_02097d78[3] == m) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == m;
    }
    return r;
}

static inline BOOL HasCmd(CmdObj *self) {
    return self->rd != self->index ? TRUE : FALSE;
}

static inline BOOL Busy(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 9)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0xa)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021705a0(mgr->unk_11c, 0);
    }
    return r;
}

static inline BOOL Locked(void) {
    return data_ov000_021ccd70->b0 == 1 ? TRUE : FALSE;
}

static inline void PlayerIdle(void) {
    Player *p = func_ov000_0219bf90();
    if (p != NULL && p->f0 == 0) {
        p->unk_15 = 3;
        p->f0 = 0;
        p->f2 = 1;
    }
}

static inline BOOL HasD4(CmdEx *obj) {
    return (obj->unk_d4 != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

static inline BOOL B2e(Player *p) {
    return p->unk_b2e != 0 ? TRUE : FALSE;
}

static inline s32 TaskVal(Task118 *t) {
    return t->unk_28 != 1 ? 0 : t->unk_30;
}

static inline BOOL TaskHasVal(Task118 *t) {
    return (TaskVal(t) != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

#define PMF_PTR(f) (*(void **)&(f))

static inline CmdPmf GetFn(s32 kind) {
    if (kind == 0) {
        return NULL;
    }
    return data_ov000_021cc1a4[kind].fn;
}

static inline void Start(CmdObj *self, u16 a, u16 b, s32 kind) {
    if (kind != 0) {
        self->unk_9c = data_ov000_021cc1a4[kind].fn;
    } else {
        self->unk_9c = NULL;
    }
    self->unk_98 = kind;
    self->unk_a4 = a;
    self->unk_a6 = b;
    self->unk_a8 = 0;
}

static inline BOOL IsFe(CmdEx *self) {
    BOOL r = FALSE;
    if (self->unk_b4 == 0xfe) {
        r = TRUE;
    }
    return r;
}

s32 func_ov000_02189194(CmdEx *self) {
    BOOL ret = FALSE;
    s32 busy;
    CmdPmf g;
    CmdPmf f;
    if (self->state != 5) {
        busy = 0;
    } else if (!HasCmd(self)) {
        if (IsMode(4)) {
            func_0203cb78(0xa000, 0, 0);
        }
        if (Busy()) {
            busy = 0;
        } else if (Locked()) {
            busy = 1;
        } else {
            if (self->unk_ca.c[0] != 0xfe) {
                Player *p = func_ov000_0219bf90();
                if (p != NULL && p->f0 == 0) {
                    p->unk_15 = 1;
                    p->f0 = 0;
                    p->f2 = 0;
                }
            }
            self->state = 3;
            busy = 0;
        }
    } else {
        s32 i;
        PlayerIdle();
        self->step = 0;
        self->state = 6;
        i = self->rd;
        {
            s32 arg = self->args[i];
            u16 hi = (u32)arg >> 16;
            u16 lo = arg;
            Start(self, lo, hi, self->kinds[i]);
        }
        {
            f = self->unk_9c;
            if (PMF_PTR(f)) {
                busy = (self->*f)();
            } else {
                busy = 0;
            }
        }
    }
    if (busy) {
        return 1;
    }
    func_ov000_02188ed0(self);
    switch (self->state) {
    case 2:
        self->state = 3;
        func_02049564(data_02097e4c, 1, 1);
        {
            Obj02097e48 *p = data_02097e48;
            if (p->flag) {
                p->unk_06 = 0x8000;
                p->unk_08 = 0x1e;
                p->unk_02 = 0;
            }
        }
        {
            Obj02097e48 *p = data_02097e48;
            p->unk_74 = 0x8000;
            p->unk_70 = 0;
        }
        CmdObj_Push(self, 0x26, 2);
        CmdObj_Push(self, 0x21, 0);
        ret = TRUE;
        break;
    case 3:
        if (HasCmd(self)) {
            self->state = 5;
            PlayerIdle();
            break;
        }
        {
            Player *p = func_ov000_0219bf90();
            if (p != NULL) {
                u16 trg = data_02097dc8->unk_12;
                if (trg & 0x400) {
                    func_ov000_021721f4(data_ov000_021ccd30);
                } else if (trg & 8) {
                    CmdEx *obj = data_ov000_021ccd50.obj;
                    if (!HasCmd(obj) && !HasD4(obj)) {
                        BOOL ok = FALSE;
                        if (p->vfunc_14() && !B2e(p)) {
                            ok = TRUE;
                        }
                        if (ok) {
                            u16 n = 0;
                            Item *it;
                            for (it = data_ov000_021ccd50.obj->unk_bc; it != NULL; it = it->unk_d4) {
                                if (n == 0) {
                                    break;
                                }
                                if (it->vfunc_34()) {
                                    n++;
                                }
                            }
                            if (it != NULL) {
                                if ((it->unk_c6 == 9 && it->unk_ca >= 3) || (it->unk_c6 == 0x22 && it->unk_ca >= 3) ||
                                    (it->unk_c6 == 0x35 && it->unk_ca >= 3)) {
                                    CmdObj_Push(self, 0x10, 2);
                                }
                            }
                        }
                    }
                }
            }
        }
        ret = TRUE;
        break;
    case 6: {
        g = self->unk_9c;
        if (PMF_PTR(g)) {
            if ((self->*g)()) {
                ret = TRUE;
            }
        } else {
            CmdObj_Done(self);
        }
        break;
    }
    case 4:
        if (IsMode(3)) {
            break;
        }
        if (!func_ov000_02181d70(&self->unk_ac, 0xffff)) {
            break;
        }
        func_02062424(&self->unk_cd);
        func_0204aa10(data_02097e48);
        data_02097e48->b2 = 0;
        self->unk_d0 = self->unk_ca;
        self->unk_ca = self->unk_cd;
        BITS0E(self).mode = 2;
        if (data_ov000_021ccd30->unk_11c != NULL && data_ov000_021ccd30->unk_11c->unk_7c != NULL) {
            func_ov000_0216bcbc(data_ov000_021ccd30->unk_11c->unk_7c);
        }
        {
            Mgr021ccd30 *mgr = data_ov000_021ccd30;
            BOOL has;
            if (mgr->unk_118 == NULL) {
                has = FALSE;
            } else {
                has = TaskHasVal(mgr->unk_118);
            }
            if (has) {
                func_ov000_021645a4(TaskVal(mgr->unk_118));
            }
        }
        self->unk_18c = 0;
        self->unk_18d = 0;
        self->unk_18e = 0;
        self->unk_18f = 0;
        func_020656b4(data_0214a420);
        func_ov000_021b53f4(data_ov000_021ccd6c);
        func_ov000_0218be9c(data_ov000_021ccd64);
        func_ov000_0218e894(data_ov000_021ccd68);
        {
            self->unk_ac = 1;
            self->unk_ca.c[0] = 0xff;
            self->unk_ca.c[1] = 0xff;
            self->unk_ca.c[2] = 0xff;
            self->unk_cd.c[0] = 0xff;
            self->unk_cd.c[1] = 0xff;
            self->unk_cd.c[2] = 0xff;
            if (self->unk_b4 == 0xfe ? TRUE : FALSE) {
                Obj02097d48 *d = data_02097d48;
                d->b4 = 0;
                d->b5 = 1;
                *(vu16 *)0x4000060 &= 0xcfdf;
            }
        }
        self->state = 3;
        break;
    }
    return ret;
}
}
