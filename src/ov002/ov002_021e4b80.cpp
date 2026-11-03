#include "ov002/ov002.h"
#include "Main/Gfx/TexObj.h"
#include "ov000/ModelPart.h"
#include "types.h"

extern "C" {

// The TU's two .bss objects, reached through the 0x021f0f98 pool literal plus offsets. They are
// defined before the first function, which already reads them that way.
Ov002Obj021f07d4 *data_ov002_021f0f98;
Ov002Stage *gOv002Stage;

}

// ---- merged from ov002_021e4b80.cpp
namespace m_021e4b80 {
extern "C" {

void Ov002StrTable_Clear(Ov002StrTable *self) {
    self->src = NULL;
    self->count = 0;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->pairs != NULL) {
            Heap_FreeArray(self->pairs);
            self->pairs = NULL;
        }
        HEAP_POP(saved);
    }
}

char *Ov002StrTable_GetLabel(Ov002StrTable *self, u32 idx) {
    if (idx >= self->count || self->pairs == NULL) {
        return NULL;
    }
    return self->pairs[idx].label;
}

char *Ov002StrTable_GetDesc(Ov002StrTable *self, u32 idx) {
    if (idx >= self->count || self->pairs == NULL) {
        return NULL;
    }
    return self->pairs[idx].desc;
}

u32 func_ov002_021e4c30(int which) {
    u32 r = 0;
    switch (which) {
    case 0:
        r = gSysState->frameCount / 3600;
        break;
    case 1:
        r = gStageFlags->unk_00a;
        break;
    case 2:
        r = gStageFlags->unk_00c;
        break;
    case 3:
        r = gStageFlags->unk_61c;
        break;
    case 4:
        r = gStageFlags->unk_010;
        break;
    case 5:
        r = gStageFlags->unk_014;
        break;
    case 6:
        r = gStageFlags->unk_016;
        break;
    }
    return r;
}

void Ov002Obj_Init(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}

void Ov002Obj_Detach(Ov002Obj *self) {
    int i;
    Ov002Obj *owner = self->owner;
    if (owner != NULL) {
        for (i = 0; i < 8; i++) {
            if (owner->children[i] == self) {
                owner->children[i] = NULL;
                break;
            }
        }
        self->owner = NULL;
    }
    for (i = 0; i < 8; i++) {
        Ov002Obj *child = self->children[i];
        if (child != NULL) {
            child->owner = NULL;
        }
    }
}

void Ov002Obj_AddChild(Ov002Obj *self, Ov002Obj *item) {
    int i;
    for (i = 0; i < 8; i++) {
        if (self->children[i] == NULL) {
            self->children[i] = item;
            return;
        }
    }
}

}
}  // namespace m_021e4b80

// ---- merged from ov002_021e4dd4.cpp
namespace m_021e4dd4 {
extern "C" {

BOOL Ov002Obj_Run(Ov002Obj *self) {
    BOOL r = TRUE;
    switch (self->unk_0c) {
    case 0:
        if (!self->vfunc_0c()) {
            break;
        }
        self->unk_0c = 1;
    case 1:
        if (!self->vfunc_10()) {
            break;
        }
        self->unk_0c = 2;
    case 2:
        if (!self->vfunc_14()) {
            break;
        }
        self->unk_0c = 3;
    case 3: {
        u8 *g = (u8 *)gOv002Stage;
        s32 m;
        if (FIELD(g, 0x10, u8)) {
            break;
        }
        m = self->unk_08;
        if (m == 3) {
            m = 2;
        }
        if (m != FIELD(g, 0xc, s32)) {
            break;
        }
        if (self->vfunc_18()) {
            break;
        }
        self->unk_0c = 4;
    }
    case 4:
    default:
        self->unk_0c = 4;
        r = FALSE;
        break;
    }
    return r;
}

}
}  // namespace m_021e4dd4

// ---- merged from ov002_021e4ec0.cpp
namespace m_021e4ec0 {
extern "C" {

BOOL Ov002Obj_Prepare(void) {
    return TRUE;
}

BOOL Ov002Obj_Load(void) {
    return TRUE;
}

BOOL Ov002Obj_Setup(void) {
    return TRUE;
}

BOOL Ov002Obj_Update(void) {
    return FALSE;
}

void Ov002Obj_Draw(void) {
}

Ov002Obj *Ov002Obj_FindChildKind(Ov002Obj *self, s32 kind, s32 min) {
    s32 limit;
    Ov002Obj *best = NULL;
    limit = gOv002Stage->unk_d0;
    int i;
    for (i = 0; i < 8; i++) {
        Ov002Obj *item = self->children[i];
        if (item != NULL && kind == item->unk_04) {
            s32 v = item->unk_18;
            if (min + 1 <= v && v <= limit) {
                best = item;
                limit = v;
            }
        }
    }
    return best;
}

// NODEDESC callback of the model being drawn (Ov002Obj021f07d4_Draw): node 0 takes the transform of the
// model's kind 3 animation object and, with unk_1f0_1, faces the camera. self is the NNSG3dRS; its
// variable is reused for the joint result.
void func_ov002_021e4f48(void *self) {
    Ov002Obj021f07d4 *ctx;
    s32 v;
    if (((NNSG3dRS *)self)->flag & NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID) {
        v = ((NNSG3dRS *)self)->currentNodeDesc;
    } else {
        v = -1;
    }
    if (v != 0) {
        return;
    }
    ctx = data_ov002_021f0f98;
    if (ctx->unk_1ec != NULL) {
        func_ov002_021e4fac((NNSG3dRS *)self);
    }
    if (ctx->unk_1f0_1) {
        self = ((NNSG3dRS *)self)->pJntAnmResult;
        MI_Copy36B(NNS_G3dGlbGetInvV(), &((NNSG3dJntAnmResult *)self)->rot);
    }
}

}
}  // namespace m_021e4ec0

// ---- merged from ov002_021e4fac.cpp
namespace m_021e4fac {
extern "C" {

void MTX_Concat33(void *a, void *b, void *c);

void func_ov002_021e4fac(NNSG3dRS *rs) {
    Ov002Obj021f075c *o = data_ov002_021f0f98->unk_1ec;
    NNSG3dJntAnmResult *m = rs->pJntAnmResult;
    s32 a = o->jnt.trans.x;
    s32 b = o->jnt.trans.y;
    s32 c = o->jnt.trans.z;
    s32 sx = o->jnt.scale.x;
    s32 sy = o->jnt.scale.y;
    s32 sz = o->jnt.scale.z;
    if (m->flag & 1) {
        m->scale.x = 0x1000;
        m->scale.y = 0x1000;
        m->scale.z = 0x1000;
        m->flag &= ~1;
    }
    m->scale.x = FX_MUL(sx, m->scale.x);
    m->scale.y = FX_MUL(sy, m->scale.y);
    m->scale.z = FX_MUL(sz, m->scale.z);
    if (m->flag & 2) {
        MTX_Identity33_((&m->rot));
        m->flag &= ~2;
    }
    MTX_Concat33(&m->rot, &o->jnt.rot, &m->rot);
    if (m->flag & 4) {
        m->flag &= ~4;
    }
    m->trans.x = a;
    m->trans.y = b;
    m->trans.z = c;
}

}
}  // namespace m_021e4fac

// ---- merged from ov002_021e50a8.cpp
namespace m_021e50a8 {
extern "C" {

void Ov002Obj021f07d4_AddLink(Ov002Obj021f07d4 *self, Ov002ObjLink *src) {
    MIi_CpuCopy32(src, (u8 *)self + 0xc0 + self->linkCount * 0x1c, 0x1c);
    self->linkCount++;
}

}
}  // namespace m_021e50a8

