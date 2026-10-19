#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a48[];
extern void func_ov000_02191318(void *a, s32 b);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);
void VEC_Normalize(const Ov014Vec *a, Ov014Vec *b);

void func_ov014_0220bd64(Ov014Actor *self) {
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0: {
        u8 *g;
        Ov014Sub48 *q;
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        g = (u8 *)data_ov000_021ccd54;
        g[0xac] = 1;
        func_ov000_02182590(g + 0xac);
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a4e, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        FLD(u16, self->unk_48, 0x9a) |= 0x12;
        q = self->unk_48;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
        self->unk_40->state++;
        self->unk_ec_0 = 0;
        break;
    }
    case 1: {
        Ov014Actor *e;
        if (!Ov014_GameIdle()) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02217a48, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        func_0204a028(data_02097e4c, 0x32, &self->pos, 4);
        func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
        func_ov000_0218996c(0xf, 0x3c);
        e = func_02065f88(0x66, &self->pos);
        e->v14(0x2800, 0x4800, 0x2800);
        self->unk_40->state++;
        FLD(u8, self, 0x1a5) = 1;
        break;
    }
    case 2: {
        Ov014Vec tgt;
        Ov014Vec d;
        tgt.x = 0;
        tgt.y = tgt.x + 0x1000;
        tgt.z = 0x3000;
        d.x = tgt.x - self->pos.x;
        d.y = tgt.y - self->pos.y;
        d.z = tgt.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &tgt) >= 0x19a) {
            break;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0x3c;
        break;
    }
    case 3:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_40->state++;
        }
        break;
    case 4: {
        Ov014Sub48 *q;
        self->pos.y -= 0x52;
        q = self->unk_48;
        if (self->pos.y >= q->unk_68.y) {
            break;
        }
        self->pos.x = 0;
        self->pos.y = 0;
        FLD(u8, self, 0x1a5) = 1;
        self->pos.z = 0x3000;
        FLD(u16, q, 0x9a) |= 0x24;
        self->unk_40->state++;
        break;
    }
    case 5:
        s->state = 0xffff;
        break;
    }
}

}
