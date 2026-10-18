#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_02216500[];
extern void func_ov000_02191780(void *a);
extern u8 *func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);
extern void func_ov000_0218dab0(Ov014Actor *self, Ov014Actor *target, s32 a);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov000_0218d46c(Ov014Actor *a, u16 id, s32 msg);

void func_ov014_022008f4(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    Ov014Actor *t;
    s32 i;
    s32 n;
    if (self->unk_40->state == 0) {
        Ov014Sub44 *s44;
        u8 *q;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x89, 0);
        func_ov000_02191780(self->unk_38);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        q = func_ov000_02190a30(self->unk_38, 3);
        if (q != NULL) {
            FLD(Ov014Flags, self->unk_38, 0xc2).b6 = 1;
            func_ov000_02191920(self->unk_38, 0, 0x1000, 0);
            if (FLD(s32 *, q, 0) != NULL) {
                *FLD(s32 *, q, 0) = 0;
            }
            FLD(u8, q, 0x111) |= 8;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    t = func_ov000_0218d240(self);
    func_ov000_0218d988(self, t, 0xcd);
    func_ov000_0218dab0(self, t, 0xcd);
    n = func_ov000_0219a510(self, 0x10, &self->pos, self->unk_64, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov014Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                if ((u16)(FLD(u16, FLD(u8 *, q, 0x4c), 0x1c) & 0xf000) != 0x5000) {
                    func_ov000_0218d46c(q, q->id, 0x15);
                    return;
                }
            }
        }
    }
}

}
