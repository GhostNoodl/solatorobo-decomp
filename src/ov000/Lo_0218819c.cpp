#include "ov000/CmdObj.h"

typedef struct {
    u8 pad_00[0xb24];
    u32 unk_b24_0 : 1;
} Obj0219bf90;

typedef struct {
    u8 pad_00[6];
    u16 unk_06;
} Obj0205b31c;

typedef struct {
    u8 pad_00[0x12];
    u16 unk_12;
} Pad02097dc8;

extern "C" {
extern s32 data_02097d78[];
extern Pad02097dc8 *data_02097dc8;
Obj0219bf90 *func_ov000_0219bf90(void);
Obj0205b31c *func_0205b31c(void);

static inline BOOL IsMode0(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL IsMode4(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

s32 func_ov000_0218819c(CmdObj *self) {
    u16 arg = self->unk_a6;
    u16 kind = arg & 0xff;
    u8 mode = (arg >> 8) & 0xf;
    BOOL done = FALSE;
    Obj0219bf90 *obj;
    u16 count = self->unk_a4;
    BOOL ret;
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        ret = (mode ^ 1) != 0;
        if (kind != 2) {
            if (!IsMode0() && !IsMode4()) {
                return ret;
            }
        } else {
            kind = 0;
        }
        if (kind == 0xff) {
            if (data_02097dc8->unk_12 & 1) {
                CmdObj_Done(self);
                CmdObj_Push(self, 0x28, 0);
            }
        } else {
            obj = func_ov000_0219bf90();
            Obj0205b31c *p = func_0205b31c();
            if ((p != NULL && p->unk_06 == 0x78) || (obj != NULL && obj->unk_b24_0)) {
                done = TRUE;
            } else if (count != 0xffff) {
                if (--count == 0) {
                    done = TRUE;
                }
            }
            if (done || ((kind == 1 || kind == 0xb) && (data_02097dc8->unk_12 & 3))) {
                CmdObj_Done(self);
                if (kind >= 10) {
                    CmdObj_Push(self, 0x28, 0);
                }
            }
            self->unk_a4 = count;
        }
        return ret;
    }
    return done;
}
}
