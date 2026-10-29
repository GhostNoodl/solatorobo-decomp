#ifndef NITRO_STD_H
#define NITRO_STD_H

// String helpers (NitroSDK std/string.h), defined in libs/nitro/std.
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

char *STD_CopyString(char *destp, const char *srcp);
int STD_CopyLStringZeroFill(char *destp, const char *srcp, int n);
int STD_CopyLString(char *destp, const char *srcp, int siz);
char *STD_SearchString(const char *srcp, const char *str);
int STD_GetStringLength(const char *str);
char *STD_ConcatenateString(char *str1, const char *str2);
int STD_CompareString(const char *str1, const char *str2);
int STD_CompareNString(const char *str1, const char *str2, int len);

#ifdef __cplusplus
}
#endif

#endif
