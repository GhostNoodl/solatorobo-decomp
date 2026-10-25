// MSL ctype classification table for the "C" locale (code points 0x00-0x7f).
//
// main keeps its read-only data inside .text: the SDK's linker script puts every object's .rodata
// after all the code, in link order. The tables are written as force-active asm blocks, which land
// in .text and carry the `$d` mapping symbol objdiff needs (symbols.txt lists them as data).

#define __msl_alpha  0x0001
#define __msl_blank  0x0002
#define __msl_cntrl  0x0004
#define __msl_digit  0x0008
#define __msl_graph  0x0010
#define __msl_lower  0x0020
#define __msl_print  0x0040
#define __msl_punct  0x0080
#define __msl_space  0x0100
#define __msl_upper  0x0200
#define __msl_xdigit 0x0400

#define ctrl __msl_cntrl
#define motn (__msl_cntrl | __msl_space)
#define tab  (__msl_cntrl | __msl_space | __msl_blank)
#define spac (__msl_space | __msl_blank | __msl_print)
#define punc (__msl_punct | __msl_graph | __msl_print)
#define digi (__msl_digit | __msl_xdigit | __msl_graph | __msl_print)
#define hexu (__msl_alpha | __msl_upper | __msl_xdigit | __msl_graph | __msl_print)
#define uppr (__msl_alpha | __msl_upper | __msl_graph | __msl_print)
#define hexl (__msl_alpha | __msl_lower | __msl_xdigit | __msl_graph | __msl_print)
#define lowr (__msl_alpha | __msl_lower | __msl_graph | __msl_print)

// Two u16 entries per word, the lower code point in the low half.
#define E2(a, b) ((a) | ((b) << 16))

#pragma force_active on

// const u16 __ctype_mapC[0x80]
void __ctype_mapC(void);

asm void __ctype_mapC(void) {
    // 0x00
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, tab)
    dcd E2(motn, motn)
    dcd E2(motn, motn)
    dcd E2(ctrl, ctrl)
    // 0x10
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    dcd E2(ctrl, ctrl)
    // 0x20 ' ' to '/'
    dcd E2(spac, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    // 0x30 '0' to '?'
    dcd E2(digi, digi)
    dcd E2(digi, digi)
    dcd E2(digi, digi)
    dcd E2(digi, digi)
    dcd E2(digi, digi)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    // 0x40 '@' to 'O'
    dcd E2(punc, hexu)
    dcd E2(hexu, hexu)
    dcd E2(hexu, hexu)
    dcd E2(hexu, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    // 0x50 'P' to '_'
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, uppr)
    dcd E2(uppr, punc)
    dcd E2(punc, punc)
    dcd E2(punc, punc)
    // 0x60 '`' to 'o'
    dcd E2(punc, hexl)
    dcd E2(hexl, hexl)
    dcd E2(hexl, hexl)
    dcd E2(hexl, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    // 0x70 'p' to DEL
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, lowr)
    dcd E2(lowr, punc)
    dcd E2(punc, punc)
    dcd E2(punc, ctrl)
}

#pragma force_active reset
