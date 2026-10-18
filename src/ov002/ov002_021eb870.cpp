#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e92b0(s32 a, s32 b, s32 c, s32 d, s32 e);

void *func_ov002_021e9380(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

typedef struct Rec021eb870 {
    s32 a;
    s32 b;
    u8 c;
    u8 pad[3];
    s16 d;
    s16 e;
    s32 f;
    s32 g;
    u32 flags;
} Rec021eb870;

void func_ov002_021eb870(void *self) {
    u8 *p = FIELD(self, 0x30, u8 *);
    s32 hdr[2];
    Rec021eb870 rec;
    s32 i;
    s32 count;
    s32 size;
    MI_CpuCopy8(p + 8, hdr, 8);
    count = hdr[0];
    size = hdr[1];
    p += 0x10;
    for (i = 0; i < count; i++) {
        void *o;
        void *q;
        u8 *a, *b, *c;
        MIi_CpuCopyFast(p, &rec, size);
        o = func_ov002_021e9380(rec.a, rec.b, rec.c, rec.d, rec.e, rec.f);
        p += size;
        a = (rec.flags & 1) ? p : NULL;
        if (rec.flags & 1) {
            p += 0x18;
        }
        b = (rec.flags & 2) ? p : NULL;
        if (rec.flags & 2) {
            p += 0x18;
        }
        c = (rec.flags & 4) ? p : NULL;
        if (rec.flags & 4) {
            p += 0x18;
        }
        q = func_ov002_021e92b0(rec.a, rec.b, rec.c, 0, 0x1000);
        FIELD(q, 0x4c, u8 *) = a;
        FIELD(q, 0x50, u8 *) = b;
        FIELD(q, 0x54, u8 *) = c;
        FIELD(o, 0x60, void *) = q;
    }
}

}
