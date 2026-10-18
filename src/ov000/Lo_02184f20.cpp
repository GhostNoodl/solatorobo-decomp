#include "ov000/CmdObj.h"
#include "ov000/VObj.h"

typedef struct {
    u8 c[3];
} Id3;

class Item : public VObj {
public:
    u8 pad_04[0xc2];
    u16 unk_c6;
    u8 pad_c8[2];
    u16 unk_ca;
    u16 unk_cc;
    u8 pad_ce[6];
    Item *unk_d4;
};

class CmdEx : public CmdObj {
public:
    u8 pad_ac[0x10];
    Item *unk_bc;
    u8 pad_c0[9];
    u8 unk_c9;
    Id3 unk_ca;
    Id3 unk_cd;
};

typedef struct {
    u8 pad_00[4];
    CmdEx *obj;
} State021ccd50;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
} Obj02097e48;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 31;
} Bits54;

typedef struct {
    u8 pad_00[0x54];
    Bits54 *unk_54;
} Task11c;

typedef struct {
    u8 pad_00[0x11c];
    Task11c *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x60c];
    u32 unk_60c[2];
} Obj0214a424;

extern "C" {
extern State021ccd50 data_ov000_021ccd50;
extern Flags021ccd44 *data_ov000_021ccd44;
extern void *data_02149ef8;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern Obj02097e48 *data_02097e48;
extern Obj0214a424 *data_0214a424;

void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
s32 func_02061d54(s32 a);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_02172390(void *mgr, s32 a, void *b);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
s32 func_02062834(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline void Warp(const Id3 *id, s32 arg) {
    data_02097e48->b1 = 1;
    CmdObj_Push(data_ov000_021ccd50.obj, 9, arg);
    if (id != NULL) {
        data_ov000_021ccd50.obj->unk_cd = *id;
    }
}

static inline BOOL Busy(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 0xf)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_0217060c(mgr->unk_11c);
    }
    return r;
}

s32 func_ov000_02184f20(CmdEx *self) {
    u16 mode = self->unk_a4;
    u16 arg = self->unk_a6;
    switch (mode) {
    case 0:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xc, arg);
            self->step++;
            return 0;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            return 1;
        }
        break;
    case 1:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xd, arg);
            self->step++;
            return 0;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            return 1;
        }
        break;
    case 2:
        switch (self->step) {
        case 0:
            func_ov000_02172390(data_ov000_021ccd30, 0, func_0204c0e8(data_02149ef8, func_02061d54(0x28)));
            self->step++;
            return 0;
        case 1:
            if (!Busy()) {
                CmdObj_Done(self);
                if (func_02062834() == 1) {
                    u16 n = 0;
                    Item *p;
                    for (p = data_ov000_021ccd50.obj->unk_bc; p != NULL; p = p->unk_d4) {
                        if (n == 0) {
                            break;
                        }
                        if (p->vfunc_34()) {
                            n++;
                        }
                    }
                    if (p != NULL) {
                        Bits54 *b = data_ov000_021ccd30->unk_11c->unk_54;
                        if (b != NULL) {
                            b->b0 = 1;
                        }
                        switch (p->unk_c6) {
                        case 9: {
                            Id3 id;
                            p->unk_ca = 3;
                            data_ov000_021ccd50.obj->unk_c9 = 1;
                            id.c[0] = 0x11;
                            id.c[1] = 3;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        case 0x22: {
                            Id3 id;
                            p->unk_ca = 3;
                            data_ov000_021ccd50.obj->unk_c9 = 1;
                            id.c[0] = 7;
                            id.c[1] = 6;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        case 0x35: {
                            Id3 id;
                            u32 i;
                            Obj0214a424 *q;
                            p->unk_ca = 3;
                            p->unk_cc = 0;
                            q = data_0214a424;
                            for (i = 0; i < 2; i++) {
                                if ((q->unk_60c[i] & ~0xff) == 0x9030c00) {
                                    q->unk_60c[i] = -1;
                                }
                            }
                            data_ov000_021ccd50.obj->unk_c9 = 1;
                            id.c[0] = 0xc;
                            id.c[1] = 3;
                            id.c[2] = 0;
                            Warp(&id, 1);
                            break;
                        }
                        }
                    }
                }
            }
            return 0;
        }
        break;
    }
    return 1;
}
}
