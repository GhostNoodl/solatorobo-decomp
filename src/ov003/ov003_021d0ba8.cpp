#include "types.h"
#include "Main/Lang/TblRes.h"
#include "Main/Effect/Effect.h"
#include "nitro/std.h"
#include "ov003/Actor.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Sys/SysState.h"

extern "C" {

typedef struct {
    MtxFx43 slots[2]; // current matrices captured during the draw
    u8 ids[2];
} Ov003SlotTable;

typedef struct {
    u8 unk_00[0x2c];
    Ov003SlotTable *table;
} Ov003SlotOwner;

// The object Ov003Obj_CaptureMtx is called with: 0x04 and 0x08 are not Actor::prev / next here.
typedef struct {
    void *vtbl;
    Ov003SlotOwner *owner;
    u32 flags;
    u8 unk_0c[0x18];
    void (*func)(void *);
    u8 unk_28[0x6a];
    u8 unk_92;
    u8 unk_93[0x1b];
    u8 unk_ae;
} Ov003Obj;

extern Actor *Actor_Ctor(Actor *self);
extern char data_ov003_021f7ab4[];

typedef struct {
    u16 bit0 : 1;
    u16 bit1 : 1;
} Ov003ResFlags;

typedef struct {
    u8 unk_00[0x12];
    Ov003ResFlags flags;
} Ov003ResInfo;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char unk_10[0x20];
    char unk_30[0x1c];
    char unk_4c[0x20];
    char unk_6c[0x58];
    char unk_c4[0x20];
    char unk_e4[0x1c];
    char unk_100[0x20];
    char unk_120[0x20];
} Ov003Res;

extern Ov003ResInfo *Tbl_FindEntry_0206fef8(u16 id);
extern char *Tbl_GetResFile(u16 id);
extern char *func_020701d4(u16 id);
extern char *Tbl_GetEntryData(u16 id, s32 n);
extern void ResSet_SetFile(Ov003Res *p, char *res, s32 a, s32 b, s32 c, s32 d);

void Ov003Res_SetNames(Ov003Res *res, u16 id) {
    Ov003ResInfo *info = Tbl_FindEntry_0206fef8(id);
    TblActorParam *param = Tbl_GetActorParam(id);
    char *name = Tbl_GetResFile(id);
    char *a;
    char *b;
    if (param->evName != NULL) {
        char *alt = func_020701d4(id);
        if (info->flags.bit0) {
            STD_CopyString(res->unk_10, name);
            STD_CopyString(res->unk_30, alt);
            res->unk_03 |= 2;
        }
        if (info->flags.bit1) {
            STD_CopyString(res->unk_4c, name);
            STD_CopyString(res->unk_6c, alt);
            res->unk_03 |= 4;
        }
        alt = param->evName;
        STD_CopyString(res->unk_c4, name);
        STD_CopyString(res->unk_e4, alt);
        res->unk_03 |= 0x10;
    } else {
        ResSet_SetFile(res, name, info->flags.bit0 != 0, info->flags.bit1 != 0, 0, 0);
    }
    a = Tbl_GetEntryData(id, 0);
    b = Tbl_GetEntryData(id, 1);
    if (a != NULL && b != NULL) {
        STD_CopyString(res->unk_100, a);
        STD_CopyString(res->unk_120, b);
        res->unk_03 |= 0x20;
    }
    res->unk_00 = 0;
}

void Ov003Obj_CaptureMtx(Ov003Obj *self) {
    s32 id;
    Ov003SlotTable *t;
    s32 i;
    t = self->owner->table;
    if (self->flags & 0x10) {
        id = self->unk_ae;
    } else {
        id = -1;
    }
    for (i = 0; i < 2; i++) {
        if (t->ids[i] != 0xff && id == t->ids[i]) {
            NNS_G3dGetCurrentMtx(&t->slots[i], 0);
            return;
        }
    }
}

void Ov003Obj_StartCapture(Ov003Obj *self) {
    self->func = (void (*)(void *))Ov003Obj_CaptureMtx;
    self->unk_92 = 3;
}

