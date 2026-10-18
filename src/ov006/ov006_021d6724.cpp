#include "ov006/Model.h"
#include "ov006/SlotManager.h"

typedef struct ov006_Info021d6724 {
    u8 unk0[4];
    int unk4;
    u8 unk8[4];
    s16 unkC;
    s16 unkE;
    s16 unk10;
} ov006_Info021d6724;

typedef struct ov006_Gauge021d6724 {
    u8 unk0[0x10];
    u8 cur;
    u8 max;
    u8 unk12[0xa];
    void *unk1C;
} ov006_Gauge021d6724;

typedef struct ov006_Pos021d6724 {
    u8 unk0[8];
    int x;
    int y;
    u8 unk10[0x40];
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
} ov006_Pos021d6724;

typedef struct ov006_Task021d6724 {
    void *vtbl;
    int type;
    int state;
    int subState;
    u8 unk10[0xc];
    ov006_Gauge021d6724 *unk1C;
    void *unk20;
    ov006_Model *unk24;
    ov006_Pos021d6724 *unk28;
    ov006_Pos021d6724 *unk2C;
    ov006_Pos021d6724 *unk30;
} ov006_Task021d6724;

typedef struct ov006_Msg021d6724 {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    int unk4;
    int unk8;
    int unkC;
} ov006_Msg021d6724;

typedef struct ov006_Bits0e {
    u8 b0 : 2;
    u8 b2 : 2;
    u8 rest : 4;
} ov006_Bits0e;

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

#define OV006_MIN(a, b) ((a) > (b) ? (b) : (a))

