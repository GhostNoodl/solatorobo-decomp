#include "ov006/SlotManager.h"
#include "nitro/fx.h"

typedef struct ov006_Party {
    u8 unk0[0x15];
    u8 count;
} ov006_Party;

typedef struct ov006_Unk021ccd6c {
    u8 unk0[0x14];
    ov006_Party *party;
} ov006_Unk021ccd6c;

typedef struct ov006_Racer021d8914 {
    u8 unk0[0x70];
    VecFx32 pos;
    u8 unk7C[0x18d];
    u8 unk209;
    u8 unk20A;
    u8 unk20B;
} ov006_Racer021d8914;

typedef struct ov006_RaceInfo {
    u16 unk0;
    u8 unk2;
    u8 ranks;
    VecFx32 unk4;
} ov006_RaceInfo;

typedef struct ov006_Checkpoint021d8914 {
    VecFx32 pos;
    u8 unkC[4];
} ov006_Checkpoint021d8914;

extern "C" {

extern void *data_ov000_021ccd68;
extern ov006_Unk021ccd6c *data_ov000_021ccd6c;

ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
void *func_ov000_0218e640(void *a, u16 id);
BOOL func_ov006_021ea3e8(void *prop);
int func_0206e264(ov006_Party *party);
ov006_RaceInfo *func_ov006_021dab98(ov006_Slot *self);
void func_ov006_021daba0(ov006_Slot *self, const ov006_RaceInfo *src);
ov006_RaceInfo *func_ov006_021dabc4(ov006_Slot *self);

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
        u16 id = func_ov006_021db060(data_ov006_021ec884, i)->unkE;
        void *prop = data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
        if (prop != NULL && func_ov006_021ea3e8(prop)) {
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
    return func_0206e264(self->party);
}

static inline int ov006_GetCheckpoints(void) {
    int result = 0;
    if (ov006_GetPartyCount(data_ov000_021ccd6c) > 5) {
        result = ov006_GetPartyValue(data_ov000_021ccd6c) + 0x50;
    }
    return result;
}

void func_ov006_021d8914(void) {
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
    slot = func_ov006_021db060(data_ov006_021ec884, 0);
    num = data_ov006_021ec884->numActive;
    remaining = ov006_CountRemaining();
    for (i = 0; i < num; i++) {
        u16 id = func_ov006_021db060(data_ov006_021ec884, i)->unkE;
        ov006_Racer021d8914 *racer = data_ov000_021ccd68 != NULL ? (ov006_Racer021d8914 *)func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
        if ((racer != NULL && func_ov006_021ea3e8(racer)) || remaining <= 1) {
            rank[i] = (func_ov006_021dab98(slot)->ranks >> (i * 2)) & 3;
            a[i] = 0xff;
        } else {
            rank[i] = 0xff;
            a[i] = 0;
            b[i] = 0;
            c[i] = 0;
            if (racer != NULL) {
                a[i] = racer->unk20B;
                b[i] = racer->unk209;
                c[i] = racer->unk20A;
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
                    VecFx32 *target = &((ov006_Checkpoint021d8914 *)ov006_GetCheckpoints())[c[i]].pos;
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
    sub = *func_ov006_021dabc4(slot);
    for (i = 0; i < num; i++) {
        sub.ranks = (sub.ranks & (u8)~(3 << (i * 2))) | (u8)((rank[i] & 3) << (i * 2));
    }
    func_ov006_021daba0(slot, &sub);
}

}
