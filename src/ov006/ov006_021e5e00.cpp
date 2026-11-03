#include "ov006/ov006.h"
#include "ov000/ObjLayouts.h"
#include "nitro/mi.h"

typedef struct ov006_TempBuffer {
    u32 unk0;
    u8 data[0x50];
} ov006_TempBuffer;

typedef struct ov006_Unk02097e40 ov006_Unk02097e40;

extern "C" {

extern void *ov006_ObjectHolder_vtbl;
extern ov006_Unk02097e40 *gWhMgr;

BOOL ov006_Menu_UpdateNode(ov006_Menu *self, const ov006_MenuData *data);
u16 func_02046ab4(ov006_Unk02097e40 *a);
BOOL func_020469d4(ov006_Unk02097e40 *a, ov006_MenuEntry *entry);
int Wh_GetError(ov006_Unk02097e40 *a);
ov006_MenuEntry *Wh_GetSharedData(ov006_Unk02097e40 *a, int idx);
void OS_GetOwnerInfo(void *a);

void ov006_Menu_ShowObj(ov006_Menu *self) {
    ov006_ObjectHolder *holder = self->unk1D8;
    Lo021cad50 *obj;
    if (holder != NULL && (obj = holder->obj) != NULL) {
        obj->flags &= ~0x10000;
    }
}

static inline void ov006_ObjectHolder_Dtor(ov006_ObjectHolder *self) {
    self->vtbl = &ov006_ObjectHolder_vtbl;
    OV006_DELETE_OBJECT(self->obj);
}

ov006_ObjectHolder *ov006_ObjectHolder_Dtor_021e5e20(ov006_ObjectHolder *self) {
    ov006_ObjectHolder_Dtor(self);
    return self;
}

ov006_ObjectHolder *ov006_ObjectHolder_DtorDelete(ov006_ObjectHolder *self) {
    ov006_ObjectHolder_Dtor(self);
    Heap_Free(self);
    return self;
}

BOOL ov006_Menu_ReceiveData(const ov006_MenuData *data) {
    if (data->unk44 != 0x401336) {
        return FALSE;
    }
    return ov006_Menu_UpdateNode(data_ov006_021ec888, data);
}

static inline ov006_MenuEntry *ov006_Menu_GetEntry(ov006_Menu *self, u32 idx) {
    return idx < 4 ? &self->entries[idx] : NULL;
}

static inline void ov006_Menu_UpdateConnection(void) {
    ov006_Menu *menu = data_ov006_021ec888;
    int status;
    if (menu->unk15F != 0) {
        return;
    }
    if (func_020469d4(gWhMgr, ov006_Menu_GetEntry(menu, func_02046ab4(gWhMgr)))) {
        status = 0;
    } else {
        status = Wh_GetError(gWhMgr);
    }
    if (status == 0) {
        data_ov006_021ec888->unk15F = data_ov006_021ec888->unk15E;
        data_ov006_021ec888->unk160 = 0x14;
    } else if (status == 5) {
        if (data_ov006_021ec888->unk160 != 0) {
            data_ov006_021ec888->unk160--;
        }
    }
}

void ov006_Menu_VBlankA(void) {
    gSysState->vblankFunc = ov006_Menu_VBlankA;
    ov006_Menu_UpdateConnection();
}

void ov006_Menu_VBlankB(void) {
    gSysState->vblankFunc = ov006_Menu_VBlankB;
    ov006_Menu_UpdateConnection();
}

u32 ov006_CopyOwnerInfo(void *dst, u32 size) {
    ov006_TempBuffer buf;
    OS_GetOwnerInfo(&buf);
    MI_CpuCopy8(buf.data, dst, size);
    return size;
}

static inline u16 ov006_Menu_GetEntryMask(int type, u16 mask) {
    u16 result = 0;
    if (data_ov006_021ec888 != NULL) {
        u16 i;
        for (i = 0; i < 4; i++) {
            u16 bit = 1 << i;
            if (mask & bit) {
                ov006_MenuEntry *entry = Wh_GetSharedData(gWhMgr, i);
                if (entry != NULL && type == entry->unk0_0) {
                    result |= bit;
                }
            }
        }
    }
    return result;
}

u16 ov006_Menu_GetEntryMask_021e60e8(int type, u16 mask) {
    u16 result = 0;
    u16 i;
    if (data_ov006_021ec888 != NULL) {
        for (i = 0; i < 4; i++) {
            u16 bit = 1 << i;
            if (mask & bit) {
                ov006_MenuEntry *entry = Wh_GetSharedData(gWhMgr, i);
                if (entry != NULL && type == entry->unk0_0) {
                    result |= bit;
                }
            }
        }
    }
    return result;
}

BOOL ov006_Menu_AllEntriesMatch(int type, u16 mask) {
    return mask == ov006_Menu_GetEntryMask(type, mask);
}

void ov006_MenuNode_Dtor(void) {
}

void *Ov006Vt_021ec444_DtorDelete(void *self) {
    Heap_Free(self);
    return self;
}

}
