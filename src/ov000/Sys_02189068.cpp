#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"

extern "C" {
extern VObj *gDataRes;
extern VObj *gStageDataRes;
extern MessageQueue021cb980 *gMessageQueue;
BOOL MsgRes_LoadGlobal(void);
BOOL LangRes2_Load(void);
BOOL Param_LoadRes(void);
BOOL MsgRes_BindGlobal(void);
void LangRes2_BindTables(void);
void Param_BindTables(void);

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

BOOL GlobalRes_Load(void *self) {
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
    if (!LangRes2_Load()) {
        return FALSE;
    }
    if (!Param_LoadRes()) {
        return FALSE;
    }
    gDataRes->vfunc_30();
    gStageDataRes->vfunc_30();
    MsgRes_BindGlobal();
    LangRes2_BindTables();
    Param_BindTables();
    return TRUE;
}
}
