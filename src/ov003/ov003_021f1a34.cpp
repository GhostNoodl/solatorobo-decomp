#include "types.h"
#include "Main/Sys/FieldState.h"


typedef struct {
    u8 unk_00[0x78];
    VecFx32 pos;
} Ov003PdModel;

typedef struct {
    u32 flags;
    u8 unk_04[0x4c];
    VecFx32 pos;
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
    VecFx32 pos;
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

extern BOOL func_ov000_0218cea4(Ov003Pd *self);
extern void func_ov000_021bd7a0(void *p);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasEvent(FieldState *g) {
    return g->event != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasEvent(data_ov000_021ccd54) ? TRUE : FALSE;
}

BOOL Ov003ActVt_021fa1b8_Draw(Ov003Pd *self) {
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

extern Ov003PdMsg *data_ov000_021ccd30;
extern void *data_ov000_021ccd64;
extern void *func_ov000_0216f674(Ov003PdMsg *mgr, s32 id);
extern BOOL func_ov000_021700c4(void *p);
extern void *Task_FindById(s32 id);
extern Ov003PdPlr *func_ov000_0219bf90(void);
extern void func_ov000_021bd624(Ov003PdIcon *p);
extern BOOL func_ov000_021bd314(Ov003PdIcon *p, s32 id);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *actor);

static inline void Ov003Icon_SetPos(Ov003PdIcon *ic, VecFx32 *v) {
    ic->pos.x = v->x;
    ic->pos.y = v->y;
    ic->pos.z = v->z;
}

static inline BOOL Ov003_MsgBusy(void) {
    Ov003PdMsg *m = data_ov000_021ccd30;
    if (m == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(m, 6) != NULL) {
        return TRUE;
    }
    if (m->unk_11c == NULL) {
        return FALSE;
    }
    return func_ov000_021700c4(m->unk_11c);
}

void func_ov003_021f1b1c(Ov003Pd *self) {
    BOOL show = TRUE;
    if (self->unk_5c != NULL) {
        Ov003PdSub44 *s;
        self->unk_5c->flags &= ~2;
        s = self->unk_44;
        if (s != NULL && s->unk_22_0 == 1 && s->unk_22_1 == 1 && !Ov003_MsgBusy() && Task_FindById(7) == NULL) {
            Ov003PdPlr *p = func_ov000_0219bf90();
            if (p != NULL && p->unk_90 == self->unk_0c) {
                show = FALSE;
                self->unk_5c->flags |= 2;
                Ov003Icon_SetPos(self->unk_5c, &self->pos);
            }
        }
        func_ov000_021bd624(self->unk_5c);
    }
    if (self->unk_ac != NULL) {
        s16 id = self->unk_22;
        self->unk_ac->flags &= ~2;
        if (show && id != -1) {
            Ov003PdPlr *p = func_ov000_0219bf90();
            if (p != NULL && p->unk_16_2 && self->unk_0e != 0x2105) {
                func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
                ((Ov003PdV *)self)->Destroy();
                return;
            }
            func_ov000_021bd314(self->unk_ac, id);
            self->unk_ac->flags |= 2;
            Ov003Icon_SetPos(self->unk_ac, &self->pos);
        }
        func_ov000_021bd624(self->unk_ac);
    }
}

}
