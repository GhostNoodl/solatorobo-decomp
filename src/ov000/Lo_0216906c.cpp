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
extern void *gTaskHost;
extern u8 data_ov000_021c9b28[];
void func_020708fc(s32 a, LoFadeP *out);
void func_02070b98(s32 a, LoFadeP *out, s32 b, s32 c);
BOOL ResMgr_IsArchiveLoaded(LoFadeP *a, LoFadeP *b, s32 c);
BOOL StageRes_IsAllLoaded(void *p);
s32 func_ov000_02180838(void *a);
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);
void TexObj_SetAllOamFuncs(void *obj, void *value);
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
    if (!StageRes_IsAllLoaded(gSceneResSet.unk_08)) {
        ret = FALSE;
    }
    return ret;
}

static inline u32 LoIdKind(u32 id) { return (id << 4) >> 16; }
static inline u32 LoIdKind2(u16 id) { u32 r = (u32)(id << 4) >> 16; return r; }
void Lo021cb840_PostUpdate(Lo021cb840 *self) {
    s32 s = self->unk_04;
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 2;
        }
    }
    if (self->unk_04 == 0xa) {
        if (!((self->unk_0c & 0x10000) ? TRUE : FALSE)) {
            self->unk_0c_1 = 1;
        }
        self->unk_0c_16 = 0;
    }
    if (self->unk_a8 >= 3) {
        return;
    }
    Obj0215fdfc_SetEntry(self, 1, data_ov000_021c9b28 + self->unk_a8 * 6);
    Obj0215fdfc_SetEntry(self, 2, data_ov000_021c9b28 + (self->unk_a8 + 1) * 6);
}

}
