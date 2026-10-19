#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e4578(const Vec2 *pos, const Vec2 *d, void *a, void *b) {
    Vec2 p;
    Vec2 out;
    p.x = pos->x + d->x;
    p.y = pos->y + d->y;
    return !func_ov002_021e3dac(&p, a, b, &out);
}

BOOL func_ov002_021e45c4(void *self, void *list, void *a2) {
    Vec2 p;
    Vec2 q;
    p.x = FIELD(self, 0x54, s32);
    p.y = FIELD(self, 0x58, s32);
    if (func_ov002_021e3dac(&p, a2, (u8 *)self + 0x4c, NULL)) {
        return TRUE;
    }
    for (; list != NULL; list = FIELD(list, 0x70, void *)) {
        if (list == self) {
            continue;
        }
        q.x = FIELD(list, 0x54, s32);
        q.y = FIELD(list, 0x58, s32);
        if (func_ov002_021e41cc(&p, &q, (u8 *)self + 0x4c, (u8 *)list + 0x4c, 0)) {
            return TRUE;
        }
    }
    return FALSE;
}

}
