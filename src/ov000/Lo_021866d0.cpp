#include "ov000/CmdObj.h"
#include "nitro/fx.h"

typedef struct {
    u16 b0 : 3;
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
    u8 pad_00[0x118];
    void *unk_118;
    void *unk_11c;
} Mgr021ccd30;

typedef struct {
    VecFx32 base;
    u8 pad_0c[8];
    s16 x;
    s16 y;
    s16 z;
    u8 pad_1a[0xa];
} Spot021ccd6c;

typedef struct {
    u8 pad_00[0xb];
    u8 cur;
    u8 pad_0c[0xc];
    Spot021ccd6c *spots;
} Obj021ccd6c;

typedef struct {
    u8 pad_00[0x15];
    u8 unk_15;
    u8 pad_16[0xaf2];
    s32 unk_b08;
    u8 pad_b0c[4];
    VecFx32 unk_b10;
    u8 pad_b1c[0xc];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 6;
} Obj0219bf90;

typedef struct {
    u8 pad_00[0xac];
    u8 unk_ac;
    u8 pad_ad[0x1d];
    u8 unk_ca;
} CmdObj021866d0;

extern "C" {
extern void *data_02149efc;
extern void *data_02149ef8;
extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
extern Mgr021ccd30 *data_ov000_021ccd30;
extern Obj021ccd6c *data_ov000_021ccd6c;
void func_020623e0(void);
void func_ov000_02182590(u8 *p);
s32 func_02061d54(s32 a);
void *func_0204c0e8(void *p, s32 a);
void func_ov000_02172390(void *mgr, s32 a, void *b);
BOOL func_ov000_0216f674(Mgr021ccd30 *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
BOOL func_02062834(void);
void func_02062500(u8 *p);
void func_02049564(void *p, s32 a, s32 b);
Obj0219bf90 *func_ov000_0219bf90(void);

static inline BOOL Busy0f(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 0xf)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_0217060c(m->unk_11c);
    }
    return r;
}

s32 func_ov000_021866d0(CmdObj *self) {
    BOOL ready;
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        func_020623e0();
        ((CmdObj021866d0 *)self)->unk_ac = 1;
        func_ov000_02182590(&((CmdObj021866d0 *)self)->unk_ac);
        ready = TRUE;
        if (data_02149efc == NULL) {
            ready = FALSE;
        }
        if (ready) {
            CmdObj_Done(self);
            return 1;
        }
        func_ov000_02172390(data_ov000_021ccd30, 0, func_0204c0e8(data_02149ef8, func_02061d54(0x19)));
        self->step++;
        break;
    case 2:
        if (!Busy0f()) {
            CmdObj_Done(self);
            if (!func_02062834()) {
                func_02062500(&((CmdObj021866d0 *)self)->unk_ca);
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
                CmdObj_Push(self, 0x26, 1);
                CmdObj_Push(self, 0x1e, 0);
            } else {
                Obj021ccd6c *g = data_ov000_021ccd6c;
                if (g->cur != 0xff) {
                    Spot021ccd6c *s = &g->spots[g->cur];
                    VecFx32 v;
                    Obj0219bf90 *obj;
                    v.x = s->x << 4;
                    v.y = s->y << 4;
                    v.z = s->z << 4;
                    VEC_Add(&v, &s->base, &v);
                    obj = func_ov000_0219bf90();
                    if (obj != NULL) {
                        obj->unk_15 = 3;
                        obj->unk_b28_0 = 2;
                        obj->unk_b10 = v;
                        obj->unk_b08 = 0x252;
                    }
                }
            }
            data_ov000_021ccd6c->cur = 0xff;
        }
        return 0;
    }
    return 1;
}
}
