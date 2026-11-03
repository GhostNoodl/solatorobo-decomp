#include "ov000/VObj.h"
#include "nitro/fx.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"
#include "Main/Effect/Effect.h"

extern "C" {

typedef struct {
    u8 unk_00[0x58];
    u16 unk_58;
    u16 unk_5a;
} Pool0214ccf8;
extern Pool0214ccf8 data_02fe1534;
extern void *gSndMgr;
extern VecFx32 data_ov000_021c9850;
extern u8 UiObj_vtbl[];
extern u8 Lo021cad50_vtbl[];
void *Heap_Alloc(u32 size);
void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_0215c744(VObj *o, s32 a, s32 b);

struct Obj0214ccf8 {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x58];
    s16 unk_68;
    u8 unk_6a[0x22];
    VObj *unk_8c;
    u8 unk_90[0x178];
    u16 unk_208;
    u16 unk_20a;
    s32 unk_20c;
    s32 unk_210;
    s32 unk_214;
    s32 unk_218;
};

void func_ov000_0214ccf8(Obj0214ccf8 *self) {
    s32 t;
    if (self->unk_8c != NULL) {
        if (self->unk_8c->vfunc_1c()) {
            return;
        }
        HEAP_DELETE_VOBJ(self->unk_8c);
        return;
    }
    if (self->unk_0c & 0x20000) {
        if (self->unk_214 == 0) {

            data_02fe1534.unk_58++;
            SndMgr_PlayVolume(gSndMgr, 0x11, -1, -1, -1);
            VecFx32 v = data_ov000_021c9850;
            Effect_SpawnId(0x2714, &v);
        }
        self->unk_214 += 0x1000;
        t = FX_Div(self->unk_214, 0x1e000);
        if (t >= 0x1000) {
            t = 0x1000;
            if (!EffectMgr_FindByKey(gEffectMgr, 0x2714)) {
                VObj *o;
                self->unk_0c &= ~0x20000;
                o = (VObj *)Heap_Alloc(0xe8);
                if (o != NULL) {
                    VOBJ_SET_VTABLE(o, UiObj_vtbl);
                    o->vfunc_28();
                    VOBJ_SET_VTABLE(o, Lo021cad50_vtbl);
                    o->vfunc_28();
                }
                self->unk_8c = o;
                func_ov000_0215c744(o, 0x46b, data_02fe1534.unk_58);
                LFLD(s16, self->unk_8c, 0x68) = self->unk_68 + 0x40;
                self->unk_8c->vfunc_70();
                return;
            }
        }
        self->unk_218 = FX_SinCosTable_[((t << 15) >> 16) * 2];
    }
    if (!(self->unk_0c & 0x10000)) {
        return;
    }
    if (self->unk_20a == 0) {
        if (self->unk_0c & 0x20000) {
            return;
        }
        data_02fe1534.unk_5a = self->unk_208;
        self->unk_0c &= ~0x10000;
        return;
    }
    if (self->unk_20c == 0) {
        SndMgr_PlayVolume(gSndMgr, 0x4a, -1, -1, -1);
    }
    self->unk_20c += 0x1000;
    t = FX_Div(self->unk_20c, 0x8000);
    if (t >= 0x1000) {
        t = 0;
        self->unk_208++;
        self->unk_20a--;
        self->unk_20c = 0;
        if (self->unk_208 >= 10) {
            self->unk_208 = 0;
            self->unk_214 = 0;
            self->unk_0c |= 0x20000;
        }
    }
    self->unk_210 = FX_SinCosTable_[((t << 14) >> 16) * 2];
}

}
