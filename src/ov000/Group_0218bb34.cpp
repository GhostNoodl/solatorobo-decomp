#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u16 id;
    u16 actor;
    u8 unk_04[0xc];
    u8 unk_10;
    u8 unk_11[0x13];
} GroupEntry;

typedef struct GroupNode {
    struct GroupNode *prev;
    struct GroupNode *next;
    u16 id;
    u8 unk_0a;
    u8 count;
    GroupEntry entries[1];
} GroupNode;

typedef struct {
    u8 flag_0 : 1;
    u8 flag_1 : 7;
} GroupFlags;

typedef struct {
    GroupNode *head;
    GroupNode *tail;
    u16 serial;
    u16 count;
    union {
        u8 raw;
        GroupFlags bits;
    } unk_0c;
    u8 unk_0d;
} Group;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Rot3;

struct GroupVec {
    s32 x;
    s32 y;
    s32 z;
    GroupVec() {}
    GroupVec(const GroupVec &o) : x(o.x), y(o.y), z(o.z) {}
};

class GroupActor : public VObj {
public:
    u8 unk_04[0x14];
    s16 unk_18[4];
    u16 unk_20;
    s16 unk_22;
    u8 unk_24[0x4c];
    GroupVec pos;
    Rot3 rot;
};

typedef struct {
    u16 kind;
    u8 unk_02[2];
    s16 unk_04[4];
    s16 unk_0c;
} GroupActorDesc;

typedef struct ActorMgr ActorMgr;

extern "C" {

extern ActorMgr *data_ov000_021ccd68;
GroupActor *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void func_0203de1c(void *p);
void func_ov000_0218ab00(GroupNode *node);
void func_ov000_0218ac98(GroupNode *node);
void func_ov000_0218b4b4(GroupNode *node, s32 a, GroupActor *actor);
GroupActor *func_ov003_021f1420(const GroupActorDesc *desc);
GroupActor *func_ov000_02192b24(const GroupActorDesc *desc);
GroupActor *func_ov003_021cfab4(const GroupActorDesc *desc);
GroupActor *func_ov000_021b4828(const GroupActorDesc *desc);
void func_ov000_0218bc9c(Group *g, GroupNode *node, BOOL notify);

static inline Group *Group_Init(Group *g) {
    g->head = NULL;
    g->tail = NULL;
    g->count = 0;
    g->serial = 0;
    g->unk_0c.raw = 0xff;
    g->unk_0d = 0;
    return g;
}

Group *func_ov000_0218bb34(Group *g) {
    return Group_Init(g);
}

Group *func_ov000_0218bb58(Group *g) {
    while (g->head != NULL) {
        func_ov000_0218bc9c(g, g->head, FALSE);
    }
    return Group_Init(g);
}

void func_ov000_0218bbb0(Group *g, GroupNode *node) {
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

void func_ov000_0218bc9c(Group *g, GroupNode *node, BOOL notify) {
    GroupNode *prev;
    GroupNode *next;
    s32 i;
    if (notify) {
        for (i = 0; i < node->count; i++) {
                GroupEntry *e = node->entries;
                if (e[i].actor != 0xffff) {
                    GroupActor *actor = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, e[i].actor);
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
    func_0203de1c(node);
}

GroupNode *func_ov000_0218bd5c(Group *g, u16 id) {
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

GroupNode *func_ov000_0218bd9c(Group *g, u16 id, u8 b) {
    GroupNode *ret = NULL;
    GroupNode *n;
    for (n = g->head; n != NULL; n = n->next) {
        if (n->entries[1].id == id && (b == 0xff || n->entries[1].unk_10 == b)) {
            ret = n;
            break;
        }
    }
    return ret;
}

GroupNode *func_ov000_0218bddc(Group *g, u16 id, u8 b) {
    GroupNode *ret = NULL;
    GroupNode *n;
    for (n = g->head; n != NULL; n = n->next) {
        u8 i;
        for (i = 0; i < n->count; i++) {
            if (id == n->entries[i].id && (b == 0xff || b == n->entries[i].unk_10)) {
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
    if (g->unk_0c.bits.flag_0 && g->unk_0d != 0) {
        GroupNode *n = g->head;
        while (n != NULL) {
            GroupNode *next = n->next;
            func_ov000_0218ac98(n);
            n = next;
        }
    }
    g->unk_0d = 0;
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

GroupActor *func_ov000_0218bf1c(Group *g, const GroupActorDesc *desc, const GroupVec *pos, const Rot3 *rot, u16 id) {
    GroupActor *actor = NULL;
    s32 i;
    switch ((u16)(desc->kind & 0xf000)) {
    case 0x1000:
        actor = func_ov003_021f1420(desc);
        break;
    case 0x2000:
    case 0x3000:
        actor = func_ov003_021f1420(desc);
        break;
    case 0x4000:
        actor = func_ov000_02192b24(desc);
        break;
    case 0x5000:
        actor = func_ov003_021cfab4(desc);
        break;
    case 0x6000:
        actor = func_ov000_021b4828(desc);
        break;
    }
    if (actor != NULL) {
        actor->unk_20 = id;
        for (i = 0; i < 4; i++) {
            actor->unk_18[i] = desc->unk_04[i];
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
