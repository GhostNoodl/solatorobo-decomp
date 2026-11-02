#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "ov006/Racer.h"

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


extern "C" {

extern const char data_ov006_021ec48c[];
extern const char data_ov006_021ec49b[];

s32 func_ov000_02199128(ov006_Finder021e7fe4 *self, ov006_Query021e7fe4 *q, void **out, s32 max);
s32 func_02049bdc(SndMgr *a, s32 b, s32 c);

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

void func_ov006_021e7fe4(Ov006Racer *self) {
    BOOL found = FALSE;
    if (self->unk_19c_0 & 1) {
        ov006_FinderQuery021e7fe4 fq;
        Actor *hits[0x20];
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
            Actor *h = hits[i];
            if (h->target == self->id) {
                found = TRUE;
                break;
            }
        }
    }
    if (found) {
        if (!self->unk_19c_14) {
            self->unk_19c_14 = 1;
            self->unk_1fc = 0;
            if (self->unk_1f0 == 0) {
                EffectObj *eff = Effect3D_Create(data_ov006_021ec48c, data_ov006_021ec49b, 0, &self->pos);
                self->unk_1f0 = eff->id;
                eff->loopCount = -1;
                eff->unk_28 = 0;
                eff->speed = 0x2000;
            }
            if (self->idx == data_ov006_021ec884->unk5) {
                func_02049bdc(data_02097e4c, 0x44, 5);
            }
        } else {
            self->unk_1fc++;
            if ((self->unk_1fc & 0xf) == 0 && self->idx == data_ov006_021ec884->unk5) {
                func_02049bdc(data_02097e4c, 0x11, 0xc);
            }
        }
    } else {
        self->unk_19c_14 = 0;
    }
}

}
