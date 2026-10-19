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

typedef struct ObjPoolVec {
    s32 x;
    s32 y;
    s32 z;
} ObjPoolVec;

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void *func_ov000_0218e750(void *mgr, u16 kind, u16 id, s32 *pos, s32 r);
extern s32 func_ov000_0218c040(void *mgr, s32 max, ObjPoolVec *out, u16 kind, u16 id);

static inline void *ObjPool_FindObj(u16 kind, u16 id, s32 *pos, s32 r) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e750(data_ov000_021ccd68, kind, id, pos, r);
}

static inline void ObjPool_Trigger(ObjPool *pool, ObjPoolEntry *entry) {
    entry->active |= 4;
    if (entry->active & 8) {
        data_02fe1534.unk_12 = entry->id;
    }
    if (entry->active & 2) {
        func_020599f4(pool, entry);
        data_02fe1534.unk_10 = entry->id;
        {
            u8 *p = &data_ov000_021ccd54->unk_0ac;
            *p = TRUE;
            func_ov000_02182590(p);
        }
        data_02fe1534.unk_10 = 0xffff;
    }
}

BOOL func_0205a028(ObjPool *pool, ObjPoolEntry *entry) {
    if (entry->unk_04 == 0) {
        ObjPoolVec *pos = (ObjPoolVec *)pool;
        s32 dy = entry->y - pos->y;
        s32 dx = entry->x - pos->x;
        s32 dz = entry->z - pos->z;
        if ((s32)(((s64)dx * dx + (s64)dy * dy + (s64)dz * dz + 0x800) >> 12) < entry->unk_1c) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    } else {
        ObjPoolVec buf[16];
        BOOL found = FALSE;
        if (ObjPool_FindObj(entry->unk_04 << 12, entry->unk_06, &entry->x, entry->unk_18) != NULL) {
            found = TRUE;
        } else {
            s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x10, buf, entry->unk_04, entry->unk_06);
            s32 i;
            for (i = 0; i < n; i++) {
                s32 dx = entry->x - buf[i].x;
                s32 dy = entry->y - buf[i].y;
                s32 dz = entry->z - buf[i].z;
                if ((s32)(((s64)dx * dx + (s64)dy * dy + (s64)dz * dz + 0x800) >> 12) < entry->unk_1c) {
                    found = TRUE;
                }
            }
        }
        if (found) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    }
    return FALSE;
}

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
