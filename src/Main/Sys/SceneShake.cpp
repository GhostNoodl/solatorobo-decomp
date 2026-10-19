#include "Main/Sys/GameScene.h"
#include "Main/Sys/Field.h"

extern "C" {

void func_02051f70(GameScene *scene) {
    FieldState *state = data_ov000_021ccd54;
    scene->shakeTime = 0;
    scene->shakePhase = -1;
    switch (scene->shakeType) {
    case 0:
        scene->shake = 1;
        scene->shakePeriod = 0x2000;
        scene->shakeAmp = 0x4000;
        scene->shakeLimit = 4;
        break;
    case 1:
        scene->shake = 1;
        scene->shakePeriod = 0x3000;
        scene->shakeAmp = 0x7000;
        scene->shakeLimit = 5;
        break;
    case 2:
        scene->shake = 1;
        scene->shakePeriod = 0x4000;
        scene->shakeAmp = 0xa000;
        scene->shakeLimit = 6;
        break;
    case 5:
        scene->shake = 2;
        scene->shakePeriod = 0x2000;
        scene->shakeAmp = 0x2000;
        scene->shakeLimit = -1;
        break;
    case 6:
        scene->shake = 2;
        scene->shakePeriod = 0x3000;
        scene->shakeAmp = 0x4000;
        scene->shakeLimit = -1;
        break;
    case 7:
        scene->shake = 2;
        scene->shakePeriod = 0x4000;
        scene->shakeAmp = 0x6000;
        scene->shakeLimit = -1;
        break;
    case 16:
        scene->shakeLimit = 0;
        scene->shake = 0;
        state->unk_18c = 0;
        state->unk_18d = 0;
        state->unk_18e = 0;
        state->unk_18f = 0;
        break;
    }
}

}
