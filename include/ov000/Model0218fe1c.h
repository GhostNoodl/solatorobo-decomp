#ifndef OV000_MODEL0218FE1C_H
#define OV000_MODEL0218FE1C_H

#include "types.h"
#include "nitro/fx.h"

// Animated 3D model object built by Model0218fe1c_Init (ctor) / Model0218fe1c_FreeAnims (dtor), with its
// animation controllers (Model0218fe1c_GetAnimCtrl ...) and the animation event interpreter
// (AnimEvent_Exec). Shared by Model_0218fe1c, Model_02190a30, Model_0219badc, Robo_0219c8e0
// and AnimEvent_02191f18.

typedef struct {
    u8 revision;
    u8 num_entry;
    u16 size_dict;
    u16 unk_04;
    u16 ofs_entry;
} ResDict;

typedef struct {
    u16 size_unit;
    u16 size_data;
    u8 data[4];
} ResDictEntry;

typedef struct {
    u8 unk_00[0x8];
    ResDict dict;
} ResMdlSet;

typedef struct {
    u32 offset;
} ResDictMdlSetData;

typedef struct {
    s32 frame;
    s32 ratio;
    void *res;
    u8 unk_0c[0x74];
} AnmObj;

typedef struct {
    AnmObj *cur;
    AnmObj *prev;
    AnmObj obj_a;
    AnmObj obj_b;
    char name[0x8];
    u8 index;
    u8 playing : 1;
    u8 same : 1;
    u8 loop : 1;
    u8 paused : 1;
    u8 reverse : 1;
    u8 flags_5 : 3;
    s16 speed;
    s16 blend;
    u16 delay;
} AnimCtrl;

typedef struct {
    void *unk_00;
} ResHandle;

typedef struct {
    void *list[5];
} AnimList;

typedef struct {
    u8 unk_00[0xc];
    ResHandle *mdl_handle;
    char mdl_name[0x20];
    char mdl_ext[0x18];
    AnimList *anims;
} ResSet;

typedef struct {
    char name[0x8];
    s32 value;
} AnimEventEntry;

typedef struct {
    u16 count;
    u16 is_ptr;
    AnimEventEntry entries[1];
} AnimEventTable;

typedef struct {
    ResSet *res;
    void *mdl;
    void *tex;
    AnimCtrl *unk_0c;
    AnimCtrl *unk_10;
    AnimCtrl *unk_14;
    AnimCtrl *unk_18;
    AnimCtrl *unk_1c;
    ResSet *unk_20;
    union {
        u8 renderObj[0x54]; // NNSG3dRenderObj (NNS_G3dRenderObjInit / NNS_G3dDraw)
        struct {
            u8 unk_24[0x2c];
            void *renderUser; // renderObj.ptrUser (ov009 points it at the actor's own data)
        };
    };
    // base transform, set with NNS_G3dGlbSetBaseTrans / prmBaseRot / NNS_G3dGlbSetBaseScale when drawn
    VecFx32 trans;
    MtxFx33 rot;
    VecFx32 scale;
    u16 actor_id; // owner actor for animation events (0xffff: none)
    u16 color;  // material colour while blend != 0 (NNS_G3dGlbMaterialColorDiffAmb)
    u16 color2; // blended toward color by blend / blendMax
    u16 blend;  // blend frames left (counts down each update)
    u16 blendMax;
    u8 alpha; // polygon alpha, 0x1f opaque
    u8 bright; // diffuse brightness, 0x1f is full
    u8 unk_c0;
    u8 polyId; // NNS_G3dGlbPolygonAttr polygonID (0: 5)
    union {
        u16 unk_c2; // or-ed whole by some ov009 actors
        struct {
            u16 visible : 1; // drawn only when set
            u16 unk_c2_1 : 1;
            u16 invV : 1;  // billboard: rotate by the inverse view matrix
            u16 flipX : 1; // with invV: mirror the x scale
            u16 boxTest : 1; // draw only if the G3 box test of the model bounds passes
            u16 clearInit : 1; // clear the render object's init callback after drawing
            u16 unk_c2_6 : 1;
            u16 restoreMat : 1; // restore the material flags after a colour blend
            u16 flushVP : 1; // NNS_G3dGlbFlushVP instead of NNS_G3dGlbFlushP
            u16 cull : 2; // NNS_G3dGlbPolygonAttr cullMode
            u16 unk_c2_11 : 5;
        };
    };
    s16 anim_state;
    s16 unk_c6;
    s16 unk_c8;
    s16 unk_ca;
    s16 unk_cc;
    u16 unk_ce;
    AnimEventTable *evTable; // named animation event scripts
    s16 *evData; // the inline scripts after evTable's entries
    s16 *evScript; // script of the current animation (looked up by name in evTable)
    s16 *evCursor; // next event in evScript (frame number, then the command)
    void *evFunc; // AnimEventFunc that runs one event (AnimEvent_Exec)
    u32 unk_e4;
} Model0218fe1c;

typedef s16 *(*AnimEventFunc)(s16 *data, Model0218fe1c *model);

#endif
