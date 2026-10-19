#include "Main/Gfx/TextWin.h"
extern "C" {
#include "nitro/gx.h"
}
#include "nitro/gx_g3b.h"

extern "C" {

extern s32 FX_Div(s32 a, s32 b);
extern void *func_0203de84(u32 size, u32 align);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void DC_FlushRange(const void *start, u32 size);

// Builds the display list that draws the window's glyph texture as a (gradient) quad.
void func_0204eb3c(TextWin *win) {
    u32 buf[0x40];
    GXDLInfo dl;
    s32 w = (8 << win->unk_58) << 12;
    s32 h = (8 << win->unk_5c) << 12;
    if (win->unk_60 != -1) {
        if (win->unk_60 < w) {
            w = win->unk_60;
        }
        if (w == 0) {
            return;
        }
    }
    if (win->unk_64 != -1) {
        if (win->unk_64 < h) {
            h = win->unk_64;
        }
        if (h == 0) {
            return;
        }
    }
    G3_BeginMakeDL(&dl, buf, sizeof(buf));
    G3B_Scale(&dl, w, h, 0x1000);
    if (win->unk_78 != 0) {
        fx16 y;
        s32 split = (s32)win->unk_78;
        y = FX_Div(split, h);
        G3B_Begin(&dl, GX_BEGIN_QUAD_STRIP);
        G3B_Color(&dl, win->unk_74);
        G3B_TexCoord(&dl, w, 0);
        G3B_Vtx(&dl, 0x1000, 0, 0);
        G3B_TexCoord(&dl, 0, 0);
        G3B_VtxXY(&dl, 0, 0);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, w, split);
        G3B_VtxXY(&dl, 0x1000, y);
        G3B_TexCoord(&dl, 0, split);
        G3B_VtxXY(&dl, 0, y);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, w, h);
        G3B_VtxXY(&dl, 0x1000, 0x1000);
        G3B_TexCoord(&dl, 0, h);
        G3B_VtxXY(&dl, 0, 0x1000);
    } else {
        G3B_Begin(&dl, GX_BEGIN_QUADS);
        G3B_Color(&dl, win->unk_74);
        G3B_TexCoord(&dl, w, 0);
        G3B_Vtx(&dl, 0x1000, 0, 0);
        G3B_TexCoord(&dl, 0, 0);
        G3B_VtxXY(&dl, 0, 0);
        G3B_Color(&dl, win->unk_76);
        G3B_TexCoord(&dl, 0, h);
        G3B_VtxXY(&dl, 0, 0x1000);
        G3B_TexCoord(&dl, w, h);
        G3B_VtxXY(&dl, 0x1000, 0x1000);
    }
    win->unk_10 = G3_EndMakeDL(&dl);
    win->unk_0c = func_0203de84(win->unk_10, 4);
    MI_CpuCopy8(buf, win->unk_0c, win->unk_10);
    DC_FlushRange(win->unk_0c, win->unk_10);
}

}
