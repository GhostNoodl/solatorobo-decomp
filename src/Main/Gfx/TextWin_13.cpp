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

extern void func_0203df0c(void *ptr);
extern BOOL func_0203e63c(void *task);
extern void func_02043d20(void *p, int a);

extern void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern void NNS_G3dGeSendDL(const void *dl, u32 size);
extern void func_0204e5d4(TextWin *win);

static inline void TW_PolygonAttr(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc) {
    u32 data = light | (polyMode << 4) | (cullMode << 6) | misc | (polygonId << 24) | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &data, 1);
}

static inline void TW_TexImageParam(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr) {
    u32 data = (addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) | (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29);
    NNS_G3dGeBufferOP_N(0x2a, &data, 1);
}

static inline void TW_TexPlttBase(u32 addr) {
    u32 data = addr >> 4;
    NNS_G3dGeBufferOP_N(0x2b, &data, 1);
}

static inline u32 TW_PlttAddr(void *key) {
    return ((u32)key & 0xffff) << 3;
}

static inline void TW_PushMtx(void) {
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
}

static inline void TW_Translate(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, data, 3);
}

static inline void TW_Scale(s32 x, s32 y, s32 z) {
    s32 data[3];
    data[0] = x;
    data[1] = y;
    data[2] = z;
    NNS_G3dGeBufferOP_N(0x1b, data, 3);
}

static inline void TW_Begin(u32 prim) {
    u32 data = prim;
    NNS_G3dGeBufferOP_N(0x40, &data, 1);
}

static inline void TW_End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

static inline void TW_Color(u32 color) {
    u32 data = color;
    NNS_G3dGeBufferOP_N(0x20, &data, 1);
}

static inline void TW_TexCoord(s32 s, s32 t) {
    u32 data = (u16)(s16)(s >> 8) | ((u16)(s16)(t >> 8) << 16);
    NNS_G3dGeBufferOP_N(0x22, &data, 1);
}

static inline void TW_Vtx(s16 x, s16 y, s16 z) {
    u32 data[2];
    data[0] = (u16)x | ((u16)y << 16);
    data[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, data, 2);
}

static inline void TW_VtxXY(s16 x, s16 y) {
    u32 data = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &data, 1);
}

static inline void TW_PopMtx(s32 num) {
    NNS_G3dGeBufferOP_N(0x12, &num, 1);
}

static inline BOOL TextWin_IsReady(TextWin *win) {
    if (win->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(win->unk_6c)) {
        win->unk_6c = NULL;
    } else {
        return win->noVram ? FALSE : TRUE;
    }
    return TRUE;
}
void func_0204edd8(TextWin *win) {
    s32 w;
    s32 h;
    if (win->unk_50 == NULL) {
        func_0204e5d4(win);
    }
    if (!TextWin_IsReady(win)) {
        return;
    }
    if (win->unk_68 != NULL) {
        func_0203df0c(win->unk_68);
        win->unk_68 = NULL;
    }
    if (win->inRender) {
        return;
    }
    func_02043d20(data_02097d48->unk_8b0, 0);
    {
        int misc = 0;
        int id = (u8)win->unk_4_13;
        int alpha = win->flag5 ? (u8)win->unk_4_8 : 0x1f;
        if (win->noShadowShift) {
            misc |= 0x4000;
        }
        if (win->flag22) {
            misc |= 0x800;
        }
        TW_PolygonAttr(0, 0, 3, id, alpha, misc);
    }
    {
    s32 pl = win->unk_2c >> 4;
    TW_TexImageParam(3, 1, win->unk_58, win->unk_5c, 0, 0, 1, ((u32)win->unk_50 & 0x1ffff) << 3);
    TW_TexPlttBase(TW_PlttAddr(win->unk_54) + pl * 0x20);
    }
    {
        s32 x = win->unk_3c << 12;
        s32 y = (win->unk_40 - 2) << 12;
        TW_PushMtx();
        TW_Translate(x, y, win->unk_70);
    }
    if (win->unk_0c != NULL) {
        NNS_G3dGeSendDL(win->unk_0c, win->unk_10);
    } else {
        w = (8 << win->unk_58) << 12;
        h = (8 << win->unk_5c) << 12;
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
        TW_Scale(w, h, 0x1000);
        if (win->unk_78 != 0) {
            s16 y;
            s32 split = (s32)win->unk_78;
            y = FX_Div(split, h);
            TW_Begin(3);
            TW_Color(win->unk_74);
            TW_TexCoord(w, 0);
            TW_Vtx(0x1000, 0, 0);
            TW_TexCoord(0, 0);
            TW_VtxXY(0, 0);
            TW_Color(win->unk_76);
            TW_TexCoord(w, split);
            TW_VtxXY(0x1000, y);
            TW_TexCoord(0, split);
            TW_VtxXY(0, y);
            TW_Color(win->unk_76);
            TW_TexCoord(w, h);
            TW_VtxXY(0x1000, 0x1000);
            TW_TexCoord(0, h);
            TW_VtxXY(0, 0x1000);
        } else {
            TW_Begin(1);
            TW_Color(win->unk_74);
            TW_TexCoord(w, 0);
            TW_Vtx(0x1000, 0, 0);
            TW_TexCoord(0, 0);
            TW_VtxXY(0, 0);
            TW_Color(win->unk_76);
            TW_TexCoord(0, h);
            TW_VtxXY(0, 0x1000);
            TW_TexCoord(w, h);
            TW_VtxXY(0x1000, 0x1000);
        }
        TW_End();
    }
    TW_PopMtx(1);
}

}
