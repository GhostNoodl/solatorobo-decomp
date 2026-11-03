#include "ov006/Tasks.h"

typedef struct ov006_Price021da098 {
    u16 unk0;
    u16 unk2;
} ov006_Price021da098;

extern "C" {

extern const ov006_Price021da098 data_ov006_021eb7b4[];
extern const ov006_Price021da098 data_ov006_021eb7c4[];

static inline u8 ov006_SlotManager_GetItem(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->items[i];
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

void ov006_Task021ec040_SetupPrices(ov006_Task021ec040 *self) {
    u8 n = gOv006SlotManager->lap;
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
    if (gOv006Manager->unk1C) {
        self->unk38 = gOv006SlotManager->numActive * 100 + self->unk38;
    }
    for (i = 0; i < 3; i++) {
        u8 item = ov006_SlotManager_GetItem(gOv006SlotManager, i);
        const ov006_Price021da098 *p = ov006_GetItemPrice(item);
        if (p != NULL) {
            int cnt = 1;
            if (item < 8) {
                cnt = ov006_SlotManager_GetItemCount(gOv006SlotManager, i);
            }
            self->unk38 += p->unk2 * cnt;
        }
    }
}

}
