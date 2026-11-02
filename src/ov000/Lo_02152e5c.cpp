#include "ov000/LoCommon.h"
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

struct Obj02152e5c {
    u8 unk_00[0x10];
    Model *unk_10;
};

BOOL func_ov000_02152e5c(Obj02152e5c *self) {
    if (self->unk_10) {
        return TRUE;
    }
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        MODEL_NEW(self->unk_10, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->unk_10, data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = func_02035d5c(self->unk_10->name);
        void *b = func_02034d88(a, self->unk_10->unk_04c);
        func_020417e0(self->unk_10, b);
    }
    self->unk_10->flags |= 2;
    func_02041d9c(self->unk_10, 0, 7);
    return TRUE;
}

}
