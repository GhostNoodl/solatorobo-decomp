#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov009_02215d0c[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009Actor *self);
extern void func_ov009_02201eac(Ov009Actor *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022013ac(Ov009Actor *self) {
    Ov009Actor *a = Ov009_FindActor(FLD(u16, self, 0xf4));
    if (a != NULL) {
        func_ov000_0218d46c(a, FLD(u16, self, 0xf4), 0x15);
        FLD(u16, self, 0xf4) = 0xffff;
    }
    func_ov003_021d6054(self);
}

static inline void Ov009_PlayAnim(Ov009Sub38 *m, void *anim) {
    if (FLD(void *, m, 0x1c) != NULL) {
        func_ov000_0218fa28(m, &FLD(u8, m, 0x24), FLD(u8 *, m, 0), FLD(void *, FLD(u8 *, FLD(u8 *, m, 0), 0x48), 0x10), anim, 0x1000, 0);
    }
}

}
