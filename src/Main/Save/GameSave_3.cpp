#include "Main/Save/GameSave.h"

extern "C" {

void func_0206dac8(GameSave *s) {
    s->vf78();
    func_0204730c(s);
}

void func_0206dae8(GameSave *s) {
    s->onReset = NULL;
    s->onSave = NULL;
    s->onLoad = NULL;
}

void func_0206dafc(GameSave *s) {
}

void func_0206db00(GameSave *s, void *dst, u32 size) {
    if (s->onReset != NULL) {
        s->onReset(NULL, dst, size);
    }
}

void func_0206db1c(GameSave *s, void *dst, u32 size) {
    if (s->onSave != NULL) {
        s->onSave((u8 *)SaveBase_GetSlot(s, s->curSlot) + 4, dst, size);
    }
}

void func_0206db50(GameSave *s, void *dst, u32 size) {
    if (s->onLoad != NULL) {
        s->onLoad((u8 *)SaveBase_GetSlot(s, s->curSlot) + 4, dst, size);
    }
}

static inline void GameSave_Dtor(GameSave *s) {
    *(u32 **)s = data_0208c994;
    s->Finalize();
    *(u32 **)s = data_0208ca9c;
    s->Finalize();
    *(u32 **)s = data_0208b614;
    s->Finalize();
}

GameSave *func_0206db84(GameSave *s) {
    GameSave_Dtor(s);
    func_0203de1c(s);
    return s;
}

GameSave *func_0206dbec(GameSave *s) {
    GameSave_Dtor(s);
    return s;
}

static inline void GameSaveBase_Dtor(GameSave *s) {
    *(u32 **)s = data_0208ca9c;
    s->Finalize();
    *(u32 **)s = data_0208b614;
    s->Finalize();
}

GameSave *func_0206dc4c(GameSave *s) {
    GameSaveBase_Dtor(s);
    func_0203de1c(s);
    return s;
}

GameSave *func_0206dc98(GameSave *s) {
    GameSaveBase_Dtor(s);
    return s;
}

GameSave *func_0206dcdc(GameSave *s) {
    GameSaveBase_Dtor(s);
    return s;
}

GameSave *func_0206dd20(GameSave *s) {
    GameSaveBase_Dtor(s);
    func_0203de1c(s);
    return s;
}

}
