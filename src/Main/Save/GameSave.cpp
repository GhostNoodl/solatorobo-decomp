#include "Main/Save/GameSave.h"

extern "C" {

void func_0206d3f4(GameSave *s) {
    s->bits.flag2 = 0;
    s->bits.flag8 = 0;
    s->bits.flag9 = 0;
    s->bits.flag10 = 0;
    s->bits.flag11 = 0;
    s->bits.flag12 = 0;
    s->bits.flag13 = 0;
    s->bits.flag14 = 0;
    func_020473ac(s, 0);
    func_02046cd0(data_02097e44);
}

#ifdef NONMATCHING
// func_0206d43c: 12 raw / 0 register-masked (round qpB). Register-only: the ROM keeps the card
// pointer in r4 and the first sum in lr (ours: r3/r4), and puts the dataSize*slotCount+headerSize
// mla in r1. ramerge.py (single and multi-target, with --pairs) finds no merge or renumbering that
// gives it, every Align spelling (12 forms, round qpB alsweep.py) is 12 or worse, and honest_search
// (40 iterations) finds nothing. It shares the CODASAVE string pool with func_0206d99c.
// Rounds x up to the card's page size (SysCard::totalSize).
// Round raC: AlignUp written in place for the header or d, and the n sum as an inline: 11 / 2 to 21 / 4.
// Round raE: AlignUp taking the card (a SysCard *card local, 29-32) or the page size (a local, 30) as a
// named argument; passing data_02097e44 itself is 12 / 0.
static inline u32 GameSave_AlignUp(u32 x) {
    u32 m = data_02097e44->totalSize; m -= 1;
    x += m;
    return x & ~m;
}

void func_0206d43c(GameSave *s) {
    u32 d;
    s->name = data_0208cb18;
    s->slotCount = 1;
    s->slotSize = 0x14;
    s->headerSize = GameSave_AlignUp(s->slotSize * s->slotCount + 0x14);
    d = GameSave_AlignUp(sizeof(data_0214a428) + (int)(s->slotSize + 4));
    s->dataSize = d;
    {
        u32 n = s->headerSize + d * s->slotCount;
        n += d;
        s->baseOffset = 0;
        s->tmpSize = GameSave_AlignUp(n);
    }
}
#endif

}
