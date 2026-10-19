#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern int NNSi_G2dFontGetStringWidth(const void *pFont, int hSpace, const void *str, const void **pPos);
extern int NNSi_G2dFontGetTextHeight(const void *pFont, int vSpace, const void *txt);
extern void NNS_G2dCharCanvasInitForBG(void *canvas, void *charBase, int w, int h, int colorMode);
extern void NNS_G2dMapScrToCharText(void *scrBase, int w, int h, int left, int top, int pitch, int charNo, int pltt);
extern void *func_0203bb68(GfxSys *sys, BOOL main);
extern void func_0203b12c(GfxMgr *mgr, const char *str);
extern void func_0203b4ac(GfxMgr *mgr, int color);
extern void DC_FlushAll(void);

void func_0203aab0(GfxMgr *mgr, const char *str) {
    GfxFont *font;
    int pal;
    int width;
    int charNo;
    int top;
    int height;
    int color;
    int rows;
    const char *p;
    u8 *charBase;
    u8 type;
    font = mgr->fonts[mgr->unk_004];
    height = NNSi_G2dFontGetTextHeight(&font->res, mgr->unk_010, str);
    pal = 0;
    color = 0;
    type = mgr->fontHeights[mgr->unk_004];
    if (type == 1) {
        int v = mgr->unk_008;
        pal = v >> 4;
        color = v % 15 + 1;
    } else if (type == 2) {
        pal = (int)mgr->unk_008 / 5 + 1;
        color = ((int)mgr->unk_008 % 5) * 3 + 1;
    }
    if (mgr->unk_00e + height > mgr->unk_67a * 8) {
        mgr->unk_00e = mgr->unk_67a * 8 - height;
    }
    top = mgr->unk_00e >> 3;
    charNo = (s16)top * mgr->unk_678 + 1;
    rows = ((mgr->unk_00e + height + 7) >> 3) - top;
    charBase = (u8 *)func_0203bb68(data_02097d48, FALSE);
    NNS_G2dCharCanvasInitForBG(mgr->unk_684, charBase + charNo * 0x20, mgr->unk_678, rows, 4);
    NNS_G2dMapScrToCharText(func_0203bb68(data_02097d48, TRUE), mgr->unk_678, rows, 0, top, 0x20, charNo, pal + mgr->plttSlots[1]);
    func_0203b12c(mgr, str);
    func_0203b4ac(mgr, color);
    DC_FlushAll();
    p = str;
    while (p != NULL) {
        width = NNSi_G2dFontGetStringWidth(&font->res, 0, p, (const void **)&p);
    }
    mgr->unk_00c = mgr->unk_00c + (s16)width;
    mgr->unk_00e = mgr->unk_00e + (s16)(height - font->res->info[1]);
}

}
