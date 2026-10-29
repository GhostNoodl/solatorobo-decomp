#include "ov002/ov002.h"

extern "C" {
BOOL func_ov002_021e45c4(void *g, void *a, void *b);
BOOL func_ov002_021e4578(Vec2 *pos, Vec2 *d, void *a, void *b);
void func_ov002_021d8c34(void *self, s32 d, void *map);
s32 func_02049bdc(void *a, int b, int c);
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

static inline void ov002_SyncCursor(void *self) {
    u8 *g = FIELD(self, 0x10, u8 *);
    FIELD(self, 0x1c, s32) = FIELD(g, 0x54, s32);
    FIELD(self, 0x20, s32) = FIELD(g, 0x58, s32);
    func_ov002_021e019c(self, FIELD(self, 0x1c, s32), FIELD(self, 0x20, s32));
}

static inline BOOL ov002_TryMove(u8 *g, s32 dx, s32 dy, void *map) {
    BOOL r = FALSE;
    Vec2 d;
    if (FIELD(g, 0xa4, s32) != 0 || FIELD(g, 0xac, s32) != 1) {
        return FALSE;
    }
    d.x = dx;
    d.y = dy;
    if (func_ov002_021e4578((Vec2 *)(g + 0x54), &d, map, g + 0x4c)) {
        FIELD(g, 0x54, s32) += d.x;
        FIELD(g, 0x58, s32) += d.y;
        if (FIELD(g, 0xac, s32) == 1) {
            func_ov002_021e3b0c((s32 *)(g + 0xb0), (s32 *)(g + 0x54), (s32 *)(g + 0x64));
            FIELD(g, 0xb4, s32) = FIELD(g, 0x8, s32);
            FIELD(g, 0xbc, s32) = FIELD(g, 0x4, s32);
            FIELD(g, 0xc0, s32) = FIELD(g, 0x8, s32);
            FIELD(g, 0xc4, s32) = FIELD(g, 0xc, s32);
            FIELD(g, 0xa4, s32) = 4;
            FIELD(g, 0xa8, s32) = 4;
            FIELD(g, 0xac, s32) = 4;
            func_02049a48(data_02097e4c, 0x22, -1, -1, -1);
        }
        r = TRUE;
    }
    return r;
}

extern "C" {

static inline u8 *GetUnit021dfcc0(void *self) { return FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *); }
static inline u8 *GetMap021dfcc0(u8 *unit) { return FIELD(FIELD(unit, 0x4, u8 *), 0x6c, u8 *); }
static inline void *GetMgr021dfcc0(void) { return data_02149ef8; }

void func_ov002_021dfcc0(void *self) {
    u8 *cam;
    void *mgr;
    u8 *cur;
    u8 *pad = data_02097dc8;
    s32 trg = FIELD(pad, 0x12, u16);
    u16 rep = FIELD(pad, 0x16, u16);
    u8 *unit = GetUnit021dfcc0(self);
    mgr = GetMgr021dfcc0();
    u8 *map;
    if (trg & 2) {
        if (FIELD(FIELD(self, 0x10, u8 *), 0xac, s32) != 1) {
            return;
        }
        FIELD(self, 0x18, s32) = 0x1e;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return;
    }
    if (trg & 1) {
        if (FIELD(FIELD(self, 0x10, u8 *), 0xac, s32) != 1) {
            return;
        }
        if (!func_ov002_021e45c4(FIELD(self, 0x10, u8 *), FIELD(unit, 0x6c, void *), FIELD(FIELD(unit, 0x4, u8 *), 0x6c, void *))) {
            FIELD(self, 0x18, s32) = 0x14;
            return;
        }
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        return;
    }
    map = GetMap021dfcc0(unit);
    if (rep & 0xf0) {
        Vec2 d = {0, 0};
        Vec2 p;
        Vec2 out;
        u8 *g;
        if (rep & 0x40) {
            d.y--;
        } else if (rep & 0x80) {
            d.y++;
        } else if (rep & 0x20) {
            d.x--;
        } else if (rep & 0x10) {
            d.x++;
        }
        cur = FIELD(self, 0x10, u8 *);
        if (ov002_TryMove(cur, d.x, d.y, map)) {
            ov002_SyncCursor(self);
            return;
        }
        g = FIELD(self, 0x10, u8 *);
        p = *(Vec2 *)(g + 0x54);
        p.x += d.x;
        p.y += d.y;
        func_ov002_021e3dac(&p, map, g + 0x4c, &out);
        if (out.x < FIELD(map, 0x4, Nibbles16).n2) {
            return;
        }
        {
            void *s = func_0204c0e8(mgr, 0x10c);
            u8 *o = FIELD(self, 0x4, u8 *);
            func_ov000_0215bb14(FIELD(o, 0x20, void *), s);
            VC(FIELD(o, 0x20, void *), 0x70)();
        }
        FIELD(unit, 0x74, u8) = 8;
        FIELD(unit, 0x75, u8) = 1;
        cam = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
        { s32 a44 = *(s32 *)(data_ov002_021eef74 + 0x44); s32 a48 = *(s32 *)(data_ov002_021eef74 + 0x48); ov002_CamMove(cam, 0xb33, a44, a48, 0xb33, 0, 0xa4); }
        FIELD(self, 0x18, s32) = 10;
        func_02049a48(data_02097e4c, 0xe, -1, -1, -1);
        return;
    }
    if (!(trg & 0x300)) {
        return;
    }
    if (trg & 0x100) {
        func_ov002_021d8c34(FIELD(self, 0x10, void *), -1, map);
    } else if (trg & 0x200) {
        func_ov002_021d8c34(FIELD(self, 0x10, void *), 1, map);
    }
    ov002_SyncCursor(self);
    func_02049bdc(data_02097e4c, 0x47, 6);
}

}
