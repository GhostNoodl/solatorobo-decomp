#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ec6fc(void *node);

struct N3_55c {
    VFunc *vt;
    s32 f4, f8, fc, f10, f14, f18, f1c;
    void *e;
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    N3_55c() {
        vt = data_ov002_021f0ef4;
        f4 = 0; f8 = 0; fc = 0; f10 = 0; f14 = 0; f18 = 0; f1c = 0x1000;
        ((VObject *)this)->v0x10();
    }
};

struct N3b_55c : N3_55c { u8 pad[0x34 - 0x24]; };

struct N4_55c : N3_55c {
    u8 pad[0x58 - 0x24];
    N4_55c() { vt = data_ov002_021f0e84; ((VObject *)this)->v0x10(); }
};

struct N5_55c : N3_55c {
    u8 pad[0x4c - 0x24];
    N5_55c() { vt = data_ov002_021f0e4c; ((VObject *)this)->v0x10(); }
};

struct N6_55c : N5_55c {
    u8 pad6[0x50 - 0x4c];
    N6_55c() { vt = data_ov002_021f0ebc; ((VObject *)this)->v0x10(); }
};

struct N7_55c : N3_55c {
    u8 pad[0x34 - 0x24];
    N7_55c() { vt = data_ov002_021f0e14; ((VObject *)this)->v0x10(); }
};

BOOL func_ov002_021ee55c(void *self, s32 start, s32 count) {
    u8 *hdr = FIELD(FIELD(self, 0x24, void *), 0x4c, u8 *);
    u8 *e = hdr + 0xc + start * 0x14;
    s32 end = start + count;
    bool clipped = FALSE;
    N3_55c *o;
    s32 i;
    if (end >= FIELD(hdr, 0xa, u16)) {
        clipped = TRUE;
        end = FIELD(hdr, 0xa, u16);
    }
    for (i = start; i < end; i++, e += 0x14) {
        switch (FIELD(e, 0, s32)) {
        case 1:
        case 2:
        case 8:
            continue;
        case 3:
            o = new N3b_55c;
            break;
        case 4:
            o = new N4_55c;
            break;
        case 5:
            o = new N5_55c;
            break;
        case 6:
            o = new N6_55c;
            break;
        case 7:
            o = new N7_55c;
            break;
        }
        o->e = e;
        func_ov002_021ec6fc(o);
    }
    return clipped;
}

}
