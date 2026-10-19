#ifndef MAIN_SAVE_SAVEBASE_H
#define MAIN_SAVE_SAVEBASE_H

#include "Main/Save/SysCard.h"
#include "Main/Res/ResMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

// Base save-data object: a header block with a slot table, followed by per-slot data blocks
// and a ring of backup data blocks. Methods are dispatched through data_0208b614.

typedef struct SaveSlot {
    /* 0x00 */ u8 checksum;
    /* 0x01 */ u8 flags; // bit0: used, bit1: corrupt
    /* 0x02 */ u16 size;
} SaveSlot;

typedef struct SaveHeader {
    /* 0x00 */ char magic[0x10];
    /* 0x10 */ u8 curSlot;
    /* 0x11 */ u8 backupIdx;
    /* 0x12 */ u8 unk_12[2];
    /* 0x14 */ u8 slots[];
} SaveHeader;

typedef struct SaveData {
    /* 0x00 */ u8 slotIdx;
    /* 0x01 */ u8 checksum;
    /* 0x02 */ u16 size;
    /* 0x04 */ SaveSlot slot;
} SaveData;

#ifdef __cplusplus
}
#endif

struct SaveBase {
    /* 0x00 */ // vtable (data_0208b614)
    virtual void Dtor();
    virtual void DeletingDtor();
    virtual void Setup();
    virtual BOOL Update();
    virtual void unk_vf10();
    virtual void Init();
    virtual void Finalize();
    virtual void FillSlot(void *dst, u32 size);
    virtual void FillData(void *dst, u32 size);
    virtual void LoadData(void *src, u32 size);
    virtual void OnError();
    virtual void State1();
    virtual void InitHeader(SaveHeader *hdr);
    virtual void State2();
    virtual void State3();
    virtual void State4();
    virtual void State5();
    virtual void State6();
    virtual void State7();
    virtual void State8();
    virtual void State9();
    virtual void State10();
    virtual void State11();
    virtual void State12();
    virtual void State13();
    virtual void State14();
    virtual void State15();
    virtual void State16();
    virtual BOOL WriteBackup(SaveHeader *hdr);
    /* 0x04 */ const char *name;
    /* 0x08 */ u8 formatted;
    /* 0x0c */ void *tmpBuf;
    /* 0x10 */ u32 tmpSize;
    /* 0x14 */ u32 baseOffset;
    /* 0x18 */ s32 state;
    /* 0x1c */ s32 step;
    /* 0x20 */ s32 counter;
    /* 0x24 */ u8 stateChanged;
    /* 0x28 */ SaveHeader *header;
    /* 0x2c */ u32 headerSize;
    /* 0x30 */ u32 slotSize;
    /* 0x34 */ SaveData *data;
    /* 0x38 */ u32 dataSize;
    /* 0x3c */ s32 slotCount;
    /* 0x40 */ s32 curSlot;
    /* 0x44 */ u8 backupIdx;
    /* 0x45 */ u8 backupStart;
    /* 0x46 */ u8 backupCount;
};

