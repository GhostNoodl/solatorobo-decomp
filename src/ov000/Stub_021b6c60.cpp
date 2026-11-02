#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u8 pad_00[0xa];
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
} Rect021b6c60;

typedef struct {
    u8 pad_00[0x14];
    Rect021b6c60 *unk_14;
} Obj021b6c60;

extern "C" {
Robo021ca458 *func_ov000_0219bf90(void);
void func_0203d45c(void *q, u16 a, u16 b, u16 c, u16 d);

void func_ov000_021b6c60(Obj021b6c60 *self) {
    Robo021ca458 *pl = func_ov000_0219bf90();
    Rect021b6c60 *r;
    FieldCam *cam;
    if (pl == NULL || (r = self->unk_14) == NULL) {
        return;
    }
    cam = &data_ov000_021ccd54->cam;
    if (cam != NULL) {
        s32 d = pl->pos.x - cam->base.at.x;
        s32 q;
        if (d > 0x5000) {
            d = 0x5000;
        } else if (d < -0x5000) {
            d = -0x5000;
        }
        q = d / 7;
        func_0203d45c(pl->unk_b70, r->unk_0a - q, r->unk_0c, r->unk_0e - q, r->unk_10);
    } else {
        func_0203d45c(pl->unk_b70, r->unk_0a, r->unk_0c, r->unk_0e, r->unk_10);
    }
}

}
