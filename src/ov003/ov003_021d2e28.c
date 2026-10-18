#include "types.h"

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u64 mask;
    u8 history[7];
    u8 current;
} Ov003Hist;

typedef struct {
    u8 unk_00[0x40];
    Ov003Hist *hist;
} Ov003HistObj;

extern s32 data_ov003_021f43f0[];
extern s32 data_ov003_021f437c[];
extern s32 data_ov003_021f440c[];
extern s32 func_ov000_0219840c(Ov003Hist *self, s32 *list, s32 count, BOOL push);
extern BOOL func_ov000_02198360(Ov003Hist *self, u8 value, BOOL force);
extern void func_ov000_0218d7e8(void *self, u8 state);

void func_ov003_021d2e28(Ov003HistObj *self) {
    Ov003Hist *h = self->hist;
    if (h->mask != 0 && func_ov000_0219840c(h, data_ov003_021f43f0, 7, TRUE) == 0) {
        h = self->hist;
        if (h->current != 0x15) {
            if (h->mask & 0x100000) {
                func_ov000_02198360(h, 0x14, TRUE);
            } else if (h->mask & 0x2) {
                func_ov000_02198360(h, 1, TRUE);
            } else if (h->mask & 0x80000) {
                func_ov000_02198360(h, 0x13, TRUE);
            } else if (h->mask & 0x40000) {
                func_ov000_02198360(h, 0x12, TRUE);
            }
        }
    }
    h = self->hist;
    switch (h->current) {
    case 9:
        func_ov000_0219840c(h, data_ov003_021f437c, 3, TRUE);
        break;
    case 4:
    case 11:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        if (h->mask & 0x200) {
            func_ov000_02198360(h, 9, FALSE);
        }
        break;
    case 0:
        func_ov000_0219840c(h, data_ov003_021f440c, 7, TRUE);
        break;
    case 1:
    case 2:
        if (func_ov000_0219840c(h, data_ov003_021f440c, 7, TRUE) == 0) {
            h = self->hist;
            if (h->mask & 0x4) {
                func_ov000_02198360(h, 2, FALSE);
            } else {
                func_ov000_02198360(h, 1, FALSE);
            }
        }
        break;
    }
    func_ov000_0218d7e8(self, self->hist->current);
}
