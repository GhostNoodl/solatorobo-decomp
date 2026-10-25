// gx_load.c's VRAM start-address tables, in units of 0x1000 bytes (LCDC addresses).
// Written as asm blocks so they land in main's .text with the other read-only data (see
// libs/msl/ctype.c).

// Texture image banks A-D are 0x20000 bytes each, from 0x06800000.
#define VRAM_A 0x6800
#define VRAM_B 0x6820
#define VRAM_C 0x6840
#define VRAM_D 0x6860
#define BANK_SIZE 0x20
// Texture palette banks: E is 0x10000 bytes, F and G 0x4000.
#define VRAM_E 0x6880
#define VRAM_F 0x6890
#define VRAM_G 0x6894

#define E2(a, b) ((a) | ((b) << 16))
// Two GXTexStartAddr entries {blk1, blk2, szBlk1} in three words: the first contiguous run of
// banks, the second run (or 0), and the size of the first run when there are two.
#define TEX2(a1, a2, a3, b1, b2, b3) dcd E2(a1, a2); dcd E2(a3, b1); dcd E2(b2, b3)

#pragma force_active on

// const u16 sTexPlttStartAddrTable[8], indexed by the E | F << 1 | G << 2 bank mask: the first
// bank of a contiguous set, or 0 when E and G are used without F.
void sTexPlttStartAddrTable(void);
// const GXTexStartAddr sTexStartAddrTable[16], indexed by the A | B << 1 | C << 2 | D << 3 mask.
void sTexStartAddrTable(void);

asm void sTexPlttStartAddrTable(void) {
    dcd E2(0, VRAM_E)      // -, E
    dcd E2(VRAM_F, VRAM_E) // F, EF
    dcd E2(VRAM_G, 0)      // G, EG
    dcd E2(VRAM_F, VRAM_E) // FG, EFG
}

asm void sTexStartAddrTable(void) {
    TEX2(0, 0, 0, VRAM_A, 0, 0) // -; A
    TEX2(VRAM_B, 0, 0, VRAM_A, 0, 0) // B; AB
    TEX2(VRAM_C, 0, 0, VRAM_A, VRAM_C, BANK_SIZE) // C; A C
    TEX2(VRAM_B, 0, 0, VRAM_A, 0, 0) // BC; ABC
    TEX2(VRAM_D, 0, 0, VRAM_A, VRAM_D, BANK_SIZE) // D; A D
    TEX2(VRAM_B, VRAM_D, BANK_SIZE, VRAM_A, VRAM_D, BANK_SIZE * 2) // B D; AB D
    TEX2(VRAM_C, 0, 0, VRAM_A, VRAM_C, BANK_SIZE) // CD; A CD
    TEX2(VRAM_B, 0, 0, VRAM_A, 0, 0) // BCD; ABCD
}

#pragma force_active reset
