#include "ov000/VObj.h"
#include "ov000/FieldMgr.h"

extern "C" {

BOOL PauseNode_IsDrawPaused(PauseNode *self, s32 a);
void FieldProp_Draw(FieldProp *n);

void FieldMgr_DrawProps(FieldMgr *self) {
    FieldProp *n;
    if (PauseNode_IsDrawPaused(&self->pause, 1)) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        if (n->visible) {
            FieldProp_Draw(n);
        }
    }
}

}
