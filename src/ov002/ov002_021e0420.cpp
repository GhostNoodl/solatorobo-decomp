#include "ov002/ov002.h"

typedef struct Oam0488A01 {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
} Oam0488A01;

typedef struct Oam0488A23 {
    u32 chr : 10;
    u32 a2 : 22;
} Oam0488A23;

typedef struct Oam0488 {
    Oam0488A01 a01;
    Oam0488A23 a23;
} Oam0488;

extern "C" {

// Material callback: scales the polygon alpha by the fx32 the render object's ptrUser points to.
void Ov002_ScaleAlphaMatCb(NNSG3dRS *rs) {
    NNSG3dMatAnmResult *mat = rs->pMatAnmResult;
    s32 w = mat->prmPolygonAttr;
    s32 v = (s32)(((s64)*(s32 *)rs->pRenderObj->ptrUser * (((w & 0x1f0000) >> 16) << 12) + 0x800) >> 12) >> 12;
    mat->prmPolygonAttr = (w & ~0x1f0000) | ((u8)v << 16);
}

// onDecide of func_ov002_021dd6a4's list: stores the chosen item's id (-1: cancelled) at the owner.
BOOL func_ov002_021e046c(UiList *self, UiListItem *item) {
    s32 *out = (s32 *)self->owner;
    if (item != NULL) {
        *out = item->id;
    } else {
        *out = -1;
    }
    return FALSE;
}

// Draws a two-digit number per marked object as OAM cells (cell callback).
// The OAM type is two 4-byte attribute structs: the front end hoists tmpl.a23
// out of the object loop into a struct-typed temp, which can't live in a
// register, so it gets the unused sp+0x18 slot and the store-load pass then
// removes its accesses (round frA). The template is read through a pointer to
// the last cell (chr first), and the object's two positions are read into
// locals before the vector is built (round frB).
void Ov002_ProjectToScreen(s32 *out, s32 *v, void *m);

static inline void SetV0488(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

Oam0488 *func_ov002_021e0488(void *ctx, u16 *cell, Oam0488 *oam, u16 *num) {
    u16 n = *num;
    Oam0488 *last = &oam[n - 1];
    u32 chr = last->a23.chr;
    Oam0488 tmpl = *last;
    if (*cell == 6) {
        s32 mtx[16];
        u8 *o;
        n = 0;
        MTX_Copy43To44_((MtxFx43 *)data_02092844, (MtxFx44 *)mtx);
        MTX_Concat44((MtxFx44 *)mtx, (MtxFx44 *)data_02092800, (MtxFx44 *)mtx);
        for (o = FIELD(cell, 0x8, u8 *); o != NULL; o = FIELD(o, 0x70, u8 *)) {
            if (FIELD(o, 0x4a, u8) == 2) {
                u32 y;
                u32 val;
                BOOL shown;
                u32 k;
                s32 v[3] = {0, 0, 0};
                s32 x;
                s32 out[2];
                u32 div;
                s32 px = FIELD(o, 0x54, s32);
                s32 pz = FIELD(o, 0x58, s32);
                s32 ox = FIELD(o, 0x64, s32);
                s32 oz = FIELD(o, 0x68, s32);
                SetV0488(v, (px - ox) * 0x28f - 0xa3, 0, (pz - oz) * 0x28f - 0xa3);
                Ov002_ProjectToScreen(out, v, mtx);
                val = FIELD(o, 0xa8, u16);
                div = 1;
                for (k = 1; k < 2; k++) {
                    div *= 10;
                }
                shown = FALSE;
                if (val >= 100) {
                    val = 99;
                }
                x = out[0];
                y = (u16)out[1] & 0x1ff;
                for (k = 2; k > 0; k--) {
                    u32 d = val / div;
                    if ((k == 1 && !shown) || shown || d != 0) {
                        oam[n] = tmpl;
                        oam[n].a01.x = (u16)x;
                        oam[n].a01.y = y;
                        oam[n].a23.chr = chr - d;
                        n++;
                        if (n >= 0x80) {
                            break;
                        }
                        shown = TRUE;
                    }
                    val -= d * div;
                    div /= 10;
                    x += 8;
                }
            }
        }
    }
    *num = n;
    return oam;
}

}
