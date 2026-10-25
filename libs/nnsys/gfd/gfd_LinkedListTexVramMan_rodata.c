// The initializer NNS_GfdResetLnkTexVramState copies onto its stack: the free / allocated sizes of
// the four texture VRAM slots, each starting as one free 128 KB slot.
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c); this is C data in a read-only
// user section named ".text" (see libs/nitro/math/math_sha1_rodata.c).

typedef unsigned long u32;

#define NNS_GFD_TEXVRAM_SLOT_SIZE 0x20000 // 128 KB

typedef struct SlotData {
    u32 szFree;
    u32 szAllocatedNrm;
    u32 szAllocated4x4;
} SlotData;

typedef struct SlotDataArr {
    SlotData s[4];
} SlotDataArr;

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

const SlotDataArr data_020755e4 = {{
    { NNS_GFD_TEXVRAM_SLOT_SIZE, 0, 0 },
    { NNS_GFD_TEXVRAM_SLOT_SIZE, 0, 0 },
    { NNS_GFD_TEXVRAM_SLOT_SIZE, 0, 0 },
    { NNS_GFD_TEXVRAM_SLOT_SIZE, 0, 0 },
}};

#pragma section rodata_text end
