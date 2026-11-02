#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 rest : 10;
} Body_0219e498;

typedef struct {
    u16 b0 : 9;
    u16 b9 : 1;
    u16 rest : 6;
} G18_0219e498;

extern "C" {
extern u8 *data_0214a424;
void HitSphere_Link(void *a);
void func_0203f364(void *a);
void func_ov000_0219864c(void *a, void *b, void *c);
void func_ov000_021987b8(void *a, s32 b, void *c, void *d);

#define BODY(s, off) LFLD(Body_0219e498, s, (off) + 0x9a)

static inline BOOL On0219e498(Robo021ca458 *s, u32 off) {
    return (!BODY(s, off).b3 && BODY(s, off).b0) ? TRUE : FALSE;
}

static inline BOOL On2_0219e498(Robo021ca458 *s, u32 off) {
    return (!BODY(s, off).b4 && BODY(s, off).b1) ? TRUE : FALSE;
}

static inline void Show0219e498(u8 *s, u32 off) {
    BODY(s, off).b0 = 1;
    BODY(s, off).b3 = 1;
    HitSphere_Link(s + off);
}

static inline void Hide0219e498(u8 *s, u32 off) {
    BODY(s, off).b0 = 0;
    BODY(s, off).b3 = 0;
    func_0203f364(s + off);
}

static inline void Hide2_0219e498(Robo021ca458 *s, u32 off) {
    BODY(s, off).b1 = 0;
    BODY(s, off).b4 = 0;
}

static inline BOOL G9_0219e498(void) {
    return LFLD(G18_0219e498, data_0214a424, 0x18).b9 ? TRUE : FALSE;
}

static inline BOOL RgbEq0219e498(FieldId *a, FieldId *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov000_0219e498(Robo021ca458 *self) {
    if (self->unk_b24_1) {
        s32 a = 0;
        s32 b = 0x266;
        if (self->unk_b22_3) {
            if (self->unk_b24_5) {
                b += 0x4f6;
                a += 0x4cd;
            } else {
                b += 0x29;
                a += 0x400;
                b += 0x400;
            }
        } else if (self->unk_b24_5) {
            if (self->unk_b24_12 == 0) {
                a += 0x333;
                b += 0x35c;
            }
        }
        self->unk_6f8 = a + self->radius;
        self->unk_720 = b + self->centerY;
        if (!On0219e498(self, 0x6c0)) {
            Show0219e498((u8 *)self, 0x6c0);
        }
        if (!On2_0219e498(self, 0x6c0)) {
            LFLD(u16, self, 0x75a) |= 0x12;
        }
        func_ov000_0219864c((u8 *)self + 0x6c0, NULL, NULL);
        self->unk_75c = self->pos;
        Hide0219e498((u8 *)self, 0x2cc);
        Hide2_0219e498(self, 0x2cc);
        func_ov000_0219864c((u8 *)self + 0x2cc, NULL, NULL);
        return;
    }
    if (!G9_0219e498() && RgbEq0219e498(&data_ov000_021ccd54->unk_ca, &LFLD(FieldId, self, 0x772))) {
        self->unk_6f8 = self->radius >> 1;
        self->unk_720 = self->centerY >> 1;
        Show0219e498((u8 *)self, 0x6c0);
        LFLD(u16, self, 0x75a) |= 0x12;
        if ((self->unk_710 & 0x20000000) || !(self->unk_714 & 0x20000000)) {
            self->unk_768 = 0;
            BODY(self, 0x6c0).b5 = 1;
        } else {
            self->unk_768 -= 0x52;
            if (self->unk_768 > -0x148) {
                self->unk_768 = -0x148;
            }
            self->unk_75c.y += self->unk_768;
        }
        if (self->unk_b24_24 || self->unk_768 != 0) {
            self->unk_b24_24 = 0;
            func_ov000_021987b8((u8 *)self + 0x6c0, 0, (u8 *)self + 0x75c, (u8 *)self + 0x76c);
        }
    } else {
        Hide0219e498((u8 *)self, 0x6c0);
        Hide2_0219e498(self, 0x6c0);
    }
    func_ov000_0219864c((u8 *)self + 0x6c0, (u8 *)self + 0x75c, (u8 *)self + 0x76c);
    if (self->unk_b24_2 != 1) {
        if (self->unk_31c & 0x400) {
            self->unk_304 = (self->radius >> 1) + (self->radius >> 2);
        } else {
            self->unk_304 = (self->radius >> 1) + (self->radius >> 3);
        }
        Show0219e498((u8 *)self, 0x2cc);
        LFLD(u16, self, 0x366) |= 0x12;
    } else {
        Hide0219e498((u8 *)self, 0x2cc);
        self->unk_31c = 0;
        self->unk_320 = 0;
        self->unk_324 = 0;
        Hide2_0219e498(self, 0x2cc);
    }
    func_ov000_0219864c((u8 *)self + 0x2cc, NULL, NULL);
}
}
