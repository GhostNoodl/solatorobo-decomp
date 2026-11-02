#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "ov006/Racer.h"

typedef struct ov006_Party {
    u8 unk0[0x15];
    u8 count;
} ov006_Party;

typedef struct ov006_Unk021ccd6c {
    u8 unk0[0x14];
    ov006_Party *party;
} ov006_Unk021ccd6c;

typedef struct ov006_RaceInfo {
    u16 unk0;
    u8 unk2;
    u8 ranks;
    VecFx32 unk4;
} ov006_RaceInfo;

extern "C" {

extern void *data_ov000_021ccd68;
extern ov006_Unk021ccd6c *data_ov000_021ccd6c;

ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
void *ActorMgr_GetActor(void *a, u16 id);
int LangBlockB_GetData(ov006_Party *party);
ov006_RaceInfo *ov006_Slot_GetSub2C(ov006_Slot *self);
void ov006_Slot_SetSub3C(ov006_Slot *self, const ov006_RaceInfo *src);
ov006_RaceInfo *ov006_Slot_GetSub3C(ov006_Slot *self);

static inline u8 ov006_CountRemaining(void) {
    u8 count;
    u8 i;
    u8 num;
    num = data_ov006_021ec884->numActive;
    if (num <= 1) {
        return 0x63;
    }
    count = 0;
    for (i = 0; i < num; i++) {
        u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->actorId;
        Ov006Racer *prop = data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
        if (prop != NULL && Ov006Racer_IsFinished(prop)) {
            count++;
        }
    }
    return num - count;
}

static inline u32 ov006_GetPartyCount(ov006_Unk021ccd6c *self) {
    return self->party != NULL ? self->party->count : 0;
}

static inline int ov006_GetPartyValue(ov006_Unk021ccd6c *self) {
    if (self->party == NULL || self->party->count == 0) {
        return 0;
    }
    return LangBlockB_GetData(self->party);
}

static inline int ov006_GetCheckpoints(void) {
    int result = 0;
    if (ov006_GetPartyCount(data_ov000_021ccd6c) > 5) {
        result = ov006_GetPartyValue(data_ov000_021ccd6c) + 0x50;
    }
    return result;
}

void ov006_ComputeRanks(void) {
    ov006_Slot *slot;
    u8 ai;
    u8 i;
    u8 n;
    u8 j;
    u8 num;
    u8 remaining;
    u8 rank[4];
    u8 a[4];
    u8 b[4];
    u8 c[4];
    VecFx32 pos[4];
    ov006_RaceInfo sub;

    if (data_ov006_021ec884->unk5 != 0) {
        return;
    }
    slot = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, 0);
    num = data_ov006_021ec884->numActive;
    remaining = ov006_CountRemaining();
    for (i = 0; i < num; i++) {
        u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->actorId;
        Ov006Racer *racer = data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
        if ((racer != NULL && Ov006Racer_IsFinished(racer)) || remaining <= 1) {
            rank[i] = (ov006_Slot_GetSub2C(slot)->ranks >> (i * 2)) & 3;
            a[i] = 0xff;
        } else {
            rank[i] = 0xff;
            a[i] = 0;
            b[i] = 0;
            c[i] = 0;
            if (racer != NULL) {
                a[i] = racer->laps;
                b[i] = racer->lastPt;
                c[i] = racer->nextPt;
                pos[i] = racer->pos;
            }
        }
    }
    for (i = 0; i < num; i++) {
        ai = a[i];
        if (ai == 0xff) {
            continue;
        }
        n = 0;
        for (j = 0; j < num; j++) {
            if (i == j) {
                continue;
            }
            if (a[j] == 0xff) {
                n++;
            } else if (ai < a[j]) {
                n++;
            } else if (ai == a[j]) {
                if (b[i] < b[j]) {
                    n++;
                } else if (b[i] == b[j]) {
                    VecFx32 *target = &((Ov006RacerPt *)ov006_GetCheckpoints())[c[i]].pos;
                    fx32 di = VEC_Distance(&pos[i], target);
                    fx32 dj = VEC_Distance(&pos[j], target);
                    if (di > dj) {
                        n++;
                    } else if (di == dj && i > j) {
                        n++;
                    }
                }
            }
        }
        rank[i] = n;
    }
    sub = *ov006_Slot_GetSub3C(slot);
    for (i = 0; i < num; i++) {
        sub.ranks = (sub.ranks & (u8)~(3 << (i * 2))) | (u8)((rank[i] & 3) << (i * 2));
    }
    ov006_Slot_SetSub3C(slot, &sub);
}

}
