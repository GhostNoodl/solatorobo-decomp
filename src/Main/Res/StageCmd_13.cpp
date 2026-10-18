#include "Main/Res/StageCmd.h"
#include "Main/Gfx/GfxMgr.h"
#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"

extern "C" {

extern SndMgr *data_02097e4c;
extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, u16 id);
extern void func_0204a284(SndMgr *mgr, int a);
extern void func_ov000_021bc3ec(FieldState *state, u16 a, s32 b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0203c9e8(int a, int b);
extern void func_0203cc58(int a, int b, int c);
extern int func_0203ca84(int a);
extern void func_0203cb78(s32 a, int b, int c);
extern void func_0203ca24(int h, int a, int b);
extern void func_ov000_02187374(FieldState *state, u16 a);
extern void func_ov000_0218348c(FieldState *state, u8 a);
extern void func_ov000_02182ad4(FieldState *state);
extern void func_ov000_02182b0c(FieldState *state);
extern void func_ov000_021b1b88(StagePlayer *player, u16 a);
extern void func_ov000_02188634(FieldState *state, u16 a, u16 b);
extern u16 func_ov000_0214be8c(void);
extern BOOL func_ov000_021b4738(StagePlayer *player);
extern int STD_CompareString(const char *a, const char *b);
extern DataRes *data_02fe1530;
extern u16 func_020594bc(DataRes *res, u32 idx, int packed, int sub);
extern void MIi_CpuClear16(u32 value, void *dst, u32 size);
extern const char data_0208be27[];
extern const char data_0208be34[];
extern const char data_0208be43[];
extern const char data_0208be50[];
extern const char data_0208be5c[];
extern const char data_0208be65[];
extern const char data_0208be74[];
extern const char data_0208be7f[];

typedef struct StageTblChunk {
    /* 0x00 */ char name[0x10];
    /* 0x10 */ u32 size;
    /* 0x14 */ u8 unk_14[8];
    /* 0x1c */ u16 offsets[1];
} StageTblChunk;

typedef struct StageTblHeader {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ StageTblChunk chunks[1];
} StageTblHeader;


static inline BOOL Stage_IsWirelessIdle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline void Shared_SetFog(u16 r, u16 g, u16 b) {
    data_02fe1534.unk_52 = r;
    data_02fe1534.unk_54 = g;
    data_02fe1534.unk_56 = b;
}

static inline BOOL Shared_TestFlag(u16 mask) {
    return (data_02fe1534.posFlags & mask) ? TRUE : FALSE;
}

static inline BOOL Shared_HasMark(void) {
    return data_02fe1534.unk_16 != 0 ? TRUE : FALSE;
}

int func_020613bc(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    func_02049a48(data_02097e4c, slot->args[0], -1, -1, -1);
    return 1;
}

int func_0206149c(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_02049de8(data_02097e4c, slot->args[0]);
    return 1;
}

int func_020614f4(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    func_0204a20c(data_02097e4c, slot->args[0]);
    return 1;
}

int func_020615bc(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_0204a284(data_02097e4c, -1);
    return 1;
}

int func_02061614(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021bc3ec(data_ov000_021ccd70, slot->args[0], slot->args[1] << 12);
    return 1;
}

int func_02061668(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021bc458(data_ov000_021ccd70);
    return 1;
}

int func_020616b0(StageResSlot *slot) {
    data_02097d48->pltt.id = slot->args[0];
    return 1;
}

int func_020616cc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02097d48->pltt.id = -1;
    return 1;
}