// ---- merged from ov002_021e50d8.cpp
namespace m_021e50d8 {
extern "C" {
typedef struct Rec021e50d8 {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Rec021e50d8;

void func_ov002_021e50d8(Ov002Obj021f07d4 *self, s32 a, s32 b) {
    Rec021e50d8 rec;
    rec.id = 0;
    rec.a = a;
    rec.b = b;
    rec.c = 0;
    rec.d = 0;
    rec.e = 0;
    rec.f = 0;
    rec.g = 0;
    rec.id = (u8)self->unk_4c;
    MIi_CpuCopy32(&rec, (u8 *)self + 0xc0 + self->linkCount * 0x1c, 0x1c);
    self->linkCount++;
}
}
}  // namespace m_021e50d8

// ---- merged from ov002_021e5140.cpp
namespace m_021e5140 {
extern "C" {

typedef struct Ent021e5140 {
    s32 kind;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Ent021e5140;

typedef struct Self021e5140 {
    u8 pad[0xc0];
    Ent021e5140 ents[8];
} Self021e5140;

static inline void setv021e5140(Ov002Obj021f07d4 *self, s32 v) {
    self->unk_4c = v >> 12;
    self->unk_04 = 0;
    self->unk_20 = v;
}

void Ov002Obj021f07d4_Init(Ov002Obj021f07d4 *self) {
    s32 i;
    self->unk_04 = 0;
    self->unk_20 = -0xa66;
    self->unk_4c = self->unk_20 >> 12;
    self->res.arc = NULL;
    self->res.name = NULL;
    self->res.item = NULL;
    self->unk_5c = NULL;
    self->unk_60 = NULL;
    self->unk_64 = NULL;
    self->unk_bc = 0;
    for (i = 0; i < 8; i++) {
        u8 *e = (u8 *)self + i * 0x1c;
        FIELD(e, 0xc0, s32) = 0;
        FIELD(e, 0xc4, s32) = 0;
        FIELD(e, 0xc8, s32) = 0;
        FIELD(e, 0xcc, s32) = 0;
        FIELD(e, 0xd0, s32) = 0;
        FIELD(e, 0xd4, u8) = 0;
        FIELD(e, 0xd5, u8) = 0;
        FIELD(e, 0xd8, s32) = 0;
    }
    self->linkCount = 0;
    self->trans.x = 0;
    self->trans.y = 0;
    self->trans.z = 0;
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    MTX_Identity33_(&self->rot);
    self->unk_1e0 = NULL;
    self->unk_1e4 = NULL;
    self->unk_1e8 = NULL;
    self->unk_1ec = NULL;
    self->unk_1f0 = 0;
}

void Ov002Obj021f07d4_Release(Ov002Obj021f07d4 *self) {
    s32 i;
    if (self->unk_10 >= 0x28) {
        if (self->unk_5c != NULL) {
            Vram_FreeRes((void *)*self->unk_5c);
        }
        for (i = 0; i < self->linkCount; i++) {
            Ov002ObjLink *e = &self->links[i];
            if (e->res != NULL) {
                Vram_FreeRes((void *)*e->res);
            } else if (e->alt) {
                Vram_FreeRes((void *)*e->res2);
            }
        }
    }
    if (self->unk_14 != 0) {
        if (self->res.arc != NULL) {
            ResMgr_ReleaseArchive(self->res.arc, self->res.name, 4);
        } else {
            ResMgr_ReleaseByName(gResMgr, self->res.name, 4, 0);
        }
    }
    for (i = 0; i < self->linkCount; i++) {
        Ov002ObjLink *e = &self->links[i];
        if (e->loaded) {
            if (e->arc != NULL) {
                if (e->alt) {
                    ResMgr_ReleaseArchive(e->arc, e->name, 4);
                } else {
                    ResMgr_ReleaseArchive(e->arc, e->name, 5);
                }
            } else {
                ResMgr_ReleaseByName(gResMgr, e->name, 5, 0);
            }
        }
    }
}

}
}  // namespace m_021e5140

// ---- merged from ov002_021e5344.cpp
namespace m_021e5344 {
extern "C" {

BOOL Ov002Obj021f07d4_Prepare(void) {
    return TRUE;
}

}

extern "C" {
extern char data_ov002_021f0640[];
void *ResList_FindType4(void *a, void *b);
void *ResList_FindType5(void *a, void *b);
void *ResMgr_GetDataType4(void *a);
void ResMgr_GetDataType5(void *a);
void G3dRes_DropTexData(u32 a);
void *NNS_G3dGetResDataByName(void *a, char *name);
void NNSi_G3dModifyMatFlag(void *mdl, BOOL a, u32 flag);
void *STD_ConcatenateString(char *dst, const char *src);
BOOL G3dRes_SetupVram(const char *name, u32 res);
u32 Vram_GetTexTransferId(void);
BOOL NNS_G3dBindMdlTex(void *mdl, void *tex);
BOOL NNS_G3dBindMdlPltt(void *mdl, void *tex);

typedef struct Ent021e534c {
    s32 kind;
    void *arc;
    char *name;
    u32 task;
    u32 *res;
    u8 loaded;
    u8 alt;
    u32 *res2;
} Ent021e534c;

static inline NNSG3dResMdl *ov002_021e534c_getMdl(u8 *set, char *name) {
    u32 *e;
    if (set != NULL && (e = (u32 *)NNS_G3dGetResDataByName(set + 8, name)) != NULL) {
        return (NNSG3dResMdl *)(set + *e);
    }
    return NULL;
}

static inline void *ov002_021e534c_mdlName(Ov002Obj021f07d4 *self) {
    return self->res.item != NULL ? self->res.item : self->res.name;
}

static inline u32 *ov002_021e534c_res(Ent021e534c *e) {
    return e->alt ? e->res2 : e->res;
}

BOOL Ov002Obj021f07d4_Load(Ov002Obj021f07d4 *self) {
    BOOL done = FALSE;
    switch (self->unk_10) {
    case 0:
        if (self->res.arc != NULL) {
            ResMgr_LoadArchive(self->res.arc, self->res.name, 4, 0);
        } else {
            ResMgr_Load(self->res.name, 4, 0);
        }
        self->unk_14 = 1;
        self->unk_10 = 10;
    case 10: {
        void *res;
        if (self->res.arc != NULL) {
            if (!ResMgr_IsArchiveLoaded(self->res.arc, self->res.name, 4)) {
                break;
            }
            void *p = ResMgr_GetArchiveList(self->res.arc, self->res.name, 4);
            res = ResList_FindType4(p, self->res.name);
        } else {
            if (!ResMgr_IsLoaded(self->res.name, 4)) {
                break;
            }
            res = ResMgr_GetDataType4(self->res.name);
        }
        self->unk_5c = (u32 *)res;
        self->unk_10++;
    }
    case 11: {
        char name[16];
        char path[32];
        MI_CpuFill8(name, 0, sizeof(name));
        if (self->res.item != NULL) {
            STD_CopyLString(name, self->res.item, sizeof(name));
        } else {
            STD_CopyLString(name, self->res.name, sizeof(name));
        }
        self->unk_60 = ov002_021e534c_getMdl((u8 *)NNS_G3dGetMdlSet((NNSG3dResFileHeader *)*self->unk_5c), name);
        STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
        STD_ConcatenateString(path, (self->res.name));
        if (self->unk_5c != NULL) {
            G3dRes_SetupVram(path, *self->unk_5c);
        }
        self->unk_bc = Vram_GetTexTransferId();
        NNSi_G3dModifyMatFlag(self->unk_60, FALSE, 0x40);
        NNSi_G3dModifyMatFlag(self->unk_60, FALSE, 0x80);
        NNSi_G3dModifyMatFlag(self->unk_60, FALSE, 0x200);
        NNSi_G3dModifyMatFlag(self->unk_60, FALSE, 0x400);
        self->unk_10++;
    }
    case 12:
        if (Vram_IsTransferDone((unsigned int)self->unk_bc)) {
            self->unk_bc = 0;
            self->unk_10++;
        }
        break;
    case 13:
        G3dRes_DropTexData(*self->unk_5c);
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                ResMgr_LoadArchive(e->arc, e->name, 5, 0);
            } else {
                ResMgr_Load(e->name, 5, 0);
            }
            e->loaded = 1;
        }
        self->unk_10 = 20;
    case 20: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            BOOL r;
            if (e->arc != NULL) {
                r = ResMgr_IsArchiveLoaded(e->arc, e->name, 5);
            } else {
                r = ResMgr_IsLoaded(e->name, 5);
            }
            ok = (ok & r) ? TRUE : FALSE;
        }
        if (!ok) {
            break;
        }
        self->unk_10++;
    }
    case 21:
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->arc != NULL) {
                void *p = ResMgr_GetArchiveList(e->arc, e->name, 5);
                u32 *r = (u32 *)ResList_FindType5(p, e->name);
                if (r == NULL) {
                    ResMgr_ReleaseArchive(e->arc, e->name, 5);
                    ResMgr_LoadArchive(e->arc, e->name, 4, 0);
                    e->alt = 1;
                }
                e->res = r;
            } else {
                ResMgr_GetDataType5(e->name);
            }
        }
        self->unk_10++;
    case 22: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                ok = (ok & ResMgr_IsArchiveLoaded(e->arc, e->name, 4)) ? TRUE : FALSE;
            }
        }
        if (!ok) {
            break;
        }
        self->unk_10++;
    }
    case 23:
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->alt) {
                void *p = ResMgr_GetArchiveList(e->arc, e->name, 4);
                e->res2 = (u32 *)ResList_FindType4(p, e->name);
            }
        }
        self->unk_10 = 30;
    case 30:
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            char path[32];
            void *tex;
            path[0] = 0;
            STD_CopyLString(path, data_ov002_021f0640, sizeof(path));
            STD_ConcatenateString(path, e->name);
            tex = NNS_G3dGetTex((NNSG3dResFileHeader *)*ov002_021e534c_res(e));
            if (e->alt) {
                if (e->res2 != NULL) {
                    G3dRes_SetupVram(path, *e->res2);
                }
            } else {
                if (e->res != NULL) {
                    G3dRes_SetupVram(path, *e->res);
                }
            }
            NNS_G3dBindMdlTex(self->unk_60, tex);
            NNS_G3dBindMdlPltt(self->unk_60, tex);
            e->task = Vram_GetTexTransferId();
        }
        self->unk_10++;
    case 31: {
        BOOL ok = TRUE;
        for (s32 i = 0; i < self->linkCount; i++) {
            if (!Vram_IsTransferDone((unsigned int)((Ent021e534c *)((u8 *)self + 0xc0))[i].task)) {
                ok = FALSE;
                break;
            }
        }
        if (ok) {
            self->unk_10++;
        }
        break;
    }
    case 32:
        for (s32 i = 0; i < self->linkCount; i++) {
            Ent021e534c *e = &((Ent021e534c *)((u8 *)self + 0xc0))[i];
            if (e->task != 0) {
                G3dRes_DropTexData(*(e->alt ? e->res2 : e->res));
            }
            e->task = 0;
        }
        self->unk_10 = 0x28;
    case 0x28:
        done = TRUE;
        break;
    default:
        self->unk_10 = 0x28;
        break;
    }
    return done;
}
}
}  // namespace m_021e5344

// ---- merged from ov002_021e5974.cpp
namespace m_021e5974 {
extern "C" {

// Kinds of the scene objects in the `+0xdc` list (the `+0x4` word). 7 is the camera
// (Ov002Cam021f0828_Apply reads its position, target, up vector and angle).
typedef enum Ov002ObjKind {
    OV002_OBJ_CAMERA = 7,
    OV002_OBJ_CAMERA2 = 8
} Ov002ObjKind;

BOOL Ov002Obj021f07d4_Setup(Ov002Obj021f07d4 *self) {
    Ov002ObjKind kind;
    Ov002Obj *p;
    NNS_G3dRenderObjInit((NNSG3dRenderObj *)((u8 *)self + 0x68), self->unk_60);
    self->unk_64 = NNS_G3dGetTex((NNSG3dResFileHeader *)*self->unk_5c);
    if (self->unk_1f0_0) {
        kind = OV002_OBJ_CAMERA2;
    } else {
        kind = OV002_OBJ_CAMERA;
    }
    for (p = (gOv002Stage->head); p != NULL; p = (p->next)) {
        if (kind == p->unk_04) {
            s32 st = p->unk_08;
            switch (st) {
            case 1:
                self->unk_1e0 = (Ov002Cam021f0854 *)p;
                break;
            case 2:
                self->unk_1e4 = (Ov002Cam021f0854 *)p;
                break;
            default:
                self->unk_1e0 = (Ov002Cam021f0854 *)p;
                break;
            }
            p->unk_08 = st;
        }
    }
    return TRUE;
}

}
}  // namespace m_021e5974

// ---- merged from ov002_021e5a10.cpp
namespace m_021e5a10 {
extern "C" {

void func_ov002_021e5fe4(Ov002Obj021f075c *p);

BOOL Ov002Obj021f07d4_Update(Ov002Obj021f07d4 *self) {
    Ov002Obj021f075c *n;
    Ov002Obj021f075c *c;
    if (gOv002Stage->unk_d0 > self->unk_1c) {
        return FALSE;
    }
    n = NULL;
    c = self->unk_1e8;
    if (c == NULL) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 2, -1);
    } else if (c->done) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 2, c->unk_18);
    }
    if (n != NULL) {
        if (self->unk_1e8 != NULL) {
            Ov002Obj021f075c_RemoveAnims(self->unk_1e8);
        }
        func_ov002_021e5fe4(n);
        self->unk_1e8 = n;
    }
    n = NULL;
    c = self->unk_1ec;
    if (c == NULL) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, -1);
    } else if (c->done) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, c->unk_18);
    }
    if (n != NULL) {
        if (self->unk_1ec != NULL) {
            Ov002Obj021f075c_RemoveAnims(self->unk_1ec);
        }
        Ov002Obj021f075c_LoadAnim(n);
        self->unk_1ec = n;
    }
    return TRUE;
}

}
}  // namespace m_021e5a10

// ---- merged from ov002_021e5cf4.cpp
namespace m_021e5cf4 {
extern "C" {

void func_ov002_021e4f48(void *self);

static inline void ov002_021e5b08_Scale(VecFx32 *out, const VecFx32 *in, s32 s) {
    out->x = FX_MUL(in->x, s);
    out->y = FX_MUL(in->y, s);
    out->z = FX_MUL(in->z, s);
}

void Ov002Obj021f07d4_Draw(Ov002Obj021f07d4 *self) {
    VObj *o;
    if (gOv002Stage->unk_d0 <= self->unk_18) {
        return;
    }
    switch (gOv002Stage->unk_0c) {
    case 1:
        o = self->unk_1e0;
        break;
    case 2:
        o = self->unk_1e4;
        break;
    default:
        o = self->unk_1e0;
        break;
    }
    o->vfunc_20();
    if (self->unk_1f0_0) {
        VecFx32 v;
        ov002_021e5b08_Scale(&v, &self->scale, 0x64000);
        v.z = 0x1000;
        NNS_G3dGlbSetBaseScale(&v);
        ov002_021e5b08_Scale(&v, &self->trans, 0x64000);
        v.z = self->unk_20;
        NNS_G3dGlbSetBaseTrans(&v);
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
    } else {
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.flag &= ~0xa4;
        NNS_G3dGlbSetBaseTrans((VecFx32 *)((u8 *)self + 0x1a4));
        NNS_G3dGlbSetBaseScale((VecFx32 *)((u8 *)self + 0x1b0));
    }
    NNS_G3dGlbFlushVP();
    data_ov002_021f0f98 = self;
    NNS_G3dRenderObjSetCallBack(&self->renderObj, (NNSG3dSbcCallBackFunc)func_ov002_021e4f48, NULL, NNS_G3D_SBC_NODEDESC, NNS_G3D_SBC_CALLBACK_TIMING_B);
    NNS_G3dDraw((NNSG3dRenderObj *)((u8 *)self + 0x68));
    NNS_G3dRenderObjResetCallBack(&self->renderObj);
    data_ov002_021f0f98 = NULL;
}


void Ov002Cam021f0854_Apply(void) {
}

BOOL Ov002Obj021f07d4_IsLoaded(Ov002Obj021f07d4 *self) {
    return self->unk_0c >= 3;
}

void Ov002Obj021f075c_Init(Ov002Obj021f075c *self) {
    self->unk_04 = 2;
    self->unk_10 = 0;
    self->res.arc = NULL;
    self->res.name = NULL;
    self->res.item = NULL;
    self->unk_58 = -1;
    self->unk_5c = -1;
    self->unk_60 = NULL;
    self->unk_64 = NULL;
    self->unk_68 = NULL;
    self->unk_6c = NULL;
    self->unk_70 = NULL;
    self->unk_74 = NULL;
    self->unk_78 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
    self->unk_84 = 0;
    self->unk_88 = 0x1000;
    self->unk_8c = 0;
    MI_CpuFill8(&self->jnt, 0, 0x58);
    self->unk_e8 = 0;
}

void Ov002Obj021f075c_FreeAnims(Ov002Obj021f075c *self) {
    if (self->unk_64 != NULL) {
        Heap_FreeHi(self->unk_64);
        self->unk_64 = NULL;
    }
    if (self->unk_68 != NULL) {
        Heap_FreeHi(self->unk_68);
        self->unk_68 = NULL;
    }
    if (self->unk_6c != NULL) {
        Heap_FreeHi(self->unk_6c);
        self->unk_6c = NULL;
    }
    if (self->unk_70 != NULL) {
        Heap_FreeHi(self->unk_70);
        self->unk_70 = NULL;
    }
    if (self->unk_74 != NULL) {
        Heap_FreeHi(self->unk_74);
        self->unk_74 = NULL;
    }
    if (self->unk_14 != 0) {
        if (self->res.arc != NULL) {
            ResMgr_ReleaseArchive(self->res.arc, self->res.name, 6);
        } else {
            ResMgr_ReleaseByName(gResMgr, self->res.name, 6, 0);
        }
    }
}

BOOL Ov002Obj021f075c_Prepare(void) {
    return TRUE;
}

BOOL Ov002Obj021f075c_Load(Ov002Obj021f075c *self) {
    BOOL r = FALSE;
    switch (self->unk_10) {
    case 0:
        if (self->res.arc != NULL) {
            ResMgr_LoadArchive(self->res.arc, self->res.name, 6, 0);
        } else {
            ResMgr_Load(self->res.name, 6, 0);
        }
        self->unk_14 = 1;
        self->unk_10++;
        break;
    case 1:
        if (self->res.arc != NULL) {
            if (ResMgr_IsArchiveLoaded(self->res.arc, self->res.name, 6) == 0) {
                break;
            }
            {
                void *t = ResMgr_GetArchiveList(self->res.arc, self->res.name, 6);
                self->unk_60 = (void **)ResList_FindType6(t, self->res.name);
            }
        } else {
            if (ResMgr_IsLoaded(self->res.name, 6) == 0) {
                break;
            }
            self->unk_60 = (void **)ResMgr_GetDataType6(self->res.name);
        }
    case 10:
        self->unk_10 = -1;
        r = TRUE;
        break;
    }
    return r;
}

BOOL Ov002Obj021f075c_Setup(void) {
    return TRUE;
}

BOOL Ov002Obj021f075c_Update(Ov002Obj021f075c *self) {
    Bits8 *fl = &FIELD(self, 0xe8, Bits8);
    s32 lim = gOv002Stage->unk_d0;
    if (fl->b2) {
        return FALSE;
    }
    if (!fl->b0 || lim <= self->unk_18) {
        return TRUE;
    }
    if (!fl->b1) {
        BOOL t = FALSE;
        if (self->unk_8c >= 0 && self->unk_7c > self->unk_8c) {
            t = TRUE;
        }
        if (t) {
            self->done = 1;
        }
    }
    Ov002Obj021f075c_UpdateAnims(self);
    if (!self->done) {
        self->unk_7c += gOv002Stage->unk_d8;
    }
    return TRUE;
}

}
}  // namespace m_021e5cf4

