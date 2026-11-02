#include "Main/Res/StageRes.h"

extern "C" {

extern const u32 data_0208bf54[];
extern const u32 data_0208be94[];
extern const u32 data_0208bf14[];
extern void StageRes_CancelSlots(StageRes *res);

StageRes *StageRes_DtorDelete(StageRes *res) {
    *(const u32 **)res = data_0208bf54;
    StageRes_CancelSlots(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    Heap_Free(res);
    return res;
}

StageRes *StageRes_Dtor(StageRes *res) {
    *(const u32 **)res = data_0208bf54;
    StageRes_CancelSlots(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

PosEvRes *PosEvRes_Dtor(PosEvRes *res) {
    res->type = 0;
    res->posCount = 0;
    res->pos = NULL;
    res->evCount = 0;
    res->ev = NULL;
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

DataRes *MainVt_0208be94_Dtor(DataRes *res) {
    *(const u32 **)res = data_0208be94;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

DataRes *MainVt_0208bf14_Dtor(DataRes *res) {
    *(const u32 **)res = data_0208bf14;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

}
