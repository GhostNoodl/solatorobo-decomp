#include "ov000/VObj.h"
#include "ov000/ActorBase.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

// The spawned actor (an Actor, with unk_18 .. unk_1e as the array the spawn args are copied to).
class GroupActor : public VObj {
public:
    u8 unk_04[0x14];
    s16 unk_18[4];
    u16 unk_20;
    s16 unk_22;
    u8 unk_24[0x4c];
    VecFx32 pos;
    Rot16 rot;
};

typedef struct ActorMgr ActorMgr;

extern "C" {

extern ActorMgr *data_ov000_021ccd68;
GroupActor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Heap_Free(void *p);
void func_ov000_0218b4b4(GroupNode *node, s32 a, GroupActor *actor);
GroupActor *Ov003Prop_New(const GroupActorDesc *desc);
GroupActor *Factory_New4000(const GroupActorDesc *desc);
GroupActor *Ov003_NewActor(const GroupActorDesc *desc);
GroupActor *Factory_New6000(const GroupActorDesc *desc);

static inline Group *Group_Init(Group *g) {
    g->head = NULL;
    g->tail = NULL;
    g->count = 0;
    g->serial = 0;
    g->unk_0c.raw = 0xff;
    g->viewCount = 0;
    return g;
}

Group *func_ov000_0218bb34(Group *g) {
    return Group_Init(g);
}

Group *Group_Clear(Group *g) {
    while (g->head != NULL) {
        Group_RemoveNode(g, g->head, FALSE);
    }
    return Group_Init(g);
}

void Group_Add(Group *g, GroupNode *node) {
    GroupNode *tail = g->tail;
    BOOL done;
    if (tail != NULL) {
        tail->next = node;
    } else {
        g->head = node;
    }
    node->prev = tail;
    node->next = NULL;
    g->tail = node;
    g->count++;
    if (!(g->serial & 0x8000)) {
        node->id = g->serial;
        g->serial++;
        if (g->serial >= 0x7ffe) {
            g->serial = 0x8000;
        }
        return;
    }
    done = FALSE;
    do {
        u16 id = g->serial & 0x7fff;
        BOOL found = FALSE;
        GroupNode *p;
        for (p = g->head; p != NULL; p = p->next) {
            if (p->id == id) {
                found = TRUE;
                break;
            }
        }
        if (!found) {
            node->id = id;
            done = TRUE;
        }
        if ((u16)(id + 1) < 0x7ffe) {
            g->serial++;
        } else {
            g->serial = 0x8000;
        }
    } while (!done);
}

void Group_RemoveNode(Group *g, GroupNode *node, BOOL notify) {
    GroupNode *prev;
    GroupNode *next;
    s32 i;
    if (notify) {
        for (i = 0; i < node->count; i++) {
                GroupEntry *e = node->entries;
                if (e[i].actor != 0xffff) {
                    GroupActor *actor = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, e[i].actor);
                    if (actor != NULL) actor->vfunc_08();
                }
        }
    }
    prev = node->prev;
    next = node->next;
    if (prev != NULL) {
        prev->next = next;
    } else {
        g->head = next;
    }
    if (next != NULL) {
        next->prev = prev;
    } else {
        g->tail = prev;
    }
    g->count--;
    Heap_Free(node);
}

GroupNode *Group_FindNode(Group *g, u16 id) {
    GroupNode *ret = NULL;
    GroupNode *n;
    if (id != 0xffff) {
        for (n = g->head; n != NULL; n = n->next) {
            if (n->id == id) {
                ret = n;
                break;
            }
        }
    }
    return ret;
}

GroupNode *Group_FindById(Group *g, u16 id, u8 b) {
    GroupNode *ret = NULL;
    GroupNode *n;
    for (n = g->head; n != NULL; n = n->next) {
        if (n->spawn.kind == id && (b == 0xff || n->fieldId.c[2] == b)) {
            ret = n;
            break;
        }
    }
    return ret;
}

GroupNode *Group_FindNodeByKind(Group *g, u16 id, u8 b) {
    GroupNode *ret = NULL;
    GroupNode *n;
    for (n = g->head; n != NULL; n = n->next) {
        u8 i;
        for (i = 0; i < n->count; i++) {
            if (id == n->entries[i].kind && (b == 0xff || b == n->entries[i].fieldId.c[2])) {
                ret = n;
                break;
            }
        }
        if (ret != NULL) {
            break;
        }
    }
    return ret;
}

void func_ov000_0218be54(Group *g) {
    if (g->unk_0c.bits.flag_0 && g->viewCount != 0) {
        GroupNode *n = g->head;
        while (n != NULL) {
            GroupNode *next = n->next;
            func_ov000_0218ac98(n);
            n = next;
        }
    }
    g->viewCount = 0;
}

void func_ov000_0218be9c(Group *g) {
    GroupNode *n = g->head;
    while (n != NULL) {
        GroupNode *next = n->next;
        func_ov000_0218ab00(n);
        n = next;
    }
    if (g->count == 0) {
        g->serial = 0;
    }
}

void func_ov000_0218bed8(Group *g, s32 a, GroupActor *actor) {
    u16 id = actor->unk_20;
    GroupNode *n;
    if (id != 0xffff) {
        for (n = g->head; n != NULL; n = n->next) {
            if (id == n->id) {
                func_ov000_0218b4b4(n, a, actor);
                return;
            }
        }
    }
}

GroupActor *Group_SpawnActor(Group *g, const GroupActorDesc *desc, const VecFx32 *pos, const Rot16 *rot, u16 id) {
    GroupActor *actor = NULL;
    s32 i;
    switch ((u16)(desc->kind & 0xf000)) {
    case 0x1000:
        actor = Ov003Prop_New(desc);
        break;
    case 0x2000:
    case 0x3000:
        actor = Ov003Prop_New(desc);
        break;
    case 0x4000:
        actor = Factory_New4000(desc);
        break;
    case 0x5000:
        actor = Ov003_NewActor(desc);
        break;
    case 0x6000:
        actor = Factory_New6000(desc);
        break;
    }
    if (actor != NULL) {
        actor->unk_20 = id;
        for (i = 0; i < 4; i++) {
            actor->unk_18[i] = desc->args[i];
        }
        actor->unk_22 = desc->unk_0c;
        actor->pos.x = pos->x;
        actor->pos.y = pos->y;
        actor->pos.z = pos->z;
        actor->rot.x = rot->x;
        actor->rot.y = rot->y;
        actor->rot.z = rot->z;
        actor->vfunc_04();
    }
    return actor;
}

}
