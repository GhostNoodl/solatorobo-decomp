#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(Ov009Actor *self, Ov009Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern BOOL func_ov000_0219a8bc(void *p, Ov009Actor *a, Ov009Actor *b, s32 c, s32 d, const Ov009Vec *pos, s32 e, s32 f, s32 g);
extern void func_ov000_0219763c(Ov009Actor *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_02214e90(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009Actor *a;
        Ov009Actor *t;
        func_ov000_0218996c(10, 10);
        FLD(u8, FLD(u8 *, self, 0x4c), 2) = 0;
        func_02065f88(5, &self->pos)->v0c(0x299a);
        func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        a = Ov009_FindActor(FLD(u16, self, 0xd2));
        if (a == NULL) {
            a = self;
        }
        func_ov000_0219aae8(self, a, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa) & 0xff, 0x30, 0, 0, 0x299a, 0, 0x64, 0x1000);
        t = func_ov000_0219bf90();
        if (t != NULL && func_01ffc198(&t->pos, &self->pos, t->unk_64 + 0x299a)) {
            u8 *q = FLD(u8 *, self, 0x4c);
            func_ov000_0219a8bc(t->unk_44, self, self, FLD(u16, q, 8), FLD(u16, q, 0xa) & 0xff, &self->pos, 0x64, 0x1000, 0x1000);
        }
    }
    func_ov000_0219763c(self);
}

}
