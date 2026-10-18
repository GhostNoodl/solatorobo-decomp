#include "ov006/SlotManager.h"

typedef struct ov006_Pos {
    s32 x;
    s32 y;
    s32 z;
} ov006_Pos;

typedef struct ov006_Rot {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot;

typedef struct ov006_PartyEntry {
    ov006_Pos pos;
    u16 rot;
    u16 pad;
} ov006_PartyEntry;

typedef struct ov006_Party {
    u8 unk0[0x15];
    u8 count;
} ov006_Party;

typedef struct ov006_Unk021ccd6c {
    u8 unk0[0x14];
    ov006_Party *party;
} ov006_Unk021ccd6c;

typedef struct ov006_Bits0c {
    u8 b0 : 1;
    u8 rest : 7;
} ov006_Bits0c;

typedef struct ov006_BitsDA {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 3;
    u8 b7 : 1;
} ov006_BitsDA;

typedef struct ov006_Unk0214a420 {
    u8 unk0[8];
    int unk8;
} ov006_Unk0214a420;

typedef struct ov006_Prop {
    u8 unk0[0xc];
    u16 unkC;
} ov006_Prop;

typedef struct ov006_Info021d630c {
    u8 unk0[8];
    u16 unk8;
} ov006_Info021d630c;

typedef struct ov006_Task021d630c {
    void *vtbl;
    int type;
    int state;
    int subState;
    u8 unk10[0x60];
    s16 *unk70[6];
} ov006_Task021d630c;

extern "C" {

extern ov006_Unk0214a420 *data_0214a420;
extern u8 *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern ov006_Unk021ccd6c *data_ov000_021ccd6c;
extern u8 *data_ov000_021ccd54;
extern char data_0214b105[];
extern char *data_0208cc94;
extern char data_ov006_021ebfe0[];
extern char data_ov006_021ec864[];
extern char data_ov006_021ebfed[];
extern char data_ov006_021ebffc[];
extern void *data_02097e4c;

void func_020656b4(void *p);
void func_ov000_0218be9c(void *p);
void func_ov000_0218e894(void *p);
void func_ov000_021b53f4(void *p);
BOOL func_02035b90(const char *name, int a);
void func_0206e900(char *dst, const char *src);
BOOL func_ov000_0218f110(void *p);
void func_02065ac0(void *p);
BOOL func_ov000_021b5578(void *p);
void func_ov000_021b5dc0(void *p);
int func_0206e264(ov006_Party *party);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
ov006_Prop *func_ov006_021ea430(u32 id, u8 a, const ov006_Pos *pos, const ov006_Rot *rot);
void func_ov000_0218c208(void *a, const ov006_Pos *pos, u16 rot);
void func_ov000_0218be54(void *p);
BOOL func_ov000_0218e470(void *p);
void func_0204a2f0(void *a, u16 b);
BOOL func_0204985c(void *a);

static inline int ov006_GetPartyValue(ov006_Unk021ccd6c *self) {
    if (self->party == NULL || self->party->count == 0) {
        return 0;
    }
    return func_0206e264(self->party);
}

BOOL func_ov006_021d630c(ov006_Task021d630c *self) {
    BOOL result;
    int i;
    int zero;
    i = 0;
    result = i;
    zero = i;
    switch (self->subState) {
    case 0:
        func_020656b4(data_0214a420);
        ((ov006_Bits0c *)(data_ov000_021ccd64 + 0xc))->b0 = 1;
        func_ov000_0218be9c(data_ov000_021ccd64);
        func_ov000_0218e894(data_ov000_021ccd68);
        func_ov000_021b53f4(data_ov000_021ccd6c);
        self->subState++;
        break;
    case 1: {
        char buf[0x20];
        if (!func_02035b90(data_0214b105, 7)) {
            break;
        }
        if (!func_02035b90(data_0208cc94, 7)) {
            break;
        }
        func_0206e900(buf, data_ov006_021ebfe0);
        if (!func_02035b90(buf, 7)) {
            break;
        }
        if (!func_02035b90(data_ov006_021ec864, 7)) {
            break;
        }
        if (!func_02035b90(data_ov006_021ebfed, 7)) {
            break;
        }
        if (!func_02035b90(data_ov006_021ebffc, 7)) {
            break;
        }
        self->subState++;
        break;
    }
    case 2:
        result = TRUE;
        for (; i < 6; i++) {
            if (*self->unk70[i] >= 0 && !func_ov000_0218f110(self->unk70[i])) {
                result = zero;
            }
        }
        if (!result) {
            break;
        }
        result = FALSE;
        self->subState++;
        break;
    case 3:
        self->subState++;
        break;
    case 4:
        if (data_0214a420->unk8 >= 3) {
            self->subState++;
            break;
        }
        func_02065ac0(data_0214a420);
        break;
    case 5: {
        ov006_PartyEntry *tbl;
        u8 j;
        u8 n;
        if (!func_ov000_021b5578(data_ov000_021ccd6c)) {
            break;
        }
        func_ov000_021b5dc0(data_ov000_021ccd6c);
        tbl = (ov006_PartyEntry *)ov006_GetPartyValue(data_ov000_021ccd6c);
        n = data_ov006_021ec884->numActive;
        for (j = 0; j < n; j++) {
            ov006_Pos pos;
            ov006_Rot rot;
            ov006_Slot *slot;
            if (tbl != NULL) {
                pos.x = tbl[j].pos.x;
                pos.y = tbl[j].pos.y;
                pos.z = tbl[j].pos.z;
                rot.y = tbl[j].rot;
                rot.x = zero;
                rot.z = zero;
            } else {
                pos.x = zero;
                pos.y = zero;
                pos.z = zero;
                rot.x = zero;
                rot.y = zero;
                rot.z = zero;
            }
            slot = func_ov006_021db060(data_ov006_021ec884, j);
            if (slot->active) {
                ov006_Prop *prop = func_ov006_021ea430(slot->unkC, j, &pos, &rot);
                if (prop != NULL) {
                    slot->unkE = prop->unkC;
                    func_ov000_0218c208(data_ov000_021ccd64, &pos, rot.y);
                }
            }
            if (j == data_ov006_021ec884->unk5) {
                u8 *o = data_ov000_021ccd54 + 0xf4;
                o[0xd8] |= 2;
                *(ov006_Pos *)(o + 0xe8) = pos;
                o[0xda] |= 2;
                *(ov006_Rot *)(o + 0xf8) = rot;
                *(int *)(o + 0xf4) = 0xa000;
                o[0xda] = ((o[0xda] | 0x70) & ~0xc) | 4;
                ((ov006_Bits0c *)(o + 0x9c))->b0 = 0;
                VCALL(o, 00);
                ((ov006_Bits0c *)(o + 0x9c))->b0 = 1;
            }
        }
        if (data_ov000_021ccd64 != NULL) {
            func_ov000_0218be54(data_ov000_021ccd64);
        }
        self->subState++;
        break;
    }
    case 6:
        if (!func_ov000_0218e470(data_ov000_021ccd68)) {
            break;
        }
        func_0204a2f0(data_02097e4c, ((ov006_Info021d630c *)data_ov006_021ec884->unk8)->unk8);
        self->subState++;
        break;
    case 7:
        if (func_0204985c(data_02097e4c)) {
            self->subState = i - 1;
            result = TRUE;
        }
        break;
    }
    return result;
}

}
