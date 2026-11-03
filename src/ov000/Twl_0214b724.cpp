#include "ov000/HeapScope.h"
#include "ov000/TwlRequest.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    s32 unk_04;
    s32 unk_08;
    u16 unk_0c;
    u32 unk_10;
    void *unk_14;
    u32 unk_18;
    char *unk_1c;
    Twl0214b570 unk_20;
} TwlLoader;

typedef struct {
    void *unk_00;
} Data02034f5c;

extern "C" {

BOOL OS_IsRunOnTwl(void);
BOOL Vram_IsTransferDone(void *a);
void *ResMgr_GetArchiveList(void *a, char *name, s32 b);
Data02034f5c *ResList_FindType5(void *a, char *name);
void Vram_FreeRes(void *p);
void ResMgr_ReleaseArchive(void *a, char *name, s32 b);
void Heap_FreeArray(void *p);
void func_ov000_0214b910(TwlLoader *self);

extern void *data_ov000_021c9838;

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
void func_0222e784(TwlLoader *self);
void func_0222e7ec(TwlLoader *self);
void func_0222e6d0(Twl0214b570 *self);
void func_0222e2a4(Twl0214b570 *self);

static inline Twl0214b570 *Twl0214b570_dtor(Twl0214b570 *self) {
    if (OS_IsRunOnTwl()) {
        func_0222e6d0(self);
    }
    return self;
}

static inline void Twl0214b570_update(Twl0214b570 *self) {
    if (!OS_IsRunOnTwl()) {
        return;
    }
    if (self->state != 1) {
        return;
    }
    func_0222e2a4(self);
}

#pragma force_active on

TwlLoader *TwlLoader_Unload(TwlLoader *self) {
    if (self->unk_08 != 0) {
        switch (self->unk_04) {
        case 0:
            func_0222e784(self);
            break;
        case 1:
            if (self->unk_14 != NULL && Vram_IsTransferDone(self->unk_14)) {
                void *a = data_ov000_021c9838;
                void *d = ResMgr_GetArchiveList(a, self->unk_1c, 5);
                Vram_FreeRes(ResList_FindType5(d, self->unk_1c)->unk_00);
                ResMgr_ReleaseArchive(a, self->unk_1c, 5);
            }
            break;
        }
        self->unk_08 = 0;
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_1c != NULL) {
            Heap_FreeArray(self->unk_1c);
            self->unk_1c = NULL;
        }
        gSysState->cur = saved;
    }
    Twl0214b570_dtor(&self->unk_20);
    return self;
}

void TwlLoader_Load(TwlLoader *self) {
    if (self->unk_08 == 1) {
        switch (self->unk_04) {
        case 0:
            func_0222e7ec(self);
            if (self->unk_02) {
                self->unk_08 = 1;
                self->unk_0c = 0;
                self->unk_04 = 1;
            }
            break;
        case 1:
            func_ov000_0214b910(self);
            break;
        }
    }
    Twl0214b570_update(&self->unk_20);
}

#pragma force_active reset

}
