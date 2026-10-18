#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

static inline void Ov009Names_Set(Ov009Names *n, const char *a, const char *b) {
    func_0201e520(n->unk_10, a);
    func_0201e520(n->unk_30, b);
    n->unk_03_1 = 1;
    func_0201e520(n->unk_4c, a);
    func_0201e520(n->unk_6c, b);
    n->unk_03_2 = 1;
    n->unk_00 = 0;
}

BOOL func_ov009_02207684(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110(&FLD(u8, self, 0xf0))) {
        r = FALSE;
    }
    return r;
}

}
