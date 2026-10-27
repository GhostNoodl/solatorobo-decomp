#include "ov000/LoCommon.h"

extern "C" {

extern char data_0214b105[];
extern char *data_0208cca0;
extern char data_ov000_021cb8e0[];
extern char data_ov000_021cb8f1[];
extern char data_ov000_021cb8fd[];
extern char data_ov000_021cb909[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
void *func_02035d5c(const char *a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *model, void *fn);
void func_02041c18(void *model, void *arg);
void func_ov000_021640fc(void);

static inline void *NewModel(char *nm) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
        }
    }
    return m;
}

void func_ov000_02164a94(u8 *self) {
    char buf[0x20];
    void *a;
    void *b;
    s32 *pp;
    s32 saved;
    u8 *m;
    func_02035d5c(data_0214b105);
    a = func_02035d5c(data_0208cca0);
    func_0206e900(buf, data_ov000_021cb8e0);
    b = func_02035d5c(buf);
    LFLD(s32, self, 0x50) = LFLD(s32, data_0214a424, 0x20);
    pp = &LFLD(s32, data_02097d48, 0x9e4);
    saved = *pp;
    *pp = -1;
    m = (u8 *)NewModel(data_ov000_021cb8f1);
    LFLD(void *, self, 0x28) = m;
    func_020417e0(LFLD(void *, self, 0x28), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x28), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb8fd);
    LFLD(void *, self, 0x2c) = m;
    func_020417e0(LFLD(void *, self, 0x2c), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x2c), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb909);
    LFLD(void *, self, 0x24) = m;
    func_020417e0(LFLD(void *, self, 0x24), func_02034d88(a, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x24), 2, 0xffff);
    func_02041c5c(LFLD(void *, self, 0x24), (void *)func_ov000_021640fc);
    func_02041c18(LFLD(void *, self, 0x24), self);
    *pp = saved;
}

}

#ifdef NONMATCHING
// func_ov000_02164c50: 185 raw / 0 register-masked diffs, real two-argument signature.
// Whole-function rotation of the callee-saved registers (self, arg and the hoisted zero).
#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 a0;
    u16 a1;
    u16 a2;
} OamAttr02164c50;

typedef struct {
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 rest : 16;
} OamW2_02164c50;

