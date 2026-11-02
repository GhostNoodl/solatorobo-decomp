#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/SysState.h"

typedef struct {
    s16 state;
} AnimRes;

extern "C" {

extern const u8 data_ov000_021cc480[];
extern void *data_0214a420;

void *Actor_Ctor(void *self);
void *func_ov000_0218c928(void *self);
ResSet *func_ov000_0218ea20(ResSet *self);
void Heap_Free(void *ptr);
void func_02065804(void *mgr, void *handle);
BOOL func_ov000_0218cf5c(void *self);
BOOL func_ov000_0218f110(AnimRes *res);
BOOL Actor_DespawnIfFar(void *self);
void *Target_Get(void *p);
void *func_ov000_0219bf90(void);
void func_0203f364(ActorSub48 *obj);
void HitMesh_Link(void *obj);
void func_ov000_0219864c(ActorSub48 *obj, VecFx32 *pos, s32 c);

static inline void ResSet_Delete(ResSet *res) {
    if (res != NULL) {
        func_ov000_0218ea20(res);
        Heap_Free(res);
    }
}

static inline void ActorEx_Init(ActorEx *self) {
    s32 i;

    Actor_Ctor(self);
    *(const void **)self = data_ov000_021cc480;
    self->unk_ac = 0xff;
    self->unk_ad = 0xff;
    self->unk_ae = 0xff;
    self->param = NULL;
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

    *(const void **)self = data_ov000_021cc480;
    for (i = 0; i < 2; i++) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        if (self->res[i] != NULL) {
            ResSet_Delete(self->res[i]);
            self->res[i] = NULL;
        }
        data_02097dd0->cur = saved;
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
