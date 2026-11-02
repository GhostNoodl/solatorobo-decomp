#include "nitro/fx.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Group.h"

extern "C" {

GroupNode *func_ov000_0218a9d8(GroupNode *self) {
    s32 i;
    self->prev = NULL;
    self->next = NULL;
    self->id = 0xffff;
    self->state = 1;
    self->count = 0;
    self->entries[0].kind = 0xffff;
    self->entries[0].actor = 0xffff;
    self->spawn.kind = 0xffff;
    self->spawn.group = 0xf000;
    for (i = 0; i < 4; i++) {
        self->spawn.args[i] = 0;
    }
    self->spawn.unk_0c = -1;
    self->fieldId.c[0] = 0xff;
    self->fieldId.c[1] = 0xff;
    self->fieldId.c[2] = 0xff;
    self->fieldFilter.c[0] = 0xff;
    self->fieldFilter.c[1] = 0xff;
    self->fieldFilter.c[2] = 0xff;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rot.x = 0;
    self->rot.y = 0;
    self->rot.z = 0;
    self->spawnRange = 0x37000;
    self->despawnRange = 0x39000;
    self->spawnHeight = 0x14000;
    self->despawnHeight = 0x16000;
    self->fadeStart = 0x32000;
    self->spawnMin.x = -self->spawnRange;
    self->spawnMin.y = -self->spawnHeight;
    self->spawnMin.z = -self->spawnRange;
    self->spawnMax.x = self->spawnRange;
    self->spawnMax.y = self->spawnHeight;
    self->spawnMax.z = self->spawnRange;
    self->despawnMin.x = -self->despawnRange;
    self->despawnMin.y = -self->despawnHeight;
    self->despawnMin.z = -self->despawnRange;
    self->despawnMax.x = self->despawnRange;
    self->despawnMax.y = self->despawnHeight;
    self->despawnMax.z = self->despawnRange;
    self->timer = 0;
    self->unk_9a = 0;
    self->spawned = 0;
    self->maxSpawns = 0;
    self->unk_a2 = 0xff;
    self->flags.toGround = 0;
    self->flags.unk_5 = 0;
    self->flags.unk_6 = 0;
    self->unk_a3 = 0xff;
    return self;
}


extern Group *data_ov000_021ccd64;
Robo021ca458 *ActorMgr_FindPlayer(void);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 key);
void func_ov000_0218df68(ActorGroup *group, Actor *actor);
void func_ov000_0218b4b4(GroupNode *self, s32 mode, Actor *actor);

static inline Actor *GetActor0218ab00(u16 id) {
    Actor *a;
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

#define ENTRY(base) ((GroupEntry *)((base) + 0xc))

void func_ov000_0218ab00(GroupNode *self) {
    FieldState *g;
    BOOL changed;
    Robo021ca458 *ctx;
    s32 i;
    u8 *base;
    Actor *a;
    g = data_ov000_021ccd54;
    changed = FALSE;
    if (self->fieldFilter.c[2] != 0xff && self->fieldFilter.c[2] != g->unk_ca.c[2]) {
        changed = TRUE;
    }
    if (self->fieldFilter.c[1] != 0xff && self->fieldFilter.c[1] != g->unk_ca.c[1]) {
        changed = TRUE;
    }
    if (self->fieldFilter.c[0] != 0xff && self->fieldFilter.c[0] != g->unk_ca.c[0]) {
        changed = TRUE;
    }
    if (g->unk_c9 != 0) {
        changed = TRUE;
    }
    ctx = ActorMgr_FindPlayer();
    for (i = 0; i < self->count; i++) {
        // The entry is reached from the slot base (node + i * 0x24) at each use: with
        // entries[i] the tests below load the player's id before the entry's.
        base = (u8 *)self + i * sizeof(GroupEntry);
        if (ENTRY(base)->actor == 0xffff) {
            continue;
        }
        a = GetActor0218ab00(ENTRY(base)->actor);
        if (a == NULL) {
            continue;
        }
        if (ctx != NULL && ENTRY(base)->actor == ctx->unk_b20) {
            continue;
        }
        if (a->flags_1) {
            a->flags_1 = 0;
            continue;
        }
        if (changed) {
            a->flags_0 = 1;
        }
        if (self->flags.unk_6 && ctx != NULL && ENTRY(base)->actor == ctx->unk_b1c && data_ov000_021ccd54->unk_c9 == 0) {
            continue;
        }
        func_ov000_0218b4b4(self, 2, a);
        func_ov000_0218df68(ActorMgr_GetGroup(data_ov000_021ccd68, a->id & 0xf000), a);
    }
    if (changed) {
        Group_RemoveNode(data_ov000_021ccd64, self, 0);
    }
}

}
