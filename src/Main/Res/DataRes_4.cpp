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

// Writes the low (packed & 0xff) bits of val, LSB first, starting at bit
// (packed >> 8) & 0xff past the entry's bit position in the block's data.
static inline void DataRes_WriteBitsAt(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, int sub, u16 val) {
    u8 *bytes;
    int n;
    int start;
    u16 i;
    start = ((packed >> 8) & 0xff) + entries[sub].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u8 v = (val >> i) & 1;
        u8 sh = pos & 7;
        u16 byte = pos >> 3;
        bytes[byte] &= ~(1 << sh);
        bytes[byte] |= v << sh;
    }
}

void func_020592c4(DataRes *res, u32 idx, int packed, int sub, u16 val) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    DataRes_WriteBitsAt(res, b, t, packed, sub, val);
}

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val) {
    u16 i;
    int start;
    u8 *bytes;
    int n;
    for (i = 0; i < block->count; i++) {
        if (id == entries[i].id) {
            break;
        }
    }
    start = ((packed >> 8) & 0xff) + entries[i].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u8 v = (val >> i) & 1;
        u8 sh = pos & 7;
        u16 byte = pos >> 3;
        bytes[byte] &= ~(1 << sh);
        bytes[byte] |= v << sh;
    }
}

}
