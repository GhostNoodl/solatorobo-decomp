#include "Main/Gfx/TextWin.h"
#include "nnsys/g2d/g2d_Font.h"

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];

typedef struct TextScanTag {
    s32 code;
    s32 value;
} TextScanTag;

typedef struct TextScanParser {
    /* 0x00 */ const u32 *vt;
    /* 0x04 */ u8 unk_04[0x7c];
    /* 0x80 */ TextScanTag tag;
    /* 0x88 */ u8 unk_88[0x30];
} TextScanParser;

void *func_0203a4c0(GfxMgr *mgr);
void func_0204c7d0(TextWin *win);
void func_0204cc18(TextScanParser *p, const char **s);

// Splits the string into the box's lines. The copy is written `*dst = start[i]; dst++;`:
// `*dst++ = start[i]` makes MWCC give dst a new object below the named locals (round loopt).
void func_020508f4(TextBox *box, const char *str) {
    TextBoxLine *line;
    char *dst;
    NNSG2dFont *font;
    TextScanParser p;
    const char *start;
    TextScanTag *tag;
    s32 width;
    const char *s;
    s32 height;
    u16 c;
    NNSiG2dSplitCharCallback fn;
    u32 n;
    s32 nLines;
    u32 i;
    data_02097ce0->unk_004 = box->pltt;
    font = (NNSG2dFont *)func_0203a4c0(data_02097ce0);
    fn = font->cbCharSpliter;
    s = str;
    p.vt = data_0208ba70;
    line = &box->lines[0];
    func_0204c7d0((TextWin *)&p);
    nLines = 0;
    dst = (char *)&line->unk_00;
    width = nLines;
    height = box->lineHeight + font->pRes->pGlyph->cellHeight;
    goto test;
    do {
        while (start = s, (c = fn((const void **)&s)) != 0) {
            if (c == '\n') {
                line->unk_88 = width;
                line->unk_8c = height;
                line++;
                dst = (char *)&line->unk_00;
                nLines++;
                width = 0;
                break;
            }
            if (c == '\\') {
                start = s;
                c = fn((const void **)&s);
            } else if (c == '<') {
                func_0204cc18(&p, &s);
                tag = &p.tag;
                switch (tag->code) {
                case 0x15:
                    if (tag->value != 0) {
                        box->unk_000 |= 0x10;
                    }
                    break;
                case 0x16:
                    box->unk_018 = tag->value;
                    break;
                }
                start = s;
            } else if (c == 0x3001) {
                c = ' ';
            } else if (c == 0x3002) {
                c = ' ';
            }
            n = s - start;
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (line->unk_80 < 0x7f) {
                        *dst = start[i];
                        dst++;
                        line->unk_80++;
                    }
                }
                *dst = 0;
                width += NNS_G2dFontGetCharWidth(font, c);
            }
            start = s;
            if (*start == 0) {
                box->unk_020 = (u32)(start + 1);
                line->unk_88 = width;
                line->unk_8c = height;
                break;
            }
        }
    test:
        if (*s == 0) {
            break;
        }
    } while (*s != 0);
    box->unk_204 = 0;
    box->unk_208 = nLines + 1;
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
}

}
