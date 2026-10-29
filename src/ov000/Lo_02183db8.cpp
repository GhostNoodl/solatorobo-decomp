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

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[0x1b];
    u8 unk_c8;
    u8 unk_c9;
    Id3 unk_ca;
    Id3 unk_cd;
    Id3 unk_d0;
    u8 pad_d3[0xb9];
    u8 unk_18c;
    u8 unk_18d;
    u8 unk_18e;
    u8 unk_18f;
};

#define BITS0E(self) (*(Bits0e *)((u8 *)(self) + 0xe))

typedef struct {
    u8 pad_00[4];
    CmdEx *obj;
} State021ccd50;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
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
    u8 pad_00[0xc];
    u8 b0 : 1;
    u8 b1 : 7;
} Obj021ccd64;

typedef struct {
    u8 pad_00[0x8b0];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Obj02097d48;

typedef struct {
    u8 pad_00[0x15];
    u8 unk_15;
    u8 pad_16[0xb12];
    u8 f0 : 2;
    u8 f2 : 1;
    u8 f3 : 5;
} Obj0219bf90;

class Player : public VObj {
public:
    u8 pad_04[0x8f];
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
};

typedef struct {
    u8 pad_00[0x22];
    u16 unk_22;
} Ov004Obj;

typedef BOOL (*ProtFn)(u32 addr, s32 arg);

typedef struct {
    u8 pad_00[0x2c];
    s32 unk_2c;
} OvMgr;

extern "C" {
extern State021ccd50 data_ov000_021ccd50;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern OvMgr *data_02149ef0;
extern s32 data_02097d78[];
extern Obj021ccd64 *data_ov000_021ccd64;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a420;
extern void *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern Obj02097d48 *data_02097d48;
extern u32 data_ov004_021cf868;
extern ProtFn data_ov004_021cf86c[];
extern u8 OVERLAY_3_ID[];
extern u8 OVERLAY_4_ID[];

Player *func_ov000_0219bf90(void);
void func_0204b270(void *p, s32 a, s32 b);
Ov004Obj *func_ov004_021cce88(void);
void func_ov004_021ccf10(void);
BOOL func_ov004_021ce2ec(u32 addr, s32 arg);
BOOL func_ov004_021ce374(u32 addr, s32 arg);
BOOL func_ov004_021ce3fc(u32 addr, s32 arg);
bool func_ov003_021ce484(u32 addr, s32 arg);
void func_0204aa10(void *p);
void func_ov000_0216bcbc(void *p);
void func_ov000_021645a4(s32 a);
void func_020656b4(void *p);
void func_ov000_021b53f4(void *p);
void func_ov000_0218be9c(void *p);
void func_ov000_0218e894(void *p);
void func_ov000_0216f6d0(Mgr021ccd30 *p, s32 a, s32 b, s32 c);
BOOL func_ov000_021b5578(void *p);
void func_ov000_021b5dc0(void *p);
void func_ov000_021b628c(void *p);
void func_ov003_021cfa30(void);
void func_ov000_0218c25c(void *p);
void func_ov000_0218be54(void *p);
BOOL func_ov000_0218e470(void *p);
void func_ov000_0216f844(Task118 *p, s32 a);

static inline u32 ProtHash(const u32 *p) {
    u32 i;
    u32 h;
    for (i = 0x1c, h = 0; i != 0; i--, p++) {
        h ^= (*p >> i) | (*p << (32 - i));
    }
    return h;
}

static inline BOOL IsMode3(void) {
    BOOL r;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 3;
    }
    return r;
}

static inline BOOL IdEq(const Id3 *a, const Id3 *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 TaskVal(Task118 *t) {
    return t->unk_28 != 1 ? 0 : t->unk_30;
}

static inline BOOL TaskHasVal(Task118 *t) {
    return (TaskVal(t) != 0 ? TRUE : FALSE) ? TRUE : FALSE;
}

s32 func_ov000_02183db8(CmdEx *self) {
    Player *pl = func_ov000_0219bf90();
    u16 sub = self->unk_a8;
    switch (self->step) {
    case 0:
        if ((s32)OVERLAY_3_ID != data_02149ef0->unk_2c) {
            Ov004Obj *obj;
            BOOL r;
            func_0204b270(data_02149ef0, (s32)OVERLAY_4_ID, 0);
            obj = func_ov004_021cce88();
            if (ProtHash((const u32 *)func_ov004_021ce2ec) == 0x786385f) {
                r = func_ov004_021ce2ec(0x2001000, 0);
            } else {
                r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001000, 0);
            }
            if (r) {
                obj->unk_22 = 1;
            } else {
                if (ProtHash((const u32 *)func_ov004_021ce374) == 0x786385f) {
                    r = func_ov004_021ce374(0x2001800, 0);
                } else {
                    r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001800, 0);
                }
                if (r) {
                    obj->unk_22 = 2;
                } else {
                    if (ProtHash((const u32 *)func_ov004_021ce3fc) == 0x786385f) {
                        r = func_ov004_021ce3fc(0x2001c00, 0x2001e00);
                    } else {
                        r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2001c00, 0x2001e00);
                    }
                    if (r) {
                        obj->unk_22 = 3;
                    } else {
                        if (ProtHash((const u32 *)func_ov003_021ce484) == 0x786385f) {
                            r = func_ov003_021ce484(0x2002000, 0);
                        } else {
                            r = data_ov004_021cf86c[data_ov004_021cf868 ^ 1](0x2002000, 0);
                        }
                        if (r) {
                            obj->unk_22 = 4;
                        }
                    }
                }
            }
            func_ov004_021ccf10();
            func_0204b270(data_02149ef0, (s32)OVERLAY_3_ID, 0);
        }
        self->step++;
        return 0;
    case 1:
        if (IsMode3()) {
            break;
        }
        data_ov000_021ccd64->b0 = 1;
        if (self->unk_cd.c[0] != 0xff) {
            if (!IdEq(&data_ov000_021ccd50.obj->unk_ca, &self->unk_cd) || self->unk_c9 != 0) {
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
            } else {
                self->unk_d0 = self->unk_ca;
                self->unk_ca = self->unk_cd;
            }
        }
        {
            Obj0219bf90 *p = (Obj0219bf90 *)func_ov000_0219bf90();
            if (p != NULL && p->f0 == 0) {
                p->unk_15 = 3;
                p->f0 = 0;
                p->f2 = 1;
            }
        }
        if (pl != NULL) {
            pl->b4 = 0;
            if (data_ov000_021ccd30 != NULL) {
                func_ov000_0216f6d0(data_ov000_021ccd30, 0x14, 1, 0);
            }
            if (data_ov000_021ccd30 != NULL) {
                func_ov000_0216f6d0(data_ov000_021ccd30, 0x14, 2, 0);
            }
        }
        self->step++;
    case 2: {
        self->unk_cd.c[0] = 0xff;
        self->unk_cd.c[1] = 0xff;
        self->unk_cd.c[2] = 0xff;
        if (self->unk_ca.c[0] == 0xfe) {
            Obj02097d48 *d;
            self->unk_a8 = 2;
            d = data_02097d48;
            d->b4 = 0;
            d->b5 = 1;
            *(vu16 *)0x4000060 &= 0xcfdf;
        }
        self->step++;
        break;
    }
    case 3:
        switch (sub) {
        case 0:
            if (pl == NULL || pl->vfunc_0c()) {
                self->unk_a8 = sub + 1;
            }
            break;
        case 1:
            if (func_ov000_021b5578(data_ov000_021ccd6c)) {
                func_ov000_021b5dc0(data_ov000_021ccd6c);
                func_ov000_021b628c(data_ov000_021ccd6c);
                func_ov003_021cfa30();
                func_ov000_0218c25c(data_ov000_021ccd64);
                if (data_ov000_021ccd64 != NULL) {
                    func_ov000_0218be54(data_ov000_021ccd64);
                }
                self->unk_a8 = sub + 1;
            }
            break;
        case 2:
            if (func_ov000_0218e470(data_ov000_021ccd68)) {
                if (data_ov000_021ccd30->unk_118 != NULL) {
                    func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
                }
                if (self->unk_ca.c[0] != 0xfe) {
                    BITS0E(self).mode = 0;
                }
                self->unk_c9 = 0;
                CmdObj_Done(self);
                data_02097e48->b1 = 0;
                return 1;
            }
            break;
        }
        break;
    }
    return 0;
}
}
