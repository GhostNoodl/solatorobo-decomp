#include "ov000/CmdObj.h"

typedef struct {
    u8 pad_00[8];
    void (*unk_08)(void);
    void (*unk_0c)(void);
    void (*unk_10)(void);
} Data021ccd50;

typedef struct {
    u8 pad_00[0x11c];
    void *unk_11c;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
} Mgr118;

typedef struct {
    u8 pad_00[0x149];
    u8 unk_149;
} Obj02097e3c;

typedef struct {
    u8 pad_00[0x12];
    u16 unk_12;
} Obj02097dc8;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
} Ov002Obj021f0f9c;

typedef struct {
    u8 pad_00[0x5b];
    u8 unk_5b;
} Obj02097e4c;

typedef struct {
    u8 pad_00[0x7c];
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
} Obj02097e48;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
extern Data021ccd50 data_ov000_021ccd50;
extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern char data_0214b105[];
extern Obj02097e3c *data_02097e3c;
extern Obj02097dc8 *data_02097dc8;
extern void *data_02149ef0;
extern Ov002Obj021f0f9c *data_ov002_021f0f9c;
extern Obj02097e4c *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern u8 OVERLAY_2_ID[];

void func_ov000_0216f844(void *p, s32 a);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_02170568(void *p);
BOOL func_ov000_021708d8(void *p);
BOOL func_ov000_021705a0(void *p, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_02036838(void *a, void *b, int c, int d);
void func_020359d0(void *a, int b, int c);
int func_02035b90(void *a, int b);
void func_0206fa70(void);
void func_0206ea7c(void);
void func_0203caf8(s32 a);
void func_020444b0(void *p, s32 a, s32 b, s32 c);
void func_0206f9dc(void);
void func_0206e9e8(void);
void func_02044524(void *p);
BOOL func_0206facc(void);
BOOL func_0206ead8(void);
void func_0206faec(void);
void func_0206eaf8(void);
void func_0204b270(void *p, s32 a, s32 b);
void func_ov000_021857e0(void);
void func_ov000_021857ec(void);
void func_ov000_021857f8(void);
void func_ov002_021e8f04(s32 a);
void func_0204a2a8(void *p, s32 a, s32 b);

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd50.unk_0c != NULL) {
        data_ov000_021ccd50.unk_0c();
    }
    data_ov000_021ccd50.unk_0c = NULL;
    data_ov000_021ccd50.unk_08 = NULL;
    data_ov000_021ccd50.unk_10 = NULL;
}

static inline BOOL Busy14(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (mgr == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(mgr, 0x10)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x11)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x12)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x13)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_02170568(mgr->unk_11c);
    }
    return r;
}

static inline BOOL Busy17(void) {
    BOOL r;
    Mgr021ccd30 *mgr = data_ov000_021ccd30;
    if (func_ov000_0216f674(mgr, 0x14)) {
        r = TRUE;
    } else if (func_ov000_0216f674(mgr, 0x15)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021708d8(mgr->unk_11c);
    }
    return r;
}

static inline BOOL Busy18(s32 a) {
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
        r = func_ov000_021705a0(mgr->unk_11c, a);
    }
    return r;
}

static inline BOOL Busy1a(void) {
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

s32 func_ov000_021859c4(CmdObj *self) {
    switch (self->unk_98) {
    case 0x14:
        if (self->step == 0) {
            Mgr118 *m = (Mgr118 *)data_ov000_021ccd30;
            if (m->unk_118 != NULL) {
                func_ov000_0216f844(m->unk_118, 1);
            }
            self->step++;
            return 0;
        }
        if (Busy14()) {
            return 1;
        }
        CmdObj_Done(self);
        break;
    case 0x15:
        switch (self->step) {
        case 0:
            func_02036838(data_02097cdc, data_0208cc94, 7, 0);
            func_02036838(data_02097cdc, data_0208cca0, 7, 0);
            func_02036838(data_02097cdc, data_0214b105, 7, 0);
            func_0206fa70();
            func_0206ea7c();
            func_0203caf8(-1);
            func_020444b0(data_02097e3c, self->unk_a4, -1, 0);
            self->step++;
            return 0;
        case 1:
            if (data_02097e3c->unk_149 == 0) {
                func_020359d0(data_0214b105, 7, 0);
                func_020359d0(data_0208cca0, 7, 0);
                func_020359d0(data_0208cc94, 7, 0);
                func_0206f9dc();
                func_0206e9e8();
                self->step++;
            } else if (data_02097dc8->unk_12 & 8) {
                func_02044524(data_02097e3c);
            }
            break;
        case 2: {
            BOOL ok = TRUE;
            if (!func_02035b90(data_0214b105, 7)) {
                ok = FALSE;
            }
            if (!func_02035b90(data_0208cca0, 7)) {
                ok = FALSE;
            }
            if (!func_02035b90(data_0208cc94, 7)) {
                ok = FALSE;
            }
            if (!func_0206facc()) {
                ok = FALSE;
            }
            if (!func_0206ead8()) {
                ok = FALSE;
            }
            if (ok) {
                func_0206faec();
                func_0206eaf8();
                CmdObj_Push(self, 0x26, 0);
                CmdObj_Done(self);
            }
            break;
        }
        }
        break;
    case 0x16:
        if (self->step == 0) {
            u16 id = self->unk_a4;
            func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
            data_ov000_021ccd50.unk_0c = func_ov000_021857e0;
            data_ov000_021ccd50.unk_08 = func_ov000_021857ec;
            data_ov000_021ccd50.unk_10 = func_ov000_021857f8;
            func_ov002_021e8f04(id);
            self->step++;
            return 0;
        }
        {
        u16 mode = self->unk_a4;
        u16 t = self->unk_a8;
        if (mode == 0x5c) {
            if (t == 0x708) {
                if (data_ov002_021f0f9c->unk_04 >= 4) {
                    Obj02097e48 *p;
                    data_02097e4c->unk_5b = 1;
                    p = data_02097e48;
                    if (!(p->unk_80 == 0xffff && p->unk_7e == 0x88)) {
                        p->unk_80 = 0x88;
                        p->unk_7c = 0;
                    }
                    func_0204a2a8(data_02097e4c, 0, 0);
                    t = 1;
                }
            } else {
                t++;
            }
            self->unk_a8 = t;
        }
        }
        if (data_ov002_021f0f9c->unk_04 == 7) {
            ClearCallbacks();
            CmdObj_Push(self, 0x26, 0);
            CmdObj_Done(self);
        }
        break;
    case 0x17:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (!Busy17()) {
            CmdObj_Done(self);
        }
        return 1;
    case 0x18:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (Busy18(1)) {
            break;
        }
        CmdObj_Done(self);
        break;
    case 0x19:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (Busy18(0)) {
            break;
        }
        CmdObj_Done(self);
        break;
    case 0x1a:
        if (self->step == 0) {
            self->step++;
            return 0;
        }
        if (!Busy1a()) {
            CmdObj_Done(self);
        }
        return 1;
    }
    return 0;
}
}
