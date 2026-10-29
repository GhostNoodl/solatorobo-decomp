#include "types.h"

typedef void (*VFunc)(void *);

extern void func_0203de1c(void *p);
extern void *func_ov000_0219429c(void *p);

void *func_ov003_021f07d8(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021f07ec(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f0808(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021f081c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f0838(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021f084c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}


typedef struct {
    s32 x, y, z;
} Ov003HitVec;

typedef struct {
    u8 unk_00[0x64];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003HitVec pos;
    u8 unk_7c[0xaa8];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
    u32 unk_b24_2 : 10;
    u32 unk_b24_12 : 2;
} Ov003HitPlr;

extern Ov003HitPlr *func_ov000_0219bf90(void);
extern BOOL func_01ffc584(void *a, Ov003HitVec *v, s32 r, s32 h);

Ov003HitPlr *func_ov003_021f0868(void *a, s32 r, s32 h) {
    Ov003HitPlr *ret;
    Ov003HitPlr *p;
    BOOL big;
    s32 rad;
    s32 hh;
    s32 y;
    Ov003HitVec v;
    ret = NULL;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        big = p->unk_b24_1 ? TRUE : FALSE;
        r += 0xccd;
        rad = p->unk_64;
        hh = p->unk_68;
        if (!big) {
            rad >>= 1;
            hh -= hh >> 2;
        }
        rad += r;
        v.x = p->pos.x;
        y = p->pos.y;
        v.y = y;
        v.z = p->pos.z;
        if (p->unk_b24_12 == 0) {
            v.y = y - (h + 0x400);
            hh += h + 0x800;
        } else {
            v.y = y - (h + 0x1000);
            hh += h + 0x4000;
            rad += 0x199a;
        }
        if (func_01ffc584(a, &v, rad, hh)) {
            ret = p;
        }
    }
    return ret;
}

typedef struct Ov003CntActor {
    u8 unk_00[0x8];
    struct Ov003CntActor *next;
    u8 unk_0c[2];
    u16 id;
    u8 unk_10[0x83];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
} Ov003CntActor;

typedef struct {
    u8 unk_00[0xc];
    Ov003CntActor *head;
} Ov003CntGroup;

typedef struct {
    u8 unk_00[0x4];
    u16 ids[2];
} Ov003CntIds;

typedef struct {
    u8 unk_00[0x10];
    Ov003CntIds sub;
} Ov003CntSelf;

extern void *data_ov000_021ccd68;
extern Ov003CntGroup *func_ov000_0218e4cc(void *mgr, u16 key);

s32 func_ov003_021f093c(Ov003CntSelf *self) {
    Ov003CntGroup *g;
    Ov003CntActor *head;
    Ov003CntActor *a;
    s32 r = 0;
    s32 total = 0;
    s32 n = 0;
    BOOL flag = FALSE;
    g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
    if (g != NULL && (a = g->head) != NULL) {
        for (; a != NULL; a = (a != NULL) ? a->next : g->head) {
            BOOL found = FALSE;
            u16 id = a->id;
            Ov003CntIds *ids = &self->sub;
            s32 j;
            for (j = 0; j < 2; j++) {
                if (id == ids->ids[j]) {
                    found = TRUE;
                    break;
                }
            }
            if (found) {
                s32 k;
                total++;
                k = a->unk_93_1;
                if (k != 0) {
                    n++;
                    if (k == 2) {
                        flag = TRUE;
                    }
                }
            }
        }
    }
    if (total != 0) {
        if (n != 0) {
            if (total <= n) {
                if (flag) {
                    r = 4;
                } else {
                    r = 3;
                }
            } else {
                r = 2;
            }
        } else {
            r = 1;
        }
    }
    return r;
}
