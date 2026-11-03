#include "ov006/ov006.h"
#include "ov000/ObjLayouts.h"
#include <nitro/mi.h>

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x2c];
    int unk2C;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *gWhMgr;
void func_02045094(ov006_Unk02097e40 *p);
void func_02045498(ov006_Unk02097e40 *p, int a);
BOOL WH_IsStopped_02044c80(void);
BOOL Wh_End(ov006_Unk02097e40 *p);

static inline void ov006_Menu_ClearNodes(ov006_Unk021ec888 *self) {
    ov006_MenuNode *node = self->nodes;
    while (node != NULL) {
        void *saved;
        ov006_MenuNode *next;
        next = node->next;
        saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (node != NULL) {
            if (node != NULL) {
                node->vfunc_04();
            }
            node = NULL;
        }
        gSysState->cur = saved;
        node = next;
    }
    self->nodes = NULL;
    self->unk24 = 0;
    self->unk26 = 1;
}

static inline void ov006_MenuEntry_Clear(ov006_MenuEntry *e) {
    e->unk0_0 = 0;
    e->unk0_4 = 0;
    MI_CpuFill16(e->unk2, 0, sizeof(e->unk2));
}

void func_ov006_021e4d38(ov006_Unk021ec888 *self) {
    int i;

    switch (self->stateTime) {
    case 0:
        gSysState->vblankFunc = NULL;
        if (WH_IsStopped_02044c80()) {
            self->state = 1;
            self->stateTime = 0;
            return;
        }
        func_02045094(gWhMgr);
        self->stateTime = 10;
        if (self->unk1D8 != NULL && self->unk1D8->obj != NULL) {
            self->unk1D8->obj->flags |= 2;
        }
    case 10:
        if (gWhMgr->unk2C == 1) {
            if (Wh_End(gWhMgr)) {
                self->stateTime = 20;
            }
        } else {
            if (gWhMgr->unk2C == 8 || gWhMgr->unk2C == 9) {
                func_02045498(gWhMgr, 0);
            }
            return;
        }
    case 20:
        if (gWhMgr->unk2C != 0) {
            return;
        }
        self->state = 1;
        self->stateTime = 0;
        ov006_Menu_ClearNodes(self);
        for (i = 0; i < 4; i++) {
            ov006_MenuEntry_Clear(&self->entries[i]);
        }
        break;
    }
}

}
