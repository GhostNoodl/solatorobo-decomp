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
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Hit0219a5c8;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot0219a5c8;

extern "C" {
s32 func_ov000_021993fc(Finder *self, Query *q, void **out, s32 max);
BOOL func_01ffc624(void *o, const VecFx32 *pos, Rot0219a5c8 *rot, s32 r, s32 a);

s32 func_ov000_0219a5c8(Actor *self, u16 mask, const VecFx32 *pos, Rot0219a5c8 *rot, s32 r, s32 a, void **list) {
    s32 ret;
    if (a == 0 || rot == NULL || (rot->x == 0 && rot->y == 0 && rot->z == 0)) {
        Finder f;
        Query q;
        q.unk_18 = 0;
        q.unk_1c = 0;
        q.flags = 0;
        q.unk_12 = 0;
        q.unk_14 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0;
        q.exclude = 0xffff;
        f.query = NULL;
        q.pos = *pos;
        q.unk_0c = 0;
        q.mask = mask;
        q.kind = 0xffff;
        if (a == 0) {
            q.unk_18 = 0;
            q.unk_1c = r;
            q.flags |= 4;
        } else {
            q.unk_18 = 0;
            q.unk_1c = r;
            q.unk_20 = 0;
            q.unk_24 = a;
            q.flags |= 0xe;
        }
        if (self != NULL) {
            q.exclude = self->id;
        }
        ret = func_ov000_021993fc(&f, &q, list, 0x20);
    } else {
        void *tmp[0x20];
        Finder f;
        Query q;
        s32 n;
        s32 cnt;
        s32 i;
        q.unk_18 = 0;
        q.unk_1c = 0;
        q.flags = 0;
        q.unk_12 = 0;
        q.unk_14 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0;
        q.exclude = 0xffff;
        f.query = NULL;
        q.pos = *pos;
        q.unk_0c = 0;
        q.mask = mask;
        q.kind = 0xffff;
        q.unk_18 = 0;
        q.unk_1c = r + a;
        q.flags |= 4;
        if (self != NULL) {
            q.exclude = self->id;
        }
        n = func_ov000_021993fc(&f, &q, tmp, 0x20);
        cnt = 0;
        for (i = 0; i < n; i++) {
            void *o = tmp[i];
            if (o != NULL) {
                BOOL hit;
                if (LFLD(Hit0219a5c8, o, 0x22).b0 == 1 && LFLD(Hit0219a5c8, o, 0x22).b1 == 1) {
                    hit = func_01ffc624(o, pos, rot, r + LFLD(s32, o, 0x1c), a);
                } else {
                    hit = FALSE;
                }
                if (hit) {
                    list[cnt++] = tmp[i];
                }
            }
        }
        ret = cnt;
    }
    return ret;
}

}
