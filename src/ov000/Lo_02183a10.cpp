#include "ov000/CmdObj.h"

typedef struct {
    u8 c[3];
} Id3;

class CmdEx : public CmdObj {
public:
    u8 unk_ac;
    u8 pad_ad[3];
    s32 unk_b0;
    u8 pad_b4[0x14];
    u8 unk_c8;
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
    u8 pad_02[0x6e];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[0x114];
    u32 b0 : 1;
    u32 b1 : 1;
} Mgr021ccd30;

typedef struct {
    u8 pad_00[0xb1c];
    u16 unk_b1c;
} Obj0219bf90;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
} Actor0218e640;

typedef struct {
    u8 pad_00[0xa];
    u8 unk_0a;
} Obj021ccd6c;

typedef struct {
    u8 pad_00[0x24];
    u16 unk_24;
    u16 unk_26;
    u8 pad_28[0x1e];
    u16 unk_46;
} Dtcm02fe1534;

extern "C" {
extern State021ccd50 data_ov000_021ccd50;
extern s32 data_02097d78[];
extern Obj02097e48 *data_02097e48;
extern void *data_ov000_021ccd68;
extern Dtcm02fe1534 data_02fe1534;
extern Obj021ccd6c *data_ov000_021ccd6c;
extern void *data_0214a424;
extern void *data_02097e4c;
extern Mgr021ccd30 *data_ov000_021ccd30;
Obj0219bf90 *func_ov000_0219bf90(void);
Actor0218e640 *func_ov000_0218e640(void *mgr, u16 id);
void func_02062478(Id3 *id);
void func_ov000_02182590(u8 *p);
void func_020624b8(void);
void func_0206c72c(void *p, Id3 *id);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_02062424(Id3 *id);
BOOL func_ov000_02181d70(u8 *p);
void func_02049564(void *p, s32 a, s32 b);

static inline BOOL IsMode1(void) {
    BOOL r;
    if (data_02097d78[3] == 1) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 1;
    }
    return r;
}

static inline BOOL IsMode0(void) {
    return data_02097d78[3] == 0 && data_02097d78[0] == 0;
}

static inline BOOL IdEq(const Id3 *a, const Id3 *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

s32 func_ov000_02183a10(CmdEx *self) {
    BOOL hasArg;
    s32 fade;
    if (self->step == 0) {
        self->step++;
        return 0;
    }
    if (IsMode1()) {
        return 0;
    }
    hasArg = TRUE;
    if (self->unk_a4 == 0) {
        hasArg = FALSE;
    }
    CmdObj_Done(self);
    data_02097e48->b1 = 0;
    if ((self->unk_b0 != 0 ? TRUE : FALSE)) {
        Obj0219bf90 *obj;
        self->unk_c8 = 0;
        obj = func_ov000_0219bf90();
        if (obj != NULL) {
            Actor0218e640 *actor = NULL;
            u16 id = obj->unk_b1c;
            if (data_ov000_021ccd68 != NULL) {
                actor = func_ov000_0218e640(data_ov000_021ccd68, id);
            }
            if (actor != NULL) {
                data_02fe1534.unk_24 = actor->unk_0e;
                data_02fe1534.unk_26 = actor->unk_0c;
            }
        }
        func_02062478(&self->unk_cd);
        self->unk_ac = 1;
        func_ov000_02182590(&self->unk_ac);
        func_020624b8();
        if (self->unk_c8) {
            self->unk_c8 = 0;
            data_ov000_021ccd6c->unk_0a = 0xff;
            self->unk_cd.c[0] = 0xff;
            self->unk_cd.c[1] = 0xff;
            self->unk_cd.c[2] = 0xff;
            self->state = 3;
            return 0;
        }
    }
    if (hasArg) {
        func_0206c72c(data_0214a424, &self->unk_cd);
    }
    fade = 0xf000;
    if (self->unk_c9) {
        fade = 0x1000;
    }
    if (IsMode0()) {
        func_0203c9e8(0x3f, 0);
        func_0203cc58(fade, 2, 0);
    }
    if (data_02fe1534.unk_46 == self->unk_cd.c[0]) {
        if (IdEq(&data_ov000_021ccd50.obj->unk_ca, &self->unk_cd) && self->unk_c9 == 0) {
            if (func_ov000_0219bf90() == NULL) {
                CmdObj_Push(data_ov000_021ccd50.obj, 0xb, 0);
            }
            data_02097e48->b1 = 1;
            CmdObj_Push(data_ov000_021ccd50.obj, 0xa, 0);
            if (&self->unk_cd != NULL) {
                data_ov000_021ccd50.obj->unk_cd = self->unk_cd;
            }
            self->state = 3;
        } else {
            func_02062424(&self->unk_cd);
            data_ov000_021ccd50.obj->unk_ac = 1;
            self->unk_cd.c[0] = 0xff;
            self->unk_cd.c[1] = 0xff;
            self->unk_cd.c[2] = 0xff;
            self->state = 3;
        }
    } else {
        func_ov000_02181d70(&self->unk_ac);
        self->state = 4;
    }
    func_02049564(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    data_ov000_021ccd30->b1 = 0;
    return 0;
}
}