extern "C" {

void *func_0203de84(u32 size, u32 align);
void *func_0203dd9c(u32 size);
void MI_CpuFill8(void *dst, u32 value, u32 size);
void func_02041218(void *res);
void func_02040be0(void *res, void *src);
void func_02040d14(void *res, s32 a, s32 b);
void func_02040d94(void *res, void *a, s32 b, s32 c);
void func_02040dd8(void *res, s32 a, s32 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_ov000_021652e4(void *self, u8 *p, u8 *rec, u8 *e);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void *LoModelGetCell(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        return LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
}

typedef struct { u8 pad[6]; u8 n6; u8 n7; } Ent02164c50;
static inline u8 *Next02164c50(u8 *e) {
    u8 *q = e + 8;
    if (((Ent02164c50 *)e)->n6 != 0) {
        q += ((Ent02164c50 *)e)->n6 * 0x14;
    }
    if (((Ent02164c50 *)e)->n7 != 0) {
        q += ((Ent02164c50 *)e)->n7 * 0xc;
    }
    return q;
}

void func_ov000_02164c50(u8 *self, u8 *arg) {
    u8 *p;
    void *m;
    u8 *buf;
    u16 base;
    void *cell;
    OamAttr02164c50 *oa;
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x3c) = 0;
    p = (u8 *)func_0203de84(0xce0, 4);
    LFLD(u8 *, self, 0x30) = p;
    MI_CpuFill8(p, 0, 0xce0);
    p[0] = 1;
    LFLD(u16, p, 0x4) = LFLD(u16, arg, 0x8);
    p[8] = arg[0xa];
    p[2] = 0;
    m = func_0203dd9c(0x64);
    if (m != NULL) {
        func_02041218(m);
    }
    LFLD(void *, p, 0xc8c) = m;
    func_02040be0(m, LFLD(void *, self, 0x24));
    buf = LFLD(u8 *, LFLD(void *, p, 0xc8c), 0x30);
    LFLD(u16, p, 0xc94) = 2;
    LFLD(u16, p, 0xc96) = 4;
    {
        u8 *r = LFLD(u8 *, p, 0xc8c);
        LFLD(u16, r, 0x34) = 2;
        LFLD(void *, r, 0x38) = p + 0xc94;
        func_02040d14(LFLD(void *, p, 0xc8c), 0, LFLD(u16, r, 0x34) << 5);
    }
    func_02040d94(LFLD(void *, p, 0xc8c), buf + 0x40, 0, 0x20);
    func_02040d94(LFLD(void *, p, 0xc8c), buf + 0x80, 0x20, 0x20);
    func_02040dd8(LFLD(void *, p, 0xc8c), 2, 1);

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 2);
    base = LFLD(u16, LFLD(void *, self, 0x24), 0xf4);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    LFLD(s32, p, 0xc90) = LFLD(s32, LFLD(void *, LFLD(void *, self, 0x24), 0xec), 0x58);
    *(OamAttr02164c50 *)(p + 0x2c) = *oa;
    LFLD(OamW2_02164c50, p, 0x30).tile += base;
    p[1]++;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 3);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0xc) = *oa;
    LFLD(OamW2_02164c50, p, 0x10).tile += base;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xc);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0x14) = *oa;
    LFLD(OamW2_02164c50, p, 0x18).tile += base;
    LFLD(OamW2_02164c50, p, 0x18).prio = LFLD(OamW2_02164c50, p, 0x10).prio;
    LFLD(u16, p, 0x24) = base + LFLD(OamW2_02164c50, oa, 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xd);
    LFLD(u16, p, 0x26) = base + LFLD(OamW2_02164c50, LFLD(void *, cell, 0x4), 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xe);
    LFLD(u16, p, 0x28) = base + LFLD(OamW2_02164c50, LFLD(void *, cell, 0x4), 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xb);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0x1c) = *oa;
    LFLD(OamW2_02164c50, p, 0x20).prio = 2;
    LFLD(OamW2_02164c50, p, 0x20).tile += base;

    {
        u16 n1 = 0;
        u16 n2 = 0;
        s32 i;
        s32 j;
        u8 *e = arg + 0xc;
        for (i = 0; i < p[8]; i++) {
            u8 *s;
            n1 += e[6];
            n2 += e[7];
            for (j = 0, s = e + 8; j < e[6]; j++, s += 0x14) {
                p[9] = p[9] < s[0x10] ? s[0x10] : p[9];
            }
            e = Next02164c50(e);
        }
        p[9]++;
        {
            u32 sz = n2 * 0x14;
            LFLD(void *, p, 0xc7c) = func_0203de84(sz, 4);
            MI_CpuFill8(LFLD(void *, p, 0xc7c), 0, sz);
        }
        {
            u32 sz = n1 * 0x18;
            LFLD(void *, p, 0xc80) = func_0203de84(sz, 4);
            MI_CpuFill8(LFLD(void *, p, 0xc80), 0, sz);
        }
        LFLD(void *, p, 0xc84) = func_0203de84(p[8] * 0x1c, 4);
        MI_CpuFill8(LFLD(void *, p, 0xc84), 0, p[8] * 0x1c);
        LFLD(void *, p, 0xc88) = func_0203de84(p[9] << 3, 4);
        MI_CpuFill8(LFLD(void *, p, 0xc88), 0, p[9] << 3);
        for (i = 0; i < p[9]; i++) {
            LFLD(void *, LFLD(u8 *, p, 0xc88) + i * 8, 4) = func_0203de84(p[8] << 2, 4);
            MI_CpuFill8(LFLD(void *, LFLD(u8 *, p, 0xc88) + i * 8, 4), 0, p[8] << 2);
        }
    }
    {
        u8 *e = arg + 0xc;
        u8 i;
        for (i = 0; i < p[8]; i++) {
            u32 off = i * 0x1c;
            LFLD(u32, LFLD(u8 *, p, 0xc84) + off, 0) = LFLD(u32, e, 0);
            LFLD(u8, LFLD(u8 *, p, 0xc84) + off, 8) = i;
            func_ov000_021652e4(self, p, LFLD(u8 *, p, 0xc84) + off, e);
            e = Next02164c50(e);
        }
    }
}

}
#endif
