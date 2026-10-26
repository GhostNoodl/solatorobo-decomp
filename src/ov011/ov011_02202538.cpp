#include "ov011/ov011.h"

struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u16 id;
    s32 mode;
    Ov011Vec off;
    void *anim;
    void *model;
    Ov011V *unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

extern "C" {

extern Ov011Vec data_ov011_02207474;
extern const Ov011Vec data_ov011_02207480;
extern const Ov011Vec data_ov011_0220742c;
extern u8 data_ov011_0220748c[];
extern void *data_0214a420;
s32 FX_Div(s32 a, s32 b);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
BOOL func_02065748(void *mgr, void *p);
void MI_Copy36B(const void *src, void *dst);

static inline s32 Ov011_Progress(Ov011Chr *c, s32 n) {
    return FX_Div(n << 12, FLD(const s16, c, 6) << 12);
}

void func_ov011_02202538(Ov011Chr *self) {
    switch (self->mode) {
    case 1: {
        Ov011Vec s;
        Ov011Vec pos;
        Ov011Vec c;
        Ov011Vec t;
        s32 r = Ov011_Progress(self, self->unk_06);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        FLD(Ov011Vec, self->model, 0xa8) = s;
        FLD(Ov011Flags, self->model, 0xc2).b0 = 1;
        pos = FLD(Ov011Vec, self->model, 0x78);
        OV011_BLKCPY(&c, &data_ov011_02207480);
        self->unk_24 = func_02065f88(0x38a, &pos);
        self->unk_24->v10(&c);
        self->unk_24->v24(0, -0x14cd, 0);
        self->mode = 2;
        break;
    }
    case 2:
        if (!func_02065748(data_0214a420, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}


static inline BOOL Ov011Model2_Idle(Ov011Model2 *m) {
    BOOL r = FALSE;
    if (m->b0) {
        if (!m->b2) {
            r = TRUE;
        }
    }
    return r;
}

void func_ov011_022026b4(Ov011Chr *self) {
    switch (self->mode) {
    case 3: {
        Ov011Vec s;
        Ov011Vec pos;
        Ov011Vec t;
        s16 a;
        s16 b;
        s32 r = FX_Div(self->unk_08 << 12, FLD(const s16, self, 6) << 12);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        FLD(Ov011Vec, self->model, 0xa8) = s;
        FLD(Ov011Flags, self->model, 0xc2).b0 = 1;
        pos = FLD(Ov011Vec, self->model, 0x78);
        self->unk_24 = func_02065f88(0x648, &pos);
        self->unk_24->v14(0x2000, 0x2000, 0x2000);
        b = s.x + 0x1500;
        a = s.x;
        if (self->m28.b0) {
            self->m28.b1 = 1;
            self->m28.b2 = 0;
            MI_Copy36B(data_ov011_0220748c, (u8 *)self->m28.model + 0x84);
            FLD(Ov011Vec, self->m28.model, 0x78) = pos;
            self->m28.unk_02 = a;
            self->m28.unk_04 = b;
        }
        self->mode = 4;
        break;
    }
    case 4: {
        BOOL done = func_02065748(data_0214a420, self->unk_24) ? FALSE : TRUE;
        if (done) {
            done = Ov011Model2_Idle(&self->m28);
        }
        if (done) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
    }
}

void func_ov011_022028a8(Ov011Chr *self) {
    switch (self->mode) {
    case 5: {
        Ov011Vec s;
        Ov011Vec c;
        Ov011Vec pos;
        Ov011Vec t;
        s32 r;
        s32 lo;
        s32 hi;
        s32 v;
        if (self->unk_08 <= 1) {
            FLD(Ov011Flags, self->model, 0xc2).b0 = 0;
            self->mode = 0;
            return;
        }
        FLD(Ov011Flags, self->model, 0xc2).b0 = 1;
        r = FX_Div((s16)(self->unk_08 - 1) << 12, self->unk_06 << 12);
        lo = self->unk_04;
        hi = self->unk_02;
        v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        FLD(Ov011Vec, self->model, 0xa8) = s;
        OV011_BLKCPY(&c, &data_ov011_0220742c);
        pos = FLD(Ov011Vec, self->model, 0x78);
        self->unk_24 = func_02065f88(0x579, &pos);
        self->unk_24->v10(&c);
        self->mode = 6;
        break;
    }
    case 6:
        if (!func_02065748(data_0214a420, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}

}
