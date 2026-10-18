#include "Main/Res/DataRes.h"

extern "C" {

u32 func_020591a4(DataRes *res, u8 *buf, BOOL keepSome);

u32 func_02059270(DataRes *res, u8 *buf) {
    return func_020591a4(res, buf, TRUE);
}

void func_02059280(DataRes *res, SaveRef *ref, u32 idx, u16 unk) {
    ref->idx = idx;
    ref->unk_04 = unk;
    ref->block = &((SaveLayout *)res->data)->blocks[idx];
    ref->table = (SaveEntry *)((u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].tableOffset);
    ref->count = ((SaveLayout *)res->data)->blocks[idx].count;
}

void func_020592c4(DataRes *res, u32 idx, int packed, int sub, u16 val);

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val);

}
