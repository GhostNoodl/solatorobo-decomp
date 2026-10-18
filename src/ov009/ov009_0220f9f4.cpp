#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_0220f9f4(Ov009Actor *self) {
    Ov009Actor *a;
    func_ov003_021d112c(self);
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
}

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern BOOL func_ov000_021983b0(void *st, s32 a, s32 b, s32 c);
static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

struct Ov009Group {
    u8 unk_00[0xc];
    Ov009Actor *head;
};

extern Ov009Group *func_ov000_0218e4cc(void *mgr, u16 id);

void func_ov009_0220fa20(Ov009Actor *self) {
    Ov009Actor *p;
    Ov009Group *g;
    Ov009Actor *a;
    if (!Ov009_GameIdle()) {
        return;
    }
    {
    u8 mode = self->unk_40->unk_13;
    self->unk_93_4 = 1;
    if (mode == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            if (self->kind != 0x541a) {
                Ov009Actor *t = func_ov000_0218d240(self);
                if (Ov009_DistXZ(&self->pos, &t->pos) < 0x3800 && func_ov000_021983b0(self->unk_40, 0x10, 4, 1)) {
                    self->unk_40->flags |= 0x8000;
                    self->unk_b6 = 0x78;
                } else {
                    self->unk_40->flags |= 0x10000;
                    self->unk_b6 = 0xb4;
                }
            } else {
                self->unk_40->flags |= 0x20000;
                self->unk_b6 = 0x96;
            }
        }
    }
    }
    if (self->kind != 0x541a) {
        return;
    }
    p = func_ov000_0219bf90();
    g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
    if (p == NULL || g == NULL || (a = g->head) == NULL) {
        return;
    }
    do {
        if (a->kind == 0x4006 && FLD(u8 *, a, 0x4c) != NULL && FLD(u16, FLD(u8 *, a, 0x4c), 0x1c) == p->id &&
            a->unk_48 != NULL) {
            a->unk_48->unk_30 = 0;
        }
        a = (a != NULL) ? FLD(Ov009Actor *, a, 8) : g->head;
    } while (a != NULL);
}

extern void *data_02097e4c;
extern u8 data_ov009_022179a8[];
extern u8 data_ov009_022179ae[];
extern void func_ov000_02191318(void *m, s32 a);
extern void func_ov000_02191690(void *m);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_0220fc38(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x1000, 0);
        func_ov000_02191318(self->unk_38, 0x35000);
        func_ov000_02191690(self->unk_38);
        FLD(s32, self, 0xf0) = self->pos.y;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
        if (self->kind == 0x541a) {
            s48 = self->unk_48;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
            self->pos.y += 0x10000;
        } else {
            self->pos.y += 0x8000;
        }
        self->unk_a0 = -0x19a;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        func_02049a48(data_02097e4c, 0x63, -1, -1, -1);
        self->unk_40->state++;
        break;
    case 1:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            if (FLD(s32, self, 0xf0) < self->pos.y) {
                return;
            }
            if (self->unk_a0 >= 0) {
                return;
            }
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022179ae, 0x200, 0);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        func_ov000_0218996c(0x14, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        self->unk_40->state++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x1e) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
