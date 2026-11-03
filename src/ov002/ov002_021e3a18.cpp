#include "ov002/ov002.h"

extern "C" {

void Ov002_RotateAbout(Vec2 *out, int rot, Vec2 *a, Vec2 *b, Vec2 *c) {
    s32 m[4];
    s32 dx;
    s32 dy;
    Vec2 t;
    Ov002_QuarterRotMtx(m, rot);
    dy = a->y - b->y;
    dx = a->x - b->x;
    t = *c;
    out->x = (s32)(((s64)dx * m[0] + (s64)dy * m[2]) >> 12);
    out->y = (s32)(((s64)dx * m[1] + (s64)dy * m[3]) >> 12);
    out->x += t.x;
    out->y += t.y;
}

}
