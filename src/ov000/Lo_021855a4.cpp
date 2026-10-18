#include "ov000/CmdObj.h"

typedef struct {
    u8 pad_00[0x118];
    void *unk_118;
    void *unk_11c;
} Mgr021ccd30;

extern "C" {
extern Mgr021ccd30 *data_ov000_021ccd30;
void func_ov000_0216f844(void *p, s32 a);
BOOL func_ov000_0216f674(Mgr021ccd30 *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
BOOL func_ov000_021700d8(void *p);
BOOL func_ov000_021700ec(void *p);
s32 func_ov000_02170100(void *p);

static inline BOOL Busy11(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 6)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700c4(m->unk_11c);
    }
    return r;
}

static inline BOOL Busy12(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 7)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700d8(m->unk_11c);
    }
    return r;
}

static inline BOOL Busy13(void) {
    BOOL r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 8)) {
        r = TRUE;
    } else if (m->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700ec(m->unk_11c);
    }
    return r;
}

static inline s32 State11c(void) {
    s32 r;
    Mgr021ccd30 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = -1;
    } else if (m->unk_11c == NULL) {
        r = -1;
    } else {
        r = func_ov000_02170100(m->unk_11c);
    }
    return r;
}

s32 func_ov000_021855a4(CmdObj *self) {
    switch (self->unk_98) {
    case 0x11:
        switch (self->step) {
        case 0:
            if (data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
            }
            self->step++;
            return 0;
        case 1:
            if (Busy11()) {
                switch (State11c()) {
                case 3:
                    return 0;
                default:
                    return 1;
                }
            }
            CmdObj_Done(self);
            break;
        }
        break;
    case 0x12:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (Busy12()) {
                return 0;
            }
            CmdObj_Done(self);
            break;
        }
        break;
    case 0x13:
        switch (self->step) {
        case 0:
            self->step++;
            return 0;
        case 1:
            if (Busy13()) {
                return 1;
            }
            CmdObj_Done(self);
            break;
        }
        break;
    }
    return 0;
}
}
