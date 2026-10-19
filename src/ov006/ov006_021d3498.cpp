#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/Tasks.h"

typedef struct ov006_Chr021d3498 {
    u8 unk0[0x6ec];
    ov006_Vec32 unk6EC;
    ov006_Vec32 unk6F8;
} ov006_Chr021d3498;

typedef struct ov006_Task021d3498 {
    u8 unk0[0x58];
    ov006_Chr021d3498 *unk58;
} ov006_Task021d3498;

extern "C" {

extern const ov006_Vec32 data_ov006_021eb74c;
extern const ov006_Vec32 data_ov006_021eb758;
extern char data_ov006_021ebc04[];

void VEC_Normalize(const ov006_Vec32 *src, ov006_Vec32 *dst);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
s16 *func_020706a0(u16 id);
void func_ov000_02162b40(ov006_Chr021d3498 *chr, const char *a, const char *b, const char *c, const char *d,
                         const char *e, int f, int g);

static inline void ov006_Chr_SetVec(ov006_Vec32 *dst, const ov006_Vec32 *src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

#define OV006_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov006_021d3498(ov006_Task021d3498 *self, u16 id, BOOL flag) {
    const char *a;
    const char *b;
    const char *c;
    const char *d;
    if (self->unk58 == NULL) {
        return;
    }
    a = func_0207011c(id);
    b = func_020701d4(id);
    c = func_0207011c(id);
    d = func_020701d4(id);
    if (flag) {
        ov006_Vec32 v;
        VEC_Normalize(&data_ov006_021eb758, &v);
        v.x = OV006_FX_MUL(v.x, 0x3000);
        v.y = OV006_FX_MUL(v.y, 0x3000);
        v.z = OV006_FX_MUL(v.z, 0x3000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6F8.x = v.x;
            chr->unk6F8.y = v.y;
            chr->unk6F8.z = v.z;
        }
        VEC_Normalize(&data_ov006_021eb74c, &v);
        v.x = OV006_FX_MUL(v.x, 0x2000);
        v.y = OV006_FX_MUL(v.y, 0x2000);
        v.z = OV006_FX_MUL(v.z, 0x2000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6EC.x = v.x;
            chr->unk6EC.y = v.y;
            chr->unk6EC.z = v.z;
        }
    } else {
        ov006_Vec32 v;
        VEC_Normalize(&data_ov006_021eb74c, &v);
        v.x = OV006_FX_MUL(v.x, 0x2000);
        v.y = OV006_FX_MUL(v.y, 0x2000);
        v.z = OV006_FX_MUL(v.z, 0x2000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6F8.x = v.x;
            chr->unk6F8.y = v.y;
            chr->unk6F8.z = v.z;
        }
        VEC_Normalize(&data_ov006_021eb758, &v);
        v.x = OV006_FX_MUL(v.x, 0x3000);
        v.y = OV006_FX_MUL(v.y, 0x3000);
        v.z = OV006_FX_MUL(v.z, 0x3000);
        {
            ov006_Chr021d3498 *chr = self->unk58;
            chr->unk6EC.x = v.x;
            chr->unk6EC.y = v.y;
            chr->unk6EC.z = v.z;
        }
    }
    {
        s16 g = *func_020706a0(id);
        func_ov000_02162b40(self->unk58, a, b, c, d, data_ov006_021ebc04, 0, g);
    }
}

}
