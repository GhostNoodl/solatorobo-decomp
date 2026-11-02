#include "ov002/ov002.h"

extern "C" {

static inline BOOL ov002_021d37f8_fade(void) {
    return (data_02097d78[3] == 4 || data_02097d78[1] == 4) ? TRUE : FALSE;
}
static inline bool ov002_021d37f8_idle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[1] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}
static inline BOOL ov002_021d37f8_on(void *p) {
    BOOL r;
    if (FIELD(p, 0x28, s32) != 1) {
        r = FALSE;
    } else {
        r = FIELD(p, 0x30, s32);
    }
    return r ? TRUE : FALSE;
}
static inline BOOL ov002_021d37f8_busy(FieldPlayer *t) {
    void *p = t->unk_118;
    if (p == NULL) {
        return FALSE;
    }
    return ov002_021d37f8_on(p) ? TRUE : FALSE;
}

static inline void ov002_021d37f8_stop(FieldPlayer *t) {
    if (t->unk_118 != NULL) {
        func_ov000_0216f844(t->unk_118, 0);
    }
}

void func_ov002_021d37f8(Task021ef91c *self) {
    void *res;
    void *m;
    if (self->unk_c4 != NULL) {
        return;
    }
    if (self->unk_c8 == NULL) {
        return;
    }
    res = (void *)self->unk_c8->vfunc_10();
    if (res == NULL) {
        return;
    }
    if (!func_ov002_isMode4b() && !ov002_021d37f8_idle()) {
        return;
    }
    if (data_ov000_021ccd30 != NULL && ov002_021d37f8_busy(data_ov000_021ccd30)) {
        ov002_021d37f8_stop(data_ov000_021ccd30);
        return;
    }
    func_0203cc58(0, 0, 1);
    func_0203cb78(0xc000, 0, 1);
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        func_02041218((PlttRes *)((u8 *)m + 0x88));
        func_02041440((Model *)m, NULL, 0);
    }
    self->unk_c4 = (Model *)m;
    func_020417e0((Model *)m, res);
    self->unk_c4->flags |= 2;
    self->unk_c4->unk_150 = -0x2000;
    func_02041d9c((Model *)self->unk_c4, 2, 0);
}

}
