#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "Main/Sys/Pad.h"

extern "C" {
extern MessageQueue021cb980 *gMessageQueue;
extern char *data_ov000_021cc858;
extern char data_ov000_021cc894[];
extern void *gSndMgr;
extern const s16 FX_SinCosTable_[];
void LangData_LocalizePath(char *dst, const char *src);
void MissionInfo_CreateBackButton(u8 *self);
BOOL Model_IsReady(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov000_02165da0(void *p);
BOOL func_ov000_02165df4(void *p);
void Lo021cb6b0_FreeAnim(void *p);

static inline void *Get021bb8dc(void) {
    TimedBuffer021cb920 *p = gMessageQueue->unk_118;
    if (p == NULL) {
        return NULL;
    }
    if (((s32)p->unk_28) != 1) {
        return NULL;
    }
    return p->unk_30;
}

struct Obj021bb8dc {
    u8 unk_00[0x48];
    s32 unk_48;
    u8 unk_4c[0x4];
    s32 unk_50;
    s16 unk_54;
    u8 unk_56[0x2];
    void *unk_58;
    VObj *unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
};

static inline BOOL Ready021bb8dc(Obj021bb8dc *self) {
    BOOL ok = TRUE;
    if (!((VObj *)((u8 *)self + 4))->vfunc_2c()) {
        ok = FALSE;
    }
    return ok;
}

BOOL MissionInfo_Update(Obj021bb8dc *self) {
    s32 t;
    void *p = Get021bb8dc();

    switch (self->unk_50) {
    case 1: {
        char buf[0x20];
        LangData_LocalizePath(buf, data_ov000_021cc858);
        self->unk_48 = 2;
        ((VObj *)((u8 *)self + 4))->vfunc_24(buf, data_ov000_021cc894);
        self->unk_50 = 2;
    }
    case 2:
        if (!Ready021bb8dc(self)) {
            break;
        }
        self->unk_50 = 4;
    case 4:
        MissionInfo_CreateBackButton((u8 *)self);
        self->unk_50 = 10;
    case 10:
        if (!Model_IsReady(self->unk_58, 0xffff)) {
            break;
        }
        self->unk_50 = 6;
    case 6:
        self->unk_64 += 0x1000;
        t = FX_Div(self->unk_64, 0x1e000);
        if (t > 0x1000) {
            self->unk_50 = 11;
            self->unk_64 = 0x1e000;
            t = 0x1000;
            if ((void *)self->unk_5c != NULL) {
                LFLD(u32, self->unk_5c, 0xc) &= ~2;
            }
        }
        self->unk_68 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 11:
        if (gPad->trig & 2) {
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
            self->unk_50 = 12;
            break;
        }
        switch (self->unk_54) {
        case 0:
            if (++self->unk_6c > 0x3c) {
                func_ov000_02165da0(p);
                self->unk_54 = 10;
            }
            break;
        case 10:
            if (func_ov000_02165df4(p)) {
                self->unk_6c = 0;
                self->unk_54 = 20;
            }
            break;
        case 20:
            if (++self->unk_6c > 0x78) {
                self->unk_6c = 0;
                self->unk_54 = 100;
            }
            break;
        case 100:
            self->unk_50 = 12;
            break;
        }
        break;
    case 12:
        Lo021cb6b0_FreeAnim(p);
        if ((void *)self->unk_5c != NULL) {
            LFLD(u32, self->unk_5c, 0xc) |= 2;
        }
        self->unk_50 = 13;
    case 13:
        self->unk_64 -= 0x1000;
        t = FX_Div(self->unk_64, 0x1e000);
        if (t <= 0) {
            t = 0;
            self->unk_64 = 0;
            self->unk_50 = 17;
        }
        self->unk_68 = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 17:
        return FALSE;
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_1c();
    }
    self->unk_60 += 0x1000;
    if (self->unk_60 < 0) {
        self->unk_60 -= (s32)0x80000001;
    }
    return TRUE;
}
}
