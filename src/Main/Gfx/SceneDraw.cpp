#include "Main/Sys/GameScene.h"
#include "nitro/fx.h"

extern "C" {

typedef struct SceneObjPart {
    u8 unk_00[0x4c];
} SceneObjPart;

typedef struct SceneObj {
    /* 0x00 */ SceneObjPart parts[3];
    /* 0xe4 */ u8 unk_e4[0x64];
} SceneObj; // size 0x148

typedef struct SceneDrawData {
    /* 0x000 */ u8 unk_000[0x3d8];
    /* 0x3d8 */ SceneObjPart mainParts[3];
    /* 0x4bc */ u8 unk_4bc[0x44];
    /* 0x500 */ SceneObj objs[5];
} SceneDrawData;

typedef struct SceneG3dGlb {
    /* 0x00 */ u8 unk_00[0xfc];
    /* 0xfc */ u32 flag;
} SceneG3dGlb;

extern SceneG3dGlb NNS_G3dGlb;
extern MtxFx44 data_02092800;
extern MtxFx43 data_02092844;

extern void NNS_G3dGeFlushBuffer(void);
extern void MI_Copy64B(const void *src, void *dst);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void NNS_G3dGlbPolygonAttr(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);
extern void func_02053254(GameScene *scene, int a, void *obj, int b);

static inline void Scene_SetProjectionMtx(const MtxFx44 *mtx) {
    MIi_CpuCopyFast(mtx, &data_02092800, sizeof(MtxFx44));
    NNS_G3dGlb.flag &= ~0x50;
}

void func_02052fcc(GameScene *scene) {
    MtxFx44 proj;
    MtxFx43 cam;
    MtxFx43 *glbCam;
    MtxFx44 ortho;
    int j;
    int i;
    NNS_G3dGeFlushBuffer();
    MI_Copy64B(&data_02092800, &proj);
    MI_Copy48B(&data_02092844, &cam);
    MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, &ortho);
    Scene_SetProjectionMtx(&ortho);
    glbCam = &data_02092844;
    MTX_Identity43_(glbCam);
    data_02092844.m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    func_02053254(scene, 1, &((SceneDrawData *)scene)->mainParts[1], 1);
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 5; i++) {
            func_02053254(scene, j, &((SceneDrawData *)scene)->objs[i].parts[j], 1);
        }
    }
    NNS_G3dGeFlushBuffer();
    Scene_SetProjectionMtx(&proj);
    MI_Copy48B(&cam, glbCam);
}

void func_0205311c(GameScene *scene) {
    MtxFx44 proj;
    MtxFx43 cam;
    MtxFx44 ortho;
    MtxFx43 *glbCam;
    int i;
    NNS_G3dGeFlushBuffer();
    glbCam = &data_02092844;
    MI_Copy64B(&data_02092800, &proj);
    MI_Copy48B(glbCam, &cam);
    MTX_OrthoW(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, &ortho);
    Scene_SetProjectionMtx(&ortho);
    MTX_Identity43_(glbCam);
    glbCam->m[3][2] = 0;
    NNS_G3dGlbPolygonAttr(0, 0, 3, 0, 0, 0);
    func_02053254(scene, 2, &((SceneDrawData *)scene)->mainParts[2], 0);
    for (i = 0; i < 5; i++) {
        SceneObj *o = &((SceneDrawData *)scene)->objs[i];
        func_02053254(scene, 2, &o->parts[2], 1);
    }
    NNS_G3dGeFlushBuffer();
    Scene_SetProjectionMtx(&proj);
    MI_Copy48B(&cam, glbCam);
}


