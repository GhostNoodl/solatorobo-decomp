#include "nitro/snd.h"
#include "nitro/os.h"

void SND_AssignWaveArc(SNDBankData *bank, int index, SNDWaveArc *waveArc) {
    SNDWaveArc *oldArc;

    SNDi_LockMutex();

    oldArc = bank->waveArcLink[index].waveArc;
    if (oldArc != NULL) {
        if (waveArc == oldArc) {
            SNDi_UnlockMutex();
            return;
        }

        if (&bank->waveArcLink[index] == oldArc->topLink) {
            oldArc->topLink = bank->waveArcLink[index].next;
            DC_StoreRange(bank->waveArcLink[index].waveArc, sizeof(SNDWaveArc));
        } else {
            SNDWaveArcLink *link;
            for (link = oldArc->topLink; link != NULL; link = link->next) {
                if (&bank->waveArcLink[index] == link->next) {
                    break;
                }
            }
            link->next = bank->waveArcLink[index].next;
            DC_StoreRange(link, sizeof(SNDWaveArcLink));
        }
    }

    {
        SNDWaveArcLink *top = waveArc->topLink;
        waveArc->topLink = &bank->waveArcLink[index];
        bank->waveArcLink[index].next = top;
        bank->waveArcLink[index].waveArc = waveArc;
    }

    SNDi_UnlockMutex();

    DC_StoreRange(bank, sizeof(SNDBankData));
    DC_StoreRange(waveArc, sizeof(SNDWaveArc));
}

void SND_DestroyBank(SNDBankData *bank) {
    int i;

    SNDi_LockMutex();

    for (i = 0; i < SND_BANK_MAX_WAVEARC; i++) {
        SNDWaveArc *waveArc = bank->waveArcLink[i].waveArc;
        SNDWaveArcLink *myLink;

        if (waveArc == NULL) {
            continue;
        }

        myLink = &bank->waveArcLink[i];
        if (myLink == waveArc->topLink) {
            waveArc->topLink = bank->waveArcLink[i].next;
            DC_StoreRange(waveArc, sizeof(SNDWaveArc));
        } else {
            SNDWaveArcLink *link;
            for (link = waveArc->topLink; link != NULL; link = link->next) {
                if (myLink == link->next) {
                    break;
                }
            }
            link->next = bank->waveArcLink[i].next;
            DC_StoreRange(link, sizeof(SNDWaveArcLink));
        }
    }

    SNDi_UnlockMutex();
}

void SND_DestroyWaveArc(SNDWaveArc *waveArc) {
    SNDWaveArcLink *link;

    SNDi_LockMutex();

    link = waveArc->topLink;
    while (link != NULL) {
        SNDWaveArcLink *next = link->next;
        link->waveArc = NULL;
        link->next = NULL;
        DC_StoreRange(link, sizeof(SNDWaveArcLink));
        link = next;
    }

    SNDi_UnlockMutex();
}

SNDInstPos SND_GetFirstInstDataPos(const SNDBankData *bank) {
    SNDInstPos pos;
    pos.prgNo = 0;
    pos.index = 0;
    return pos;
}

BOOL SND_GetNextInstData(const SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos) {
    while (pos->prgNo < bank->instCount) {
        const SNDDrumSet *drumSet;
        const SNDKeySplit *keySplit;
        u32 instOffset = bank->instOffset[pos->prgNo];
        u32 offset;

        inst->type = (u8)instOffset;
        offset = instOffset >> 8;

        switch (inst->type) {
        case SND_INST_PCM:
        case SND_INST_PSG:
        case SND_INST_NOISE:
        case SND_INST_DIRECTPCM:
        case SND_INST_NULL:
            inst->param = *(const SNDInstParam *)((u8 *)bank + offset);
            pos->prgNo++;
            return TRUE;

        case SND_INST_DRUM_SET:
            drumSet = (const SNDDrumSet *)((u8 *)bank + offset);
            for (; pos->index < drumSet->max - drumSet->min + 1;) {
                *inst = drumSet->instOffset[pos->index];
                pos->index++;
                return TRUE;
            }
            break;

        case SND_INST_KEY_SPLIT:
            keySplit = (const SNDKeySplit *)((u8 *)bank + offset);
            for (; pos->index < SND_INST_MAX_KEYSPLIT;) {
                if (keySplit->key[pos->index] == 0) {
                    break;
                }
                *inst = keySplit->instOffset[pos->index];
                pos->index++;
                return TRUE;
            }
            break;
        }

        pos->prgNo++;
        pos->index = 0;
    }
    return FALSE;
}

u32 SND_GetWaveDataCount(const SNDWaveArc *waveArc) {
    return waveArc->waveCount;
}

void SND_SetWaveDataAddress(SNDWaveArc *waveArc, int index, const SNDWaveData *address) {
    SNDi_LockMutex();
    waveArc->waveOffset[index] = (u32)address;
    DC_StoreRange(&waveArc->waveOffset[index], sizeof(u32));
    SNDi_UnlockMutex();
}

const SNDWaveData *SND_GetWaveDataAddress(const SNDWaveArc *waveArc, int index) {
    u32 offset;

    SNDi_LockMutex();

    offset = waveArc->waveOffset[index];
    if (offset != 0) {
        if (offset < 0x02000000) {
            offset = (u32)&((u8 *)waveArc)[offset];
        }
    } else {
        offset = 0;
    }

    SNDi_UnlockMutex();
    return (const SNDWaveData *)offset;
}
