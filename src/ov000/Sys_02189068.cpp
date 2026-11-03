#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {
extern VObj *data_02fe152c;
extern VObj *data_02fe1530;
extern MessageQueue021cb980 *data_ov000_021ccd30;
BOOL func_0204c100(void);
BOOL func_0206facc(void);
BOOL func_0206ead8(void);
BOOL func_0204c120(void);
void func_0206faec(void);
void func_0206eaf8(void);

static inline BOOL HasMgr(void) {
    return data_02fe152c != NULL ? TRUE : FALSE;
}

static inline BOOL IsReady(MessageQueue021cb980 *c) {
    BOOL ok;
    if (c->flag0) {
        ok = FALSE;
    } else if (c->unk_118 == NULL || c->unk_11c == NULL) {
        ok = TRUE;
    } else {
        ok = TRUE;
        if (!c->unk_118->vfunc_08()) {
            ok = FALSE;
        }
        if (!c->unk_11c->vfunc_08()) {
            ok = FALSE;
        }
    }
    return ok;
}

BOOL func_ov000_02189068(void *self) {
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