extern "C" {

extern char data_ov006_021ec00b[];
extern char data_ov006_021ec864[];
extern char data_ov006_021ec017[];
extern char data_ov006_021ec028[];
extern u8 *data_ov000_021ccd54;
extern ov006_Unk02097e40 *data_02097e40;

ov006_SlotManager *func_ov006_021dae90(void);
void func_ov006_021cd580(int a, void *b, int c);
ov006_Gauge021d6724 *func_ov006_021ddc70(void *p);
void func_ov006_021de008(ov006_Gauge021d6724 *p);
void func_ov000_0216da2c(void *p, int a, int b, int c);
ov006_Pos021d6724 *func_ov006_021e1484(void *p);
void func_ov006_021e16b0(ov006_Pos021d6724 *p);
const void *func_0206ec48(u16 id);
void func_ov006_021e1e6c(ov006_Pos021d6724 *a, const void *b);
void func_ov006_021e1ddc(ov006_Pos021d6724 *a, const char *b, int c, int d);
ov006_Pos021d6724 *func_ov006_021e2174(void *p);
void func_ov006_021e22e4(ov006_Pos021d6724 *p);
ov006_Pos021d6724 *func_ov006_021e264c(void *p);
void func_ov006_021e279c(ov006_Pos021d6724 *p);
BOOL func_0203e688(void);
void func_02039518(void *p);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
int func_02046ab4(ov006_Unk02097e40 *a);
u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e4b90(ov006_Unk021ec888 *self);

static inline void ov006_Gauge_Init(ov006_Gauge021d6724 *g, int a, int b, int c) {
    if (g->unk1C != NULL) {
        func_ov000_0216da2c(g->unk1C, a, b, c);
    }
}

static inline void ov006_Pos_SetXY(ov006_Pos021d6724 *p, int x, int y) {
    p->x = x;
    p->y = y;
}

static inline void ov006_Pos_Set3(ov006_Pos021d6724 *p, int x, int y, int z) {
    p->unk54 = x;
    p->unk58 = y;
    p->unk5C = z;
}

static inline void ov006_Gauge_Set(u8 n, ov006_Gauge021d6724 *g) { g->cur = OV006_MIN((u8)(n ? 1 : 0), n); g->max = n; }
BOOL func_ov006_021d6724(ov006_Task021d6724 *self) {
    int zero = 0;
    BOOL result = zero;
    switch (self->subState) {
    case 0: {
        ov006_Info021d6724 *info;
        ov006_Gauge021d6724 *g;
        ov006_Model *model;
        ov006_Pos021d6724 *p;
        u8 n;
        func_ov006_021cd580(7, func_ov006_021dae90(), result);
        g = (ov006_Gauge021d6724 *)func_0203dd9c(0x38);
        if (g != NULL) {
            g = func_ov006_021ddc70(g);
        }
        self->unk1C = g;
        func_ov006_021de008(g);
        ov006_Gauge_Init(self->unk1C, data_ov006_021ec884->unk13C ? 2 : 1, data_ov006_021ec884->unk140, data_ov006_021ec884->unk144);
        ov006_Gauge_Set(data_ov006_021ec884->unk8->unkB, self->unk1C);
        model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
        if (model != NULL) {
            const char *name = data_ov006_021ec00b;
            if (name) {
                func_02041218(model->unk88);
                func_02041440(model, name, 0);
                STD_CopyString(model->unk2C, data_ov006_021ec864);
            }
        }
        self->unk24 = model;
        func_020417e0(self->unk24, func_02035de0(data_ov006_021ec864, data_ov006_021ec00b));
        self->unk24->unk6C |= 2;
        self->unk24->unk6C |= 0x400000;
        func_02041d9c(self->unk24, 2, 0xffff);
        info = (ov006_Info021d6724 *)data_ov006_021ec884->unk8;
        p = (ov006_Pos021d6724 *)func_0203dd9c(0x30);
        if (p != NULL) {
            p = func_ov006_021e1484(p);
        }
        self->unk28 = p;
        func_ov006_021e16b0(p);
        func_ov006_021e1e6c(self->unk28, func_0206ec48(data_ov006_021ec884->unk6));
        func_ov006_021e1ddc(self->unk28, data_ov006_021ec017, info->unk4, zero);
        ov006_Pos_SetXY(self->unk28, -0x2c, 0xc);
        p = (ov006_Pos021d6724 *)func_0203dd9c(0xa4);
        if (p != NULL) {
            p = func_ov006_021e2174(p);
        }
        self->unk2C = p;
        func_ov006_021e22e4(p);
        ov006_Pos_SetXY(self->unk2C, 0x24, -0x2c);
        p = (ov006_Pos021d6724 *)func_0203dd9c(0x64);
        if (p != NULL) {
            p = func_ov006_021e264c(p);
        }
        self->unk30 = p;
        func_ov006_021e279c(p);
        ov006_Pos_SetXY(self->unk30, -0x2d, 9);
        self->unk30->unk50 = (info->unkC << 12) / 100;
        ov006_Pos_Set3(self->unk30, info->unkE << 12, zero, info->unk10 << 12);
        ((ov006_Bits0e *)(data_ov000_021ccd54 + 0xe))->b2 = 0;
        data_02097dd0->unk1C = 2;
        data_ov006_021ec888->unk15E = 1;
        self->subState++;
        break;
    }
    case 1:
        if (!func_0203e688()) {
            break;
        }
        func_02039518(func_02035de0(data_ov006_021ec864, data_ov006_021ec00b));
        func_02039518(func_02035de0(data_ov006_021ec864, data_ov006_021ec028));
        self->subState = 10;
        break;
    case 10:
        if (data_ov006_021ec860->unk1C != 0 && data_ov006_021ec888->unk8 != 9) {
            ov006_Msg021d6724 msg;
            msg.unk0 = 0;
            msg.unk2 = 0;
            msg.unk3 = 0;
            msg.unk4 = 0;
            msg.unk8 = 0;
            msg.unkC = 0;
            func_ov006_021e4a80(data_ov006_021ec888, 7, 3, &msg, 0x10);
            if (func_02046ab4(data_02097e40) == 0) {
                self->subState = 20;
            } else {
                self->subState = 30;
            }
        } else {
            self->subState = 40;
        }
        break;
    case 20: {
        u16 mask;
        if (data_ov006_021ec888->unk8 == 9) {
            self->subState = 40;
            break;
        }
        mask = data_02097e40->unk32;
        if (mask == func_ov006_021e60e8(7, mask)) {
            ov006_Msg021d6724 msg;
            msg.unk0 = 0;
            msg.unk2 = 0;
            msg.unk3 = 0;
            msg.unk4 = 0;
            msg.unk8 = 0;
            msg.unkC = 0;
            func_ov006_021e4a80(data_ov006_021ec888, 8, 3, &msg, 0x10);
            self->subState++;
        }
        break;
    }
    case 21:
        self->subState = 40;
        break;
    case 30: {
        u16 mask;
        if (data_ov006_021ec888->unk8 == 9) {
            self->subState = 40;
            break;
        }
        mask = data_02097e40->unk32;
        if (mask != func_ov006_021e60e8(8, mask)) {
            break;
        }
        self->subState = 40;
    }
    case 40:
        func_ov006_021e4b90(data_ov006_021ec888);
        self->subState = -1;
        result = TRUE;
        break;
    }
    return result;
}

}
