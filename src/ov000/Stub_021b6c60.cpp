#include "types.h"

typedef struct {
    u8 pad_00[0x10];
    s32 unk_10;
} Cam021b6c60;

typedef struct {
    u8 pad_00[0xf4];
    Cam021b6c60 unk_f4;
} Game021b6c60;

typedef struct {
    u8 pad_00[0xa];
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
} Rect021b6c60;

typedef struct {
    u8 pad_00[0x70];
    s32 unk_70;
    u8 pad_74[0xafc];
    u8 unk_b70[1];
} Player021b6c60;

typedef struct {
    u8 pad_00[0x14];
    Rect021b6c60 *unk_14;
} Obj021b6c60;

extern "C" {

extern Game021b6c60 *data_ov000_021ccd54;
Player021b6c60 *func_ov000_0219bf90(void);
void func_0203d45c(void *q, u16 a, u16 b, u16 c, u16 d);

void func_ov000_021b6c60(Obj021b6c60 *self) {
    Player021b6c60 *pl = func_ov000_0219bf90();
    Rect021b6c60 *r;
    Cam021b6c60 *cam;
    if (pl == NULL || (r = self->unk_14) == NULL) {
        return;
    }
    cam = &data_ov000_021ccd54->unk_f4;
    if (cam != NULL) {
        s32 d = pl->unk_70 - cam->unk_10;
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
