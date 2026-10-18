#include "ov006/ov006.h"

typedef struct ov006_Flagged {
    u8 unk0[0xc];
    u32 flags;
} ov006_Flagged;

typedef struct ov006_TempBuffer {
    u32 unk0;
    u8 data[0x50];
} ov006_TempBuffer;

typedef struct ov006_Unk02097e40 ov006_Unk02097e40;

extern "C" {

extern void *data_ov006_021ec414;
extern ov006_Unk02097e40 *data_02097e40;

BOOL func_ov006_021e46e8(ov006_Unk021ec888 *self, const ov006_MenuData *data);
int func_02046ab4(ov006_Unk02097e40 *a);
BOOL func_020469d4(ov006_Unk02097e40 *a, ov006_MenuEntry *entry);
int func_02046abc(ov006_Unk02097e40 *a);
ov006_MenuEntry *func_02046a50(ov006_Unk02097e40 *a, int idx);
void func_0201a9a8(void *a);
void func_02016fa0(const void *src, void *dst, u32 size);

void func_ov006_021e5e00(ov006_Unk021ec888 *self) {
    ov006_ObjectHolder *holder = self->unk1D8;
    ov006_Flagged *obj;
    if (holder != NULL && (obj = (ov006_Flagged *)holder->obj) != NULL) {
        obj->flags &= ~0x10000;
    }
}

static inline void ov006_ObjectHolder_Dtor(ov006_ObjectHolder *self) {
    self->vtbl = &data_ov006_021ec414;
    OV006_DELETE_OBJECT(self->obj);
}

ov006_ObjectHolder *func_ov006_021e5e20(ov006_ObjectHolder *self) {
    ov006_ObjectHolder_Dtor(self);
    return self;
}

ov006_ObjectHolder *func_ov006_021e5e84(ov006_ObjectHolder *self) {
    ov006_ObjectHolder_Dtor(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov006_021e5ef0(const ov006_MenuData *data) {
    if (data->unk44 != 0x401336) {
        return FALSE;
    }
    return func_ov006_021e46e8(data_ov006_021ec888, data);
}

static inline ov006_MenuEntry *ov006_Menu_GetEntry(ov006_Unk021ec888 *self, u32 idx) {
    return idx < 4 ? &self->entries[idx] : NULL;
}

static inline void ov006_Menu_UpdateConnection(void) {
    ov006_Unk021ec888 *menu = data_ov006_021ec888;
    int status;
    if (menu->unk15F != 0) {
        return;
    }
    if (func_020469d4(data_02097e40, ov006_Menu_GetEntry(menu, func_02046ab4(data_02097e40)))) {
        status = 0;
    } else {
        status = func_02046abc(data_02097e40);
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

void func_ov006_021e5f24(void) {
    data_02097dd0->unk18 = (int)func_ov006_021e5f24;
    ov006_Menu_UpdateConnection();
}

void func_ov006_021e5fec(void) {
    data_02097dd0->unk18 = (int)func_ov006_021e5fec;
    ov006_Menu_UpdateConnection();
}

u32 func_ov006_021e60b4(void *dst, u32 size) {
    ov006_TempBuffer buf;
    func_0201a9a8(&buf);
    func_02016fa0(buf.data, dst, size);
    return size;
}

static inline u16 ov006_Menu_GetEntryMask(int type, u16 mask) {
    u16 result = 0;
    if (data_ov006_021ec888 != NULL) {
        u16 i;
        for (i = 0; i < 4; i++) {
            u16 bit = 1 << i;
            if (mask & bit) {
                ov006_MenuEntry *entry = func_02046a50(data_02097e40, i);
                if (entry != NULL && type == entry->unk0_0) {
                    result |= bit;
                }
            }
        }
    }
    return result;
}

u16 func_ov006_021e60e8(int type, u16 mask) {
    u16 result = 0;
    u16 i;
    if (data_ov006_021ec888 != NULL) {
        for (i = 0; i < 4; i++) {
            u16 bit = 1 << i;
            if (mask & bit) {
                ov006_MenuEntry *entry = func_02046a50(data_02097e40, i);
                if (entry != NULL && type == entry->unk0_0) {
                    result |= bit;
                }
            }
        }
    }
    return result;
}

BOOL func_ov006_021e616c(int type, u16 mask) {
    return mask == ov006_Menu_GetEntryMask(type, mask);
}

void func_ov006_021e61f8(void) {
}

void *func_ov006_021e61fc(void *self) {
    func_0203de1c(self);
    return self;
}

}
