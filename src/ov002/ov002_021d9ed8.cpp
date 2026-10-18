#include "ov002/ov002.h"

extern "C" {

typedef struct {
    u16 b0 : 1;
    u16 mode : 2;
    u16 id : 4;
    u16 rest : 9;
} Bits9ed8;

void func_ov002_021d9ed8(void *self, void *obj, bool del) {
    s32 j;
    s32 i;
    u32 saved;
    s32 rows;
    s32 cols;
    u8 *grid;
    void *next = FIELD(obj, 0x70, void *);
    void *prev = FIELD(obj, 0x74, void *);
    if (prev == NULL) {
        FIELD(self, 0x6c, void *) = next;
        if (next != NULL) {
            FIELD(next, 0x74, void *) = NULL;
        }
    } else {
        FIELD(prev, 0x70, void *) = next;
        if (next != NULL) {
            FIELD(next, 0x74, void *) = prev;
        }
    }
    FIELD(obj, 0x70, void *) = NULL;
    FIELD(obj, 0x74, void *) = NULL;
    {
        u8 *q = FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *);
        u32 h;
        grid = FIELD(self, 0x70, u8 *);
        h = FIELD(q, 4, u16);
        cols = (h << 20) >> 28;
        rows = (h << 16) >> 28;
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            u8 *e = grid + (j + i * cols) * 0xc;
            if (FIELD(e, 8, void *) == obj) {
                FIELD(e, 0, u16) = 0xffff;
                e[2] = 0;
                e[3] = 0;
                e[4] = 0;
                FIELD(e, 8, void *) = NULL;
            }
        }
    }
    if (FIELD(data_0214a424, 0x18, Bits9ed8).mode == 1) {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
        func_ov000_021c95ac((u8 *)self + 0x76, FIELD(data_0214a424, 0x18, Bits9ed8).id | 0x8000);
    } else {
        func_ov000_021c9544((u8 *)self + 0x76, FIELD(self, 0x6c, void *));
    }
    if (del) {
        HEAP_PUSH(saved);
        if (obj != NULL) {
            if (obj != NULL) {
                VC(obj, 0x4)();
            }
        }
        HEAP_POP(saved);
    }
}

void *func_0203dddc(u32 size);

void func_ov002_021da054(void *self) {
    s32 j;
    s32 i;
    s32 rows;
    s32 cols;
    u8 *p;
    if (FIELD(self, 0x4, void *) == NULL) {
        return;
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x70, void *) != NULL) {
            func_0203de1c(FIELD(self, 0x70, void *));
            FIELD(self, 0x70, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    FIELD(self, 0x70, void *) = func_0203dddc(FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *), 0x4, Nibbles16).n3 * FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *), 0x4, Nibbles16).n2 * 12);
    cols = FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *), 0x4, Nibbles16).n2;
    rows = FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *), 0x4, Nibbles16).n3;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            u8 *e = FIELD(self, 0x70, u8 *) + (j + i * rows) * 12;
            FIELD(e, 0x0, u16) = 0xffff;
            FIELD(e, 0x2, u8) = 0;
            FIELD(e, 0x3, u8) = 0;
            FIELD(e, 0x4, u8) = 0;
            FIELD(e, 0x8, s32) = 0;
        }
    }
    for (p = FIELD(self, 0x6c, u8 *); p != NULL; p = FIELD(p, 0x70, u8 *)) {
        func_ov002_021da184(self, p);
    }
}

typedef struct Cell021da184 {
    u16 id;
    u8 a;
    u8 b;
    u8 c;
    void *obj;
} Cell021da184;

typedef struct Bits021da184 {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Bits021da184;

void func_ov002_021e3aa0(s32 *out, s32 *m, s32 *p, s32 *q, s32 *t);

void func_ov002_021da184(void *self, void *obj) {
    u8 *g;
    s32 j;
    u8 *e;
    s32 i;
    s32 m[4];
    s32 pos[2];
    s32 org[2];
    s32 v[2];
    u8 rows;
    u8 cols;
    pos[0] = FIELD(obj, 0x54, s32);
    pos[1] = FIELD(obj, 0x58, s32);
    func_ov002_021e38f8(org, (u8 *)obj + 0x4c);
    cols = FIELD(obj, 0x50, Nibbles16).n2;
    rows = FIELD(obj, 0x50, Nibbles16).n3;
    func_ov002_021e391c(m, FIELD(obj, 0x52, Bits021da184).rot);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (FIELD(obj, 0x4c, u8 *)[i * cols + j] == 1) {
                s32 W;
                s32 H;
                v[0] = j;
                v[1] = i;
                func_ov002_021e3aa0(v, m, v, org, pos);
                g = FIELD(FIELD(self, 0x4, u8 *), 0x6c, u8 *);
                W = FIELD(g, 0x4, Nibbles16).n2;
                H = FIELD(g, 0x4, Nibbles16).n3;
                if (v[0] >= 0 && v[1] >= 0 && v[0] < W && v[1] < H && FIELD(g, 0x0, u8 *)[v[1] * H + v[0]] == 0) {
                    e = (u8 *)&FIELD(self, 0x70, Cell021da184 *)[v[0] + v[1] * H];
                    u8 *info = func_0206ede8(FIELD(obj, 0x48, u16));
                    FIELD(e, 0x0, u16) = FIELD(obj, 0x48, u16);
                    FIELD(e, 0x2, u8) = FIELD(obj, 0x4a, u8);
                    FIELD(e, 0x3, u8) = info[0];
                    FIELD(e, 0x4, u8) = info[2];
                    FIELD(e, 0x8, void *) = obj;
                }
            }
        }
    }
}

}