// ---- merged from ov002_021e6290.cpp
namespace m_021e6290 {
extern "C" {
u32 NNS_G3dAnmObjCalcSizeRequired(void *a, void *b);
void NNS_G3dAnmObjInit(void *a, void *b, void *c, int d);
void NNS_G3dRenderObjAddAnmObj(void *a, void *b);

static inline void ov002_021e5fe4_Load(NNSG3dAnmObj **slot, void *set, char *name, void *mdl, void *tex, void *robj) {
    void *a = NNS_G3dGetAnmByName(set, (NNSG3dResName *)name);
    if (a != NULL) {
        *slot = (NNSG3dAnmObj *)Heap_AllocHi(NNS_G3dAnmObjCalcSizeRequired(a, mdl), 4);
        NNS_G3dAnmObjInit(*slot, a, mdl, (int)tex);
        NNS_G3dRenderObjAddAnmObj(robj, *slot);
    }
}

void func_ov002_021e5fe4(Ov002Obj021f075c *self) {
    char name[0x10];
    Ov002Obj021f07d4 *obj = (Ov002Obj021f07d4 *)self->owner;
    void *mdl = obj->unk_60;
    void *tex = obj->unk_64;
    MI_CpuFill8(name, 0, sizeof(name));
    if (self->res.item != NULL) {
        STD_CopyLString(name, self->res.item, sizeof(name));
    } else {
        STD_CopyLString(name, self->res.name, sizeof(name));
    }
    ov002_021e5fe4_Load(&self->unk_64, self->unk_60[0], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&self->unk_68, self->unk_60[1], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&self->unk_6c, self->unk_60[2], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&self->unk_70, self->unk_60[3], name, mdl, tex, (u8 *)obj + 0x68);
    ov002_021e5fe4_Load(&self->unk_74, self->unk_60[4], name, mdl, tex, (u8 *)obj + 0x68);
    Ov002Obj021f075c_UpdateAnims(self);
    func_ov002_021e6290(self);
}

void Ov002Obj021f075c_LoadAnim(Ov002Obj021f075c *self) {
    char name[0x10];
    void *anm;
    self->unk_04 = 3;
    MI_CpuFill8(name, 0, sizeof(name));
    if (self->res.item != NULL) {
        STD_CopyLString(name, self->res.item, sizeof(name));
    } else {
        STD_CopyLString(name, self->res.name, sizeof(name));
    }
    anm = NNS_G3dGetAnmByName(*self->unk_60, (NNSG3dResName *)name);
    self->unk_64 = (NNSG3dAnmObj *)Heap_AllocHi(0x100, 4);
    self->unk_64->resAnm = anm;
    self->unk_64->frame = 0;
    self->unk_64->ratio = 0x1000;
    self->unk_64->funcAnm = NNS_G3dFuncAnmJntNsBcaDefault;
    self->unk_64->next = NULL;
    self->unk_64->resTex = NULL;
    self->unk_64->priority = 0x7f;
    self->unk_64->numMapData = 0;
    Ov002Obj021f075c_UpdateAnims(self);
    func_ov002_021e6290(self);
}

void func_ov002_021e6290(Ov002Obj021f075c *self) {
    NNSG3dAnmObj *m;
    s32 cur;
    s32 lim;
    s32 t;
    if (self->unk_64 != NULL) {
        m = self->unk_64;
    } else if (self->unk_68 != NULL) {
        m = self->unk_68;
    } else if (self->unk_6c != NULL) {
        m = self->unk_6c;
    }
    t = self->unk_1c;
    lim = (((NNSG3dResAnmCommon *)m->resAnm)->numFrame << 12) - 0x1000;
    self->unk_80 = lim;
    cur = gOv002Stage->unk_d0;
    if (t < 0) {
        self->unk_8c = -1;
    } else if (self->unk_78 == 0) {
        self->unk_8c = t - self->unk_18;
    } else if (self->unk_78 == 1) {
        self->unk_8c = ((t - self->unk_18) / lim + 1) * lim;
    }
    {
        self->unk_7c = cur > self->unk_18 ? cur - self->unk_18 : 0;
    }
    self->started = 1;
}

void Ov002Obj021f075c_RemoveAnims(Ov002Obj021f075c *self) {
    u8 *o = ((u8 *)self->owner);
    if (self->unk_04 == 2) {
        if (self->unk_64 != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), self->unk_64);
        }
        if (self->unk_68 != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), self->unk_68);
        }
        if (self->unk_6c != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), self->unk_6c);
        }
        if (self->unk_70 != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), self->unk_70);
        }
        if (self->unk_74 != NULL) {
            NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)(o + 0x68), self->unk_74);
        }
    } else {
        self->stopped = 1;
    }
}

}
}  // namespace m_021e6290

// ---- merged from ov002_021e63f0.cpp
namespace m_021e63f0 {
/* The frame read sits in every arm of the mode switch; the arms are tail-merged
   into one block that loads 0x7c before the join loads the rate at 0x88. */
static inline s32 Ov002Anm_Frame(Ov002Obj021f075c *self) {
    switch (self->unk_84) {
    case 1:
        return self->unk_7c;
    case 0:
        return self->unk_7c;
    default:
        return self->unk_7c;
    }
}

extern "C" {

void Ov002Obj021f075c_UpdateAnmFrame(Ov002Obj021f075c *self, NNSG3dAnmObj *out);

extern void *NNS_G3dRS;

extern u32 NNS_G3dGetJointScale_FuncArray;

void MIi_CpuClearFast(int v, void *dst, u32 size);

typedef void (*Func0208b000)(void *a, void *b, int c);

void Ov002Obj021f075c_UpdateAnims(Ov002Obj021f075c *self) {
    u8 buf[0x188];
    u32 fl;
    if (self->unk_64 != NULL) {
        Ov002Obj021f075c_UpdateAnmFrame(self, self->unk_64);
    }
    if (self->unk_68 != NULL) {
        Ov002Obj021f075c_UpdateAnmFrame(self, self->unk_68);
    }
    if (self->unk_6c != NULL) {
        Ov002Obj021f075c_UpdateAnmFrame(self, self->unk_6c);
    }
    if (self->unk_70 != NULL) {
        Ov002Obj021f075c_UpdateAnmFrame(self, self->unk_70);
    }
    if (self->unk_74 != NULL) {
        Ov002Obj021f075c_UpdateAnmFrame(self, self->unk_74);
    }
    if (self->unk_64 == NULL) {
        return;
    }
    NNS_G3dRS = buf;
    MIi_CpuClearFast(0, buf, 0x188);
    FIELD(buf, 0xe8, u32) = NNS_G3dGetJointScale_FuncArray;
    ((Func0208b000)NNS_G3dFuncAnmJntNsBcaDefault)(&self->jnt, self->unk_64, 0);
    fl = self->jnt.flag;
    if (fl & 2) {
        MTX_Identity33_(&self->jnt.rot);
    }
    if (fl & 4) {
        self->jnt.trans.x = 0;
        self->jnt.trans.y = 0;
        self->jnt.trans.z = 0;
    }
    if (fl & 1) {
        self->jnt.scale.x = 0x1000;
        self->jnt.scale.y = 0x1000;
        self->jnt.scale.z = 0x1000;
    }
    NNS_G3dRS = NULL;
}

void Ov002Obj021f075c_UpdateAnmFrame(Ov002Obj021f075c *self, NNSG3dAnmObj *out) {
    s32 n = ((NNSG3dResAnmCommon *)out->resAnm)->numFrame << 12;
    s32 f;
    f = Ov002Anm_Frame(self);
    f = FX_MUL(f, self->unk_88);
    if (self->unk_78 == 0) {
        if (f >= n - 0x1000) {
            f = n - 0x1000;
        }
        out->frame = f;
    } else if (self->unk_78 == 1) {
        if (self->unk_7c >= self->unk_8c && self->unk_8c >= 0) {
            out->frame = n - 0x1000;
            return;
        }
        out->frame = f % n;
    }
}

}
}  // namespace m_021e63f0

// ---- merged from ov002_021e659c.cpp
namespace m_021e659c {
extern "C" {

BOOL Ov002Obj021f070c_Setup(Ov002Obj021f070c *self) {
    self->unk_6c = self->unk_18;
    return TRUE;
}

}
}  // namespace m_021e659c

// ---- merged from ov002_021e65ac.cpp
namespace m_021e65ac {
extern "C" {

void func_ov002_021e6784(Ov002Obj021f070c *self);

void Math_DirToAngles(void *out, VecFx32 *dir);

static inline BOOL ov002_inWindow(s32 t) {
    Ov002Stage *g = gOv002Stage;
    BOOL r = FALSE;
    if (t > g->unk_d4 && t <= g->unk_d0) {
        r = TRUE;
    }
    return r;
}

BOOL Ov002Obj021f070c_Update(Ov002Obj021f070c *self) {
    Ov002Stage *g = gOv002Stage;
    s32 now = g->unk_d0;
    s32 i;
    if (now > self->unk_1c) {
        return FALSE;
    }
    if (now < self->unk_18) {
        return TRUE;
    }
    if (self->unk_18 > g->unk_d4 && self->unk_18 <= now) {
        Ov002Obj021f075c_LoadAnim(self->unk_60);
    }
    if (self->unk_64 == 1) {
        while (ov002_inWindow(self->unk_6c)) {
            func_ov002_021e6784(self);
            self->unk_6c += self->unk_68;
        }
    } else if (ov002_inWindow(self->unk_18)) {
        func_ov002_021e6784(self);
    }
    for (i = 0; i < 4; i++) {
        EffectObj *o = Effect_Find_020657b0(gEffectMgr, ((u32 *)((u8 *)self + 0x50))[i]);
        if (o == NULL) {
            ((u32 *)((u8 *)self + 0x50))[i] = 0;
        } else {
            VecFx32 dir;
            VecFx32 scale;
            VecFx32 pos;
            s32 rot[2];
            Ov002Obj021f075c *m = self->unk_60;
            pos.x = m->jnt.trans.x;
            pos.y = m->jnt.trans.y;
            pos.z = m->jnt.trans.z;
            scale.x = m->jnt.scale.x;
            scale.y = m->jnt.scale.y;
            scale.z = m->jnt.scale.z;
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, &m->jnt.rot, &dir);
            Math_DirToAngles(rot, &dir);
            o->SetPos(&pos);
            o->SetScale(&scale);
            o->SetRot((const EffectRot *)rot); // rot is s32[2]: Rot16 would shrink the frame
        }
    }
    return TRUE;
}


void func_ov002_021e6784(Ov002Obj021f070c *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((u32 *)((u8 *)self + 0x50))[i] == 0) {
            VecFx32 zero;
            VecFx32 dir;
            VecFx32 scale;
            VecFx32 pos;
            s32 rot[2];
            EffectObj *o;
            Ov002Obj021f075c *m;
            s32 k;
            zero.x = 0;
            zero.y = 0;
            zero.z = 0;
            o = Effect_SpawnId(self->unk_4c, &zero);
            m = self->unk_60;
            pos.x = m->jnt.trans.x;
            pos.y = m->jnt.trans.y;
            pos.z = m->jnt.trans.z;
            scale.x = m->jnt.scale.x;
            scale.y = m->jnt.scale.y;
            scale.z = m->jnt.scale.z;
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            MTX_MultVec33(&dir, &m->jnt.rot, &dir);
            Math_DirToAngles(rot, &dir);
            o->SetPos(&pos);
            o->SetScale(&scale);
            o->SetRot((const EffectRot *)rot); // rot is s32[2]: Rot16 would shrink the frame
            o->SetParam(self->unk_08);
            o->unk_50 = 0xfb1e0000;
            o->unk_54 = 0;
            k = self->unk_64;
            if (k == -1) {
                o->loopCount = -1;
            } else if (k == -2) {
                o->loopCount = -2;
            }
            ((u32 *)((u8 *)self + 0x50))[i] = o->id;
            return;
        }
    }
}

}
}  // namespace m_021e65ac

