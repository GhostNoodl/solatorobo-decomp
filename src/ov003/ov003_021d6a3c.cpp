#include "types.h"

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003Game54;

typedef struct {
    u8 unk_00[0xa];
    u16 unk_0a;
    u8 unk_0c[0x14c];
    u32 flags[1][4];
} Ov003SaveData;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
} Ov003Player;

typedef struct {
    u8 unk_00[4];
    u16 unk_04;
} Ov003Link;

class Ov003Pickup {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    u8 unk_04[0x8];
    u16 id;
    u16 kind;
    u8 unk_10[0x7];
    u8 index;
    u8 unk_18[0x38];
    Ov003Link *unk_50;
    u8 unk_54[0x58];
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae[2];
    Ov003Link *unk_b0;
};

extern "C" {
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003SaveData *data_0214a424;
extern void *data_ov000_021ccd64;

s32 func_0206e7ec(u32 a, u32 b);
Ov003Player *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627a0(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_ov000_02182590(u8 *p);
void func_ov003_021ce9c4(u16 id);
void func_ov000_0218bed8(void *mgr, s32 a, void *obj);

}

static inline void SaveData_SetNibble(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int SaveData_GetNibble(s32 row, s32 idx) {
    u32 w = data_0214a424->flags[row][idx / 8];
    return (w >> ((idx % 8) * 4)) & 0xf;
}

static inline void Obj_StoreValue(Ov003Pickup *self, u8 value) {
    u8 idx = self->index;
    s32 row;

    if (idx != 0xff) {
        row = func_0206e7ec(self->unk_ac, self->unk_ad);
        if (row != 0xffff) {
            value |= SaveData_GetNibble(row, idx) & 8;
            SaveData_SetNibble(row, idx, value);
        }
    }
}

extern "C" void func_ov003_021d6a3c(Ov003Pickup *self, BOOL release, BOOL mark, BOOL sound) {
    Ov003Player *pl = func_ov000_0219bf90();
    if (pl != NULL && !func_ov000_021b4738()) {
        if (sound) {
            func_020627a0(self->kind, self->id);
            func_020627dc(2);
            {
                Ov003Game54 *g = data_ov000_021ccd54;
                g->unk_ac = 1;
                func_ov000_02182590(&g->unk_ac);
            }
        }
        if (mark) {
            u8 idx = self->index;
            if (idx != 0xff) {
                s32 row = func_0206e7ec(self->unk_ac, self->unk_ad);
                if (row != 0xffff) {
                    u8 value = 0xf;
                    value |= SaveData_GetNibble(row, idx) & 8;
                    SaveData_SetNibble(row, idx, value);
                }
            }
        }
        if (self->unk_50->unk_04 == pl->unk_0c || self->unk_50->unk_04 == self->id) {
            u32 n;
            func_ov003_021ce9c4(self->unk_b0->unk_04);
            n = data_0214a424->unk_0a + 1;
            if (n >= 0xffff) {
                n = 0xffff;
            }
            data_0214a424->unk_0a = n;
        }
    }
    if (release) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
    }
}
