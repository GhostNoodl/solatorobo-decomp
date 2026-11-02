#include "ov004/ov004.h"

extern "C" {

// This file's .bss: the active callback and the object it is called with.
Ov004Cb data_ov004_021cf860;
Ov004V *data_ov004_021cf864;

#pragma force_active on

void *func_ov004_021ccda0(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
    u8 *x = (u8 *)func_ov000_0219bf90();
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

void *func_ov004_021ccdfc(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
    u8 *x = (u8 *)func_ov000_0219bf90();
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

void *func_ov004_021cce88(void) {
    Ov004V *o;
    u32 k;
    func_ov004_021ce50c();
    o = (Ov004V *)Heap_Alloc(0xac);
    if (o != NULL) {
        Actor_Ctor(o);
        *(u8 **)o = data_ov004_021cf808;
    }
    data_ov004_021cf864 = o;
    k = *(u32 *)0x2fffc3c & 1;
    data_ov004_021cf86c[k] = (void *)func_ov004_021ccdfc;
    data_ov004_021cf868 = k;
    data_ov004_021cf86c[k ^ 1] = (void *)func_ov004_021ccda0;
    data_ov004_021cf860 = func_ov004_021cce5c;
    return o;
}

void func_ov004_021ccf10(void) {
    void *saved;
    if (data_ov004_021cf860 != NULL) {
        data_ov004_021cf860(data_ov004_021cf864, 0x2010000);
    }
    data_ov004_021cf860 = NULL;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (data_ov004_021cf864 != NULL) {
        Ov004V *p = data_ov004_021cf864;
        if (p != NULL) {
            p->v24();
        }
        data_ov004_021cf864 = NULL;
    }
    data_02097dd0->cur = saved;
}

void *Ov004ActVt_021cf808_DtorDelete(void *p) {
    func_ov000_0218c928(p);
    Heap_Free(p);
    return p;
}

void func_ov004_021ccfb0(Ov004V *p) {
    if (p->unk_44 != NULL) {
        func_ov000_021984f4(p->unk_44, 0, 0);
    }
}

void func_ov004_021ccfd0(Ov004V *p) {
    if (p->unk_48 != NULL) {
        func_ov000_0219864c(p->unk_48, 0, 0);
    }
}

void func_ov004_021ccff0(Ov004V *p) {
    if (p->unk_38 != NULL) {
        func_ov000_02190a80(p->unk_38, func_0203db40(p->unk_24));
    }
}

void func_ov004_021cd01c(void) {}
void func_ov004_021cd020(void) {}
void func_ov004_021cd024(void) {}
void func_ov004_021cd028(void) {}
void Ov004ActVt_021cf808_Update(void) {}
void Ov004ActVt_021cf808_Start(void) {}
void func_ov004_021cd034(void) {}
void Ov004ActVt_021cf808_Init(void) {}

void *Ov004ActVt_021cf808_Dtor(void *p) {
    func_ov000_0218c928(p);
    return p;
}

#pragma force_active reset

}
