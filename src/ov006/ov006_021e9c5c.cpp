#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Rot021e9c5c {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e9c5c;

typedef struct ov006_Ent021e9c5c {
    u8 kind;
    u8 unk1;
    u16 id;
    u16 unk4;
    s16 se;
    u8 unk8[4];
} ov006_Ent021e9c5c;

typedef struct ov006_Eff021e9c5c {
    struct ov006_EffVtbl021e9c5c *vtbl;
    u8 unk4[0x20];
    int unk24;
    u8 unk28[0x14];
    fx32 unk3C;
    u8 unk40[0x88];
    int unkC8;
} ov006_Eff021e9c5c;

typedef struct ov006_EffVtbl021e9c5c {
    void *unk0[3];
    void (*setScale)(ov006_Eff021e9c5c *self, fx32 s);
} ov006_EffVtbl021e9c5c;

typedef struct ov006_Hit021e9c5c {
    u8 unk0[0xc];
    u16 unkC;
} ov006_Hit021e9c5c;

typedef struct ov006_Col021e9c5c {
    u8 unk0[0xb6];
    u16 unkB6;
    u16 unkB8;
    u16 unkBA;
    u16 unkBC;
} ov006_Col021e9c5c;

typedef struct ov006_Prop021e9c5c {
    u8 unk0[0xc];
    u16 unkC;
    u8 unkE[0x2a];
    ov006_Col021e9c5c *unk38;
    u8 unk3C[0x34];
    VecFx32 pos;
    u8 unk7C[0x20];
    VecFx32 ofs;
    u8 unkA8[0xf4];
    u16 unk19C_0 : 10;
    u16 unk19C_10 : 3;
    u16 unk19C_13 : 3;
    u8 unk19E[8];
    u16 unk1A6;
    u8 unk1A8[2];
    u8 unk1AA;
    u8 unk1AB;
    u8 unk1AC;
    u8 unk1AD;
    u8 unk1AE[0xc];
    ov006_Rot021e9c5c rot;
    u8 unk1C0[0x24];
    int unk1E4;
    int unk1E8;
    u8 unk1EC[0xc];
    u16 unk1F8;
} ov006_Prop021e9c5c;

extern "C" {

extern const ov006_Ent021e9c5c data_ov006_021eb858[];
extern u16 data_ov006_021eb894[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd68;

s32 func_ov000_0219a5c8(ov006_Prop021e9c5c *self, u16 mask, const VecFx32 *pos, ov006_Rot021e9c5c *rot, s32 r, s32 a, void **list);
ov006_Hit021e9c5c *func_ov000_021985c0(void *p);
void *func_ov000_0219be1c(s32 id, VecFx32 *pos, ov006_Rot021e9c5c *rot, u16 a, u16 b);
ov006_Eff021e9c5c *func_02065f88(int id, VecFx32 *pos);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
void *func_ov000_0218e4cc(void *mgr, u16 kind);
void func_ov000_0218dfe8(void *obj, u16 a, int b, int c, int d, int e);

void func_ov006_021e9c5c(ov006_Prop021e9c5c *self) {
    u8 a;
    u8 b;
    const ov006_Ent021e9c5c *ent;
    if (!(self->unk1A6 & 0x400) || (a = self->unk1AA) == 0 || (b = self->unk1AB) == 0) {
        return;
    }
    if (a != b) {
        return;
    }
    ent = &data_ov006_021eb858[a];
    switch (ent->kind) {
    case 1: {
        u16 id = ent->id;
        u16 tgt = 0xffff;
        VecFx32 pos;
        ov006_Rot021e9c5c rot;
        if (id == 0xffff) {
            break;
        }
        switch (id) {
        case 0x4f43: {
            void *list[0x20];
            rot = self->rot;
            rot.x += 0x4000;
            if (func_ov000_0219a5c8(self, 0x80, &self->pos, &rot, 0x3c000, 0xc8000, list) && list[0] != NULL) {
                tgt = func_ov000_021985c0(list[0])->unkC;
            }
            pos = self->pos;
            VEC_Add(&pos, &self->ofs, &pos);
            VEC_Add(&pos, &self->ofs, &pos);
            rot = self->rot;
            break;
        }
        case 0x4f44:
            pos = self->pos;
            VEC_Add(&pos, &self->ofs, &pos);
            VEC_Add(&pos, &self->ofs, &pos);
            rot = self->rot;
            break;
        default:
            id = tgt;
            break;
        }
        if (id == 0xffff) {
            break;
        }
        func_ov000_0219be1c(id, &pos, &rot, self->unkC, tgt);
        {
            ov006_Eff021e9c5c *e = func_02065f88(0x69, &self->pos);
            if (e != NULL) {
                self->unk1E4 = e->unk24;
            }
        }
        if (ent->se >= 0) {
            func_02049f44(data_02097e4c, ent->se, &self->pos, 0);
        }
        break;
    }
    case 2:
        self->unk1F8 = data_ov006_021eb894[self->unk1AD];
        if (self->unk1E8 == 0) {
            ov006_Eff021e9c5c *e = func_02065f88(0x391, &self->pos);
            if (e != NULL) {
                self->unk1E8 = e->unk24;
                VCALL(e, 0C, 0x199a);
                e->unkC8 = -1;
            }
        }
        if (ent->se >= 0) {
            func_02049f44(data_02097e4c, ent->se, &self->pos, 0);
        }
        self->unk19C_10 = 0;
        {
            ov006_Col021e9c5c *c = self->unk38;
            c->unkB6 = 0x53ff;
            c->unkB8 = 0x7f94;
            c->unkBA = 0x15;
            c->unkBC = 0x14;
        }
        break;
    case 3: {
        void *obj = func_ov000_0218e4cc(data_ov000_021ccd68, self->unkC & 0xf000);
        ov006_Eff021e9c5c *e;
        if (obj != NULL) {
            func_ov000_0218dfe8(obj, self->unkC, 0xb, 1, 0, 0);
        }
        e = func_02065f88(0x389, &self->pos);
        if (e != NULL) {
            self->unk1E4 = e->unk24;
            VCALL(e, 0C, 0x2800);
            e->unk3C = 0x3000;
        }
        if (ent->se >= 0) {
            func_02049f44(data_02097e4c, ent->se, &self->pos, 0);
        }
        break;
    }
    }
    self->unk1AB = 0;
}

}
