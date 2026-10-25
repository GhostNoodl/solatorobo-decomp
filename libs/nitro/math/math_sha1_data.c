// math_sha1.c's .data: the block function MATH_SHA1Update calls, switched to the overlay-digest
// variant while overlay tables are hashed. A data-only file so the matched math_sha1.c is left as
// it is; it links right after math_sha1.c.

#include "math_sha1.h"

typedef void (*MATHiSHA1ProcessBlockFunc)(MATHSHA1Context *context);

void MATHi_SHA1ProcessBlock(MATHSHA1Context *context);

MATHiSHA1ProcessBlockFunc MATHi_SHA1ProcessBlockFunc = MATHi_SHA1ProcessBlock;
