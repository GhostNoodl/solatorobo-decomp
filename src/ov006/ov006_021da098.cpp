#include "ov006/SlotManager.h"

typedef struct ov006_Price021da098 {
    u16 unk0;
    u16 unk2;
} ov006_Price021da098;

typedef struct ov006_Task021da098 {
    u8 unk0[0x38];
    int unk38;
} ov006_Task021da098;

extern "C" {

extern const ov006_Price021da098 data_ov006_021eb7b4[];
extern const ov006_Price021da098 data_ov006_021eb7c4[];

static inline u8 ov006_SlotManager_GetItem(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14A[i];
    }
    return 0;
}

static inline u8 ov006_SlotManager_GetItemCount(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14D[i];
    }
    return 0;
}

static inline const ov006_Price021da098 *ov006_GetItemPrice(u8 item) {
    const ov006_Price021da098 *p = NULL;
    if (item != 0 && item < 11) {
        p = &data_ov006_021eb7c4[item];
    }
    return p;
}

void func_ov006_021da098(ov006_Task021da098 *self) {
    u8 n = data_ov006_021ec884->unk13E;
    u8 i;
    if (n < 1) {
        n = 1;
    } else if (n > 4) {
        n = 4;
    }
    {
        const ov006_Price021da098 *base = &data_ov006_021eb7b4[(u8)(n - 1)];
        self->unk38 = base->unk2;
    }
    if (data_ov006_021ec860->unk1C) {
        self->unk38 = data_ov006_021ec884->numActive * 100 + self->unk38;
    }
    for (i = 0; i < 3; i++) {
        u8 item = ov006_SlotManager_GetItem(data_ov006_021ec884, i);
        const ov006_Price021da098 *p = ov006_GetItemPrice(item);
        if (p != NULL) {
            int cnt = 1;
            if (item < 8) {
                cnt = ov006_SlotManager_GetItemCount(data_ov006_021ec884, i);
            }
            self->unk38 += p->unk2 * cnt;
        }
    }
}

}
