#include "Main/Res/StageRes.h"

extern "C" {

extern const u32 StageRes_vtbl[];
extern const u32 MainVt_0208be94_vtbl[];
extern const u32 MainVt_0208bf14_vtbl[];
extern void StageRes_CancelSlots(StageRes *res);

StageRes *StageRes_DtorDelete(StageRes *res) {
    *(const u32 **)res = StageRes_vtbl;
    StageRes_CancelSlots(res);
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    Heap_Free(res);
    return res;
}

StageRes *StageRes_Dtor(StageRes *res) {
    *(const u32 **)res = StageRes_vtbl;
    StageRes_CancelSlots(res);
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    return res;
}

PosEvRes *PosEvRes_Dtor(PosEvRes *res) {
    res->type = 0;
    res->posCount = 0;
    res->pos = NULL;
    res->evCount = 0;
    res->ev = NULL;
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    return res;
}

DataRes *MainVt_0208be94_Dtor(DataRes *res) {
    *(const u32 **)res = MainVt_0208be94_vtbl;
    res->Unload();
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    return res;
}

DataRes *MainVt_0208bf14_Dtor(DataRes *res) {
    *(const u32 **)res = MainVt_0208bf14_vtbl;
    res->Unload();
    *(const u32 **)res = ResHandle_vtbl;
    res->Unload();
    return res;
}

}
