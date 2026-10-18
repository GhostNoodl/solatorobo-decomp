#include "Main/Res/StageRes.h"

extern "C" {

extern const u32 data_0208bf54[];
extern const u32 data_0208be94[];
extern const u32 data_0208bf14[];
extern void func_0205a6e8(StageRes *res);

StageRes *func_02062844(StageRes *res) {
    *(const u32 **)res = data_0208bf54;
    func_0205a6e8(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

StageRes *func_02062888(StageRes *res) {
    *(const u32 **)res = data_0208bf54;
    func_0205a6e8(res);
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

PosEvRes *func_020628c4(PosEvRes *res) {
    res->type = 0;
    res->posCount = 0;
    res->pos = NULL;
    res->evCount = 0;
    res->ev = NULL;
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

DataRes *func_02062904(DataRes *res) {
    *(const u32 **)res = data_0208be94;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

DataRes *func_02062948(DataRes *res) {
    *(const u32 **)res = data_0208bf14;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    return res;
}

}
