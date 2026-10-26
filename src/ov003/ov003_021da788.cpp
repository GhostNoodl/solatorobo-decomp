#include "ov003/Vec.h"

struct Ov003Src {
    u8 unk_00[0xc];
    u16 id;
};

struct Ov003Follow {
    void *vtable;
    s32 id;
    Ov003Vec offset;
    u8 unk_14[0xc8];
    void (*callback)(Ov003Follow *self);
};

class Ov003Scaled {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void SetScale(Ov003Vec *v);
    s32 scale;
    u8 unk_08[0x38];
    Ov003Vec base;
};

struct Ov003FxNode {
    u8 id;
    void *handle;
    Ov003FxNode *next;
};

struct Ov003FxList {
    Ov003FxNode *head;
};

struct Ov003Handled {
    u8 unk_00[0x24];
    void *handle;
};

struct Ov003HeapCtx {
    void *cur;
    u32 unk_04;
    void *alt;
};


struct Ov003VecP {
    s32 x;
    s32 y;
    s32 z;
};

class Ov003FxObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(s32 a);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(Ov003Vec *v);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30(s32 a);
    u8 unk_04[0x54];
    Ov003Vec base;
};

extern "C" {

extern Ov003HeapCtx *data_02097dd0;
extern void *data_0214a420;
extern const Ov003VecP data_ov003_021f4988;
extern Ov003FxObj *func_020657b0(void *mgr, void *handle);
extern void func_01ffc9fc(Ov003Vec *out, const Ov003Vec *in, u16 ang);
extern u8 data_ov003_021f7cc4[];
extern void *func_02065f88(void *mgr, const void *arg);
extern void func_02065804(void *mgr, void *handle);
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *p);
extern void func_ov003_021da520(Ov003Follow *self);
extern void func_ov003_021da620(Ov003Follow *self);

static inline Ov003Follow *Ov003_SpawnFollow(void *mgr, Ov003Src *src, const Ov003Vec *offset) {
    Ov003Follow *p = NULL;
    if (src != NULL && offset != NULL) {
        p = (Ov003Follow *)func_02065f88(mgr, data_ov003_021f7cc4);
        if (p != NULL) {
            p->id = src->id;
            p->offset = *offset;
            p->callback = func_ov003_021da520;
        }
    }
    return p;
}

Ov003Follow *func_ov003_021da788(void *mgr, Ov003Src *src, const Ov003Vec *offset) {
    return Ov003_SpawnFollow(mgr, src, offset);
}

Ov003Follow *func_ov003_021da7e8(void *mgr, Ov003Src *src, const Ov003Vec *offset) {
    Ov003Follow *p = Ov003_SpawnFollow(mgr, src, offset);
    p->callback = func_ov003_021da620;
    return p;
}

void func_ov003_021da854(Ov003Scaled *self) {
    if (self == NULL) {
        return;
    }
    Ov003Vec v = self->base;
    s32 s = self->scale;
    v.x = Ov003_FxMul(v.x, s);
    v.y = Ov003_FxMul(v.y, s);
    v.z = Ov003_FxMul(v.z, s);
    self->SetScale(&v);
}

Ov003Follow *func_ov003_021da8e4(void *mgr, const void *arg, s32 scale) {
    Ov003Follow *p = (Ov003Follow *)func_02065f88(mgr, arg);
    p->id = scale;
    p->callback = (void (*)(Ov003Follow *))func_ov003_021da854;
    return p;
}

void func_ov003_021da904(Ov003Follow *p, Ov003Src *src, const Ov003Vec *offset) {
    if (p == NULL) {
        return;
    }
    p->id = src->id;
    p->offset = *offset;
    p->callback = func_ov003_021da520;
}

static inline void Ov003_HeapDelete(void *p) {
    void *old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    if (p != NULL) {
        func_0203de1c(p);
    }
    data_02097dd0->cur = old;
}

Ov003FxList *func_ov003_021da940(Ov003FxList *self) {
    Ov003FxNode *n = self->head;
    while (n != NULL) {
        Ov003FxNode *next = n->next;
        func_02065804(data_0214a420, n->handle);
        Ov003_HeapDelete(n);
        n = next;
    }
    return self;
}

void func_ov003_021da9ac(Ov003FxList *self, u8 id, Ov003Handled *obj) {
    Ov003FxNode *node = (Ov003FxNode *)func_0203dd9c(sizeof(Ov003FxNode));
    node->id = id;
    node->handle = obj->handle;
    node->next = NULL;
    if (self->head == NULL) {
        self->head = node;
    } else {
        Ov003FxNode *p = self->head;
        // The read through a const view keeps p->next from being reused across iterations
        while (p->next != NULL) {
            p = ((const Ov003FxNode *)p)->next;
        }
        p->next = node;
    }
}

BOOL func_ov003_021daa0c(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            return TRUE;
        }
    }
    return FALSE;
}

void *func_ov003_021daa3c(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            return n->handle;
        }
    }
    return NULL;
}

void func_ov003_021daa6c(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            func_02065804(data_0214a420, n->handle);
        }
    }
}

void func_ov003_021daab0(Ov003FxList *self) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        func_02065804(data_0214a420, n->handle);
    }
}

static inline void Ov003_RotX(Ov003Vec *out, const Ov003Vec *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

void func_ov003_021daae4(Ov003FxList *self, u8 id, const Ov003Vec *pos, s32 a, s32 b, const Ov003Vec *ofs, const u16 *rot) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            Ov003FxObj *o = func_020657b0(data_0214a420, n->handle);
            if (o != NULL) {
                Ov003VecP vp = data_ov003_021f4988;
                if (ofs != NULL) {
                    *(Ov003Vec *)&vp = *ofs;
                }
                if (rot != NULL) {
                    Ov003_RotX((Ov003Vec *)&vp, (Ov003Vec *)&vp, rot[0]);
                    func_01ffc9fc((Ov003Vec *)&vp, (Ov003Vec *)&vp, rot[1]);
                }
                VEC_Add((Ov003Vec *)&vp, pos, (Ov003Vec *)&vp);
                {
                    Ov003Vec base = o->base;
                    vp.x -= base.x;
                    vp.y -= base.y;
                    vp.z -= base.z;
                }
                o->SetPos((Ov003Vec *)&vp);
                if (a != 0) {
                    o->v30(a);
                }
                if (b != 0) {
                    o->v10(b);
                }
            }
        }
    }
}

}