int func_02061710(StageResSlot *slot) {
    if (!slot->bits.flag8 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (Stage_IsWirelessIdle()) {
        int mode;
        switch (slot->args[2]) {
        case 0:
            mode = 0;
            break;
        case 1:
            mode = 1;
            break;
        case 3:
            mode = 3;
            break;
        default:
            mode = -1;
            break;
        }
        func_0203c9e8(0x3f, 0);
        func_0203cc58(slot->args[0] << 12, slot->args[1] != 0 ? 1 : 2, mode);
    }
    return 1;
}

int func_020617ec(StageResSlot *slot) {
    if (!slot->bits.flag8 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (Stage_IsWirelessReady()) {
        int h = func_0203ca84(0);
        func_0203cb78(slot->args[0] << 12, 2, 0);
        func_0203ca24(h, 0, 0);
    }
    return 1;
}

int func_0206189c(StageResSlot *slot) {
    if (Stage_IsWirelessReady()) {
        return 1;
    }
    return -0x63;
}

int func_020618d4(StageResSlot *slot) {
    if (!Stage_IsWirelessIdle()) {
        return -0x63;
    }
    return 1;
}

int func_02061904(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, slot->args[0], slot->args[1], 0);
    return 1;
}

int func_02061950(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, slot->args[0], slot->args[1], 1);
    return 1;
}

int func_020619a0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, 1, 0, 0);
    return 1;
}

int func_020619ec(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    return 1;
}

int func_02061a1c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02187374(state, slot->args[0]);
    return 1;
}

int func_02061a60(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218348c(state, slot->args[0]);
    return 1;
}

int func_02061aa8(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02182ad4(state);
    return 1;
}

int func_02061ae4(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02182b0c(state);
    return 1;
}

int func_02061b20(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        if (slot->args[1] == 0) {
            data_0214a424->bits18.flag7 = 0;
        } else if (slot->args[1] == 1) {
            data_0214a424->bits18.flag7 = 1;
        }
        break;
    case 1:
        if (slot->args[1] != data_0214a424->bits18.mode) {
            StagePlayer *player = func_ov000_0219bf90();
            if (player != NULL) {
                func_ov000_021b1b88(player, slot->args[1]);
                Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
            } else {
                data_0214a424->bits18.mode = slot->args[1];
            }
        }
        break;
    }
    return 1;
}

int func_02061c44(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188634(state, slot->args[0], slot->args[1]);
    return 1;
}

int func_02061c8c(StageResSlot *slot) {
    ObjPoolShared *shared = &data_02fe1534;
    switch (slot->args[0]) {
    case 0:
        shared->unk_80 = func_ov000_0214be8c();
        break;
    case 1: {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            StageObj3D *o = Stage_FindObj3DByIdx(player->unk_b1c);
            if (o == NULL) {
                shared->unk_80 = 0;
            } else {
                shared->unk_80 = 1;
                shared->unk_24 = o->unk_0e;
                shared->unk_26 = o->unk_0c;
            }
        }
        break;
    }
    case 2: {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            if (func_ov000_021b4738(player)) {
                shared->unk_80 = 1;
            } else {
                shared->unk_80 = 0;
            }
        } else {
            shared->unk_80 = 0;
        }
        break;
    }
    }
    return 1;
}

u16 func_02061d54(u16 a) {
    return a & ~0x8000;
}

