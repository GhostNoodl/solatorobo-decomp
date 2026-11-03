#include "types.h"
#include "ov003/Actor.h"

/* Gimmick factory: picks the class from the gimmick id. */

// What the factory writes into a new gimmick: the vtable pointer, plus two class-specific
// fields the inline constructors below clear.
typedef struct {
    void *vtbl;
} GmHead021cfab4;

typedef struct {
    void *vtbl;
    u8 unk_04[0x100];
    s32 unk_104;
    u8 unk_108[0x4];
} Gm10c021cfab4;
typedef char Gm10c021cfab4_size_check[(sizeof(Gm10c021cfab4) == 0x10c) ? 1 : -1];

typedef struct {
    void *vtbl;
    u8 unk_04[0xf0];
    u8 unk_f4[2][0x138]; // built with ResSet_Init
    s32 unk_364;
    s32 unk_368;
    u8 unk_36c[0x30];
} Gm39c021cfab4;
typedef char Gm39c021cfab4_size_check[(sizeof(Gm39c021cfab4) == 0x39c) ? 1 : -1];

typedef struct {
    u16 id;
    u16 sub;
} Spawn021cfab4;

typedef struct {
    u8 v[3];
} Rgb021cfab4;

extern "C" {

extern u8 Ov003ActVt_021f7b60_vtbl[];
extern u8 Ov003ActVt_021f7c0c_vtbl[];
extern u8 Ov009ActVt_02216348_vtbl[];
extern u8 Ov009ActVt_022163f4_vtbl[];
extern u8 Ov009ActVt_022164a0_vtbl[];
extern u8 Ov009ActVt_0221654c_vtbl[];
extern u8 Ov009ActVt_022165f8_vtbl[];
extern u8 Ov009ActVt_022166a4_vtbl[];
extern u8 Ov009ActVt_02216750_vtbl[];
extern u8 Ov009ActVt_022167fc_vtbl[];
extern u8 Ov009ActVt_022168a8_vtbl[];
extern u8 Ov009ActVt_02216954_vtbl[];
extern u8 Ov009ActVt_02216a00_vtbl[];
extern u8 Ov009ActVt_02216bc8_vtbl[];
extern u8 Ov009ActVt_02216c74_vtbl[];
extern u8 Ov009ActVt_02216dcc_vtbl[];
extern u8 Ov009ActVt_02216f24_vtbl[];
extern u8 Ov009ActVt_02216fd0_vtbl[];
extern u8 Ov009ActVt_0221707c_vtbl[];
extern u8 Ov009ActVt_02217128_vtbl[];
extern u8 Ov009ActVt_022171d4_vtbl[];
extern u8 Ov009ActVt_022172e4_vtbl[];
extern u8 Ov009ActVt_02217390_vtbl[];
extern u8 Ov009Multi_vtbl[];
extern u8 Ov009ActVt_022174e8_vtbl[];
extern u8 Ov009ActVt_02217594_vtbl[];
extern u8 Ov009ActVt_02217640_vtbl[];
extern u8 Ov009ActVt_022176ec_vtbl[];
extern u8 Ov009ActVt_02217798_vtbl[];
extern u8 Ov009ActVt_02217844_vtbl[];
extern u8 Ov009ActVt_022178f0_vtbl[];
extern u8 Ov009ActSpin_vtbl[];
extern u8 Ov009ActVt_02217aac_vtbl[];
extern u8 Ov009ActPair110_vtbl[];
extern u8 Ov009ActVt_02217c04_vtbl[];
extern u8 Ov009ActVt_02217cb0_vtbl[];
extern u8 Ov009ActVt_02217d5c_vtbl[];
extern u8 Ov009ActVt_02217e08_vtbl[];
extern u8 Ov009ActVt_02217eb4_vtbl[];
extern u8 Ov009ActVt_02217f60_vtbl[];
extern u8 Ov010ActVt_0221009c_vtbl[];
extern u8 Ov011ActVt_02207a88_vtbl[];
extern u8 Ov011ActVt_02207b34_vtbl[];
extern u8 Ov011Act7c4c_vtbl[];
extern u8 Ov011Act7cf8_vtbl[];
extern char Ov011Act7da4_vtbl[];
extern u8 Ov011Act7e50_vtbl[];
extern u8 Ov012ActVt_0220b280_vtbl[];
extern u8 Ov012ActVt_0220b35c_vtbl[];
extern u8 Ov013ActVt_0220b5e0_vtbl[];
extern u8 Ov013Boss_vtbl[];
extern u8 Ov013ActVt_0220bc80_vtbl[];
extern u8 Ov013ActVt_0220bdd8_vtbl[];
extern u8 *gSceneCmd;
void *Heap_Alloc(u32 size);
s32 Tbl_GetText(u16 id);
s32 Ov003_OverlayForKind(Spawn021cfab4 *s);
void *ResSet_Init(void *p);
ResSet *ResSet_ReleaseAll(ResSet *p);
void *Model0218fe1c_Init(void *p);
Model0218fe1c *Model0218fe1c_FreeAnims(Model0218fe1c *p);
void *Ov003Actor_Ctor_021d0c94(void *p);
void Actor_JoinGroup(void *p, u16 sub, u16 id, s32 a);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *Ov012Lift_Ctor(void *p);
void *Ov014Act_021fa6a0_Ctor(void *p);
void *Ov009Act_02200b48_Ctor(void *p);
void *Ov009Act_02202788_Ctor(void *p);
void *Ov010ActVt_0220fccc_Ctor(void *p);
void *Ov010ActVt_02210154_Ctor(void *p);
void *Ov010ActVt_0220ffe4_Ctor(void *p);
void *Ov011SceneActor_Ctor(void *p);
void *Ov012Act_021fee1c_Ctor(void *p);
void *Ov012Act_021ffa68_Ctor(void *p);
void *Ov012Act_02202b10_Ctor(void *p);
void *Ov013Act_021fea8c_Ctor(void *p);
void *Ov013Act_02207968_Ctor(void *p);
void *Ov014Act_021fd4d4_Ctor(void *p);
void *Ov014Act_0220011c_Ctor(void *p);
void *Ov014Act_02201b94_Ctor(void *p);
void *Ov014Act_02209280_Ctor(void *p);
void *Ov014Act_0220f9d0_Ctor(void *p);
void *Ov014Act_0221267c_Ctor(void *p);

#define Base(p) Ov003Actor_Ctor((Ov003Actor *)(p))

#define NEW_CTOR(size, ctor)                   \
    {                                          \
        u8 *t = (u8 *)Heap_Alloc(size);     \
        if (t != NULL) {                       \
            t = (u8 *)ctor(t);                 \
        }                                      \
        p = t;                                 \
    }

#define NEW_BASIC(size, vt)                    \
    {                                          \
        u8 *t = (u8 *)Heap_Alloc(size);     \
        if (t != NULL) {                       \
            Base(t);                           \
            ((GmHead021cfab4 *)t)->vtbl = (vt);     \
        }                                      \
        p = t;                                 \
    }

#define NEW_DERIV(size, base, vt)              \
    {                                          \
        u8 *t = (u8 *)Heap_Alloc(size);     \
        if (t != NULL) {                       \
            base(t);                           \
            ((GmHead021cfab4 *)t)->vtbl = (vt);     \
        }                                      \
        p = t;                                 \
    }

u8 *Ov003_NewActor(Spawn021cfab4 *s) {
    u8 *p;
    Ov003_OverlayForKind(s);
    switch (s->id) {
    default:
        NEW_CTOR(0xf0, Ov003Actor_Ctor_021d0c94);
        break;
    case 0x5035:
    case 0x503f:
    case 0x5047:
    case 0x5048:
    case 0x5054:
        {
            Gm10c021cfab4 *t = (Gm10c021cfab4 *)Heap_Alloc(0x10c);
            if (t != NULL) {
                Base(t);
                t->vtbl = Ov009ActVt_0221707c_vtbl;
                t->unk_104 = 0;
            }
            p = (u8 *)t;
        }
        break;
    case 0x5049:
    case 0x5055:
        NEW_CTOR(0x12c, Ov009Act_02202788_Ctor);
        break;
    case 0x502e:
    case 0x5033:
    case 0x504c:
    case 0x5053:
    case 0x5059:
        NEW_BASIC(0xf4, Ov009ActVt_02216c74_vtbl);
        break;
    case 0x5027:
    case 0x503e:
    case 0x504d:
    case 0x5810:
    case 0x5811:
        NEW_BASIC(0x148, Ov009ActVt_02216bc8_vtbl);
        break;
    case 0x504a:
    case 0x504b:
        NEW_BASIC(0xf0, Ov009ActVt_02216fd0_vtbl);
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
        NEW_BASIC(0xf0, Ov009ActVt_02216f24_vtbl);
        break;
    case 0x5046:
        NEW_BASIC(0xf8, Ov009ActVt_02216dcc_vtbl);
        break;
    case 0x5021:
    case 0x5400:
    case 0x5422:
        NEW_BASIC(0xf4, Ov009ActVt_02216a00_vtbl);
        break;
    case 0x541f:
        NEW_BASIC(0xf0, Ov009ActVt_02216954_vtbl);
        break;
    case 0x5032:
    case 0x5402:
        NEW_BASIC(0xf4, Ov009ActVt_022164a0_vtbl);
        break;
    case 0x502f:
    case 0x5405:
        NEW_BASIC(0xf0, Ov009ActVt_022168a8_vtbl);
        break;
    case 0x540e:
        NEW_BASIC(0x100, Ov009ActVt_022172e4_vtbl);
        break;
    case 0x5415:
        NEW_BASIC(0xfc, Ov009ActVt_022176ec_vtbl);
        break;
    case 0x5414:
        {
            u8 *t = (u8 *)Heap_Alloc(0x310);
            if (t != NULL) {
                Base(t);
                ((GmHead021cfab4 *)t)->vtbl = Ov009ActVt_02217844_vtbl;
                ResSet_Init(t + 0xf0);
                Model0218fe1c_Init(t + 0x228);
            }
            p = t;
        }
        break;
    case 0x540a:
    case 0x540b:
    case 0x5417:
    case 0x5425:
        NEW_BASIC(0x10c, Ov009ActVt_022166a4_vtbl);
        break;
    case 0x5031:
    case 0x5421:
        NEW_BASIC(0x104, Ov009ActVt_022171d4_vtbl);
        break;
    case 0x540f:
    case 0x5410:
        {
            u8 *t = (u8 *)Heap_Alloc(0x4ac);
            if (t != NULL) {
                Base(t);
                ((GmHead021cfab4 *)t)->vtbl = Ov009Multi_vtbl;
                __cxa_vec_ctor(t + 0xf0, 4, 0xe8, (void (*)(void *))Model0218fe1c_Init, (void (*)(void *))Model0218fe1c_FreeAnims);
            }
            p = t;
        }
        break;
    case 0x5409:
        NEW_BASIC(0xf8, Ov009ActVt_022163f4_vtbl);
        break;
    case 0x5418:
        NEW_BASIC(0xf4, Ov009ActVt_02216348_vtbl);
        break;
    case 0x5423:
    case 0x5424:
        NEW_BASIC(0x110, Ov009ActVt_02217128_vtbl);
        break;
    case 0x5420:
        NEW_BASIC(0xf0, Ov009ActVt_02217798_vtbl);
        break;
    case 0x5030:
    case 0x5411:
        NEW_CTOR(0x12c, Ov009Act_02200b48_Ctor);
        break;
    case 0x5419:
        NEW_BASIC(0x100, Ov013ActVt_0220bdd8_vtbl);
        break;
    case 0x541c:
        NEW_CTOR(0x114, Ov013Act_02207968_Ctor);
        break;
    case 0x540c:
        NEW_BASIC(0x10c, Ov013ActVt_0220bc80_vtbl);
        break;
    case 0x5800:
    case 0x5815:
    case 0x5816:
        NEW_BASIC(0xf0, Ov003ActVt_021f7c0c_vtbl);
        break;
    case 0x5802:
        NEW_BASIC(0xf4, Ov003ActVt_021f7b60_vtbl);
        break;
    case 0x5807:
        NEW_BASIC(0xf0, Ov011ActVt_02207a88_vtbl);
        break;
    case 0x5801:
        NEW_BASIC(0xf0, Ov011ActVt_02207b34_vtbl);
        break;
    case 0x5805:
        NEW_CTOR(0x110, Ov011SceneActor_Ctor);
        break;
    case 0x580c:
    case 0x580d:
    case 0x580e:
        NEW_CTOR(0x370, Ov014Act_02201b94_Ctor);
        break;
    case 0x5808:
    case 0x5809:
    case 0x580a:
    case 0x580b:
        NEW_BASIC(0x114, Ov009ActVt_02217640_vtbl);
        break;
    case 0x580f:
        NEW_BASIC(0xf0, Ov009ActVt_022174e8_vtbl);
        break;
    case 0x5814:
        NEW_BASIC(0x110, Ov011Act7c4c_vtbl);
        break;
    case 0x5813:
        NEW_BASIC(0x100, Ov011Act7e50_vtbl);
        break;
    case 0x5812:
        NEW_BASIC(0xfc, Ov011Act7cf8_vtbl);
        break;
    case 0x5c08:
        NEW_CTOR(0x160, Ov013Act_021fea8c_Ctor);
        break;
    case 0x5c0a:
        NEW_BASIC(0x13c, Ov013Boss_vtbl);
        break;
    case 0x5c17:
        NEW_BASIC(0xfc, Ov013ActVt_0220b5e0_vtbl);
        break;
    case 0x5036:
    case 0x5c00:
        NEW_BASIC(0xf0, Ov012ActVt_0220b35c_vtbl);
        break;
    case 0x5c13:
        NEW_CTOR(0x108, Ov012Act_021fee1c_Ctor);
        break;
    case 0x5029:
    case 0x5039:
    case 0x5057:
    case 0x5c01:
        {
            u8 *t = (u8 *)Heap_Alloc(0x22c);
            if (t != NULL) {
                Base(t);
                ((GmHead021cfab4 *)t)->vtbl = Ov012ActVt_0220b280_vtbl;
                ResSet_Init(t + 0xf0);
            }
            p = t;
        }
        break;
    case 0x5c14:
        NEW_CTOR(0x10c, Ov012Act_021ffa68_Ctor);
        break;
    case 0x5c02:
        NEW_CTOR(0x3b0, Ov012Lift_Ctor);
        break;
    case 0x5c03:
        NEW_CTOR(0x128, Ov012Act_02202b10_Ctor);
        break;
    case 0x5c15:
        NEW_CTOR(0x368, Ov014Act_021fa6a0_Ctor);
        break;
    case 0x5c04:
        NEW_CTOR(0x204, Ov010ActVt_0220ffe4_Ctor);
        break;
    case 0x5c05:
        NEW_DERIV(0x1fc, Ov010ActVt_02210154_Ctor, Ov010ActVt_0221009c_vtbl);
        break;
    case 0x5c06:
        NEW_CTOR(0x1dc, Ov010ActVt_0220fccc_Ctor);
        break;
    case 0x5c0f:
        NEW_CTOR(0x1f8, Ov014Act_02209280_Ctor);
        break;
    case 0x5c0c:
        NEW_CTOR(0x184, Ov014Act_0220f9d0_Ctor);
        break;
    case 0x5c16:
        NEW_CTOR(0x358, Ov014Act_0221267c_Ctor);
        break;
    case 0x5c0e:
        NEW_CTOR(0x17c, Ov014Act_021fd4d4_Ctor);
        break;
    case 0x5c19:
        NEW_CTOR(0x124, Ov014Act_0220011c_Ctor);
        break;
    case 0x5c11:
        {
            Gm39c021cfab4 *t = (Gm39c021cfab4 *)Heap_Alloc(0x39c);
            if (t != NULL) {
                Base(t);
                t->vtbl = Ov011Act7da4_vtbl;
                __cxa_vec_ctor(t->unk_f4, 2, 0x138, (void (*)(void *))ResSet_Init, (void (*)(void *))ResSet_ReleaseAll);
                t->unk_364 = 0;
                t->unk_368 = 0;
            }
            p = (u8 *)t;
        }
        break;
    case 0x5010:
        NEW_BASIC(0x110, Ov009ActVt_022178f0_vtbl);
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
        NEW_BASIC(0xf0, Ov009ActVt_022167fc_vtbl);
        break;
    case 0x5012:
    case 0x5038:
    case 0x5044:
        NEW_BASIC(0x108, Ov009ActVt_02216750_vtbl);
        break;
    case 0x5013:
    case 0x5045:
        NEW_BASIC(0xfc, Ov009ActVt_022165f8_vtbl);
        break;
    case 0x5011:
        NEW_BASIC(0xf0, Ov009ActVt_0221654c_vtbl);
        break;
    case 0x5016:
        NEW_BASIC(0x110, Ov009ActVt_02217f60_vtbl);
        break;
    case 0x5017:
        NEW_BASIC(0x10c, Ov009ActVt_02217eb4_vtbl);
        break;
    case 0x5018:
        NEW_BASIC(0x110, Ov009ActPair110_vtbl);
        break;
    case 0x541e:
        {
            u8 *t = (u8 *)Heap_Alloc(0x31c);
            if (t != NULL) {
                Base(t);
                ((GmHead021cfab4 *)t)->vtbl = Ov009ActVt_02217594_vtbl;
                ResSet_Init(t + 0xf0);
                Model0218fe1c_Init(t + 0x228);
            }
            p = t;
        }
        break;
    case 0x5416:
        NEW_BASIC(0x104, Ov009ActVt_02217390_vtbl);
        break;
    case 0x5023:
    case 0x5408:
    case 0x541a:
        NEW_BASIC(0xf4, Ov009ActVt_02217e08_vtbl);
        break;
    case 0x501c:
        NEW_BASIC(0xfc, Ov009ActVt_02217c04_vtbl);
        break;
    case 0x501d:
    case 0x5058:
        NEW_BASIC(0x108, Ov009ActVt_02217aac_vtbl);
        break;
    case 0x504f:
        NEW_BASIC(0x140, Ov009ActSpin_vtbl);
        break;
    case 0x5050:
        NEW_BASIC(0x140, Ov009ActVt_02217d5c_vtbl);
        break;
    case 0x501b:
    case 0x5037:
    case 0x504e:
    case 0x5056:
        NEW_BASIC(0xfc, Ov009ActVt_02217cb0_vtbl);
        break;
    }
    Actor_JoinGroup(p, s->sub, s->id, Tbl_GetText(s->id));
    *(Rgb021cfab4 *)(p + 0xac) = *(Rgb021cfab4 *)(gSceneCmd + 0xca);
    return p;
}

}
