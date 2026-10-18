#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
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
    u8 flags;
} Query;

typedef struct {
    Query *query;
} Finder;

typedef struct {
    Finder finder;
    Query q;
} FinderQuery;

extern "C" {
s32 func_ov000_021993fc(Finder *self, Query *q, void **out, s32 max);
s32 func_ov000_02199128(Finder *self, Query *q, void **out, s32 max);
void func_ov000_02198360(void *a, s32 b, s32 c);

s32 func_ov000_0219a510(Actor *self, u16 mask, const VecFx32 *pos, s32 r, s32 a, void **list) {
    FinderQuery fq;
    fq.q.unk_18 = 0;
    fq.q.unk_1c = 0;
    fq.q.flags = 0;
    fq.q.unk_12 = 0;
    fq.q.unk_14 = 0;
    fq.q.unk_20 = 0;
    fq.q.unk_24 = 0;
    fq.q.exclude = 0xffff;
    fq.finder.query = NULL;
    fq.q.pos = *pos;
    fq.q.unk_0c = 0;
    fq.q.mask = mask;
    fq.q.kind = 0xffff;
    if (a == 0) {
        fq.q.unk_18 = 0;
        fq.q.unk_1c = r;
        fq.q.flags |= 4;
    } else {
        fq.q.unk_18 = 0;
        fq.q.unk_1c = r;
        fq.q.unk_20 = 0;
        fq.q.unk_24 = a;
        fq.q.flags |= 0xe;
    }
    if (self != NULL) {
        fq.q.exclude = self->id;
    }
    return func_ov000_021993fc(&fq.finder, &fq.q, list, 0x20);
}

}
