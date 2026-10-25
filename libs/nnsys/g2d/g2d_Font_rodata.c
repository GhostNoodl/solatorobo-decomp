// The character splitter for each font encoding (NNSG2dFontEncoding: UTF-8, UTF-16, Shift_JIS,
// CP1252), which NNSi_G2dFontGetSpliter returns.
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c); this is C data in a read-only
// user section named ".text" (see libs/nitro/math/math_sha1_rodata.c).

typedef unsigned short u16;
typedef u16 (*NNSiG2dSplitCharCallback)(const void **ppChar);

u16 NNSi_G2dSplitCharUTF8(const void **ppChar);
u16 NNSi_G2dSplitCharUTF16(const void **ppChar);
u16 NNSi_G2dSplitCharShiftJIS(const void **ppChar);
u16 NNSi_G2dSplitChar1Byte(const void **ppChar);

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

// static const NNSiG2dSplitCharCallback spliterTable[]
const NNSiG2dSplitCharCallback data_02075644[4] = {
    NNSi_G2dSplitCharUTF8,
    NNSi_G2dSplitCharUTF16,
    NNSi_G2dSplitCharShiftJIS,
    NNSi_G2dSplitChar1Byte,
};

#pragma section rodata_text end
