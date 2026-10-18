#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
} AnmFlags0219c54c;

typedef struct {
    char *name[6];
    u8 unk_18;
    u8 pad_19[7];
} Entry0219c54c;

typedef struct {
    u16 b0 : 6;
    u16 kind : 3;
    u16 b9 : 7;
} Bits0219c54c;

typedef struct {
    u16 b0 : 3;
    u16 sub : 4;
    u16 b7 : 9;
} Save0219c54c;

extern "C" {
extern Entry0219c54c data_ov000_021ca398[];
extern u8 *data_0214a424;
extern char data_ov000_021cc5d2[];
extern char data_ov000_021cc5d9[];
void *func_0207011c(u16 id);
s32 func_020701d4(u16 id);
u8 *func_0206ef10(u16 id);
void *func_0203dd9c(u32 size);
void *func_ov000_021919c8(void *p);
void func_ov000_02191b70(void *s);
void func_ov000_0218f074(void *o, void *a, BOOL b, BOOL c, s32 d, BOOL e);
void STD_CopyString(char *dst, const char *src);

static inline void SetNames0219c54c(char *d0, char *d1, const char *a, const char *b) {
    STD_CopyString(d0, a);
    STD_CopyString(d1, b);
}

void func_ov000_0219c54c(u8 *self) {
    void *res;
    void *p;
    Entry0219c54c *e;
    u32 kind;

    res = func_0207011c(LFLD(u16, self, 0xe));
    func_020701d4(LFLD(u16, self, 0xe));
    func_ov000_0218f074(self + 0x194, res, TRUE, TRUE, 1, FALSE);
    LFLD(u16, self, 0x194) = 0;
    {
        const char *b = data_ov000_021cc5d2;
        const char *a = data_ov000_021cc5d9;
        if (a != NULL && b != NULL) {
            SetNames0219c54c((char *)self + 0x870, (char *)self + 0x890, a, b);
            LFLD(AnmFlags0219c54c, self, 0x863).b1 = 1;
        }
    }
    LFLD(u16, self, 0x860) = 0;
    p = func_0203dd9c(0x1c);
    if (p != NULL) {
        p = func_ov000_021919c8(p);
    }
    LFLD(void *, self, 0x3c) = p;
    func_ov000_02191b70(p);
    kind = LFLD(Bits0219c54c, self, 0xb22).kind;
    e = &data_ov000_021ca398[kind];
    if ((u16)(kind + 0xfffe) <= 1) {
        u8 *x = func_0206ef10(LFLD(Save0219c54c, data_0214a424, 0x18).sub | 0x8000);
        if (x != NULL) {
            LFLD(u8 *, self, 0xba4) = x;
            e = (Entry0219c54c *)(x + 0xc);
        }
    }
    LFLD(Entry0219c54c *, self, 0xba0) = e;
    SetNames0219c54c((char *)self + 0x460, (char *)self + 0x480, e->name[0], e->name[1]);
    LFLD(AnmFlags0219c54c, self, 0x453).b1 = 1;
    SetNames0219c54c((char *)self + 0x49c, (char *)self + 0x4bc, e->name[2], e->name[3]);
    LFLD(AnmFlags0219c54c, self, 0x453).b2 = 1;
    if (e->name[4] != NULL && e->name[5] != NULL) {
        SetNames0219c54c((char *)self + 0x514, (char *)self + 0x534, e->name[4], e->name[5]);
        LFLD(AnmFlags0219c54c, self, 0x453).b4 = 1;
    }
    LFLD(u16, self, 0x450) = 0;
    if (e->unk_18 == 0) {
        return;
    }
    SetNames0219c54c((char *)self + 0x5d4, (char *)self + 0x5f4, e->name[0], e->name[1]);
    LFLD(AnmFlags0219c54c, self, 0x58b).b2 = 1;
    LFLD(u16, self, 0x588) = 0;
}
}
