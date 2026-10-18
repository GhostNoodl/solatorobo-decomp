#include "ov002/ov002.h"

extern "C" {

typedef struct Ev021d7320 {
    s16 time;
    s16 unk_02;
    u16 id;
} Ev021d7320;

void func_ov002_021d7320(void *self, s32 t, s32 range) {
    Ev021d7320 *p = FIELD(self, 0x64, Ev021d7320 *);
    s32 v;
    if (p == NULL || FIELD(self, 0x60, Ev021d7320 *) == NULL) {
        return;
    }
    if (FIELD(self, 0x5d, u8)) {
        v = p->time << 12;
        while (v >= 0 && v < t) {
            func_02049a48(data_02097e4c, p->id, -1, -1, -1);
            p = ++FIELD(self, 0x64, Ev021d7320 *);
            v = p->time << 12;
        }
    } else {
        s32 lo = t - range;
        v = p->time << 12;
        while (v < t && v >= lo) {
            func_02049a48(data_02097e4c, p->id, -1, -1, -1);
            if (FIELD(self, 0x64, Ev021d7320 *) == FIELD(self, 0x60, Ev021d7320 *)) {
                return;
            }
            p = --FIELD(self, 0x64, Ev021d7320 *);
            v = p->time << 12;
        }
    }
}

}
