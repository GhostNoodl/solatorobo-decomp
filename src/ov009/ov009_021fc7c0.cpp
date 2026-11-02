#include "ov009/ov009.h"

extern "C" {

extern u8 *Group_FindNode(void *mgr, u16 id);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021fc7c0(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    self->pos.y += 0x4000;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    self->unk_40->flags |= 0x100000000ULL;
    self->unk_4c->unk_18 |= 2;
}

void func_ov009_021fc834(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        self->unk_38->unk_c2_0 = 0;
        self->unk_40->state++;
        break;
    case 1:
        if (Ov009_GameIdle()) {
            self->unk_38->unk_c2_0 = 1;
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        break;
    }
}

extern void *data_02097e4c;
extern char data_ov009_02216ac8[];
extern char data_ov009_02216ab0[];
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218999c(s32 a, s32 b);
void func_ov009_021fc8f4(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub38 *m;
    switch (st->state) {
    case 0:
        self->unk_40->timer = Rand_UpTo(0x4b);
        self->unk_40->state++;
        break;
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
        m = self->unk_38;
        m->unk_c2_0 = 1;
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ac8, 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_a8 = 0x52;
        self->unk_40->state++;
        break;
    case 2:
        if (self->unk_48->unk_50 & 0x20000000) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02216ab0, 0x800, 0);
            func_02049a48(data_02097e4c, 8, -1, -1, -1);
            func_ov000_0218999c(8, 0xa);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        } else {
            Actor_Move((Actor *)self, 0);
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
        }
        break;
    case 3:
        self->unk_48->unk_9a_5 = 1;
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

extern void func_0203f364(Ov009Sub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0219b5dc(u16 id, const Ov009Vec *pos, const u16 *rot);
extern void func_ov003_021ce9c4(u16 id);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern u8 *data_0214a424;
void func_ov009_021fcad0(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Sub40 *st;
    if (self->unk_1a == 0) {
        func_ov003_021d6054(self);
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov009Sub38 *m;
        Ov009V *o;
        u32 n;
        self->unk_50[0] = 0;
        if (self->unk_48 != NULL) {
            Ov009Sub48 *s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
        }
        if (self->unk_44 != NULL) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->unk_4c->target = 0xffff;
        m = self->unk_38;
        m->unk_c2_9 = 2;
        NNSi_G3dModifyPolygonAttrMask(FLD(void *, m, 4), 0, 0xc0);
        self->unk_ea_3 = 0;
        func_ov000_0218996c(8, 0xa);
        p = self->pos;
        p.y += (self->unk_68 >> 1) - (self->unk_68 >> 3);
        o = func_02065f88(3, &p);
        if (o != NULL) {
            s32 s = self->unk_64 + (self->unk_64 >> 3);
            o->v14(s, s, s);
        }
        func_ov000_0219b5dc(FLD(u16, self->unk_b0, 6), &p, self->rot);
        func_ov003_021ce9c4(FLD(u16, self->unk_b0, 4));
        n = FLD(u16, data_0214a424, 0xa) + 1;
        if (n >= 0xffff) {
            n = 0xffff;
        }
        FLD(u16, data_0214a424, 0xa) = n;
        self->unk_50[2] = 0xffff;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 0x78) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        } else {
            u16 h = (u16)(self->unk_40->timer >> 1);
            if (h > 0x1f) {
                h = 0x1f;
            }
            func_ov003_021d6954(self, 0x1f - h);
        }
        break;
    }
}

}
