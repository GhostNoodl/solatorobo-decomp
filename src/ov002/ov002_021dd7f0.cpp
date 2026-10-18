#include "ov002/ov002.h"

extern "C" {

void func_0206ecd4(u32 size, void *dst, u16 id);

static inline u8 *ov002_GetCell(u8 *w, Vec2 *pos) {
    s32 y = pos->y;
    s32 x = pos->x;
    void *q = FIELD(w, 4, void *);
    u8 *base;
    if (q == NULL || (base = FIELD(w, 0x70, u8 *)) == NULL) {
        return NULL;
    }
    return base + (y * FIELD(FIELD(q, 0x6c, u8 *), 4, Nibbles16).n3 + x) * 0xc;
}

static inline void ov002_ShowMsg(void *self, void *str) {
    u8 *t = FIELD(self, 0x4, u8 *);
    func_ov000_0215bb14(FIELD(t, 0x20, void *), str);
    FIELD(t, 0x20, VObject *)->v0x70();
    FIELD(self, 0x20, u8) = 0;
}

void func_ov002_021dd7f0(void *self, Vec2 *a, Vec2 *b, int c) {
    u8 *w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    u8 *cur = ov002_GetCell(w, b);
    u8 *nxt = ov002_GetCell(w, a);
    void *msg = data_02149ef8;
    switch (nxt[2]) {
    case 1:
        if (FIELD(nxt, 8, void *) != FIELD(cur, 8, void *) || c != 0 || FIELD(self, 0x20, u8) != 0) {
            FIELD(w, 0x74, u8) = 1;
            FIELD(w, 0x75, u8) = 1;
            func_0206ecd4(0x100, (u8 *)self + 0x34, FIELD(FIELD(nxt, 8, u8 *), 0x48, u16));
            ov002_ShowMsg(self, (u8 *)self + 0x34);
        }
        break;
    case 0:
        if (nxt[2] != cur[2] || c != 0 || FIELD(self, 0x20, u8) != 0) {
            FIELD(w, 0x74, u8) = 2;
            FIELD(w, 0x75, u8) = 1;
            ov002_ShowMsg(self, func_0204c0e8(msg, 0x109));
        }
        break;
    case 2:
        if (nxt[2] != cur[2] || c != 0 || FIELD(self, 0x20, u8) != 0) {
            FIELD(w, 0x74, u8) = 3;
            FIELD(w, 0x75, u8) = 1;
            ov002_ShowMsg(self, func_0204c0e8(msg, 0x108));
        }
        break;
    }
    if (FIELD(cur, 8, void *) == FIELD(nxt, 8, void *) && c == 0) {
        return;
    }
    if (cur[2] == 1) {
        u8 *t = FIELD(cur, 8, u8 *);
        FIELD(t, 0xcd, u8) = 0;
        FIELD(t, 0x9c, s32) = 0xf85;
    } else if (cur[2] == 2) {
        FIELD(FIELD(cur, 8, u8 *), 0x9c, u8) = 0;
    }
    if (nxt[2] == 1) {
        u8 *t = FIELD(nxt, 8, u8 *);
        FIELD(t, 0xcd, u8) = 1;
        FIELD(t, 0xd0, s32) = 0;
    } else if (nxt[2] == 2) {
        FIELD(FIELD(nxt, 8, u8 *), 0x9c, u8) = 1;
    }
}

}
