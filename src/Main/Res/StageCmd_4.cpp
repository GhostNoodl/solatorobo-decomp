#include "Main/Res/StageCmd.h"

extern "C" {

extern void func_0205b348(void);

extern void func_ov000_02183858(FieldState *state, u16 a);
extern void func_ov000_0218386c(FieldState *state, u16 a);
extern void func_ov000_02186dbc(FieldState *state);
extern void func_ov000_021723b4(FieldPlayer *player, u16 a);
extern void func_ov000_021723d8(FieldPlayer *player, u16 a);
extern void func_ov000_021723fc(FieldPlayer *player, u16 a, u16 b, u16 c);
extern void func_ov000_0217242c(FieldPlayer *player, int mode, u16 a);
extern void func_ov000_02185804(FieldState *state, u16 a);
extern void func_ov000_02185918(FieldState *state, u16 a);

extern void func_ov000_02182590(u8 *p);
extern void func_ov000_021836d0(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e);
extern void func_ov000_0218372c(FieldState *state, u16 a);
extern void func_ov000_021837c0(FieldState *state);
extern void func_ov000_021837f8(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f);

extern void *func_0206fef8(u32 id);
extern s32 func_ov000_0218c040(void *mgr, s32 max, StageVec *out, s32 kind, u16 id);

static inline s32 StageFx_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

typedef struct StageObjInfo {
    /* 0x00 */ u8 unk_00[0x16];
    /* 0x16 */ s16 height;
} StageObjInfo;

int func_0205cbf0(StageResSlot *slot) {
    StageVec list[0x20];
    StageVec pos;
    StageAng ang;
    StageRes *res;
    StageObj3D *o;
    StageLightObj *l;
    s32 dist;
    u16 id;
    u16 a;
    if (StageCam_IsActive() || Field_IsBusy()) {
        return -0x63;
    }
    id = slot->args[1];
    o = NULL;
    l = NULL;
    res = slot->res;
    if (id == 0) {
        o = Stage_FindObj3DByIdx(slot->args[3]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[3]);
    } else if (!(id & 0x8000)) {
        o = Stage_FindObj3DPtr(id);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[1], 0xff);
    }
    id = slot->args[1];
    if (id == 0x1000) {
        pos = ((StageCamView *)data_ov000_021ccd54)->cur.pos;
    } else if (id == 0) {
        if (o != NULL) {
            pos = o->pos;
        } else {
            return 1;
        }
    } else if (id & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(id & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    } else {
        StageObjInfo *info = (StageObjInfo *)func_0206fef8(id);
        s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x20, list, id >> 12, id);
        s32 hh = info->height << 4;
        s32 h;
        s32 i = 0;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        h = StageFx_Mul(hh, 0xaab);
        if (n != 0) {
            s32 inv;
            for (; i < n; i++) {
                VEC_Add(&pos, &list[i], &pos);
                pos.y += h;
            }
            inv = FX_Div(0x1000, n << 12);
            pos.x = StageFx_Mul(pos.x, inv);
            pos.y = StageFx_Mul(pos.y, inv);
            pos.z = StageFx_Mul(pos.z, inv);
        } else if (o != NULL) {
            pos = o->pos;
            pos.y += h;
        }
    }
    a = slot->args[2];
    if (!(a & 0x8000)) {
        dist = 0;
        ang.x = 0;
        ang.y = 0;
        ang.z = 0;
    } else {
        s16 *p;
        a &= 0x7fff;
        p = (s16 *)(res->posEv->pos + a * 6);
        ((s16 *)&ang)[0] = p[0];
        ((s16 *)&ang)[1] = p[1];
        ((s16 *)&ang)[2] = 0;
        dist = p[2] << 4;
    }
    if (!(slot->args[1] & 0x8000) && !(slot->args[2] & 0x8000)) {
        ang.x = 0;
        ang.y = 0;
        ang.z = 0;
        if (o != NULL) {
            ang = *(StageAng *)o->rot;
        } else if (l != NULL) {
            ang.y = l->rot[1];
        }
        ang.x += a;
        ang.y += 0x8000;
        dist += 0x8000;
    }
    {
        StageCamView *cam;
        s32 f = slot->args[4] != 0 ? (s16)slot->args[4] : 0x1000;
        cam = (StageCamView *)data_ov000_021ccd54;
        cam->active = slot->args[0];
        cam->pos = pos;
        cam->ang = ang;
        cam->dist = dist;
        cam->unk_f0 = f;
    }
    return 1;
}

int func_0205d000(StageResSlot *slot) {
    return func_0205cbf0(slot);
}

int func_0205d00c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_d4 = 0;
    return 1;
}

typedef struct FieldStateBits {
    /* 0x000 */ u8 unk_000[0x18c];
    /* 0x18c */ u8 unk_18c;
    /* 0x18d */ u8 unk_18d;
    /* 0x18e */ u8 unk_18e;
    /* 0x18f */ u8 unk_18f;
    /* 0x190 */ u8 flag0 : 1;
    /* 0x190 */ u8 flag1 : 1;
    /* 0x190 */ u8 flag2 : 1;
    /* 0x190 */ u8 flag3 : 1;
    /* 0x190 */ u8 flag4 : 1;
    /* 0x190 */ u8 unk_190_5 : 3;
} FieldStateBits;

int func_0205d044(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    FieldStateBits *b;
    u16 v;
    u16 a0;
    if (Field_HasEvent(10)) {
        return -0x63;
    }
    v = slot->args[1];
    a0 = slot->args[0];
    b = (FieldStateBits *)state;
    b->flag2 = 1;
    b->flag3 = 1;
    b->flag4 = 1;
    b->unk_18d = a0;
    b->unk_18e = v;
    b->unk_18f = v;
    if (slot->args[2] != 0) {
        b->unk_18c = 1;
    }
    return 1;
}

}
