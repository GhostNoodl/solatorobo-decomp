#include "types.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct ResSet ResSet;

typedef struct {
    s16 state;
} AnimRes;

typedef struct {
    u8 unk_00[0x2];
    u16 type : 3;
    u16 unk_02_3 : 13;
} ActorExParam;

typedef struct {
    u8 unk_00[0x9a];
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 11;
} Obj48;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    const void *vtbl;
    u8 unk_04[0x1c];
    u16 unk_20;
    u8 unk_22[0x1a];
    void *unk_3c;
    u8 unk_40[0x8];
    Obj48 *unk_48;
    void *unk_4c;
    u8 unk_50[0x8];
    void *unk_58;
    u8 unk_5c[0x14];
    VecFx32 pos;
    u8 unk_7c[0x30];
    u8 unk_ac;
    u8 unk_ad;
    u8 unk_ae;
    u8 unk_af;
    ActorExParam *unk_b0;
    ResSet *res[2];
    void *unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u16 unk_cc_0 : 1;
    u16 unk_cc_1 : 1;
    u16 unk_cc_2 : 1;
    u16 unk_cc_3 : 1;
    u16 unk_cc_4 : 1;
    u16 unk_cc_5 : 1;
    u16 unk_cc_6 : 10;
} ActorEx;

extern "C" {

extern const u8 data_ov000_021cc480[];
extern HeapState *data_02097dd0;
extern void *data_0214a420;

void func_ov000_0218c2d4(void *self);
void func_ov000_0218c928(void *self);
ResSet *func_ov000_0218ea20(ResSet *self);
void func_0203de1c(void *ptr);
void func_02065804(void *mgr, void *handle);
BOOL func_ov000_0218cf5c(void *self);
BOOL func_ov000_0218f110(AnimRes *res);
BOOL func_ov000_0218d850(void *self);
void *func_ov000_02199ba0(void *p);
void *func_ov000_0219bf90(void);
void func_0203f364(Obj48 *obj);
void func_0203f8d8(void *obj);
void func_ov000_0219864c(Obj48 *obj, VecFx32 *pos, s32 c);

static inline void ResSet_Delete(ResSet *res) {
    if (res != NULL) {
        func_ov000_0218ea20(res);
        func_0203de1c(res);
    }
}

static inline void ActorEx_Init(ActorEx *self) {
    s32 i;

    func_ov000_0218c2d4(self);
    self->vtbl = data_ov000_021cc480;
    self->unk_ac = 0xff;
    self->unk_ad = 0xff;
    self->unk_ae = 0xff;
    self->unk_b0 = NULL;
    for (i = 0; i < 2; i++) {
        self->res[i] = NULL;
    }
    *((u16 *)self + 0x66) = 0;
    self->unk_bc = NULL;
    self->unk_c0 = 0;
    self->unk_c4 = 0;
    self->unk_c8 = 0;
    self->unk_cc_3 = 1;
    self->unk_cc_4 = 1;
    self->unk_cc_5 = 1;
}

static inline void ActorEx_Destroy(ActorEx *self) {
    s32 i;

    self->vtbl = data_ov000_021cc480;
    for (i = 0; i < 2; i++) {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk_08;
        if (self->res[i] != NULL) {
            ResSet_Delete(self->res[i]);
            self->res[i] = NULL;
        }
        data_02097dd0->current = saved;
    }
    if (self->unk_bc != NULL) {
        func_02065804(data_0214a420, self->unk_bc);
    }
    func_ov000_0218c928(self);
}

BOOL func_ov000_021946f8(ActorEx *self) {
    BOOL ret = func_ov000_0218cf5c(self);
    s32 i;

    if (self->unk_4c != NULL) {
        for (i = 0; i < 2; i++) {
            AnimRes *res = (AnimRes *)self->res[i];
            if (res != NULL && res->state >= 0) {
                if (!func_ov000_0218f110(res)) {
                    ret = FALSE;
                }
            }
        }
    }
    return ret;
}

}
