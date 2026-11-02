#include "ov000/LoCommon.h"
#include "ov000/CmdQueue.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 state;
    u16 timer;
} St021ad130;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} B44_021ad130;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 8;
    u16 b9 : 2;
    u16 rest : 5;
} Bc2_021ad130;

typedef struct {
    s32 w[3];
} Ids021ad130;

typedef struct {
    u16 v[3];
} Ids16_021ad130;

typedef struct {
    u8 pad[0xa];
    Ids16_021ad130 ids;
} Def021ad130;

extern "C" {
extern u8 data_ov000_021cc6de[];
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc618[];
extern void *data_0214a424;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd68;
extern const u8 data_ov000_021c9fe8[3];
extern const u8 data_ov000_021c9feb[3];
extern const u8 data_ov000_021c9fee[3];
extern const Ids16_021ad130 data_ov000_021c9ff2;
const u8 data_ov000_021c9fee[3] = {0x11, 0, 0};
const u8 data_ov000_021c9feb[3] = {0x11, 0, 2};
const u8 data_ov000_021c9fe8[3] = {0x11, 0, 0};
const Ids16_021ad130 data_ov000_021c9ff2 = {{0x127, 0x310, 0}};
extern Ids021ad130 data_ov000_021ca018;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
u8 func_0206d204(void *p, s32 a);
VObj *func_02065f88(s32 id, void *pos);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
u8 *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
s32 Rand_UpTo(s32 max);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void *func_0204a028(void *a, s32 b, void *c, s32 d);
void func_ov000_0218996c(s32 a, s32 b);
void func_02062410(void);
void func_ov000_02182590(void *p);
BOOL func_0205b29c(u16 *ids);
void func_ov000_02186dbc(void *g);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02198360(void *st, s32 a, s32 b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);

static inline void Fx021ad130(Robo021ca458 *self) {
    VecFx32 v;
    v = *(VecFx32 *)((u8 *)self + 0x70);
    v.y += self->unk_68;
    func_ov000_021899d8(&v, 0, 0x8ccd, 1, 0x1000, 0x1000);
}

static inline BOOL QHas021ad130(const s32 *w) {
    u8 *q = data_ov000_021ccd54;
    s32 i;
    for (i = LFLD(s32, q, 0x90); i != LFLD(s32, q, 0x94);) {
        const s32 *p = w;
        while (*p != 0) {
            if (*p++ == ((s32 *)(q + 0x10))[i]) {
                return TRUE;
            }
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline void Spawn021ad130(Robo021ca458 *self, s32 id, s32 scale) {
    VObj *e = func_02065f88(id, (u8 *)self + 0x70);
    if (e != NULL) {
        e->vfunc_0c(scale);
        LFLD(s32, e, 0x3c) = 0xb33;
        if (self->unk_b22_6 == 5) {
            e->vfunc_24(0, 0x1800, 0);
            e->vfunc_0c(0x3000);
        }
    }
}

void func_ov000_021ad130(Robo021ca458 *self) {
    switch (((St021ad130 *)self->unk_40)->state) {
    case 0: {
        s32 r;
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc6de, 0x400, 0);
        r = func_0206d204(data_0214a424, 1);
        if (r != 0) {
            u8 *p;
            ((St021ad130 *)self->unk_40)->state = 10;
            p = ((u8 *)self->hp);
            LFLD(u16, p, 0) = (s32)(r * LFLD(u16, p, 2)) / 100;
            func_02065f88(0xcb, (u8 *)self + 0x70)->vfunc_14(0x99a, 0x1800, 0x99a);
            break;
        }
        if (self->unk_b24_1) {
            ((St021ad130 *)self->unk_40)->timer = 0;
        } else {
            ((St021ad130 *)self->unk_40)->timer = 0xd2;
        }
        if (self->unk_b32 < 0xa0) {
            self->unk_b32 = 0xa0;
        }
        {
            u8 *m = (u8 *)self->unk_38;
            LFLD(Bc2_021ad130, m, 0xc2).b9 = 2;
            NNSi_G3dModifyPolygonAttrMask(LFLD(void *, m, 4), 0, 0xc0);
        }
    next:
        ((St021ad130 *)self->unk_40)->state++;
        break;
    }
    case 1: {
        if (self->unk_b24_1) {
            u16 t = ((St021ad130 *)self->unk_40)->timer;
            if (t <= 0xfa) {
                if (t % 25 == 0) {
                    s32 a = -1;
                    s32 b = 0;
                    VecFx32 pos;
                    VecFx32 ext;
                    u8 *hit;
                    switch (t % 100) {
                    case 0:
                        a = 0x322;
                        b = 100;
                        break;
                    case 0x32:
                        a = 6;
                        b = 0x4b;
                        break;
                    }
                    pos = *(VecFx32 *)((u8 *)self + 0x70);
                    pos.y += self->unk_6c;
                    ext.x = self->unk_64;
                    ext.y = self->unk_68 >> 2;
                    ext.z = self->unk_64;
                    hit = func_ov000_0219b71c(&pos, &ext, 0x400, 0x666, a, b);
                    if (hit != NULL) {
                        s32 k = LFLD(s32, hit, 0x20);
                        if (k != 4) {
                            if (k == 0x322) {
                                func_02049f44(data_02097e4c, Rand_UpTo(2) + 0x78, (u8 *)self + 0x70, 0);
                            }
                        } else {
                            func_0204a028(data_02097e4c, 0x35, (u8 *)self + 0x70, 8);
                        }
                    }
                }
            } else if (t == 0x118) {
                VObj *e = func_02065f88(5, (u8 *)self + 0x70);
                if (e != NULL) {
                    e->vfunc_0c(0x2800);
                    LFLD(s32, e, 0x3c) = 0x800;
                    if (self->unk_b22_6 == 5) {
                        e->vfunc_24(0, 0x1800, 0);
                        e->vfunc_0c(0x3000);
                    }
                }
                e = func_02065f88(0x66, (u8 *)self + 0x70);
                if (e != NULL) {
                    e->vfunc_0c(0x28cd);
                    LFLD(s32, e, 0x3c) = 0xb33;
                    if (self->unk_b22_6 == 5) {
                        e->vfunc_24(0, 0x1800, 0);
                        e->vfunc_0c(0x3000);
                    }
                }
                func_0204a028(data_02097e4c, 0x56, (u8 *)self + 0x70, -5);
                func_ov000_0218996c(0x14, 0x3c);
                LFLD(Bc2_021ad130, self->unk_38, 0xc2).b0 = 0;
                LFLD(u8, self->unk_3c, 0x19) = 0;
            }
        }
        if (((St021ad130 *)self->unk_40)->timer == 300) {
            func_02062410();
            {
                u8 *g = data_ov000_021ccd54;
                LFLD(u8, g, 0xac) = 1;
                func_ov000_02182590(g + 0xac);
            }
            {
                Ids021ad130 ids = data_ov000_021ca018;
                Ids16_021ad130 ids16 = data_ov000_021c9ff2;
                if (!QHas021ad130(ids.w) && !func_0205b29c(ids16.v)) {
                    func_ov000_02186dbc(data_ov000_021ccd54);
                }
            }
            ((St021ad130 *)self->unk_40)->state++;
        }
        if (((St021ad130 *)self->unk_40)->timer <= 0x11d) {
            Fx021ad130(self);
        }
        ((St021ad130 *)self->unk_40)->timer++;
        break;
    }
    case 10:
        if (func_ov000_02191120(self->unk_38)) {
            St021ad130 *st = (St021ad130 *)self->unk_40;
            st->timer++;
            if (st->timer > 0x3c) {
                VObj *e = func_02065f88(0xc9, (u8 *)self + 0x70);
                s32 sc = 0x4800;
                self->unk_b44 = LFLD(s32, e, 0x24);
                if (self->unk_b22_6 == 5) {
                    sc = 0x8000;
                }
                e->vfunc_0c(sc);
                LFLD(B44_021ad130, self->unk_44, 0x22).b1 = 0;
                ((St021ad130 *)self->unk_40)->timer = 0;
                goto next;
            }
        }
        break;
    case 11: {
        St021ad130 *st = (St021ad130 *)self->unk_40;
        st->timer++;
        if (st->timer > 0x14) {
            u8 *anm;
            func_02065f88(0x190, (u8 *)self + 0x70);
            anm = data_ov000_021cc5e3;
            if (!self->unk_b24_1 && (LFLD(u32, self->unk_48, 0x50) & 0x400)) {
                anm = data_ov000_021cc618;
            }
            func_ov000_02190cb0(self->unk_38, anm, 0x400, 0);
            LFLD(u16, ((u8 *)self->hp), 0xa) = 0xf0;
            self->unk_b24_0 = 0;
            ((St021ad130 *)self->unk_40)->timer = 0;
            ((St021ad130 *)self->unk_40)->state++;
        }
        Fx021ad130(self);
        LFLD(B44_021ad130, self->unk_44, 0x22).b1 = 0;
        break;
    }
    case 12: {
        St021ad130 *st = (St021ad130 *)self->unk_40;
        st->timer++;
        if (st->timer > 0x2d) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        if (((St021ad130 *)self->unk_40)->timer < 10) {
            Fx021ad130(self);
        }
        break;
    }
    }
    if (self->unk_b22_6 == 5) {
        return;
    }
    LFLD(u16, self->unk_48, 0x9a) |= 0x20;
    if (!(self->msg_flags & 0x80) && LFLD(u16, ((u8 *)self->hp), 0) == 0) {
        return;
    }
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}
}
