#include "types.h"

typedef struct {
    u8 pad_00[0xa];
    u16 unk_0a_0 : 3;
    u16 unk_0a_3 : 2;
    u16 unk_0a_5 : 1;
    u16 unk_0a_6 : 10;
} Ov003Flags;

typedef struct {
    u8 pad_00[0x13];
    u8 kind;
} Ov003EvWork;

typedef struct {
    u8 pad_00[0x50];
    u32 flags;
} Ov003EvCtl;

typedef struct {
    u16 hp;
    u8 pad_02[4];
    u16 dmg;
    u8 kind;
    u8 kind2;
} Ov003EvHp;

typedef struct {
    u16 dmg;
    u8 kind;
} Ov003Hit;

typedef struct {
    u8 pad_00[0xb24];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003EvPlayer;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 pad_10[0x30];
    Ov003EvWork *unk_40;
    u8 pad_44[4];
    Ov003EvCtl *ctl;
    u8 pad_4c[4];
    Ov003EvHp *hp;
    u8 pad_54[0x5c];
    Ov003Flags *unk_b0;
    u8 pad_b4[0x28];
    u16 unk_dc;
    u8 pad_de[0xa];
    u16 unk_e8;
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 8;
    u16 unk_ea_11 : 1;
    u8 unk_ec_0 : 1;
} Ov003Ev;

typedef struct {
    u8 pad_00[0xac];
    u8 unk_ac;
} Ov003G54;

extern Ov003G54 *data_ov000_021ccd54;
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

void func_ov003_021d64f0(Ov003Ev *self) {
    if (self->unk_b0->unk_0a_5) {
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

extern const u8 data_ov003_021f43dc[];
extern const u8 data_ov003_021f43e1[];
extern const u8 data_ov003_021f43e6[];
extern const u8 data_ov003_021f43eb[];
extern const u8 data_ov003_021f4428[];
extern const u8 data_ov003_021f442d[];
extern const u8 data_ov003_021f4432[];
extern const u8 data_ov003_021f4437[];
extern const u8 data_ov003_021f443c[];
extern const u8 data_ov003_021f4441[];
extern void func_ov003_021cedf4(s32 n);
extern Ov003EvPlayer *func_ov000_0219bf90(void);

static inline BOOL Ov003EvPlayer_Flag(Ov003EvPlayer *pl) {
    return pl->unk_b24_1 ? TRUE : FALSE;
}

u8 func_ov003_021d6548(Ov003Ev *self, Ov003Hit *hit) {
    Ov003EvHp *hp;
    u16 old;
    u8 res;
    u8 kind;
    u8 kind2;
    u16 dmg;
    s32 cur;
    kind = hit->kind;
    dmg = hit->dmg;
    hp = self->hp;
    old = hp->hp;
    res = 0;
    kind2 = kind;

    if (dmg >= old) {
        hp->hp = 0;
    } else {
        hp->hp = old - dmg;
    }
    cur = hp->hp;
    if (cur <= 0) {
        if (self->unk_b0->unk_0a_0 == 0 || ((s32)old <= 0 && (kind == 0x40 || kind == 0x41))) {
            res = 0x15;
        } else {
            res = 0x14;
        }
    } else {
        if (kind == 0x41) {
            res = 0x14;
            kind2 = 0x41;
        } else if (self->unk_e8 != 0) {
            res = 0x14;
        } else if (kind != 1) {
            u16 step = self->unk_dc;
            s32 th = step;
            s32 i;
            for (i = 1; i < self->unk_b0->unk_0a_0; i++, th += step) {
                {
                    if (old <= th) {
                        break;
                    }
                    if (cur <= th) {
                        res = 0x13;
                        kind2 = 0x21;
                        self->unk_ea_0 = 4;
                        break;
                    }
                }
            }
        }
        if (dmg != 0) {
            func_ov003_021cedf4(8);
        }
    }
    if (res == 0 && kind2 != 2 && kind2 != 1) {
        switch (kind) {
        case 0x10:
            kind2 = data_ov003_021f4428[self->unk_ea_0];
            res = data_ov003_021f43dc[self->unk_ea_0];
            break;
        case 0x11:
            kind2 = data_ov003_021f442d[self->unk_ea_0];
            res = data_ov003_021f43e1[self->unk_ea_0];
            break;
        case 0x20:
            kind2 = data_ov003_021f4432[self->unk_ea_0];
            res = data_ov003_021f43e6[self->unk_ea_0];
            break;
        case 0x21:
        case 0x40:
        case 0x42:
            kind2 = data_ov003_021f4437[self->unk_ea_0];
            res = data_ov003_021f43e6[self->unk_ea_0];
            break;
        case 0x30:
            kind2 = data_ov003_021f443c[self->unk_ea_0];
            res = data_ov003_021f43eb[self->unk_ea_0];
            break;
        case 0x31:
            kind2 = data_ov003_021f4441[self->unk_ea_0];
            res = data_ov003_021f43eb[self->unk_ea_0];
            break;
        case 0x41:
            kind2 = 0x41;
            res = 0x14;
            break;
        }
        if (self->ctl != NULL && !(self->ctl->flags & 0x20000000)) {
            switch (self->unk_ea_0) {
            case 0:
            case 1:
                if (res != 0x13 && res != 0x14) {
                    res = 0x13;
                    kind2 = 0x20;
                }
                break;
            default:
                if (res != 0) {
                    res = 0;
                    kind2 = 2;
                }
                break;
            }
        }
    }
    if (res == 0x12 && kind2 == 2) {
        u8 f = self->unk_ec_0;
        u8 k = self->unk_40->kind;
        if (!f && k != 1 && k != 2) {
            res = 0;
        }
    }
    self->unk_ea_11 = 0;
    if (dmg == 0 && (res == 0x12 || res == 0x13)) {
        Ov003EvPlayer *pl = func_ov000_0219bf90();
        if (pl != NULL && Ov003EvPlayer_Flag(pl) == FALSE) {
            self->unk_ea_11 = 1;
        }
    }
    hp = self->hp;
    hp->dmg = dmg;
    hp->kind = kind;
    hp->kind2 = kind2;
    return res;
}
