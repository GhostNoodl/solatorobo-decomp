#include "ov013/ov013.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern char data_ov013_0220b88d[];
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_0203f324(Ov013Sub48 *p);
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern u32 func_0200af34(u32 a);
extern u32 func_0200b674(u32 a, u32 b);
extern s32 func_0200b5a8(u32 a);
extern void *func_02065f88(s32 id, Ov013Vec *pos);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_021fdc30(Ov013Actor *self) {
    Ov013Actor *t = Ov013_FindActor(self->unk_90);
    if (t == NULL) {
        return;
    }
    if (self->unk_40->state == 0) {
        Ov013Sub48 *m;
        Ov013Sub44 *n;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0x14;
        self->unk_48->unk_30 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_94_1 = 1;
        func_02049f44(data_02097e4c, 0x34, &self->pos, 0);
        self->unk_40->state++;
        self->unk_40->timer = 0;
    }
    func_ov000_0218dbe0(self, 0);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), 0x20, 1 << (t->id >> 12), NULL, NULL, self->unk_64, 0, 100, 0x1000);
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        return;
    }
    {
        Ov013Sub44 *n;
        u16 w = func_0200b5a8(func_0200b674(0x3f4ccccd, func_0200af34(FLD(u16, FLD(void *, self, 0x4c), 8))));
        func_ov000_0219aae8(self, self, w, 0x20, 1 << (t->id >> 12), NULL, NULL, self->unk_64 + 0x1000, 0xccd, 100, 0x1000);
        func_02065f88(0x66, &self->pos);
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x14);
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        func_ov000_021984f4(self->unk_44, 0, 0);
        self->unk_94_1 = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}
}
