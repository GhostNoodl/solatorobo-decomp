#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct Node021b5578 {
    struct Node021b5578 *prev;
    struct Node021b5578 *next;
} Node021b5578;

typedef struct {
    u8 pad_00[0xa];
    u8 n_a;
    u8 n_b;
    u8 n_ents;
} Res021b5578;

typedef struct {
    u8 pad_00[0x16];
    u8 n;
} Res2021b5578;

typedef struct {
    u8 pad_00[8];
    u8 state;
    u8 pad_09[3];
    void *unk_0c;
    Res021b5578 *unk_10;
    Res2021b5578 *unk_14;
    void *unk_18;
    Node021b5578 *head;
    Node021b5578 *tail;
} Mgr021b5578;

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    u16 id;
    s16 h[4];
    u8 c[3];
    u8 flag;
} Ent021b5578;

typedef struct {
    u16 id;
    u16 kind;
    s16 v[4];
    s16 m;
} Spawn021b5578;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save021b5578;

typedef struct {
    u8 pad[8];
    void *unk_08;
} Lang021b5578;

extern "C" {

extern u8 *data_ov000_021ccd54;
extern Save021b5578 *data_0214a424;

Lang021b5578 *func_0206e7d0(u8 id);
void func_0206dde4(char *buf, u8 *ids);
void func_0206dedc(char *buf, u8 *ids);
void func_0206dfd4(char *buf, u8 *ids);
void func_020359fc(void *a, char *buf, s32 b, s32 c);
BOOL func_02035bd4(void *a, char *buf, s32 b);
void **func_02035fe8(void *a, char *buf);
Ent021b5578 *func_0206e1bc(Res021b5578 *r);
s32 func_0206e7ec(u32 a, u32 b);
u8 *func_020704b4(u16 id);
void *func_ov000_0218b9ec(Spawn021b5578 *s, u8 *a, u8 *b, s32 c, s32 d);
void func_ov000_0218b7c0(void *o, u16 kind, s32 mode);
u8 *func_0206e150(Res021b5578 *r);
u8 *func_0206e180(Res021b5578 *r);
void func_020359d0(void *e, s32 a, s32 b);
BOOL func_02035b90(void *e, s32 a);
void *func_02035d5c(void *e);
void *func_02039674(void *e);
void **func_02034f5c(void *m, void *k);
void **func_02034ec0(void *m, void *k);
void func_0203ed04(void *k, void *r);
BOOL func_0203e688(void);
void func_02039494(void *r);
void *func_0206e230(Res2021b5578 *r);
u8 *func_0206e2a4(Res2021b5578 *r);
void *func_0203dd9c(u32 size);
Node021b5578 *func_ov000_021b79f4(void *p);
void func_ov000_021b8014(Node021b5578 *n, u8 *d, u8 *e, u8 c);
BOOL func_ov000_021b7f0c(Node021b5578 *n);

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

static inline void SpawnInit021b5578(Spawn021b5578 *s, u16 id) {
    s32 k;
    s->id = id;
    s->kind = id & 0xf000;
    for (k = 0; k < 4; k++) {
        s->v[k] = 0;
    }
    s->m = -1;
}

static inline u16 Kind021b5578(u16 v) {
    return v >> 12;
}

BOOL func_ov000_021b5578(Mgr021b5578 *self) {
    BOOL ret = FALSE;
    BOOL ok_0 = TRUE;
    u8 st;
    char buf[0x20];
    u16 kind;
    u8 *ids = data_ov000_021ccd54 + 0xca;
    Lang021b5578 *t = func_0206e7d0(ids[0]);
    switch (self->state) {
    case 0:
        if (self->unk_10 == NULL) {
            self->state = 10;
        } else {
            st = 0x1e;
            goto set;
        }
    case 10:
        func_0206dde4(buf, ids);
        func_020359fc(t->unk_08, buf, 0, 0);
        st = 0xb;
        goto set;
    case 0xb:
        func_0206dde4(buf, ids);
        if (!func_02035bd4(t->unk_08, buf, 0)) {
            break;
        }
        func_0206dedc(buf, ids);
        func_020359fc(t->unk_08, buf, 0, 0);
        self->state = 0x10;
    case 0x10: {
        void **r_0;
        func_0206dedc(buf, ids);
        if (!func_02035bd4(t->unk_08, buf, 0)) {
            break;
        }
        r_0 = func_02035fe8(t->unk_08, buf);
        if (r_0 != NULL) {
            self->unk_0c = *r_0;
        }
        func_0206dde4(buf, ids);
        r_0 = func_02035fe8(t->unk_08, buf);
        if (r_0 != NULL) {
            self->unk_10 = (Res021b5578 *)*r_0;
        }
        self->state = 0x1e;
        if (self->unk_10 == NULL) {
            break;
        }
        {
            Ent021b5578 *ents = func_0206e1bc(self->unk_10);
            u8 n_0 = self->unk_10->n_ents;
            s32 i_0;
            if (ents != NULL) {
                for (i_0 = 0; i_0 < n_0; i_0++) {
                    Ent021b5578 *e_0 = &ents[i_0];
                    u8 f = e_0->flag;
                    s16 h = e_0->h[0];
                    Spawn021b5578 s;
                    u8 a[3];
                    u8 b[3];
                    void *o;
                    s32 mode;
                    s32 k_0;
                    if (f != 0xff) {
                        int nib = GetNibble021b5578(func_0206e7ec(ids[0], ids[1]), f);
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
                                SetNibble021b5578(func_0206e7ec(ids[0], ids[1]), f2, (u8)(h | 8));
                            }
                        }
                    }
                    SpawnInit021b5578(&s, e_0->id);
                    s.v[0] = h;
                    for (k_0 = 1; k_0 < 4; k_0++) {
                        s.v[k_0] = e_0->h[k_0];
                    }
                    a[0] = e_0->c[0];
                    a[1] = e_0->c[1];
                    a[2] = e_0->c[2];
                    b[0] = e_0->c[0];
                    b[1] = e_0->c[1];
                    b[2] = 0xff;
                    mode = 0;
                    o = func_ov000_0218b9ec(&s, a, b, 0, 0);
                    LFLD(VecFx32, o, 0x88) = e_0->pos;
                    LFLD(u16, o, 0x94) = e_0->unk_0c;
                    LFLD(u16, o, 0x96) = e_0->unk_0e;
                    LFLD(u16, o, 0x98) = e_0->unk_10;
                    LFLD(u8, o, 0xa3) = e_0->flag;
                    kind = Kind021b5578(s.id);
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
            u8 *e_1 = func_0206e150(self->unk_10);
            s32 i_1;
            if (e_1 != NULL) {
                for (i_1 = 0; i_1 < self->unk_10->n_a; i_1++, e_1 += 0x18) {
                    func_020359d0(e_1, 7, 0);
                }
                self->state = 0x14;
            }
            e_1 = func_0206e180(self->unk_10);
            if (e_1 == NULL) {
                break;
            }
            for (i_1 = 0; i_1 < self->unk_10->n_b; i_1++, e_1 += 0x18) {
                func_020359d0(e_1, 7, 0);
            }
            st = 0x14;
        }
        goto set;
    }
    case 0x14: {
        u8 *e_2;
        s32 i_2;
        e_2 = func_0206e150(self->unk_10);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->unk_10->n_a; i_2++, e_2 += 0x18) {
                if (!func_02035b90(e_2, 7)) {
                    ok_0 = FALSE;
                    break;
                }
            }
        }
        e_2 = func_0206e180(self->unk_10);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->unk_10->n_b; i_2++, e_2 += 0x18) {
                if (!func_02035b90(e_2, 7)) {
                    ok_0 = FALSE;
                    break;
                }
            }
        }
        if (!ok_0) {
            break;
        }
        e_2 = func_0206e150(self->unk_10);
        if (e_2 != NULL) {
            for (i_2 = 0; i_2 < self->unk_10->n_a; i_2++, e_2 += 0x18) {
                void *m_1 = func_02035d5c(e_2);
                if (m_1 != NULL) {
                    void *k_1 = func_02039674(e_2);
                    void **r_1 = func_02034f5c(m_1, k_1);
                    if (r_1 != NULL) {
                        if (r_1 != NULL) {
                            func_0203ed04(k_1, *r_1);
                        }
                    } else {
                        r_1 = func_02034ec0(m_1, k_1);
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
        if (func_0203e688()) {
            self->state = 0x16;
        }
        break;
    case 0x16: {
        u8 *e_3 = func_0206e150(self->unk_10);
        s32 i_3;
        if (e_3 != NULL) {
            for (i_3 = 0; i_3 < self->unk_10->n_a; i_3++, e_3 += 0x18) {
                void *m_2 = func_02035d5c(e_3);
                if (m_2 != NULL) {
                    void *k_2 = func_02039674(e_3);
                    void **r_2 = func_02034f5c(m_2, k_2);
                    if (r_2 != NULL) {
                        func_02039494(*r_2);
                    } else {
                        r_2 = func_02034ec0(m_2, k_2);
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
        if (self->unk_14 != NULL) {
            self->state = 0xff;
            break;
        }
        func_0206dfd4(buf, ids);
        func_020359fc(t->unk_08, buf, 0, 0);
        st = 0x1f;
    set:
        self->state = st;
        break;
    case 0x1f: {
        func_0206dfd4(buf, ids);
        void **r_3;
        if (!func_02035bd4(t->unk_08, buf, 0)) {
            break;
        }
        r_3 = func_02035fe8(t->unk_08, buf);
        if (r_3 != NULL) {
            self->unk_14 = (Res2021b5578 *)*r_3;
        }
        if (self->unk_14) {
            u8 *d;
            u8 n_1;
            u8 *e_4;
            s32 i_4;
            self->unk_18 = func_0206e230(self->unk_14);
            d = func_0206e2a4(self->unk_14);
            n_1 = self->unk_14->n;
            e_4 = func_0206e150(self->unk_10);
            for (i_4 = 0; i_4 < n_1; i_4++) {
                Node021b5578 *nd = (Node021b5578 *)func_0203dd9c(0x114);
                if (nd != NULL) {
                    nd = func_ov000_021b79f4(nd);
                }
                func_ov000_021b8014(nd, d + i_4 * 0x34, e_4, self->unk_10->n_a);
                {
                    Node021b5578 *tl = self->tail;
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
        Node021b5578 *n_2;
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
        if (func_0203e688()) {
            self->state = 0xff;
            ret = TRUE;
        }
        break;
    }
    return ret;
}

}
