#include "ov002/ov002.h"

extern "C" {

/* Returns TRUE if `shape`, placed at `pos`, leaves `map` or overlaps one of
 * its set cells. The offending cell goes to `out`
 * (-1, -1 when there is none). */
int Ov002Shape_FitInMap(Vec2 *pos, Ov002Shape *map, Ov002Shape *sh, Vec2 *out) {
    s32 m[4];
    int hit;
    int cols;
    s32 j;
    long x; /* `s32 x` reorders the stack slots */
    s32 y;
    int rows;
    s32 i;
    int w;
    int h;
    int ox;
    int oy;
    hit = 0;
    Ov002_QuarterRotMtx(m, sh->rot);
    ox = sh->ox;
    w = map->w;
    rows = sh->h;
    oy = sh->oy;
    h = map->h;
    cols = sh->w;
    x = 0;
    y = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sh->grid[i * cols + j] == 1) {
                s32 dj = j - ox;
                s32 di = i - oy;
                x = (s32)(((s64)dj * m[0] + (s64)di * m[2]) >> 12);
                y = (s32)(((s64)dj * m[1] + (s64)di * m[3]) >> 12);
                x += pos->x;
                y += pos->y;
                if (x < 0 || y < 0 || x >= w || y >= h) {
                    hit = 1;
                    goto end;
                }
            }
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sh->grid[i * cols + j] == 1) {
                s32 dj = j - ox;
                s32 di = i - oy;
                x = (s32)(((s64)dj * m[0] + (s64)di * m[2]) >> 12);
                y = (s32)(((s64)dj * m[1] + (s64)di * m[3]) >> 12);
                x += pos->x;
                y += pos->y;
                if (map->grid[y * w + x] == 1) {
                    hit = 1;
                    goto end;
                }
            }
        }
    }
end:
    if (out != NULL) {
        if (hit) {
            out->y = y;
            out->x = x;
        } else {
            out->x = -1;
            out->y = -1;
        }
    }
    return hit;
}

}
