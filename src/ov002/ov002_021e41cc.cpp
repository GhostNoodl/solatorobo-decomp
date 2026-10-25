#include "ov002/ov002.h"

extern "C" {

/* A block shape on the puzzle grid (same layout as in ov002_021e3dac.cpp). */
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

/* Returns TRUE if shape `a` placed at `pa` and shape `b` placed at `pb`
 * share a set cell. The first shared cell goes to `out` (-1, -1 when
 * there is none). */
BOOL func_ov002_021e41cc(Vec2 *pa, Vec2 *pb, void *a, void *b, Vec2 *out) {
    GridShape *sa = (GridShape *)a;
    GridShape *sb = (GridShape *)b;
    s32 ma[4];
    s32 mb[4];
    int hit;
    u8 *ca;
    int na;
    u8 *cb;
    int oxa;
    int oya;
    int oxb;
    int oyb;
    u16 wa; /* `int` puts wa/wb in the wrong stack slots */
    int nb;
    s32 xa;
    u16 wb;
    s32 i;
    s32 j;
    s32 ya;
    s32 xb;
    s32 yb;
    hit = 0;
    func_ov002_021e391c(ma, sa->rot);
    func_ov002_021e391c(mb, sb->rot);
    oxa = sa->ox;
    ca = sa->cells;
    cb = sb->cells;
    oya = sa->oy;
    oxb = sb->ox;
    oyb = sb->oy;
    wa = sa->cols;
    na = wa * sa->rows;
    wb = sb->cols;
    nb = wb * sb->rows;
    for (i = 0; i < na; i++) {
        for (j = 0; j < nb; j++) {
            if (ca[i] == 1 && cb[j] == 1) {
                s32 dya = i / wa - oya;
                s32 dxa = i % wa - oxa;
                xa = (s32)(((s64)dxa * ma[0] + (s64)dya * ma[2]) >> 12);
                ya = (s32)(((s64)dxa * ma[1] + (s64)dya * ma[3]) >> 12);
                xa += pa->x;
                ya += pa->y;
                s32 dyb = j / wb - oyb;
                s32 dxb = j % wb - oxb;
                xb = (s32)(((s64)dxb * mb[0] + (s64)dyb * mb[2]) >> 12);
                yb = (s32)(((s64)dxb * mb[1] + (s64)dyb * mb[3]) >> 12);
                xb += pb->x;
                yb += pb->y;
                if (xa == xb && ya == yb) {
                    hit = 1;
                    goto end;
                }
            }
        }
    }
end:
    if (out != NULL) {
        if (hit) {
            out->x = xa;
            out->y = ya;
        } else {
            out->x = -1;
            out->y = -1;
        }
    }
    return hit;
}

}
