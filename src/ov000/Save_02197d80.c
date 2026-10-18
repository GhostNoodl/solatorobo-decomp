#include "types.h"

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
    u8 unk_ad[0x1d];
    u8 unk_ca;
    u8 unk_cb;
} Player021ccd54;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} SaveData;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u16 kind;
    u8 unk_10[0x7];
    u8 index;
    u16 value;
    u8 unk_1a[0x92];
    u8 unk_ac;
    u8 unk_ad;
} Obj02197d80;

extern Player021ccd54 *data_ov000_021ccd54;
extern SaveData *data_0214a424;

s32 func_0206e7ec(u32 a, u32 b);
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627a0(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);

static inline void SaveData_SetNibble(s32 row, s32 idx, u32 value) {
    u32 *p = &data_0214a424->flags[row][idx / 8];
    s32 sh = (idx % 8) * 4;
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int SaveData_GetNibble(s32 row, s32 idx) {
    return (data_0214a424->flags[row][idx / 8] >> ((idx % 8) * 4)) & 0xf;
}

static inline void Obj_StoreValue(Obj02197d80 *self, u32 value) {
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

void func_ov000_02197d80(Obj02197d80 *self) {
    u8 idx = self->index;
    s32 row;

    if (idx == 0xff) {
        return;
    }
    row = func_0206e7ec(data_ov000_021ccd54->unk_ca, data_ov000_021ccd54->unk_cb);
    self->value = SaveData_GetNibble(row, idx) & 7;
}
