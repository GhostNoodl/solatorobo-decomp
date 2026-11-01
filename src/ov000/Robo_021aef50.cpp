#include "ov000/LoCommon.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021aef50;

typedef struct {
    u32 b0 : 12;
    u32 kind : 2;
    u32 b14 : 18;
} B24_021aef50;

typedef struct {
    s32 x, y, z;
} Vec_021aef50;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
} B190_021aef50;

typedef struct {
    u16 x, y, z;
} Rot_021aef50;

#define REG_SQRTCNT_021aef50 (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT_021aef50 (*(volatile u32 *)0x40002b4)
/* written without volatile: the target computes both halves before storing */
#define REG_SQRT_PARAM_021aef50 (*(u64 *)0x40002b8)

extern "C" {

extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc630[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02198360(St_021aef50 *st, s32 state, s32 x);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d918(void *self, void *v, s32 a);
void func_ov000_0218ddd4(void *self, const void *target, s32 turn);
void func_ov000_0218dbe0(void *self, s32 turn);
s32 func_ov000_0219a2f4(void *pos, s32 up, s32 down);
VObj *func_02065f88(s32 id, void *pos);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
void *func_0204a028(void *a, s32 b, void *c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void VEC_MultAdd(s32 a, const void *v1, const void *v2, void *out);

static inline u8 *FindActor021aef50(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Dist021aef50(s32 dx, s32 dz) {
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    REG_SQRTCNT_021aef50 = 1;
    REG_SQRT_PARAM_021aef50 = (u64)(sq << 2);
    while (REG_SQRTCNT_021aef50 & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT_021aef50 + 1) >> 1;
}

struct Obj021aef50 {
    u8 unk_00[0x38];
    void *unk_38;
    u8 unk_3c[0x4];
    St_021aef50 *unk_40;
    u8 unk_44[0x24];
    s32 unk_68;
    u8 unk_6c[0x4];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92[0x6];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0xa74];
    u16 unk_b20;
    u8 unk_b22[0x2];
    B24_021aef50 unk_b24;
    u8 unk_b28[0x1];
    u8 unk_b29;
    u8 unk_b2a[0x5];
    u8 unk_b2f;
};

void func_ov000_021aef50(Obj021aef50 *self) {
    u16 id;
    u8 *a;
    u8 *info;
    Vec_021aef50 pos;
    id = self->unk_b20;
    if (id == 0xffff) {
        id = self->unk_90;
    }
    a = FindActor021aef50(id);
    info = NULL;
    if (a != NULL) {
        info = LFLD(u8 *, a, 0x4c);
        pos = LFLD(Vec_021aef50, a, 0x70);
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    switch (self->unk_40->state) {
    case 0:
        if (info != NULL) {
            u8 k = info[2];
            if (k == 9) {
                self->unk_b24.kind = 1;
                LFLD(u8, data_ov000_021ccd54, 0x190) |= 0x20;
            } else if (k == 10) {
                self->unk_b24.kind = 2;
            } else if (k == 11) {
                self->unk_b24.kind = 3;
            }
        } else {
            self->unk_b24.kind = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
            return;
        }
        self->unk_b20 = self->unk_90;
        self->unk_90 = 0xffff;
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc62a, 0x800, 0);
        {
            s32 d = Dist021aef50(pos.x - self->unk_70, pos.z - self->unk_78);
            self->unk_9c = d >> 4;
            self->unk_a0 = 0x53f;
            self->unk_a4 = 0;
            self->unk_a8 = 0x52;
        }
        func_02049f44(data_02097e4c, 7, (u8 *)self + 0x70, 0);
        self->unk_40->state++;
        break;
    case 1:
        if (a == NULL) {
            self->unk_b24.kind = 0;
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        func_ov000_0218d918(self, &pos, 0x59a);
        func_ov000_0218ddd4(self, &pos, 0);
        {
            St_021aef50 *st = self->unk_40;
            st->timer++;
            if (st->timer < 0x10) {
                break;
            }
        }
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc630, 0x400, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        if (self->unk_b24.kind == 1) {
            VObj *e = func_02065f88(0x6d, &pos);
            e->vfunc_0c(0xb33);
            e->vfunc_34(0xf000, 0, 0);
        } else if (self->unk_b24.kind == 3) {
            func_0204a028(data_02097e4c, 0xe, (u8 *)self + 0x70, -5);
        }
        break;
    case 2: {
        St_021aef50 *st = self->unk_40;
        st->timer++;
        if (st->timer >= 10) {
            if (a != NULL) {
                LFLD(Vec_021aef50, self, 0x70) = pos;
                {
                    u16 ry = LFLD(u16, a, 0x7e);
                    u16 rz = LFLD(u16, a, 0x80);
                    u16 rx = LFLD(u16, a, 0x7c);
                    self->unk_7c = rx;
                    self->unk_7e = ry;
                    self->unk_80 = rz;
                    self->unk_98 = ry;
                }
            }
            func_ov000_02198360(self->unk_40, 1, 0);
        } else {
            Vec_021aef50 d;
            self->unk_7e = func_01ffc128(LFLD(u16, a, 0x7e), self->unk_7e, 0x800, 1, 0x8000);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            d.x = pos.x - self->unk_70;
            d.y = pos.y - self->unk_74;
            d.z = pos.z - self->unk_78;
            VEC_MultAdd(0x800, &d, (u8 *)self + 0x70, (u8 *)self + 0x70);
        }
        break;
    }
    case 100:
        self->unk_b20 = 0xffff;
        self->unk_b24.kind = 0;
        self->unk_7c = 0;
        func_02049f44(data_02097e4c, 7, (u8 *)self + 0x70, 0);
        self->unk_40->state++;
    case 101:
        self->unk_b29 |= 2;
        func_ov000_0218dbe0(self, 0);
        if (self->unk_a0 >= 0) {
            break;
        }
        if (func_ov000_0219a2f4((u8 *)self + 0x70, self->unk_68 << 1, -0x66) == -0x1000) {
            break;
        }
        LFLD(B190_021aef50, data_ov000_021ccd54, 0x190).b5 = 0;
        func_ov000_02198360(self->unk_40, 4, 0);
        break;
    }
}

}
