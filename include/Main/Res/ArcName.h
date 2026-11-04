#ifndef MAIN_RES_ARCNAME_H
#define MAIN_RES_ARCNAME_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pointers in Main's .data to archive / file name strings, passed as the name arguments of the ResArc
// functions (ResMgr_Load, ResMgr_IsLoaded, ResMgr_GetArcList, ResMgr_ReleaseByName) and of TexObj_Init / STD_CopyString
// when a Model is built.
extern const char *ResName_CommonCells;
extern const char *ResName_CommonModel;
extern const char *ResName_TextCells;
extern const char *ResName_WifiCells;
extern const char *ResName_BattleCells;
extern const char *ArcPath_MenuWifi;
extern const char *ArcPath_MenuBattle;
extern const char *ArcPath_MenuLoad;
extern const char *ArcPath_Menu;

#ifdef __cplusplus
}
#endif

#endif
