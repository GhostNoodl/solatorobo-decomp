#ifndef MAIN_SYS_FIELDID_H
#define MAIN_SYS_FIELDID_H

#include "types.h"

// A 3-byte id (compared and copied as a whole by the field code).
typedef struct FieldId {
    u8 c[3];
} FieldId;

#endif