extern "C" {

extern u32 data_0208b614[];
extern const char data_0208b5fd[];

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void MI_CpuFill8(void *dst, u32 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

BOOL func_02047694(SaveBase *s);
BOOL func_02047724(SaveBase *s);

static inline void SaveBase_SetState(SaveBase *s, s32 state) {
    if (s->state != state) {
        s->state = state;
        s->step = 0;
        s->counter = 0;
        s->stateChanged = 1;
    }
}

static inline SaveSlot *SaveBase_GetSlot(SaveBase *s, s32 idx) {
    return (SaveSlot *)((u8 *)s->header + (idx * s->slotSize + 0x14));
}

static inline s32 SaveBase_ReadHeader(SaveBase *s, SaveHeader *hdr) {
    return func_02046e48(data_02097e44, hdr, s->baseOffset, s->headerSize);
}

static inline s32 SaveBase_WriteHeader(SaveBase *s, SaveHeader *hdr) {
    return func_02047004(data_02097e44, s->baseOffset, hdr, s->headerSize);
}

static inline u32 SaveBase_DataOffset(SaveBase *s, s32 idx) {
    return s->baseOffset + s->headerSize + idx * s->dataSize;
}

static inline u32 SaveBase_BackupOffset(SaveBase *s, s32 idx) {
    return s->baseOffset + s->headerSize + s->dataSize * s->slotCount + idx * s->dataSize;
}

static inline void SaveBase_BuildSlot(SaveBase *s) {
    u32 size = s->slotSize;
    SaveSlot *slot = SaveBase_GetSlot(s, s->curSlot);
    u32 n;
    slot->flags |= 1;
    slot->flags &= ~2;
    slot->size = size;
    size = s->slotSize;
    n = size - 4;
    if (n != 0) {
        u32 len;
        u8 x;
        const u8 *p;
        u32 i;
        s->FillSlot((u8 *)SaveBase_GetSlot(s, s->curSlot) + (size - n), n);
        x = 0;
        len = s->slotSize - 1;
        p = (const u8 *)slot + 1;
        for (i = 0; i < len; i++) {
            x ^= p[i];
        }
        slot->checksum = x;
    } else {
        slot->checksum = 0;
    }
}

static inline void SaveBase_BuildData(SaveBase *s) {
    s32 idx = s->curSlot;
    SaveSlot *src = SaveBase_GetSlot(s, idx);
    u32 size = s->dataSize;
    u32 n;
    SaveData *data = s->data;
    data->slotIdx = idx;
    data->size = size;
    MI_CpuCopy8(src, &data->slot, s->slotSize);
    size = s->dataSize;
    n = size - (s->slotSize + 4);
    if (n != 0) {
        u8 x;
        u32 i;
        u8 *p = (u8 *)s->data + (size - n);
        s->FillData(p, n);
        x = 0;
        for (i = 0; i < n; i++) {
            x ^= p[i];
        }
        data->checksum = x;
    } else {
        data->checksum = 0;
    }
}

static inline BOOL SaveBase_CheckSlot(SaveBase *s, SaveHeader *hdr) {
    SaveSlot *slot;
    u8 cks;
    u32 n;
    u8 x;
    const u8 *p;
    u32 i;
    slot = (SaveSlot *)((u8 *)hdr + (s->curSlot * s->slotSize + 0x14));
    if (slot->size != s->slotSize || (slot->flags & 2)) {
        return FALSE;
    }
    n = s->slotSize - 1;
    if (n != 0) {
        BOOL ok;
        x = 0;
        p = (const u8 *)slot + 1;
        cks = slot->checksum;
        for (i = 0; i < n; i++) {
            x ^= p[i];
        }
        ok = (x ^ cks) == 0;
        if (!ok) {
            return FALSE;
        }
    }
    return TRUE;
}

static inline void SaveBase_LoadPayload(SaveBase *s, u8 *data, u16 off, u16 size) {
    u16 n = size - off;
    if (n != 0) {
        s->LoadData(data + off, n);
    }
}

static inline void SaveBase_LoadData(SaveBase *s) {
    u32 slotSize = s->slotSize;
    u8 *data = (u8 *)s->data;
    if (s->step != 0) {
        return;
    }
    SaveBase_LoadPayload(s, data, slotSize + 4, s->dataSize);
    s->step = 1;
}

static inline BOOL SaveBase_CheckData(SaveBase *s) {
    SaveData *data;
    u32 size;
    u8 cks;
    u32 n;
    u8 x;
    const u8 *p;
    u32 i;
    data = s->data;
    size = s->dataSize;
    if (data->slotIdx != s->curSlot || data->size != size || (data->slot.flags & 2)) {
        return FALSE;
    }
    n = s->slotSize - 1;
    if (n != 0) {
        BOOL ok;
        x = 0;
        p = (const u8 *)&data->slot + 1;
        cks = data->slot.checksum;
        for (i = 0; i < n; i++) {
            x ^= p[i];
        }
        ok = (x ^ cks) == 0;
        if (!ok) {
            return FALSE;
        }
    }
    n = size - (s->slotSize + 4);
    if (n != 0) {
        BOOL ok;
        x = 0;
        p = (const u8 *)data + (size - n);
        cks = data->checksum;
        for (i = 0; i < n; i++) {
            x ^= p[i];
        }
        ok = (x ^ cks) == 0;
        if (!ok) {
            return FALSE;
        }
    }
    return TRUE;
}

}

#endif
