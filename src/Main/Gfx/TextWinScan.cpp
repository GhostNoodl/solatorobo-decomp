#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/GfxMgr.h"

// Base of the text layout helper; its vtable stays in asm.
struct TextLayout {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
};

extern "C" {

extern const u32 data_0208ba70[];

typedef s32 (*TextScanCharFn)(const char **s);

// Stack copy of a TextWin used only for tag parsing.
typedef struct TextScanParser {
    /* 0x00 */ const u32 *vt;
    /* 0x04 */ u8 unk_04[0x7c];
    /* 0x80 */ s32 code;
    /* 0x84 */ s32 value;
    /* 0x88 */ u8 unk_88[0x30];
} TextScanParser;

void *func_0203a4c0(GfxMgr *mgr);
void func_0204c7d0(TextWin *win);
void func_0204cc18(TextScanParser *p, const char **s);

void func_0204c6bc(const char *str, s32 maxLines, void *arg, void (*cb)(void *arg, s32 *tag)) {
    const char *s;
    TextScanParser p;
    s32 n;
    TextScanCharFn fn;
    s32 c;
    data_02097ce0->unk_004 = 3;
    fn = *(TextScanCharFn *)((u8 *)func_0203a4c0(data_02097ce0) + 4);
    s = str;
    n = 0;
    p.vt = data_0208ba70;
    func_0204c7d0((TextWin *)&p);
    while (*s != 0) {
        while ((c = fn(&s)) != 0) {
            if (c != '\n') {
                if (c == '\\') {
                    fn(&s);
                } else if (c == '<') {
                    func_0204cc18(&p, &s);
                    cb(arg, &p.code);
                }
                if (*s == 0) {
                    if (++n >= maxLines) {
                        break;
                    }
                    s++;
                }
            }
        }
    }
    p.vt = data_0208ba70;
    ((TextLayout *)&p)->Clear();
}

}
