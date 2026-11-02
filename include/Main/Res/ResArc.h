#ifndef MAIN_RES_RESARC_H
#define MAIN_RES_RESARC_H

#include "Main/Res/ResMgr.h"

// Archive loading in ResMgr.cpp (declared at their defining types). Kept out of ResMgr.h, which many
// TUs include next to their own older prototypes of these functions.
#ifdef __cplusplus
extern "C" {
#endif

ResNode *ResMgr_Load(const char *name, int type, u8 toFront);
BOOL ResMgr_IsLoaded(const char *name, int type);
ResList *ResMgr_GetArcList(const char *name);
void *ResList_FindType2(void *list, const void *name);
void ResMgr_ReleaseByName(ResMgr *mgr, const char *name, int type, BOOL force);

#ifdef __cplusplus
}
#endif

#endif
