#include "Main/Effect/EffectInt.h"

extern "C" {

extern u32 EffectSetup_vtbl[];
extern u32 MainVt_0208c1e8_vtbl[];
extern u32 EffectGroup_vtbl[];
extern u32 MainVt_0208c290_vtbl[];
extern u32 EffectObj_vtbl[];
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

extern void EffectObj_Register(EffectObj *obj);
extern void EffectObj_Unregister(EffectObj *obj);
extern void Effect3D_Init(Effect3D *e);
extern void Effect3D_Release(Effect3D *e);
extern void EffectObj_AddSndCue(EffectObj *obj, s32 id, s32 frame);
extern void EffectHud_Init(Effect3D *e);
extern void func_02068540(struct EffectSetup *setup);
extern void ResMgr_ReleaseList(void *arc);
extern void LangData_LocalizePath(char *dst, const char *src);

static inline void Effect_SetStr(char *dst, const char *src) {
    if (src == NULL) {
        dst[0] = 0;
    } else {
        STD_CopyString(dst, src);
    }
}

static inline Effect3D *Effect3D_New(void) {
    Effect3D *e = (Effect3D *)Heap_Alloc(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = EffectObj_vtbl;
        EffectObj_Register(e);
        *(u32 **)e = MainVt_0208c290_vtbl;
        Effect3D_Init(e);
    }
    return e;
}

static inline Effect3D *EffectHud3D_New(void) {
    Effect3D *e = (Effect3D *)Heap_Alloc(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = EffectObj_vtbl;
        EffectObj_Register(e);
        *(u32 **)e = MainVt_0208c290_vtbl;
        Effect3D_Init(e);
        *(u32 **)e = MainVt_0208c1e8_vtbl;
        EffectHud_Init(e);
    }
    return e;
}

Effect3D *Effect3D_Create(const char *arc, const char *mdl, const char *anm, const VecFx32 *pos) {
    Effect3D *e = Effect3D_New();
    Effect_SetStr(e->arcName, arc);
    Effect_SetStr(e->mdlName, mdl);
    Effect_SetStr(e->anmName, anm);
    e->SetPos(pos);
    return e;
}

Effect3D *Effect3D_NewAt(const char *arc, const char *mdl, const char *anm, const VecFx32 *pos) {
    Effect3D *e = (Effect3D *)Heap_Alloc(sizeof(Effect3D));
    if (e != NULL) {
        *(u32 **)e = EffectObj_vtbl;
        EffectObj_Register(e);
        *(u32 **)e = MainVt_0208c290_vtbl;
        Effect3D_Init(e);
        *(u32 **)e = MainVt_0208c1e8_vtbl;
        e->unk_14 = 1;
        e->unk_c4 = 0;
    }
    Effect_SetStr(e->arcName, arc);
    Effect_SetStr(e->mdlName, mdl);
    Effect_SetStr(e->anmName, anm);
    e->SetPos(pos);
    return e;
}

EffectGroup *EffectGroup_Create(const char *arc, const char *name, const VecFx32 *pos) {
    EffectGroup *g = (EffectGroup *)Heap_Alloc(sizeof(EffectGroup));
    if (g != NULL) {
        *(u32 **)g = EffectObj_vtbl;
        EffectObj_Register(g);
        *(u32 **)g = EffectGroup_vtbl;
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

struct EffectSetup *EffectSetup_Dtor(struct EffectSetup *setup) {
    *(u32 **)setup = EffectSetup_vtbl;
    func_02068540(setup);
    return setup;
}

void EffectObj_SetOffset(EffectObj *obj, const VecFx32 *offset) {
    obj->offset = *offset;
}

void EffectObj_SetOffsetXYZ(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->offset.x = x;
    obj->offset.y = y;
    obj->offset.z = z;
}

void EffectObj_SetScaleAll(EffectObj *obj, s32 scale) {
    obj->SetScaleXYZ(scale, scale, scale);
}

void EffectObj_SetScaleXYZ(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

static inline void EffectGroup_Dtor(EffectGroup *g) {
    EffectObj *c;
    *(u32 **)g = EffectGroup_vtbl;
    for (c = g->child; c != NULL; c = c->child) {
        c->state = 4;
    }
    if (g->arcName[0] != 0) {
        ResMgr_ReleaseList(g->arc);
        g->arc = NULL;
        g->arcName[0] = 0;
    }
    *(u32 **)g = EffectObj_vtbl;
    EffectObj_Unregister(g);
}

EffectGroup *EffectGroup_DtorDelete(EffectGroup *g) {
    EffectGroup_Dtor(g);
    Heap_Free(g);
    return g;
}

EffectGroup *EffectGroup_Dtor_02066a9c(EffectGroup *g) {
    EffectGroup_Dtor(g);
    return g;
}

void EffectObj_SetRotXYZ(EffectObj *obj, u16 x, u16 y, u16 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void EffectObj_AddPosXYZ(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->pos.x += x;
    obj->pos.y += y;
    obj->pos.z += z;
}

void EffectObj_SetPosXYZ(EffectObj *obj, s32 x, s32 y, s32 z) {
    obj->pos.x = x;
    obj->pos.y = y;
    obj->pos.z = z;
}

static inline void Effect3D_Dtor(Effect3D *e) {
    *(u32 **)e = MainVt_0208c290_vtbl;
    Effect3D_Release(e);
    *(u32 **)e = EffectObj_vtbl;
    EffectObj_Unregister(e);
}

Effect3D *MainVt_0208c1e8_DtorDelete(Effect3D *e) {
    Effect3D_Dtor(e);
    Heap_Free(e);
    return e;
}

Effect3D *MainVt_0208c1e8_Dtor(Effect3D *e) {
    Effect3D_Dtor(e);
    return e;
}

Effect3D *MainVt_0208c290_DtorDelete(Effect3D *e) {
    Effect3D_Dtor(e);
    Heap_Free(e);
    return e;
}

Effect3D *MainVt_0208c290_Dtor(Effect3D *e) {
    Effect3D_Dtor(e);
    return e;
}

EffectObj *EffectObj_Dtor(EffectObj *obj) {
    *(u32 **)obj = EffectObj_vtbl;
    EffectObj_Unregister(obj);
    return obj;
}

static inline Effect3D *EffectHud_Create(const char *arc, const char *mdl, s32 id) {
    char buf[0x20];
    Effect3D *e = EffectHud3D_New();
    e->unk_20 = id;
    LangData_LocalizePath(buf, arc);
    STD_CopyString(e->arcName, buf);
    Effect_SetStr(e->mdlName, mdl);
    e->unk_c4 = 0;
    return e;
}

Effect3D *EffectHud_New2710(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c374;
    arc = data_0208c380;
    e = EffectHud_Create(arc, mdl, 0x2710);
    return e;
}

Effect3D *EffectHud_New2714(const VecFx32 *pos) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c38b;
    arc = data_0208c397;
    e = EffectHud_Create(arc, mdl, 0x2714);
    EffectObj_AddSndCue(e, 0x85, 2);
    e->SetPos(pos);
    return e;
}

Effect3D *EffectHud_New2711(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c3a1;
    arc = data_0208c3ad;
    e = EffectHud_Create(arc, mdl, 0x2711);
    EffectObj_AddSndCue(e, 0x27, 2);
    EffectObj_AddSndCue(e, 0x2c, 0x3c);
    return e;
}

Effect3D *EffectHud_New2712(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c3bb;
    arc = data_0208c3c7;
    e = EffectHud_Create(arc, mdl, 0x2712);
    EffectObj_AddSndCue(e, 0x2c, 2);
    return e;
}

Effect3D *EffectHud_New2713(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c3d6;
    arc = data_0208c3e2;
    e = EffectHud_Create(arc, mdl, 0x2713);
    EffectObj_AddSndCue(e, 0xd, 2);
    return e;
}

Effect3D *EffectHud_New2715(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c3f1;
    arc = data_0208c3fd;
    e = EffectHud_Create(arc, mdl, 0x2715);
    EffectObj_AddSndCue(e, 0x2c, 2);
    return e;
}

Effect3D *EffectHud_New2716(void) {
    const char *arc;
    const char *mdl;
    Effect3D *e;
    mdl = data_0208c40c;
    arc = data_0208c418;
    e = EffectHud_Create(arc, mdl, 0x2716);
    EffectObj_AddSndCue(e, 0x44, 2);
    return e;
}

}
