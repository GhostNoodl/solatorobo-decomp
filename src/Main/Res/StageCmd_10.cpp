#include "Main/Res/StageCmd.h"
#include "Main/Hit/HitSphere.h"
#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"

extern "C" {

extern void func_0205fc88(u32 flags);
extern void func_ov000_02184594(FieldState *state);
extern ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param);
extern void func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int a);
extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_ov000_02187a20(FieldState *state, u16 a);
extern void func_0204aa10(SndQueue *queue);
extern void func_02049564(SndMgr *mgr, int a, int b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0204aab0(SndQueue *queue, u16 value);
extern u16 func_0204aac4(SndQueue *queue);
extern void func_0204aa90(SndQueue *queue);
int func_02060898(u16 id, u16 idx, int val);

static inline u32 *Flags_FindFreeSlot(StageFlags *flags) {
    u32 i;
    for (i = 0; i < 2; i++) {
        if (flags->slots[i] == 0xffffffff) {
            return &flags->slots[i];
        }
    }
    return NULL;
}

static inline u32 Flags_MakeKey(u8 a, u8 b, u8 c, u8 d) {
    return ((u32)(a << 24) | ((u32)(b << 24) >> 8) | ((u32)(c << 24) >> 16)) | d;
}

static inline void Flags_AddSlot(StageFlags *flags, u8 a, u8 b, u8 c, u8 d) {
    u32 *p = Flags_FindFreeSlot(flags);
    if (p != NULL) {
        *p = Flags_MakeKey(a, b, c, d);
    }
}

static inline void Flags_ClearSlot(StageFlags *flags, u8 a, u8 b, u8 c) {
    u32 key = Flags_MakeKey(a, b, c, 0);
    u32 i;
    for (i = 0; i < 2; i++) {
        if (key == (flags->slots[i] & ~0xff)) {
            flags->slots[i] = 0xffffffff;
        }
    }
}

int func_02060364(StageResSlot *slot) {
    StageRes *res;
    u16 idx;
    u16 ang;
    if (Field_HasEvent(9) || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    res = slot->res;
    idx = slot->args[0] & ~0x8000;
    ang = Stage_GetAngleOr0(res, slot->args[1]);
    if (slot->args[0] & 0x8000) {
        StagePlayer *player = func_ov000_0219bf90();
        s16 *p = (s16 *)(res->posEv->pos + idx * 6);
        if (player != NULL) {
            s32 x = p[0] << 4;
            s32 y = p[1] << 4;
            s32 z = p[2] << 4;
            player->target.x = x;
            player->target.y = y;
            player->target.z = z;
            player->targetRot[0] = 0;
            player->targetRot[1] = ang;
            player->targetRot[2] = 0;
        }
    }
    return 1;
}

int func_020604f4(StageResSlot *slot) {
    ObjPoolEntry *e = func_02059b14(data_02149efc.pool, slot->args[0], (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12));
    e->active |= 2;
    return 1;
}

int func_02060534(StageResSlot *slot) {
    u16 a;
    ObjPoolEntry *e;
    ObjPoolParam *prm = (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12);
    a = slot->args[1];
    e = func_02059b14(data_02149efc.pool, slot->args[0], prm);
    if ((u16)(a & 0xfff) == 0xfff) {
        e->unk_06 = 0xffff;
    } else {
        e->unk_06 = a;
    }
    e->unk_04 = a >> 12;
    e->active |= 2;
    return 1;
}

int func_020605a4(StageResSlot *slot) {
    u16 id = slot->args[0];
    ObjPool *pool = data_02149efc.pool;
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind != 0 && e->id == id) {
            break;
        }
    }
    if (i != 16) {
        func_020599f4(pool, e);
    }
    return 1;
}

}
