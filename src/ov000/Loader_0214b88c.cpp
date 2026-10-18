#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u32 unk_00;
    VObj *unk_04;
    VObj *unk_08;
} Data021ccd24;

typedef struct {
    u8 unk_00;
    u8 unk_01[0x3];
    u32 unk_04;
    s32 unk_08;
    u16 unk_0c;
    u8 unk_0e[0x2];
    u32 unk_10;
    void *unk_14;
    u32 unk_18;
    char *unk_1c;
} Loader;

typedef struct {
    u8 unk_00[0x8];
    u32 unk_08;
} Data0202aca0;

typedef struct {
    u32 unk_00;
} Data02034f5c;

extern "C" {

extern HeapState *data_02097dd0;
extern Data021ccd24 data_ov000_021ccd24;
extern void *data_ov000_021c9838;
extern u8 data_0208b318[];
extern u8 data_0208bf54[];
extern const char data_ov000_021ca8f7[];
extern const char data_ov000_021ca8ff[];
extern const char data_ov000_021ca907[];
extern const char data_ov000_021ca917[];

s32 func_0201e708(const char *str);
void *func_0203dddc(u32 size);
void *func_0203dd9c(u32 size);
void func_0201e5a0(char *dst, const char *src, s32 n);
void func_0201e520(char *dst, const char *src);
void func_0201e78c(char *dst, const char *src);
BOOL func_02018d58(void);
void func_020359fc(void *a, char *name, s32 b, s32 c);
BOOL func_02035bd4(void *a, char *name, s32 b);
void *func_02035f30(void *a, char *name, s32 b);
Data02034f5c *func_02034f5c(void *a, char *name);
char *func_0203ed04(char *name, u32 a);
void *func_0203ebf8(char *name);
Data0202aca0 *func_0202aca0(u32 a);
BOOL func_0203e63c(void *a);
void func_0205a6a0(VObj *obj);
void func_0205a840(VObj *obj, char *a, const char *b);
BOOL func_0205a9c8(VObj *obj);
s32 func_0205aa30(VObj *obj);

void func_ov000_0214b88c(Loader *self, const char *name) {
    s32 len = func_0201e708(name);
    self->unk_1c = (char *)func_0203dddc(len + 1);
    func_0201e5a0(self->unk_1c, name, len + 1);
    self->unk_08 = 1;
    self->unk_04 = func_02018d58() ? 0 : 1;
}

BOOL func_ov000_0214b8d8(Loader *self) {
    return self->unk_08 == 2;
}

u32 func_ov000_0214b8ec(Loader *self) {
    return self->unk_10;
}

u8 func_ov000_0214b8f4(Loader *self) {
    if (func_02018d58()) {
        return self->unk_00;
    }
    return 1;
}

void func_ov000_0214b910(Loader *self) {
    Data02034f5c *entry;
    void *data;
    char *name;
    switch (self->unk_0c) {
    case 0:
        func_020359fc(data_ov000_021c9838, self->unk_1c, 5, 0);
        self->unk_0c = 1;
        break;
    case 1:
        if (func_02035bd4(data_ov000_021c9838, self->unk_1c, 5)) {
            self->unk_0c = 2;
        }
        break;
    case 2:
        data = func_02035f30(data_ov000_021c9838, self->unk_1c, 5);
        entry = func_02034f5c(data, self->unk_1c);
        name = self->unk_1c;
        if (entry != NULL) {
            name = func_0203ed04(name, entry->unk_00);
        }
        self->unk_14 = func_0203ebf8(name);
        self->unk_18 = func_0202aca0(entry->unk_00)->unk_08;
        self->unk_0c = 3;
        break;
    case 3:
        if (func_0203e63c(self->unk_14)) {
            self->unk_0c = 4;
        }
        break;
    case 4:
        self->unk_10 = (u16)self->unk_18 << 3;
        self->unk_08 = 2;
        self->unk_0c = 0;
        break;
    }
}

static inline VObj *CreateLoader(void) {
    VObj *obj = (VObj *)func_0203dd9c(0xc4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
        VOBJ_SET_VTABLE(obj, data_0208bf54);
        func_0205a6a0(obj);
    }
    return obj;
}

void func_ov000_0214ba18(void) {
    char path[0x20];
    data_ov000_021ccd24.unk_04 = CreateLoader();
    func_0201e520(path, data_ov000_021ca8f7);
    func_0201e78c(path, data_ov000_021ca8ff);
    func_0205a840(data_ov000_021ccd24.unk_04, path, data_ov000_021ca907);
}

void func_ov000_0214baa8(void) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (data_ov000_021ccd24.unk_04 != NULL) {
        if (data_ov000_021ccd24.unk_04 != NULL) {
            data_ov000_021ccd24.unk_04->vfunc_04();
        }
        data_ov000_021ccd24.unk_04 = NULL;
    }
    data_02097dd0->current = saved;
}

BOOL func_ov000_0214bb04(void) {
    BOOL ret = TRUE;
    if (!func_0205a9c8(data_ov000_021ccd24.unk_04)) {
        ret = FALSE;
    }
    return ret;
}

s32 func_ov000_0214bb2c(void) {
    s32 ret = data_ov000_021ccd24.unk_04->vfunc_34();
    if (ret != 0) {
        return ret;
    }
    return func_0205aa30(data_ov000_021ccd24.unk_04);
}

void func_ov000_0214bb5c(void) {
    data_ov000_021ccd24.unk_04->vfunc_38(1);
}

void func_ov000_0214bb80(void) {
    char path[0x20];
    data_ov000_021ccd24.unk_08 = CreateLoader();
    func_0201e520(path, data_ov000_021ca8f7);
    func_0201e78c(path, data_ov000_021ca8ff);
    func_0205a840(data_ov000_021ccd24.unk_08, path, data_ov000_021ca917);
}

void func_ov000_0214bc10(void) {
    void *saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (data_ov000_021ccd24.unk_08 != NULL) {
        if (data_ov000_021ccd24.unk_08 != NULL) {
            data_ov000_021ccd24.unk_08->vfunc_04();
        }
        data_ov000_021ccd24.unk_08 = NULL;
    }
    data_02097dd0->current = saved;
}

BOOL func_ov000_0214bc6c(void) {
    BOOL ret = TRUE;
    if (!func_0205a9c8(data_ov000_021ccd24.unk_08)) {
        ret = FALSE;
    }
    return ret;
}

s32 func_ov000_0214bc94(void) {
    s32 ret = data_ov000_021ccd24.unk_08->vfunc_34();
    if (ret != 0) {
        return ret;
    }
    return func_0205aa30(data_ov000_021ccd24.unk_08);
}

}
