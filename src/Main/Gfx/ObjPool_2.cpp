#include "Main/Gfx/ObjPool.h"
#include "Main/Sys/Field.h"

typedef struct ObjPoolPlayer {
    /* 0x000 */ u8 unk_000[0xb2a];
    /* 0xb2a */ u8 flag0 : 1;
    /* 0xb2a */ u8 flag1 : 1;
    /* 0xb2a */ u8 flag2 : 1;
    /* 0xb2a */ u8 flag3 : 1;
    /* 0xb2a */ u8 flag4 : 1;
} ObjPoolPlayer;

extern "C" {

extern ObjPoolPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02182590(u8 *p);

BOOL func_0205a268(ObjPool *pool, ObjPoolEntry *entry) {
    ObjPoolPlayer *player = func_ov000_0219bf90();
    BOOL hit;
    if (player == NULL) {
        return FALSE;
    }
    hit = FALSE;
    if ((entry->active & 0x10) && player->flag0) {
        hit = TRUE;
    }
    if ((entry->active & 0x20) && player->flag1) {
        hit = TRUE;
    }
    if ((entry->active & 0x40) && player->flag2) {
        hit = TRUE;
    }
    if ((entry->active & 0x80) && player->flag3) {
        hit = TRUE;
    }
    if ((entry->active & 0x100) && player->flag4) {
        hit = TRUE;
    }
    if (!hit) {
        return FALSE;
    }
    func_020599f4(pool, entry);
    data_02fe1534.unk_10 = entry->id;
    {
        u8 *p = &data_ov000_021ccd54->unk_0ac;
        *p = TRUE;
        func_ov000_02182590(p);
    }
    data_02fe1534.unk_10 = 0xffff;
    return TRUE;
}

}
