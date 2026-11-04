#include "ov000/VObj.h"
#include "Main/Sys/FieldState.h"
#include "Main/Res/ResMgr.h"

#include "ov000/FieldMgr.h"

extern "C" {

u8 *LangBlockA_GetData(LangBlockA *p);
u8 *LangBlockA_GetData1(LangBlockA *p);
void *ResMgr_GetArcList(void *e);
void *Path_SkipDir(void *e);
void **ResList_FindType5(void *m, void *k);
void **ResList_FindType4(void *m, void *k);
void Vram_FreeRes(void *p);
void ResMgr_ReleaseByName(void *a, void *e, s32 b, s32 c);
LangGroup *Lang_GetGroup(int id);
void LangData_MakeRadarPath(void *buf, u8 *p);
void LangData_MakeAreaInfoPath(void *buf, u8 *p);
void ResMgr_ReleaseArchive(const char *name, void *buf, s32 b);

void FieldMgr_LoadBlockArchives(FieldMgr *self, u8 arg) {
    u8 *e;
    s32 i;
    u8 *p;
    LangGroup *t;
    u8 buf[0x20];
    if (self->blockA == NULL) {
        return;
    }
    e = LangBlockA_GetData(self->blockA);
    if (e != NULL) {
        for (i = 0; i < self->blockA->count0; i++, e += 0x18) {
            void *m = ResMgr_GetArcList(e);
            if (m != NULL) {
                void *k = Path_SkipDir(e);
                void **r = ResList_FindType5(m, k);
                if (r != NULL) {
                    Vram_FreeRes(*r);
                } else {
                    r = ResList_FindType4(m, k);
                    if (r != NULL) {
                        Vram_FreeRes(*r);
                    }
                }
            }
            ResMgr_ReleaseByName(gResMgr, e, 7, 0);
        }
    }
    e = LangBlockA_GetData1(self->blockA);
    if (e != NULL) {
        for (i = 0; i < self->blockA->count1; i++, e += 0x18) {
            ResMgr_ReleaseByName(gResMgr, e, 7, 0);
        }
    }
    p = gSceneCmd->unk_d0.c;
    if (arg || p[0] == 0xff || p[1] == 0xff || p[2] == 0xff) {
        p = gSceneCmd->unk_ca.c;
    }
    t = Lang_GetGroup(p[0]);
    LangData_MakeRadarPath(buf, p);
    ResMgr_ReleaseArchive(t->unk_08, buf, 0);
    LangData_MakeAreaInfoPath(buf, p);
    ResMgr_ReleaseArchive(t->unk_08, buf, 0);
    self->blockA = NULL;
    self->unk_0c = NULL;
}

}
