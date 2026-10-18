#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003SnNames {
    const char *names[4];
};

struct Ov003Sensor {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x1e];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x20];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec pos;
    u8 unk_7c[0x20];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    u16 wait;
};

extern "C" {

extern Ov003Game54 *data_ov000_021ccd54;
extern const Ov003SnNames data_ov003_021f6a80;
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern s32 func_ov000_0219a510(void *self, s32 a, Ov003Vec *pos, s32 b, s32 c, void **list);
extern BOOL func_ov000_021985c0(void *p);

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
    return true;
}

void func_ov003_021e7780(Ov003Sensor *self) {
    func_ov000_02194758(self);
    self->wait = self->kind;
    if (self->kind == 0) {
        self->wait = 0x64;
    }
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e77b4(Ov003Sensor *self) {
    void *list[0x20];
    s32 n;
    s32 i;
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[2], 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    case 1:
        if (!Ov003_GameIdle()) {
            return;
        }
        n = func_ov000_0219a510(self, 2, &self->pos, self->unk_64, self->unk_68, list);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (list[i] != NULL && func_ov000_021985c0(list[i])) {
                func_ov000_02198360(self->work, 6, 0);
                return;
            }
        }
        break;
    }
}
}
