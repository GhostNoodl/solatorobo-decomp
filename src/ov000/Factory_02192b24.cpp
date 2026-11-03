#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"

/* Actor factory: picks the class from the actor info type, then from the id. */

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad[0x18];
    u8 type;
} Info02192b24;

typedef struct {
    u16 id;
    u16 sub;
} Spawn02192b24;

extern "C" {

extern u8 Ov003ActVt_021f7d4c_vtbl[];
extern u8 Ov003ActVt_021f7de4_vtbl[];
extern u8 Ov003ActVt_021f7e7c_vtbl[];
extern u8 Ov003ActVt_021f7f14_vtbl[];
extern u8 Ov003ActVt_021f7fac_vtbl[];
extern u8 Ov003ActVt_021f8058_vtbl[];
extern u8 Ov003ActVt_021f80f0_vtbl[];
extern u8 Ov003ActVt_021f8188_vtbl[];
extern u8 Ov003ActVt_021f8220_vtbl[];
extern u8 Ov003ActVt_021f82b8_vtbl[];
extern u8 Ov003ActVt_021f8350_vtbl[];
extern u8 Ov003ActVt_021f83e8_vtbl[];
extern u8 Ov003ActVt_021f8480_vtbl[];
extern u8 Ov003ActVt_021f8638_vtbl[];
extern u8 Ov003ActVt_021f86d0_vtbl[];
extern u8 Ov003ActVt_021f8768_vtbl[];
extern u8 Ov003ActVt_021f8800_vtbl[];
extern u8 Ov003ActVt_021f8898_vtbl[];
extern u8 Ov003ActVt_021f8930_vtbl[];
extern u8 Ov003ActVt_021f89c8_vtbl[];
extern u8 Ov003ActVt_021f8a60_vtbl[];
extern u8 Ov003ActVt_021f8af8_vtbl[];
extern u8 Ov003ActVt_021f8b90_vtbl[];
extern u8 Ov003ActVt_021f8c28_vtbl[];
extern u8 Ov003ActVt_021f8cc0_vtbl[];
extern u8 Ov003ActVt_021f8d58_vtbl[];
extern u8 Ov003ActVt_021f8df0_vtbl[];
extern u8 Ov003ActVt_021f8e88_vtbl[];
extern u8 Ov003ActVt_021f8f20_vtbl[];
extern u8 Ov003ActVt_021f8fb8_vtbl[];
extern u8 Ov003ActVt_021f9050_vtbl[];
extern u8 Ov003ActVt_021f9114_vtbl[];
extern u8 Ov003ActVt_021f91ac_vtbl[];
extern u8 Ov003ActVt_021f9244_vtbl[];
extern u8 Ov003ActVt_021f92dc_vtbl[];
extern u8 Ov003ActVt_021f9374_vtbl[];
extern u8 Ov003ActVt_021f940c_vtbl[];
extern u8 Ov003ActVt_021f94a4_vtbl[];
extern u8 Ov003ActVt_021f953c_vtbl[];
extern u8 Ov003ActVt_021f95d4_vtbl[];
extern u8 Ov003ActVt_021f966c_vtbl[];
extern u8 Ov003ActVt_021f9704_vtbl[];
extern u8 Ov003ActVt_021f979c_vtbl[];
extern u8 Ov003ActVt_021f9834_vtbl[];
extern u8 Ov003ActVt_021f98cc_vtbl[];
extern u8 Ov003ActVt_021f9a80_vtbl[];
extern u8 Ov003ActVt_021f9b18_vtbl[];
extern u8 Ov003ActVt_021f9bb0_vtbl[];
extern u8 Ov003ActVt_021f9c48_vtbl[];
extern u8 Ov003ActVt_021f9ce0_vtbl[];
extern u8 Ov003ActVt_021f9d78_vtbl[];
extern u8 Ov003ActVt_021f9e10_vtbl[];
extern u8 Ov003ActVt_021f9ea8_vtbl[];
extern u8 Ov003ActVt_021f9f40_vtbl[];
extern u8 Ov003ActVt_021f9fe4_vtbl[];
extern u8 Ov003ActVt_021fa07c_vtbl[];
extern u8 Ov003ActVt_021fa114_vtbl[];
extern u8 Ov006ActVt_021ec54c_vtbl[];
extern u8 Ov006ActVt_021ec5e4_vtbl[];
extern u8 Ov006ActVt_021ec67c_vtbl[];
extern u8 Ov006ActVt_021ec714_vtbl[];
extern u8 Ov006ActVt_021ec7ac_vtbl[];
extern u8 data_ov009_02217838[];
extern u8 data_ov009_022178d0[];
extern u8 Ov009ActExVt_0221802c_vtbl[];
extern u8 Ov009ActVt_022180c4_vtbl[];
extern u8 Ov009ActVt_0221815c_vtbl[];
extern u8 Ov009ActExVt_022181f4_vtbl[];
extern u8 Ov009ActExVt_0221828c_vtbl[];
extern u8 Ov009ActVt_02218324_vtbl[];
extern u8 Ov012ActExVt_0220af10_vtbl[];
extern u8 Ov012ActExVt_0220b150_vtbl[];
extern u8 Ov012ActExVt_0220b1e8_vtbl[];
extern u8 Ov013ActExVt_0220b7d0_vtbl[];
void *Heap_Alloc(u32 size);
Info02192b24 *Tbl_Elem_020704b4(u16 id);
s32 Tbl_GetText(u16 id);
void *ResSet_Init(void *p);
void *Model0218fe1c_Init(void *p);
void *ActorEx_Ctor(void *p);
void *ActorEx_CtorBase(void *p);
void *func_ov000_02193e34(void *p);
void *func_ov000_02193e48(void *p);
void Actor_JoinGroup(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *Ov003ActVt_021f99e8_Ctor(void *p);
void *Ov010ActVt_0220fe6c_Ctor(void *p);
void *Ov010ActVt_02210378_Ctor(void *p);
void *Ov013ActEx_0220a9a8_Ctor(void *p);
void *Ov010ActVt_022102e0_Ctor(void *p);
void *Ov011Npc_Ctor(void *p);
void *Ov012ActEx_02207018_Ctor(void *p);
void *Ov013ActEx_021fdb70_Ctor(void *p);
void *Ov013ActEx_02204454_Ctor(void *p);
void *Ov013ActEx_02205ae4_Ctor(void *p);
void *Ov013ActEx_022065ac_Ctor(void *p);
void *Ov013ActEx_0220a4e0_Ctor(void *p);
void *Ov014ActEx_021fbd64_Ctor(void *p);
void *Ov014ActEx_021fc24c_Ctor(void *p);
void *Ov014ActEx_02206c68_Ctor(void *p);
void *Ov014ActEx_0220774c_Ctor(void *p);
void *Ov014ActEx_02208618_Ctor(void *p);
void *Ov014ActEx_0220d70c_Ctor(void *p);
void *Ov014ActEx_0220dcf4_Ctor(void *p);
void *Ov014ActEx_0220eca0_Ctor(void *p);
void *Ov014ActEx_022142fc_Ctor(void *p);
void *Ov014ActEx_022152e8_Ctor(void *p);

#define Base(p) ActorEx_Ctor(p)

/* Allocates an object built by an out-of-line constructor that returns it. */
#define NEW_CTOR(size, ctor)                   \
    {                                          \
        u8 *t = (u8 *)Heap_Alloc(size);     \
        if (t != NULL) {                       \
            t = (u8 *)ctor(t);                 \
        }                                      \
        p = t;                                 \
    }

/* Allocates an object with the shared base constructor and its own vtable. */
#define NEW_BASIC(size, vt)                    \
    {                                          \
        u8 *t = (u8 *)Heap_Alloc(size);     \
        if (t != NULL) {                       \
            Base(t);                           \
            VOBJ_SET_VTABLE(t, vt);         \
        }                                      \
        p = t;                                 \
    }

u8 *Factory_New4000(Spawn02192b24 *s) {
    u8 *p;
    switch (Tbl_Elem_020704b4(s->id)->type) {
    default:
    case 0:
        switch (s->id) {
        default:
            NEW_CTOR(0xd0, ActorEx_CtorBase);
            break;
        case 0x4009:
        case 0x4058:
            {
                u8 *t = (u8 *)Heap_Alloc(0x20c);
                if (t != NULL) {
                    Base(t);
                    VOBJ_SET_VTABLE(t, Ov003ActVt_021f8a60_vtbl);
                    ResSet_Init(t + 0xd0);
                }
                p = t;
            }
            break;
        case 0x4012:
        case 0x4705:
            NEW_BASIC(0xd0, Ov003ActVt_021f8fb8_vtbl);
            break;
        case 0x4013:
            NEW_BASIC(0xd0, Ov003ActVt_021f8cc0_vtbl);
            break;
        case 0x483e:
            NEW_CTOR(0xfc, Ov013ActEx_02204454_Ctor);
            break;
        case 0x4808:
        case 0x4809:
            NEW_CTOR(0xf0, Ov013ActEx_02205ae4_Ctor);
            break;
        case 0x4807:
            NEW_CTOR(0xf8, Ov013ActEx_022065ac_Ctor);
            break;
        case 0x480f:
            NEW_BASIC(0xe4, Ov012ActExVt_0220af10_vtbl);
            break;
        case 0x4811:
            NEW_CTOR(0xe0, Ov013ActEx_0220a4e0_Ctor);
            break;
        case 0x4813:
            NEW_CTOR(0xd8, Ov013ActEx_0220a9a8_Ctor);
            break;
        case 0x4812:
            NEW_CTOR(0xfc, Ov011Npc_Ctor);
            break;
        case 0x4815:
            NEW_CTOR(0xe4, Ov014ActEx_022142fc_Ctor);
            break;
        case 0x4814:
            NEW_CTOR(0xf8, Ov014ActEx_022152e8_Ctor);
            break;
        case 0x4819:
            NEW_CTOR(0xe0, Ov014ActEx_0220d70c_Ctor);
            break;
        case 0x481d:
            NEW_CTOR(0xdc, Ov014ActEx_0220dcf4_Ctor);
            break;
        case 0x481e:
            NEW_CTOR(0xf8, Ov014ActEx_0220eca0_Ctor);
            break;
        case 0x4817:
            NEW_CTOR(0x19c, Ov010ActVt_02210378_Ctor);
            break;
        case 0x4818:
            NEW_CTOR(0x100, Ov010ActVt_022102e0_Ctor);
            break;
        case 0x4820:
            NEW_BASIC(0xdc, Ov013ActExVt_0220b7d0_vtbl);
            break;
        case 0x4823:
            NEW_CTOR(0xd8, Ov013ActEx_021fdb70_Ctor);
            break;
        case 0x4821:
            NEW_CTOR(0xd4, Ov014ActEx_021fbd64_Ctor);
            break;
        case 0x4822:
            NEW_CTOR(0x104, Ov014ActEx_021fc24c_Ctor);
            break;
        case 0x4824:
            {
                u8 *t = (u8 *)Heap_Alloc(0x2fc);
                if (t != NULL) {
                    Base(t);
                    VOBJ_SET_VTABLE(t, Ov012ActExVt_0220b1e8_vtbl);
                    ResSet_Init(t + 0xd8);
                    Model0218fe1c_Init(t + 0x210);
                }
                p = t;
            }
            break;
        case 0x4825:
            NEW_BASIC(0xe8, Ov012ActExVt_0220b150_vtbl);
            break;
        case 0x4826:
            NEW_CTOR(0xd8, Ov012ActEx_02207018_Ctor);
            break;
        case 0x4827:
            NEW_BASIC(0xe8, data_ov009_022178d0);
            break;
        case 0x4828:
            NEW_BASIC(0xec, data_ov009_02217838);
            break;
        case 0x482a:
            NEW_CTOR(0xdc, Ov014ActEx_02208618_Ctor);
            break;
        case 0x482b:
            NEW_CTOR(0xe0, Ov014ActEx_02206c68_Ctor);
            break;
        case 0x482c:
            NEW_CTOR(0xdc, Ov014ActEx_0220774c_Ctor);
            break;
        case 0x4829:
            NEW_CTOR(0x114, Ov010ActVt_0220fe6c_Ctor);
            break;
        case 0x482d:
            NEW_BASIC(0xdc, Ov009ActExVt_0221802c_vtbl);
            break;
        case 0x401f:
            NEW_BASIC(0xd0, Ov003ActVt_021f8df0_vtbl);
            break;
        case 0x4032:
        case 0x4093:
            NEW_BASIC(0xd0, Ov003ActVt_021f8480_vtbl);
            break;
        case 0x4029:
            NEW_BASIC(0xd4, Ov003ActVt_021f83e8_vtbl);
            break;
        case 0x4036:
            NEW_BASIC(0xd0, Ov003ActVt_021f8188_vtbl);
            break;
        case 0x4037:
            NEW_BASIC(0xd4, Ov003ActVt_021f8350_vtbl);
            break;
        case 0x4041:
            NEW_BASIC(0xd0, Ov003ActVt_021f8220_vtbl);
            break;
        case 0x4040:
        case 0x4056:
            NEW_BASIC(0xd0, Ov003ActVt_021f8b90_vtbl);
            break;
        case 0x404a:
            NEW_BASIC(0xd0, Ov003ActVt_021f9ce0_vtbl);
            break;
        case 0x4628:
            {
                u8 *t = (u8 *)Heap_Alloc(0xb1c);
                if (t != NULL) {
                    Base(t);
                    VOBJ_SET_VTABLE(t, Ov003ActVt_021f8af8_vtbl);
                    ResSet_Init(t + 0xd0);
                    ResSet_Init(t + 0x208);
                    Model0218fe1c_Init(t + 0x340);
                    __cxa_vec_ctor(t + 0x46c, 4, 0x98, (void (*)(void *))func_ov000_02193e34, (void (*)(void *))func_ov000_02193e48);
                    __cxa_vec_ctor(t + 0x6cc, 4, 0x98, (void (*)(void *))func_ov000_02193e34, (void (*)(void *))func_ov000_02193e48);
                    __cxa_vec_ctor(t + 0x92c, 3, 0x98, (void (*)(void *))func_ov000_02193e34, (void (*)(void *))func_ov000_02193e48);
                }
                p = t;
            }
            break;
        case 0x404b:
        case 0x404c:
        case 0x404d:
            NEW_BASIC(0xd0, Ov003ActVt_021f8930_vtbl);
            break;
        case 0x4055:
            NEW_BASIC(0xd0, Ov003ActVt_021f86d0_vtbl);
            break;
        case 0x406b:
            NEW_BASIC(0xd0, Ov003ActVt_021f966c_vtbl);
            break;
        case 0x4078:
            NEW_BASIC(0xd4, Ov003ActVt_021f95d4_vtbl);
            break;
        case 0x4073:
            NEW_BASIC(0xd0, Ov003ActVt_021f9244_vtbl);
            break;
        case 0x4071:
            NEW_BASIC(0xd4, Ov003ActVt_021f9114_vtbl);
            break;
        case 0x4072:
            {
                u8 *t = (u8 *)Heap_Alloc(0x1c0);
                if (t != NULL) {
                    Base(t);
                    VOBJ_SET_VTABLE(t, Ov003ActVt_021f953c_vtbl);
                    Model0218fe1c_Init(t + 0xd0);
                }
                p = t;
            }
            break;
        case 0x4076:
        case 0x4086:
            NEW_BASIC(0xf0, Ov003ActVt_021f9374_vtbl);
            break;
        case 0x405c:
        case 0x407b:
        case 0x407c:
        case 0x407d:
            NEW_BASIC(0xd4, Ov003ActVt_021f91ac_vtbl);
            break;
        case 0x408b:
            NEW_BASIC(0xdc, Ov003ActVt_021f94a4_vtbl);
            break;
        case 0x408c:
            NEW_BASIC(0x104, Ov003ActVt_021f940c_vtbl);
            break;
        case 0x4074:
            NEW_BASIC(0xd0, Ov003ActVt_021f92dc_vtbl);
            break;
        case 0x4047:
        case 0x405d:
        case 0x405f:
        case 0x407e:
        case 0x407f:
        case 0x4080:
        case 0x4082:
        case 0x4090:
            NEW_BASIC(0xd4, Ov003ActVt_021f8f20_vtbl);
            break;
        case 0x4030:
            NEW_BASIC(0xd0, Ov003ActVt_021f8e88_vtbl);
            break;
        case 0x404f:
            NEW_BASIC(0x104, Ov003ActVt_021f80f0_vtbl);
            break;
        case 0x409f:
            NEW_BASIC(0xd0, Ov003ActVt_021f8058_vtbl);
            break;
        case 0x4084:
            NEW_BASIC(0xd0, Ov003ActVt_021f9c48_vtbl);
            break;
        case 0x4085:
            NEW_BASIC(0xd0, Ov003ActVt_021f9bb0_vtbl);
            break;
        case 0x4063:
        case 0x4064:
        case 0x4065:
        case 0x4066:
            NEW_CTOR(0x214, Ov003ActVt_021f99e8_Ctor);
            break;
        case 0x4075:
            NEW_BASIC(0xd0, Ov003ActVt_021f9b18_vtbl);
            break;
        case 0x482e:
        case 0x483f:
            NEW_BASIC(0xf4, Ov003ActVt_021f9a80_vtbl);
            break;
        case 0x4083:
        case 0x408f:
        case 0x4096:
            NEW_BASIC(0xd4, Ov009ActExVt_0221828c_vtbl);
            break;
        case 0x4830:
            NEW_BASIC(0xd0, Ov009ActVt_02218324_vtbl);
            break;
        case 0x482f:
            NEW_BASIC(0xd0, Ov009ActVt_022180c4_vtbl);
            break;
        case 0x4802:
            NEW_BASIC(0xd4, Ov009ActExVt_022181f4_vtbl);
            break;
        case 0x4092:
            NEW_BASIC(0xd0, Ov009ActVt_0221815c_vtbl);
            break;
        case 0x4f40:
            NEW_BASIC(0xd0, Ov006ActVt_021ec7ac_vtbl);
            break;
        case 0x4f41:
            NEW_BASIC(0xd0, Ov006ActVt_021ec54c_vtbl);
            break;
        case 0x4f42:
        case 0x4f45:
            NEW_BASIC(0xd0, Ov006ActVt_021ec5e4_vtbl);
            break;
        case 0x4f43:
            NEW_BASIC(0xd0, Ov006ActVt_021ec67c_vtbl);
            break;
        case 0x4f44:
            NEW_BASIC(0xd0, Ov006ActVt_021ec714_vtbl);
            break;
        case 0x4044:
            NEW_BASIC(0xd0, Ov003ActVt_021f8d58_vtbl);
            break;
        }
        break;
    case 1:
        NEW_BASIC(0xd0, Ov003ActVt_021f98cc_vtbl);
        break;
    case 2:
        {
            u8 *t = (u8 *)Heap_Alloc(0x304);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f9834_vtbl);
                ResSet_Init(t + 0xd0);
                Model0218fe1c_Init(t + 0x208);
            }
            p = t;
        }
        break;
    case 3:
        {
            u8 *t = (u8 *)Heap_Alloc(0x314);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f9704_vtbl);
                ResSet_Init(t + 0xd0);
                Model0218fe1c_Init(t + 0x208);
                LFLD(u16, t, 0x2fc) = 0;
                LFLD(u16, t, 0x2fe) = 0;
            }
            p = t;
        }
        break;
    case 4:
        {
            u8 *t = (u8 *)Heap_Alloc(0x304);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f979c_vtbl);
                ResSet_Init(t + 0xd0);
                Model0218fe1c_Init(t + 0x208);
            }
            p = t;
        }
        break;
    case 8:
        NEW_BASIC(0xd0, Ov003ActVt_021f9f40_vtbl);
        break;
    case 9:
        NEW_BASIC(0xd0, Ov003ActVt_021f9ea8_vtbl);
        break;
    case 10:
        NEW_BASIC(0xd4, Ov003ActVt_021f9e10_vtbl);
        break;
    case 11:
        NEW_BASIC(0xd0, Ov003ActVt_021f9d78_vtbl);
        break;
    case 5:
        NEW_BASIC(0xd0, Ov003ActVt_021f7fac_vtbl);
        break;
    case 6:
        NEW_BASIC(0xd0, Ov003ActVt_021f7f14_vtbl);
        break;
    case 7:
        NEW_BASIC(0xd0, Ov003ActVt_021f7e7c_vtbl);
        break;
    case 12:
        NEW_BASIC(0xf4, Ov003ActVt_021f7de4_vtbl);
        break;
    case 13:
        NEW_BASIC(0xfc, Ov003ActVt_021f7d4c_vtbl);
        break;
    case 14:
        {
            u8 *t = (u8 *)Heap_Alloc(0x218);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f8638_vtbl);
                ResSet_Init(t + 0xd0);
            }
            p = t;
        }
        break;
    case 15:
        NEW_BASIC(0xd0, Ov003ActVt_021f9050_vtbl);
        break;
    case 16:
        {
            u8 *t = (u8 *)Heap_Alloc(0x208);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f8c28_vtbl);
                ResSet_Init(t + 0xd0);
            }
            p = t;
        }
        break;
    case 17:
        {
            u8 *t = (u8 *)Heap_Alloc(0x208);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f89c8_vtbl);
                ResSet_Init(t + 0xd0);
            }
            p = t;
        }
        break;
    case 18:
        NEW_BASIC(0xd0, Ov003ActVt_021f8800_vtbl);
        break;
    case 19:
        NEW_BASIC(0xd0, Ov003ActVt_021fa07c_vtbl);
        break;
    case 20:
        NEW_BASIC(0xd0, Ov003ActVt_021fa114_vtbl);
        break;
    case 21:
        NEW_BASIC(0xe0, Ov003ActVt_021f9fe4_vtbl);
        break;
    case 22:
        {
            u8 *t = (u8 *)Heap_Alloc(0xe0);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f8898_vtbl);
                LFLD(u16, t, 0xd0) = 0;
                LFLD(u16, t, 0xd2) = 0;
            }
            p = t;
        }
        break;
    case 23:
        {
            u8 *t = (u8 *)Heap_Alloc(0x214);
            if (t != NULL) {
                Base(t);
                VOBJ_SET_VTABLE(t, Ov003ActVt_021f8768_vtbl);
                ResSet_Init(t + 0xd0);
                LFLD(s32, t, 0x208) = 0;
            }
            p = t;
        }
        break;
    case 24:
        NEW_BASIC(0xd0, Ov003ActVt_021f82b8_vtbl);
        break;
    }
    if (p != NULL) {
        Actor_JoinGroup(p, s->sub, s->id, Tbl_GetText(s->id));
        *(FieldId *)(p + 0xac) = gSceneCmd->unk_ca;
    }
    return p;
}

}
