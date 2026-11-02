#include "types.h"
#include "ov000/ActorParts.h"

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0xe];
    u16 unk_22_0 : 2;
    u16 unk_22_2 : 2;
} Ov003Part44;

typedef struct {
    u8 unk_00[0x60];
    s32 unk_60;
} Ov003Part48;

typedef struct {
    s32 x, y, z;
} Ov003PropVec;

typedef struct {
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *unk_38;
    u8 unk_3c[0x4];
    ActorSub40 *work;
    Ov003Part44 *unk_44;
    Ov003Part48 *unk_48;
    u8 unk_4c[0x24];
    Ov003PropVec pos;
    u8 unk_7c[0x54];
    s32 unk_d0;
} Ov003Prop;

extern void *data_02097e4c;
extern char data_ov003_021f83e8[];
extern const char data_ov003_021f8510[];
extern char data_ov003_021f8516[];
extern void Heap_Free(void *p);
extern void *ActorEx_DtorBase(void *p);
extern void ActorEx_Start(void *p);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern s32 SndMgr_StartSeqArc(void *mgr, s32 v);
extern BOOL Model0218fe1c_SetAnim(void *p, const char *name, s32 a, s32 b);
extern void *Model0218fe1c_SetAnimFrame(void *p, s32 v);
extern void Model0218fe1c_SetLoop(void *p);

Ov003Prop *Ov003ActVt_021f83e8_Dtor(Ov003Prop *self) {
    self->vtbl = data_ov003_021f83e8;
    if (self->unk_d0 >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->unk_d0);
    }
    ActorEx_DtorBase(self);
    return self;
}

Ov003Prop *Ov003ActVt_021f83e8_DtorDelete(Ov003Prop *self) {
    self->vtbl = data_ov003_021f83e8;
    if (self->unk_d0 >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->unk_d0);
    }
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f83e8_Start(Ov003Prop *self) {
    ActorEx_Start(self);
    if (self->unk_18 >= 3) {
        Model0218fe1c_SetAnim(self->unk_38, data_ov003_021f8510, 0x1000, 0);
        Model0218fe1c_SetAnimFrame(self->unk_38, -1);
    } else {
        Model0218fe1c_SetAnim(self->unk_38, data_ov003_021f8516, 0x1000, 0);
        Model0218fe1c_SetLoop(self->unk_38);
    }
    self->unk_44->unk_22_2 = 2;
    self->unk_44->unk_10 = -0x3800;
    self->unk_48->unk_60 = -0x3800;
    self->unk_d0 = SndMgr_StartSeqArc(data_02097e4c, 0x3f);
}

extern void func_ov000_0218996c(u8 a, u8 b);
extern void *Spawn_ScatterEffect(Ov003PropVec *pos, Ov003PropVec *v, s32 a, s32 b, s32 c, s32 d);

void Ov003ActVt_021f83e8_StateIdle(Ov003Prop *self) {
    ActorSub40 *w;
    s32 a;
    s32 b;
    Ov003PropVec p;
    Ov003PropVec sc;
    if (self->unk_18 < 3) {
        return;
    }
    w = self->work;
    w->timer++;
    if (w->timer & 0xf) {
        return;
    }
    a = -1;
    b = 100;
    switch (self->work->timer & 0x3f) {
    case 0:
        func_ov000_0218996c(8, 0xf);
        a = 1;
        break;
    case 0x10:
        break;
    case 0x20:
        func_ov000_0218996c(6, 8);
        a = 3;
        break;
    case 0x30:
        a = 3;
        b = 0x19;
        break;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.y -= 0x4000;
    sc.x = 0x5000;
    sc.y = 0x3000;
    sc.z = 0x3800;
    Spawn_ScatterEffect(&p, &sc, 0x1000, 0x2800, a, b);
}
