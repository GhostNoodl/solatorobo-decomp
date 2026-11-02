#include "ov000/LoCommon.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;

struct Obj02152294 {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x5c];
    s16 unk_68;
    u8 unk_6a[0xa];
    VObj *unk_74;
};

void func_ov000_02152294(Obj02152294 *self, u16 a, s32 b, s32 c) {
    VObj *p;
    void *res = data_02149ef8;
    p = (VObj *)Heap_Alloc(0x1e4);
    if (p) {
        *(void **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(void **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb1b0;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb0b8;
        p->vfunc_28();
    }
    self->unk_74 = p;
    LFLD(u16, p, 0x1d8) = a;
    LFLD(void *, self->unk_74, 0x1dc) = MsgRes_GetString(res, b);
    LFLD(u16, self->unk_74, 0x1e0) = 0;
    LFLD(s32, self->unk_74, 8) = self->unk_08;
    LFLD(s32, self->unk_74, 0x84) = c;
    self->unk_74->vfunc_08();
    LFLD(s16, self->unk_74, 0x68) = self->unk_68 + 0x200;
    LBIT(self, 0xc).b0 = 1;
}

}
