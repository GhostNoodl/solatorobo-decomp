#include "ov006/SlotManager.h"
#include "nitro/fx.h"

typedef struct ov006_Work021e742c {
    u8 unk0[4];
    int unk4;
    int unk8;
    u8 unkC[7];
    u8 kind;
} ov006_Work021e742c;

typedef struct ov006_Cam021e742c {
    u8 unk0[0x1cd];
    u8 unk1CD;
    u8 unk1CE_0 : 1;
    u8 unk1CE_1 : 1;
    u8 unk1CE_2 : 2;
    u8 unk1CE_4 : 4;
    u8 unk1CF;
    VecFx32 unk1D0;
    VecFx32 unk1DC;
    fx32 unk1E8;
} ov006_Cam021e742c;

typedef struct ov006_Pad021e742c {
    u8 unk0[0xa];
    u16 unkA;
} ov006_Pad021e742c;

class ov006_Prop021e742c {
public:
    u8 unk0[0x40];
    ov006_Work021e742c *work;
    u8 unk44[0x20];
    fx32 unk64;
    fx32 unk68;
    u8 unk6C[4];
    VecFx32 pos;
    u8 unk7C[2];
    u16 unk7E;
    u8 unk80[0x118];
    void *unk198;
    u16 unk19C_0 : 13;
    u16 unk19C_13 : 1;
    u16 unk19C_14 : 2;
    u8 unk19E;
    u8 unk19F;
};

typedef void (ov006_Prop021e742c::*ov006_Prop021e742cFn)();

typedef struct ov006_Entry021e742c {
    u32 kind;
    ov006_Prop021e742cFn fn;
} ov006_Entry021e742c;

extern "C" {

extern const ov006_Entry021e742c data_ov006_021eb930[];
extern const VecFx32 data_ov006_021eb8c8;
extern ov006_Cam021e742c *data_ov000_021ccd54;
extern ov006_Pad021e742c *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern const MtxFx43 data_02092844;
extern const MtxFx44 data_02092800;

void func_ov006_021dccc8(void *out, const VecFx32 *pos, const MtxFx43 *cam, const MtxFx44 *proj, u8 flag);
void func_ov006_021dc9c8(void *self);
void func_ov006_021e9f80(ov006_Prop021e742c *self);
void func_ov006_021e7fe4(ov006_Prop021e742c *self);
void func_ov006_021e76d8(ov006_Prop021e742c *self);
void func_ov000_0218c208(void *a, const VecFx32 *pos, u16 rot);

static inline BOOL ov006_Prop021e742c_IsOver(ov006_Prop021e742c *self) {
    BOOL result = FALSE;
    if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
        result = TRUE;
    }
    return result;
}

static inline void ov006_Prop021e742c_Dispatch(ov006_Prop021e742c *self, u32 kind) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (data_ov006_021eb930[i].kind != kind) {
            continue;
        }
        (self->*data_ov006_021eb930[i].fn)();
        return;
    }
}

void func_ov006_021e742c(ov006_Prop021e742c *self) {
    BOOL was;
    VecFx32 p;
    ov006_Prop021e742c_Dispatch(self, self->work->kind);
    was = self->unk19C_13;
    self->unk19C_13 = 0;
    if (self->unk19E == data_ov006_021ec884->unk5) {
        ov006_Cam021e742c *cam = data_ov000_021ccd54;
        if (cam->unk1CD == 0) {
            VecFx32 v = data_ov006_021eb8c8;
            cam->unk1D0 = v;
            cam->unk1CE_0 = 1;
            cam->unk1E8 = (self->unk64 << 2) + 0x5ccd + self->unk64;
            cam->unk1CE_2 = 1;
            cam->unk1DC = self->pos;
            cam->unk1CE_1 = 1;
        }
        if (data_ov006_021ec860->unk1C != 0 && data_ov006_021ec884->unk13D == 0 && !ov006_Prop021e742c_IsOver(self)) {
            u16 k = data_ov000_021ccd68->unkA & 0x7f;
            if (k <= 0x3f && (k & 0xf) <= 0xc) {
                self->unk19C_13 = 1;
            }
        }
    } else if (data_ov006_021ec884->unk13D == 0 && !ov006_Prop021e742c_IsOver(self)) {
        self->unk19C_13 = 1;
    }
    if (self->unk19C_13) {
        p = self->pos;
        p.y += self->unk68;
        {
            u8 flag = FALSE;
            if (!was) {
                flag = TRUE;
            }
            func_ov006_021dccc8(self->unk198, &p, &data_02092844, &data_02092800, flag);
        }
        func_ov006_021dc9c8(self->unk198);
    }
    func_ov006_021e9f80(self);
    func_ov006_021e7fe4(self);
    func_ov006_021e76d8(self);
    func_ov000_0218c208(data_ov000_021ccd64, &self->pos, self->unk7E);
    {
        ov006_Work021e742c *w = self->work;
        w->unk4 = 0;
        w->unk8 = 0;
    }
}

}
