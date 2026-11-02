#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/SceneRes.h"

typedef struct {
    s32 v[4];
} LoFadeP;

typedef struct {
    u16 lo : 12;
    u16 hi : 4;
} LoU16Hi;
typedef struct { u32 a : 28; u32 k : 4; } LoW28;
typedef struct { u32 a : 12; u32 k : 16; } LoW12;

extern "C" {
extern void *data_ov000_021ccd44;
extern u8 data_ov000_021c9b28[];
void func_020708fc(s32 a, LoFadeP *out);
void func_02070b98(s32 a, LoFadeP *out, s32 b, s32 c);
BOOL ResMgr_IsArchiveLoaded(LoFadeP *a, LoFadeP *b, s32 c);
BOOL StageRes_IsAllLoaded(void *p);
u32 func_ov000_02180838(void *a);
void func_02041c5c(void *obj, void *value);
void func_02041c18(void *obj, s32 value);
u8 *Param_GetEntry(u16 id);

static inline BOOL LoFadeDone(void) {
    LoFadeP a;
    LoFadeP b;
    BOOL ret = TRUE;
    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    if (!ResMgr_IsArchiveLoaded(&a, &b, 2)) {
        ret = FALSE;
    }
    return ret;
}

static inline BOOL LoResReady(void) {
    BOOL ret = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd24.unk_08)) {
        ret = FALSE;
    }
    return ret;
}

static inline u32 LoIdKind(u32 id) { return (id << 4) >> 16; }
static inline u32 LoIdKind2(u16 id) { u32 r = (u32)(id << 4) >> 16; return r; }
BOOL Lo021caa44_IsLoaded(Lo021caa44 *self) {
    BOOL ok = TRUE;
    if (!LoFadeDone()) {
        ok = FALSE;
    }
    if (!LoResReady()) {
        ok = FALSE;
    }
    if (!self->unk_3c->vfunc_2c()) {
        ok = FALSE;
    }
    if (!func_ov000_02180838(data_ov000_021ccd44)) {
        ok = FALSE;
    }
    return ok;
}

}
