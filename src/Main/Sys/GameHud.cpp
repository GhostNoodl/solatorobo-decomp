#include "Main/Sys/GameScene.h"
#include "Main/Sys/Field.h"
#include "Main/Gfx/Gfx3D.h"

// Field-scene HUD drawing (func_02056e74).

class GameHudObj {
public:
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void unk_vf0c();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void SetPos(s32 x, s32 y);
    virtual void unk_vf24();
    virtual void unk_vf28();
    virtual void unk_vf2c();
    virtual void unk_vf30();
    virtual void unk_vf34();
    virtual void unk_vf38();
    virtual void unk_vf3c();
    virtual void unk_vf40();
    virtual void unk_vf44();
    virtual void unk_vf48();
    virtual void unk_vf4c();
    virtual void unk_vf50();
    virtual void unk_vf54();
    virtual void unk_vf58();
    virtual void unk_vf5c();
    virtual void unk_vf60();
    virtual void unk_vf64();
    virtual void unk_vf68();
    virtual void unk_vf6c();
    virtual void unk_vf70();
    virtual void unk_vf74();
    virtual void unk_vf78();
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Draw();
    /* 0x04 */ u32 unk_04_0 : 2;
    /* 0x04 */ u32 visible : 1;
    /* 0x04 */ u32 unk_04_3 : 29;
    /* 0x08 */ u8 unk_08[0x68];
    /* 0x70 */ s32 unk_70;
};

struct GameHud {
    /* 0x000 */ u32 unk_0_0 : 1;
    /* 0x000 */ u32 flip : 1;
    /* 0x000 */ u32 unk_0_2 : 2;
    /* 0x000 */ u32 enabled : 1;
    /* 0x000 */ u32 unk_0_5 : 11;
    /* 0x000 */ u32 flip2 : 1;
    /* 0x000 */ u32 unk_0_17 : 15;
    /* 0x004 */ u16 unk_4;
    /* 0x006 */ u16 unk_6;
    /* 0x008 */ u8 unk_8[4];
    /* 0x00c */ s32 t;
    /* 0x010 */ u8 unk_10[0x344];
    /* 0x354 */ GameHudObj *obj;
    /* 0x358 */ s32 width;
    /* 0x35c */ u8 unk_35c[4];
    /* 0x360 */ s32 t2;
};

extern "C" {

extern void func_020435e8(GfxPltt *pltt, void *src, u32 size);
extern void func_02041c34(Model *model, int idx, void *cb, void *arg);
extern void *func_02050ebc(void);
extern BOOL func_ov000_021705a0(FieldActor *actor, int a);

static inline BOOL GameScene_IsPlayerActing(void) {
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

static inline void GameScene_SetModelPos(Model *model, s32 x, s32 y) {
    model->x = x << 12;
    model->y = y << 12;
}

static inline BOOL GameHudObj_IsVisible(GameHudObj *obj) {
    return obj->visible ? TRUE : FALSE;
}

void func_02056e74(GameScene *scene, GameHud *hud) {
    u16 col;
    s32 y;
    s32 base;
    s32 s;
    s32 x;
    s64 prod;
    GameHudObj *obj;
    GfxPltt *pltt;
    if (!hud->enabled) {
        return;
    }
    G3_Cmd1(0x13, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    G3_Cmd1(0x29, 0x1600d0 | (func_02043d84(data_02097d48->unk_8b0) << 24));
    G3_Cmd1(0x2a, 0x20000000);
    col = 0;
    y = 0x8c;
    if (*(s32 *)data_ov000_021ccd70->unk_08 != 2) {
        pltt = &data_02097d48->pltt;
        hud->unk_4 = 0xf;
        hud->unk_6 = 0x94;
        y <<= 12;
        base = 0xb;
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3_Vec(0x1c, 0x5000, y, 0);
        s = !hud->flip ? FX_SinCosTable_[((hud->t << 14) >> 16) * 2] : 0x1000 - FX_SinCosTable_[((hud->t << 14) >> 16) * 2];
        G3_Vec(0x1b, s, s, 0x1000);
        if (!GameScene_IsPlayerActing()) {
            if ((u8)(data_ov000_021ccd54->unk_0c9[1] + 2) <= 1) {
                col = 0xc63;
            }
        }
        func_020435e8(pltt, &col, 2);
        G3_Cmd1(0x20, col);
        scene->unk_vfb0(0xf7, 0x30);
        G3_Cmd1(0x12, 1);
    } else {
        hud->unk_4 = 0xf;
        hud->unk_6 = 0x98;
        y <<= 12;
        base = 6;
    }
    obj = hud->obj;
    if (obj == NULL) {
        return;
    }
    if (!GameHudObj_IsVisible(obj)) {
        return;
    }
    s = !hud->flip2 ? FX_SinCosTable_[((hud->t2 << 14) >> 16) * 2] : 0x1000 - FX_SinCosTable_[((hud->t2 << 14) >> 16) * 2];
    s = 0x1000 - s;
    // Rounded fixed-point product kept in a 64-bit accumulator: sign word of `s` comes first.
    prod = s;
    prod = prod * -0x80000 + 0x800;
    x = (s32)(prod >> 12);
    x >>= 12;
    s = (y >> 12) - base;
    func_02041c34(scene->model, 0, (void *)func_02050ebc, scene);
    GameScene_SetModelPos(scene->model, x, s - 0x60);
    scene->model->unk_150 = -0x97a;
    scene->model->flags |= 0x80000;
    scene->model->flags |= 0x200000;
    scene->model->flags = (scene->model->flags & ~0x7c) | 0x78;
    Model_ApplyPart(scene->model, 0);
    scene->model->flags &= ~0x80000;
    scene->model->flags &= ~0x200000;
    hud->obj->SetPos(x + 0x30 - (hud->width >> 1), s + 2);
    hud->obj->unk_70 = -0xcd;
    hud->obj->Draw();
}

}
