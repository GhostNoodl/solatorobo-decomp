#include "Main/Effect/Effect.h"

extern "C" {

extern u32 data_0208c1d8[];
extern u32 data_0208c1e8[];
extern u32 data_0208c23c[];
extern u32 data_0208c290[];
extern u32 data_0208c2e4[];
extern char data_0208c374[];
extern char data_0208c380[];
extern char data_0208c38b[];
extern char data_0208c397[];
extern char data_0208c3a1[];
extern char data_0208c3ad[];
extern char data_0208c3bb[];
extern char data_0208c3c7[];
extern char data_0208c3d6[];
extern char data_0208c3e2[];
extern char data_0208c3f1[];
extern char data_0208c3fd[];
extern char data_0208c40c[];
extern char data_0208c418[];
extern char data_0208c427[];
extern char data_0208c436[];

extern void func_02063a34(EffectObj *obj);
extern void func_02063bd0(EffectObj *obj);
extern void func_02063f90(Effect3D *e);
extern void func_02063fd4(Effect3D *e);
extern void func_020639d4(EffectObj *obj, s32 id, s32 frame);
extern void func_02064b40(Effect3D *e);
extern void func_02068540(struct EffectSetup *setup);
extern void func_02035a74(void *arc);
extern void func_0206e900(char *dst, const char *src);

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        func_0201e520(dst, src);
    }
}

static inline Effect3D *Effect3D_New(void) {
    Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = data_0208c2e4;
        func_02063a34(e);
        *(u32 **)e = data_0208c290;
        func_02063f90(e);
    }
    return e;
}

static inline Effect3D *EffectHud3D_New(void) {
    Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = data_0208c2e4;
        func_02063a34(e);
        *(u32 **)e = data_0208c290;
        func_02063f90(e);
        *(u32 **)e = data_0208c1e8;
        func_02064b40(e);
    }
    return e;
}

Effect3D *func_02066774(const char *arc, const char *mdl, const char *anm, const EffectVec *pos) {
    Effect3D *e = Effect3D_New();
    Effect_SetStr(e->arcName, arc);
    Effect_SetStr(e->mdlName, mdl);
    Effect_SetStr(e->anmName, anm);
    e->SetPos(pos);
    return e;
}

Effect3D *func_0206682c(const char *arc, const char *mdl, const char *anm, const EffectVec *pos) {
    Effect3D *e = (Effect3D *)func_0203dd9c(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = data_0208c2e4;
        func_02063a34(e);
        *(u32 **)e = data_0208c290;
        func_02063f90(e);
        *(u32 **)e = data_0208c1e8;
        e->unk_14 = 1;
        e->unk_c4 = 0;
    }
    Effect_SetStr(e->arcName, arc);
    Effect_SetStr(e->mdlName, mdl);
    Effect_SetStr(e->anmName, anm);
    e->SetPos(pos);
    return e;
}

EffectGroup *func_02066900(const char *arc, const char *name, const EffectVec *pos) {
    EffectGroup *g = (EffectGroup *)func_0203dd9c(sizeof(EffectGroup));
    if (g != NULL) {
        *(u32 **)g = data_0208c2e4;
        func_02063a34(g);
        *(u32 **)g = data_0208c23c;
        g->unk_14 = 4;
        g->arcName[0] = 0;
        g->name[0] = 0;
        g->arc = NULL;
        g->setup = NULL;
    }
    Effect_SetStr(g->arcName, arc);
    Effect_SetStr(g->name, name);
    g->SetPos(pos);
    return g;
}

struct EffectSetup *func_020669ac(struct EffectSetup *setup) {
    *(u32 **)setup = data_0208c1d8;
    func_02068540(setup);
    return setup;
}

void func_020669cc(EffectObj *obj, const EffectVec *offset) {
    obj->offset = *offset;
}

void func_020669e8(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->offset.x = x;
    obj->offset.y = y;
    obj->offset.z = z;
}

void func_020669f8(EffectObj *obj, s32 scale) {
    obj->SetScaleXYZ(scale, scale, scale);
}

void func_02066a14(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

static inline void EffectGroup_Dtor(EffectGroup *g) {
    EffectObj *c;
    *(u32 **)g = data_0208c23c;
    for (c = g->child; c != NULL; c = c->child) {
        c->state = 4;
    }
    if (g->arcName[0] != 0) {
        func_02035a74(g->arc);
        g->arc = NULL;
        g->arcName[0] = 0;
    }
    *(u32 **)g = data_0208c2e4;
    func_02063bd0(g);
}

EffectGroup *func_02066a24(EffectGroup *g) {
    EffectGroup_Dtor(g);
    func_0203de1c(g);
    return g;
}

EffectGroup *func_02066a9c(EffectGroup *g) {
    EffectGroup_Dtor(g);
    return g;
}

void func_02066b0c(EffectObj *obj, u16 x, u16 y, u16 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void func_02066b1c(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->pos.x += x;
    obj->pos.y += y;
    obj->pos.z += z;
}

void func_02066b48(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->pos.x = x;
    obj->pos.y = y;
    obj->pos.z = z;
}

static inline void Effect3D_Dtor(Effect3D *e) {
    *(u32 **)e = data_0208c290;
    func_02063fd4(e);
    *(u32 **)e = data_0208c2e4;
    func_02063bd0(e);
}

Effect3D *func_02066b58(Effect3D *e) {
    Effect3D_Dtor(e);
    func_0203de1c(e);
    return e;
}

Effect3D *func_02066b94(Effect3D *e) {
    Effect3D_Dtor(e);
    return e;
}

Effect3D *func_02066bc8(Effect3D *e) {
    Effect3D_Dtor(e);
    func_0203de1c(e);
    return e;
}

Effect3D *func_02066c04(Effect3D *e) {
    Effect3D_Dtor(e);
    return e;
}

EffectObj *func_02066c38(EffectObj *obj) {
    *(u32 **)obj = data_0208c2e4;
    func_02063bd0(obj);
    return obj;
}

}
