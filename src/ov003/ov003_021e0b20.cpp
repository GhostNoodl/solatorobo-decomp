#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActorApi.h"

extern "C" {

extern int func_02043d9c(void *p);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);
extern void func_ov000_02191008(void *p);

void Ov003ActVt_021f8058_Draw(ActorEx *self) {
    GfxSys *s = data_02097d48;
    u8 v = s->unk_8b0[3];
    func_02043d9c(s->unk_8b0);
    self->model->polyId = v;
    func_ov000_02194c08(self);
}

void Ov003ActVt_021f82b8_Start(ActorEx *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 0x20, 0);
    func_ov000_02191008(self->model);
}

extern char data_ov003_021f8531[];
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void func_ov003_021e0b7c(ActorEx *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *p;
        func_ov000_02190cb0(self->model, data_ov003_021f8531, 0x1000, 0);
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        }
        self->fsm->st++;
    }
    case 1: {
        ActorSub44 *p;
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}

} // extern "C"
