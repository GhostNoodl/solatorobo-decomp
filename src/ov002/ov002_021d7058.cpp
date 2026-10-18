#include "ov002/ov002.h"

extern "C" {

void *func_ov000_0218fe1c(void *p);

void func_ov000_0218ffdc(void *a, void *b, int c, int d);

void func_ov000_02190cb0(void *a, void *b, s32 c, int d);

void func_ov000_021915a0(void *a);

void func_ov000_02191618(void *a);

void func_ov000_02191780(void *a);

s32 **func_ov000_02190a30(void *a, int b);

void func_0202a624(void *a, int b, s32 c);

void func_02026df0(void *a, void *b);

void func_ov002_021d7238(void *self);

extern char data_ov002_021efdd1[];

extern char data_ov002_021efdd7[];

typedef struct Key021d7058 {
    s16 t;
    s16 a;
    s16 b;
} Key021d7058;

extern Key021d7058 data_ov002_021eeffc[];

static inline void *ov002_newAnim(void) {
    void *m = func_0203dd9c(0xe8);
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    return m;
}

static inline void ov002_bindPal(void *anim, void *pal) {
    void **res = FIELD(*(void **)anim, 0xc, void **);
    func_02026df0(func_0202ac90(res != NULL ? *res : NULL), pal);
}

void func_ov002_021d7058(void *self) {
    void *pal;
    void *src = FIELD(FIELD(self, 0x4, u8 *), 0xfc, void *);
    Key021d7058 *k;
    s32 x;
    if (src == NULL) {
        pal = NULL;
    } else {
        pal = func_0202aca0(*(void **)src);
    }
    FIELD(self, 0x8, void *) = ov002_newAnim();
    func_ov000_0218ffdc(FIELD(self, 0x8, void *), FIELD(self, 0xc, void *), 0, 1);
    func_ov000_02190cb0(FIELD(self, 0x8, void *), data_ov002_021efdd1, 0x1000, 0);
    func_ov000_021915a0(FIELD(self, 0x8, void *));
    FIELD(FIELD(self, 0x8, u8 *), 0xc2, Bits16).b4 = 0;
    func_0202a624(FIELD(FIELD(self, 0x8, u8 *), 0x4, void *), 1, 0x1f0000);
    ov002_bindPal(FIELD(self, 0x8, void *), pal);
    FIELD(FIELD(self, 0x8, u8 *), 0xc2, Bits16).b0 = 1;
    FIELD(self, 0x10, void *) = ov002_newAnim();
    func_ov000_0218ffdc(FIELD(self, 0x10, void *), FIELD(self, 0x14, void *), 0, 1);
    func_ov000_02190cb0(FIELD(self, 0x10, void *), data_ov002_021efdd7, 0x1000, 0);
    func_ov000_02191618(FIELD(self, 0x10, void *));
    FIELD(FIELD(self, 0x10, u8 *), 0xc2, Bits16).b4 = 0;
    ov002_bindPal(FIELD(self, 0x10, void *), pal);
    FIELD(FIELD(self, 0x10, u8 *), 0xc2, Bits16).b0 = 1;
    func_ov000_02191780(FIELD(self, 0x10, void *));
    k = data_ov002_021eeffc;
    FIELD(self, 0x60, Key021d7058 *) = k;
    {
        s32 **pp = func_ov000_02190a30(FIELD(self, 0x10, void *), 0);
        x = 0;
        if (*pp != NULL) {
            x = **pp;
        }
    }
    while (k->t < (x + 0x1000) >> 12) {
        if (k->t < 0) {
            k--;
            break;
        }
        k++;
    }
    FIELD(self, 0x64, Key021d7058 *) = k;
    FIELD(self, 0x5d, u8) = 0;
    func_ov002_021d7238(self);
    FIELD(self, 0x5c, u8) = 1;
}

}
