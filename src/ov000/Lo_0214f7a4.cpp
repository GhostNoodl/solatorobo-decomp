#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"
#include "ov000/SceneRes.h"

typedef struct {
    const void *vtbl;
    u32 unk_04;
    u8 unk_08[0x20];
    s32 unk_28;
    u8 unk_2c[0x8c];
    u32 unk_b8_0 : 4;
    u32 unk_b8_4 : 28;
    u8 unk_bc[0xab4];
    s32 unk_b70;
    s32 unk_b74;
    u8 unk_b78[0x4];
    s32 unk_b7c;
} Obj0214c6b4;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x1f0];
    Obj0214c6b4 *unk_200;
    s32 unk_204;
} Obj0214c668;

extern "C" {

extern const u8 TextWin_vtbl[];
extern const u8 MainVt_0208bbc8_vtbl[];
void TextWin_Init(void *obj);
void TwScene_Init(void *obj);
s32 MsgRes_GetLines(void *a, u16 b, s32 *out, s32 c);

static inline void Obj0214c6b4_SetParams(Obj0214c6b4 *obj, s32 a, s32 b) {
    obj->unk_b7c = a;
    obj->unk_b70 = 0;
    obj->unk_b74 = b;
}

static inline BOOL HasWin(Obj0214c668 *w) {
    return w->unk_200 != NULL ? TRUE : FALSE;
}

void Lo021caa44_PostUpdate(Lo021caa44 *self) {
    if (self->state == 0xd) {
        s32 n;
        if (self->unk_5c != NULL) {
            if (self->unk_5c->vfunc_1c()) {
                if ((u8 *)self->unk_50 != NULL) {
                    self->unk_50->flags |= 4;
                }
            } else {
                LO_FREE_V(self, 0x5c);
            }
        }
        if ((Obj0214c668 *)self->unk_60 != NULL) {
            if (!HasWin((Obj0214c668 *)self->unk_60)) {
                if (self->unk_64 != 0xffff) {
                    s32 a;
                    Obj0214c668 *w;
                    Obj0214c6b4 *obj;
                    s32 b;
                    b = MsgRes_GetLines(gSceneResSet.unk_08->sub, self->unk_64, &a, 1);
                    w = (Obj0214c668 *)self->unk_60;
                    w->unk_204 = 0x1e;
                    obj = (Obj0214c6b4 *)Heap_Alloc(0xb80);
                    if (obj != NULL) {
                        obj->vtbl = TextWin_vtbl;
                        TextWin_Init(obj);
                        obj->vtbl = MainVt_0208bbc8_vtbl;
                        TwScene_Init(obj);
                    }
                    w->unk_200 = obj;
                    obj->unk_28 = 8;
                    Obj0214c6b4_SetParams(w->unk_200, a, b);
                    w->unk_200->unk_b8_0 = 4;
                    w->unk_200->unk_04 |= 4;
                    w->unk_0c |= 2;
                    self->unk_50->flags |= 4;
                    self->unk_64 = 0xffff;
                }
            } else {
                self->unk_50->flags |= 4;
            }
        }
        n = 0;
        if (self->unk_4c != NULL && self->unk_4c->vfunc_1c()) {
            n++;
        }
        if ((VObj *)self->unk_50 != NULL && ((VObj *)self->unk_50)->vfunc_1c()) {
            n++;
        }
        if (self->unk_60 != NULL && self->unk_60->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
    }
    if ((u8 *)self->unk_50 != NULL) {
        self->unk_50->flags |= 4;
    }
}

}
