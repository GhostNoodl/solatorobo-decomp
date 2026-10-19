#include "ov014/ov014.h"

struct Ov014G190C {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

struct Ov014BgmC {
    u16 active : 1;
    u16 rest : 15;
};

extern "C" {

extern u8 data_ov014_02217d7c[];
extern u8 data_ov014_02217d82[];
extern void func_ov000_02191318(void *a, s32 b);
extern void func_ov000_02191618(void *a);
extern BOOL func_ov000_02191120(void *a);

void func_ov014_02211f0c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n;
        if (FLD(u16, self, 0x150) == 0x4806) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d7c, 0x1000, 0);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d82, 0x1000, 0);
        }
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 0;
        break;
    }
    case 1: {
        Ov014Sub44 *n;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        self->unk_40->state = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        break;
    }
    default: {
        Ov014Sub44 *n;
        self->unk_40->state = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        break;
    }
    }
}

extern void *data_02097e4c;
extern u8 *data_02097e48;
extern void *data_0214a420;
extern u8 data_ov014_02217d88[];
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(void *p);
extern void func_ov000_021911c8(void *a, s32 b);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_02065860(void *a, void *b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov014Actor *self, s32 a, s32 b, s32 c);

// *(&data_02097e4c) keeps the global's address in a saved register (r7) across the
// switch, as in the target; a plain data_02097e4c reloads it from the pool each time.
void func_ov014_02212050(Ov014Actor *self) {
    u16 t;
    Ov014Vec v1;
    Ov014Vec v3;
    u8 b;
    switch (*(volatile u16 *)&self->unk_40->state) {
    case 0: {
        Ov014Game54 *g;
        Ov014Sub44 *n;
        Ov014Actor *e;
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        g = data_ov000_021ccd54;
        FLD(u8, g, 0xac) = 1;
        func_ov000_02182590((u8 *)g + 0xac);
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d88, 0x19a, 0);
        func_ov000_021911c8(self->unk_38, 0x400);
        func_ov000_02191618(self->unk_38);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        b = 0x15;
        func_ov000_0219bd20(0x5c16, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4806, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4814, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4815, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4816, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4838, self->id, 2, 1, 1, &b);
        func_ov000_0219bd20(0x4839, self->id, 2, 1, 1, &b);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v24(0, 0x6000, 0x4000);
            e->v0c(0x6000);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x5a);
        self->unk_40->timer = 0x258;
        self->unk_40->state++;
        break;
    }
    case 1: {
        t = self->unk_40->timer;
        if (t != 0) {
        if (t == 0x21c) {
            Ov014Actor *e = func_02065f88(0x390, &self->pos);
            e->v24(0, 0x6000, 0x2000);
            e->v0c(0x3000);
            FLD(void *, self, 0x158) = FLD(void *, e, 0x24);
            func_02049f44(*(&data_02097e4c), 0x44, &self->pos, 0);
        }
        if (t == 0x1fe || t == 0x1e0 || t == 0x1c2 || t == 0x1a4) {
            func_02049f44(*(&data_02097e4c), 0x44, &self->pos, 0);
        }
        if (t == 0x12c) {
            func_02065860(data_0214a420, FLD(void *, self, 0x158));
        }
        if (t == 0x140) {
            Ov014Game54 *g = data_ov000_021ccd54;
            u8 *h;
            FLD(Ov014G190C, g, 0x190).b2 = 1;
            FLD(Ov014G190C, g, 0x190).b3 = 0;
            FLD(Ov014G190C, g, 0x190).b4 = 0;
            FLD(u8, g, 0x18d) = 0x10;
            FLD(u8, g, 0x18e) = 0x1e;
            FLD(u8, g, 0x18f) = 0x1e;
            FLD(u8, g, 0x18c) = 1;
            h = data_02097e48;
            if (FLD(Ov014BgmC, h, 0).active != 1 || FLD(u16, h, 0x74) != 0xffff || FLD(u16, h, 0x72) != 0x38) {
                FLD(u16, h, 0x74) = 0x38;
                FLD(u16, h, 0x70) = 0;
            }
        }
        if (t <= 0xc8 && t % 30 == 0) {
            Ov014Actor *e;
            s32 r;
            v1 = self->pos;
            v1.x += func_02040528(0x4000);
            v1.y = func_02040528(0x3000) + 0x5000;
            v1.z += func_02040528(0x1000) + 0x5000;
            e = func_02065f88(0x38f, &v1);
            r = func_02040498(0x1000);
            e->v14(r + 0x2800, r + 0x2800, r + 0x2800);
            func_02049f44(*(&data_02097e4c), 0x35, &v1, 0);
            func_02049f44(*(&data_02097e4c), 0x56, &v1, 0);
        }
        if (t > 0xfa) {
            s32 a = 0;
            s32 **q = func_ov000_02190a30(self->unk_38, 0);
            if (*q != NULL) {
                a = **q;
            }
            if (a >= 0x8000) {
                func_ov000_02191318(self->unk_38, 0);
            }
        }
        if (t == 0xfa) {
            func_ov000_021911c8(self->unk_38, 0x1000);
        }
        {
            Ov014Sub40 *s = self->unk_40;
            if (s->timer != 0) {
                s->timer--;
            }
        }
        } else {
            Ov014Game54 *g;
            self->unk_40->state++;
            g = data_ov000_021ccd54;
            FLD(u8, g, 0x18c) = 0;
            FLD(u8, g, 0x18d) = 0;
            FLD(u8, g, 0x18e) = 0;
            FLD(u8, g, 0x18f) = 0;
        }
        break;
    }
    case 2:
        func_ov003_021d6a3c(self, 0, 1, 1);
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d88, 0x19a, 0);
        func_ov000_02191618(self->unk_38);
        func_ov000_021911c8(self->unk_38, 0x1000);
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 3: {
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer % 48 != 0) {
            break;
        }
        v3 = self->pos;
        v3.x += func_02040528(0xa000);
        v3.y = func_02040528(0x3000) + 0x5000;
        v3.z += func_02040528(0x1000) + 0x5000;
        func_02065f88(0x38f, &v3)->v14(0x2ccd, 0x2ccd, 0x2ccd);
        func_0204a028(*(&data_02097e4c), 0x35, &v3, -(func_02040498(5) + 2));
        func_02049f44(*(&data_02097e4c), 0x56, &v3, 0);
        func_ov000_0218996c(10, 0x1e);
        break;
    }
    }
}

}
