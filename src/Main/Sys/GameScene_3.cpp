#include "Main/Sys/GameScene.h"
#include "Main/Sys/Field.h"
#include "Main/Gfx/Gfx3D.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern BOOL func_ov000_021700c4(void *p);

void func_02056c0c(u32 mode, ...) {
    NNS_G3dGeBufferOP_N(0x13, &mode, 1);
}

void func_02056c30(void) {
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
}

BOOL func_02056c48(void) {
    FieldPlayer *player = data_ov000_021ccd30;
    if (player == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(player, 6)) {
        return TRUE;
    }
    if (player->unk_11c == NULL) {
        return FALSE;
    }
    return func_ov000_021700c4(player->unk_11c);
}

u8 func_02056c94(u8 *p) {
    return p[2];
}

BOOL func_02056c9c(SlidePanel *panel) {
    if (panel->state == 0 || panel->state == 2) {
        return TRUE;
    }
    return FALSE;
}

void func_02056cb8(Model *model) {
    model->flags |= 0x200000;
}

void func_02056cc8(Model *model, u32 r, u32 g, u32 b) {
    model->color = r | (g << 5) | (b << 10);
}

void func_02056cdc(Model *model, int idx, s32 dx, s32 dy) {
    model->pos[idx].x += dx << 12;
    model->pos[idx].y += dy << 12;
}

void func_02056d04(Model *model) {
    model->flags &= ~0x80000;
}

void func_02056d14(Model *model) {
    model->flags |= 0x100000;
}

u8 func_02056d24(Model *model) {
    return (model->flags << 25) >> 27;
}

void func_02056d38(Model *model, u32 v) {
    model->flags = (model->flags & ~0x1f80) | ((v << 26) >> 19);
}

void func_02056d50(Model *model) {
    model->flags &= ~0x100000;
}

void func_02056d60(GameScene *scene, s32 x, s32 y) {
    G3_Vec(0x1b, x << 12, y << 12, 0x1000);
    G3_Cmd1(0x40, 2);
    G3_Vtx(0, 0x375, -0x9ba);
    G3_VtxXY(0x84, 0x1000);
    G3_VtxXY(0xf8, 0);
    G3_VtxXY(0xf9c, 0x1000);
    G3_VtxXY(0xf17, 0);
    G3_VtxXY(0x1000, 0xbac);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
