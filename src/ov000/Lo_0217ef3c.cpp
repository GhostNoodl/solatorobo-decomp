#include "ov000/LoCommon.h"

extern "C" {

extern s32 data_02097d78[];
extern u8 *data_02097e48;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd64;
extern u8 data_0208b318[];
extern char data_ov000_021cba75[];
extern char data_ov000_021cba7f[];
extern char data_ov000_021cba8b[];
extern char data_ov000_021cba97[];
extern char data_ov000_021cbaa3[];
extern void *data_02097e4c;
extern u8 *data_02097dc8;
BOOL func_02059454(void *p, s32 a, s32 b, s32 c);
void func_ov000_0217ea30(void);
void func_ov000_0216f42c(void *a, void *b);
void func_020656b4(void *p);
void func_ov000_0218e514(void *p, s32 a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void STD_CopyString(void *dst, void *src);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_0204a2e0(void *mgr, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0204aab0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_ov000_02187150(void *p, s32 a);
void func_ov000_02182b0c(void *p);
void *func_ov000_0219bf90(void);
void func_ov000_021b4774(void);
void func_020623fc(void);
void func_ov000_02182590(void *p);

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
} SndBits;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 2;
} Bits0e;

typedef struct {
    u8 b0 : 1;
} LoBits8;

#define STATE LFLD(s32, self, 0x3c)

static inline BOOL FadeIs4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

static inline BOOL FadeIs3(void) {
    BOOL r = FALSE;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else if (data_02097d78[0] == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL FadeIdle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline void SndStop(void) {
    u8 *p = data_02097e48;
    if (LFLD(SndBits, p, 0).b3) {
        LFLD(u16, p, 6) = 0x8000;
        LFLD(u16, p, 8) = 0x3c;
        LFLD(u16, p, 2) = 0;
    }
    p = data_02097e48;
    LFLD(u16, p, 0x74) = 0x8000;
    LFLD(u16, p, 0x70) = 0;
}

static inline BOOL LoBit1(VObj *self) {
    return LBIT(self, 4).b1 ? TRUE : FALSE;
}

static inline VObj *NewLoader(void) {
    VObj *o = (VObj *)func_0203dd9c(0x4c);
    if (o != NULL) {
        *(void **)o = data_0208b318;
        o->vfunc_08();
    }
    return o;
}

static inline u8 *NewModel2(char *nm, char *arc) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        char *a = arc;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
            STD_CopyString(m + 0x2c, a);
        }
    }
    return m;
}

void func_ov000_0217ef3c(VObj *self) {
    char buf[0x20];
    switch (STATE) {
    case 0:
        if (func_02059454(data_02fe152c, 5, 1, 3)) {
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217ea30;
            self->vfunc_48();
            STATE = 1;
        } else {
            STATE = 3;
        }
        return;
    case 1:
        if (LoBit1(self)) {
            return;
        }
        if (!self->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x44) == 2) {
            STATE = 2;
        } else if (LFLD(s32, self, 0x44) == -1) {
            STATE = 3;
        } else if (LFLD(s32, self, 0x44) == 0) {
            STATE = 8;
        } else if (LFLD(s32, self, 0x44) == 1) {
            STATE = 10;
        }
        return;
    case 2:
    case 3:
        SndStop();
        if (!FadeIs3() && !FadeIs4()) {
            func_0203cc58(0xb4000, 1, -1);
        }
        if (STATE == 3) {
            STATE = 4;
        } else {
            STATE = 7;
            return;
        }
        LFLD(s32, self, 0x40) = 0;
    case 4: {
        VObj *o;
        if (!FadeIs4()) {
            return;
        }
        {
            u8 **pmq = &data_ov000_021ccd30;
            u8 *mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x11c));
            LFLD(void *, mq, 0x11c) = NULL;
            mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x118));
            LFLD(void *, mq, 0x118) = NULL;
        }
        LFLD(Bits0e, data_ov000_021ccd54, 0xe).b2 = 2;
        func_020656b4(data_0214a420);
        func_ov000_0218e514(data_ov000_021ccd68, 0xf000);
        LFLD(LoBits8, data_ov000_021ccd64, 0xc).b0 = 0;
        func_0206e900(buf, data_ov000_021cba75);
        o = NewLoader();
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x48)->vfunc_24(buf, data_ov000_021cba7f);
        o = NewLoader();
        LFLD(VObj *, self, 0x50) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x50)->vfunc_24(buf, data_ov000_021cba8b);
        STATE = 5;
    }
    case 5: {
        BOOL ok = TRUE;
        u8 *m;
        u8 *p;
        if (!LFLD(VObj *, self, 0x48)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!LFLD(VObj *, self, 0x50)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!ok) {
            return;
        }
        if (++LFLD(s32, self, 0x40) < 0x1e) {
            return;
        }
        LFLD(s32, self, 0x40) = 0;
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
        LFLD(u8 *, self, 0x4c) = m;
        func_020417e0(LFLD(void *, self, 0x4c), (void *)LFLD(VObj *, self, 0x48)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x4c), 2, 0xffff);
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
        LFLD(u8 *, self, 0x54) = m;
        func_020417e0(LFLD(void *, self, 0x54), (void *)LFLD(VObj *, self, 0x50)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x54), 0, 0xffff);
        LFLD(s32, LFLD(void *, self, 0x54), 0x150) = -0x1ccd;
        func_0204a2e0(data_02097e4c, 0);
        func_0203cb78(0x3c000, 0, -1);
        p = data_02097e48;
        if (LFLD(SndBits, p, 0).b0) {
            if (LFLD(u16, p, 6) != 0xffff || LFLD(u16, p, 4) != 0x2f) {
                if (LFLD(u16, p, 2) != 10 && LFLD(u16, p, 2) != 0) {
                    if (LFLD(u16, p, 6) != 0xffff) {
                        func_0204aab0(p);
                    }
                    LFLD(u16, p, 2) = 1;
                } else {
                    LFLD(u16, p, 2) = 0;
                }
                LFLD(u16, p, 6) = 0x2f;
                LFLD(u16, p, 8) = 10;
            }
        }
        STATE = 6;
    }
    case 6:
        if (!FadeIdle()) {
            return;
        }
        if (++LFLD(s32, self, 0x40) <= 600) {
            if (!(LFLD(u16, data_02097dc8, 0x12) & 3)) {
                return;
            }
        }
        func_0203cc58(0xf000, 1, -1);
        STATE = 7;
        return;
    case 7:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02187150(data_ov000_021ccd54, 0);
        STATE = 12;
        return;
    case 8:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 9;
    case 9:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02182b0c(data_ov000_021ccd54);
        STATE = 12;
        return;
    case 10:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 11;
    case 11:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        if (func_ov000_0219bf90()) {
            func_ov000_021b4774();
        }
        func_020623fc();
        { u8 *q = data_ov000_021ccd54; q[0xac] = 1;
        func_ov000_02182590(q + 0xac); }
        STATE = 12;
        break;
    }
}

}
