#include "ov000/LoCommon.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021a5d00;

typedef struct {
    u32 b0 : 5;
    u32 f5 : 2;
    u32 f7 : 2;
    u32 f9 : 1;
    u32 rest : 22;
} B24_021a5d00;

typedef struct {
    s32 x, y, z;
} Vec_021a5d00;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
} B18_021a5d00;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} B19_021a5d00;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} B22_021a5d00;

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd6c;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern char data_ov000_021cc67e[];
extern char data_ov000_021cc61e[];
extern char data_ov000_021cc660[];
extern char data_ov000_021cc684[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
u16 FX_Atan2(s32 y, s32 x);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_01ffc584(void *a, void *b, s32 c, s32 d);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_0218dbe0(void *self, s32 turn);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_02191120(void *a);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_ov000_02182590(void *p);
BOOL func_0205b1fc(void);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void func_ov000_02199b88(u8 *info, u8 *self);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_02198360(St_021a5d00 *st, s32 state, s32 x);

static inline u8 *FindActor021a5d00(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 AngleTo021a5d00(u8 *self, u8 *a) {
    if (a == NULL || a == self) {
        return LFLD(u16, self, 0x7e);
    }
    return FX_Atan2(LFLD(s32, a, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, a, 0x78) - LFLD(s32, self, 0x78));
}

static inline BOOL Ev19_021a5d00(void) {
    u8 *e = LFLD(u8 *, data_ov000_021ccd6c, 0x14);
    if (e != NULL && LFLD(B19_021a5d00, e, 0x19).b0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Fx021a5d00(u8 *self, u8 *info) {
    if (!Ev19_021a5d00() && !(info != NULL && (LFLD(B18_021a5d00, info, 0x18).b4 ? TRUE : FALSE))) {
        Vec_021a5d00 v;
        v = *(Vec_021a5d00 *)(self + 0x70);
        v.y += LFLD(s32, self, 0x68);
        func_ov000_021899d8(&v, 0, 0x8000, 1, 0x1000, 0x1000);
    }
    LFLD(B22_021a5d00, LFLD(u8 *, self, 0x44), 0x22).b1 = 0;
}

static inline void Reset021a5d00(u8 *self) {
    LFLD(B24_021a5d00, self, 0xb24).f5 = 0;
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_021a5d00, self, 0xb24).f7 = LFLD(B24_021a5d00, self, 0xb24).f9;
    func_ov000_02198360(LFLD(St_021a5d00 *, self, 0x40), 1, 0);
}

void func_ov000_021a5d00(u8 *self) {
    u8 *a;
    u8 *info;
    LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
    a = FindActor021a5d00(LFLD(u16, self, 0x90));
    info = NULL;
    if (a != NULL) {
        info = LFLD(u8 *, a, 0x4c);
    }
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f)++;
    }
    switch (LFLD(St_021a5d00 *, self, 0x40)->state) {
    case 0: {
        char *lbl = data_ov000_021cc67e;
        if (a != NULL) {
            Vec_021a5d00 pos;
            pos = *(Vec_021a5d00 *)(self + 0x70);
            pos.y -= 0x1000;
            LFLD(u16, self, 0x98) = AngleTo021a5d00(self, a);
            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
            {
                St_021a5d00 *st = LFLD(St_021a5d00 *, self, 0x40);
                st->timer++;
                if (st->timer < 0xf) {
                    if (!func_01ffc584(a + 0x70, &pos, (LFLD(s32, a, 0x64) << 1) + 0x19a, 0x3800)) {
                        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc61e, 0x400, 0);
                        func_ov000_021915a0(LFLD(void *, self, 0x38));
                        LFLD(s32, self, 0x9c) = 0x15c;
                        func_ov000_0218dbe0(self, 0);
                        func_ov000_021987b8(LFLD(void *, self, 0x48), 0, 0, 0);
                        return;
                    }
                }
            }
            if (pos.y > LFLD(s32, self, 0x74)) {
                lbl = data_ov000_021cc660;
            }
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), lbl, 0x400, 0);
        LFLD(St_021a5d00 *, self, 0x40)->state++;
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        return;
    }
    case 1:
        Fx021a5d00(self, info);
        if (!func_ov000_02191120(LFLD(void *, self, 0x38))) {
            return;
        }
        if (a != NULL && info != NULL) {
            BOOL done;
            u8 *o44;
            o44 = LFLD(u8 *, a, 0x44);
            done = FALSE;
            if (LFLD(B18_021a5d00, info, 0x18).b1 && info[3] != 10 && info[3] != 11) {
                u8 *g;
                func_02062764(0x3c0, 0x80);
                func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
                g = data_ov000_021ccd54;
                LFLD(u8, g, 0xac) = 1;
                func_ov000_02182590(g + 0xac);
                if (func_0205b1fc()) {
                    done = TRUE;
                }
            }
            if (!done && o44 != NULL) {
                u8 k0 = info[0];
                u8 k1 = info[1];
                if ((k0 == 5 || k0 == 7) && (k1 == 4 || k1 == 6)) {
                    LFLD(B24_021a5d00, self, 0xb24).f5 = 3;
                    LFLD(B24_021a5d00, self, 0xb24).f7 = 3;
                    LFLD(u16, self, 0xb1c) = LFLD(u16, self, 0x90);
                    LFLD(u16, self, 0x90) = 0xffff;
                    func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xd);
                    func_ov000_02199b88(info, self);
                    info[1] = 9;
                    if (info[3] != 10 && info[3] != 11) {
                        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
                    }
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc684, 0x1000, 0);
                    LFLD(St_021a5d00 *, self, 0x40)->state++;
                    LFLD(St_021a5d00 *, self, 0x40)->timer = 0;
                    return;
                }
            }
        }
        Reset021a5d00(self);
        return;
    case 2:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            St_021a5d00 *st = LFLD(St_021a5d00 *, self, 0x40);
            st->timer++;
            if (st->timer > 0x14) {
                Reset021a5d00(self);
            }
        }
        Fx021a5d00(self, info);
        return;
    }
}

}
