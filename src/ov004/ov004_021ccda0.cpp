#include "ov004/ov004.h"

extern "C" {

// This file's .bss: the active callback and the object it is called with.
Ov004Cb data_ov004_021cf860;
Ov004V *data_ov004_021cf864;

#pragma force_active on

void *Ov004_OnCheckFail(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
    u8 *x = (u8 *)ActorMgr_FindPlayer();
    u32 v = (o->unk_16 |= 4);
    if (x != NULL) {
        v |= x[0x16];
    }
    v |= 0x1200;
    if (x != NULL) {
        x[0x16] = v;
    }
    if (a != b) {
        o->unk_16 = v;
    }
    o->unk_22 = v;
    func_ov000_02176264(o);
    return o;
}

void *Ov004_OnCheckPass(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
    u8 *x = (u8 *)ActorMgr_FindPlayer();
    u32 v = (o->unk_16 = o->unk_16 & ~4);
    if (x != NULL) {
        v &= x[0x16];
    }
    v |= 0x3400;
    if (x != NULL) {
        x[0x16] = v;
    }
    if (a != b) {
        o->unk_16 = v;
    }
    o->unk_22 = v;
    func_ov000_021761f0(o);
    return NULL;
}

void *func_ov004_021cce5c(void *a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
    if (a == o) {
        o->unk_22 = 1;
    }
    if ((Ov004V *)b == o) {
        o->unk_22 = 2;
    }
    return o;
}

void *Ov004_Create(void) {
    Ov004V *o;
    u32 k;
    func_ov004_021ce50c();
    o = (Ov004V *)Heap_Alloc(0xac);
    if (o != NULL) {
        Actor_Ctor(o);
        *(u8 **)o = Ov004ActVt_021cf808_vtbl;
    }
    data_ov004_021cf864 = o;
    k = *(u32 *)0x2fffc3c & 1;
    data_ov004_021cf86c[k] = (void *)Ov004_OnCheckPass;
    data_ov004_021cf868 = k;
    data_ov004_021cf86c[k ^ 1] = (void *)Ov004_OnCheckFail;
    data_ov004_021cf860 = func_ov004_021cce5c;
    return o;
}

void Ov004_Destroy(void) {
    void *saved;
    if (data_ov004_021cf860 != NULL) {
        data_ov004_021cf860(data_ov004_021cf864, 0x2010000);
    }
    data_ov004_021cf860 = NULL;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (data_ov004_021cf864 != NULL) {
        Ov004V *p = data_ov004_021cf864;
        if (p != NULL) {
            p->v24();
        }
        data_ov004_021cf864 = NULL;
    }
    gSysState->cur = saved;
}

void *Ov004ActVt_021cf808_DtorDelete(void *p) {
    Actor_DtorBase(p);
    Heap_Free(p);
    return p;
}

void Ov004ActVt_021cf808_UpdateSub44(Ov004V *p) {
    if (p->unk_44 != NULL) {
        Obj021984c8_UpdatePos(p->unk_44, 0, 0);
    }
}

void Ov004ActVt_021cf808_UpdateHit(Ov004V *p) {
    if (p->unk_48 != NULL) {
        ActorSub48_UpdatePos(p->unk_48, 0, 0);
    }
}

void Ov004ActVt_021cf808_Animate(Ov004V *p) {
    if (p->model != NULL) {
        Model0218fe1c_UpdateAnim(p->model, func_0203db40(p->unk_24));
    }
}

void Ov004ActVt_021cf808_RunState(void) {}
void Ov004ActVt_021cf808_SelectState(void) {}
void Ov004ActVt_021cf808_UpdateMode1(void) {}
void Ov004ActVt_021cf808_UpdateMode3(void) {}
void Ov004ActVt_021cf808_Update(void) {}
void Ov004ActVt_021cf808_Start(void) {}
void func_ov004_021cd034(void) {}
void Ov004ActVt_021cf808_Init(void) {}

void *Ov004ActVt_021cf808_Dtor(void *p) {
    Actor_DtorBase(p);
    return p;
}

#pragma force_active reset

}
