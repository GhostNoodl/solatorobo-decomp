#include "ov000/LoCommon.h"
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
s32 func_ov000_02180838(void *a);
void TexObj_SetAllOamFuncs(void *obj, void *value);
void func_02041c18(void *obj, s32 value);
u8 *Param_GetEntry(u16 id);
void UiList_DrawItemIcon(void *self, void *msg, s32 c, s32 d, u8 e, u8 f);
void *func_ov000_02161bc4(void *self, s32 unused, void *g, u16 *count);

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
struct Obj02161c14 {
    u8 unk_00[0xb8];
    void *unk_b8;
};

void Ov000Vt_021cb2a8_DrawItemIcon(Obj02161c14 *self, void *msg, s32 c, s32 d, u8 e, u8 f) {
    s32 v;
    if (self->unk_b8 == NULL || LFLD(u16, msg, 8) == 0xffff) {
        return;
    }
    TexObj_SetAllOamFuncs(self->unk_b8, (void *)func_ov000_02161bc4);
    if (((u32)(LFLD(u16, msg, 6) << 4) >> 16) - 1 == 1) {
        func_02041c18(self->unk_b8, *Param_GetEntry(LFLD(u16, msg, 6)));
    } else {
        func_02041c18(self->unk_b8, 0);
    }
    UiList_DrawItemIcon(self, msg, c, d, e, f);
    TexObj_SetAllOamFuncs(self->unk_b8, NULL);
    func_02041c18(self->unk_b8, 0);
}

}
