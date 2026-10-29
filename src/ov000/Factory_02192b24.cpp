#include "types.h"

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

typedef struct {
    u8 v[3];
} Rgb02192b24;

extern "C" {

extern u8 data_ov003_021f7d4c[];
extern u8 data_ov003_021f7de4[];
extern u8 data_ov003_021f7e7c[];
extern u8 data_ov003_021f7f14[];
extern u8 data_ov003_021f7fac[];
extern u8 data_ov003_021f8058[];
extern u8 data_ov003_021f80f0[];
extern u8 data_ov003_021f8188[];
extern u8 data_ov003_021f8220[];
extern u8 data_ov003_021f82b8[];
extern u8 data_ov003_021f8350[];
extern u8 data_ov003_021f83e8[];
extern u8 data_ov003_021f8480[];
extern u8 data_ov003_021f8638[];
extern u8 data_ov003_021f86d0[];
extern u8 data_ov003_021f8768[];
extern u8 data_ov003_021f8800[];
extern u8 data_ov003_021f8898[];
extern u8 data_ov003_021f8930[];
extern u8 data_ov003_021f89c8[];
extern u8 data_ov003_021f8a60[];
extern u8 data_ov003_021f8af8[];
extern u8 data_ov003_021f8b90[];
extern u8 data_ov003_021f8c28[];
extern u8 data_ov003_021f8cc0[];
extern u8 data_ov003_021f8d58[];
extern u8 data_ov003_021f8df0[];
extern u8 data_ov003_021f8e88[];
extern u8 data_ov003_021f8f20[];
extern u8 data_ov003_021f8fb8[];
extern u8 data_ov003_021f9050[];
extern u8 data_ov003_021f9114[];
extern u8 data_ov003_021f91ac[];
extern u8 data_ov003_021f9244[];
extern u8 data_ov003_021f92dc[];
extern u8 data_ov003_021f9374[];
extern u8 data_ov003_021f940c[];
extern u8 data_ov003_021f94a4[];
extern u8 data_ov003_021f953c[];
extern u8 data_ov003_021f95d4[];
extern u8 data_ov003_021f966c[];
extern u8 data_ov003_021f9704[];
extern u8 data_ov003_021f979c[];
extern u8 data_ov003_021f9834[];
extern u8 data_ov003_021f98cc[];
extern u8 data_ov003_021f9a80[];
extern u8 data_ov003_021f9b18[];
extern u8 data_ov003_021f9bb0[];
extern u8 data_ov003_021f9c48[];
extern u8 data_ov003_021f9ce0[];
extern u8 data_ov003_021f9d78[];
extern u8 data_ov003_021f9e10[];
extern u8 data_ov003_021f9ea8[];
extern u8 data_ov003_021f9f40[];
extern u8 data_ov003_021f9fe4[];
extern u8 data_ov003_021fa07c[];
extern u8 data_ov003_021fa114[];
extern u8 data_ov006_021ec54c[];
extern u8 data_ov006_021ec5e4[];
extern u8 data_ov006_021ec67c[];
extern u8 data_ov006_021ec714[];
extern u8 data_ov006_021ec7ac[];
extern u8 data_ov009_02217838[];
extern u8 data_ov009_022178d0[];
extern u8 data_ov009_0221802c[];
extern u8 data_ov009_022180c4[];
extern u8 data_ov009_0221815c[];
extern u8 data_ov009_022181f4[];
extern u8 data_ov009_0221828c[];
extern u8 data_ov009_02218324[];
extern u8 data_ov012_0220af10[];
extern u8 data_ov012_0220b150[];
extern u8 data_ov012_0220b1e8[];
extern u8 data_ov013_0220b7d0[];
extern u8 *data_ov000_021ccd54;
void *func_0203dd9c(u32 size);
Info02192b24 *func_020704b4(u16 id);
s32 func_0206ffa0(u16 id);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void *func_ov000_02194074(void *p);
void *func_ov000_021940e4(void *p);
void *func_ov000_02193e34(void *p);
void *func_ov000_02193e48(void *p);
void func_ov000_0218d1c0(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *func_ov003_021ec31c(void *p);
void *func_ov010_022020c8(void *p);
void *func_ov010_0220a6b0(void *p);
void *func_ov013_0220a9a8(void *p);
void *func_ov010_0220dd60(void *p);
void *func_ov011_02200e84(void *p);
void *func_ov012_02207018(void *p);
void *func_ov013_021fdb70(void *p);
void *func_ov013_02204454(void *p);
void *func_ov013_02205ae4(void *p);
void *func_ov013_022065ac(void *p);
void *func_ov013_0220a4e0(void *p);
void *func_ov014_021fbd64(void *p);
void *func_ov014_021fc24c(void *p);
void *func_ov014_02206c68(void *p);
void *func_ov014_0220774c(void *p);
void *func_ov014_02208618(void *p);
void *func_ov014_0220d70c(void *p);
void *func_ov014_0220dcf4(void *p);
void *func_ov014_0220eca0(void *p);
void *func_ov014_022142fc(void *p);
void *func_ov014_022152e8(void *p);

#define Base(p) func_ov000_02194074(p)

/* Allocates an object built by an out-of-line constructor that returns it. */
#define NEW_CTOR(size, ctor)                   \
    {                                          \
        u8 *t = (u8 *)func_0203dd9c(size);     \
        if (t != NULL) {                       \
            t = (u8 *)ctor(t);                 \
        }                                      \
        p = t;                                 \
    }

/* Allocates an object with the shared base constructor and its own vtable. */
#define NEW_BASIC(size, vt)                    \
    {                                          \
        u8 *t = (u8 *)func_0203dd9c(size);     \
        if (t != NULL) {                       \
            Base(t);                           \
            LFLD(void *, t, 0) = (vt);         \
        }                                      \
        p = t;                                 \
    }

u8 *func_ov000_02192b24(Spawn02192b24 *s) {
    u8 *p;
    switch (func_020704b4(s->id)->type) {
    default:
    case 0:
        switch (s->id) {
        default:
            NEW_CTOR(0xd0, func_ov000_021940e4);
            break;
        case 0x4009:
        case 0x4058:
            {
                u8 *t = (u8 *)func_0203dd9c(0x20c);
                if (t != NULL) {
                    Base(t);
                    LFLD(void *, t, 0) = data_ov003_021f8a60;
                    func_ov000_0218e9c4(t + 0xd0);
                }
                p = t;
            }
            break;
        case 0x4012:
        case 0x4705:
            NEW_BASIC(0xd0, data_ov003_021f8fb8);
            break;
        case 0x4013:
            NEW_BASIC(0xd0, data_ov003_021f8cc0);
            break;
        case 0x483e:
            NEW_CTOR(0xfc, func_ov013_02204454);
            break;
        case 0x4808:
        case 0x4809:
            NEW_CTOR(0xf0, func_ov013_02205ae4);
            break;
        case 0x4807:
            NEW_CTOR(0xf8, func_ov013_022065ac);
            break;
        case 0x480f:
            NEW_BASIC(0xe4, data_ov012_0220af10);
            break;
        case 0x4811:
            NEW_CTOR(0xe0, func_ov013_0220a4e0);
            break;
        case 0x4813:
            NEW_CTOR(0xd8, func_ov013_0220a9a8);
            break;
        case 0x4812:
            NEW_CTOR(0xfc, func_ov011_02200e84);
            break;
        case 0x4815:
            NEW_CTOR(0xe4, func_ov014_022142fc);
            break;
        case 0x4814:
            NEW_CTOR(0xf8, func_ov014_022152e8);
            break;
        case 0x4819:
            NEW_CTOR(0xe0, func_ov014_0220d70c);
            break;
        case 0x481d:
            NEW_CTOR(0xdc, func_ov014_0220dcf4);
            break;
        case 0x481e:
            NEW_CTOR(0xf8, func_ov014_0220eca0);
            break;
        case 0x4817:
            NEW_CTOR(0x19c, func_ov010_0220a6b0);
            break;
        case 0x4818:
            NEW_CTOR(0x100, func_ov010_0220dd60);
            break;
        case 0x4820:
            NEW_BASIC(0xdc, data_ov013_0220b7d0);
            break;
        case 0x4823:
            NEW_CTOR(0xd8, func_ov013_021fdb70);
            break;
        case 0x4821:
            NEW_CTOR(0xd4, func_ov014_021fbd64);
            break;
        case 0x4822:
            NEW_CTOR(0x104, func_ov014_021fc24c);
            break;
        case 0x4824:
            {
                u8 *t = (u8 *)func_0203dd9c(0x2fc);
                if (t != NULL) {
                    Base(t);
                    LFLD(void *, t, 0) = data_ov012_0220b1e8;
                    func_ov000_0218e9c4(t + 0xd8);
                    func_ov000_0218fe1c(t + 0x210);
                }
                p = t;
            }
            break;
        case 0x4825:
            NEW_BASIC(0xe8, data_ov012_0220b150);
            break;
        case 0x4826:
            NEW_CTOR(0xd8, func_ov012_02207018);
            break;
        case 0x4827:
            NEW_BASIC(0xe8, data_ov009_022178d0);
            break;
        case 0x4828:
            NEW_BASIC(0xec, data_ov009_02217838);
            break;
        case 0x482a:
            NEW_CTOR(0xdc, func_ov014_02208618);
            break;
        case 0x482b:
            NEW_CTOR(0xe0, func_ov014_02206c68);
            break;
        case 0x482c:
            NEW_CTOR(0xdc, func_ov014_0220774c);
            break;
        case 0x4829:
            NEW_CTOR(0x114, func_ov010_022020c8);
            break;
        case 0x482d:
            NEW_BASIC(0xdc, data_ov009_0221802c);
            break;
        case 0x401f:
            NEW_BASIC(0xd0, data_ov003_021f8df0);
            break;
        case 0x4032:
        case 0x4093:
            NEW_BASIC(0xd0, data_ov003_021f8480);
            break;
        case 0x4029:
            NEW_BASIC(0xd4, data_ov003_021f83e8);
            break;
        case 0x4036:
            NEW_BASIC(0xd0, data_ov003_021f8188);
            break;
        case 0x4037:
            NEW_BASIC(0xd4, data_ov003_021f8350);
            break;
        case 0x4041:
            NEW_BASIC(0xd0, data_ov003_021f8220);
            break;
        case 0x4040:
        case 0x4056:
            NEW_BASIC(0xd0, data_ov003_021f8b90);
            break;
        case 0x404a:
            NEW_BASIC(0xd0, data_ov003_021f9ce0);
            break;
        case 0x4628:
            {
                u8 *t = (u8 *)func_0203dd9c(0xb1c);
                if (t != NULL) {
                    Base(t);
                    LFLD(void *, t, 0) = data_ov003_021f8af8;
                    func_ov000_0218e9c4(t + 0xd0);
                    func_ov000_0218e9c4(t + 0x208);
                    func_ov000_0218fe1c(t + 0x340);
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
            NEW_BASIC(0xd0, data_ov003_021f8930);
            break;
        case 0x4055:
            NEW_BASIC(0xd0, data_ov003_021f86d0);
            break;
        case 0x406b:
            NEW_BASIC(0xd0, data_ov003_021f966c);
            break;
        case 0x4078:
            NEW_BASIC(0xd4, data_ov003_021f95d4);
            break;
        case 0x4073:
            NEW_BASIC(0xd0, data_ov003_021f9244);
            break;
        case 0x4071:
            NEW_BASIC(0xd4, data_ov003_021f9114);
            break;
        case 0x4072:
            {
                u8 *t = (u8 *)func_0203dd9c(0x1c0);
                if (t != NULL) {
                    Base(t);
                    LFLD(void *, t, 0) = data_ov003_021f953c;
                    func_ov000_0218fe1c(t + 0xd0);
                }
                p = t;
            }
            break;
        case 0x4076:
        case 0x4086:
            NEW_BASIC(0xf0, data_ov003_021f9374);
            break;
        case 0x405c:
        case 0x407b:
        case 0x407c:
        case 0x407d:
            NEW_BASIC(0xd4, data_ov003_021f91ac);
            break;
        case 0x408b:
            NEW_BASIC(0xdc, data_ov003_021f94a4);
            break;
        case 0x408c:
            NEW_BASIC(0x104, data_ov003_021f940c);
            break;
        case 0x4074:
            NEW_BASIC(0xd0, data_ov003_021f92dc);
            break;
        case 0x4047:
        case 0x405d:
        case 0x405f:
        case 0x407e:
        case 0x407f:
        case 0x4080:
        case 0x4082:
        case 0x4090:
            NEW_BASIC(0xd4, data_ov003_021f8f20);
            break;
        case 0x4030:
            NEW_BASIC(0xd0, data_ov003_021f8e88);
            break;
        case 0x404f:
            NEW_BASIC(0x104, data_ov003_021f80f0);
            break;
        case 0x409f:
            NEW_BASIC(0xd0, data_ov003_021f8058);
            break;
        case 0x4084:
            NEW_BASIC(0xd0, data_ov003_021f9c48);
            break;
        case 0x4085:
            NEW_BASIC(0xd0, data_ov003_021f9bb0);
            break;
        case 0x4063:
        case 0x4064:
        case 0x4065:
        case 0x4066:
            NEW_CTOR(0x214, func_ov003_021ec31c);
            break;
        case 0x4075:
            NEW_BASIC(0xd0, data_ov003_021f9b18);
            break;
        case 0x482e:
        case 0x483f:
            NEW_BASIC(0xf4, data_ov003_021f9a80);
            break;
        case 0x4083:
        case 0x408f:
        case 0x4096:
            NEW_BASIC(0xd4, data_ov009_0221828c);
            break;
        case 0x4830:
            NEW_BASIC(0xd0, data_ov009_02218324);
            break;
        case 0x482f:
            NEW_BASIC(0xd0, data_ov009_022180c4);
            break;
        case 0x4802:
            NEW_BASIC(0xd4, data_ov009_022181f4);
            break;
        case 0x4092:
            NEW_BASIC(0xd0, data_ov009_0221815c);
            break;
        case 0x4f40:
            NEW_BASIC(0xd0, data_ov006_021ec7ac);
            break;
        case 0x4f41:
            NEW_BASIC(0xd0, data_ov006_021ec54c);
            break;
        case 0x4f42:
        case 0x4f45:
            NEW_BASIC(0xd0, data_ov006_021ec5e4);
            break;
        case 0x4f43:
            NEW_BASIC(0xd0, data_ov006_021ec67c);
            break;
        case 0x4f44:
            NEW_BASIC(0xd0, data_ov006_021ec714);
            break;
        case 0x4044:
            NEW_BASIC(0xd0, data_ov003_021f8d58);
            break;
        }
        break;
    case 1:
        NEW_BASIC(0xd0, data_ov003_021f98cc);
        break;
    case 2:
        {
            u8 *t = (u8 *)func_0203dd9c(0x304);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f9834;
                func_ov000_0218e9c4(t + 0xd0);
                func_ov000_0218fe1c(t + 0x208);
            }
            p = t;
        }
        break;
    case 3:
        {
            u8 *t = (u8 *)func_0203dd9c(0x314);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f9704;
                func_ov000_0218e9c4(t + 0xd0);
                func_ov000_0218fe1c(t + 0x208);
                LFLD(u16, t, 0x2fc) = 0;
                LFLD(u16, t, 0x2fe) = 0;
            }
            p = t;
        }
        break;
    case 4:
        {
            u8 *t = (u8 *)func_0203dd9c(0x304);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f979c;
                func_ov000_0218e9c4(t + 0xd0);
                func_ov000_0218fe1c(t + 0x208);
            }
            p = t;
        }
        break;
    case 8:
        NEW_BASIC(0xd0, data_ov003_021f9f40);
        break;
    case 9:
        NEW_BASIC(0xd0, data_ov003_021f9ea8);
        break;
    case 10:
        NEW_BASIC(0xd4, data_ov003_021f9e10);
        break;
    case 11:
        NEW_BASIC(0xd0, data_ov003_021f9d78);
        break;
    case 5:
        NEW_BASIC(0xd0, data_ov003_021f7fac);
        break;
    case 6:
        NEW_BASIC(0xd0, data_ov003_021f7f14);
        break;
    case 7:
        NEW_BASIC(0xd0, data_ov003_021f7e7c);
        break;
    case 12:
        NEW_BASIC(0xf4, data_ov003_021f7de4);
        break;
    case 13:
        NEW_BASIC(0xfc, data_ov003_021f7d4c);
        break;
    case 14:
        {
            u8 *t = (u8 *)func_0203dd9c(0x218);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f8638;
                func_ov000_0218e9c4(t + 0xd0);
            }
            p = t;
        }
        break;
    case 15:
        NEW_BASIC(0xd0, data_ov003_021f9050);
        break;
    case 16:
        {
            u8 *t = (u8 *)func_0203dd9c(0x208);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f8c28;
                func_ov000_0218e9c4(t + 0xd0);
            }
            p = t;
        }
        break;
    case 17:
        {
            u8 *t = (u8 *)func_0203dd9c(0x208);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f89c8;
                func_ov000_0218e9c4(t + 0xd0);
            }
            p = t;
        }
        break;
    case 18:
        NEW_BASIC(0xd0, data_ov003_021f8800);
        break;
    case 19:
        NEW_BASIC(0xd0, data_ov003_021fa07c);
        break;
    case 20:
        NEW_BASIC(0xd0, data_ov003_021fa114);
        break;
    case 21:
        NEW_BASIC(0xe0, data_ov003_021f9fe4);
        break;
    case 22:
        {
            u8 *t = (u8 *)func_0203dd9c(0xe0);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f8898;
                LFLD(u16, t, 0xd0) = 0;
                LFLD(u16, t, 0xd2) = 0;
            }
            p = t;
        }
        break;
    case 23:
        {
            u8 *t = (u8 *)func_0203dd9c(0x214);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov003_021f8768;
                func_ov000_0218e9c4(t + 0xd0);
                LFLD(s32, t, 0x208) = 0;
            }
            p = t;
        }
        break;
    case 24:
        NEW_BASIC(0xd0, data_ov003_021f82b8);
        break;
    }
    if (p != NULL) {
        func_ov000_0218d1c0(p, s->sub, s->id, func_0206ffa0(s->id));
        *(Rgb02192b24 *)(p + 0xac) = *(Rgb02192b24 *)(data_ov000_021ccd54 + 0xca);
    }
    return p;
}

}