#ifdef NONMATCHING
// func_02053254: 75 raw / 16 register-masked (round rtG), honest base (no two-definition
// masks, no locals as parameters). `x += 0x8000` comes before the two `~0xfff` masks, so the
// tail has one extended block with the mask constant: with the masks first, `y & ~0xfff` is
// forwarded to its store past the `if`, the mask group gets 5 extended blocks and step 4 of
// move-constant-loads hoists the else arm's mask to the entry. The target still does the `x`
// mask before the predicated `addeq`, and colours `o` in `r6`.
// Round frD: 65 / 16. `dir` declared after `t` (tools/declsweep.py single move; it was second).
// Round qpE: 37 / 4. The position goes through a `VecFx32 pos` local (scalarised, no frame
// change) that is filled with the masked `x`/`y` and `z` first, then `pos.x += 0x8000`, then
// stored by `Obj3254Model_SetPosV(model, &pos)`. That gives the ROM's mask-before-`addeq` tail
// without the hoisted mask (the `pos.y` field is not forwarded past the `if`, so the mask
// group stays at 4 extended blocks). With `if (b == 0) dir = 1; scale = dir << 12;` after the
// `pos` stores the tail matches; `sz` before `sx` and `x` before `y` in the else arm, plus a
// declaration order from honest_search (no enum or named-local moves), give the rest. What is
// left is `o`: the ROM issues `add o` before the model `cmp` and colours `o` in `r6`; ours
// issues the `cmp` first (both tie at cycle 12 of the pre-allocation schedule; the `cmp` probably
// wins because it entered the ready list first), so `o` takes the dead model register `r2`.
// Round qpF: the tie is the pre-allocation class (`cmp` class 1 beats `add` class 2 at equal
// c0 h3), not list order. For the ROM order `add o` needs an in-block successor (a copy that
// survives to scheduling) or the `cmp` must not be ready; no honest spelling gave either.
typedef struct Obj3254Model {
    /* 0x00 */ u8 unk_00[0x78];
    /* 0x78 */ s32 x;
    /* 0x7c */ s32 y;
    /* 0x80 */ s32 z;
    /* 0x84 */ u8 unk_84[0x24];
    /* 0xa8 */ s32 scaleX;
    /* 0xac */ s32 scaleY;
    /* 0xb0 */ s32 scaleZ;
} Obj3254Model;

typedef struct Obj3254Part {
    /* 0x00 */ u8 unk_00[0x8];
    /* 0x08 */ u16 objIdx;
    /* 0x0a */ u16 type;
    /* 0x0c */ u8 unk_0c[0x10];
    /* 0x1c */ Obj3254Model *model;
    /* 0x20 */ s32 x;
    /* 0x24 */ s32 y;
    /* 0x28 */ u8 unk_28[0x10];
    /* 0x38 */ u16 rot[3];
    /* 0x3e */ u8 unk_3e[0xa];
    /* 0x48 */ s8 unk_48;
    /* 0x49 */ u8 unk_49[3];
} Obj3254Part;

typedef struct Obj3254Owner {
    /* 0x000 */ u8 unk_000[0xfc];
    /* 0x0fc */ s32 x;
    /* 0x100 */ s32 y;
} Obj3254Owner;

typedef struct Obj3254 {
    /* 0x00 */ u32 unk_00_0 : 22;
    /* 0x00 */ u32 flip : 1;
    /* 0x00 */ u32 unk_00_23 : 9;
    /* 0x04 */ u8 unk_04[0x4];
    /* 0x08 */ u16 mode;
    /* 0x0a */ u8 unk_0a[0x22];
    /* 0x2c */ Obj3254Owner *owner;
    /* 0x30 */ u8 unk_30[0x14];
    /* 0x44 */ Obj3254Part parts[3];
    /* 0x128 */ u8 unk_128[0x20];
} Obj3254; // size 0x148

typedef struct Draw3254 {
    /* 0x000 */ u8 unk_000[0x3d8];
    /* 0x3d8 */ Obj3254Part mainParts[3];
    /* 0x4bc */ Obj3254 objs[5];
    /* 0xb24 */ u8 unk_b24[0x14];
    /* 0xb38 */ s32 unk_b38;
    /* 0xb3c */ s32 unk_b3c;
    /* 0xb40 */ s32 unk_b40;
} Draw3254;

