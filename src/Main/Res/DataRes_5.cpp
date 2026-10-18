#include "Main/Res/DataRes.h"

extern "C" {

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val);

void func_02059428(DataRes *res, SaveRef *ref, u32 id, u16 val) {
    func_02059360(res, ref->block, ref->table, ref->unk_04, id, val);
}

u16 func_02059454(DataRes *res, u32 idx, int nbits, int pos);

u16 func_020594bc(DataRes *res, u32 idx, int packed, int sub);

}