#define OV003_OBJ_CTOR(name)                 \
Ov003Actor *name(Ov003Actor *self) {         \
    Actor_Ctor(self);                        \
    *(void **)self = data_ov003_021f7ab4;    \
    self->unk_b4 = 0;                        \
    self->unk_b6 = 0;                        \
    self->unk_ac = 0xff;                     \
    self->unk_ad = 0xff;                     \
    self->unk_ae = 0xff;                     \
    self->unk_b0 = NULL;                     \
    self->unk_c4 = NULL;                     \
    self->unk_d0 = NULL;                     \
    self->unk_d4 = NULL;                     \
    self->unk_d8 = NULL;                     \
    self->unk_e8 = 0;                        \
    self->target_id = 0xffff;                \
    self->unk_ea = 0;                        \
    self->unk_ec = 0;                        \
    self->unk_ee = 0;                        \
    self->unk_c8 = 0;                        \
    self->unk_cc = 0;                        \
    self->unk_e4 = NULL;                     \
    self->unk_e0 = NULL;                     \
    return self;                             \
}

OV003_OBJ_CTOR(Ov003Actor_Ctor)
OV003_OBJ_CTOR(Ov003Actor_Ctor_021d0c94)

extern void *Model0218fe1c_FreeAnims(void *p);
extern void Heap_Free(void *p);
extern void *Actor_DtorBase(Actor *self);

static inline void Ov003Actor_DtorBody(Ov003Actor *self) {
    s32 i;
    *(void **)self = data_ov003_021f7ab4;
    if (self->unk_d0 != NULL) {
        for (i = 0; i < 2; i++) {
            void *old = data_02097dd0->cur;
            void *m;
            data_02097dd0->cur = data_02097dd0->heapHi;
            m = self->unk_d0->models[i];
            if (m != NULL) {
                if (m != NULL) {
                    Model0218fe1c_FreeAnims(m);
                    Heap_Free(m);
                }
                self->unk_d0->models[i] = NULL;
            }
            data_02097dd0->cur = old;
        }
        Heap_FreeHi(self->unk_d0);
    }
    if (self->unk_e4 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_e4);
        self->unk_e4 = NULL;
    }
    if (self->unk_e0 != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_e0);
        self->unk_e0 = NULL;
    }
    Actor_DtorBase(self);
}

Ov003Actor *Ov003Actor_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBody(self);
    return self;
}

Ov003Actor *Ov003Actor_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBody(self);
    Heap_Free(self);
    return self;
}

void *Ov003Actor_DtorBase(void *self) {
    Ov003Actor_DtorBody(static_cast<Ov003Actor *>(self));
    return self;
}

typedef struct {
    u8 unk_00[0x12];
    u16 unk_12_0 : 12;
    u16 unk_12_12 : 2;
    u16 unk_12_14 : 2;
} Ov003InitInfo;

extern void *Heap_Alloc(u32 size);
extern void *ResSet_Init(void *p);
extern ActorShadow *Shadow_Ctor(void *p);
extern void Shadow_Load(ActorShadow *p);
extern void *History_Init(void *p);
extern BOOL History_SetState(void *p, s32 a, s32 b);

static inline void Ov003Shadow_Push(ActorShadow *s, u8 v) {
    s->unk_18_4 = s->unk_18_0;
    s->unk_18_0 = v;
}

void Ov003Actor_Init(Ov003Actor *self) {
    Ov003InitInfo *info = (Ov003InitInfo *)Tbl_FindEntry_0206fef8(self->kind);
    void *p;
    self->unk_b0 = (Ov003Param *)((u8 *)Tbl_GetActorParam(self->kind) + 0x10);
    p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = ResSet_Init(p);
    }
    self->unk_34 = p;
    if (self->nameFunc != NULL) {
        self->nameFunc(p, self->kind);
    } else {
        Ov003Res_SetNames((Ov003Res *)p, self->kind);
    }
    if (info->unk_12_12 != 0) {
        ActorShadow *s = (ActorShadow *)Heap_Alloc(0x1c);
        if (s != NULL) {
            s = Shadow_Ctor(s);
        }
        self->unk_3c = s;
        if (info->unk_12_14 == 0) {
            Ov003Shadow_Push(s, 1);
        } else {
            Ov003Shadow_Push(s, 0);
        }
        Shadow_Load(self->unk_3c);
    }
    p = Heap_Alloc(0x14);
    if (p != NULL) {
        p = History_Init(p);
    }
    self->fsm = (ActorSub40 *)p;
    if (self->unk_b0->unk_0a_13) {
        History_SetState(p, 0x20, 0);
    }
    self->moveYaw = self->rot_y;
    self->unk_ea_0 = self->unk_b0->unk_0a_7;
    self->unk_ea_10 = self->unk_b0->unk_0a_0 ? 1 : 0;
}

}
