#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/Model.h"
#include "ov006/SlotManager.h"

extern "C" u8 *data_ov000_021ccd54;

typedef struct ov006_Unk021d5b98 {
    void *vtbl;
    u8 unk4[0x18];
    Object *unk1C;
    Object *unk20;
    ov006_Model *unk24;
    Object *unk28;
    Object *unk2C;
    Object *unk30;
    Object *unk34;
    u8 unk38[0x38];
    void *unk70[6];
} ov006_Unk021d5b98;

extern "C" {

extern u8 data_ov006_021ebfc0[];
extern void *data_02097cdc;
extern char *data_0208cc94;
extern char data_0214b105[];
extern char data_ov006_021ec864[];
void func_02036838(void *a, const void *b, int c, int d);
void func_0206e900(char *dst, const char *src);
void *func_ov000_0218ea20(void *p);
void func_ov006_021ccddc(void *self);

static inline void ov006_Unk021d5b98_dtor(ov006_Unk021d5b98 *self) {
    char buf[0x20];
    int i;
    self->vtbl = data_ov006_021ebfc0;
    OV006_DELETE_OBJECT(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
    OV006_DELETE_MODEL(self->unk24);
    OV006_DELETE_OBJECT(self->unk28);
    OV006_DELETE_OBJECT(self->unk2C);
    OV006_DELETE_OBJECT(self->unk30);
    OV006_DELETE_OBJECT(self->unk34);
    func_02036838(data_02097cdc, data_0214b105, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_0206e900(buf, "menu/skyrace");
    func_02036838(data_02097cdc, buf, 7, 0);
    func_02036838(data_02097cdc, data_ov006_021ec864, 7, 0);
    {
        // The name in a local makes the literal load come before the manager load.
        const char *s = "ef/effect3darc";
        func_02036838(data_02097cdc, s, 7, 0);
    }
    func_02036838(data_02097cdc, "ef/effect3dtri", 7, 0);
    i = 0;
    for (; i < 6; i++) {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk8;
        if (self->unk70[i] != NULL) {
            if (self->unk70[i] != NULL) {
                void *p = self->unk70[i];
                func_ov000_0218ea20(p);
                func_0203de1c(p);
            }
            self->unk70[i] = NULL;
        }
        data_02097dd0->current = saved;
    }
    func_ov006_021ccddc(self);
}

ov006_Unk021d5b98 *func_ov006_021d5b98(ov006_Unk021d5b98 *self) {
    ov006_Unk021d5b98_dtor(self);
    return self;
}

ov006_Unk021d5b98 *func_ov006_021d5e68(ov006_Unk021d5b98 *self) {
    ov006_Unk021d5b98_dtor(self);
    func_0203de1c(self);
    return self;
}

}


typedef struct ov006_Color021d6140 {
    u8 c[3];
} ov006_Color021d6140;

typedef struct ov006_Game021d6140 {
    u8 unk0[0xca];
    ov006_Color021d6140 cur;
    ov006_Color021d6140 next;
    ov006_Color021d6140 prev;
} ov006_Game021d6140;

typedef struct ov006_Info021d6140 {
    u8 unk0[0xa];
    u8 lo : 4;
    u8 hi : 4;
} ov006_Info021d6140;

typedef struct ov006_Unk02097e48 {
    u16 unk0_0 : 3;
    u16 active : 1;
    u16 unk0_4 : 12;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} ov006_Unk02097e48;

typedef struct ov006_Task021d6140 {
    void *vtbl;
    int type;
    int state;
    int subState;
    u8 unk10[0x60];
    void *unk70[6];
} ov006_Task021d6140;

extern "C" {

extern const u16 data_ov006_021eb7a8[];
extern ov006_Unk02097e48 *data_02097e48;

void *func_020359d0(const char *a, int b, int c);
void func_0206e900(char *dst, const char *src);
void *func_0203dd9c(u32 size);
void *func_ov000_0218e9c4(void *p);
void func_ov000_02193e5c(void *p, u16 id);
void func_0203cc58(s32 a, int b, int c);
void func_0203cd10(void);

static inline void ov006_Game_SetColor(u8 r, u8 g, u8 b) {
    // The aggregate initializer keeps c in memory; its stores are dead but still emitted.
    ov006_Color021d6140 c = {r, g, b};
    ov006_Game021d6140 *game = ((ov006_Game021d6140 *)data_ov000_021ccd54);
    game->next = c;
    game = ((ov006_Game021d6140 *)data_ov000_021ccd54);
    game->prev = game->cur;
    game->cur = game->next;
}

BOOL func_ov006_021d6140(ov006_Task021d6140 *self) {
    char buf[0x21];
    int i;
    func_020359d0(data_0214b105, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);
    func_0206e900(buf, "menu/skyrace");
    func_020359d0(buf, 7, 0);
    func_020359d0(data_ov006_021ec864, 7, 0);
    func_020359d0("ef/effect3darc", 7, 0);
    func_020359d0("ef/effect3dtri", 7, 0);
    for (i = 0; i < 6; i++) {
        void *p = func_0203dd9c(0x138);
        if (p != NULL) {
            p = func_ov000_0218e9c4(p);
        }
        self->unk70[i] = p;
        func_ov000_02193e5c(p, data_ov006_021eb7a8[i]);
    }
    {
        ov006_Info021d6140 *info = (ov006_Info021d6140 *)data_ov006_021ec884->unk8;
        ov006_Game_SetColor(0x12, info->lo, info->hi);
    }
    func_0203cc58(0x1000, 0, 0);
    func_0203cc58(0x1000, 0, 1);
    func_0203cd10();
    {
        ov006_Unk02097e48 *p = data_02097e48;
        if (p->active) {
            p->unk6 = 0x8000;
            p->unk8 = 0xf0;
            p->unk2 = 0;
        }
    }
    return TRUE;
}

}


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
        func_0206e900(buf, "menu/skyrace");
        if (!func_02035b90(buf, 7)) {
            break;
        }
        if (!func_02035b90(data_ov006_021ec864, 7)) {
            break;
        }
        if (!func_02035b90("ef/effect3darc", 7)) {
            break;
        }
        if (!func_02035b90("ef/effect3dtri", 7)) {
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
u16 func_02046ab4(ov006_Unk02097e40 *a);
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
            const char *name = "cefly1pic00";
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, data_ov006_021ec864);
        }
        self->unk24 = model;
        func_020417e0(self->unk24, func_02035de0(data_ov006_021ec864, "cefly1pic00"));
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
        func_ov006_021e1ddc(self->unk28, "menu/skyrace_map", info->unk4, zero);
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
        func_02039518(func_02035de0(data_ov006_021ec864, "cefly1pic00"));
        func_02039518(func_02035de0(data_ov006_021ec864, "cefly1cmn01"));
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
