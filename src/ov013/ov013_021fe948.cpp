#include "ov013/ov013.h"

struct Ov013Spot {
    VecFx32 pos;
    u16 rot;
};

extern "C" {

extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern BOOL Ov003Vec_Equal(void *a, const Ov013Spot *b);

void func_ov013_021fe948(VecFx32 *outPos, u16 *outRot, const Ov013Spot *list, u32 count, void *exclude) {
    s32 n = 0;
    Ov013Spot tmp[8];
    u32 i;
    s32 r;
    for (i = 0; i < count; i++) {
        if (exclude != NULL && Ov003Vec_Equal(exclude, &list[i])) {
            continue;
        }
        tmp[n] = list[i];
        n++;
    }
    r = Rand_UpTo(n - 1);
    *outPos = tmp[r].pos;
    *outRot = tmp[r].rot;
}

static inline Ov003Actor *Ov013_ListNext(void *list, Ov003Actor *a) {
    if (a != NULL) {
        return static_cast<Ov003Actor *>(a->next); // the group lists only ov003 actors here
    }
    return FLD(Ov003Actor *, list, 0xc);
}

u32 func_ov013_021fe9f8(Ov003Actor **out, u32 max, u16 kind, const VecFx32 *pos, s32 dist) {
    u32 n = 0;
    void *list = ActorMgr_GetGroup(data_ov000_021ccd68, kind);
    Ov003Actor *a = FLD(Ov003Actor *, list, 0xc);
    for (; a != NULL; a = Ov013_ListNext(list, a)) {
        if (kind == a->kind && Hit_DiffInSphere(&a->pos, (VecFx32 *)pos, dist + a->radius)) {
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
