#ifndef MAIN_RES_STAGECMD_H
#define MAIN_RES_STAGECMD_H

#include "Main/Res/StageRes.h"
#include "Main/Sys/Field.h"

// Stage script commands: each takes the queued slot and returns 1 when done,
// or -0x63 while the field event queue is busy.

extern "C" {

typedef struct StageVec {
    s32 x;
    s32 y;
    s32 z;
} StageVec;

typedef struct StageColor {
    u8 r;
    u8 g;
    u8 b;
} StageColor;

typedef struct StageItemEntry {
    /* 0x0 */ u16 id;
    /* 0x2 */ union {
        u16 info;
        struct {
            u16 a : 3;
            u16 b : 3;
            u16 c : 2;
            u16 used : 1;
            u16 unk_9 : 7;
        } bits;
    };
} StageItemEntry;

#define STAGE_FLAGS_MAGIC 0x45564153 // 'SAVE'
#define STAGE_ITEM_ENTRY_MAX 37

typedef struct StageFlags {
    /* 0x000 */ u32 magic;
    /* 0x004 */ u32 frameCount;
    /* 0x008 */ u8 unk_008;
    /* 0x009 */ u8 unk_009;
    /* 0x00a */ u16 unk_00a;
    /* 0x00c */ u32 unk_00c;
    /* 0x010 */ u32 unk_010;
    /* 0x014 */ u16 unk_014;
    /* 0x016 */ u16 unk_016;
    /* 0x018 */ union {
        u16 unk_018;
        struct {
            u16 unk_0 : 1;
            u16 mode : 2;
            u16 unk_3 : 4;
            u16 flag7 : 1;
            u16 unk_8 : 8;
        } bits18;
    };
    /* 0x01a */ u8 unk_01a;
    /* 0x01b */ u8 unk_01b;
    /* 0x01c */ u32 unk_01c;
    /* 0x020 */ u32 unk_020;
    /* 0x024 */ u16 unk_024;
    /* 0x026 */ u8 unk_026[2];
    /* 0x028 */ u16 itemTotal;
    /* 0x02a */ u8 items[100];
    /* 0x08e */ StageItemEntry entries[STAGE_ITEM_ENTRY_MAX];
    /* 0x122 */ u8 bits[8];
    /* 0x12a */ u16 shapeId;
    /* 0x12c */ u8 unk_12c[5];
    /* 0x131 */ StageColor color2;
    /* 0x134 */ StageColor color;
    /* 0x137 */ u8 unk_137;
    /* 0x138 */ u16 unk_138;
    /* 0x13a */ u8 unk_13a[2];
    /* 0x13c */ StageVec pos;
    /* 0x148 */ StageVec target;
    /* 0x154 */ u16 rotY;
    /* 0x156 */ u16 targetRotY;
    /* 0x158 */ u8 unk_158[0x518 - 0x158];
    /* 0x518 */ u32 unk_518_0 : 8;
    /* 0x518 */ u32 unk_518_8 : 8;
    /* 0x518 */ u32 unk_518_16 : 8;
    /* 0x518 */ u32 unk_518_24 : 4;
    /* 0x518 */ u32 unk_518_28 : 4;
    /* 0x51c */ u8 buf[0xf0];
    /* 0x60c */ u32 slots[2];
    /* 0x614 */ u32 unk_614;
    /* 0x618 */ u32 unk_618;
    /* 0x61c */ u16 unk_61c;
    /* 0x61e */ u8 unk_61e[2];
    /* 0x620 */ u32 unk_620;
    /* 0x624 */ u32 unk_624[5];
    /* 0x638 */ u8 unk_638;
    /* 0x639 */ u8 unk_639;
    /* 0x63a */ u8 unk_63a[2];
} StageFlags; // size 0x63c

extern StageFlags *data_0214a424;
extern void *data_02149ef8;
extern int (*const data_0208bf9c[])(StageResSlot *slot);
extern const u32 data_02082a28[];
extern BOOL func_0206f21c(u16 id, int a);
extern BOOL func_0206f5e4(u16 id, int a);
extern void func_ov000_02184ea4(FieldState *state, u16 id);
extern void func_ov000_02184bb0(FieldState *state, u16 a);
extern void func_ov000_02184d90(FieldState *state, u16 a);
extern void func_ov000_021762e4(u16 a, u16 b);
extern void func_ov000_0214e7ac(u16 a);
extern void func_ov000_02188d28(u8 *buf);
extern void func_ov000_02188ca0(u8 *buf, int a);
extern void func_ov000_021865f8(FieldState *state);
extern void func_ov000_02186bb0(FieldState *state);
extern void func_ov000_0218547c(FieldState *state, u16 a, void *res, u16 id);
extern void func_ov000_021854d4(FieldState *state, void *res, u16 id);
extern void func_ov000_02172264(FieldPlayer *player, u32 v, u16 id, void *res);

static inline BOOL Field_IsEventPending(FieldState *state) {
    return state->head != state->tail;
}

static inline void Field_PushEvent(FieldState *state, s32 ev, s32 arg) {
    state->queue[state->tail] = ev;
    state->queueArg[state->tail] = arg;
    state->tail++;
    if (state->tail >= 0x10) {
        state->tail = 0;
    }
}

static inline BOOL Field_HasEvent(s32 ev) {
    FieldState *state = data_ov000_021ccd54;
    s32 i;
    for (i = state->head; i != state->tail;) {
        if (state->queue[i] == ev) {
            return TRUE;
        }
        i++;
        if (i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL Field_IsBusy(void) {
    FieldState *state = data_ov000_021ccd54;
    return state->head != state->tail;
}

static inline BOOL Field_HasEventIn(FieldState *state, s32 ev) {
    s32 tail = state->tail;
    s32 i = state->head;
    while (i != tail) {
        if (state->queue[i] == ev) {
            return TRUE;
        }
        i++;
        if (i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}


typedef struct StageShape {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ s32 type;
    /* 0x0c */ u8 unk_0c[0xc];
    /* 0x18 */ StageVec size;
    /* 0x24 */ u8 unk_24[0xc];
} StageShape;

typedef struct StageArea {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s16 w;
    /* 0x08 */ s16 h;
    /* 0x0a */ s16 d;
} StageArea;


struct StagePlayer {
    /* 0x000 */ // vtable
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void unk_vf0c();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    /* 0x004 */ u8 unk_004[0x11];
    /* 0x015 */ u8 unk_015;
    /* 0x016 */ u8 unk_016[0x52];
    /* 0x068 */ s32 unk_68;
    /* 0x06c */ u8 unk_06c[4];
    /* 0x070 */ StageVec pos;
    /* 0x07c */ u16 rot[3];
    /* 0x082 */ u8 unk_082[0x75c - 0x82];
    /* 0x75c */ StageVec target;
    /* 0x768 */ u8 unk_768[4];
    /* 0x76c */ u16 targetRot[3];
    /* 0x772 */ StageColor color;
    /* 0x775 */ u8 unk_775[0xb08 - 0x775];
    /* 0xb08 */ s32 unk_b08;
    /* 0xb0c */ u8 unk_b0c[4];
    /* 0xb10 */ StageVec unk_b10;
    /* 0xb1c */ u16 unk_b1c;
    /* 0xb1e */ u16 unk_b1e;
    /* 0xb20 */ u8 unk_b20[8];
    /* 0xb28 */ union {
        u8 unk_b28;
        struct {
            u8 mode : 2;
            u8 flag2 : 1;
            u8 flag3 : 1;
            u8 unk_4 : 4;
        } bitsB28;
    };
    /* 0xb29 */ u8 unk_b29;
    /* 0xb2a */ union {
        u8 unk_b2a;
        struct {
            u8 flag0 : 1;
            u8 flag1 : 1;
            u8 unk_2 : 6;
        } bitsB2a;
    };
};

extern void func_ov000_021b1110(StagePlayer *player, int a);
extern StagePlayer *func_ov000_0219bf90(void);

extern void func_ov000_02172288(FieldPlayer *player, int a, u16 b);
extern BOOL func_ov000_021705a0(FieldActor *actor, int a);
extern void func_ov000_021722c4(FieldPlayer *player, int a, u16 b, u16 c, u16 d, u16 e);
extern void func_ov000_021705dc(FieldActor *actor, u16 a, u16 b);
extern void func_ov000_02172338(FieldPlayer *player, int a, u16 b, s32 c, u16 d);
extern BOOL func_ov000_021705ec(FieldActor *actor);
extern void func_ov000_0216da78(FieldActorState *st);
extern void *func_0204c0e8(void *msg, u16 id);
extern void func_ov000_02172390(FieldPlayer *player, u16 a, void *str);
extern void func_ov000_02186158(FieldState *state, u16 a);
extern void func_ov000_02186204(FieldState *state, u16 a);
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void *func_ov000_0218e6d0(void *mgr, u16 kind, u16 id);
extern void *func_ov000_0218bd9c(void *mgr, u16 id, u8 a);

static inline BOOL Field_IsPlayerActing(void) {
    FieldPlayer *player = data_ov000_021ccd30;
    if (player == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(player, 9)) {
        return TRUE;
    }
    if (func_ov000_0216f674(player, 10)) {
        return TRUE;
    }
    if (player->unk_11c == NULL) {
        return FALSE;
    }
    return func_ov000_021705a0(player->unk_11c, 0);
}

static inline void Actor_SetDir(FieldActor *actor, u16 a, u16 b) {
    if (actor != NULL) {
        func_ov000_021705dc(actor, a, b);
    }
}

static inline void Slot_Push(StageRes *res, u16 id, u16 a0) {
    StageResSlot *slot = Slot_Alloc();
    slot->res = res;
    slot->unk_04 = 0;
    slot->id = id;
    slot->args[0] = a0;
    slot->args[1] = 0;
    slot->args[2] = 0;
    slot->args[3] = 0;
    slot->args[4] = 0;
    slot->args[5] = 0;
}

static inline void *Stage_FindObj3D(u16 id) {
    u16 kind = id & 0xf000;
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e6d0(data_ov000_021ccd68, kind, id);
}

static inline void Stage_FindObj(u16 id, u16 b) {
    if (id == 0) {
        return;
    }
    data_02149efc.unk_14 = Stage_FindObj3D(id);
    data_02149efc.unk_04 = func_ov000_0218bd9c(data_ov000_021ccd64, id, b & 0xff);
}

struct StageObj3D {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Remove();
    /* 0x04 */ u8 unk_04[8];
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u8 unk_10[8];
    /* 0x18 */ s16 params[0x18];
    /* 0x48 */ void *unk_48;
    /* 0x4c */ u8 unk_4c[0x1c];
    /* 0x68 */ s32 unk_68;
    /* 0x6c */ u8 unk_6c[4];
    /* 0x70 */ StageVec pos;
    /* 0x7c */ u16 rot[3];
    /* 0x82 */ u8 unk_82[0x1a];
    /* 0x9c */ s32 unk_9c;
    /* 0xa0 */ s32 unk_a0;
    /* 0xa4 */ s32 unk_a4;
    /* 0xa8 */ s32 unk_a8;
};

typedef struct StageLightObj {
    /* 0x00 */ u8 unk_00[0x34];
    /* 0x34 */ s16 params[0x2a];
    /* 0x88 */ StageVec pos;
    /* 0x94 */ u16 rot[3];
} StageLightObj;

typedef struct StageLight {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ u8 state;
} StageLight;

extern void func_ov000_0218bc9c(void *mgr, void *obj, int a);
extern void *func_ov000_0218bddc(void *mgr, u16 id, u8 a);
extern StageObj3D *func_ov000_0218e750(void *mgr, u16 kind, u16 id, StageVec *pos, s32 r);
extern void func_ov000_0218b60c(void *obj, u8 *color, StageVec *pos, s16 *rot);
extern s32 FX_Div(s32 a, s32 b);
extern StageObj3D *func_ov000_0218e640(void *mgr, u16 idx);
extern StageLightObj *func_ov000_0218bd5c(void *mgr, u16 idx);
extern void func_ov000_02198d28(void *p, StageVec *pos, u16 rot);
extern void *func_ov000_0218e4cc(void *mgr, u16 kind);
extern void func_ov000_0218e044(void *p, u16 id, s32 m);
extern void func_ov000_0218d46c(StageObj3D *o, u16 id, s32 m);

static inline StageObj3D *Stage_FindObj3DByIdx(u16 idx) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, idx);
}

static inline StageObj3D *Stage_FindObj3DPtr(u16 id) {
    u16 kind = id & 0xf000;
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (StageObj3D *)func_ov000_0218e6d0(data_ov000_021ccd68, kind, id);
}

static inline void *Stage_FindLight1(u16 id, u16 b) {
    return func_ov000_0218bd9c(data_ov000_021ccd64, id, (u8)b);
}

static inline void *Stage_FindLight2(u16 id, u16 b) {
    return func_ov000_0218bddc(data_ov000_021ccd64, id, (u8)b);
}

typedef struct StageCamPoint {
    /* 0x00 */ StageVec pos;
    /* 0x0c */ u8 unk_0c[8];
    /* 0x14 */ s16 x;
    /* 0x16 */ s16 y;
    /* 0x18 */ s16 z;
    /* 0x1a */ u8 unk_1a[0xa];
} StageCamPoint;

typedef struct StageCamMgr {
    /* 0x00 */ u8 unk_00[9];
    /* 0x09 */ u8 cur;
    /* 0x0a */ u8 unk_0a;
    /* 0x0b */ u8 next;
    /* 0x0c */ u8 unk_0c[0xc];
    /* 0x18 */ StageCamPoint *points;
} StageCamMgr;

extern StageCamMgr *data_ov000_021ccd6c;
extern s32 data_02097d78[5];
// Camera request block inside the field state (data_ov000_021ccd54).
typedef struct StageAng {
    u16 x;
    u16 y;
    u16 z;
} StageAng;

typedef struct StageCamCur {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ StageVec pos;
    /* 0x1c */ u8 unk_1c[0x26];
    /* 0x42 */ StageAng ang;
} StageCamCur;

typedef struct StageCamView {
    /* 0x00 */ u8 unk_00[0xd4];
    /* 0xd4 */ u32 active;
    /* 0xd8 */ StageVec pos;
    /* 0xe4 */ StageAng ang;
    /* 0xea */ u8 unk_ea[2];
    /* 0xec */ s32 dist;
    /* 0xf0 */ u16 unk_f0;
    /* 0xf2 */ u8 unk_f2[2];
    /* 0xf4 */ StageCamCur cur;
} StageCamView;

static inline BOOL StageCam_IsActive(void) {
    StageCamView *cam = (StageCamView *)data_ov000_021ccd54;
    return cam->active != 0;
}

extern int func_0205f5c4(StageRes *res, u16 id, u16 idx, u16 posIdx, u16 mode);
extern void VEC_Add(const StageVec *a, const StageVec *b, StageVec *out);
extern void func_ov000_021b12c0(StagePlayer *player, int a);
extern void func_ov000_021b1514(StagePlayer *player);
extern void func_ov000_021b13cc(StagePlayer *player, int a);
extern void func_ov000_021b14e8(StagePlayer *player);
extern void func_ov000_021b1540(StagePlayer *player, int a, int b);
extern void func_ov000_021b1740(StagePlayer *player, int a);
extern void func_ov000_021b1814(StagePlayer *player, int a, int b);
extern void func_ov000_021b1a54(StagePlayer *player, int a);
extern void func_ov000_021b4774(StagePlayer *player);

static inline BOOL Stage_IsWirelessReady(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[0] == 4;
    }
    return r;
}

static inline u16 Stage_GetAngle(StageRes *res, u16 arg, u16 def) {
    u16 rot = def;
    if (arg != 0xffff) {
        if (arg & 0x8000) {
            rot = ((u16 *)(res->posEv->pos + (u16)(arg & ~0x8000) * 6))[1];
        } else if (arg != 0xffff) {
            rot = (u16)((s32)(((s64)FX_Div(arg << 12, 0x168000) * 0x10000000 + 0x800) >> 12) >> 12);
        }
    }
    return rot;
}

static inline u16 Stage_GetAngleOr0(StageRes *res, u16 arg) {
    if (arg == 0xffff) {
        return 0;
    }
    if (arg & 0x8000) {
        return ((u16 *)(res->posEv->pos + (u16)(arg & ~0x8000) * 6))[1];
    }
    if (arg == 0xffff) {
        return 0;
    }
    return (u16)((s32)(((s64)FX_Div(arg << 12, 0x168000) * 0x10000000 + 0x800) >> 12) >> 12);
}

static inline s32 Stage_EffectId(u16 a) {
    s32 m = 6;
    if (a != 10) {
        m = a + 0x21;
    }
    return m;
}

}

#endif
