#include "ov006/SlotManager.h"
#include "nitro/fx.h"

typedef struct ov006_Query021e7fe4 {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    union {
        u8 flags;
        struct {
            u8 b0 : 2;
            u8 b2 : 1;
            u8 b3 : 5;
        } bits;
    };
} ov006_Query021e7fe4;

typedef struct ov006_Finder021e7fe4 {
    ov006_Query021e7fe4 *query;
} ov006_Finder021e7fe4;

typedef struct ov006_FinderQuery021e7fe4 {
    ov006_Finder021e7fe4 finder;
    ov006_Query021e7fe4 q;
} ov006_FinderQuery021e7fe4;

typedef struct ov006_Hit021e7fe4 {
    u8 unk0[0x90];
    u16 unk90;
} ov006_Hit021e7fe4;

typedef struct ov006_Eff021e7fe4 {
    u8 unk0[0x24];
    int unk24;
    u8 unk28;
    u8 unk29[0x13];
    fx32 unk3C;
    u8 unk40[0x88];
    int unkC8;
} ov006_Eff021e7fe4;

typedef struct ov006_Prop021e7fe4 {
    u8 unk0[0xc];
    u16 unkC;
    u8 unkE[0x62];
    VecFx32 pos;
    u8 unk7C[0x120];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 12;
    u16 unk19C_14 : 1;
    u16 unk19C_15 : 1;
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0[0x50];
    int unk1F0;
    u8 unk1F4[8];
    u16 unk1FC;
} ov006_Prop021e7fe4;

extern "C" {

extern void *data_02097e4c;
extern const char data_ov006_021ec48c[];
extern const char data_ov006_021ec49b[];

s32 func_ov000_02199128(ov006_Finder021e7fe4 *self, ov006_Query021e7fe4 *q, void **out, s32 max);
ov006_Eff021e7fe4 *func_02066774(const char *a, const char *b, s32 c, VecFx32 *pos);
s32 func_02049bdc(void *a, int b, int c);

static inline void ov006_FinderQuery_Init(ov006_FinderQuery021e7fe4 *fq) {
    fq->q.mask = 0;
    fq->q.unk_12 = 0;
    fq->q.unk_14 = 0;
    fq->q.unk_18 = 0;
    fq->q.unk_1c = 0;
    fq->q.unk_20 = 0;
    fq->q.unk_24 = 0;
    fq->q.flags = 0;
    fq->finder.query = NULL;
    fq->q.kind = 0xffff;
    fq->q.exclude = 0xffff;
}

static inline BOOL ov006_Hit_IsOwner(ov006_Hit021e7fe4 *h, ov006_Prop021e7fe4 *p) {
    return h->unk90 == p->unkC;
}

void func_ov006_021e7fe4(ov006_Prop021e7fe4 *self) {
    BOOL found = FALSE;
    if (self->unk19C_0 & 1) {
        ov006_FinderQuery021e7fe4 fq;
        ov006_Hit021e7fe4 *hits[0x20];
        int n;
        int i;
        ov006_FinderQuery_Init(&fq);
        fq.q.pos = self->pos;
        fq.q.unk_0c = 0;
        fq.q.mask = 0x10;
        fq.q.kind = 0x4f43;
        fq.q.unk_18 = 0;
        fq.q.unk_1c = 0x46000;
        fq.q.bits.b2 = 0;
        n = func_ov000_02199128(&fq.finder, &fq.q, (void **)hits, 0x20);
        for (i = 0; i < n; i++) {
            ov006_Hit021e7fe4 *h = hits[i];
            if (h->unk90 == self->unkC) {
                found = TRUE;
                break;
            }
        }
    }
    if (found) {
        if (!self->unk19C_14) {
            self->unk19C_14 = 1;
            self->unk1FC = 0;
            if (self->unk1F0 == 0) {
                ov006_Eff021e7fe4 *eff = func_02066774(data_ov006_021ec48c, data_ov006_021ec49b, 0, &self->pos);
                self->unk1F0 = eff->unk24;
                eff->unkC8 = -1;
                eff->unk28 = 0;
                eff->unk3C = 0x2000;
            }
            if (self->unk19E == data_ov006_021ec884->unk5) {
                func_02049bdc(data_02097e4c, 0x44, 5);
            }
        } else {
            self->unk1FC++;
            if ((self->unk1FC & 0xf) == 0 && self->unk19E == data_ov006_021ec884->unk5) {
                func_02049bdc(data_02097e4c, 0x11, 0xc);
            }
        }
    } else {
        self->unk19C_14 = 0;
    }
}

}
