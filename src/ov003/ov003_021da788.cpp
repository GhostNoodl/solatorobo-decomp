#include "ov003/Vec.h"
#include "Main/Effect/Effect.h"
#include "ov003/FxList.h"

struct Ov003Src {
    u8 unk_00[0xc];
    u16 id;
};

// Callback-side view of an EffectObj that follows an actor: its onUpdate callback (0xdc) reads the
// actor's id (or a scale) and the offset from the object's user words at 0x04..0x13.
struct Ov003Follow {
    void *vtable;
    s32 id;
    Ov003Vec offset;
    u8 unk_14[0xc8];
    void (*callback)(Ov003Follow *self);
};

// The same object for the scaling callback (Ov003Scaled_ApplyScale): EffectObj::unk_04 is the scale,
// 0x10 is EffectObj::SetScale and 0x40 its base scale.
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


extern "C" {

extern const VecFx32 data_ov003_021f4988;
extern void func_01ffc9fc(Ov003Vec *out, const Ov003Vec *in, u16 ang);
extern const VecFx32 data_ov003_021f7cc4;
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *p);
extern void Ov003Follower_Follow(Ov003Follow *self);
extern void Ov003Follower_FollowRot(Ov003Follow *self);

static inline Ov003Follow *Ov003_SpawnFollow(s32 fxId, Ov003Src *src, const Ov003Vec *offset) {
    Ov003Follow *p = NULL;
    if (src != NULL && offset != NULL) {
        p = (Ov003Follow *)Effect_SpawnId(fxId, &data_ov003_021f7cc4);
        if (p != NULL) {
            p->id = src->id;
            p->offset = *offset;
            p->callback = Ov003Follower_Follow;
        }
    }
    return p;
}

Ov003Follow *Ov003_SpawnFollowFx(s32 fxId, Ov003Src *src, const Ov003Vec *offset) {
    return Ov003_SpawnFollow(fxId, src, offset);
}

Ov003Follow *Ov003_SpawnFollowRotFx(s32 fxId, Ov003Src *src, const Ov003Vec *offset) {
    Ov003Follow *p = Ov003_SpawnFollow(fxId, src, offset);
    p->callback = Ov003Follower_FollowRot;
    return p;
}

void Ov003Scaled_ApplyScale(Ov003Scaled *self) {
    if (self == NULL) {
        return;
    }
    Ov003Vec v = self->base;
    s32 s = self->scale;
    v.x = FX_Mul(v.x, s);
    v.y = FX_Mul(v.y, s);
    v.z = FX_Mul(v.z, s);
    self->SetScale(&v);
}

Ov003Follow *Ov003_SpawnScaledFx(s32 fxId, const VecFx32 *pos, s32 scale) {
    Ov003Follow *p = (Ov003Follow *)Effect_SpawnId(fxId, pos);
    p->id = scale;
    p->callback = (void (*)(Ov003Follow *))Ov003Scaled_ApplyScale;
    return p;
}

void Ov003Follow_Attach(Ov003Follow *p, Ov003Src *src, const Ov003Vec *offset) {
    if (p == NULL) {
        return;
    }
    p->id = src->id;
    p->offset = *offset;
    p->callback = Ov003Follower_Follow;
}

static inline void Ov003_HeapDelete(void *p) {
    void *old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (p != NULL) {
        Heap_Free(p);
    }
    data_02097dd0->cur = old;
}

Ov003FxList *Ov003FxList_Dtor(Ov003FxList *self) {
    Ov003FxNode *n = self->head;
    while (n != NULL) {
        Ov003FxNode *next = n->next;
        EffectMgr_Kill(data_0214a420, n->handle);
        Ov003_HeapDelete(n);
        n = next;
    }
    return self;
}

void Ov003FxList_Add(Ov003FxList *self, u8 id, EffectObj *obj) {
    Ov003FxNode *node = (Ov003FxNode *)Heap_Alloc(sizeof(Ov003FxNode));
    node->id = id;
    node->handle = obj->id;
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

BOOL Ov003FxList_Has(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            return TRUE;
        }
    }
    return FALSE;
}

u32 Ov003FxList_Get(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            return n->handle;
        }
    }
    return 0;
}

void Ov003FxList_Kill(Ov003FxList *self, u8 id) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            EffectMgr_Kill(data_0214a420, n->handle);
        }
    }
}

void Ov003FxList_KillAll(Ov003FxList *self) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        EffectMgr_Kill(data_0214a420, n->handle);
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

void Ov003FxList_Place(Ov003FxList *self, u8 id, const VecFx32 *pos, const EffectRot *rot, const VecFx32 *scale, const VecFx32 *ofs, const u16 *angles) {
    Ov003FxNode *n;
    for (n = self->head; n != NULL; n = n->next) {
        if (id == n->id) {
            EffectObj *o = Effect_Find_020657b0(data_0214a420, n->handle);
            if (o != NULL) {
                VecFx32 vp = data_ov003_021f4988;
                if (ofs != NULL) {
                    vp = *ofs;
                }
                if (angles != NULL) {
                    Ov003_RotX((Ov003Vec *)&vp, (Ov003Vec *)&vp, angles[0]);
                    func_01ffc9fc((Ov003Vec *)&vp, (Ov003Vec *)&vp, angles[1]);
                }
                VEC_Add(&vp, pos, &vp);
                {
                    Ov003Vec base(o->pos);
                    vp.x -= base.x;
                    vp.y -= base.y;
                    vp.z -= base.z;
                }
                o->AddPos(&vp);
                if (rot != NULL) {
                    o->SetRot(rot);
                }
                if (scale != NULL) {
                    o->SetScale(scale);
                }
            }
        }
    }
}

}
