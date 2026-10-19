#include "Main/Res/DataRes.h"

extern "C" {

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val);

void func_02059428(DataRes *res, SaveRef *ref, u32 id, u16 val) {
    func_02059360(res, ref->block, ref->table, ref->unk_04, id, val);
}

u16 func_02059454(DataRes *res, u32 idx, int n, int start) {
    u16 r;
    u16 i;
    u8 *bytes;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].offset;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

// Reads (packed & 0xff) bits, LSB first, starting at bit (packed >> 8) & 0xff
// past the entry's bit position in the block's data.
static inline u16 DataRes_ReadBitsAt(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, int sub) {
    u16 r;
    int n;
    u8 *bytes;
    int start;
    u16 i;
    start = ((packed >> 8) & 0xff) + entries[sub].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

// Same, for the entry whose id matches.
static inline u16 DataRes_ReadBitsById(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id) {
    u16 r;
    u16 i;
    int n;
    u8 *bytes;
    int start;
    for (i = 0; i < block->count; i++) {
        if (id == entries[i].id) {
            break;
        }
    }
    start = ((packed >> 8) & 0xff) + entries[i].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

u16 func_020594bc(DataRes *res, u32 idx, int packed, int sub) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    return DataRes_ReadBitsAt(res, b, t, packed, sub);
}

u16 func_02059544(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u16 sub) {
    return DataRes_ReadBitsAt(res, block, entries, packed, sub);
}

u16 func_020595c4(DataRes *res, u32 idx, int packed, u32 id) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    return DataRes_ReadBitsById(res, b, t, packed, id);
}

u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id) {
    return DataRes_ReadBitsById(res, block, entries, packed, id);
}

}
