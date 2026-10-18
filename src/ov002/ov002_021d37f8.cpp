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
static inline BOOL ov002_021d37f8_busy(void *t) {
    void *p = FIELD(t, 0x118, void *);
    if (p == NULL) {
        return FALSE;
    }
    return ov002_021d37f8_on(p) ? TRUE : FALSE;
}

static inline void ov002_021d37f8_stop(void *t) {
    if (FIELD(t, 0x118, void *) != NULL) {
        func_ov000_0216f844(FIELD(t, 0x118, void *), 0);
    }
}

void func_ov002_021d37f8(void *self) {
    void *res;
    void *m;
    if (FIELD(self, 0xc4, void *) != NULL) {
        return;
    }
    if (FIELD(self, 0xc8, VObject *) == NULL) {
        return;
    }
    res = (void *)FIELD(self, 0xc8, VObject *)->v0x10();
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
    m = func_0203dd9c(0x160);
    if (m != NULL) {
        func_02041218((u8 *)m + 0x88);
        func_02041440(m, NULL, 0);
    }
    FIELD(self, 0xc4, void *) = m;
    func_020417e0(m, res);
    FIELD(FIELD(self, 0xc4, void *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0xc4, void *), 0x150, s32) = -0x2000;
    func_02041d9c(FIELD(self, 0xc4, void *), 2, 0);
}

}
