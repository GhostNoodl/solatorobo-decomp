#include "ov000/CmdObj.h"
#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[8];
    void (*unk_08)(void);
    void (*unk_0c)(void);
    void (*unk_10)(void);
} Data021ccd50;

typedef struct {
    u32 b0 : 1;
} Ov002Obj021f0f80;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
} Ov008Obj021d0500;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Ov002Obj021f0f80 *data_ov002_021f0f80;
extern Ov008Obj021d0500 *data_ov008_021d0500;
extern u8 *data_02149ef0;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_8_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void func_ov002_021ccda0(void);
void func_ov008_021cd448(void);
void func_ov000_021865bc(void);
void func_ov000_021865c8(void);
void func_ov000_021865e0(void);
void func_ov000_02186b74(void);
void func_ov000_02186b80(void);
void func_ov000_02186b98(void);

static inline BOOL Ov002Flag(Ov002Obj021f0f80 *p) {
    return p->b0 ? TRUE : FALSE;
}

static inline BOOL Ov002Done(void) {
    BOOL r;
    Ov002Obj021f0f80 *p = data_ov002_021f0f80;
    if (p != NULL) {
        r = Ov002Flag(p) ? TRUE : FALSE;
    } else {
        r = TRUE;
    }
    return r;
}

static inline void ClearCallbacks(void) {
    if (data_ov000_021ccd50.unk_0c != NULL) {
        data_ov000_021ccd50.unk_0c();
    }
    data_ov000_021ccd50.unk_0c = NULL;
    data_ov000_021ccd50.unk_08 = NULL;
    data_ov000_021ccd50.unk_10 = NULL;
}

s32 func_ov000_02186c88(CmdObj *self) {
    switch (self->step) {
    case 0:
        data_ov000_021ccd50.unk_0c = func_ov000_02186b74;
        data_ov000_021ccd50.unk_08 = func_ov000_02186b80;
        data_ov000_021ccd50.unk_10 = func_ov000_02186b98;
        func_0204b270(data_02149ef0, (s32)OVERLAY_8_ID, 0);
        func_ov008_021cd448();
        self->step++;
        return 0;
    case 1:
        if ((data_ov008_021d0500->unk_04 == 0 ? TRUE : FALSE)) {
            ClearCallbacks();
            CmdObj_Done(self);
        }
        break;
    }
    return 0;
}
}
