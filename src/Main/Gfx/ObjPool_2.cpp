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
extern s32 func_ov000_0218c040(void *mgr, s32 max, ObjPoolVec *out, int kind, u16 id);

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

extern BOOL func_ov000_021b4738(ObjPoolPlayer *pl);

static inline BOOL ObjPool_InBox(ObjPoolEntry *e, s32 dx, s32 dy, s32 dz) {
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    return dx < e->unk_18 && dy < e->unk_1c && dz < e->unk_20;
}

static inline BOOL ObjPool_InBoxW(ObjPoolEntry *e, s32 dx, s32 dy, s32 dz, s32 w) {
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    return dx < w && dy < e->unk_1c && dz < e->unk_20;
}

static inline BOOL ObjPool_CheckBox(ObjPool *pool, ObjPoolEntry *entry) {
    if (entry->unk_04 == 0) {
        ObjPoolVec *pos = (ObjPoolVec *)pool;
        s32 dx = entry->x - pos->x;
        s32 dy = entry->y - pos->y;
        s32 dz = entry->z - pos->z;
        if (ObjPool_InBox(entry, dx, dy, dz)) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    } else {
        ObjPoolVec buf[16];
        s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x10, buf, entry->unk_06 >> 12, entry->unk_06);
        s32 w;
        s32 z;
        s32 y;
        s32 x;
        s32 i;
        i = 0;
        if (i < n) {
            x = entry->x;
            y = entry->y;
            z = entry->z;
            w = entry->unk_18;
            do {
                s32 dx = x - buf[i].x;
                s32 dy = y - buf[i].y;
                s32 dz = z - buf[i].z;
                if (ObjPool_InBoxW(entry, dx, dy, dz, w)) {
                    ObjPool_Trigger(pool, entry);
                    return TRUE;
                }
            } while (++i < n);
        }
    }
    return FALSE;
}

void func_0205a358(ObjPool *pool) {
    ObjPoolEntry *next;
    ObjPoolEntry *e;
    if (*(s32 *)data_ov000_021ccd54 != 3) {
        return;
    }
    data_02fe1534.unk_10 = 0xffff;
    data_02fe1534.unk_12 = 0xffff;
    e = pool->head;
    if (e == NULL) {
        return;
    }
    do {
        next = e->next;
        if (e->b != data_02fe1534.b || e->g != data_02fe1534.g || e->r != data_02fe1534.r) {
            func_020599f4(pool, e);
        } else {
            ObjPoolPlayer *pl = func_ov000_0219bf90();
            if (pl != NULL && !func_ov000_021b4738(pl) && (e->active & 1)) {
                switch (e->kind) {
                case 1:
                    if (func_0205a028(pool, e)) {
                        return;
                    }
                    break;
                case 2:
                    if (ObjPool_CheckBox(pool, e)) {
                        return;
                    }
                    break;
                case 5:
                    if (func_0205a268(pool, e)) {
                        return;
                    }
                    break;
                }
                e->active &= ~4;
            }
        }
        e = next;
    } while (e != NULL);
}

}
