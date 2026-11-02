#include "types.h"
#include "ov003/ActorApi.h"

extern "C" {

extern s32 Ov003CntSelf_CountLiving(void *p);
extern BOOL Ov003Switch_AreTargetsDone(void *p, BOOL deep);
extern void func_020627b4(void);

static inline BOOL Ov003SwPart_IsOn(ActorSub44 *p) {
    if (p->unk_22_0 == 1 && p->unk_22_1 == 1) {
        return TRUE;
    }
    return FALSE;
}

void Ov003ActVt_021f7e7c_Update(ActorEx *self) {
    u8 changed = FALSE;
    s32 v = -1;
    switch (self->unk_1a) {
    case 3:
        switch (Ov003CntSelf_CountLiving(self->targetObj)) {
        case 3:
        case 4:
            if (self->unk_18 == 0) {
                changed = TRUE;
                v = 1;
            }
            break;
        case 1:
        case 2:
            if (self->unk_18 != 0) {
                v = 0;
                changed = TRUE;
            }
            break;
        }
        break;
    case 2:
        if (Ov003Switch_AreTargetsDone(self->targetObj, TRUE)) {
            if (self->unk_18 == 0) {
                changed = TRUE;
                v = 1;
            }
        } else {
            if (self->unk_18 != 0) {
                changed = TRUE;
                v = 0;
            }
        }
        break;
    case 1:
        if (self->unk_93_1 != self->unk_18) {
            v = self->unk_18;
            func_ov000_02197dec(self, (u8)self->unk_18, -1);
        }
        break;
    }
    switch (v) {
    case 0: {
        ActorSub44 *p = self->unk_44;
        if (p->unk_22_0 == 1 && p->unk_22_1 == 1) {
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        }
        self->unk_93_1 = v;
        break;
    }
    case 1: {
        ActorSub44 *p = self->unk_44;
        if (!Ov003SwPart_IsOn(p)) {
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
        }
        self->unk_93_1 = v;
        break;
    }
    }
    if (changed) {
        self->unk_18 = v;
        func_020627b4();
        func_ov000_02197dec(self, changed, changed);
    }
}

} // extern "C"
