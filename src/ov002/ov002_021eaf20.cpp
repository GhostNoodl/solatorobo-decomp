#include "ov002/ov002.h"

extern "C" {

extern char data_ov002_021f0d00[];

extern char data_ov002_021f0d0f[];

void func_ov002_021eb298(void *self);

void func_ov002_021ebcf8(void *self, int a, s32 b, s32 c);

void func_ov002_021eb0f8(void *self);

void func_ov002_021eb448(void *self);

void func_ov002_021eb7c0(void *self);

void func_ov002_021eb870(void *self);

void func_ov002_021e9cec(void *dst, u32 size, void *src, int mode, u8 idx);

void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

void *func_ov002_021e9a50(void *a, void *b);

void *func_ov002_021e9bd8(void *a, void *b);

void *func_ov002_021e9478(s32 a, s32 b, s32 c, s32 d, u16 e, s32 mode, u8 f, u8 g);

typedef struct Hdr021eaf20 {
    s32 count;
    s32 stride;
} Hdr021eaf20;

typedef struct Rec021eaf20 {
    s32 a;
    s32 b;
    u8 d;
    s32 mode;
    s32 c;
    s32 e;
    u16 f;
    u16 g;
} Rec021eaf20;

void func_ov002_021eaf20(void *self) {
    u8 *d;
    s32 stride;
    s32 i;
    s32 n;
    u8 *src;
    Rec021eaf20 rec;
    char bufB[0x20];
    char bufA[0x20];
    char bufD[0x20];
    char bufC[0x20];
    void *x;
    Hdr021eaf20 hdr;
    func_ov002_021eb298(self);
    func_ov002_021ebcf8(self, 2, FIELD(self, 0x1c, s32), FIELD(self, 0x44, s32));
    func_ov002_021ebcf8(self, 3, FIELD(self, 0x20, s32), FIELD(self, 0x48, s32));
    func_ov002_021ebcf8(self, 3, FIELD(self, 0x24, s32), FIELD(self, 0x4c, s32));
    func_ov002_021eb0f8(self);
    func_ov002_021eb448(self);
    d = FIELD(self, 0x28, u8 *);
    MI_CpuCopy8(d + 8, &hdr, 8);
    n = hdr.count;
    src = d + 0x10;
    stride = hdr.stride;
    for (i = 0; i < n; i++) {
        MI_CpuCopy8(src, &rec, 0x1c);
        func_ov002_021e9478(rec.a, rec.b, rec.c, rec.d, rec.e, rec.mode, rec.f, rec.g);
        src += stride;
    }
    func_ov002_021eb7c0(self);
    func_ov002_021eb870(self);
    func_ov002_021e9cec(bufA, 0x20, data_ov002_021f0d00, 1, ((u8 (*)(void))func_0206e8f0)());
    func_ov002_021e9d7c(bufB, 0x20, FIELD(self, 0x4, void *), 1, ((u8 (*)(void))func_0206e8f0)());
    func_ov002_021e9bd8(bufA, bufB);
    func_ov002_021e9cec(bufC, 0x20, data_ov002_021f0d0f, 2, ((u8 (*)(void))func_0206e8f0)());
    func_ov002_021e9d7c(bufD, 0x20, FIELD(self, 0x4, void *), 2, ((u8 (*)(void))func_0206e8f0)());
    func_ov002_021e9a50(bufC, bufD);
    MI_CpuCopy8(FIELD(self, 0x8, u8 *) + 0xc, &x, 4);
    func_ov002_021e9b28(x);
}

void *func_0203dddc(u32 size);

void *func_ov002_021e97e8(u8 *a, u8 *b);

void *func_ov002_021e95c4(u8 *a, u8 *b);

void func_ov002_021e772c(void *self, s32 v);

void func_ov002_021e4dac(void *self, void *item);

typedef struct Hdr021eb0f8 {
    s32 count;
    s32 stride;
} Hdr021eb0f8;

typedef struct Rec021eb0f8 {
    s16 id;
    s16 type;
    s16 parent;
} Rec021eb0f8;

typedef struct Ent021eb0f8 {
    u8 *obj;
    s32 parent;
} Ent021eb0f8;

void func_ov002_021eb0f8(void *self) {
    Rec021eb0f8 rec;
    Hdr021eb0f8 hdr;
    u8 *d = FIELD(self, 0x10, u8 *);
    s32 n;
    s32 stride;
    u8 *src;
    Ent021eb0f8 *tbl;
    s32 i;
    MI_CpuCopy8(d + 8, &hdr, 8);
    n = hdr.count;
    stride = hdr.stride;
    src = d + 0x10;
    tbl = (Ent021eb0f8 *)func_0203dddc(n * 8);
    for (i = 0; i < n; i++) {
        u8 *obj;
        s32 k;
        s32 cnt;
        MI_CpuCopy8(src, &rec, 6);
        switch (rec.type) {
        case 0:
            obj = (u8 *)func_ov002_021e97e8(NULL, NULL);
            break;
        case 1:
            obj = (u8 *)func_ov002_021e95c4(NULL, NULL);
            func_ov002_021e772c(obj, 0x1e000);
            break;
        case 2:
            obj = (u8 *)func_ov002_021e95c4(NULL, NULL);
            func_ov002_021e772c(obj, 0x28000);
            break;
        case 3:
            obj = (u8 *)func_ov002_021e95c4(NULL, NULL);
            func_ov002_021e772c(obj, 0xf000);
            break;
        }
        FIELD(obj, 0x4c, s32) = rec.id;
        FIELD(obj, 0x8, s32) = (i % 2) ? 2 : 1;
        cnt = FIELD(self, 0x58, s32);
        for (k = 0; k < cnt; k++) {
            u8 *q = FIELD(self, 0x48, u8 **)[k];
            if (rec.id == FIELD(q, 0x5c, s32)) {
                FIELD(q, 0x48, void *) = obj;
                func_ov002_021e4dac(obj, FIELD(self, 0x48, u8 **)[k]);
            }
        }
        tbl[i].obj = obj;
        tbl[i].parent = rec.parent;
        src += stride;
    }
    for (i = 0; i < n; i++) {
        s32 par = tbl[i].parent;
        u8 *o = tbl[i].obj;
        if (par >= 0) {
            u8 *po = tbl[par].obj;
            FIELD(o, 0x48, void *) = po;
            func_ov002_021e4dac(po, o);
        }
    }
    func_0203de1c(tbl);
}

s32 func_0201e950(const void *a, const void *b, u32 n);

typedef struct Ent021eb298 {
    s32 kind;
    u8 *a;
    u8 *b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Ent021eb298;

typedef struct Rec021eb298 {
    s32 id;
    u8 kind;
    u8 flags;
    u8 pad[2];
} Rec021eb298;

static inline void ov002_addPair(u8 *list, u8 *a, u8 *b, s32 kind) {
    u8 *n;
    for (n = FIELD(list, 0x4, u8 *); n != NULL; n = FIELD(n, 0x4c, u8 *)) {
        if (func_0201e950(n, a, STD_GetStringLength(n)) == 0 && func_0201e950(n + 0x20, b, STD_GetStringLength(n)) == 0 && FIELD(n, 0x40, s32) == kind) {
            break;
        }
    }
    if (n == NULL) {
        n = (u8 *)func_0203dd9c(0x50);
        MI_CpuFill8(n, 0, 0x20);
        MI_CpuFill8(n + 0x20, 0, 0x20);
        FIELD(n, 0x44, u8) = 0;
        FIELD(n, 0x48, s32) = 0;
        FIELD(n, 0x4c, u8 *) = NULL;
        STD_CopyLString(n, a, 0x20);
        STD_CopyLString(n + 0x20, b, 0x20);
        FIELD(n, 0x40, s32) = kind;
        FIELD(n, 0x4c, u8 *) = FIELD(list, 0x4, u8 *);
        FIELD(list, 0x4, u8 *) = n;
    }
}

static inline void ov002_initEnt(Ent021eb298 *e) {
    e->kind = 0;
    e->a = NULL;
    e->b = NULL;
    e->c = 0;
    e->d = 0;
    e->e = 0;
    e->f = 0;
    e->g = 0;
}

void func_ov002_021eb298(void *self) {
    Rec021eb298 rec;
    s32 hdr[2];
    u8 *d;
    s32 n;
    u8 *src;
    s32 i;
    d = FIELD(self, 0x18, u8 *);
    MI_CpuCopy8(d + 8, hdr, 8);
    n = hdr[0];
    src = d + 0x10;
    for (i = 0; i < n; i++) {
        Ent021eb298 *e;
        u8 fl;
        MI_CpuCopy8(src, &rec, 8);
        fl = rec.flags;
        e = &FIELD(self, 0x40, Ent021eb298 *)[i];
        ov002_initEnt(e);
        src += 8;
        {
            s32 f1 = fl & 1;
            e->a = f1 ? src : NULL;
            if (f1) {
                src += 0x18;
            }
        }
        {
            s32 f2 = fl & 2;
            e->b = f2 ? src : NULL;
            if (f2) {
                src += 0x18;
            }
        }
        e->kind = rec.kind;
        d = FIELD(self, 0x60, u8 *);
        if (d != NULL) {
            ov002_addPair(d, e->a, e->b, 5);
        }
    }
}

void *func_ov002_021e91c8(s32 a, s32 b, s32 c, bool d, u8 e);
void func_ov002_021e50a8(void *obj, void *entry);

typedef struct Hdr021eb448 {
    s32 count;
    s32 stride;
} Hdr021eb448;

typedef struct Rec021eb448 {
    s32 id;
    s32 a;
    s32 b;
    u8 c;
    u8 pad[3];
    u8 kind;
    u8 speed;
    u16 extra;
    u32 mask;
} Rec021eb448;

typedef struct Link021eb448 {
    s32 id;
    u8 unk4[0x18];
} Link021eb448;

void func_ov002_021eb448(void *self) {
    Hdr021eb448 hdr;
    Rec021eb448 rec;
    u8 *d;
    u8 *src;
    s32 n;
    s32 stride;
    s32 i;
    d = FIELD(self, 0x14, u8 *);
    MI_CpuCopy8(d + 8, &hdr, 8);
    src = d + 0x10;
    n = hdr.count;
    stride = hdr.stride;
    for (i = 0; i < n; i++) {
        u8 *obj;
        u8 *s1;
        u8 *s2;
        u8 *s3;
        s32 off;
        s32 spd;
        s32 q;
        s32 j;
        s32 m;
        s32 m2;
        s32 k;
        MI_CpuCopy8(src, &rec, 0x18);
        obj = (u8 *)func_ov002_021e91c8(rec.a, rec.b, rec.c, false, 0);
        FIELD(obj, 0x4c, s32) = rec.id;
        switch (rec.kind) {
        case 0:
            FIELD(obj, 0x1f0, Bits8).b1 = 0;
            FIELD(obj, 0x1f0, Bits8).b0 = 0;
            break;
        case 1:
            FIELD(obj, 0x1f0, Bits8).b1 = 1;
            FIELD(obj, 0x1f0, Bits8).b0 = 0;
            break;
        case 2:
            FIELD(obj, 0x1f0, Bits8).b1 = 0;
            FIELD(obj, 0x1f0, Bits8).b0 = 1;
            break;
        }
        switch (rec.speed) {
        case 0:
            spd = -0xa66;
            break;
        case 1:
            spd = -0x119a;
            break;
        case 2:
            spd = -0x18cd;
            break;
        case 3:
            spd = -0x2000;
            break;
        default:
            spd = -0xa66;
            break;
        }
        FIELD(obj, 0x20, s32) = spd;
        off = 0x18;
        s1 = (rec.mask & 1) ? src + 0x18 : NULL;
        if (rec.mask & 1) {
            off += 0x18;
        }
        s2 = (rec.mask & 2) ? src + off : NULL;
        if (rec.mask & 2) {
            off += 0x18;
        }
        s3 = (rec.mask & 4) ? src + off : NULL;
        FIELD(obj, 0x50, u8 *) = s1;
        FIELD(obj, 0x54, u8 *) = s2;
        FIELD(obj, 0x58, u8 *) = s3;
        for (q = 0; q < FIELD(self, 0x50, s32); q++) {
            Link021eb448 *l = &FIELD(self, 0x40, Link021eb448 *)[q];
            if (l->id == FIELD(obj, 0x4c, s32)) {
                func_ov002_021e50a8(obj, l);
            }
        }
        m = FIELD(self, 0x54, s32);
        for (j = 0; j < m; j++) {
            if (rec.id == FIELD(FIELD(self, 0x44, u8 **)[j], 0x5c, s32)) {
                func_ov002_021e4dac(obj, FIELD(self, 0x44, u8 **)[j]);
                FIELD(FIELD(self, 0x44, u8 **)[j], 0x48, u8 *) = obj;
                FIELD(FIELD(self, 0x44, u8 **)[j], 0x8, s32) = FIELD(obj, 0x8, s32);
            }
        }
        m2 = FIELD(self, 0x5c, s32);
        for (k = 0; k < m2; k++) {
            if (rec.id == FIELD(FIELD(self, 0x4c, u8 **)[k], 0x5c, s32)) {
                func_ov002_021e4dac(obj, FIELD(self, 0x4c, u8 **)[k]);
                FIELD(FIELD(self, 0x4c, u8 **)[k], 0x48, u8 *) = obj;
                FIELD(FIELD(self, 0x4c, u8 **)[k], 0x8, s32) = FIELD(obj, 0x8, s32);
            }
        }
        if (FIELD(self, 0x60, u8 *) != NULL && s1 != NULL && s2 != NULL) {
            ov002_addPair(FIELD(self, 0x60, u8 *), s1, s2, 4);
        }
        src += stride + rec.extra;
    }
}

}
