#include "ov000/LoCommon.h"

extern "C" {

extern u8 Ov000Vt_021cabd8_vtbl[];
void *ResSet_ReleaseAll(void *p);
void ResSet_SetName0(void *p, s32 a, s32 b, s32 c, s32 d);
void ResSet_SetName1(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));

// The mixed (u8 *) casts below are no-ops, but they change which
// addresses MWCC shares between the calls; this mix matches.
// Kept (round auA honesty audit): plain, typed-struct and slot-pointer forms all differ.
// Kept rather than demoted: a cast macro used at some call sites
// (and not at others) plausibly gives the same mix in the original.
static inline void StopSlot(u8 *self, u8 i) {
    if (i > 2) {
        return;
    }
    ResSet_SetName0(self + 0x78 + i * 0x138, 0, 0, 1, 0);
    ResSet_SetName1((u8 *)self + 0x78 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, self + i * 0x138, 0x78) = 0;
    ResSet_SetName1(self + 0x2e8 + i * 0x138, 0, 0, 1, 0);
    LFLD(u16, (u8 *)self + i * 0x138, 0x2e8) = 0;
}

static inline void Dtor02161cd4(u8 *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cabd8_vtbl);
    StopSlot(self, LFLD(u8, self, 5));
    StopSlot(self, (LFLD(u8, self, 5) & 1) ^ 1);
    __cxa_vec_cleanup(self + 0x2e8, 2, 0x138, (void (*)(void *))ResSet_ReleaseAll);
    __cxa_vec_cleanup(self + 0x78, 2, 0x138, (void (*)(void *))ResSet_ReleaseAll);
}

u8 *Ov000Vt_021cabd8_Dtor(u8 *self) {
    Dtor02161cd4(self);
    return self;
}

u8 *Ov000Vt_021cabd8_DtorDelete(u8 *self) {
    Dtor02161cd4(self);
    Heap_Free(self);
    return self;
}

}
