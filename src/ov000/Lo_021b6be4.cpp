#include "types.h"
#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern u8 *data_ov000_021ccd54;
u16 func_0204bfa8(void *cam);
void func_0204b924(void *p, s32 v);

typedef struct {
    s32 a, b, c;
} Ent0218c25c;

static inline BOOL IsBusy021b6be4(u8 *m) {
    return LFLD(s32, m, 0x90) != LFLD(s32, m, 0x94) ? TRUE : FALSE;
}

static inline BOOL IsIdle021b6be4(u8 *m) {
    BOOL r;
    if (m != NULL) {
        if (IsBusy021b6be4(m)) {
            r = FALSE;
        } else if (LFLD(s32, m, 0) != 3) {
            r = FALSE;
        } else {
            r = TRUE;
        }

    } else {
        r = TRUE;
    }
    return r;
}

void func_ov000_021b6be4(u8 *self) {
    u8 *m;
    u8 *s;
    if (LFLD(s16, self, 0x1f2) == 0) {
        return;
    }
    m = data_ov000_021ccd54;
    s = m + 0xf4;
    if (s == NULL) {
        return;
    }
    {
        s32 v = 0x1000;
        if (!IsIdle021b6be4(m)) {
            v = 0;
        }
        func_0204b924(s, v);
    }
}
}
