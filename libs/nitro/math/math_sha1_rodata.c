// The SHA-1 padding constants MATH_SHA1GetHash feeds through MATH_SHA1Update: the 0x80 lead byte
// and the zero bytes that fill the block up to the length field.
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c). These two are byte arrays and
// MATHi_SHA1PadAlign starts at +1, which an asm block (aligned to 4, one global name) cannot give,
// so they are C data in a user section named ".text". The `R` access mode makes the section
// read-only (SHF_ALLOC without SHF_EXECINSTR): it still links into .text, but objdiff treats it as
// data and does not need a mapping symbol (an `RX` section without one makes it panic).

typedef unsigned char u8;

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

const u8 MATHi_SHA1PadLead[1] = { 0x80 };
const u8 MATHi_SHA1PadAlign[8] = { 0 };

#pragma section rodata_text end
