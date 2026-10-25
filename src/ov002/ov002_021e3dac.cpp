#include "ov002/ov002.h"

extern "C" {

/* A block shape on the puzzle grid: a cols x rows cell mask with a pivot
 * (ox, oy) and a quarter-turn rotation. */
typedef struct GridShape {
    u8 *cells;
    u16 pad : 8;
    u16 cols : 4;
    u16 rows : 4;
    u16 ox : 4;
    u16 oy : 4;
    u16 rot : 2;
    u16 pad2 : 6;
} GridShape;

/* The grid itself: a w x h cell mask. */
typedef struct GridMap {
    u8 *cells;
    u16 pad : 8;
    u16 w : 4;
    u16 h : 4;
} GridMap;

/* Returns TRUE if the shape `b`, placed at `pos`, leaves the map `a` or
 * overlaps one of its set cells. The offending cell goes to `out`
 * (-1, -1 when there is none). */
int func_ov002_021e3dac(Vec2 *pos, void *a, void *b, Vec2 *out) {
    GridMap *map = (GridMap *)a;
    GridShape *sh = (GridShape *)b;
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
    func_ov002_021e391c(m, sh->rot);
    ox = sh->ox;
    w = map->w;
    rows = sh->rows;
    oy = sh->oy;
    h = map->h;
    cols = sh->cols;
    x = 0;
    y = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (sh->cells[i * cols + j] == 1) {
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
            if (sh->cells[i * cols + j] == 1) {
                s32 dj = j - ox;
                s32 di = i - oy;
                x = (s32)(((s64)dj * m[0] + (s64)di * m[2]) >> 12);
                y = (s32)(((s64)dj * m[1] + (s64)di * m[3]) >> 12);
                x += pos->x;
                y += pos->y;
                if (map->cells[y * w + x] == 1) {
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
