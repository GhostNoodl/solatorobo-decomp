#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Group.h"
#include "ov000/FieldMgr.h"


typedef struct {
    VecFx32 pos;
    Rot16 rot;
    u16 id;
    s16 h[4];
    FieldId c;
    u8 flag;
} Ent021b5578;


typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save021b5578;

typedef struct {
    u8 pad[8];
    void *unk_08;
} Lang021b5578;

extern "C" {

extern Save021b5578 *data_0214a424;

Lang021b5578 *Lang_GetGroup(u8 id);
void func_0206dde4(char *buf, u8 *ids);
void func_0206dedc(char *buf, u8 *ids);
void func_0206dfd4(char *buf, u8 *ids);
void ResMgr_LoadArchive(void *a, char *buf, s32 b, s32 c);
BOOL ResMgr_IsArchiveLoaded(void *a, char *buf, s32 b);
void **func_02035fe8(void *a, char *buf);
Ent021b5578 *func_0206e1bc(LangBlockA *r);
u16 LangData_GetIndex(u32 a, u32 b);
u8 *func_020704b4(u16 id);
u8 *LangBlockA_GetData(LangBlockA *r);
u8 *LangBlockA_GetData1(LangBlockA *r);
void *ResMgr_Load(void *e, s32 a, s32 b);
BOOL ResMgr_IsLoaded(void *e, s32 a);
void *ResMgr_GetArcList(void *e);
void *Path_SkipDir(void *e);
void **ResList_FindType5(void *m, void *k);
void **ResList_FindType4(void *m, void *k);
BOOL func_0203ed04(void *k, void *r);
BOOL Vram_IsIdle(void);
void func_02039494(void *r);
FieldExit *func_0206e230(LangBlockB *r);
FieldPropDef *func_0206e2a4(LangBlockB *r);
void *Heap_Alloc(u32 size);
FieldProp *func_ov000_021b79f4(FieldProp *p);
void func_ov000_021b8014(FieldProp *n, const FieldPropDef *def, u8 *list, u8 count);
BOOL func_ov000_021b7f0c(FieldProp *n);

static inline void SetNibble021b5578(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble021b5578(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

static inline void SpawnInit021b5578(GroupActorDesc *s, u16 id) {
    s32 k;
    s->kind = id;
    s->group = id & 0xf000;
    for (k = 0; k < 4; k++) {
        s->args[k] = 0;
    }
    s->unk_0c = -1;
}

static inline u16 Kind021b5578(u16 v) {
    return v >> 12;
}

BOOL FieldMgr_UpdateLoad(FieldMgr *self) {
    BOOL ret = FALSE;
    BOOL ok_0 = TRUE;
    u8 st;
    char buf[0x20];
    u16 kind;
    u8 *ids = data_ov000_021ccd54->unk_ca.c;
    Lang021b5578 *t = Lang_GetGroup(ids[0]);
    switch (self->state) {
    case 0:
        if (self->blockA == NULL) {
            self->state = 10;
        } else {
            st = 0x1e;
            goto set;
        }
    case 10:
        func_0206dde4(buf, ids);
        ResMgr_LoadArchive(t->unk_08, buf, 0, 0);
        st = 0xb;
        goto set;
    case 0xb:
        func_0206dde4(buf, ids);
        if (!ResMgr_IsArchiveLoaded(t->unk_08, buf, 0)) {
            break;
        }
        func_0206dedc(buf, ids);
        ResMgr_LoadArchive(t->unk_08, buf, 0, 0);
        self->state = 0x10;
    case 0x10: {
        void **r_0;
        func_0206dedc(buf, ids);
        if (!ResMgr_IsArchiveLoaded(t->unk_08, buf, 0)) {
            break;
        }
        r_0 = func_02035fe8(t->unk_08, buf);
        if (r_0 != NULL) {
            self->unk_0c = *r_0;
        }
        func_0206dde4(buf, ids);
        r_0 = func_02035fe8(t->unk_08, buf);
        if (r_0 != NULL) {
            self->blockA = (LangBlockA *)*r_0;
        }
        self->state = 0x1e;
        if (self->blockA == NULL) {
            break;
        }
        {
            Ent021b5578 *ents = func_0206e1bc(self->blockA);
            u8 n_0 = self->blockA->count2;
            s32 i_0;
            if (ents != NULL) {
                for (i_0 = 0; i_0 < n_0; i_0++) {
                    Ent021b5578 *e_0 = &ents[i_0];
                    u8 f = e_0->flag;
                    s16 h = e_0->h[0];
                    GroupActorDesc s;
                    FieldId a;
                    FieldId b;
                    GroupNode *o;
                    s32 mode;
                    s32 k_0;
                    if (f != 0xff) {
                        int nib = GetNibble021b5578(LangData_GetIndex(ids[0], ids[1]), f);
                        if (nib == 0xf) {
                            continue;
                        }
                        if (nib & 8) {
                            h = nib & 7;
                        } else {
                            u8 m_0;
                            m_0 = 0;
                            if ((e_0->id >> 12) == 4) {
                                m_0 = func_020704b4(e_0->id)[0x18];
                            }
                            if (m_0 != 1 && m_0 != 2 && m_0 != 3 && m_0 != 4) {
                                u8 f2 = e_0->flag;
                                SetNibble021b5578(LangData_GetIndex(ids[0], ids[1]), f2, (u8)(h | 8));
                            }
                        }
                    }
                    SpawnInit021b5578(&s, e_0->id);
                    s.args[0] = h;
                    for (k_0 = 1; k_0 < 4; k_0++) {
                        s.args[k_0] = e_0->h[k_0];
                    }
                    a.c[0] = e_0->c.c[0];
                    a.c[1] = e_0->c.c[1];
                    a.c[2] = e_0->c.c[2];
                    b.c[0] = e_0->c.c[0];
                    b.c[1] = e_0->c.c[1];
                    b.c[2] = 0xff;
                    mode = 0;
                    o = func_ov000_0218b9ec(&s, &a, &b, NULL, NULL);
                    o->pos = e_0->pos;
                    o->rot.x = e_0->rot.x;
                    o->rot.y = e_0->rot.y;
                    o->rot.z = e_0->rot.z;
                    o->unk_a3 = e_0->flag;
                    kind = Kind021b5578(s.kind);
                    if (e_0->flag != 0xff) {
                        mode = 1;
                    }
                    if (ids[0] == 2 || ids[0] == 0xd) {
                        mode = 3;
                    } else if (ids[0] == 0xa || ids[0] == 0xe || ids[0] == 0xf || ids[0] == 0x10) {
                        mode = 4;
                    }
                    func_ov000_0218b7c0(o, kind, mode);
                }
            }
        }
        {
            u8 *e_1 = LangBlockA_GetData(self->blockA);
            s32 i_1;
            if (e_1 != NULL) {
                for (i_1 = 0; i_1 < self->blockA->count0; i_1++, e_1 += 0x18) {
                    ResMgr_Load(e_1, 7, 0);
                }
                self->state = 0x14;
            }
            e_1 = LangBlockA_GetData1(self->blockA);
            if (e_1 == NULL) {
                break;
            }
            for (i_1 = 0; i_1 < self->blockA->count1; i_1++, e_1 += 0x18) {
                ResMgr_Load(e_1, 7, 0);
            }
            st = 0x14;
        }
        goto set;
    }
    case 0x14: {
        u8 *e_2;
        s32 i_2;
        e_2 = LangBlockA_GetData(self->blockA);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->blockA->count0; i_2++, e_2 += 0x18) {
                if (!ResMgr_IsLoaded(e_2, 7)) {
                    ok_0 = FALSE;
                    break;
                }
            }
        }
        e_2 = LangBlockA_GetData1(self->blockA);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->blockA->count1; i_2++, e_2 += 0x18) {
                if (!ResMgr_IsLoaded(e_2, 7)) {
                    ok_0 = FALSE;
                    break;
                }
            }
        }
        if (!ok_0) {
            break;
        }
        e_2 = LangBlockA_GetData(self->blockA);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->blockA->count0; i_2++, e_2 += 0x18) {
                void *m_1 = ResMgr_GetArcList(e_2);
                if (m_1 != NULL) {
                    void *k_1 = Path_SkipDir(e_2);
                    void **r_1 = ResList_FindType5(m_1, k_1);
                    if (r_1 != NULL) {
                        if (r_1 != NULL) {
                            func_0203ed04(k_1, *r_1);
                        }
                    } else {
                        r_1 = ResList_FindType4(m_1, k_1);
                        if (r_1 != NULL) {
                            func_0203ed04(k_1, *r_1);
                        }
                    }
                }
            }
        }
        self->state = 0x15;
    }
    case 0x15:
        if (Vram_IsIdle()) {
            self->state = 0x16;
        }
        break;
    case 0x16: {
        u8 *e_3 = LangBlockA_GetData(self->blockA);
        s32 i_3;
        if (e_3 != NULL) {
            for (i_3 = 0; i_3 < self->blockA->count0; i_3++, e_3 += 0x18) {
                void *m_2 = ResMgr_GetArcList(e_3);
                if (m_2 != NULL) {
                    void *k_2 = Path_SkipDir(e_3);
                    void **r_2 = ResList_FindType5(m_2, k_2);
                    if (r_2 != NULL) {
                        func_02039494(*r_2);
                    } else {
                        r_2 = ResList_FindType4(m_2, k_2);
                        if (r_2 != NULL) {
                            func_02039494(*r_2);
                        }
                    }
                }
            }
        }
        self->state = 0x1e;
    }
    case 0x1e:
        if (self->blockB != NULL) {
            self->state = 0xff;
            break;
        }
        func_0206dfd4(buf, ids);
        ResMgr_LoadArchive(t->unk_08, buf, 0, 0);
        st = 0x1f;
    set:
        self->state = st;
        break;
    case 0x1f: {
        func_0206dfd4(buf, ids);
        void **r_3;
        if (!ResMgr_IsArchiveLoaded(t->unk_08, buf, 0)) {
            break;
        }
        r_3 = func_02035fe8(t->unk_08, buf);
        if (r_3 != NULL) {
            self->blockB = (LangBlockB *)*r_3;
        }
        if (self->blockB) {
            FieldPropDef *d;
            u8 n_1;
            u8 *e_4;
            s32 i_4;
            self->exits = func_0206e230(self->blockB);
            d = func_0206e2a4(self->blockB);
            n_1 = self->blockB->count2;
            e_4 = LangBlockA_GetData(self->blockA);
            for (i_4 = 0; i_4 < n_1; i_4++) {
                FieldProp *nd = (FieldProp *)Heap_Alloc(sizeof(FieldProp));
                if (nd != NULL) {
                    nd = func_ov000_021b79f4(nd);
                }
                func_ov000_021b8014(nd, &d[i_4], e_4, self->blockA->count0);
                {
                    FieldProp *tl = self->tail;
                    bool has = tl != NULL;
                    if (has) {
                        tl->next = nd;
                    } else {
                        self->head = nd;
                    }
                    nd->prev = tl;
                }
                nd->next = NULL;
                self->tail = nd;
            }
        }
        self->state = 0x28;
    }
    case 0x28: {
        FieldProp *n_2;
        BOOL ok_1 = TRUE;
        for (n_2 = self->head; n_2 != NULL; n_2 = n_2->next) {
            if (!func_ov000_021b7f0c(n_2)) {
                ok_1 = FALSE;
            }
        }
        if (ok_1) {
            self->state = 0xff;
        }
        break;
    }
    case 0xff:
        if (Vram_IsIdle()) {
            self->state = 0xff;
            ret = TRUE;
        }
        break;
    }
    return ret;
}

}
