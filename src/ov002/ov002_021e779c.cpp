#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e779c(void *self) {
    void *o = FIELD(self, 0x48, void *);
    G020927f8 *g;
    if (o != NULL && FIELD(o, 4, s32) == 8) {
        s32 y = FIELD(o, 0x54, s32) + 0x120000;
        s32 x = FIELD(o, 0x50, s32);
        Vec3 *v = &FIELD(self, 0x50, Vec3);
        Vec3 *w = &FIELD(self, 0x5c, Vec3);
        v->x = x;
        v->y = y;
        v->z = 0;
        w->x = x;
        w->y = y;
        w->z = -0x1000;
    }
    g = &data_020927f8;
    g->v240 = FIELD(self, 0x50, Vec3);
    g->v24c = FIELD(self, 0x68, Vec3);
    g->v258 = FIELD(self, 0x5c, Vec3);
    func_02011ff0((u8 *)self + 0x50, (u8 *)self + 0x68, (u8 *)self + 0x5c, data_02092844);
    g->fc &= ~0xe8;
    func_02016d68((u8 *)self + 0x74, data_02092800, 0x40);
    g->fc &= ~0x50;
}

BOOL func_ov002_021e7880(void *self) {
    Vec3 v = data_ov002_021ef110;
    s32 x;
    FIELD(self, 0x68, Vec3) = v;
    if (FIELD(self, 8, s32) == 1) {
        x = 0x90000;
    } else if (FIELD(self, 8, s32) == 2) {
        x = -0x90000;
    }
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = x;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = x;
    FIELD(self, 0x64, s32) = -0x1000;
    return TRUE;
}

BOOL func_ov002_021e7900(void *self) {
    void *found = NULL;
    void *cur = FIELD(self, 0xb4, void *);
    if (cur == NULL) {
        found = func_ov002_021e4ee4(self, 3, -1);
    } else if (FIELD(cur, 0xe8, Bits8).b1) {
        found = func_ov002_021e4ee4(self, 3, FIELD(cur, 0x18, s32));
    }
    if (found != NULL) {
        if (FIELD(self, 0xb4, void *) != NULL) {
            func_ov002_021e6360(FIELD(self, 0xb4, void *));
        }
        func_ov002_021e61b4(found);
        FIELD(self, 0xb4, void *) = found;
    }
    cur = FIELD(self, 0xb4, void *);
    if (cur != NULL) {
        s32 x = FIELD(cur, 0xdc, s32);
        s32 y = FIELD(cur, 0xe0, s32);
        Vec3 *v = &FIELD(self, 0x50, Vec3);
        Vec3 *w = &FIELD(self, 0x5c, Vec3);
        v->x = x * 100;
        v->y = y * 100;
        v->z = 0;
        w->x = x * 100;
        w->y = y * 100;
        w->z = -0x1000;
    }
    return TRUE;
}

BOOL func_ov002_021e79b0(void *self) {
    FIELD(self, 0x4c, Bits16).b6 = 0;
    return TRUE;
}

BOOL func_ov002_021e79c4(void *self) {
    u8 *ctx = (u8 *)data_ov002_021f0f98[1];
    BOOL r = TRUE;
    if (FIELD(self, 0x18, s32) > FIELD(ctx, 0xd4, s32) && FIELD(self, 0x18, s32) <= FIELD(ctx, 0xd0, s32)) {
        u8 *g;
        func_0206e3a0((u8 *)self + 0x4c, FIELD(self, 0x50, void *));
        g = data_02097d48 + 0x8b0;
        if (!FIELD(self, 0x4c, Bits16).b2) {
            FIELD(g, 0, Bits8).b4 = 0;
            FIELD(g, 0, Bits8).b5 = 1;
            *(vu16 *)0x04000060 &= 0xcfdf;
        }
        if (!FIELD(self, 0x4c, Bits16).b3) {
            func_02013dbc(0, FIELD(g, 8, void *), FIELD(g, 0xc, void *), FIELD(g, 0x10, u16));
            FIELD(g, 0, Bits8).b3 = 0;
        }
        func_02043b20(g);
        r = FALSE;
    }
    return r;
}

BOOL func_ov002_021e7a94(void *self) {
    BOOL r = TRUE;
    if (FIELD(data_ov002_021f0f98[1], 0xd0, s32) >= FIELD(self, 0x1c, s32)) {
        r = FALSE;
    }
    return r;
}

Oam021e7ab8 *func_ov002_021e7ab8(void *self, u16 *flag, Oam021e7ab8 *oam, u16 *count) {
    u16 n = *count;
    if (*flag == 0) {
        u8 pal = FIELD(self, 0x70, s32);
        int i;
        for (i = 0; i < n; i++) {
            oam[i].x -= 0x80;
            oam[i].y -= 0x60;
            oam[i].pal += pal;
        }
    }
    *count = n;
    return oam;
}

void func_ov002_021e7b58(void) {
    void *p;
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*(VObject **)&data_ov002_021f0f98[1]);
        HEAP_POP(saved);
    }
    p = func_0203dd9c(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0674;
        *(VFunc **)((u8 *)p + 0x6c) = data_ov002_021f0684;
        func_ov002_021eacd0((u8 *)p + 0x6c);
        func_02043858((u8 *)p + 0x14c);
        func_ov002_021e7cb4(p);
    }
    data_ov002_021f0f98[1] = p;
}

void *func_ov002_021e7bfc(void *self) {
    *(VFunc **)self = data_ov002_021f0684;
    func_ov002_021eae3c(self);
    return self;
}

void func_ov002_021e7c1c(void) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*(VObject **)&data_ov002_021f0f98[1]);
    HEAP_POP(saved);
}

void *func_ov002_021e7c78(void *self) {
    *(VFunc **)self = data_ov002_021f0674;
    func_ov002_021e7dac(self);
    *(VFunc **)((u8 *)self + 0x6c) = data_ov002_021f0684;
    func_ov002_021eae3c((u8 *)self + 0x6c);
    func_0203de1c(self);
    return self;
}

}
