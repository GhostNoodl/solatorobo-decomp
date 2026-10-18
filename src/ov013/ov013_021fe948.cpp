#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

extern "C" {

extern void *data_ov000_021ccd68;
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov003_021d98bc(void *a, const Ov013Spot *b);

void func_ov013_021fe948(Ov013Vec *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude) {
    s32 n = 0;
    Ov013Spot tmp[8];
    u32 i;
    s32 r;
    for (i = 0; i < count; i++) {
        if (exclude != NULL && func_ov003_021d98bc(exclude, &list[i])) {
            continue;
        }
        tmp[n] = list[i];
        n++;
    }
    r = func_02040498(n - 1);
    *outPos = tmp[r].pos;
    *outRot = tmp[r].rot;
}

static inline Ov013Actor *Ov013_ListNext(void *list, Ov013Actor *a) {
    if (a != NULL) {
        return FLD(Ov013Actor *, a, 8);
    }
    return FLD(Ov013Actor *, list, 0xc);
}

u32 func_ov013_021fe9f8(Ov013Actor **out, u32 max, u16 kind, const Ov013Vec *pos, s32 dist) {
    u32 n = 0;
    void *list = func_ov000_0218e4cc(data_ov000_021ccd68, kind);
    Ov013Actor *a = FLD(Ov013Actor *, list, 0xc);
    for (; a != NULL; a = Ov013_ListNext(list, a)) {
        if (kind == a->kind && func_01ffc198(&a->pos, pos, dist + a->unk_64)) {
            if (n >= max) {
                break;
            }
            out[n] = a;
            n++;
        }
    }
    return n;
}

}
