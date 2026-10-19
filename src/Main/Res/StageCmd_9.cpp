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

u16 func_020600cc(StageResSlot *slot, StageVec *pos, u16 *rot, u16 *idx) {
    StageRes *res;
    u16 ang;
    func_ov000_0219bf90();
    res = slot->res;
    *idx = slot->args[0] & ~0x8000;
    ang = Stage_GetAngleOr0(res, slot->args[1]);
    if (slot->args[0] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + *idx * 6);
        pos->x = p[0] << 4;
        pos->y = p[1] << 4;
        pos->z = p[2] << 4;
        rot[0] = 0;
        rot[1] = ang;
        rot[2] = 0;
        *idx = 0xffff;
    }
    return slot->args[2];
}

int func_020601e0(StageResSlot *slot) {
    if (!Stage_IsWirelessReady() || Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (func_ov000_0219bf90() == NULL) {
        func_ov000_02184594(data_ov000_021ccd54);
        return -0x63;
    }
    func_0205fc88(slot->args[0]);
    return 1;
}

int func_02060278(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL || Field_HasEvent(9) || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    if (player != NULL) {
        u8 rgb[3];
        rgb[0] = slot->args[0];
        rgb[1] = slot->args[1];
        rgb[2] = slot->args[2];
        player->color = *(StageColor *)rgb;
    }
    return 1;
}

}