// ---- merged from ov002_021e68d4.cpp
namespace m_021e68d4 {
extern "C" {

BOOL Ov002Obj021f06bc_Load(Ov002Obj021f06bc *self) {
    BOOL r = FALSE;
    switch (self->unk_10) {
    case 0:
        if (self->unk_4c[0] != 0 && self->unk_6c[0] != 0) {
            ResMgr_LoadArchive(self->unk_4c, self->unk_6c, 0, 0);
            self->unk_10++;
            self->unk_14 = 1;
        } else {
            self->unk_10 = -1;
            r = TRUE;
            break;
        }
    case 1:
        if (ResMgr_IsArchiveLoaded(self->unk_4c, self->unk_6c, 0) == 0) {
            break;
        }
        self->unk_10++;
    case 2: {
        void *t = ResMgr_FindNamedArcType0(self->unk_4c, self->unk_6c);
        if (t != NULL) {
            Ov002Snd021f0cf8_Load(&self->snd, t);
        }
        self->unk_10 = -1;
        break;
    }
    case -1:
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL Ov002Obj021f06bc_Setup(void) {
    return TRUE;
}

}
}  // namespace m_021e68d4

// ---- merged from ov002_021e69b0.cpp
namespace m_021e69b0 {
extern "C" {

BOOL Ov002Obj021f06bc_Update(Ov002Obj021f06bc *self) {
    s16 *p;
    s32 v;
    while ((p = self->snd.cur) != NULL && gOv002Stage->unk_d4 < (v = *p << 12) && v <= gOv002Stage->unk_d0) {
        SndQueue_Exec(gSndQueue.queue, (SndCmd *)p);
        Ov002Snd021f0cf8_Next(&self->snd);
    }
    return TRUE;
}

}
}  // namespace m_021e69b0

// ---- merged from ov002_021e6a14.cpp
namespace m_021e6a14 {
extern "C" {

void Ov002Obj021f07ac_Init(Ov002Obj021f07ac *self) {
    self->unk_04 = 5;
    self->unk_20 = -0x29;
    MI_CpuFill8(self->unk_4c, 0, 0x20);
    MI_CpuFill8(self->unk_6c, 0, 0x20);
    Ov002Msg021f0ce8_Init(&self->msg);
    self->unk_b4 = 0;
    self->unk_b8 = 0;
    self->unk_bc = 0;
    self->unk_c0 = NULL;
    MI_CpuFill8(self->unk_c4, 0, 0x80);
    self->unk_144 = self->unk_c4;
    self->unk_148 = 0xff;
    self->unk_150 = 6;
    self->unk_14c = NULL;
    self->unk_154 = 2;
    self->unk_158 = NULL;
    self->unk_15c = NULL;
}

BOOL Ov002Obj021f07ac_Load(Ov002Obj021f07ac *self) {
    BOOL r = FALSE;
    switch (self->unk_10) {
    case 0:
        if (self->unk_4c[0] != 0 && self->unk_6c[0] != 0) {
            ResMgr_LoadArchive(self->unk_4c, self->unk_6c, 0, 0);
            self->unk_14 = 1;
            self->unk_10++;
        } else {
            self->unk_10 = 2;
            r = TRUE;
            break;
        }
    case 1:
        if (ResMgr_IsArchiveLoaded(self->unk_4c, self->unk_6c, 0) == 0) {
            break;
        }
        self->unk_10++;
    case 2:
        r = TRUE;
        break;
    }
    return r;
}

BOOL Ov002Obj021f07ac_Setup(Ov002Obj021f07ac *self) {
    s8 **r;
    if (self->unk_14 != 0) {
        void *t = ResMgr_FindNamedArcType0(self->unk_4c, self->unk_6c);
        if (t == NULL) {
            self->unk_08 = 0;
        } else {
            Ov002Msg021f0ce8_Load(&self->msg, t);
            self->unk_08 = 2;
        }
    }
    switch (self->unk_08) {
    case 1:
        self->unk_150 = 5;
        self->unk_154 = 1;
        break;
    case 2:
        self->unk_150 = 6;
        self->unk_154 = 2;
        break;
    }
    gGfxMgr->unk_004 = self->unk_150;
    r = (s8 **)GfxMgr_GetFont(gGfxMgr);
    self->unk_158 = r;
    self->unk_15c = (Ov002GetChar)r[1];
    gOv002Stage->unk_128 = self->unk_08;
    return TRUE;
}

}
}  // namespace m_021e6a14

// ---- merged from ov002_021e6c0c.cpp
namespace m_021e6c0c {
extern "C" {

void Ov002Msg021f0ce8_Next(Ov002Msg021f0ce8 *p);

void Ov002Obj021f07ac_UpdateText(Ov002Obj021f07ac *self);

static inline bool isVisible021e6c0c(Ov002Obj021f07ac *self) {
    BOOL in = FALSE;
    s32 idx = self->unk_b8;
    if (idx >= 0 && idx < gOv002Stage->unk_d0) {
        in = TRUE;
    }
    return in;
}

BOOL Ov002Obj021f07ac_Update(Ov002Obj021f07ac *self) {
    if (self->msg.count != 0) {
        if (gOv002Stage->unk_d4 < self->msg.unk_10 << 12 && self->msg.unk_10 << 12 <= gOv002Stage->unk_d0) {
            BOOL has;
            char *s;
            self->unk_b4 = 0;
            self->unk_b8 = self->msg.unk_12 << 12;
            self->unk_bc = 0;
            self->unk_c0 = self->msg.text;
            self->unk_14c = self->msg.name;
            MI_CpuFill8(self->unk_c4, 0, 0x80);
            self->unk_144 = self->unk_c4;
            has = FALSE;
            s = self->msg.name;
            if (s != NULL && s[0] != 0) {
                has = TRUE;
            }
            if (!has) {
                self->unk_148 = 0xff;
            } else if ((s8)self->msg.unk_1c == 1) {
                self->unk_148 = 0;
            } else {
                self->unk_148 = 1;
            }
            Ov002Msg021f0ce8_Next(&self->msg);
        }
    }
    if (!isVisible021e6c0c(self)) {
        Ov002Obj021f07ac_UpdateText(self);
    }
    if (isVisible021e6c0c(self)) {
        self->unk_148 = 0xff;
    }
    gOv002Stage->unk_12c = self->unk_148;
    return TRUE;
}

}
}  // namespace m_021e6c0c

// ---- merged from ov002_021e6d4c.cpp
namespace m_021e6d4c {
extern "C" {

#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))
u8 LangData_GetLang(void);
void GfxMgr_PutString(void *mgr, void *arg);
int NNSi_G2dFontGetTextWidth(const void *pFont, int hSpace, const void *txt);

static inline BOOL Ov002_IsValidIdx(s32 idx) {
    BOOL r = FALSE;
    if (idx < 0) {
        return r;
    }
    if (idx < gOv002Stage->unk_d0) {
        r = TRUE;
    }
    return r;
}

static inline void Pos_Set(s16 *p, s16 x, s16 y) {
    p[0] = x;
    p[1] = y;
}

void Ov002Obj021f07ac_Draw(Ov002Obj021f07ac *self) {
    s16 x;
    s16 y;
    s16 pal;
    if (Ov002_IsValidIdx(self->unk_b8)) {
        return;
    }
    if (!LangData_GetLang()) {
        y = 0x9c;
        pal = 3;
        x = 10;
    } else {
        y = 0x99;
        pal = 1;
        x = 10;
    }
    gGfxMgr->unk_004 = self->unk_150;
    gGfxMgr->unk_008 = 0;
    Pos_Set((s16 *)((u8 *)gGfxMgr + 0xc), x, y);
    gGfxMgr->unk_010 = pal;
    GfxMgr_PutString(gGfxMgr, self->unk_c4);
    if (self->unk_148 == 0xff) {
        return;
    }
    {
        void *txt = self->unk_14c;
        void *font = GfxMgr_GetFont(gGfxMgr);
        s32 w = NNSi_G2dFontGetTextWidth(font, 0, txt);
        gGfxMgr->unk_004 = self->unk_154;
        gGfxMgr->unk_008 = 0;
        Pos_Set((s16 *)((u8 *)gGfxMgr + 0xc), (0x60 - w) >> 1, 0x8d);
        GfxMgr_PutString(gGfxMgr, self->unk_14c);
    }
}

}
}  // namespace m_021e6d4c

// ---- merged from ov002_021e6e40.cpp
namespace m_021e6e40 {
extern "C" {

void Ov002Obj021f07ac_AppendChar(Ov002Obj021f07ac *self, s32 ch);

static inline s32 classifyChar(s32 ch) {
    if (ch == 0) {
        return 1;
    }
    if (ch == 10) {
        return 4;
    }
    if (((int (*)(void))LangData_GetLang)() == 0) {
        if (ch == 0x8141) {
            return 2;
        }
        if (ch == 0x8142) {
            return 3;
        }
    } else {
        if (ch == 0xfeff) {
            return 5;
        }
    }
    return 0;
}

void Ov002Obj021f07ac_UpdateText(Ov002Obj021f07ac *self) {
    char *s = self->unk_c0;
    if (s == NULL || s[0] == 0) {
        return;
    }
    self->unk_b4 -= gOv002Stage->unk_d8;
    while (self->unk_b4 < 0 && self->unk_c0[0] != 0) {
        s32 ch = self->unk_15c(&self->unk_c0);
        switch (classifyChar(ch)) {
        case 0:
        case 1:
            break;
        case 2:
            if (((int (*)(void))LangData_GetLang)() == 0) {
                ch = 0x8140;
            }
            self->unk_b4 += self->unk_bc != 0 ? 0x5000 : 0;
            break;
        case 3:
            if (((int (*)(void))LangData_GetLang)() == 0) {
                ch = 0x8140;
            }
            self->unk_b4 += self->unk_bc != 0 ? 0xa000 : 0;
            break;
        case 4:
            Ov002Obj021f07ac_AppendChar(self, ch);
            ch = self->unk_15c(&self->unk_c0);
            break;
        case 5:
            ch = self->unk_15c(&self->unk_c0);
            break;
        }
        Ov002Obj021f07ac_AppendChar(self, ch);
        self->unk_b4 += self->unk_bc << 12;
    }
}

typedef u8 Buf80[0x80];

void Ov002Obj021f07ac_AppendChar(Ov002Obj021f07ac *self, s32 ch) {
    // unk_c4 + 0x7e, spelled so that the base address is formed before the offset is added
    if (self->unk_144 > (char *)FIELD(self, 0xc4, Buf80) + 0x7e) {
        return;
    }
    if (((int (*)(void))LangData_GetLang)() == 0) {
        if (ch == (ch & 0xff)) {
            *self->unk_144++ = ch;
            *self->unk_144 = 0;
        } else {
            *self->unk_144++ = ch >> 8;
            *self->unk_144++ = ch;
            *self->unk_144 = 0;
        }
    } else if (ch == (ch & 0x7f)) {
        *self->unk_144++ = ch;
        *self->unk_144 = 0;
    } else if (ch == (ch & 0x7ff)) {
        *self->unk_144++ = ((ch >> 6) & 0x1f) | 0xc0;
        *self->unk_144++ = (ch & 0x3f) | 0x80;
        *self->unk_144 = 0;
    } else {
        *self->unk_144++ = ((ch >> 12) & 0xf) | 0xe0;
        *self->unk_144++ = ((ch >> 6) & 0x3f) | 0x80;
        *self->unk_144++ = (ch & 0x3f) | 0x80;
        *self->unk_144 = 0;
    }
}

}
}  // namespace m_021e6e40

// ---- merged from ov002_021e7118.cpp
namespace m_021e7118 {
extern "C" {

BOOL Ov002Obj021f0784_Prepare(void) {
    return TRUE;
}

BOOL Ov002Obj021f0784_Setup(Ov002Obj021f0784 *self) {
    switch (self->unk_4c) {
    case 0:
        self->unk_54 = 0x1f;
        self->unk_58 = 0;
        break;
    case 1:
        self->unk_54 = 0;
        self->unk_58 = 0x1f;
        break;
    }
    return TRUE;
}

BOOL Ov002Obj021f0784_Update(Ov002Obj021f0784 *self) {
    Ov002Stage *ctx = gOv002Stage;
    s32 v = ctx->unk_d0;
    if (v <= self->unk_18) {
        return TRUE;
    }
    if (v > self->unk_1c) {
        return FALSE;
    }
    ctx->unk_138 = self->unk_50;
    return TRUE;
}

}
}  // namespace m_021e7118

// ---- merged from ov002_021e719c.cpp
namespace m_021e719c {
extern "C" {

s32 Interp_SinLerp(s32 t, s32 a, s32 b);

void NNS_G3dGlbFlushP(void);

void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);

void Gfx3D_DrawPrimScaled(int a, s32 b, s32 c, u16 d);

extern VecFx32 data_ov002_021ef104;

extern VecFx32 data_ov002_021ef0bc;

void Ov002Obj021f0784_Draw(Ov002Obj021f0784 *self) {
    s32 now = gOv002Stage->unk_d0;
    s32 a;
    if (now < self->unk_18) {
        return;
    }
    if (now - self->unk_18 >= self->unk_5c) {
        a = self->unk_58;
    } else {
        a = Interp_SinLerp(FX_Div(now - self->unk_18, self->unk_5c), self->unk_54 << 12, self->unk_58 << 12) >> 12;
    }
    {
        VecFx32 zero = {0, 0, 0};
        VecFx32 up = data_ov002_021ef104;
        VecFx32 at = data_ov002_021ef0bc;
        VecFx32 w;
        s32 t;
        u32 c;
        s32 t2;
        s32 t3;
        u8 *g2 = (u8 *)gOv002Stage;
        NNS_G3dGlb.camPos = zero;
        NNS_G3dGlb.camUp = up;
        NNS_G3dGlb.camTarget = at;
        MTX_LookAt(&zero, &up, &at, (MtxFx43 *)data_02092844);
        NNS_G3dGlb.flag &= ~0xe8;
        MIi_CpuCopyFast(g2 + 0xe4, data_02092800, 0x40);
        NNS_G3dGlb.flag &= ~0x50;
        NNS_G3dGlbFlushP();
        t = 2;
        NNS_G3dGeBufferOP_N(0x10, &t, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        NNS_G3dGeBufferOP_N(0x15, NULL, 0);
        c = 0x3f0000c0 | (a << 16);
        NNS_G3dGeBufferOP_N(0x29, &c, 1);
        w.z = self->unk_20;
        w.x = 0x80000;
        w.y = 0x60000;
        NNS_G3dGeBufferOP_N(0x1c, &w, 3);
        Gfx3D_DrawPrimScaled(0, 0x100000, 0xc0000, self->unk_50);
        t2 = 2;
        NNS_G3dGeBufferOP_N(0x10, &t2, 1);
        t3 = 1;
        NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    }
}

}
}  // namespace m_021e719c

// ---- merged from ov002_021e7390.cpp
namespace m_021e7390 {
extern "C" {

void VEC_Normalize(VecFx32 *src, VecFx32 *dst);
void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *ab);
void MTX_RotAxis33(void *m, VecFx32 *axis, s32 s, s32 c);
void MTX_PerspectiveW(s32 s, s32 c, s32 aspect, s32 n, s32 f, s32 scale, void *mtx);

typedef struct Mtx33_021e7390 {
    s32 m[3][3];
} Mtx33_021e7390;

static inline void ov002_Cross(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}

void Ov002Cam021f0828_Apply(Ov002Cam021f0828 *self) {
    Ov002Cam021f0828 *obj = (Ov002Cam021f0828 *)self->owner;
    if (obj != NULL && obj->unk_04 == 7) {
        VecFx32 pos;
        VecFx32 at;
        VecFx32 dir;
        VecFx32 axis;
        Mtx33_021e7390 m;
        VecFx32 up;
        u16 ang;
        pos = obj->eye;
        at = obj->at;
        up = obj->up;
        ang = obj->unk_b8 + 0x3e9;
        dir.x = at.x - pos.x;
        dir.y = at.y - pos.y;
        dir.z = at.z - pos.z;
        ov002_Cross(&dir, &up, &axis);
        VEC_Normalize(&axis, &axis);
        MTX_RotAxis33(&m, &axis, FX_SINCOS((ang >> 4) * 2), FX_SINCOS((ang >> 4) * 2 + 1));
        MTX_MultVec33(&dir, (MtxFx33 *)&m, &dir);
        VEC_Add(&dir, &pos, &at);
        self->at = at;
        self->eye = pos;
        self->up = up;
    }
    NNS_G3dGlb.camPos = self->eye;
    NNS_G3dGlb.camUp = self->up;
    NNS_G3dGlb.camTarget = self->at;
    MTX_LookAt((VecFx32 *)((u8 *)self + 0x50), (VecFx32 *)((u8 *)self + 0x68), (VecFx32 *)((u8 *)self + 0x5c), (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MTX_PerspectiveW(self->fovySin, self->fovyCos, ((s16)self->unk_be), self->unk_c0,
                     self->unk_c4, 0x1000, (u8 *)self + 0x74);
    MIi_CpuCopyFast((u8 *)self + 0x74, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
}

}
}  // namespace m_021e7390

// ---- merged from ov002_021e75f0.cpp
namespace m_021e75f0 {
extern "C" {

extern VecFx32 data_ov002_021ef0f8;

extern VecFx32 data_ov002_021ef0d4;

void VEC_Add(void *a, void *b, void *c);

BOOL Ov002Cam021f0828_Update(Ov002Cam021f0828 *self) {
    Ov002Obj021f075c *n;
    Ov002Obj021f075c *c;
    Ov002Obj021f075c *m;
    n = NULL;
    c = self->unk_c8;
    if (c == NULL) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, -1);
    } else if (c->done) {
        n = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, c->unk_18);
    }
    if (n != NULL) {
        if (self->unk_c8 != NULL) {
            Ov002Obj021f075c_RemoveAnims(self->unk_c8);
        }
        Ov002Obj021f075c_LoadAnim(n);
        self->unk_c8 = n;
    }
    m = self->unk_c8;
    if (m != NULL) {
        VecFx32 pos;
        VecFx32 a = data_ov002_021ef0f8;
        VecFx32 b = data_ov002_021ef0d4;
        pos.x = m->jnt.trans.x;
        pos.y = m->jnt.trans.y;
        pos.z = m->jnt.trans.z;
        MTX_MultVec33(&a, &m->jnt.rot, &a);
        VEC_Add(&pos, &a, &a);
        MTX_MultVec33(&b, &m->jnt.rot, &b);
        self->eye = pos;
        self->at = a;
        self->up = b;
    }
    return TRUE;
}

void Ov002Cam021f0828_SetFovy(Ov002Cam021f0828 *self, s32 deg) {
    s32 idx;
    self->unk_b8 = (u16)(((s64)deg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    self->unk_b4 = deg;
    idx = (u16)(self->unk_b8 >> 1);
    self->fovySin = FX_SINCOS_TABLE[(idx >> 4) * 2];
    self->fovyCos = FX_SINCOS_TABLE[(idx >> 4) * 2 + 1];
}

}
}  // namespace m_021e75f0

// ---- merged from ov002_021e779c.cpp
namespace m_021e779c {
extern "C" {

void Ov002Cam021f07fc_Apply(Ov002Cam021f07fc *self) {
    Ov002Cam021f07fc *o = (Ov002Cam021f07fc *)self->owner;
    NNSG3dGlb *g;
    if (o != NULL && o->unk_04 == 8) {
        s32 y = o->eye.y + 0x120000;
        s32 x = o->eye.x;
        VecFx32 *v = &self->eye;
        VecFx32 *w = &self->at;
        v->x = x;
        v->y = y;
        v->z = 0;
        w->x = x;
        w->y = y;
        w->z = -0x1000;
    }
    g = &NNS_G3dGlb;
    g->camPos = self->eye;
    g->camUp = self->up;
    g->camTarget = self->at;
    MTX_LookAt((VecFx32 *)((u8 *)self + 0x50), (VecFx32 *)((u8 *)self + 0x68), (VecFx32 *)((u8 *)self + 0x5c), (MtxFx43 *)data_02092844);
    g->flag &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0x74, data_02092800, 0x40);
    g->flag &= ~0x50;
}

BOOL Ov002Cam021f07fc_Setup(Ov002Cam021f07fc *self) {
    VecFx32 v = data_ov002_021ef110;
    s32 x;
    self->up = v;
    if (self->unk_08 == 1) {
        x = 0x90000;
    } else if (self->unk_08 == 2) {
        x = -0x90000;
    }
    self->eye.x = 0;
    self->eye.y = x;
    self->eye.z = 0;
    self->at.x = 0;
    self->at.y = x;
    self->at.z = -0x1000;
    return TRUE;
}

BOOL Ov002Cam021f07fc_Update(Ov002Cam021f07fc *self) {
    Ov002Obj021f075c *found = NULL;
    Ov002Obj021f075c *cur = self->unk_b4;
    if (cur == NULL) {
        found = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, -1);
    } else if (cur->done) {
        found = (Ov002Obj021f075c *)Ov002Obj_FindChildKind(self, 3, cur->unk_18);
    }
    if (found != NULL) {
        if (self->unk_b4 != NULL) {
            Ov002Obj021f075c_RemoveAnims(self->unk_b4);
        }
        Ov002Obj021f075c_LoadAnim(found);
        self->unk_b4 = found;
    }
    cur = self->unk_b4;
    if (cur != NULL) {
        s32 x = cur->jnt.trans.x;
        s32 y = cur->jnt.trans.y;
        VecFx32 *v = &self->eye;
        VecFx32 *w = &self->at;
        v->x = x * 100;
        v->y = y * 100;
        v->z = 0;
        w->x = x * 100;
        w->y = y * 100;
        w->z = -0x1000;
    }
    return TRUE;
}

BOOL Ov002Obj021f06e4_Setup(Ov002Obj021f06e4 *self) {
    self->unk_4c_6 = 0;
    return TRUE;
}

BOOL Ov002Obj021f06e4_Update(Ov002Obj021f06e4 *self) {
    Ov002Stage *ctx = gOv002Stage;
    BOOL r = TRUE;
    if (self->unk_18 > ctx->unk_d4 && self->unk_18 <= ctx->unk_d0) {
        Gfx3DState *g;
        func_0206e3a0(&self->unk_4c, self->unk_50);
        g = (Gfx3DState *)gGfxSys->unk_8b0;
        if (!self->unk_4c_2) {
            g->edgeMarking = 0;
            g->unk_000_5 = 1;
            *(vu16 *)0x04000060 &= 0xcfdf;
        }
        if (!self->unk_4c_3) {
            G3X_SetFog(0, (GXFogBlend)g->fogMode, (GXFogSlope)g->fogSlope, g->fogOffset);
            g->fog = 0;
        }
        Gfx3DState_Apply(g);
        r = FALSE;
    }
    return r;
}

BOOL Ov002Vt_021f0694_Update(Ov002Obj *self) {
    BOOL r = TRUE;
    if (gOv002Stage->unk_d0 >= self->unk_1c) {
        r = FALSE;
    }
    return r;
}

Oam021e7ab8 *func_ov002_021e7ab8(TexObj *obj, TexObjEntry *entry, Oam021e7ab8 *oam, u16 *count) {
    u16 n = *count;
    if (entry->index == 0) {
        u8 pal = obj->unk_070;
        int i;
        for (i = 0; i < n; i++) {
            oam[i].x -= 0x80;
            oam[i].y -= 0x60;
            oam[i].pal += pal;
        }
    }
    *count = n;
    return oam;
}

void Ov002Stage_Create(void) {
    Ov002Stage *p;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*&gOv002Stage);
        HEAP_POP(saved);
    }
    p = (Ov002Stage *)Heap_Alloc(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0674_vtbl;
        *(VFunc **)&p->file = Ov002Vt_021f0684_vtbl;
        Ov002StageFile_Init(&p->file);
        Gfx3DState_Init(&p->unk_14c);
        Ov002Stage_Init(p);
    }
    gOv002Stage = p;
}

void *Ov002Vt_021f0684_Dtor(Ov002StageFile *self) {
    *(VFunc **)self = Ov002Vt_021f0684_vtbl;
    Ov002StageFile_DtorBase(self);
    return self;
}

void Ov002Stage_Delete(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*&gOv002Stage);
    HEAP_POP(saved);
}

