#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

extern "C" {

extern u8 data_ov010_02210378[];
extern void func_ov000_02194074(void *self);
extern void func_ov003_021d79d0(void *p);
extern void func_ov000_02198328(void *p);
extern void func_ov010_0220c49c(void *self);

BOOL func_ov010_0220a6a0(void *self) {
    return FLD(Ov010Flags8, self, 4).b0;
}

void *func_ov010_0220a6b0(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_02210378;
    func_ov003_021d79d0((u8 *)self + 0x120);
    func_ov000_02198328((u8 *)self + 0x158);
    func_ov000_02198328((u8 *)self + 0x16c);
    func_ov010_0220c49c(self);
    return self;
}


extern Ov010Heap *data_02097dd0;
extern void *data_0214a420;
extern u8 data_ov010_02210378[];
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021d79ec(void *p);
extern void func_ov000_0219429c(void *self);
extern void func_ov010_0220c49c(void *self);

static inline void Ov010FxA_Dtor(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065804(data_0214a420, FLD(s32, p, 4));
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
}

static inline void Ov010FxB_Dtor(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065804(data_0214a420, FLD(s32, p, 8));
        FLD(s32, p, 8) = 0;
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
}

static inline void Ov010_FreeFxA(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        u8 *p = FLD(u8 *, self, off);
        if (p != NULL) {
            Ov010FxA_Dtor(p);
            func_0203de1c(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010_FreeFxB(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        u8 *p = FLD(u8 *, self, off);
        if (p != NULL) {
            Ov010FxB_Dtor(p);
            func_0203de1c(p);
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov010Boss_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_02210378;
    Ov010_FreeFxA(self, 0xe8);
    Ov010_FreeFxB(self, 0xec);
    ((Ov010V *)((u8 *)self + 0x120))->v08();
    func_ov010_0220c49c(self);
    func_ov003_021d79ec((u8 *)self + 0x120);
    func_ov000_0219429c(self);
}

void *func_ov010_0220a6f0(void *self) {
    Ov010Boss_Dtor(self);
    return self;
}

void *func_ov010_0220a818(void *self) {
    Ov010Boss_Dtor(self);
    func_0203de1c(self);
    return self;
}
}
