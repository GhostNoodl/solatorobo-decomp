#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3aa0(Vec2 *out, const s32 *m, const Vec2 *a, const Vec2 *b, const Vec2 *c) {
    s32 dx;
    s32 dy;
    Vec2 t;
    t = *c;
    dy = a->y - b->y;
    dx = a->x - b->x;
    out->x = (s32)(((s64)dx * m[0] + (s64)dy * m[2]) >> 12);
    out->y = (s32)(((s64)dx * m[1] + (s64)dy * m[3]) >> 12);
    out->x += t.x;
    out->y += t.y;
}

}
