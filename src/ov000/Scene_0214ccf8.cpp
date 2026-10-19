#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"

typedef struct {
    s32 x, y, z;
} Vec0214ccf8;

extern "C" {

typedef struct {
    u8 unk_00[0x58];
    u16 unk_58;
    u16 unk_5a;
} Pool0214ccf8;
extern Pool0214ccf8 data_02fe1534;
extern void *data_02097e4c;
extern s32 data_0214a420;
extern Vec0214ccf8 data_ov000_021c9850;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern const s16 FX_SinCosTable_[];
void *func_0203dd9c(u32 size);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_02065f88(s32 id, Vec0214ccf8 *v);
s32 func_020658cc(s32 a, s32 id);
s32 FX_Div(s32 a, s32 b);
void func_ov000_0215c744(VObj *o, s32 a, s32 b);

void func_ov000_0214ccf8(u8 *self) {
    s32 t;
    if (LFLD(VObj *, self, 0x8c) != NULL) {
        if (LFLD(VObj *, self, 0x8c)->vfunc_1c()) {
            return;
        }
        HEAP_DELETE_VOBJ(LFLD(VObj *, self, 0x8c));
        return;
    }
    if (LFLD(u32, self, 0xc) & 0x20000) {
        if (LFLD(s32, self, 0x214) == 0) {

            data_02fe1534.unk_58++;
            func_02049a48(data_02097e4c, 0x11, -1, -1, -1);
            Vec0214ccf8 v = data_ov000_021c9850;
            func_02065f88(0x2714, &v);
        }
        LFLD(s32, self, 0x214) += 0x1000;
        t = FX_Div(LFLD(s32, self, 0x214), 0x1e000);
        if (t >= 0x1000) {
            t = 0x1000;
            if (!func_020658cc(data_0214a420, 0x2714)) {
                VObj *o;
                LFLD(u32, self, 0xc) &= ~0x20000;
                o = (VObj *)func_0203dd9c(0xe8);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, data_ov000_021cac60);
                    o->vfunc_28();
                    VOBJ_SET_VTABLE(o, data_ov000_021cad50);
                    o->vfunc_28();
                }
                LFLD(VObj *, self, 0x8c) = o;
                func_ov000_0215c744(o, 0x46b, data_02fe1534.unk_58);
                LFLD(s16, LFLD(VObj *, self, 0x8c), 0x68) = LFLD(s16, self, 0x68) + 0x40;
                LFLD(VObj *, self, 0x8c)->vfunc_70();
                return;
            }
        }
        LFLD(s32, self, 0x218) = FX_SinCosTable_[((t << 15) >> 16) * 2];
    }
    if (!(LFLD(u32, self, 0xc) & 0x10000)) {
        return;
    }
    if (LFLD(u16, self, 0x20a) == 0) {
        if (LFLD(u32, self, 0xc) & 0x20000) {
            return;
        }
        data_02fe1534.unk_5a = LFLD(u16, self, 0x208);
        LFLD(u32, self, 0xc) &= ~0x10000;
        return;
    }
    if (LFLD(s32, self, 0x20c) == 0) {
        func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
    }
    LFLD(s32, self, 0x20c) += 0x1000;
    t = FX_Div(LFLD(s32, self, 0x20c), 0x8000);
    if (t >= 0x1000) {
        t = 0;
        LFLD(u16, self, 0x208)++;
        LFLD(u16, self, 0x20a)--;
        LFLD(s32, self, 0x20c) = 0;
        if (LFLD(u16, self, 0x208) >= 10) {
            LFLD(u16, self, 0x208) = 0;
            LFLD(s32, self, 0x214) = 0;
            LFLD(u32, self, 0xc) |= 0x20000;
        }
    }
    LFLD(s32, self, 0x210) = FX_SinCosTable_[((t << 14) >> 16) * 2];
}

}
