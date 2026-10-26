#include "ov010/ov010.h"

struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
    u8 unk_08[4];
    s32 fx0;
    s32 fx1;
};

struct Ov010Sub44 {
    u8 unk_00[0x22];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
};

struct Ov010Sub48 {
    u8 unk_00[0x9a];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 rest : 11;
};

extern "C" {
extern void *data_0214a420;
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern u8 data_ov010_0220fe38[];
extern void func_02065804(void *a, s32 b);
extern void func_ov010_02203bf8(Ov010FxSet *p);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern s32 func_ov003_021d9c38(void *p);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(Ov010Sub48 *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

static inline void *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Ov010_TeamBit(u16 id) {
    void *a = Ov010_FindActor(id);
    if (a == NULL) {
        return 0;
    }
    return (u16)(1 << (FLD(u16, a, 0xe) >> 12));
}

void func_ov010_022033d0(void *self) {
    u16 *st = FLD(u16 *, self, 0x40);
    if (((const u16 *)st)[0] == 0) {
        Ov010V *e;
        Ov010FxSet *s;
        st[0]++;
        if (FLD(Ov010Flags8, self, 0xce).b1) {
            func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), Ov010_TeamBit(FLD(u16, self, 0x90)), NULL, NULL, 0x2000, 0, 100, 0x1000);
            func_ov000_0218996c(0xf, 5);
        }
        e = func_02065f88(0x131, &FLD(Ov010Vec, self, 0x70));
        e->v34(0, func_ov003_021d9c38(data_ov010_0220fe38), 0);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x1a, &FLD(Ov010Vec, self, 0x70), 0);
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 0;
            func_02065804(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b2 = 0;
            func_02065804(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
        if (FLD(Ov010Sub44 *, self, 0x44) != NULL) {
            Ov010Sub44 *n = FLD(Ov010Sub44 *, self, 0x44);
            n->b0 = 0;
            n->b1 = 0;
        }
        if (FLD(Ov010Sub48 *, self, 0x48) != NULL) {
            Ov010Sub48 *m;
            func_ov000_02198c8c(FLD(Ov010Sub48 *, self, 0x48), 0xffff);
            m = FLD(Ov010Sub48 *, self, 0x48);
            m->b0 = 0;
            m->b3 = 0;
            func_0203f364(m);
            m = FLD(Ov010Sub48 *, self, 0x48);
            m->b1 = 0;
            m->b4 = 0;
        }
    } else {
        st[1]++;
        if (st[1] > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov010V *)self)->v08();
        } else if (FLD(void *, self, 0x38) != NULL) {
            FLD(u8, FLD(void *, self, 0x38), 0xbe) = 31 - FLD(u16 *, self, 0x40)[1] * 4;
        }
    }
    func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
}
}
