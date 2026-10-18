#include "ov000/CmdObj.h"
#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
    u8 unk_b28_3 : 5;
} Obj0219bf90;

extern "C" {
extern s32 data_02097d78[];
Obj0219bf90 *func_ov000_0219bf90(void);
VObj *func_ov000_0219bfbc(void *p);
void *func_0203dd9c(u32 size);
s32 func_0206ffa0(s32 a);
void func_ov000_0218d1c0(void *self, u16 id, u16 kind, s32 arg);
BOOL func_ov000_0219c86c(Obj0219bf90 *self);

static inline BOOL IsMode3(void) {
    BOOL r;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 3;
    }
    return r;
}

static inline void Wake0219bf90(void) {
    Obj0219bf90 *p = func_ov000_0219bf90();
    if (p == NULL) {
        return;
    }
    if (p->unk_b28_0 != 0) {
        return;
    }
    p->unk_15 = 3;
    p->unk_b28_0 = 0;
    p->unk_b28_2 = 1;
}

s32 func_ov000_021845cc(CmdObj *self) {
    Obj0219bf90 *cur = func_ov000_0219bf90();
    switch (self->step) {
    case 0:
        self->step++;
        return 0;
    case 1:
        if (IsMode3()) {
            break;
        }
        if (cur == NULL) {
            VObj *obj = (VObj *)func_0203dd9c(0xbb0);
            if (obj != NULL) {
                obj = func_ov000_0219bfbc(obj);
            }
            func_ov000_0218d1c0(obj, 0x1000, 0x1000, func_0206ffa0(0x1000));
            obj->vfunc_04();
            Wake0219bf90();
        } else {
            Wake0219bf90();
        }
        self->step++;
        break;
    case 2:
        if (cur == NULL) {
            return 1;
        }
        if (func_ov000_0219c86c(cur) == 1 && cur->unk_b28_0 == 0) {
            if ((self->rd != self->index ? TRUE : FALSE)) {
                Wake0219bf90();
            }
            CmdObj_Done(self);
        }
        break;
    }
    return 1;
}
}
