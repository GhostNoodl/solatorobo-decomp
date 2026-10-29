#include "types.h"

typedef struct {
    u8 unk_00[0x6];
    u16 unk_06;
} Msg0215e634;

typedef struct {
    u8 unk_00[0x7c];
    u16 unk_7c;
} Dtcm02fe1534;

typedef struct Obj0215e5f8 {
    u8 unk_00[0x84];
    BOOL (*unk_84)(struct Obj0215e5f8 *self, Msg0215e634 *msg);
    u8 unk_88[0x154];
    void *unk_1dc;
} Obj0215e5f8;

extern void *data_02149ef8;
extern void *data_02097e4c;
extern Dtcm02fe1534 data_02fe1534;

void *func_02061d54(s32 a);
void *func_0204c0e8(void *a, void *b);
void func_ov000_0215e344(Obj0215e5f8 *self);
void func_0206281c(void);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);

void func_ov000_0215e5f8(Obj0215e5f8 *self) {
    self->unk_1dc = func_0204c0e8(data_02149ef8, func_02061d54(0x18));
    func_ov000_0215e344(self);
}

void func_ov000_0215e62c(void) {
}

void func_ov000_0215e630(void) {
}

BOOL func_ov000_0215e634(Obj0215e5f8 *self, Msg0215e634 *msg) {
    if (self->unk_84 != NULL) {
        return self->unk_84(self, msg);
    }
    if (msg == NULL) {
        func_0206281c();
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return FALSE;
    }
    if (msg->unk_06 == 0) {
        data_02fe1534.unk_7c = 1;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else if (msg->unk_06 == 1) {
        data_02fe1534.unk_7c = 0;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}
