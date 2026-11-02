#include "ov000/VObj.h"
#include "ov000/FieldMgr.h"

extern "C" {

BOOL PauseNode_IsDrawPaused(PauseNode *self, s32 a);
void func_ov000_021b7e34(FieldProp *n);

void func_ov000_021b53a8(FieldMgr *self) {
    FieldProp *n;
    if (PauseNode_IsDrawPaused(&self->pause, 1)) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        if (n->visible) {
            func_ov000_021b7e34(n);
        }
    }
}

}
