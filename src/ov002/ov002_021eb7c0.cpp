#include "ov002/ov002.h"

extern "C" {

void func_ov002_021eb7c0(void *self) {
    u8 *data = FIELD(self, 0x2c, u8 *);
    s32 v[3];
    s32 size;
    s32 id;
    s32 hdr[2];
    s32 n;
    u8 *p;
    int i;
    func_02016fa0(data + 8, hdr, 8);
    n = hdr[0];
    p = data + 0x10;
    for (i = 0; i < n; i++) {
        func_02016fa0(p, &size, 4);
        func_02016fa0(p + 4, &id, 4);
        func_02016fa0(p + 8, v, 0xc);
        func_ov002_021e9974(v[0], v[1], (s16)id, p + 0x14);
        p += size;
    }
}

}
