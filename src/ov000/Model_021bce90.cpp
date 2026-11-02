#include "types.h"
#include "ov000/Bss021ccd74.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern const char *data_0208cca0;
extern const char *data_0208cb74;
extern const char *data_0208cc94;
extern const char *data_0208cc88;
extern const char *data_0208cb7c;
extern char data_0214b105[];
void *Heap_Alloc(u32 size);

void func_ov000_021bce90(void) {
    void *res;
    Model *m;
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cca0), data_0208cb74);
    MODEL_NEW(m, data_0208cb74, data_0208cca0);
    data_ov000_021ccd74.unk_0c = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_0c->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 0);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 1);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 2);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 3);
    TexObj_SelectImage(data_ov000_021ccd74.unk_0c, 0, 0xf);
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
    MODEL_NEW(m, data_0208cc88, data_0208cc94);
    data_ov000_021ccd74.unk_14 = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_14->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_14, 0, 2);
    res = ResList_FindType2(ResMgr_GetArcList(data_0214b105), data_0208cb7c);
    MODEL_NEW(m, data_0208cb7c, data_0214b105);
    data_ov000_021ccd74.unk_04 = m;
    TexObj_SetRes(m, res);
    data_ov000_021ccd74.unk_04->flags |= 2;
    TexObj_SelectImage(data_ov000_021ccd74.unk_04, 0, 6);
}
}
