#include "types.h"

typedef struct {
    u8 unk_00[0x8b0];
    u8 unk_8b0[3];
    u8 unk_8b3;
} Ov003Save;

typedef struct {
    u8 unk_00[0xc1];
    u8 unk_c1;
} Ov003Model;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Prop44;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    Ov003Model *unk_38;
    u8 unk_3c[0x4];
    Ov003PropWk *unk_40;
    Ov003Prop44 *unk_44;
} Ov003Prop;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003G54;

extern Ov003Save *data_02097d48;
extern int func_02043d9c(void *p);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02191008(void *p);

void func_ov003_021e0b20(Ov003Prop *self) {
    Ov003Save *s = data_02097d48;
    u8 v = s->unk_8b3;
    func_02043d9c(s->unk_8b0);
    self->unk_38->unk_c1 = v;
    func_ov000_02194c08(self);
}

void func_ov003_021e0b54(Ov003Prop *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0x20, 0);
    func_ov000_02191008(self->unk_38);
}

extern Ov003G54 *data_ov000_021ccd54;
extern char data_ov003_021f8531[];
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void func_ov003_021e0b7c(Ov003Prop *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov003Prop44 *p;
        func_ov000_02190cb0(self->unk_38, data_ov003_021f8531, 0x1000, 0);
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        }
        self->unk_40->state++;
    }
    case 1: {
        Ov003Prop44 *p;
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}
