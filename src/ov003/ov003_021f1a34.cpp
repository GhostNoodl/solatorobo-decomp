#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003PdVec;

typedef struct {
    u8 unk_00[0x78];
    Ov003PdVec pos;
} Ov003PdModel;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    void *unk_d4;
} Ov003PdGame;

typedef struct {
    u32 flags;
    u8 unk_04[0x4c];
    Ov003PdVec pos;
} Ov003PdIcon;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003PdSub44;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x79];
    u16 unk_90;
} Ov003PdPlr;

typedef struct {
    u8 unk_00[0x11c];
    void *unk_11c;
} Ov003PdMsg;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x12];
    s16 unk_22;
    u8 unk_24[0x14];
    Ov003PdModel *model;
    u8 unk_3c[0x8];
    Ov003PdSub44 *unk_44;
    u8 unk_48[0x14];
    Ov003PdIcon *unk_5c;
    u8 unk_60[0x10];
    Ov003PdVec pos;
    u8 unk_7c[0x17];
    u8 unk_93_0 : 1;
    u8 unk_94[0x18];
    Ov003PdIcon *unk_ac;
} Ov003Pd;

class Ov003PdV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

extern "C" {

extern Ov003PdGame *data_ov000_021ccd54;
extern BOOL func_ov000_0218cea4(Ov003Pd *self);
extern void func_ov000_021bd7a0(void *p);

static inline BOOL Ov003Game_IsBusy(Ov003PdGame *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003PdGame *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003PdGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003PdGame *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54) ? TRUE : FALSE;
}

BOOL func_ov003_021f1a34(Ov003Pd *self) {
    BOOL r = FALSE;
    Ov003PdModel *m = self->model;
    if (m != NULL) {
        self->unk_93_0 = 1;
        m->pos.x = self->pos.x;
        m->pos.y = self->pos.y;
        m->pos.z = self->pos.z;
        r = func_ov000_0218cea4(self);
    }
    if (Ov003_GameIdle() && !Ov003_GameHasD4()) {
        if (self->unk_5c != NULL) {
            func_ov000_021bd7a0(self->unk_5c);
        }
        if (self->unk_ac != NULL) {
            func_ov000_021bd7a0(self->unk_ac);
        }
    }
    return r;
}

}
