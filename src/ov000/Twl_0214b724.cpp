#include "ov000/HeapScope.h"

typedef struct {
    u16 unk_00;
    s32 state;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Twl0214b570;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0c;
    u32 unk_10;
    void *unk_14;
    u32 unk_18;
    char *unk_1c;
    Twl0214b570 unk_20;
} TwlLoader;

typedef struct {
    void *unk_00;
} Data02034f5c;

extern "C" {

BOOL OS_IsRunOnTwl(void);
BOOL func_0203e63c(void *a);
void *func_02035f30(void *a, char *name, s32 b);
Data02034f5c *func_02034f5c(void *a, char *name);
void func_0203f0b4(void *p);
void func_02035acc(void *a, char *name, s32 b);
void func_0203de50(void *p);
void func_ov000_0214b910(TwlLoader *self);

extern void *data_ov000_021c9838;

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
void func_0222e784(TwlLoader *self);
void func_0222e7ec(TwlLoader *self);
void func_0222e6d0(Twl0214b570 *self);
void func_0222e2a4(Twl0214b570 *self);

static inline Twl0214b570 *Twl0214b570_dtor(Twl0214b570 *self) {
    if (OS_IsRunOnTwl()) {
        func_0222e6d0(self);
    }
    return self;
}

static inline void Twl0214b570_update(Twl0214b570 *self) {
    if (!OS_IsRunOnTwl()) {
        return;
    }
    if (self->state != 1) {
        return;
    }
    func_0222e2a4(self);
}

#pragma force_active on

TwlLoader *func_ov000_0214b724(TwlLoader *self) {
    if (self->unk_08 != 0) {
        switch (self->unk_04) {
        case 0:
            func_0222e784(self);
            break;
        case 1:
            if (self->unk_14 != NULL && func_0203e63c(self->unk_14)) {
                void *a = data_ov000_021c9838;
                void *d = func_02035f30(a, self->unk_1c, 5);
                func_0203f0b4(func_02034f5c(d, self->unk_1c)->unk_00);
                func_02035acc(a, self->unk_1c, 5);
            }
            break;
        }
        self->unk_08 = 0;
    }
    {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (self->unk_1c != NULL) {
            func_0203de50(self->unk_1c);
            self->unk_1c = NULL;
        }
        data_02097dd0->current = saved;
    }
    Twl0214b570_dtor(&self->unk_20);
    return self;
}

void func_ov000_0214b810(TwlLoader *self) {
    if (self->unk_08 == 1) {
        switch (self->unk_04) {
        case 0:
            func_0222e7ec(self);
            if (self->unk_02) {
                self->unk_08 = 1;
                self->unk_0c = 0;
                self->unk_04 = 1;
            }
            break;
        case 1:
            func_ov000_0214b910(self);
            break;
        }
    }
    Twl0214b570_update(&self->unk_20);
}

#pragma force_active reset

}
