#include "ov006/SlotManager.h"

typedef struct ov006_Party {
    u8 unk0[0x15];
    u8 count;
} ov006_Party;

typedef struct ov006_Unk021ccd6c {
    u8 unk0[0x14];
    ov006_Party *party;
} ov006_Unk021ccd6c;

typedef struct ov006_PriceEntry {
    u16 unk0;
    u16 unk2;
} ov006_PriceEntry;

extern "C" {

extern void *data_ov000_021ccd68;
extern ov006_Unk021ccd6c *data_ov000_021ccd6c;
extern ov006_PriceEntry data_ov006_021eb7c4[];

ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void *func_ov000_0218e640(void *a, u16 id);
BOOL func_ov006_021ea3e8(void *prop);
int func_0206e264(ov006_Party *party);

u8 func_ov006_021d8cb8(void) {
    u8 count;
    u8 i;
    u8 num;
    num = data_ov006_021ec884->numActive;
    if (num <= 1) {
        return 0x63;
    }
    count = 0;
    for (i = 0; i < num; i++) {
        u16 id = func_ov006_021db060(data_ov006_021ec884, i)->unkE;
        void *prop = data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
        if (prop != NULL && func_ov006_021ea3e8(prop)) {
            count++;
        }
    }
    return num - count;
}

static inline u32 ov006_GetPartyCount(ov006_Unk021ccd6c *self) {
    return self->party != NULL ? self->party->count : 0;
}

static inline int ov006_GetPartyValue(ov006_Unk021ccd6c *self) {
    if (self->party == NULL || self->party->count == 0) {
        return 0;
    }
    return func_0206e264(self->party);
}

int func_ov006_021d8d4c(void) {
    int result = 0;
    if (ov006_GetPartyCount(data_ov000_021ccd6c) > 5) {
        result = ov006_GetPartyValue(data_ov000_021ccd6c) + 0x50;
    }
    return result;
}

u8 func_ov006_021d8d9c(void) {
    u8 result = 0;
    if (ov006_GetPartyCount(data_ov000_021ccd6c) > 5) {
        result = ov006_GetPartyCount(data_ov000_021ccd6c) - 5;
    }
    return result;
}

int func_ov006_021d8de0(void) {
    int result = 0;
    if (ov006_GetPartyCount(data_ov000_021ccd6c) > 4) {
        result = ov006_GetPartyValue(data_ov000_021ccd6c) + 0x40;
    }
    return result;
}

u8 func_ov006_021d8e30(const u16 *digits) {
    u8 count = 0;
    BOOL started = FALSE;
    int v;
    u32 w;
    v = digits[1];
    if (v != 0) {
        started = TRUE;
        if (v / 10 == v % 10) {
            count++;
        }
    }
    v = digits[2];
    if (v != 0 || started) {
        started = TRUE;
        if (v / 10 == v % 10) {
            count++;
        }
    }
    w = digits[3] / 10;
    if (w != 0 || started) {
        if (w / 10 == w % 10) {
            count++;
        }
    }
    return count;
}

ov006_PriceEntry *func_ov006_021d8f20(u32 id) {
    ov006_PriceEntry *entry = NULL;
    if (id != 0 && id < 11) {
        entry = &data_ov006_021eb7c4[id];
    }
    return entry;
}

}
