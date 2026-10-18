#include "types.h"

typedef s32 (*FilterFunc)(s32 value);

typedef struct {
    u8 unk_00[0x10];
    FilterFunc fn_10;
    u8 unk_14[0x4];
    FilterFunc fn_18;
} Filter;

s32 func_ov000_0219a874(Filter *a, Filter *b, s32 value) {
    if (b != NULL && b->fn_10 != NULL) {
        value = b->fn_10(value);
    }
    if (a != NULL && a->fn_18 != NULL) {
        value = a->fn_18(value);
    }
    return value;
}
