#include "Main/Save/GameSave.h"

extern "C" {

void GameSave_ResetFlags(GameSave *s) {
    s->bits.flag2 = 0;
    s->bits.flag8 = 0;
    s->bits.flag9 = 0;
    s->bits.flag10 = 0;
    s->bits.flag11 = 0;
    s->bits.flag12 = 0;
    s->bits.flag13 = 0;
    s->bits.flag14 = 0;
    SaveBase_SetState_020473ac(s, 0);
    SysCard_Reset_02046cd0(gSysCard);
}

#ifdef NONMATCHING
// Status (round drA): GameSave_Configure is 12 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is the
// best clean draft. Blocker: register-only: the card pointer and the first sum swap registers; every wrong node is a
// backend temp. History: docs/MATCHING.md rounds qpB, raC, raE, rgB, nmA, cvA (search for the address); the full
// list is docs/UNMATCHED.md.
// GameSave_Configure: 12 raw / 0 register-masked (round qpB). Register-only: the ROM keeps the card
// pointer in r4 and the first sum in lr (ours: r3/r4), and puts the dataSize*slotCount+headerSize
// mla in r1. ramerge.py (single and multi-target, with --pairs) finds no merge or renumbering that
// gives it, every Align spelling (12 forms, round qpB alsweep.py) is 12 or worse, and honest_search
// (40 iterations) finds nothing. It shares the CODASAVE string pool with MainVt_0208c994_Configure.
// Rounds x up to the card's page size (SysCard::totalSize).
// Round raC: AlignUp written in place for the header or d, and the n sum as an inline: 11 / 2 to 21 / 4.
// Round raE: AlignUp taking the card (a SysCard *card local, 29-32) or the page size (a local, 30) as a
// named argument; passing gSysCard itself is 12 / 0.
// Round rgB: tools/vnum.sh: every object (d, n, AlignUp's x/m) is uncoloured (propagated), so every wrong node
// is a backend temp and no band lever applies.
static inline u32 GameSave_AlignUp(u32 x) {
    u32 m = gSysCard->totalSize; m -= 1;
    x += m;
    return x & ~m;
}

void GameSave_Configure(GameSave *s) {
    u32 d;
    s->name = data_0208cb18;
    s->slotCount = 1;
    s->slotSize = 0x14;
    s->headerSize = GameSave_AlignUp(s->slotSize * s->slotCount + 0x14);
    d = GameSave_AlignUp(sizeof(gStageFlagsSave) + (int)(s->slotSize + 4));
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