void *func_02061d64(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be27;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061df0(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be34;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061e7c(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be43;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061f08(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be50;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061f94(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be5c;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02062020(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be65;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_020620ac(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be74;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02062138(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = data_0208be7f;
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

BOOL func_020621c4(void) {
    BOOL r = TRUE;
    if (func_020594bc(data_02fe152c, 5, r, 8) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_020621f8(void) {
    BOOL r = TRUE;
    if (func_020594bc(data_02fe152c, 5, r, 9) == 0) {
        r = FALSE;
    }
    return r;
}

void func_0206222c(void) {
    ObjPoolShared *shared = &data_02fe1534;
    MIi_CpuClear16(0, shared, 0x82);
    shared->unk_04 = 0;
    shared->r = 0xffff;
    shared->g = 0xffff;
    shared->b = 0xffff;
    shared->unk_10 = 0xffff;
    shared->unk_12 = 0xffff;
    shared->unk_4c = 0xffff;
    shared->unk_4e = 0xffff;
    shared->unk_50 = 0xffff;
    shared->unk_52 = 0x8000;
    shared->unk_54 = 0x8000;
    shared->unk_56 = 0x8000;
}

void func_0206228c(void) {
    data_02fe1534.unk_00 = 0;
    data_02fe1534.unk_42 = 0;
    data_02fe1534.unk_44 = 0;
    data_02fe1534.unk_20 = 0xffff;
    data_02fe1534.unk_24 = 0;
    data_02fe1534.unk_26 = 0;
    data_02fe1534.unk_28 = 0;
    data_02fe1534.unk_22 = 0;
    data_02fe1534.unk_2a = 0;
    data_02fe1534.unk_32 = 0;
    data_02fe1534.unk_70 = 0;
    data_02fe1534.unk_72 = 0;
    data_02fe1534.unk_74 = 0;
    data_02fe1534.unk_76 = 0;
    data_02fe1534.unk_14 &= ~0x3c0;
}

int func_020622ec(u8 *buf, u32 size) {
    MI_CpuFill8(buf, 0, size);
    buf[0] = data_02fe1534.unk_02[0];
    buf[1] = data_02fe1534.unk_02[1];
    buf[2] = data_02fe1534.unk_52_bytes[0];
    buf[3] = data_02fe1534.unk_52_bytes[1];
    buf[4] = data_02fe1534.unk_52_bytes[2];
    buf[5] = data_02fe1534.unk_52_bytes[3];
    buf[6] = data_02fe1534.unk_52_bytes[4];
    buf[7] = data_02fe1534.unk_52_bytes[5];
    buf[8] = data_02fe1534.unk_52_bytes[6];
    buf[9] = data_02fe1534.unk_52_bytes[7];
    buf[10] = data_02fe1534.unk_52_bytes[8];
    buf[11] = data_02fe1534.unk_52_bytes[9];
    return 12;
}

int func_02062370(u8 *buf) {
    data_02fe1534.unk_02[0] = buf[0];
    data_02fe1534.unk_02[1] = buf[1];
    data_02fe1534.unk_52_bytes[0] = buf[2];
    data_02fe1534.unk_52_bytes[1] = buf[3];
    data_02fe1534.unk_52_bytes[2] = buf[4];
    data_02fe1534.unk_52_bytes[3] = buf[5];
    data_02fe1534.unk_52_bytes[4] = buf[6];
    data_02fe1534.unk_52_bytes[5] = buf[7];
    data_02fe1534.unk_52_bytes[6] = buf[8];
    data_02fe1534.unk_52_bytes[7] = buf[9];
    data_02fe1534.unk_52_bytes[8] = buf[10];
    data_02fe1534.unk_52_bytes[9] = buf[11];
    return 12;
}

void func_020623e0(void) {
    data_02fe1534.unk_44 = 2;
    data_02fe1534.unk_42 = 3;
}

void func_020623fc(void) {
    data_02fe1534.unk_42 = 5;
}

void func_02062410(void) {
    data_02fe1534.unk_42 = 6;
}

void func_02062424(const StageColor *c) {
    data_02fe1534.unk_44 = 1;
    data_02fe1534.r = c->r;
    data_02fe1534.g = c->g;
    data_02fe1534.b = c->b;
    data_02fe1534.unk_68 = 0;
    data_02fe1534.unk_6a = 0;
    data_02fe1534.unk_6c = 0;
    data_02fe1534.unk_6e = 0;
    data_02fe1534.unk_80 = data_ov000_021ccd6c->unk_0a;
}

void func_02062478(const StageColor *c) {
    data_02fe1534.unk_44 = 2;
    data_02fe1534.unk_4c = c->r;
    data_02fe1534.unk_4e = c->g;
    data_02fe1534.unk_50 = c->b;
    data_02fe1534.unk_80 = data_ov000_021ccd6c->unk_0a;
}

void func_020624b8(void) {
    data_02fe1534.unk_4c = 0xffff;
    data_02fe1534.unk_4e = 0xffff;
    data_02fe1534.unk_50 = 0xffff;
}

BOOL func_020624d8(void) {
    u16 v = data_02fe1534.unk_52;
    return (v != 0xffff && v != 0x8000) ? TRUE : FALSE;
}

void func_02062500(const StageColor *c) {
    data_02fe1534.unk_52 = c->r;
    data_02fe1534.unk_54 = c->g;
    data_02fe1534.unk_56 = c->b;
}

void func_02062524(void) {
    data_02fe1534.unk_52 = 0x8000;
    data_02fe1534.unk_54 = 0x8000;
    data_02fe1534.unk_56 = 0x8000;
}

void func_02062540(StageVec *out) {
    s32 x = data_02fe1534.posX;
    s32 y = data_02fe1534.posY;
    s32 z = data_02fe1534.posZ;
    data_02fe1534.posFlags &= ~1;
    out->x = x << 4;
    out->y = y << 4;
    out->z = z << 4;
}

u16 func_02062588(void) {
    data_02fe1534.posFlags &= ~2;
    return data_02fe1534.unk_3c;
}

u16 func_020625ac(void) {
    data_02fe1534.posFlags &= ~4;
    return data_02fe1534.unk_3e;
}

s32 func_020625d0(void) {
    s16 v = data_02fe1534.unk_40;
    data_02fe1534.posFlags &= ~8;
    return v << 4;
}

BOOL func_020625f8(void) {
    return Shared_TestFlag(1) ? TRUE : FALSE;
}

BOOL func_02062620(void) {
    return Shared_TestFlag(2) ? TRUE : FALSE;
}

BOOL func_02062648(void) {
    return Shared_TestFlag(4) ? TRUE : FALSE;
}

BOOL func_02062670(void) {
    return Shared_TestFlag(8) ? TRUE : FALSE;
}

BOOL func_02062698(void) {
    return Shared_HasMark() ? TRUE : FALSE;
}

void func_020626c0(void) {
    data_02fe1534.unk_16 = 0;
}

void func_020626d4(StageVec *pos, u16 rot) {
    data_02fe1534.unk_16 = 1;
    if (pos == NULL) {
        return;
    }
    data_02fe1534.unk_18 = (pos->x + 8) >> 4;
    data_02fe1534.unk_1a = (pos->y + 8) >> 4;
    data_02fe1534.unk_1c = (pos->z + 8) >> 4;
    data_02fe1534.unk_1e = rot;
}

void func_02062724(StageVec *out) {
    out->x = data_02fe1534.unk_18 << 4;
    out->y = data_02fe1534.unk_1a << 4;
    out->z = data_02fe1534.unk_1c << 4;
}

u16 func_02062754(void) {
    return data_02fe1534.unk_1e;
}

void func_02062764(u16 clear, u16 set) {
    data_02fe1534.unk_14 &= (u16)~clear;
    data_02fe1534.unk_14 |= set;
}

void func_02062790(u16 a) {
    data_02fe1534.unk_20 = a;
}

void func_020627a0(u16 a, u16 b) {
    data_02fe1534.unk_24 = a;
    data_02fe1534.unk_26 = b;
}

void func_020627b4(void) {
    data_02fe1534.unk_22 = 1;
}

void func_020627c8(void) {
    data_02fe1534.unk_22 = 0;
}

void func_020627dc(u16 a) {
    data_02fe1534.unk_28 = a;
}

void func_020627ec(u16 a) {
    data_02fe1534.unk_2a = a;
}

void func_020627fc(u16 a) {
    data_02fe1534.unk_32 = a;
}

void func_0206280c(u16 a) {
    data_02fe1534.unk_80 = a;
}

void func_0206281c(void) {
    data_02fe1534.unk_7c = 0xffff;
}

u16 func_02062834(void) {
    return data_02fe1534.unk_7c;
}

}
