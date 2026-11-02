#include "types.h"
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
extern u8 data_ov000_021ccd74[];
void *Heap_Alloc(u32 size);

void func_ov000_021bce90(void) {
    void *res;
    Model *m;
    res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
    MODEL_NEW(m, data_0208cb74, data_0208cca0);
    LFLD(Model *, data_ov000_021ccd74, 0xc) = m;
    func_020417e0(m, res);
    LFLD(Model *, data_ov000_021ccd74, 0xc)->flags |= 2;
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0xc), 0, 0);
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0xc), 0, 1);
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0xc), 0, 2);
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0xc), 0, 3);
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0xc), 0, 0xf);
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    MODEL_NEW(m, data_0208cc88, data_0208cc94);
    LFLD(Model *, data_ov000_021ccd74, 0x14) = m;
    func_020417e0(m, res);
    LFLD(Model *, data_ov000_021ccd74, 0x14)->flags |= 2;
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0x14), 0, 2);
    res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    MODEL_NEW(m, data_0208cb7c, data_0214b105);
    LFLD(Model *, data_ov000_021ccd74, 0x4) = m;
    func_020417e0(m, res);
    LFLD(Model *, data_ov000_021ccd74, 0x4)->flags |= 2;
    func_02041d9c(LFLD(Model *, data_ov000_021ccd74, 0x4), 0, 6);
}
}
