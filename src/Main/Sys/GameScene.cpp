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

BOOL func_02055aa4(GameScene *scene) {
    u32 type;
    if (scene->fadeReq) {
        if (!Gfx_IsFadeIdle2(0)) {
            return !Gfx_IsFadeDone(0) ? TRUE : FALSE;
        }
        type = scene->fadeType;
        if (type == 0xff) {
            func_0203c9e8(0x3f, -1);
            func_0203cc58(scene->fadeFrames << 12, 2, -1);
        } else if (type == 0xfe) {
            func_0203c9e8(0x3f, 0);
            func_0203cc58(scene->fadeFrames << 12, 2, 0);
        } else if (type == 0xfd) {
            func_0203c9e8(0x3f, 0);
            func_0203cc58(scene->fadeFrames << 12, 1, 0);
        } else if (type == 0xfc) {
            func_0203c9e8(0x3f, -1);
            func_0203cc58(scene->fadeFrames << 12, 1, -1);
        }
        return TRUE;
    }
    return TRUE;
}

void func_02055bbc(GameScene *scene) {
    ShakeTable table;
    s32 t;
    if (scene->shake == 0) {
        return;
    }
    table = data_020829d0;
    t = FX_Div(scene->shakeTime, scene->shakePeriod) >> 12;
    if (scene->shakeLimit != -1 && t >= scene->shakeLimit) {
        scene->shake = 0;
        scene->shakeX = 0;
        scene->shakeY = 0;
        scene->shakeZ = 0;
        return;
    }
    if (scene->shakePhase == -1) {
        scene->shakePhase = func_02040498(7);
    }
    scene->shakeX = 0;
    scene->shakeY = GameScene_FxMul(table.entries[(t + scene->shakePhase) % 8].value, scene->shakeAmp);
    scene->shakeTime += 0x1000;
}

void func_02055cbc(GameScene *scene) {
    u32 effect = scene->effect;
    FieldState *state;
    if (effect == 0) {
        return;
    }
    state = data_ov000_021ccd54;
    switch (effect) {
    case 5:
        state->unk_18c = 1;
    case 0:
        state->unk_190 |= 0x1c;
        state->unk_18d = 1;
        state->unk_18e = 0x3c;
        state->unk_18f = 0x3c;
        break;
    case 6:
        state->unk_18c = 1;
    case 1:
        state->unk_190 |= 0x1c;
        state->unk_18d = 3;
        state->unk_18e = 0x3c;
        state->unk_18f = 0x3c;
        break;
    case 7:
        state->unk_18c = 1;
    case 2:
        state->unk_190 |= 0x1c;
        state->unk_18d = 5;
        state->unk_18e = 0x3c;
        state->unk_18f = 0x3c;
        break;
    case 10:
        state->unk_18c = 0;
        state->unk_18d = 0;
        state->unk_18e = 0;
        state->unk_18f = 0;
        break;
    }
    scene->effect = 0;
}

void func_02055d80(GameScene *scene) {
    BOOL busy = FALSE;
    GfxSys *sys = data_02097d48;
    s32 r;
    u16 n;
    func_02043d20(sys->unk_8b0, 0);
    func_02043d84(sys->unk_8b0);
    if (!scene->flag1 && scene->flag25) {
        busy = Field_IsPlayerBusy();
        if (!busy) {
            scene->Update98();
        }
    }
    scene->UpdateAc();
    scene->UpdateB4((u8 *)scene + 0xc0);
    func_02052fcc(scene);
    if (!scene->flag2) {
        return;
    }
    r = func_020572f8(scene, (u8 *)scene + 0xc0);
    if (r == -1) {
        return;
    }
    n = scene->count - r;
    if (n == 0) {
        return;
    }
    func_0203972c(scene->unk_0d0, n);
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
        tex = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, tex, part, 0);
}

void func_02055ee0(GameScene *scene) {
    s32 t;
    s32 sn;
    Model *model;
    if (scene->flag27 == 1) {
        return;
    }
    t = FX_Div(scene->unk_018 << 12, 0x28000);
    if (t >= 0x1000) {
        scene->unk_018 = 0;
        t = 0x1000;
    }
    sn = FX_SinCosTable_[((t << 14) >> 16) * 2];
    model = scene->model;
    model->x = 0x68000;
    sn = GameScene_FxMul(sn, 0x6000) >> 12;
    model->y = (sn + 0x50) << 12;
    scene->model->unk_150 = -0x99a;
    Model_ApplyPart(scene->model, 4);
}

}
