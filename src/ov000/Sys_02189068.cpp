#include "ov000/LoCommon.h"

extern "C" {
extern VObj *data_02fe152c;
extern VObj *data_02fe1530;
extern u8 *data_ov000_021ccd30;
BOOL func_0204c100(void);
BOOL func_0206facc(void);
BOOL func_0206ead8(void);
BOOL func_0204c120(void);
void func_0206faec(void);
void func_0206eaf8(void);

static inline BOOL HasMgr(void) {
    return data_02fe152c != NULL ? TRUE : FALSE;
}

static inline BOOL IsReady(u8 *c) {
    BOOL ok;
    if (LBIT(c, 0x114).b0) {
        ok = FALSE;
    } else if (LFLD(VObj *, c, 0x118) == NULL || LFLD(VObj *, c, 0x11c) == NULL) {
        ok = TRUE;
    } else {
        ok = TRUE;
        if (!LFLD(VObj *, c, 0x118)->vfunc_08()) {
            ok = FALSE;
        }
        if (!LFLD(VObj *, c, 0x11c)->vfunc_08()) {
            ok = FALSE;
        }
    }
    return ok;
}

BOOL func_ov000_02189068(void) {
    if (!HasMgr()) {
        return FALSE;
    }
    if (!data_02fe1530->vfunc_2c()) {
        return FALSE;
    }
    if (!func_0204c100()) {
        return FALSE;
    }
    if (!IsReady(data_ov000_021ccd30)) {
        return FALSE;
    }
    if (!func_0206facc()) {
        return FALSE;
    }
    if (!func_0206ead8()) {
        return FALSE;
    }
    data_02fe152c->vfunc_30();
    data_02fe1530->vfunc_30();
    func_0204c120();
    func_0206faec();
    func_0206eaf8();
    return TRUE;
}
}
