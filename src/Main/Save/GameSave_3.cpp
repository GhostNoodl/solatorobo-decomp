#include "Main/Save/GameSave.h"

extern "C" {

void MainVt_0208c994_Setup(GameSave0208c994 *s) {
    s->vf78();
    SaveBase_AllocBuffers(s);
}

void MainVt_0208c994_Init(GameSave0208c994 *s) {
    s->onReset = NULL;
    s->onSave = NULL;
    s->onLoad = NULL;
}

void MainVt_0208c994_Finalize(GameSave0208c994 *s) {
}

void MainVt_0208c994_FillSlot(GameSave0208c994 *s, void *dst, u32 size) {
    if (s->onReset != NULL) {
        s->onReset(NULL, dst, size);
    }
}

void MainVt_0208c994_FillData(GameSave0208c994 *s, void *dst, u32 size) {
    if (s->onSave != NULL) {
        s->onSave((u8 *)SaveBase_GetSlot(s, s->curSlot) + 4, dst, size);
    }
}

void MainVt_0208c994_OnLoadData(GameSave0208c994 *s, void *dst, u32 size) {
    if (s->onLoad != NULL) {
        s->onLoad((u8 *)SaveBase_GetSlot(s, s->curSlot) + 4, dst, size);
    }
}

static inline void GameSave_Dtor(GameSave0208c994 *s) {
    *(u32 **)s = data_0208c994;
    s->Finalize();
    *(u32 **)s = data_0208ca9c;
    s->Finalize();
    *(u32 **)s = data_0208b614;
    s->Finalize();
}

GameSave0208c994 *MainVt_0208c994_DtorDelete(GameSave0208c994 *s) {
    GameSave_Dtor(s);
    Heap_Free(s);
    return s;
}

GameSave0208c994 *MainVt_0208c994_Dtor(GameSave0208c994 *s) {
    GameSave_Dtor(s);
    return s;
}

static inline void GameSaveBase_Dtor(GameSave *s) {
    *(u32 **)s = data_0208ca9c;
    s->Finalize();
    *(u32 **)s = data_0208b614;
    s->Finalize();
}

GameSave *MainVt_0208ca9c_DtorDelete(GameSave *s) {
    GameSaveBase_Dtor(s);
    Heap_Free(s);
    return s;
}

GameSave *MainVt_0208ca9c_Dtor(GameSave *s) {
    GameSaveBase_Dtor(s);
    return s;
}

GameSave *MainVt_0208ca18_Dtor(GameSave *s) {
    GameSaveBase_Dtor(s);
    return s;
}

GameSave *MainVt_0208ca18_DtorDelete(GameSave *s) {
    GameSaveBase_Dtor(s);
    Heap_Free(s);
    return s;
}

}
