#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215ee4[];
extern s32 func_ov000_0219a510(Ov009Actor *self, s32 a, const Ov009Vec *pos, s32 r, s32 b, void **out);
extern BOOL func_ov000_021985c0(void *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

void func_ov009_0220cc24(Ov009Actor *self) {
    Ov009Vec v;
    void *list[32];
    s32 i;
    s32 n;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        n = func_ov000_0219a510(self, 2, &self->pos, 0x1000, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && func_ov000_021985c0(list[i])) {
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    break;
                }
            }
        }
        break;
    }
    v = func_ov000_0219bf90()->pos;
    func_ov000_0218d918(self, &v, 0x1000);
    self->unk_98 = self->rot[1];
    func_ov000_0218dbe0(self, 0);
}

extern void *data_02097e4c;
extern void func_0203f364(Ov009Sub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern void MTX_MultVec33(const Ov009Vec *v, const void *m, Ov009Vec *out);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
void func_ov009_0220cd40(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov009Sub48 *s48;
        Ov009Sub44 *s44;
        *self->unk_50 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 s;
            s16 n;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            w = self->unk_64;
            y = func_02040528(FLD(s32, self, 0x68));
            x = func_02040528(w);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            s = func_02040498(0x4cd) + 0x4cd;
            n = self->unk_18;
            if (n % 3 == 0) {
                func_02065f88(0x69, &self->pos)->v0c(0x1333);
                func_02065f88(4, &self->pos);
                if (n >= 9) {
                    self->unk_40->state++;
                }
            } else {
                func_02065f88(0x69, &v)->v0c(s);
                if (n % 2 == 0) {
                    func_02065f88(4, &v)->v0c(s);
                }
                self->unk_40->timer = 5;
            }
            func_0204a028(data_02097e4c, 0x2b, &v, -5);
            self->unk_18 = n + 1;
        }
        if (*func_ov000_0219bf90()->unk_50 == 0) {
            return;
        }
        func_ov000_0219aae8(self, self, 0xc8, FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, NULL, 0, 0x2000, 0, 0x64, 0x1000);
        break;
    case 2: {
        u8 b = FLD(u8, self->unk_38, 0xbe);
        if (b == 0) {
            return;
        }
        b--;
        if (b == 0) {
            st->state = 10;
            b = 0;
        }
        FLD(u8, self->unk_38, 0xbe) = b;
        break;
    }
    case 10:
        func_ov003_021d6a3c(self, 1, 1, 1);
        break;
    }
}

}
