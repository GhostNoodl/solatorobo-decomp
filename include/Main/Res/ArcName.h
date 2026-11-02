#ifndef MAIN_RES_ARCNAME_H
#define MAIN_RES_ARCNAME_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pointers in Main's .data to archive / file name strings, passed as the name arguments of the ResArc
// functions (ResMgr_Load, ResMgr_IsLoaded, ResMgr_GetArcList, ResMgr_ReleaseByName) and of TexObj_Init / STD_CopyString
// when a Model is built.
extern const char *data_0208cb74;
extern const char *data_0208cb78;
extern const char *data_0208cb7c;
extern const char *data_0208cb84;
extern const char *data_0208cc88;
extern const char *data_0208cc8c;
extern const char *data_0208cc94;
extern const char *data_0208cc9c;
extern const char *data_0208cca0;

#ifdef __cplusplus
}
#endif

#endif