void *Ov002Vt_021f0674_DtorDelete(Ov002Stage *self) {
    *(VFunc **)self = Ov002Vt_021f0674_vtbl;
    Ov002Stage_Release(self);
    *(VFunc **)&self->file = Ov002Vt_021f0684_vtbl;
    Ov002StageFile_DtorBase(&self->file);
    Heap_Free(self);
    return self;
}

}
}  // namespace m_021e779c

// ---- merged from ov002_021e7cb4.cpp
namespace m_021e7cb4 {
extern "C" {

void MTX_OrthoW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

void Ov002Stage_Init(Ov002Stage *self) {
    self->state = 0;
    self->step = 0;
    self->unk_0c = 1;
    self->unk_10 = 1;
    self->unk_14 = -1;
    self->unk_18 = 0;
    self->unk_1a = 1;
    self->unk_1c = -1;
    self->unk_20 = NULL;
    MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
    self->unk_44 = NULL;
    MI_CpuFill8((u8 *)self + 0x48, 0, 0x20);
    self->unk_68 = NULL;
    self->unk_d0 = 0;
    self->unk_d4 = -1;
    self->unk_d8 = 0x1000;
    self->head = NULL;
    self->tail = NULL;
    MTX_OrthoW(0, 0xc0000, 0, 0x100000, 0, 0x20000, 0x400000, (u8 *)self + 0xe4);
    self->unk_124 = NULL;
    self->unk_128 = 0;
    self->unk_130 = 0;
    self->unk_134 = 0;
    self->unk_13c = 0;
    self->unk_140 = 0;
    self->unk_144 = 0;
    self->unk_148 = 0;
    self->unk_12c = 0xff;
    self->unk_138 = 0;
    MI_CpuFill8((u8 *)self + 0x14c, 0, 0x180);
}

void Ov002Stage_FreeObjs(Ov002Stage *self);


void GXx_SetMasterBrightness_(u32 reg, int v);

extern void *data_ov002_021f0104[];

void Ov002Stage_Release(Ov002Stage *self) {
    Ov002Stage_FreeObjs(self);
    if (self->unk_44 != NULL) {
        if (self->unk_20 != NULL) {
            ResMgr_ReleaseArchive((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
        } else {
            ResMgr_ReleaseByName(gResMgr, (char *)((u8 *)self + 0x48), 0, 0);
        }
    }
    ResMgr_ReleaseArchive(data_ov002_021f0104[1], data_ov002_021f0104[2], 2);
    SndQueue_StopSeqArcs(gSndQueue.queue);
    if (self->unk_148) {
        u8 *g = (u8 *)gGfxSys;
        MIi_CpuCopy32((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        Gfx3DState_Apply(g + 0x8b0);
        self->unk_148 = 0;
    }
    gGfxSys->nextState = 1;
    gEffectMgr->drawFilter = 0;
    gEffectMgr->useCamera = 0;
    GXx_SetMasterBrightness_(0x400006c, 0);
    GXx_SetMasterBrightness_(0x400106c, 0);
}

}
}  // namespace m_021e7cb4

// ---- merged from ov002_021e7ea8.cpp
namespace m_021e7ea8 {
extern "C" {

void GXx_SetMasterBrightness_(vu16 *reg, int v);
static inline void GX_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400006c, b); }
static inline void GXS_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400106c, b); }

int GfxSys_GetFadeLevel(int a);
void Gfx3DState_SetDefaults(void *p);
BOOL Ov002Stage_State1(Ov002Stage *self);
BOOL Ov002Stage_State2(Ov002Stage *self);
BOOL Ov002Stage_UpdateObjs(Ov002Stage *self);
void Ov002Stage_FreeObjs(Ov002Stage *self);

static inline void ov002_SetBright(int v) {
    GX_SetMasterBrightness(v);
    GXS_SetMasterBrightness(v);
}

static inline void G3X_EdgeMarking(BOOL e) {
    if (e) *(vu16 *)0x04000060 = (u16)((*(vu16 *)0x04000060 & ~0x3000) | 0x20);
    else *(vu16 *)0x04000060 &= ~(0x3000 | 0x20);
}
static inline void ov002_SetState(Ov002Stage *self, s32 st) {
    self->state = st;
    self->step = 0;
}

static inline s32 FxM7ea8(s32 a, s32 b) { return (s32)(((s64)a * b + 0x800) >> 12); }
BOOL Ov002Stage_Update(Ov002Stage *self) {
    BOOL ret = TRUE;
    Gfx3DState *gx;
    BOOL done;
    int mode;
    u8 *g;
    s32 b;
    self->unk_0c = gGfxSys->unk_a30_4 ? 1 : 2;
    switch (self->state) {
    case 0: {
        b = 0;
        switch (self->unk_130) {
        case 0:
            b = GfxSys_GetFadeLevel(0);
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        ov002_SetBright(b);
        GfxSys_StopFade(-1);
        self->unk_13c = b << 12;
        self->unk_140 = 0;
        self->unk_144 = 0;
        gx = (Gfx3DState *)gGfxSys->unk_8b0;
        MIi_CpuCopy32(gx, (u8 *)self + 0x14c, 0x180);
        Gfx3DState_SetDefaults(gx);
        gx->edgeMarking = 0;
        gx->unk_000_5 = 1;
        G3X_EdgeMarking(FALSE);
        gx->light.diffuse = 0x4a52;
        gx->light.ambient = 0x1084;
        gx->light.specular = 0x739c;
        gx->light.emission = 0;
        Gfx3DState_Apply(gx);
        self->unk_148 = 1;
        gGfxSys->nextState = 2;
        gEffectMgr->drawFilter = 1;
        gEffectMgr->useCamera = 1;
        ov002_SetState(self, 1);
        break;
    }
    case 1:
        if (!Ov002Stage_State1(self)) {
            break;
        }
        ov002_SetState(self, 2);
    case 2:
        if (!Ov002Stage_State2(self)) {
            break;
        }
        ov002_SetState(self, 3);
    case 3:
        Ov002Stage_UpdateObjs(self);
        if (self->unk_10 == 0) {
            ov002_SetState(self, 4);
        }
        break;
    case 4: {
        if (self->unk_144 < 0xa000) {
            {
                s32 t_0 = self->unk_144;
                b = (self->unk_13c + FxM7ea8(FX_Div(self->unk_140 - self->unk_13c, 0xa000), t_0)) >> 12;
                ov002_SetBright(b);
                self->unk_144 += 0x1000;
            }
        }
        if (Ov002Stage_UpdateObjs(self)) {
            break;
        }
        b = 0;
        switch (self->unk_134) {
        case 0:
            b = self->unk_138 > 0x4210 ? 0x10 : -0x10;
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        self->unk_13c = 0;
        self->unk_140 = b << 12;
        self->unk_144 = 0;
        ov002_SetState(self, 5);
    }
    case 5: {
        done = FALSE;
        if (self->unk_144 >= 0x14000) {
            mode = self->unk_140 > 0 ? 1 : 2;
            GfxSys_StartFadeOut(0x1000, mode, 0);
            done = TRUE;
            GfxSys_StartFadeOut(0x1000, mode, 1);
        } else {
            {
                s32 t_1 = self->unk_144;
                b = (self->unk_13c + FxM7ea8(FX_Div(self->unk_140 - self->unk_13c, 0x14000), t_1)) >> 12;
                ov002_SetBright(b);
                self->unk_144 += 0x1000;
            }
        }
        if (done) {
            Ov002Stage_FreeObjs(self);
            EffectMgr_FreeAll(gEffectMgr);
            gEffectMgr->drawFilter = 0;
            gGfxSys->nextState = 1;
            ov002_SetState(self, 6);
        }
        break;
    }
    case 6: {
        ov002_SetBright(0);
        g = (u8 *)gGfxSys;
        MIi_CpuCopy32((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        Gfx3DState_Apply(g + 0x8b0);
        self->unk_148 = 0;
        ov002_SetState(self, 7);
    }
    case 7:
        ret = FALSE;
        break;
    }
    return ret;
}

}
}  // namespace m_021e7ea8

// ---- merged from ov002_021e828c.cpp
namespace m_021e828c {
extern "C" {

extern void *data_ov002_021f0104[];
void *ResMgr_GetDataType0(void *a);
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

static inline BOOL ov002_ResReady(Ov002Stage *self) {
    BOOL r = FALSE;
    if (self->unk_20 != NULL) {
        if (ResMgr_IsArchiveLoaded((u8 *)self + 0x24, (u8 *)self + 0x48, 0)) {
            r = TRUE;
            self->unk_68 = (u8 **)(ResMgr_FindNamedArcType0((u8 *)self + 0x24, (u8 *)self + 0x48));
        }
    } else {
        if (ResMgr_IsLoaded((char *)((u8 *)self + 0x48), 0)) {
            r = TRUE;
            self->unk_68 = (u8 **)(ResMgr_GetDataType0((u8 *)self + 0x48));
        }
    }
    return r;
}

static inline void ov002_ResLoad(Ov002Stage *self) {
    if (self->unk_20 != NULL) {
        ResMgr_LoadArchive((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
    } else {
        ResMgr_Load((char *)((u8 *)self + 0x48), 0, 0);
    }
}

static inline void ov002_ResFree(Ov002Stage *self) {
    if (self->unk_20 != NULL) {
        ResMgr_ReleaseArchive((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
    } else {
        ResMgr_ReleaseByName(gResMgr, (char *)((u8 *)self + 0x48), 0, 0);
    }
}

BOOL Ov002Stage_State1(Ov002Stage *self) {
    BOOL r = FALSE;
    switch (self->step) {
    case 0:
        ResMgr_LoadArchive(data_ov002_021f0104[1], data_ov002_021f0104[2], 2, 0);
        if (self->unk_44 != NULL) {
            ov002_ResLoad(self);
            self->step = 10;
        } else {
            self->step = 0x28;
            break;
        }
    case 10:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (self->unk_68 != NULL) {
            self->step = 0x28;
            break;
        }
        ov002_ResFree(self);
        self->step = 0x14;
    case 0x14:
        if (self->unk_20 != NULL) {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, self->unk_44, 0, 1);
            ResMgr_LoadArchive((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, self->unk_44, 0, 1);
            ResMgr_Load((char *)((u8 *)self + 0x48), 0, 0);
        }
        self->step++;
    case 0x15:
        if (!ov002_ResReady(self)) {
            break;
        }
        if (self->unk_68 != NULL) {
            self->step = 0x28;
            break;
        }
        ov002_ResFree(self);
        self->step = 0x1e;
    case 0x1e: {
        char *n = self->unk_20;
        if (n != NULL) {
            MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
            STD_CopyLString((char *)((u8 *)self + 0x24), n, 0x20);
            STD_TSNPrintf((u8 *)self + 0x24, 0x20, data_ov002_021f0647, n, data_ov002_021f0104[0x520 / 4]);
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, self->unk_44, 0, 0);
            ResMgr_LoadArchive((u8 *)self + 0x24, (u8 *)self + 0x48, 0, 0);
        } else {
            func_ov002_021e9d7c((u8 *)self + 0x48, 0x20, self->unk_44, 0, 0);
            ResMgr_Load((char *)((u8 *)self + 0x48), 0, 0);
        }
        self->step++;
    }
    case 0x1f:
        if (!ov002_ResReady(self)) {
            break;
        }
        self->step = 0x28;
    case 0x28:
        if (!ResMgr_IsArchiveLoaded(data_ov002_021f0104[1], data_ov002_021f0104[2], 2)) {
            break;
        }
        self->step = 0x64;
    case 0x64:
    default:
        r = TRUE;
        break;
    }
    return r;
}

}
}  // namespace m_021e828c

// ---- merged from ov002_021e86a0.cpp
namespace m_021e86a0 {
extern "C" {

extern void *data_ov002_021f0104[];


void TexObj_SetOamFunc(void *a, int b, void *c, int d);


void func_0204a360(void *a, int b);

BOOL SndMgr_IsLoadDone(void *a);

void func_ov002_021eaf20(Ov002StageFile *self);

Oam021e7ab8 *func_ov002_021e7ab8(TexObj *obj, TexObjEntry *entry, Oam021e7ab8 *oam, u16 *count);

void Ov002StageFile_Open(Ov002StageFile *self, u8 *data, char *name, u8 c);

BOOL Ov002Stage_State2(Ov002Stage *self) {
    BOOL r = FALSE;
    switch (self->step) {
    case 0: {
        void **tbl;
        void *res;
        void *m = Heap_Alloc(0x160);
        if (m != NULL) {
            void *file = data_ov002_021f0104[1];
            void *name = data_ov002_021f0104[2];
            PlttRes_Init_02041218((PlttRes *)((u8 *)m + 0x88));
            TexObj_Init((Model *)m, (char *)name, 0);
            STD_CopyString((char *)((u8 *)m + 0x2c), (char *)file);
        }
        self->unk_124 = (struct Model *)m;
        tbl = data_ov002_021f0104;
        res = ResMgr_GetArchiveList(tbl[1], tbl[2], 2);
        TexObj_SetRes(self->unk_124, ResList_FindType2(res, tbl[2]));
        self->unk_124->flags |= 2;
        self->unk_124->unk_150 = -9;
        TexObj_SetOamFunc(self->unk_124, 0, func_ov002_021e7ab8, 0);
        TexObj_SelectImage(self->unk_124, 0, 0);
        self->unk_124->flags |= 0x80000;
        self->unk_124->flags |= 0x200000;
        self->unk_124->flags = (self->unk_124->flags & ~0x7c) | 0x78;
        func_0204aad0(gSndQueue.queue);
        if (self->unk_68 != NULL) {
            Ov002StageFile_Open(&self->file, *self->unk_68, self->unk_44, 1);
            func_ov002_021eaf20(&self->file);
        }
        func_0204a360(gSndMgr, -1);
        self->step = 10;
    }
    case 10:
        if (SndMgr_IsLoadDone(gSndMgr)) {
            self->step = 0x14;
        }
        break;
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL Ov002Obj_Run(Ov002Obj *n);

void Ov002Stage_RemoveObj(Ov002Stage *self, void *n);

void MI_Copy64B(void *src, void *dst);

typedef struct Blk24_8828 { s32 v[9]; } Blk24_8828;

static inline BOOL ov002_inRange8828(Ov002Stage *self) {
    BOOL r = FALSE;
    if (self->unk_14 >= 0 && self->unk_14 <= self->unk_d0) {
        r = TRUE;
    }
    return r;
}

BOOL Ov002Stage_UpdateObjs(Ov002Stage *self) {
    BOOL ret = TRUE;
    BOOL busy = FALSE;
    BOOL in;
    BOOL r;
    Ov002Obj *next;
    Ov002Obj *n;
    if (self->unk_1c != 0x5c && self->unk_1c != 0x1e) {
        if ((gPad->trig & 8) && self->unk_1a != 0) {
            ret = busy;
        }
    }
    for (n = (Ov002Obj *)(self->head); n != NULL; n = next) {
        next = (n->next);
        r = Ov002Obj_Run(n);
        if (n->unk_04 == 7 && self->unk_0c == n->unk_08) {
            {
                s32 *sv = (s32 *)((u8 *)n + 0x50);
                s32 a0 = sv[0], a1 = sv[1], a2 = sv[2], a3 = sv[3], a4 = sv[4], a5 = sv[5], a6 = sv[6], a7 = sv[7], a8 = sv[8];
                s32 *d = (s32 *)((u8 *)gEffectMgr + 0x38);
                d[0] = a0; d[1] = a1; d[2] = a2; d[3] = a3; d[4] = a4; d[5] = a5; d[6] = a6; d[7] = a7; d[8] = a8;
            }
            MI_Copy64B((u8 *)n + 0x74, (u8 *)gEffectMgr + 0x5c);
        }
        if (!r) {
            if (n->unk_04 == 9) {
                ret = FALSE;
            }
            Ov002Stage_RemoveObj(self, n);
            {
                void *saved;
                HEAP_PUSH(saved);
                if (n != NULL) {
                    if (n != NULL) {
                        (n)->vfunc_04();
                    }
                }
                HEAP_POP(saved);
            }
        } else if (!(n)->vfunc_08()) {
            busy = TRUE;
        }
    }
    in = ov002_inRange8828(self);
    if (in && (self->unk_18 & gPad->trig)) {
        Ov002Stage *ctx = gOv002Stage;
        ctx->unk_14 = -1;
        ctx->unk_18 = 0;
    }
    if (self->unk_0c == 2) {
        if (self->unk_10 == 0) {
            EffectObj *p;
            self->unk_d4 = self->unk_d0;
            self->unk_d0 = self->unk_d0 + self->unk_d8;
            EffectMgr_Update(gEffectMgr);
            for (p = (gEffectMgr->head); p != NULL; p = (p->drawNext)) {
                p->speed = self->unk_d8;
            }
            gEffectMgr->useCamera = 1;
        }
        { BOOL v = TRUE; if (!busy && !ov002_inRange8828(self)) v = FALSE; self->unk_10 = v; }
    }
    return ret;
}

}
}  // namespace m_021e86a0

// ---- merged from ov002_021e8aac.cpp
namespace m_021e8aac {
extern "C" {

void *Ov002Vt_021f0734_DtorDelete(Ov002Obj *self) {
    *(VFunc **)self = Ov002Vt_021f0734_vtbl;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

BOOL Ov002Obj_IsLoaded(Ov002Obj *self) {
    return self->unk_0c >= 3;
}

void Ov002Stage_Draw(Ov002Stage *self) {
    Ov002Obj *o;
    u32 mask;
    if (self->state != 4 && self->state != 5) {
        return;
    }
    mask = self->unk_0c;
    if ((self->unk_128 & mask) && self->unk_d0 > 0) {
        func_ov002_021e8cc4(self);
    }
    for (o = self->head; o != NULL; o = o->next) {
        if ((o->unk_08 & mask) && o->unk_0c == 3) {
            o->vfunc_1c();
        }
    }
}

void Ov002Stage_RemoveObj(Ov002Stage *self, Ov002Obj *item) {
    Ov002Obj *node = self->head;
    Ov002Obj *prev = NULL;
    if (node == item) {
        self->head = (item->next);
        return;
    }
    while (node != NULL) {
        if (node == item) {
            break;
        }
        prev = node;
        node = node->next;
    }
    if (node != NULL) {
        prev->next = node->next;
        node->next = NULL;
    }
}

void Ov002Stage_FreeObjs(Ov002Stage *self) {
    VObj *o = self->head;
    while (o != NULL) {
        VObj *next = ((Ov002Obj *)o)->next;
        void *saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->vfunc_04();
            }
        }
        HEAP_POP(saved);
        o = next;
    }
    self->head = NULL;
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            void *p = self->unk_124;
            if (p != NULL) {
                if (p != NULL) {
                    TexObj_Release((Model *)p);
                    PlttRes_Release((PlttRes *)((u8 *)p + 0x88));
                    Heap_Free(p);
                }
                self->unk_124 = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

}
}  // namespace m_021e8aac

// ---- merged from ov002_021e8cc4.cpp
namespace m_021e8cc4 {
extern "C" {

void NNS_G3dGlbFlushP(void);
void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);
void Gfx3D_DrawPrimScaled(int a, s32 b, s32 c, u16 d);
void func_02041c18(void *a, int b);
extern VecFx32 data_ov002_021ef104;
extern VecFx32 data_ov002_021ef0bc;

typedef struct Blk12 {
    s32 w[3];
} Blk12;

typedef struct Bits021e8cc4 {
    u32 lo : 7;
    u32 b7 : 6;
    u32 hi : 19;
} Bits021e8cc4;

void func_ov002_021e8cc4(Ov002Stage *self) {
    VecFx32 at;
    VecFx32 up = data_ov002_021ef104;
    VecFx32 zero = {0, 0, 0};
    VecFx32 w;
    s32 t;
    u32 c;
    s32 t2;
    s32 t3;
    *(Blk12 *)&at = *(Blk12 *)&data_ov002_021ef0bc;
    NNS_G3dGlb.camPos = zero;
    NNS_G3dGlb.camUp = up;
    NNS_G3dGlb.camTarget = at;
    MTX_LookAt(&zero, &up, &at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0xe4, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    NNS_G3dGlbFlushP();
    t = 2;
    NNS_G3dGeBufferOP_N(0x10, &t, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    w.x = 0;
    w.y = 0x93000;
    w.z = -0x29;
    NNS_G3dGeBufferOP_N(0x1c, &w, 3);
    c = 0x3e1e08c0;
    NNS_G3dGeBufferOP_N(0x29, &c, 1);
    Gfx3D_DrawPrimScaled(1, 0x100000, 0x2d000, 0);
    t2 = 2;
    NNS_G3dGeBufferOP_N(0x10, &t2, 1);
    t3 = 1;
    NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    if (self->unk_12c == 0xff) {
        return;
    }
    FIELD((self->unk_124), 0x6c, Bits021e8cc4).b7 = 0x3d;
    func_02041c18(self->unk_124, self->unk_12c);
    {
        Model *m = (self->unk_124);
        m->x = 0;
        m->y = 0x8a000;
    }
    Model_PlayPart(self->unk_124, 0);
}

}
}  // namespace m_021e8cc4

// ---- merged from ov002_021e8f04.cpp
namespace m_021e8f04 {
extern "C" {


extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

#define GAME ((u8 *)gOv002Stage)

void func_ov002_021e8f04(s32 idx) {
    Ov002Stage *p;
    void *name;
    Ov002Stage *g;
    u8 m;
    s32 v;
    float f;
    s32 off;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(*&gOv002Stage);
        HEAP_POP(saved);
    }
    p = (Ov002Stage *)Heap_Alloc(0x2cc);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0674_vtbl;
        *(VFunc **)&p->file = Ov002Vt_021f0684_vtbl;
        Ov002StageFile_Init(&p->file);
        Gfx3DState_Init(&p->unk_14c);
        Ov002Stage_Init(p);
    }
    off = idx * 0xc;
    GAME = (u8 *)p;
    p->unk_1c = idx;
    name = *(void **)(data_ov002_021f0878 + off);
    g = (Ov002Stage *)GAME;
    g->unk_20 = (char *)name;
    m = ((u8 (*)(void))LangData_GetLang)();
    MI_CpuFill8((u8 *)g + 0x24, 0, 0x20);
    STD_CopyLString((char *)((u8 *)g + 0x24), (char *)name, 0x20);
    STD_TSNPrintf((u8 *)g + 0x24, 0x20, data_ov002_021f0647, name, data_ov002_021f0624[m]);
    {
        void *desc;
        Ov002Stage *g2;
        g2 = (Ov002Stage *)GAME;
        desc = *(void **)(data_ov002_021f087c + off);
        g2->unk_44 = (char *)desc;
        func_ov002_021e9d7c((u8 *)g2 + 0x48, 0x20, desc, 0, ((u8 (*)(void))LangData_GetLang)());
    }
    v = *(s16 *)(data_ov002_021f0880 + off);
    if (v > 0) {
        f = (float)(v << 12) + 0.5f;
    } else {
        f = (float)(v << 12) - 0.5f;
    }
    v = (s32)f;
    {
        Ov002Stage *g3 = (Ov002Stage *)GAME;
        g3->unk_14 = v;
        g3->unk_18 = 1;
    }
}

}
}  // namespace m_021e8f04
#undef GAME

// ---- merged from ov002_021e90ac.cpp
namespace m_021e90ac {
extern "C" {

bool Ov002Stage_UpdateCur(void) {
    BOOL r;
    if (gOv002Stage == NULL) {
        r = FALSE;
    } else {
        r = Ov002Stage_Update(gOv002Stage);
    }
    return r;
}

void Ov002Stage_DrawCur(void) {
    Ov002Stage *self = gOv002Stage;
    Ov002Obj *o;
    u32 mask;
    if (self == NULL) {
        return;
    }
    if (self->state != 4 && self->state != 5) {
        return;
    }
    mask = self->unk_0c;
    if ((self->unk_128 & mask) && self->unk_d0 > 0) {
        func_ov002_021e8cc4(self);
    }
    for (o = self->head; o != NULL; o = o->next) {
        if ((o->unk_08 & mask) && o->unk_0c == 3) {
            o->vfunc_1c();
        }
    }
}

void Ov002Stage_Delete_021e916c(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(*&gOv002Stage);
    HEAP_POP(saved);
}

static inline void func_ov002_021e4cd8_inline5(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}
Ov002Obj *Ov002Obj021f07d4_New(s32 a, s32 b, s32 c, bool d, u8 e) {
    Ov002Obj021f07d4 *p = (Ov002Obj021f07d4 *)Heap_Alloc(0x1f4);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline5(p);
        *(VFunc **)p = Ov002Vt_021f07d4_vtbl;
        Ov002Obj021f07d4_Init(p);
    }
    p->unk_18 = a;
    p->unk_1c = b;
    p->unk_08 = c;
    p->unk_1f0_0 = e;
    p->unk_1f0_1 = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline2(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}
Ov002Obj *Ov002Obj021f075c_New(s32 a, s32 b, s32 c, s32 d, s32 e) {
    Ov002Obj021f075c *p = (Ov002Obj021f075c *)Heap_Alloc(0xec);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f075c_vtbl;
        Ov002Obj021f075c_Init(p);
    }
    p->unk_18 = a;
    p->unk_1c = b;
    p->unk_08 = c;
    p->unk_78 = d;
    p->unk_88 = e;
    return p;
}

}
}  // namespace m_021e90ac

// ---- merged from ov002_021e9380.cpp
namespace m_021e9380 {
extern "C" {

static inline void func_ov002_021e4cd8_inline2(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}

Ov002Obj *Ov002Obj021f070c_New(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Ov002Obj021f070c *p = (Ov002Obj021f070c *)Heap_Alloc(0x70);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f070c_vtbl;
        p->unk_4c = -1;
        MIi_CpuClear32(0, (u8 *)p + 0x50, 0x10);
        p->unk_68 = -1;
        p->unk_6c = -1;
    }
    p->unk_18 = a;
    p->unk_1c = b;
    p->unk_08 = c;
    p->unk_4c = d;
    p->unk_64 = e;
    p->unk_68 = e == 1 ? f : -1;
    return p;
}

extern VFunc Ov002Vt_021f0784_vtbl[];

Ov002Obj *Ov002Obj021f0784_New(s32 a, s32 b, s32 c, s32 d, u16 e, s32 mode, u8 f, u8 g) {
    Ov002Obj021f0784 *p = (Ov002Obj021f0784 *)Heap_Alloc(0x60);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f0784_vtbl;
        p->unk_04 = 6;
        p->unk_20 = -0x19a;
        p->unk_4c = 0;
        p->unk_50 = 0;
        p->unk_54 = 0;
        p->unk_58 = 0;
        p->unk_5c = 0;
    }
    p->unk_18 = a;
    p->unk_1c = b;
    p->unk_08 = d;
    switch (mode) {
    case 0:
        p->unk_4c = 0;
        break;
    case 1:
        p->unk_4c = 1;
        break;
    case 2:
        p->unk_4c = 2;
        p->unk_54 = f > 0x1f ? 0x1f : f;
        p->unk_58 = g > 0x1f ? 0x1f : g;
        break;
    }
    p->unk_5c = c;
    p->unk_50 = e;
    return p;
}

void *GfxCamPos_Init(void *p);

void MTX_Identity44_(void *p);

extern VFunc Ov002Vt_021f0854_vtbl[];

extern VFunc Ov002Vt_021f0828_vtbl[];

extern const VecFx32 data_ov002_021ef0e0;

extern const VecFx32 data_ov002_021ef0ec;

extern const VecFx32 data_ov002_021ef0c8;

Ov002Obj *Ov002Cam021f0828_New(Ov002Obj *a, Ov002Obj *b) {
    s32 i;
    Ov002Cam021f0828 *p = (Ov002Cam021f0828 *)Heap_Alloc(0xcc);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f0854_vtbl;
        GfxCamPos_Init((u8 *)p + 0x50);
        p->unk_04 = 7;
        p->unk_4c = -1;
        MTX_Identity44_((u8 *)p + 0x74);
        *(VFunc **)p = Ov002Vt_021f0828_vtbl;
        p->unk_04 = 7;
        {
            VecFx32 v = data_ov002_021ef0e0;
            p->eye = v;
        }
        {
            VecFx32 v = data_ov002_021ef0ec;
            p->up = v;
        }
        {
            VecFx32 v = data_ov002_021ef0c8;
            p->at = v;
        }
        p->unk_b8 = 0xaaa;
        p->unk_b4 = 0xeff1;
        p->fovySin = FX_SINCOS(0xaa);
        p->fovyCos = FX_SINCOS(0xab);
        p->unk_be = 0x1555;
        p->unk_c0 = 0x2000;
        p->unk_c4 = 0x7d0000;
        p->unk_c8 = NULL;
    }
    if (a != NULL) {
        p->owner = a;
        for (i = 0; i < 8; i++) {
            if (a->children[i] == NULL) {
                a->children[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (p->children[i] == NULL) {
                p->children[i] = b;
                break;
            }
        }
        b->owner = p;
    }
    p->unk_18 = 0;
    p->unk_1c = 0x7ffffffe;
    p->unk_08 = 1;
    return p;
}

void MTX_OrthoW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

extern VFunc Ov002Vt_021f07fc_vtbl[];

Ov002Obj *Ov002Cam021f07fc_New(Ov002Obj *a, Ov002Obj *b) {
    s32 i;
    Ov002Cam021f07fc *p = (Ov002Cam021f07fc *)Heap_Alloc(0xb8);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f0854_vtbl;
        GfxCamPos_Init((u8 *)p + 0x50);
        p->unk_04 = 7;
        p->unk_4c = -1;
        MTX_Identity44_((u8 *)p + 0x74);
        *(VFunc **)p = Ov002Vt_021f07fc_vtbl;
        p->unk_04 = 8;
        MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, (u8 *)p + 0x74);
        p->unk_b4 = NULL;
    }
    if (a != NULL) {
        p->owner = a;
        for (i = 0; i < 8; i++) {
            if (a->children[i] == NULL) {
                a->children[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (p->children[i] == NULL) {
                p->children[i] = b;
                break;
            }
        }
        b->owner = p;
    }
    p->unk_18 = 0;
    p->unk_1c = 0x7ffffffe;
    p->unk_08 = 1;
    return p;
}

}
}  // namespace m_021e9380

// ---- merged from ov002_021e9974.cpp
namespace m_021e9974 {
extern "C" {

static inline void func_ov002_021e4cd8_inline4(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}
Ov002Obj *Ov002Obj021f06e4_New(s32 a, s32 b, s16 c, void *d) {
    Ov002Obj021f06e4 *p = (Ov002Obj021f06e4 *)Heap_Alloc(0x54);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline4(p);
        *(VFunc **)p = Ov002Vt_021f06e4_vtbl;
        p->unk_04 = 10;
        p->unk_4c = 0;
        p->unk_50 = NULL;
    }
    p->unk_18 = a;
    p->unk_1c = b;
    p->unk_08 = 2;
    p->unk_4c = c;
    p->unk_50 = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline3(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}
Ov002Obj *Ov002Obj021f07ac_New(void *a, void *b) {
    Ov002Obj021f07ac *p = (Ov002Obj021f07ac *)Heap_Alloc(0x160);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline3(p);
        *(VFunc **)p = Ov002Vt_021f07ac_vtbl;
        Ov002Vt_021f0ce8_Ctor(&p->msg);
        Ov002Obj021f07ac_Init(p);
    }
    STD_CopyLString((char *)((u8 *)p + 0x4c), (char *)a, 0x20);
    STD_CopyLString((char *)((u8 *)p + 0x6c), (char *)b, 0x20);
    return p;
}

static inline void func_ov002_021e4cd8_inline(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}
Ov002Obj *Ov002Vt_021f0694_New(s32 end) {
    Ov002Obj *p = (Ov002Obj *)Heap_Alloc(0x4c);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline(p);
        *(VFunc **)p = Ov002Vt_021f0694_vtbl;
        p->unk_04 = 9;
    }
    p->unk_1c = end;
    return p;
}

}
}  // namespace m_021e9974

// ---- merged from ov002_021e9bd8.cpp
namespace m_021e9bd8 {
extern "C" {

static inline void func_ov002_021e4cd8_inline2(Ov002Obj *self) {
    Ov002Stage *ctx;
    self->unk_04 = -1;
    self->unk_08 = 1;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = -0x29;
    self->next = NULL;
    MIi_CpuClear32(0, self->children, 0x20);
    self->owner = NULL;
    ctx = gOv002Stage;
    if (ctx->tail == NULL) {
        ctx->head = self;
    } else {
        ctx->tail->next = self;
    }
    ctx->tail = self;
}

extern VFunc Ov002Vt_021f06bc_vtbl[];

void *Ov002Vt_021f0cf8_Ctor(Ov002Snd021f0cf8 *p);

void Ov002Snd021f0cf8_Init(Ov002Snd021f0cf8 *p);

Ov002Obj *Ov002Obj021f06bc_New(void *a, void *b) {
    Ov002Obj021f06bc *p = (Ov002Obj021f06bc *)Heap_Alloc(0xac);
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021f0734_vtbl;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = Ov002Vt_021f06bc_vtbl;
        Ov002Vt_021f0cf8_Ctor(&p->snd);
        p->unk_04 = 4;
        MI_CpuFill8((u8 *)p + 0x4c, 0, 0x20);
        MI_CpuFill8((u8 *)p + 0x6c, 0, 0x20);
        p->unk_8c = 0;
        p->unk_90 = 0;
        Ov002Snd021f0cf8_Init(&p->snd);
    }
    STD_CopyLString((char *)((u8 *)p + 0x4c), (char *)a, 0x20);
    STD_CopyLString((char *)((u8 *)p + 0x6c), (char *)b, 0x20);
    return p;
}

}
}  // namespace m_021e9bd8

// ---- merged from ov002_021e9cec.cpp
namespace m_021e9cec {
extern "C" {

void func_ov002_021e9cec(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *s;
    MI_CpuFill8(dst, 0, size);
    STD_CopyLString((char *)dst, (char *)src, size);
    switch (mode) {
    case 0:
        s = data_ov002_021f0624[idx];
        break;
    case 1:
        s = data_ov002_021f064c;
        break;
    case 2:
        s = data_ov002_021f0624[idx];
        break;
    default:
        s = data_ov002_021f064c;
        break;
    }
    STD_TSNPrintf(dst, size, data_ov002_021f0647, src, s);
}

void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx) {
    void *a;
    void *b;
    MI_CpuFill8(dst, 0, size);
    STD_CopyLString((char *)dst, (char *)src, size);
    switch (mode) {
    case 0:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f064d;
        break;
    case 1:
        b = data_ov002_021f0654;
        a = data_ov002_021f064c;
        break;
    case 2:
        a = data_ov002_021f0624[idx];
        b = data_ov002_021f065e;
        break;
    default:
        b = data_ov002_021f064c;
        a = b;
        break;
    }
    STD_TSNPrintf(dst, size, data_ov002_021f0665, src, a, b);
}

}
}  // namespace m_021e9cec

// ---- merged from ov002_021e9e40.cpp
namespace m_021e9e40 {
extern "C" {


extern u8 data_ov002_021f0878[];
extern u8 data_ov002_021f087c[];
extern u8 data_ov002_021f0880[];
void func_ov002_021e9d7c(void *dst, u32 size, void *src, int mode, u8 idx);

#define GAME ((u8 *)gOv002Stage)
void func_ov002_021e9e40(int idx) {
    void *name;
    Ov002Stage *g;
    u8 m;
    s32 v;
    float f;
    s32 off = idx * 0xc;
    gOv002Stage->unk_1c = idx;
    name = *(void **)(data_ov002_021f0878 + off);
    g = (Ov002Stage *)GAME;
    g->unk_20 = (char *)name;
    m = ((u8 (*)(void))LangData_GetLang)();
    MI_CpuFill8((u8 *)g + 0x24, 0, 0x20);
    STD_CopyLString((char *)((u8 *)g + 0x24), (char *)name, 0x20);
    STD_TSNPrintf((u8 *)g + 0x24, 0x20, data_ov002_021f0647, name, data_ov002_021f0624[m]);
    {
        void *desc;
        Ov002Stage *g2;
        g2 = (Ov002Stage *)GAME;
        desc = *(void **)(data_ov002_021f087c + off);
        g2->unk_44 = (char *)desc;
        func_ov002_021e9d7c((u8 *)g2 + 0x48, 0x20, desc, 0, ((u8 (*)(void))LangData_GetLang)());
    }
    v = *(s16 *)(data_ov002_021f0880 + off);
    if (v > 0) {
        f = (float)(v << 12) + 0.5f;
    } else {
        f = (float)(v << 12) - 0.5f;
    }
    v = (s32)f;
    {
        Ov002Stage *g3 = (Ov002Stage *)GAME;
        g3->unk_14 = v;
        g3->unk_18 = 1;
    }
}

}
}  // namespace m_021e9e40
#undef GAME
