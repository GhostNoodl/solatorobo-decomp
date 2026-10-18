#include "types.h"

typedef struct {
    void *unk_00;
} ResHandle;

typedef struct {
    ResHandle *handle;
    char name[0x20];
    char ext[0x18];
} ResEntry;

typedef struct {
    s16 unk_00;
    u8 loaded_0 : 1;
    u8 loaded_1 : 1;
    u8 loaded_2 : 1;
    u8 loaded_3 : 1;
    u8 loaded_4 : 1;
    u8 loaded_5 : 1;
    u8 loaded_6 : 2;
    u8 owned_0 : 1;
    u8 owned_1 : 1;
    u8 owned_2 : 1;
    u8 owned_3 : 1;
    u8 owned_4 : 1;
    u8 owned_5 : 3;
    void *unk_04;
    void *unk_08;
    ResEntry entries[5];
} ResSet;

extern "C" {

extern void *data_02097cdc;
extern const char data_ov000_021cc41d[];
extern const char data_ov000_021cc424[];

void func_0203f0b4(void *a);
BOOL func_0203e63c(void *a);
void func_0203e58c(void *a);
void func_02035acc(const char *name, const char *ext, s32 type);
void func_02036838(void *a, const char *name, s32 b, s32 c);
void STD_CopyString(char *dst, const char *src);
void STD_ConcatenateString(char *dst, const char *src);
BOOL func_0201e7b0(const char *a, const char *b);

}

static inline void ResEntry_Init(ResEntry *entry) {
    entry->handle = NULL;
    entry->name[0] = 0;
    entry->ext[0] = 0;
}

static inline void ResSet_Release0(ResSet *self) {
    if (self->entries[0].handle != NULL) {
        func_0203f0b4(self->entries[0].handle->unk_00);
        if (self->unk_04 != NULL && !func_0203e63c(self->unk_04)) {
            func_0203e58c(self->unk_04);
        }
    }
    if (self->loaded_1 && self->owned_1) {
        func_02035acc(self->entries[0].name, self->entries[0].ext, 4);
    }
    self->unk_04 = NULL;
    self->loaded_1 = 0;
    self->entries[0].handle = NULL;
}

static inline void ResSet_Release1(ResSet *self) {
    if (self->loaded_2 && self->owned_2) {
        func_02035acc(self->entries[1].name, self->entries[1].ext, 6);
    }
    self->loaded_2 = 0;
    self->entries[1].handle = NULL;
}

static inline void ResSet_Release3(ResSet *self) {
    char buf[0x18];
    if (self->loaded_4 && self->owned_4) {
        STD_CopyString(buf, self->entries[3].ext);
        STD_ConcatenateString(buf, data_ov000_021cc424);
        func_02035acc(self->entries[3].name, buf, 0);
    }
    self->entries[3].handle = NULL;
    self->loaded_4 = 0;
}

