#include "Main/Res/DataRes.h"

extern "C" {



u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);

u16 func_0205973c(DataRes *res, SaveRef *ref, u32 id) {
    return func_02059688(res, ref->block, ref->table, ref->unk_04, id);
}

u32 func_0205975c(DataRes *res, u32 idx) {
    return ((SaveLayout *)res->data)->blocks[idx].count;
}

SaveEntry *func_0205976c(DataRes *res, u32 idx) {
    return (SaveEntry *)((u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].tableOffset);
}

typedef struct ResChunk {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 next;
    /* 0x08 */ u32 dataOffset;
    /* 0x0c */ u32 count;
} ResChunk;

typedef struct ResFileHeader {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 firstChunk;
} ResFileHeader;

BOOL func_02059784(PosEvRes *res) {
    ResFileHeader *hdr;
    ResChunk *chunk;
    u32 next;
    if (res->loaded) {
        return TRUE;
    }
    hdr = *(ResFileHeader **)res->GetData();
    if (hdr->size == 0) {
        return TRUE;
    }
    chunk = (ResChunk *)((u8 *)hdr + hdr->firstChunk);
    next = 0;
    res->posCount = 0;
    res->pos = NULL;
    if (chunk->magic == 0x534f5054) {
        res->posCount = chunk->count;
        res->pos = (u8 *)chunk + chunk->dataOffset;
        next = chunk->next;
    }
    res->evCount = 0;
    res->ev = NULL;
    chunk = (ResChunk *)((u8 *)chunk + next);
    if (chunk->magic == 0x50564554) {
        res->evCount = chunk->count;
        res->ev = (u8 *)chunk + chunk->dataOffset;
    }
    res->loaded = TRUE;
    return TRUE;
}

}
