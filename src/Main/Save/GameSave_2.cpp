#include "Main/Save/GameSave.h"

extern "C" {

void GameSave_Setup(GameSave *s) {
    s->vf78();
    SaveBase_AllocBuffers(s);
}

void GameSave_Init(GameSave *s) {
    s->flags = 0;
}

void GameSave_Finalize(GameSave *s) {
}

void GameSave_FillSlot(GameSave *s, GameSaveSlot *slot) {
    slot->saveCount++;
    slot->frameCount = data_0214a424->frameCount;
    slot->unk_08 = data_0214a424->unk_020;
    slot->unk_0c_0 = data_0214a424->unk_01a;
    slot->unk_0c_8 = (u8)data_0214a424->unk_518_16;
    slot->unk_0c_16 = data_0214a424->unk_009;
    slot->unk_0c_28 = (u8)data_0214a424->unk_518_28;
}

void GameSave_FillData(GameSave *s, void *dst) {
    MI_CpuCopy8(data_0214a428, dst, sizeof(data_0214a428));
}

void GameSave_OnLoadData(GameSave *s, const void *src) {
    MI_CpuCopy8(src, data_0214a428, sizeof(data_0214a428));
}

void GameSave_OnError(GameSave *s) {
    s->bits.flag8 = 0;
    s->bits.flag9 = 0;
    s->bits.flag10 = 0;
    s->bits.flag2 = 1;
}

void GameSave_State1(GameSave *s) {
    if (s->bits.active) {
        SaveBase_SetState_020473ac(s, 2);
    }
}

void GameSave_State3(GameSave *s) {
    SaveSlot *slot = (SaveSlot *)(s->header->slots + s->curSlot * s->slotSize);
    if (slot->flags & 2) {
        s->bits.flag11 = 1;
    }
    SaveBase_SetState_020473ac(s, 4);
}

void GameSave_State4(GameSave *s) {
    s->bits.flag1 = 0;
    if (s->bits.flag3) {
        SaveBase_SetState_020473ac(s, 5);
    } else if (s->bits.flag12) {
        SaveBase_SetState_020473ac(s, 12);
    } else if (s->bits.flag14) {
        SaveBase_SetState_020473ac(s, 15);
    } else if (s->bits.flag5) {
        if (s->bits.flag9) {
            SaveBase_SetState_020473ac(s, 7);
        }
    } else if (s->bits.flag6) {
        s->bits.flag7 = 0;
        if (s->bits.flag8) {
            SaveBase_SetState_020473ac(s, 7);
        } else if (s->bits.flag10) {
            SaveBase_SetState_020473ac(s, 9);
        } else {
            s->bits.flag7 = 1;
        }
    } else {
        s->bits.flag7 = 1;
    }
}

void GameSave_State6(GameSave *s) {
    s->bits.flag3 = 0;
    s->bits.flag1 = 1;
    SaveBase_SetState_020473ac(s, 0);
}

void GameSave_State7(GameSave *s) {
    SaveSlot *slot = SaveBase_GetSlot(s, s->curSlot);
    if (s->step == 0) {
        if (s->bits.flag8) {
            slot->flags |= 4;
        } else {
            slot->flags &= ~4;
        }
        if (s->bits.flag4) {
            slot->flags |= 8;
        } else {
            slot->flags &= ~8;
        }
    }
    SaveBase_State7(s);
}

void GameSave_State8(GameSave *s) {
    s->bits.flag8 = 0;
    s->bits.flag9 = 0;
    s->bits.flag1 = 1;
    SaveBase_SetState_020473ac(s, 0);
}

void GameSave_State10(GameSave *s) {
    SaveBase_State10(s);
    if (s->step == 1) {
        s->bits.flag10 = 0;
        s->bits.flag1 = 1;
        SaveBase_SetState_020473ac(s, 0);
    }
}

void GameSave_State11(GameSave *s) {
    s->bits.flag11 = 1;
    if (s->bits.flag12) {
        SaveBase_SetState_020473ac(s, 12);
    }
}

void GameSave_State14(GameSave *s) {
    s->bits.flag13 = 1;
    SaveBase_SetState_020473ac(s, 0);
}

void GameSave_State13(GameSave *s) {
    SaveBase_State13(s);
    if (s->step == 1) {
        s->bits.flag12 = 0;
        s->bits.flag1 = 1;
        SaveBase_SetState_020473ac(s, 0);
    }
}

void GameSave_State16(GameSave *s) {
    s->bits.flag14 = 0;
    s->bits.flag1 = 1;
    SaveBase_SetState_020473ac(s, 0);
}

void MainVt_0208ca18_State1(GameSave *s) {
    if (s->bits.active) {
        SaveBase_SetState_020473ac(s, 4);
    }
}

void MainVt_0208ca18_State7(GameSave *s) {
    switch (s->step) {
    case 0:
        s->step = 100;
        break;
    case 1:
        s->step = 2;
        break;
    case 2:
        s->step = 3;
        break;
    case 3:
        s->step = 4;
        break;
    case 4:
        SaveBase_SetState_020473ac(s, 8);
        break;
    default:
        s->step = 1;
        break;
    }
}

void MainVt_0208ca18_State9(GameSave *s) {
    switch (s->step) {
    case 0:
        if (func_02047694(s)) {
            s->step = 1;
        } else {
            SaveBase_SetState_020473ac(s, 11);
        }
        break;
    case 1:
        s->step = 2;
        break;
    case 2:
        SaveBase_SetState_020473ac(s, 10);
        break;
    }
}

#ifdef NONMATCHING
// Status (round drA): MainVt_0208c994_Configure is 19 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is the
// best clean draft. Blocker: register-only: the first product and the card pointer swap registers; every wrong node
// is a backend temp. History: docs/MATCHING.md rounds qpB, raC, rgB, cvA (search for the address); the full list is
// docs/UNMATCHED.md.
// MainVt_0208c994_Configure: 19 raw / 0 register-masked (round qpB; was 36 / 0 with a split `sm_t24` sum).
// The first half is GameSave_Configure's layout; the second places a 0xc-byte-slot save after it and
// gives it the rest of the card, rounded down to a page. The align-down written out as
// `payload &= ~(totalSize - 1)` followed by `payload -= slotSize + 4` keeps both the sub and the add.
// Register-only: the ROM gives the first product r1 and the card pointer r2 (ours r2/r1). Passing
// the page size as an argument (`RoundUp(x, data_02097e44->totalSize)`) fixes that pair (18 / 0) but
// moves the `m` of the first align off the loaded register; honest_search finds nothing.
// Round rgB: as in GameSave_Configure, tools/vnum.sh shows every object uncoloured (d, n, end, payload and the inline
// temps are all propagated); the swapped values are backend temps, so no band lever applies.
// Rounds x up to the card's page size (SysCard::totalSize).
static inline u32 GameSave_AlignUp(u32 x) {
    u32 m = data_02097e44->totalSize; m -= 1;
    x += m;
    return x & ~m;
}

void MainVt_0208c994_Configure(GameSave *s) {
    u32 d;
    u32 end;
    u32 payload;
    s->name = data_0208cb18;
    s->slotCount = 1;
    s->slotSize = 0x14;
    s->headerSize = GameSave_AlignUp(s->slotSize * s->slotCount + 0x14);
    d = GameSave_AlignUp(sizeof(data_0214a428) + (int)(s->slotSize + 4));
    s->dataSize = d;
    {
        int n = s->headerSize + d * s->slotCount;
        n += d;
        s->baseOffset = 0;
        end = GameSave_AlignUp(n);
        s->tmpSize = end;
    }
    s->slotCount = 1;
    s->slotSize = 0xc;
    s->headerSize = GameSave_AlignUp(s->slotSize * s->slotCount + 0x14);
    payload = data_02097e44->sectorSize - end - s->headerSize;
    payload &= ~(data_02097e44->totalSize - 1);
    payload -= s->slotSize + 4;
    s->dataSize = GameSave_AlignUp(payload + (int)(s->slotSize + 4));
    s->baseOffset = end;
    s->tmpSize = GameSave_AlignUp(s->headerSize + s->dataSize * s->slotCount);
}
#endif

}
