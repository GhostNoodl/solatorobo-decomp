#include "ov010/ov010.h"

class Ov010Fx {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    s32 timer;
    s32 scale;
};

extern "C" {

extern u8 data_ov010_0220fe30[];
extern Ov010Fx *func_02065f88(s32 a, void *b);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
void func_ov010_02203f08(Ov010Fx *fx);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

void func_ov010_02203ff4(void *self) {
    if (FLD(void *, self, 0x38) == NULL) {
        return;
    }
    func_ov000_02190a80(FLD(void *, self, 0x38), func_0203db40((u8 *)self + 0x24));
}

void func_ov010_02204020(void) {
}

void func_ov010_02204024(void) {
}

void func_ov010_02204028(void) {
}

void func_ov010_0220402c(void) {
}

}
