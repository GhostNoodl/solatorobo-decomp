#include "ov013/ov013.h"

struct Ov013Opt120 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[3];
    Ov013Vec v;
};

extern "C" {

extern void *data_0214a420;
extern void *data_ov013_0220b9a0[];
extern u8 data_ov013_0220aedc[];
extern const Ov013Vec data_ov013_0220af28;
extern void *func_ov003_021d8910(void *p);
extern void *func_ov003_021cf2bc(void *p);
extern void func_ov003_021d8f24(void *p);
extern void func_ov003_021d8f34(void *p);
extern void *func_ov003_021cf2d8(void *p);
extern void *func_ov003_021d8928(void *p);
extern void func_ov003_021d8fa8(void *p);
extern void func_02065804(void *a, s32 b);
extern void VEC_Add(const Ov013Vec *a, const Ov013Vec *b, Ov013Vec *out);
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void func_ov003_021cf3fc(s32 a);
void func_ov013_021fed64(Ov013Actor *self);
void func_ov013_021febf8(Ov013Actor *self);

Ov013Actor *func_ov013_021fea8c(Ov013Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov003_021d8910((u8 *)self + 0x12c);
    func_ov003_021cf2bc((u8 *)self + 0x13c);
    func_ov003_021d8f24((u8 *)self + 0x14c);
    func_ov013_021fed64(self);
    return self;
}

Ov013Actor *func_ov013_021feacc(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov013_021febf8(self);
    func_ov003_021d8f34((u8 *)self + 0x14c);
    func_ov003_021cf2d8((u8 *)self + 0x13c);
    func_ov003_021d8928((u8 *)self + 0x12c);
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_021feb0c(Ov013Actor *self) {
    FLD(void *, self, 0) = data_ov013_0220b9a0;
    func_ov013_021febf8(self);
    func_ov003_021d8f34((u8 *)self + 0x14c);
    func_ov003_021cf2d8((u8 *)self + 0x13c);
    func_ov003_021d8928((u8 *)self + 0x12c);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

static inline void Ov013_AddVec(Ov013Vec *a, Ov013Vec b, Ov013Vec *out) {
    VEC_Add(a, &b, out);
}

static inline Ov013Vec Ov013_GetOff(Ov013Opt120 *o) {
    Ov013Vec off = data_ov013_0220af28;
    if (o->b0) {
        off.x = o->v.x;
        off.y = o->v.y;
        off.z = o->v.z;
    }
    return off;
}

BOOL func_ov013_021feb54(Ov013Actor *self) {
    Ov013Vec saved = self->pos;
    BOOL r;
    Ov013_AddVec(&self->pos, Ov013_GetOff(FLD(Ov013Opt120 *, self, 0x120)), &self->pos);
    r = func_ov003_021d16cc(self);
    self->pos.x = saved.x;
    self->pos.y = saved.y;
    self->pos.z = saved.z;
    return r;
}

static inline void Ov013_DelOpt(Ov013Opt120 *o) {
    if (o != NULL) {
        if (o->b0) {
            o->b0 = 0;
        }
        func_0203de1c(o);
    }
}

void func_ov013_021febf8(Ov013Actor *self) {
    u32 saved;
    ((Ov013V *)((u8 *)self + 0x12c))->v08();
    ((Ov013V *)((u8 *)self + 0x13c))->v08();
    func_ov003_021d8fa8((u8 *)self + 0x14c);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov013Opt120 *, self, 0x120) != NULL) {
        Ov013_DelOpt(FLD(Ov013Opt120 *, self, 0x120));
        FLD(Ov013Opt120 *, self, 0x120) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov013Opt120 *, self, 0x124) != NULL) {
        Ov013_DelOpt(FLD(Ov013Opt120 *, self, 0x124));
        FLD(Ov013Opt120 *, self, 0x124) = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(Ov013V *, self, 0x128) != NULL) {
        Ov013V *v = FLD(Ov013V *, self, 0x128);
        if (v != NULL) {
            v->v04();
        }
        FLD(Ov013V *, self, 0x128) = NULL;
    }
    data_02097dd0->cur = saved;
    func_02065804(data_0214a420, FLD(s32, self, 0x100));
    func_02065804(data_0214a420, FLD(s32, self, 0x104));
    func_ov013_021fed64(self);
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_ov003_021cf3fc(0);
}

void *func_ov013_021fed50(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov013_021fed64(Ov013Actor *self) {
    Ov013Flags8 *f = &FLD(Ov013Flags8, self, 0xf0);
    f->b0 = 0;
    f->b1 = 0;
    f->b2 = 0;
    f->b3 = 0;
    f->b4 = 0;
    f->b5 = 0;
    FLD(u16, self, 0xf2) = 0xffff;
    FLD(u16, self, 0xf4) = 0xffff;
    FLD(u16, self, 0xf6) = 0xffff;
    FLD(u16, self, 0xf8) = 0;
    FLD(u16, self, 0xfa) = 0;
    FLD(u16, self, 0xfc) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(Ov013Vec, self, 0x108) = FLD(Ov013Vec, data_ov013_0220aedc, 0x4c);
    FLD(Ov013Vec, self, 0x114) = FLD(Ov013Vec, self, 0x108);
    FLD(void *, self, 0x120) = NULL;
    FLD(void *, self, 0x124) = NULL;
    FLD(void *, self, 0x128) = NULL;
    FLD(u8, self, 0x15c) = 0;
    FLD(u8, self, 0x15d) = 0xff;
}

}
