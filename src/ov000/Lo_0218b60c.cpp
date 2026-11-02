#include "ov000/Group.h"

extern "C" {

// Sets the position, rotation and field of the entry of the node's spawn kind; a node that is not
// in state 2 first gets its first entry from `spawn` and goes to state 2.
void func_ov000_0218b60c(GroupNode *self, const FieldId *fieldId, const VecFx32 *pos, const Rot16 *rot) {
    GroupEntry *e;
    s32 i;
    i = 0;
    e = NULL;
    if (self->state == 2) {
        for (; i < self->count; i++) {
            if (self->spawn.kind == self->entries[i].kind) {
                e = &self->entries[i];
                break;
            }
        }
        if (e == NULL) {
            return;
        }
    } else {
        self->state = 2;
        self->count++;
        e = &self->entries[0];
        e->actor = self->spawn.group;
        e->kind = self->spawn.kind;
        for (; i < 4; i++) {
            e->args[i] = self->spawn.args[i];
        }
        e->unk_0c = self->spawn.unk_0c;
    }
    e->pos = *pos;
    e->rot = *rot;
    e->fieldId = *fieldId;
}

}
