#include "ov002/ov002.h"

extern "C" {

s32 func_02049bdc(void *a, int b, int c);
void *func_ov002_021dd6a4(void *self, s32 a, u16 b);
void func_ov002_021dd7f0(void *self, Vec2 *a, Vec2 *b, int c);

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
}

static inline void ov002_CamMove(u8 *c, s32 px, s32 py, s32 pz, s32 tx, s32 ty, s32 tz) {
    FIELD(c, 0x90, s32) = 15;
    FIELD(c, 0x94, s32) = 15;
    *(Vec3 *)(c + 0x98) = *(Vec3 *)FIELD(c, 0x8c, u8 *);
    *(Vec3 *)(c + 0xa4) = *(Vec3 *)(FIELD(c, 0x8c, u8 *) + 0xc);
    FIELD(c, 0xb0, s32) = px;
    FIELD(c, 0xb4, s32) = py;
    FIELD(c, 0xb8, s32) = pz;
    FIELD(c, 0xbc, s32) = tx;
    FIELD(c, 0xc0, s32) = ty;
    FIELD(c, 0xc4, s32) = tz;
}

void func_ov002_021dc83c(void *self) {
    u16 trig = FIELD(data_02097dc8, 0x12, u16);
    u8 *w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    void *msg = data_02149ef8;
    u16 rep = FIELD(data_02097dc8, 0x16, u16);
    u8 *cell;
    if (trig & 2) {
        FIELD(self, 0x18, s32) = 0x46;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return;
    }
    if (trig & 1) {
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        switch (cell[2]) {
        case 1: {
            void *p;
            FIELD(self, 0x30, void *) = FIELD(cell, 8, void *);
            func_02049bdc(data_02097e4c, 0x47, -5);
            p = func_0203dd9c(0x30);
            if (p != NULL) {
                *(VFunc **)p = data_ov002_021eff30;
                FIELD(p, 0x4, s32) = 0;
                FIELD(p, 0x8, s32) = -1;
                FIELD(p, 0xc, s32) = 0;
                FIELD(p, 0x10, s32) = 0;
                FIELD(p, 0x14, s32) = 0;
                FIELD(p, 0x18, s32) = 0;
                FIELD(p, 0x20, s32) = 0;
                FIELD(p, 0x1c, s32) = 0;
                FIELD(p, 0x28, s32) = 0;
                FIELD(p, 0x24, s32) = 0;
                FIELD(p, 0x2c, u8) = 0;
            }
            {
                u8 *t = FIELD(self, 0x4, u8 *);
                FIELD(t, 0x10, void *) = p;
                FIELD(t, 0xc, s32) = 0x1e;
            }
            return;
        }
        case 2: {
            u8 *o = FIELD(cell, 8, u8 *);
            if (FIELD(w, 0x8a, u16) >= FIELD(o, 0xa8, u16)) {
                FIELD(self, 0x2c, void *) = o;
                func_ov002_021dd6a4(self, (s32)func_0204c0e8(data_02149ef8, 0x1f), 0x8d);
                FIELD(self, 0x18, s32) = 0x1e;
                return;
            }
            ov002_ShowMsg(self, func_0204c0e8(msg, 0x106));
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            FIELD(self, 0x20, u8) = 1;
            return;
        }
        case 0: {
            int i;
            u16 sum = 0;
            void *p;
            for (i = 0; i < 100; i++) {
                sum += w[8 + i];
            }
            if (sum == 0) {
                ov002_ShowMsg(self, func_0204c0e8(msg, 0x107));
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                FIELD(self, 0x20, u8) = 1;
                return;
            }
            p = func_0203dd9c(0x138);
            if (p != NULL) {
                *(VFunc **)p = data_ov002_021efef0;
                func_ov002_021ddd80(p);
            }
            {
                u8 *t = FIELD(self, 0x4, u8 *);
                FIELD(t, 0x10, void *) = p;
                FIELD(t, 0xc, s32) = 0x14;
            }
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            return;
        }
        }
        return;
    }
    if (trig & 0x400) {
        func_ov002_021dd6a4(self, (s32)func_0204c0e8(msg, 0x20), 0x8d);
        FIELD(self, 0x18, s32) = 0x32;
        return;
    }
    if (trig & 0x800) {
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        if (cell[2] != 1) {
            return;
        }
        FIELD(self, 0x30, void *) = FIELD(cell, 8, void *);
        func_ov002_021dd6a4(self, (s32)func_0204c0e8(data_02149ef8, 0x21), 0x8d);
        FIELD(self, 0x18, s32) = 0x28;
        return;
    }
    if (rep & 0xf0) {
        Vec2 np;
        void *v = func_02070dcc(4);
        u8 *map = FIELD(FIELD(w, 0x4, u8 *), 0x6c, u8 *);
        np.x = FIELD(self, 0x24, s32);
        np.y = FIELD(self, 0x28, s32);
        if (rep & 0x20) {
            np.x--;
        } else if (rep & 0x10) {
            np.x++;
        } else if (rep & 0x40) {
            np.y--;
        } else if (rep & 0x80) {
            np.y++;
        }
        if (!func_ov002_021e3dac(&np, map, v, NULL)) {
            Vec2 old;
            u8 *c;
            s32 d;
            s32 px, py, pz, tz;
            func_02049a48(data_02097e4c, 0x22, -1, -1, -1);
            old.x = FIELD(self, 0x24, s32);
            old.y = FIELD(self, 0x28, s32);
            func_ov002_021dd7f0(self, &np, &old, 0);
            c = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
            d = (u8)np.y - FIELD(FIELD(FIELD(FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *), 0x4, u8 *), 0x6c, u8 *), 6, Nibbles16).n1;
            px = *(s32 *)(data_ov002_021eef74 + 0x58);
            py = *(s32 *)(data_ov002_021eef74 + 0x5c);
            pz = *(s32 *)(data_ov002_021eef74 + 0x60);
            tz = 0x148;
            if (d < -1) {
                pz -= 0x1ec;
                tz -= 0x1ec;
            } else if (d > 1) {
                pz += 0x1ec;
                tz += 0x1ec;
            }
            ov002_CamMove(c, px, py, pz, 0, 0, tz);
            FIELD(self, 0x24, s32) = np.x;
            FIELD(self, 0x28, s32) = np.y;
            return;
        }
        if (np.x <= FIELD(self, 0x24, s32)) {
            return;
        }
        if (np.x < FIELD(map, 4, Nibbles16).n2) {
            return;
        }
        func_02049a48(data_02097e4c, 0xe, -1, -1, -1);
        {
            u8 *c = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
            s32 py = *(s32 *)(data_ov002_021eef74 + 0x5c);
            s32 pz = *(s32 *)(data_ov002_021eef74 + 0x60);
            ov002_CamMove(c, 0xb33, py, pz, 0xb33, 0, 0x148);
        }
        FIELD(w, 0x74, u8) = 4;
        FIELD(w, 0x75, u8) = 1;
        ov002_ShowMsg(self, func_0204c0e8(msg, 0x10b));
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        if (cell[2] == 1) {
            u8 *t = FIELD(cell, 8, u8 *);
            FIELD(t, 0xcd, u8) = 0;
            FIELD(t, 0x9c, s32) = 0xf85;
        } else if (cell[2] == 2) {
            FIELD(FIELD(cell, 8, u8 *), 0x9c, u8) = 0;
        }
        FIELD(self, 0x18, s32) = 0x14;
    }
}

}
