#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003Rot;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Work;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x3c];
    void *unk_d4;
} Ov003Game54;

typedef struct {
    s16 handle;
    u8 unk_02[0x136];
} Ov003LiftRes;

typedef struct {
    u8 unk_00[0xbe];
    u8 alpha;
} Ov003LiftModel;

typedef struct {
    u8 unk_00[0x24];
    void *handle;
} Ov003LiftFx;

typedef struct {
    u8 unk_00[0x64];
    s32 radius;
    u8 unk_68[8];
    Ov003Vec pos;
} Ov003LiftPlayer;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xc];
    s16 mode;
    u8 unk_1c[8];
    u8 unk_24[0x14];
    Ov003LiftModel *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[4];
    void *obj;
    u8 unk_4c[0x10];
    void *unk_5c;
    u8 unk_60[0x10];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[0x3a];
    void *fx;
    Ov003Vec dir;
    u16 unk_cc_0 : 7;
    u16 active : 1;
    u8 unk_ce[2];
    Ov003LiftRes res;
    u8 anim[0x78];
    Ov003Vec animPos;
    u8 unk_28c[0x24];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    u16 unk_2bc;
    u8 unk_2be[8];
    u8 alpha;
    u8 unk_2c7[0x29];
    Ov003Vec savedPos;
    Ov003Rot savedRot;
    u16 timer;
} Ov003Lift;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

extern "C" {

extern Ov003HeapCtx *data_02097dd0;
extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_0214a420;
extern char data_ov003_021f998f[];
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(Ov003LiftRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(Ov003LiftRes *p);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_0218ffdc(void *anim, Ov003LiftRes *res, s32 a, s32 b);
extern void func_ov000_02190e98(void *anim, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *anim);
extern void func_0203f2b8(void *p);
extern void func_0203de1c(void *p);
extern void func_01ffc9fc(Ov003Vec *src, Ov003Vec *dst, u16 angle);
extern void func_02065804(void *mgr, void *handle);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern Ov003LiftPlayer *func_ov000_0219bf90(void);
extern BOOL func_01ffc198(Ov003Vec *a, Ov003Vec *b, s32 r);
extern Ov003LiftFx *func_02065f88(s32 id, const Ov003Vec *pos);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02190758(void *anim, void *p, s32 a);
extern BOOL func_ov000_021903b4(void *anim);
extern void func_ov000_021bd7a0(void *p);

void func_ov003_021ebc38(Ov003Lift *self) {
    func_ov000_0219433c(self);
    if (self->mode != 0) {
        func_ov000_0218f074(&self->res, data_ov003_021f998f, 1, 1, 0, 0);
        self->res.handle = 0;
    }
    self->savedPos.x = self->pos.x;
    self->savedPos.y = self->pos.y;
    self->savedPos.z = self->pos.z;
    self->savedRot.x = self->rot.x;
    self->savedRot.y = self->rot.y;
    self->savedRot.z = self->rot.z;
    func_ov000_02198360(self->work, 1, 0);
}

BOOL func_ov003_021ebccc(Ov003Lift *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->mode != 0 && self->res.handle >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    return r;
}

void func_ov003_021ebd0c(Ov003Lift *self) {
    func_ov000_02194758(self);
    if (self->mode != 0) {
        func_ov000_0218ffdc(self->anim, &self->res, 0, 1);
        self->unk_2bc = self->unk_0c;
        self->scaleX = 0x1c00;
        self->scaleY = 0x1c00;
        self->scaleZ = 0x1c00;
        func_ov000_02190e98(self->anim, 0, 0x1000, 0);
        func_ov000_021915a0(self->anim);
        self->dir.x = 0;
        self->dir.y = 0x1800;
        self->dir.z = 0x1800;
    } else {
        void *p;
        void *old = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->alt;
        p = self->obj;
        if (p != NULL) {
            if (p != NULL) {
                func_0203f2b8(p);
                func_0203de1c(p);
            }
            self->obj = NULL;
        }
        data_02097dd0->cur = old;
        self->dir.x = 0;
        self->dir.y = 0x1800;
        self->dir.z = 0x800;
    }
    func_01ffc9fc(&self->dir, &self->dir, self->rot.y);
    self->timer = 0;
}

void func_ov003_021ebe08(Ov003Lift *self) {
    if (self->active) {
        if (self->fx != NULL) {
            func_02065804(data_0214a420, self->fx);
            self->fx = NULL;
        }
        if (self->model != NULL) {
            func_ov000_02190a80(self->model, func_0203db40(self->unk_24));
        }
        return;
    }
    if (self->mode != 0) {
        func_ov000_02190a80(self->anim, (void *)0x1000);
    }
    if (!(self->timer & 0x7f)) {
        Ov003LiftPlayer *pl = func_ov000_0219bf90();
        if (pl != NULL && func_01ffc198(&pl->pos, &self->pos, pl->radius + 0xf000)) {
            Ov003LiftFx *fx = func_02065f88(0xcc, &self->pos);
            if (fx != NULL) {
                self->fx = fx->handle;
            }
        }
    }
    self->timer++;
}

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003Game54 *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54) ? TRUE : FALSE;
}

BOOL func_ov003_021ebee4(Ov003Lift *self) {
    BOOL r = TRUE;
    BOOL done = FALSE;
    if (self->active) {
        done = func_ov000_02194c08(self);
        if (self->mode != 0) {
            self->alpha = self->model->alpha;
        }
    }
    if (self->mode != 0) {
        self->animPos.x = self->savedPos.x;
        self->animPos.y = self->savedPos.y;
        self->animPos.z = self->savedPos.z;
        func_ov000_02190758(self->anim, &self->savedRot, 0);
        r = func_ov000_021903b4(self->anim);
    }
    if (!done && self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    return r;
}
}
