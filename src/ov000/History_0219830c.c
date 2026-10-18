#include "types.h"

#define HISTORY_LEN 7

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u64 mask;
    u8 history[HISTORY_LEN];
    u8 current;
} History;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8 unk_18[0x2];
    u16 unk_1a;
    u32 unk_1c;
    u16 unk_20;
    u16 unk_22;
} Obj021984c8;

void func_ov000_0219830c(void) {
}

void func_ov000_02198310(void) {
}

void func_ov000_02198314(void) {
}

void func_ov000_02198318(void) {
}

void func_ov000_0219831c(void) {
}

void func_ov000_02198320(void) {
}

void func_ov000_02198324(void) {
}

void func_ov000_02198328(History *self) {
    s32 i;
    self->unk_00 = 0;
    self->unk_02 = 0;
    self->mask = 0;
    for (i = 0; i < HISTORY_LEN; i++) {
        self->history[i] = 0;
    }
    self->current = 1;
}

static inline BOOL History_Push(History *self, u8 value, BOOL force) {
    s32 i;
    if (self->current == value && !force) {
        return FALSE;
    }
    for (i = HISTORY_LEN - 1; i > 0; i--) {
        self->history[i] = self->history[i - 1];
    }
    self->history[0] = self->current;
    self->unk_00 = 0;
    self->current = value;
    self->unk_02 = 0;
    return TRUE;
}

BOOL func_ov000_02198360(History *self, u8 value, BOOL force) {
    return History_Push(self, value, force);
}

BOOL func_ov000_021983b0(History *self, u8 value, s32 count, BOOL checkCurrent) {
    BOOL found = FALSE;
    s32 i;
    if (checkCurrent && self->current == value) {
        found = TRUE;
    } else {
        if (count > HISTORY_LEN) {
            count = HISTORY_LEN;
        }
        for (i = 0; i < count; i++) {
            if (value == self->history[i]) {
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

s32 func_ov000_0219840c(History *self, s32 *list, s32 count, BOOL push) {
    s32 result = 0;
    s32 i;
    if (self->mask != 0) {
        for (i = 0; i < count; i++) {
            s32 bit = list[i];
            if (self->mask & ((u64)1 << bit)) {
                if (push) {
                    History_Push(self, bit, FALSE);
                }
                result = bit;
                break;
            }
        }
    }
    return result;
}

void func_ov000_021984c8(Obj021984c8 *self) {
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_1a = 0;
    self->unk_1c = 0;
    self->unk_20 = 0xffff;
    self->unk_22 = 0;
}
