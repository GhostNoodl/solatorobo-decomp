#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

class VObjB {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void vfunc_38(s32 a);
};

typedef struct {
    u8 pad_00[0x14];
    VObj *unk_14;
    u8 unk_18;
} Obj02182524;

static inline BOOL IsActive(VObj *p) {
    return LFLD(u8, p, 0x5a) != 0 ? TRUE : FALSE;
}

extern "C" {
void func_0206228c(void);

void func_ov000_02182524(Obj02182524 *self) {
    if (self->unk_14 == NULL) {
        return;
    }
    if (self->unk_18 != 0) {
        self->unk_14->vfunc_38(1);
    } else {
        ((VObjB *)self->unk_14)->vfunc_38(1);
    }
    if (!IsActive(self->unk_14)) {
        self->unk_14 = NULL;
        self->unk_18 = 0;
    }
    if (self->unk_14 == NULL) {
        func_0206228c();
    }
}
}
