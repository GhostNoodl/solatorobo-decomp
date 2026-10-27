#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov014_02205d70(Ov014Actor *self);

extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov014_02205924(Ov014Actor *self);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *v);
extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *data_02097e4c;

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)

// Like the SDK's CP_SetSqrt64: the parameter is written through a plain (non-volatile)
// u64 pointer, so the scheduler may still move other stores around it.
static inline void Ov014_SetSqrt64(u64 param) {
    OV014_SQRTCNT = 1;
    *(u64 *)0x40002b8 = param;
}

static inline s32 Ov014g_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_02205634(Ov014Actor *self) {
    Ov014Actor *t = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (t != NULL) {
        {
            Ov014Sub48 *m = t->unk_48;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
        }
        if (t->kind == 0x1000) {
            func_ov014_02205924(self);
            return;
        }
        switch (self->unk_40->state) {
        case 0: {
            Ov014Actor *g;
            s32 r;
            u16 a;
            Ov014V *e;
            {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
            }
            g = func_ov000_0218d240(self);
            {
                s64 sq;
                s32 dx;
                s32 dz;
                Ov014Vec p;
                Ov014_VecCopyYZ(&p, &g->pos);
                dx = self->pos.x - p.x; dz = self->pos.z - p.z; sq = (s64)dx * dx; sq += (s64)dz * dz;
                self->unk_84.x = p.x;
                self->unk_84.y = p.y + 0x1000;
                self->unk_84.z = p.z;
                Ov014_SetSqrt64((u64)(sq * 4));
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->unk_9c = Ov014g_FxMul64(OV014_SIN(a), 0x666);
            FLD(s32, self, 0xa0) = Ov014g_FxMul64(OV014_COS(a), 0x666);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            e = func_02065f88(0x68, &self->pos);
            e->v0c(0xb33);
            e->v34(0xbfff, self->rot[1], 0);
            func_02065f88(0x6b, &self->pos);
            func_0204a028(data_02097e4c, 0x35, &self->pos, 5);
            {
                Ov014Sub48 *m = self->unk_48;
                m->unk_50 = 0;
                m->unk_54 = 0;
                FLD(u32, m, 0x58) = 0;
            }
            FLD(u8, self, 0xe4) = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            if (self->pos.y - self->unk_84.y > 0x1000) {
                func_ov000_0218d918(self, &self->unk_84, 0x266);
                self->unk_98 = self->rot[1];
            }
            func_ov000_0218dbe0(self, 0);
            func_ov014_02205d70(self);
            if ((self->unk_48->unk_50 & 0x20000000) || ++FLD(u8, self, 0xe4) >= 100) {
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
            break;
        }
    } else {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
