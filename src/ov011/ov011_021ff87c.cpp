#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d3524(void *p);

struct Ov011FfChr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad[3];
    s32 unk_04;
};

struct Ov011FfScl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 sx;
    u16 sy;
};

struct Ov011Ff {
    u8 pad[0x40];
    u16 *unk_40;
    u8 pad44[0xac];
    u8 b0 : 1;
    u8 restf0 : 7;
    u8 padf1[0xf];
    Ov011FfChr *unk_100;
    void *unk_104;
    Ov011FfScl *unk_108;
};

#pragma force_active on
void func_ov011_021ff87c(Ov011Ff *self) {
    if (*self->unk_40 == 0) {
        Ov011FfChr *c = self->unk_100;
        if (c->b0 && c->b2) {
            c->unk_04 = 1;
            c->b2 = 0;
        }
    }
    if (!self->b0) {
        Ov011FfScl *p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->sx = 0x1000;
        p->sy = 0x1000;
    }
    func_ov003_021d3524(self);
}
#pragma force_active reset
}
