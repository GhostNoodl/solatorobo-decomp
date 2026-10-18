#include "Main/Sys/GameScene.h"
#include "Main/Sys/Field.h"
#include "Main/Gfx/Gfx3D.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

static inline BOOL Gfx_IsFadeIdle2(int ch) {
    if (data_02097d78[3] == 0 && data_02097d78[ch] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Gfx_IsFadeDone(int ch) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[ch] == 4 ? TRUE : FALSE;
}

static inline void Model_ApplyPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *tex;
    if (res == NULL) {
        return;
    }
    part = idx >= model->numParts ? NULL : &model->parts[idx];
    if (part != NULL && part->res != NULL) {
        tex = part->res->tex;
    } else {
        tex = func_02023410(res->texRes, ***(u16 ***)((u8 *)func_02023390(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}





void func_02055ff0(GameScene *scene, s32 x, s32 y) {
    G3_Vec(0x1b, x << 12, y << 12, 0x1000);
    func_0202a260(data_0208b3d0[0], data_020828f8[0]);
}

void func_02056044(GameScene *scene, s32 x, s32 y, u32 color, u16 color2) {
    G3_Vec(0x1b, x << 12, y << 12, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x20, color);
    G3_Vtx(0x800, -0x800, 0);
    G3_VtxXY(-0x800, -0x800);
    G3_Cmd1(0x20, color2);
    G3_VtxXY(-0x800, 0x800);
    G3_VtxXY(0x800, 0x800);
    func_0202a3ec(0x41, NULL, 0);
}

static inline s32 GameScene_Sin(s32 t) {
    return FX_SinCosTable_[((t << 14) >> 16) * 2];
}

s32 func_02056148(GameScene *scene, SlidePanel *panel, SlidePanel *other) {
    s32 t = panel->unk_20;
    s32 r = 0;
    if (t == 0x1000) {
        if (panel->state != 1 && panel->state != 3) {
            if (other->state != 0 && other->state != 2) {
                return 0x1000;
            }
            return GameScene_Sin(other->unk_20);
        }
        return 0;
    } else {
        u32 state = panel->state;
        if (state == 0 || state == 2) {
            r = GameScene_Sin(t);
        } else if (state == 1 || state == 3) {
            if (panel == other) {
                r = 0x1000;
            } else if (other->state == 1 || other->state == 3) {
                r = 0x1000;
            } else {
                r = GameScene_Sin(0x1000 - t);
            }
        }
    }
    return r;
}

}
