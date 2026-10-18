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

int func_02060be4(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02187a20(state, slot->args[0]);
    return 1;
}

int func_02060c28(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        data_02097e48->flag0 = 0;
        break;
    case 1:
        data_02097e48->flag0 = 1;
        break;
    case 2:
        data_02097e48->flag2 = 0;
        break;
    case 3:
        if (Field_HasEvent(0xa)) {
            return -0x63;
        }
        func_0204aa10(data_02097e48);
        data_02097e48->flag2 = 1;
        {
            SndQueue *q = data_02097e48;
            if (q->flag3) {
                q->unk_06 = 0x8000;
                q->unk_08 = 10;
                q->unk_02 = 0;
            }
        }
        break;
    case 4:
        data_02097e48->flag3 = 0;
        break;
    case 5:
        data_02097e48->flag3 = 1;
        break;
    case 6:
        func_02049564(data_02097e4c, 1, 1);
        break;
    }
    return 1;
}

int func_02060e0c(StageResSlot *slot) {
    if (Field_HasEvent(0x27) || Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        if (q->unk_06 != 0xffff ? TRUE : FALSE) {
            func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
            return -0x63;
        }
        func_0204aab0(q, slot->args[0]);
    }
    return 1;
}

int func_02060f58(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        SndQueue *q = data_02097e48;
        if (q->flag0) {
            if (!(q->unk_06 == 0xffff && q->unk_04 == id)) {
                if (q->unk_02 != 10 && q->unk_02 != 0) {
                    if (q->unk_06 != 0xffff) {
                        func_0204aab0(q, q->unk_06);
                    }
                    q->unk_02 = 1;
                } else {
                    q->unk_02 = 0;
                }
                q->unk_06 = id;
                q->unk_08 = 10;
            }
        }
    }
    return 1;
}

int func_02061088(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        if (q->flag0) {
            u16 cur = func_0204aac4(q);
            if (!(q->unk_06 == 0xffff && q->unk_04 == cur)) {
                if (cur == 0xffff) {
                    if (q->flag2 == 1 && q->flag3) {
                        q->unk_06 = 0x8000;
                        q->unk_08 = 10;
                        q->unk_02 = 0;
                    }
                } else {
                    q->unk_06 = cur;
                    q->unk_08 = 10;
                    q->unk_02 = 0;
                }
                func_0204aa90(q);
            }
        }
    }
    return 1;
}

int func_020611c8(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (slot->args[0] != 0) {
        u16 n = slot->args[0];
        SndQueue *q = data_02097e48;
        if (q->flag3) {
            q->unk_06 = 0x8000;
            q->unk_08 = n;
            q->unk_02 = 0;
        }
    } else {
        SndQueue *q = data_02097e48;
        if (q->flag3) {
            q->unk_06 = 0x8000;
            q->unk_08 = 10;
            q->unk_02 = 0;
        }
    }
    return 1;
}

int func_02061270(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        SndQueue *q = data_02097e48;
        if (!(q->flag0 == 1 && q->unk_74 == 0xffff && q->unk_72 == id)) {
            q->unk_74 = id;
            q->unk_70 = 0;
        }
    }
    return 1;
}

int func_02061360(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        q->unk_74 = 0x8000;
        q->unk_70 = 0;
    }
    return 1;
}

}
