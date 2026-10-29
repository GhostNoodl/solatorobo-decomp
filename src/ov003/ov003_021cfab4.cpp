#include "types.h"

/* Gimmick factory: picks the class from the gimmick id. */

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 id;
    u16 sub;
} Spawn021cfab4;

typedef struct {
    u8 v[3];
} Rgb021cfab4;

extern "C" {

extern u8 data_ov003_021f7b60[];
extern u8 data_ov003_021f7c0c[];
extern u8 data_ov009_02216348[];
extern u8 data_ov009_022163f4[];
extern u8 data_ov009_022164a0[];
extern u8 data_ov009_0221654c[];
extern u8 data_ov009_022165f8[];
extern u8 data_ov009_022166a4[];
extern u8 data_ov009_02216750[];
extern u8 data_ov009_022167fc[];
extern u8 data_ov009_022168a8[];
extern u8 data_ov009_02216954[];
extern u8 data_ov009_02216a00[];
extern u8 data_ov009_02216bc8[];
extern u8 data_ov009_02216c74[];
extern u8 data_ov009_02216dcc[];
extern u8 data_ov009_02216f24[];
extern u8 data_ov009_02216fd0[];
extern u8 data_ov009_0221707c[];
extern u8 data_ov009_02217128[];
extern u8 data_ov009_022171d4[];
extern u8 data_ov009_022172e4[];
extern u8 data_ov009_02217390[];
extern u8 data_ov009_0221743c[];
extern u8 data_ov009_022174e8[];
extern u8 data_ov009_02217594[];
extern u8 data_ov009_02217640[];
extern u8 data_ov009_022176ec[];
extern u8 data_ov009_02217798[];
extern u8 data_ov009_02217844[];
extern u8 data_ov009_022178f0[];
extern u8 data_ov009_02217a00[];
extern u8 data_ov009_02217aac[];
extern u8 data_ov009_02217b58[];
extern u8 data_ov009_02217c04[];
extern u8 data_ov009_02217cb0[];
extern u8 data_ov009_02217d5c[];
extern u8 data_ov009_02217e08[];
extern u8 data_ov009_02217eb4[];
extern u8 data_ov009_02217f60[];
extern u8 data_ov010_0221009c[];
extern u8 data_ov011_02207a88[];
extern u8 data_ov011_02207b34[];
extern u8 data_ov011_02207c4c[];
extern u8 data_ov011_02207cf8[];
extern u8 data_ov011_02207da4[];
extern u8 data_ov011_02207e50[];
extern u8 data_ov012_0220b280[];
extern u8 data_ov012_0220b35c[];
extern u8 data_ov013_0220b5e0[];
extern u8 data_ov013_0220b68c[];
extern u8 data_ov013_0220bc80[];
extern u8 data_ov013_0220bdd8[];
extern u8 *data_ov000_021ccd54;
void *func_0203dd9c(u32 size);
s32 func_0206ffa0(u16 id);
s32 func_ov003_021cf77c(Spawn021cfab4 *s);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fe1c(void *p);
void *func_ov000_0218fee4(void *p);
void func_ov003_021d0c1c(void *p);
void *func_ov003_021d0c94(void *p);
void func_ov000_0218d1c0(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *func_ov012_021fa6a0(void *p);
void *func_ov014_021fa6a0(void *p);
void *func_ov009_02200b48(void *p);
void *func_ov009_02202788(void *p);
void *func_ov010_021fa860(void *p);
void *func_ov010_02204204(void *p);
void *func_ov010_02207ac4(void *p);
void *func_ov011_021fed5c(void *p);
void *func_ov012_021fee1c(void *p);
void *func_ov012_021ffa68(void *p);
void *func_ov012_02202b10(void *p);
void *func_ov013_021fea8c(void *p);
void *func_ov013_02207968(void *p);
void *func_ov014_021fd4d4(void *p);
void *func_ov014_0220011c(void *p);
void *func_ov014_02201b94(void *p);
void *func_ov014_02209280(void *p);
void *func_ov014_0220f9d0(void *p);
void *func_ov014_0221267c(void *p);

#define Base(p) func_ov003_021d0c1c(p)

#define NEW_CTOR(size, ctor)                   \
    {                                          \
        u8 *t = (u8 *)func_0203dd9c(size);     \
        if (t != NULL) {                       \
            t = (u8 *)ctor(t);                 \
        }                                      \
        p = t;                                 \
    }

#define NEW_BASIC(size, vt)                    \
    {                                          \
        u8 *t = (u8 *)func_0203dd9c(size);     \
        if (t != NULL) {                       \
            Base(t);                           \
            LFLD(void *, t, 0) = (vt);         \
        }                                      \
        p = t;                                 \
    }

#define NEW_DERIV(size, base, vt)              \
    {                                          \
        u8 *t = (u8 *)func_0203dd9c(size);     \
        if (t != NULL) {                       \
            base(t);                           \
            LFLD(void *, t, 0) = (vt);         \
        }                                      \
        p = t;                                 \
    }

u8 *func_ov003_021cfab4(Spawn021cfab4 *s) {
    u8 *p;
    func_ov003_021cf77c(s);
    switch (s->id) {
    default:
        NEW_CTOR(0xf0, func_ov003_021d0c94);
        break;
    case 0x5035:
    case 0x503f:
    case 0x5047:
    case 0x5048:
    case 0x5054:
        {
            u8 *t = (u8 *)func_0203dd9c(0x10c);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov009_0221707c;
                LFLD(s32, t, 0x104) = 0;
            }
            p = t;
        }
        break;
    case 0x5049:
    case 0x5055:
        NEW_CTOR(0x12c, func_ov009_02202788);
        break;
    case 0x502e:
    case 0x5033:
    case 0x504c:
    case 0x5053:
    case 0x5059:
        NEW_BASIC(0xf4, data_ov009_02216c74);
        break;
    case 0x5027:
    case 0x503e:
    case 0x504d:
    case 0x5810:
    case 0x5811:
        NEW_BASIC(0x148, data_ov009_02216bc8);
        break;
    case 0x504a:
    case 0x504b:
        NEW_BASIC(0xf0, data_ov009_02216fd0);
        break;
    case 0x5014:
    case 0x5019:
    case 0x501a:
    case 0x501e:
    case 0x5020:
    case 0x5028:
    case 0x502b:
    case 0x502c:
    case 0x5034:
    case 0x5043:
    case 0x5051:
    case 0x5052:
    case 0x505a:
    case 0x505b:
        NEW_BASIC(0xf0, data_ov009_02216f24);
        break;
    case 0x5046:
        NEW_BASIC(0xf8, data_ov009_02216dcc);
        break;
    case 0x5021:
    case 0x5400:
    case 0x5422:
        NEW_BASIC(0xf4, data_ov009_02216a00);
        break;
    case 0x541f:
        NEW_BASIC(0xf0, data_ov009_02216954);
        break;
    case 0x5032:
    case 0x5402:
        NEW_BASIC(0xf4, data_ov009_022164a0);
        break;
    case 0x502f:
    case 0x5405:
        NEW_BASIC(0xf0, data_ov009_022168a8);
        break;
    case 0x540e:
        NEW_BASIC(0x100, data_ov009_022172e4);
        break;
    case 0x5415:
        NEW_BASIC(0xfc, data_ov009_022176ec);
        break;
    case 0x5414:
        {
            u8 *t = (u8 *)func_0203dd9c(0x310);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov009_02217844;
                func_ov000_0218e9c4(t + 0xf0);
                func_ov000_0218fe1c(t + 0x228);
            }
            p = t;
        }
        break;
    case 0x540a:
    case 0x540b:
    case 0x5417:
    case 0x5425:
        NEW_BASIC(0x10c, data_ov009_022166a4);
        break;
    case 0x5031:
    case 0x5421:
        NEW_BASIC(0x104, data_ov009_022171d4);
        break;
    case 0x540f:
    case 0x5410:
        {
            u8 *t = (u8 *)func_0203dd9c(0x4ac);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov009_0221743c;
                __cxa_vec_ctor(t + 0xf0, 4, 0xe8, (void (*)(void *))func_ov000_0218fe1c, (void (*)(void *))func_ov000_0218fee4);
            }
            p = t;
        }
        break;
    case 0x5409:
        NEW_BASIC(0xf8, data_ov009_022163f4);
        break;
    case 0x5418:
        NEW_BASIC(0xf4, data_ov009_02216348);
        break;
    case 0x5423:
    case 0x5424:
        NEW_BASIC(0x110, data_ov009_02217128);
        break;
    case 0x5420:
        NEW_BASIC(0xf0, data_ov009_02217798);
        break;
    case 0x5030:
    case 0x5411:
        NEW_CTOR(0x12c, func_ov009_02200b48);
        break;
    case 0x5419:
        NEW_BASIC(0x100, data_ov013_0220bdd8);
        break;
    case 0x541c:
        NEW_CTOR(0x114, func_ov013_02207968);
        break;
    case 0x540c:
        NEW_BASIC(0x10c, data_ov013_0220bc80);
        break;
    case 0x5800:
    case 0x5815:
    case 0x5816:
        NEW_BASIC(0xf0, data_ov003_021f7c0c);
        break;
    case 0x5802:
        NEW_BASIC(0xf4, data_ov003_021f7b60);
        break;
    case 0x5807:
        NEW_BASIC(0xf0, data_ov011_02207a88);
        break;
    case 0x5801:
        NEW_BASIC(0xf0, data_ov011_02207b34);
        break;
    case 0x5805:
        NEW_CTOR(0x110, func_ov011_021fed5c);
        break;
    case 0x580c:
    case 0x580d:
    case 0x580e:
        NEW_CTOR(0x370, func_ov014_02201b94);
        break;
    case 0x5808:
    case 0x5809:
    case 0x580a:
    case 0x580b:
        NEW_BASIC(0x114, data_ov009_02217640);
        break;
    case 0x580f:
        NEW_BASIC(0xf0, data_ov009_022174e8);
        break;
    case 0x5814:
        NEW_BASIC(0x110, data_ov011_02207c4c);
        break;
    case 0x5813:
        NEW_BASIC(0x100, data_ov011_02207e50);
        break;
    case 0x5812:
        NEW_BASIC(0xfc, data_ov011_02207cf8);
        break;
    case 0x5c08:
        NEW_CTOR(0x160, func_ov013_021fea8c);
        break;
    case 0x5c0a:
        NEW_BASIC(0x13c, data_ov013_0220b68c);
        break;
    case 0x5c17:
        NEW_BASIC(0xfc, data_ov013_0220b5e0);
        break;
    case 0x5036:
    case 0x5c00:
        NEW_BASIC(0xf0, data_ov012_0220b35c);
        break;
    case 0x5c13:
        NEW_CTOR(0x108, func_ov012_021fee1c);
        break;
    case 0x5029:
    case 0x5039:
    case 0x5057:
    case 0x5c01:
        {
            u8 *t = (u8 *)func_0203dd9c(0x22c);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov012_0220b280;
                func_ov000_0218e9c4(t + 0xf0);
            }
            p = t;
        }
        break;
    case 0x5c14:
        NEW_CTOR(0x10c, func_ov012_021ffa68);
        break;
    case 0x5c02:
        NEW_CTOR(0x3b0, func_ov012_021fa6a0);
        break;
    case 0x5c03:
        NEW_CTOR(0x128, func_ov012_02202b10);
        break;
    case 0x5c15:
        NEW_CTOR(0x368, func_ov014_021fa6a0);
        break;
    case 0x5c04:
        NEW_CTOR(0x204, func_ov010_02207ac4);
        break;
    case 0x5c05:
        NEW_DERIV(0x1fc, func_ov010_02204204, data_ov010_0221009c);
        break;
    case 0x5c06:
        NEW_CTOR(0x1dc, func_ov010_021fa860);
        break;
    case 0x5c0f:
        NEW_CTOR(0x1f8, func_ov014_02209280);
        break;
    case 0x5c0c:
        NEW_CTOR(0x184, func_ov014_0220f9d0);
        break;
    case 0x5c16:
        NEW_CTOR(0x358, func_ov014_0221267c);
        break;
    case 0x5c0e:
        NEW_CTOR(0x17c, func_ov014_021fd4d4);
        break;
    case 0x5c19:
        NEW_CTOR(0x124, func_ov014_0220011c);
        break;
    case 0x5c11:
        {
            u8 *t = (u8 *)func_0203dd9c(0x39c);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov011_02207da4;
                __cxa_vec_ctor(t + 0xf4, 2, 0x138, (void (*)(void *))func_ov000_0218e9c4, (void (*)(void *))func_ov000_0218ea20);
                LFLD(s32, t, 0x364) = 0;
                LFLD(s32, t, 0x368) = 0;
            }
            p = t;
        }
        break;
    case 0x5010:
        NEW_BASIC(0x110, data_ov009_022178f0);
        break;
    case 0x5000:
    case 0x5001:
    case 0x5002:
    case 0x5003:
    case 0x5004:
    case 0x5005:
    case 0x5006:
    case 0x5007:
    case 0x5008:
    case 0x5009:
    case 0x500a:
    case 0x500b:
    case 0x500c:
    case 0x500d:
    case 0x500e:
    case 0x500f:
    case 0x501f:
    case 0x502a:
    case 0x502d:
    case 0x503a:
    case 0x503b:
    case 0x503c:
    case 0x503d:
        NEW_BASIC(0xf0, data_ov009_022167fc);
        break;
    case 0x5012:
    case 0x5038:
    case 0x5044:
        NEW_BASIC(0x108, data_ov009_02216750);
        break;
    case 0x5013:
    case 0x5045:
        NEW_BASIC(0xfc, data_ov009_022165f8);
        break;
    case 0x5011:
        NEW_BASIC(0xf0, data_ov009_0221654c);
        break;
    case 0x5016:
        NEW_BASIC(0x110, data_ov009_02217f60);
        break;
    case 0x5017:
        NEW_BASIC(0x10c, data_ov009_02217eb4);
        break;
    case 0x5018:
        NEW_BASIC(0x110, data_ov009_02217b58);
        break;
    case 0x541e:
        {
            u8 *t = (u8 *)func_0203dd9c(0x31c);
            if (t != NULL) {
                Base(t);
                LFLD(void *, t, 0) = data_ov009_02217594;
                func_ov000_0218e9c4(t + 0xf0);
                func_ov000_0218fe1c(t + 0x228);
            }
            p = t;
        }
        break;
    case 0x5416:
        NEW_BASIC(0x104, data_ov009_02217390);
        break;
    case 0x5023:
    case 0x5408:
    case 0x541a:
        NEW_BASIC(0xf4, data_ov009_02217e08);
        break;
    case 0x501c:
        NEW_BASIC(0xfc, data_ov009_02217c04);
        break;
    case 0x501d:
    case 0x5058:
        NEW_BASIC(0x108, data_ov009_02217aac);
        break;
    case 0x504f:
        NEW_BASIC(0x140, data_ov009_02217a00);
        break;
    case 0x5050:
        NEW_BASIC(0x140, data_ov009_02217d5c);
        break;
    case 0x501b:
    case 0x5037:
    case 0x504e:
    case 0x5056:
        NEW_BASIC(0xfc, data_ov009_02217cb0);
        break;
    }
    func_ov000_0218d1c0(p, s->sub, s->id, func_0206ffa0(s->id));
    *(Rgb021cfab4 *)(p + 0xac) = *(Rgb021cfab4 *)(data_ov000_021ccd54 + 0xca);
    return p;
}

}
