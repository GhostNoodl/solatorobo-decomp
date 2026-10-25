// The null pointer-to-member-function constant of the MW runtime. MWCC copies it into a PMF that
// is cleared or left without a handler (for example in `__sinit_Obj3D_2.cpp`). An ARM PMF is two
// words, both zero here. Written as an asm block so it lands in main's .text with the other
// read-only data (see libs/msl/ctype.c).

#pragma force_active on

// const __ptmf __ptmf_null
void __ptmf_null(void);

asm void __ptmf_null(void) {
    dcd 0
    dcd 0
}

#pragma force_active reset