extern "C" {

const char *func_02039674(const char *path);

void func_ov000_0218e9c4(ResSet *self) {
    self->unk_00 = -1;
    *((u8 *)self + 2) = 0;
    *((u8 *)self + 3) = 0;
    self->unk_04 = NULL;
    self->unk_08 = NULL;
    ResEntry_Init(&self->entries[0]);
    ResEntry_Init(&self->entries[1]);
    ResEntry_Init(&self->entries[2]);
    ResEntry_Init(&self->entries[3]);
    ResEntry_Init(&self->entries[4]);
}

ResSet *func_ov000_0218ea20(ResSet *self) {
    char buf2[0x18];
    char buf3[0x18];
    ResSet_Release0(self);
    if (self->loaded_2 && self->owned_2) {
        func_02035acc(self->entries[1].name, self->entries[1].ext, 6);
    }
    self->entries[1].handle = NULL;
    self->loaded_2 = 0;
    if (self->loaded_3 && self->owned_3) {
        STD_CopyString(buf2, self->entries[2].ext);
        STD_ConcatenateString(buf2, data_ov000_021cc41d);
        func_02035acc(self->entries[2].name, buf2, 0);
    }
    self->entries[2].handle = NULL;
    self->loaded_3 = 0;
    if (self->loaded_4 && self->owned_4) {
        STD_CopyString(buf3, self->entries[3].ext);
        STD_ConcatenateString(buf3, data_ov000_021cc424);
        func_02035acc(self->entries[3].name, buf3, 0);
    }
    self->entries[3].handle = NULL;
    self->loaded_4 = 0;
    if (self->entries[4].handle != NULL) {
        func_0203f0b4(self->entries[4].handle->unk_00);
        if (self->unk_08 != NULL && !func_0203e63c(self->unk_08)) {
            func_0203e58c(self->unk_08);
        }
    }
    if (self->loaded_5) {
        func_02036838(data_02097cdc, self->entries[4].name, 7, 0);
    }
    self->unk_08 = NULL;
    self->loaded_5 = 0;
    self->entries[4].handle = NULL;
    if (self->owned_0 && self->loaded_0) {
        func_02036838(data_02097cdc, self->entries[0].name, 7, 0);
    }
    return self;
}

void func_ov000_0218ec60(ResSet *self, const char *name, const char *ext, BOOL owned, u8 force) {
    if (name != NULL && ext != NULL) {
        if (!force && !func_0201e7b0(self->entries[0].name, name) && !func_0201e7b0(self->entries[0].ext, ext)) {
            return;
        }
        ResSet_Release0(self);
        STD_CopyString(self->entries[0].name, name);
        STD_CopyString(self->entries[0].ext, ext);
        if (owned) {
            self->owned_1 = 1;
        }
        self->unk_00 = 0;
    } else {
        ResSet_Release0(self);
        self->entries[0].name[0] = 0;
        self->entries[0].ext[0] = 0;
        self->owned_1 = 0;
    }
}

void func_ov000_0218edf0(ResSet *self, const char *name, const char *ext, BOOL owned, u8 force) {
    if (name != NULL && ext != NULL) {
        if (!force && !func_0201e7b0(self->entries[2].name, name) && !func_0201e7b0(self->entries[1].ext, ext)) {
            return;
        }
        ResSet_Release1(self);
        STD_CopyString(self->entries[1].name, name);
        STD_CopyString(self->entries[1].ext, ext);
        if (owned) {
            self->owned_2 = 1;
        }
        self->unk_00 = 0;
    } else {
        ResSet_Release1(self);
        self->entries[1].name[0] = 0;
        self->entries[1].ext[0] = 0;
        self->owned_2 = 0;
    }
}

void func_ov000_0218ef10(ResSet *self, const char *name, const char *ext, BOOL owned, u8 force) {
    if (name != NULL && ext != NULL) {
        if (!force && !func_0201e7b0(self->entries[3].name, name) && !func_0201e7b0(self->entries[3].ext, ext)) {
            return;
        }
        ResSet_Release3(self);
        STD_CopyString(self->entries[3].name, name);
        STD_CopyString(self->entries[3].ext, ext);
        if (owned) {
            self->owned_4 = 1;
        }
        self->unk_00 = 0;
    } else {
        ResSet_Release3(self);
        self->entries[3].name[0] = 0;
        self->entries[3].ext[0] = 0;
        self->owned_4 = 0;
    }
}

void func_ov000_0218f074(ResSet *self, const char *name, BOOL a, BOOL b, u8 c, u8 d) {
    STD_CopyString(self->entries[0].name, name);
    STD_CopyString(self->entries[0].ext, func_02039674(name));
    self->owned_0 = 1;
    if (a) {
        self->owned_1 = 1;
    }
    if (b) {
        self->owned_2 = 1;
        STD_CopyString(self->entries[1].ext, self->entries[0].ext);
    }
    if (c) {
        self->owned_4 = 1;
    }
    if (d) {
        self->owned_3 = 1;
    }
}

}
