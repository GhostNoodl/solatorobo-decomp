#include "types.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Group.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/FieldMgr.h"


typedef struct {
    VecFx32 pos;
    Rot16 rot;
    u16 id;
    s16 h[4];
} Ent021b5dc0;


extern "C" {

extern Group *data_ov000_021ccd64;
extern const FieldMgrFn data_ov000_021cc81c;
extern const FieldMgrFn data_ov000_021cc824;
extern char data_ov000_021cc82c[];
extern char data_ov000_021cc83d[];

void func_0206e660(LangBlockA *p);
void func_0206e648(LangBlockB *p);
void Gfx3DState_Apply(void *p);
s32 func_0206e340(LangBlockB *r);
Ent021b5dc0 *func_0206e2ec(LangBlockB *r);
Robo021ca458 *ActorMgr_FindPlayer(void);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Body_SetPos(void *body, VecFx32 *pos, u16 angle);
void **func_02035edc(const char *a, const char *b);
void *NNS_G3dGetAnmByIdx(void *p, s32 idx);
void Camera_SetAnim(Camera *cam, void *anim);
void func_ov000_021b7e60(FieldProp *n, s32 v);

static inline BOOL SameArea021b5dc0(void) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g->unk_ca.c[0] == g->unk_d0.c[0] && g->unk_ca.c[1] == g->unk_d0.c[1] && g->unk_ca.c[2] == g->unk_d0.c[2]) {
        r = TRUE;
    }
    return r;
}

static inline void SpawnInit021b5dc0(GroupActorDesc *s, u16 id) {
    s32 k;
    s->kind = id;
    s->group = id & 0xf000;
    for (k = 0; k < 4; k++) {
        s->args[k] = 0;
    }
    s->unk_0c = -1;
}

static inline u16 Kind021b5dc0(u16 v) {
    return v >> 12;
}

void func_ov000_021b5dc0(FieldMgr *self) {
    GroupActorDesc s;
    VecFx32 base;
    VecFx32 out;
    FieldCam *cam;
    FieldState *g;
    Ent021b5dc0 *ents;
    s32 i;
    s32 k;
    u16 id;
    u8 v;
    s32 mode;
    Robo021ca458 *pl;
    Actor *a;
    FieldProp *n;

    if (self->blockA != NULL) {
        func_0206e660(self->blockA);
    }
    if (self->blockB != NULL) {
        func_0206e648(self->blockB);
    }
    Gfx3DState_Apply(data_02097d48->unk_8b0);
    v = self->blockB->count4;
    cam = &data_ov000_021ccd54->cam;
    cam->unk_c8 = func_0206e340(self->blockB);
    cam->unk_d6 = v;
    g = data_ov000_021ccd54;
    ents = func_0206e2ec(self->blockB);
    if (ents != NULL && (!SameArea021b5dc0() || data_ov000_021ccd54->unk_c9 != 0)) {
        for (i = 0; i < self->blockB->count3; i++) {
            GroupNode *o;
            u16 kind;
            id = ents[i].id;
            if (id == 0xffff) {
                if (g->unk_ca.c[0] != 0x12) {
                    continue;
                }
                id = 0x4f41;
            }
            SpawnInit021b5dc0(&s, id);
            for (k = 0; k < 4; k++) {
                s.args[k] = ents[i].h[k];
            }
            mode = 0;
            o = func_ov000_0218b9ec(&s, &g->unk_ca, &g->unk_ca, NULL, NULL);
            o->pos = ents[i].pos;
            o->rot.x = ents[i].rot.x;
            o->rot.y = ents[i].rot.y;
            o->rot.z = ents[i].rot.z;
            kind = Kind021b5dc0(s.kind);
            if (g->unk_ca.c[0] == 2 || g->unk_ca.c[0] == 0xd) {
                mode = 3;
            } else if (g->unk_ca.c[0] == 0xa || g->unk_ca.c[0] == 0xf || g->unk_ca.c[0] == 0xe || g->unk_ca.c[0] == 0x10 || id == 0x461a) {
                mode = 4;
            } else if (g->unk_ca.c[0] == 0x12) {
                mode = 5;
            }
            func_ov000_0218b7c0(o, kind, mode);
        }
    }
    if (self->unk_1f0 != 0xffff) {
        pl = ActorMgr_FindPlayer();
        if (Group_GetSpawnPositions(data_ov000_021ccd64, 1, &base, self->unk_1f0 >> 12, self->unk_1f0)) {
            for (i = 0; i < 0x20; i++) {
                id = self->ids[i];
                if (id == 0xffff) {
                    continue;
                }
                if (pl != NULL && id == pl->id) {
                    VEC_Add(&base, &self->vecs[i], &out);
                    pl->unk_75c = out;
                    pl->fieldId = data_ov000_021ccd54->unk_ca;
                } else {
                    a = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, id);
                    if (a != NULL) {
                        VEC_Add(&base, &self->vecs[i], &out);
                        a->pos = out;
                        a->speed = 0;
                        a->velY = 0;
                        a->friction = 0;
                        a->gravity = 0;
                        if (a->hit != NULL) {
                            Body_SetPos(a->hit, &out, a->rot_y);
                        }
                    }
                }
                self->ids[i] = 0xffff;
            }
        }
        self->unk_1f0 = 0xffff;
    }
    self->step = NULL;
    self->unk_1f2 = 0;
    if (g->unk_ca.c[0] == 0x10 && g->unk_ca.c[1] == 0 && (g->unk_ca.c[2] == 0 || g->unk_ca.c[2] == 3)) {
        void **res = func_02035edc(data_ov000_021cc82c, data_ov000_021cc83d);
        if (res != NULL && *res != NULL) {
            Camera_SetAnim(&cam->base, NNS_G3dGetAnmByIdx(*res, 0));
            self->unk_1f2 = 0x52;
            if (g->unk_ca.c[2] == 3) {
                self->unk_1f2 = 0xa4;
            }
            cam->base.speed = self->unk_1f2;
            self->step = data_ov000_021cc81c;
        }
    }
    if (self->blockB->unk_19_2) {
        self->step = data_ov000_021cc824;
    }
    if (g->unk_ca.c[0] != 0x12) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        n->keepHit = 1;
        func_ov000_021b7e60(n, 0x1ccd);
    }
}

}