typedef struct Obj3254Type {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ u8 flip;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 x;
    /* 0x08 */ s16 y;
    /* 0x0a */ u8 unk_0a[0xa];
} Obj3254Type; // size 0x14

extern Obj3254Type data_0208bc80[];
extern s8 data_02149ef4;
extern void func_ov000_02190758(Obj3254Model *model, u16 *rot, int a);
extern void func_ov000_021903b4(Obj3254Model *model);

static inline void Obj3254Model_SetScale(Obj3254Model *m, s32 x, s32 y, s32 z) {
    m->scaleX = x;
    m->scaleY = y;
    m->scaleZ = z;
}

static inline void Obj3254Model_SetPosV(Obj3254Model *m, const VecFx32 *p) {
    m->x = p->x;
    m->y = p->y;
    m->z = p->z;
}

void func_02053254(GameScene *scene, int a, void *obj, int b) {
    s32 x;
    s32 dx;
    s32 dy;
    s32 y;
    s32 tx;
    Obj3254Type *t;
    s32 dir;
    s32 sy;
    s8 *off;
    s32 sz;
    Draw3254 *d;
    s8 buf[2];
    s32 sx;
    s32 v;
    s32 ty;
    s32 z;
    u16 type;
    Obj3254Part *part = (Obj3254Part *)obj;
    Obj3254 *o;
    s32 scale;
    VecFx32 pos;
    d = (Draw3254 *)scene;
    o = &d->objs[part->objIdx];
    if (part->model == NULL) {
        return;
    }
    if (a == 0 && d->objs[part->objIdx].owner == NULL) {
        return;
    }
    type = part->type;
    t = &data_0208bc80[type];
    dir = 1;
    if (type < 0xb) {
        off = NULL;
        tx = t->x;
        ty = t->y;
        if (o->mode == 0x1000) {
            buf[0] = 10;
            buf[1] = 10;
            off = buf;
        }
        x = (o->owner->x + part->x) & ~0xfff;
        y = (part->y - o->owner->y) & ~0xfff;
        dx = tx << 12;
        dy = ty << 12;
        if (off != NULL) {
            v = off[0];
            if (tx < 0) {
                v = -v;
            }
            dx += v << 12;
            v = off[1];
            if (ty < 0) {
                v = -v;
            }
            dy += v << 12;
        }
        if (o->mode == 0x1000) {
            if (o->flip) {
                if (t->flip) {
                    x -= dx;
                    dir = -1;
                } else {
                    x += dx;
                }
            } else {
                x += dx;
            }
        } else {
            if (o->flip) {
                x += dx;
            } else {
                if (t->flip) {
                    x -= dx;
                    dir = -1;
                } else {
                    x += dx;
                }
            }
        }
        y += dy;
        z = 0;
    } else {
        sy = d->unk_b3c & ~0xfff;
        sz = d->unk_b40 & ~0xfff;
        sx = (s32)(((s64)d->unk_b38 * 0x7000 + 0x800) >> 12) & ~0xfff;
        if (type >= 0xf) {
            if (o->mode == 0x1000) {
                if (o->flip == 1) {
                    dir = -1;
                }
            } else {
                if (o->flip == 0) {
                    dir = -1;
                }
            }
        }
        x = sy + (part->x & ~0xfff);
        y = (part->y & ~0xfff) + 0xa000 - sx - sz;
        if (type < 0xf) {
            z = -0xa2c;
        } else {
            z = -0xa7a;
        }
    }
    pos.x = x & ~0xfff;
    pos.y = y & ~0xfff;
    pos.z = z;
    if (b == 0) {
        dir = 1;
    }
    scale = dir << 12;
    if (scene->unk_b8_0 == 4 && part->objIdx == 1) {
        pos.x += 0x8000;
    }
    Obj3254Model_SetPosV(part->model, &pos);
    func_ov000_02190758(part->model, part->rot, 0);
    Obj3254Model_SetScale(part->model, scale, 0x1000, 0x1000);
    data_02149ef4 = part->unk_48;
    func_ov000_021903b4(part->model);
}
#endif

}
