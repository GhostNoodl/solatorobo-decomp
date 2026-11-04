#include "ov002/ov002.h"

extern "C" {

/* Returns TRUE if shape `a` placed at `pa` and shape `b` placed at `pb`
 * share a set cell. The first shared cell goes to `out` (-1, -1 when
 * there is none). */
BOOL Ov002Shape_Overlaps(Vec2 *pa, Vec2 *pb, Ov002Shape *sa, Ov002Shape *sb, Vec2 *out) {
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
    Ov002_QuarterRotMtx(ma, sa->rot);
    Ov002_QuarterRotMtx(mb, sb->rot);
    oxa = sa->ox;
    ca = sa->grid;
    cb = sb->grid;
    oya = sa->oy;
    oxb = sb->ox;
    oyb = sb->oy;
    wa = sa->w;
    na = wa * sa->h;
    wb = sb->w;
    nb = wb * sb->h;
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
