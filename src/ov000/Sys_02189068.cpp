#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {
extern VObj *gDataRes;
extern VObj *gStageDataRes;
extern MessageQueue021cb980 *gMessageQueue;
BOOL MsgRes_LoadGlobal(void);
BOOL func_0206facc(void);
BOOL func_0206ead8(void);
BOOL MsgRes_BindGlobal(void);
void func_0206faec(void);
void func_0206eaf8(void);

static inline BOOL HasMgr(void) {
    return gDataRes != NULL ? TRUE : FALSE;
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
    if (!gStageDataRes->vfunc_2c()) {
        return FALSE;
    }
    if (!MsgRes_LoadGlobal()) {
        return FALSE;
    }
    if (!IsReady(gMessageQueue)) {
        return FALSE;
    }
    if (!func_0206facc()) {
        return FALSE;
    }
    if (!func_0206ead8()) {
        return FALSE;
    }
    gDataRes->vfunc_30();
    gStageDataRes->vfunc_30();
    MsgRes_BindGlobal();
    func_0206faec();
    func_0206eaf8();
    return TRUE;
}
}
