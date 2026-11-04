#include "types.h"
#include "ov000/SceneRes.h"

typedef struct {
    s32 v[4];
} FadeParam;

extern "C" {

void Tbl_MakeFacePath(s32 a, FadeParam *out);
void Tbl_MakeFaceName(s32 a, FadeParam *out, s32 b, s32 c);
void ResMgr_LoadArchive(FadeParam *a, FadeParam *b, s32 c, s32 d);
void ResMgr_ReleaseArchive(FadeParam *a, FadeParam *b, s32 c);
BOOL ResMgr_IsArchiveLoaded(FadeParam *a, FadeParam *b, s32 c);

void FaceIcon_LoadPlayer(void) {
    FadeParam a;
    FadeParam b;

    Tbl_MakeFacePath(0x1000, &a);
    Tbl_MakeFaceName(0x1000, &b, 1, 2);
    ResMgr_LoadArchive(&a, &b, 2, 0);
    gSceneResSet.unk_00 = 1;
}

void FaceIcon_ReleasePlayer(void) {
    FadeParam a;
    FadeParam b;

    Tbl_MakeFacePath(0x1000, &a);
    Tbl_MakeFaceName(0x1000, &b, 1, 2);
    ResMgr_ReleaseArchive(&a, &b, 2);
    gSceneResSet.unk_00 = 0;
}

BOOL FaceIcon_IsPlayerLoaded(void) {
    FadeParam a;
    FadeParam b;
    BOOL ret = TRUE;

    Tbl_MakeFacePath(0x1000, &a);
    Tbl_MakeFaceName(0x1000, &b, 1, 2);
    if (!ResMgr_IsArchiveLoaded(&a, &b, 2)) {
        ret = FALSE;
    }
    return ret;
}

}
