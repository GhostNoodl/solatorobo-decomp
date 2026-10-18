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

int func_02060714(StageResSlot *slot) {
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

int func_0206076c(StageResSlot *slot) {
    u16 f = slot->args[1];
    ObjPoolEntry *e = func_02059b14(data_02149efc.pool, slot->args[0], NULL);
    e->kind = 5;
    e->active |= f;
    return 1;
}

int func_020607a8(StageResSlot *slot) {
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

int func_02060800(StageResSlot *slot) {
    ObjPoolEntry *e = func_02059b14(data_02149efc.pool, slot->args[0], (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12));
    e->active |= 8;
    return 1;
}

int func_02060840(StageResSlot *slot) {
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

int func_02060898(u16 id, u16 idx, int val) {
    StageObj3D *o;
    StageLightObj *l;
    if (id == 0xffff) {
        o = (StageObj3D *)data_02149efc.unk_14;
        l = (StageLightObj *)data_02149efc.unk_04;
    } else if (id != 0) {
        o = Stage_FindObj3DPtr(id);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, id, data_02fe1534.b & 0xff);
    } else {
        o = Stage_FindObj3DByIdx(idx);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, idx);
    }
    if (o != NULL) {
        o->params[5] = val;
    }
    if (l != NULL) {
        l->params[4] = val;
    }
    return 1;
}

int func_0206096c(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    func_02060898(slot->args[1], slot->args[2], slot->args[0] + 0xc);
    return 1;
}

int func_020609e8(StageResSlot *slot) {
    func_02060898(slot->args[0], slot->args[1], -1);
    return 1;
}

}
