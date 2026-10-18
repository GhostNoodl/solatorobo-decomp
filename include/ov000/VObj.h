#ifndef OV000_VOBJ_H
#define OV000_VOBJ_H

#include "types.h"

#ifdef __cplusplus

// Generic polymorphic object used to emit virtual calls by vtable offset.
// vfunc_XX is the function at byte offset XX in the vtable.
class VObj {
public:
    virtual s32 vfunc_00(...);
    virtual s32 vfunc_04(...);
    virtual s32 vfunc_08(...);
    virtual s32 vfunc_0c(...);
    virtual s32 vfunc_10(...);
    virtual s32 vfunc_14(...);
    virtual s32 vfunc_18(...);
    virtual s32 vfunc_1c(...);
    virtual s32 vfunc_20(...);
    virtual s32 vfunc_24(...);
    virtual s32 vfunc_28(...);
    virtual s32 vfunc_2c(...);
    virtual s32 vfunc_30(...);
    virtual s32 vfunc_34(...);
    virtual s32 vfunc_38(...);
    virtual s32 vfunc_3c(...);
    virtual s32 vfunc_40(...);
    virtual s32 vfunc_44(...);
    virtual s32 vfunc_48(...);
    virtual s32 vfunc_4c(...);
    virtual s32 vfunc_50(...);
    virtual s32 vfunc_54(...);
    virtual s32 vfunc_58(...);
    virtual s32 vfunc_5c(...);
    virtual s32 vfunc_60(...);
    virtual s32 vfunc_64(...);
    virtual s32 vfunc_68(...);
    virtual s32 vfunc_6c(...);
    virtual s32 vfunc_70(...);
    virtual s32 vfunc_74(...);
    virtual s32 vfunc_78(...);
    virtual s32 vfunc_7c(...);
    virtual s32 vfunc_80(...);
    virtual s32 vfunc_84(...);
    virtual s32 vfunc_88(...);
    virtual s32 vfunc_8c(...);
    virtual s32 vfunc_90(...);
    virtual s32 vfunc_94(...);
    virtual s32 vfunc_98(...);
    virtual s32 vfunc_9c(...);
    virtual s32 vfunc_a0(...);
    virtual s32 vfunc_a4(...);
    virtual s32 vfunc_a8(...);
    virtual s32 vfunc_ac(...);
    virtual s32 vfunc_b0(...);
    virtual s32 vfunc_b4(...);
    virtual s32 vfunc_b8(...);
    virtual s32 vfunc_bc(...);
    virtual s32 vfunc_c0(...);
    virtual s32 vfunc_c4(...);
    virtual s32 vfunc_c8(...);
    virtual s32 vfunc_cc(...);
    virtual s32 vfunc_d0(...);
    virtual s32 vfunc_d4(...);
    virtual s32 vfunc_d8(...);
    virtual s32 vfunc_dc(...);
    virtual s32 vfunc_e0(...);
    virtual s32 vfunc_e4(...);
    virtual s32 vfunc_e8(...);
    virtual s32 vfunc_ec(...);
    virtual s32 vfunc_f0(...);
    virtual s32 vfunc_f4(...);
    virtual s32 vfunc_f8(...);
    virtual s32 vfunc_fc(...);
    virtual s32 vfunc_100(...);
    virtual s32 vfunc_104(...);
    virtual s32 vfunc_108(...);
    virtual s32 vfunc_10c(...);
    virtual s32 vfunc_110(...);
    virtual s32 vfunc_114(...);
    virtual s32 vfunc_118(...);
    virtual s32 vfunc_11c(...);
    virtual s32 vfunc_120(...);
    virtual s32 vfunc_124(...);
    virtual s32 vfunc_128(...);
    virtual s32 vfunc_12c(...);
    virtual s32 vfunc_130(...);
    virtual s32 vfunc_134(...);
    virtual s32 vfunc_138(...);
    virtual s32 vfunc_13c(...);
};

#define VOBJ_SET_VTABLE(obj, vtbl) (*(void **)(obj) = (void *)(vtbl))
#define VOBJ_AT(obj, offset) ((VObj *)((u8 *)(obj) + (offset)))

#endif

#endif
