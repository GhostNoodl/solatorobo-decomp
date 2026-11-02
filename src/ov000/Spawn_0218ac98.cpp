#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorBase.h"
#include "ov000/Group.h"

extern "C" {

void func_ov000_0218af9c(GroupNode *self);

extern Group *data_ov000_021ccd64;
Actor *Group_SpawnActor(Group *g, const GroupActorDesc *desc, const VecFx32 *pos, const Rot16 *rot, u16 id);

static inline BOOL GroupNode_InField(GroupNode *self) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g->unk_ca.c[0] == self->fieldId.c[0] && g->unk_ca.c[1] == self->fieldId.c[1] && g->unk_ca.c[2] == self->fieldId.c[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov000_0218ac98(GroupNode *self) {
    switch (self->state) {
    case 1:
        if (!GroupNode_InField(self)) {
            return;
        }
        func_ov000_0218adf0(self);
        if (self->count != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        BOOL done;
        func_ov000_0218af9c(self);
        if (self->count != 0) {
            return;
        }
        done = FALSE;
        if (self->maxSpawns < 0) {
            done = TRUE;
        } else {
            self->spawned++;
            if (self->maxSpawns >= self->spawned) {
                done = TRUE;
            }
        }
        if (done) {
            self->state = 3;
            return;
        }
        Group_RemoveNode(data_ov000_021ccd64, self, 0);
        break;
    }
    case 3:
        if (!GroupNode_InField(self)) {
            return;
        }
        if (++self->timer >= self->unk_9a * 60) {
            self->timer = 0;
            self->state = 1;
        }
        break;
    }
}


void func_ov000_0218adf0(GroupNode *self) {
    GroupView seg;
    VecFx32 pos;
    u8 i;
    seg.from = self->pos;
    for (i = 0; i < data_ov000_021ccd64->viewCount; i = (u8)(i + 1)) {
        seg.to.x = data_ov000_021ccd64->viewPos[i].x;
        seg.to.y = data_ov000_021ccd64->viewPos[i].y;
        seg.to.z = data_ov000_021ccd64->viewPos[i].z;
        seg.yaw = data_ov000_021ccd64->viewYaw[i];
        if (func_01ffc89c(self, &seg)) {
            BOOL done = FALSE;
            Actor *sp;
            pos = self->pos;
            if (self->flags.toGround) {
                func_ov000_0219a2f4(&pos, 0x5dc000, -0x1000);
            }
            sp = Group_SpawnActor(data_ov000_021ccd64, &self->spawn, &pos, &self->rot, self->id);
            if (sp != NULL) {
                GroupEntry *r;
                done = TRUE;
                if (self->unk_a3 != 0xff) {
                    sp->unk_17 = self->unk_a3;
                }
                r = &self->entries[self->count];
                r->actor = sp->id;
                r->pos = self->pos;
                r->rot.x = self->rot.x;
                r->rot.y = self->rot.y;
                r->rot.z = self->rot.z;
                r->fieldId = data_ov000_021ccd54->unk_ca;
                self->count++;
            }
            if (done) {
                return;
            }
        }
    }
}

}
