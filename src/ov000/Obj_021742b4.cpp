#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x4c];
    s32 unk_4c;
} Sub021742b4;

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
    u8 unk_08[0x1c];
    s32 unk_24;
} Msg021742c8;

typedef struct {
    u32 unk_00;
    s32 unk_04;
    void *unk_08;
} Obj021742b4;

typedef struct {
    u8 unk_00[0x8];
    VObj unk_08;
} Sub02174380;

typedef struct {
    u8 unk_00[0x10];
    Sub02174380 *unk_10;
} Data021ccd34;

extern "C" {

extern void *data_02097e4c;
extern Data021ccd34 data_ov000_021ccd34;

void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_0214c270(void);

void func_ov000_021742b4(Obj021742b4 *self) {
    Sub021742b4 *sub = (Sub021742b4 *)self->unk_08;
    if (self->unk_04 == 3) {
        sub->unk_4c = 1;
    }
}

BOOL func_ov000_021742c8(Obj021742b4 *self, Msg021742c8 *msg) {
    VObj *obj = (VObj *)self->unk_08;
    if (msg == NULL) {
        obj->vfunc_0c(0);
        return TRUE;
    }
    if (msg->unk_06 != 0xffff) {
        if (msg->unk_24 != 0xe) {
            obj->vfunc_60(msg->unk_06, 1);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    } else {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
    }
    return TRUE;
}

}
