#include "types.h"

typedef struct Ov003SwNode Ov003SwNode;
struct Ov003SwNode {
    u8 unk_00[8];
    Ov003SwNode *next;
    u8 unk_0c[2];
    u16 id;
    u8 unk_10[0x83];
    u8 unk_93_0 : 1;
    u8 state : 3;
};

typedef struct {
    u8 unk_00[0xc];
    Ov003SwNode *head;
} Ov003SwList;

typedef struct {
    u8 unk_00[4];
    u16 ids[2];
} Ov003SwTargets;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    Ov003SwTargets targets;
} Ov003Switch;

BOOL func_ov003_021f0a38(Ov003Switch *self, Ov003Switch *def) {
    BOOL r = FALSE;
    s32 i;
    Ov003SwTargets *t = &def->targets;
    for (i = 0; i < 2; i++) {
        u16 id = t->ids[i];
        if (id != 0xffff) {
            if ((u16)(id & 0xf000)) {
                if (id == self->id) {
                    r = TRUE;
                }
            } else if ((u16)(id << 12) == (u16)(self->id & 0xf000)) {
                r = TRUE;
            }
        }
        if (r) {
            break;
        }
    }
    return r;
}

typedef struct {
    u8 unk_00[8];
    u16 unk_08;
    u8 unk_0a[2];
    Ov003SwNode *head;
    u8 unk_10[6];
    u16 unk_16;
} Ov003SwGroup;

typedef struct Ov003SwObj Ov003SwObj;
struct Ov003SwObj {
    u8 unk_00[4];
    Ov003SwObj *next;
    u8 unk_08[0x2a];
    u16 unk_32;
    u8 unk_34[0xa];
    u8 unk_3e;
    u8 unk_3f;
    u8 unk_40;
};

typedef struct {
    Ov003SwObj *head;
} Ov003SwObjList;

typedef struct {
    u8 unk_00[0xca];
    u8 unk_ca;
    u8 unk_cb;
    u8 unk_cc;
} Ov003SwGame;

typedef struct {
    u8 unk_00[0x93];
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
} Ov003SwPlayer;

extern void *data_ov000_021ccd68;
extern Ov003SwObjList *data_ov000_021ccd64;
extern Ov003SwGame *data_ov000_021ccd54;
extern Ov003SwGroup *func_ov000_0218e4cc(void *mgr, u16 key);
extern Ov003SwPlayer *func_ov000_0219bf90(void);

BOOL func_ov003_021f0abc(Ov003Switch *self, BOOL deep) {
    BOOL r = TRUE;
    s32 i;
    Ov003SwTargets *t = &self->targets;
    for (i = 0; i < 2; i++) {
        u16 id = t->ids[i];
        if (id != 0xffff) {
            Ov003SwGroup *g;
            if ((u16)(id & 0xf000) == 0) {
                id = (u16)(id << 12) | 0xfff;
            }
            g = func_ov000_0218e4cc(data_ov000_021ccd68, id);
            if (g != NULL) {
                if ((id & 0xfff) != 0xfff) {
                    Ov003SwNode *head = g->head;
                    Ov003SwNode *a = head;
                    if (head != NULL) {
                        do {
                            if (id == a->id) {
                                r = FALSE;
                                break;
                            }
                            a = (a != NULL) ? a->next : head;
                        } while (a != NULL);
                    }
                } else {
                    if (g->unk_16 != 0) {
                        r = FALSE;
                        break;
                    }
                    if ((g->unk_08 >> 12) == 5) {
                        Ov003SwPlayer *p = func_ov000_0219bf90();
                        if (p != NULL && p->unk_93_4) {
                            r = FALSE;
                            break;
                        }
                    }
                    if (deep) {
                        Ov003SwGame *game = data_ov000_021ccd54;
                        Ov003SwObjList *list = data_ov000_021ccd64;
                        u16 key = id & 0xf000;
                        Ov003SwObj *n;
                        for (n = list->head; n != NULL; n = (n != NULL) ? n->next : list->head) {
                            BOOL match = FALSE;
                            if (n->unk_3e == game->unk_ca && n->unk_3f == game->unk_cb && n->unk_40 == game->unk_cc) {
                                match = TRUE;
                            }
                            if (match && n->unk_32 == key) {
                                r = FALSE;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (!r) {
            break;
        }
    }
    return r;
}
