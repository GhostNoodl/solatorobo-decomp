#ifndef MAIN_RES_RESARC_H
#define MAIN_RES_RESARC_H

#include "Main/Res/ResMgr.h"

// Archive loading in ResMgr.cpp (declared at their defining types). Kept out of ResMgr.h, which many
// TUs include next to their own older prototypes of these functions.
#ifdef __cplusplus
extern "C" {
#endif

ResNode *func_020359d0(const char *name, int type, u8 toFront);
BOOL func_02035b90(const char *name, int type);
ResList *func_02035d5c(const char *name);
void func_02036838(ResMgr *mgr, const char *name, int type, BOOL force);

#ifdef __cplusplus
}
#endif

#endif
