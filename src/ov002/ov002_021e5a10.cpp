#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e5fe4(void *p);

BOOL func_ov002_021e5a10(void *self) {
    void *n;
    void *c;
    if (FIELD(data_ov002_021f0f98[1], 0xd0, s32) > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    n = NULL;
    c = FIELD(self, 0x1e8, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 2, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 2, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0x1e8, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0x1e8, void *));
        }
        func_ov002_021e5fe4(n);
        FIELD(self, 0x1e8, void *) = n;
    }
    n = NULL;
    c = FIELD(self, 0x1ec, void *);
    if (c == NULL) {
        n = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(c, 0xe8, Bits8).b1) {
        n = func_ov002_021e4ee4(self, 3, FIELD(c, 0x18, s32));
    }
    if (n != NULL) {
        if (FIELD(self, 0x1ec, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0x1ec, void *));
        }
        func_ov002_021e61b4(n);
        FIELD(self, 0x1ec, void *) = n;
    }
    return TRUE;
}

}
