#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    u8 unk_04[0x8];
    s32 unk_0c;
} Data02097d78;

extern "C" {

extern Data02097d78 data_02097d78;
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL IsMode(s32 mode) {
    return data_02097d78.unk_0c == mode ? TRUE : (data_02097d78.unk_00 == mode ? TRUE : FALSE);
}

static inline BOOL IsIdle(void) {
    return data_02097d78.unk_0c == 0 && data_02097d78.unk_00 == 0;
}

BOOL func_ov000_02184498(void *self) {
    if (IsMode(4)) {
        func_0203cb78(0xa000, 0, 0);
    }
    if (!IsIdle()) {
        return FALSE;
    }
    return TRUE;
}

}
