#include "types.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 3;
    u16 b8 : 1;
    u16 rest : 7;
} Bits02195d88;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 rest : 4;
} Bits8_02195d88;

typedef struct {
    u16 x, y, z;
} Rot02195d88;

extern "C" {
extern char data_ov000_021cc45c[];
extern u8 *data_0214a424;
void func_ov000_02191008(void *a);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_0203f364(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u8 *func_ov000_02199ba0(void *a);
u16 func_ov000_02199bc8(void *a, void *pos, u16 t, s32 n);
Robo021ca458 *func_ov000_0219bf90(void);
void func_ov003_021f0c60(void *self, s32 a);

void func_ov000_02195d88(ActorEx *self) {
    ActorSub40 *s = self->unk_40;
    switch (s->st) {
    case 0:
        self->unk_93_1 = 1;
        if (self->unk_38 != NULL) {
            char *name = self->unk_4c->unk_0c;
            if (name != NULL) {
                if (STD_CompareString(name, data_ov000_021cc45c) == 0) {
                    func_ov000_02191008(self->unk_38);
                } else {
                    func_ov000_02190cb0(self->unk_38, name, 0x1000, 0);
                    func_ov000_021915a0(self->unk_38);
                }
            }
            LFLD(u8, self->unk_38, 0xbe) = 0x1f;
        }
        if (self->unk_44 != NULL) {
            u8 *q = self->unk_44;
            LFLD(Bits02195d88, q, 0x22).b0 = 0;
            LFLD(Bits02195d88, q, 0x22).b1 = 0;
        }
        if (self->unk_48 != NULL) {
            ActorSub48 *p = self->unk_48;
            p->unk_50 = 0;
            p->unk_54 = 0;
            p->unk_58 = 0;
            p = self->unk_48;
            LFLD(Bits02195d88, p, 0x9a).b0 = 0;
            p->unk_9a_3 = 0;
            func_0203f364(p);
            p = self->unk_48;
            LFLD(Bits02195d88, p, 0x9a).b1 = 0;
            p->unk_9a_4 = 0;
        }
        self->target = 0xffff;
        if (self->unk_58 != NULL) {
            self->unk_cc_0 = 0;
        }
        if (LFLD(Bits02195d88, self->unk_b0, 2).b8) {
            LFLD(Bits8_02195d88, ((u8 *)self->unk_4c), 0x18).b0 = 1;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 2;
        self->unk_40->st++;
        break;
    case 1: {
        u8 *t = func_ov000_02199ba0(((u8 *)self->unk_4c));
        u16 r;
        Robo021ca458 *pl;
        if (t != NULL) {
            r = func_ov000_02199bc8(((u8 *)self->unk_4c), &self->pos, self->unk_40->timer, 10);
            LFLD(Rot02195d88, self, 0x7c) = LFLD(Rot02195d88, t, 0x7c);
            self->unk_40->timer = r;
            if (self->unk_4c->unk_01 != 3) {
                break;
            }
            if (r < 10) {
                break;
            }
            pl = func_ov000_0219bf90();
            if (pl->id == self->unk_4c->unk_1c) {
                u32 n = LFLD(u16, data_0214a424, 0x16) + 1;
                if (n >= 0xffff) {
                    n = 0xffff;
                }
                LFLD(u16, data_0214a424, 0x16) = n;
                if (self->unk_44 != NULL) {
                    u8 *q = self->unk_44;
                    LFLD(Bits02195d88, q, 0x22).b0 = 0;
                    LFLD(Bits02195d88, q, 0x22).b1 = 0;
                }
                if (self->unk_48 != NULL) {
                    ActorSub48 *p = self->unk_48;
                    LFLD(Bits02195d88, p, 0x9a).b0 = 0;
                    p->unk_9a_3 = 0;
                    func_0203f364(p);
                    p = self->unk_48;
                    LFLD(Bits02195d88, p, 0x9a).b1 = 0;
                    p->unk_9a_4 = 0;
                }
                if (self->unk_4c->unk_03 != 0) {
                    self->unk_4c->unk_1c = 0xffff;
                    func_ov003_021f0c60(self, 0);
                }
            }
            func_ov000_02198360(self->unk_40, 0x15, 0);
        } else {
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        break;
    }
    }
}
}
