#include "ov000/VObj.h"
#include "nnsys/g3d.h"

typedef struct {
    u8 pad_00[0x28];
    s32 unk_28;
    u8 pad_2c[4];
    s32 unk_30;
} Sub021c9198;

typedef struct {
    u8 pad_00[0x118];
    Sub021c9198 *unk_118;
} Mgr021c9198;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} Bits021c9198;

typedef struct {
    fx32 n;
    fx32 f;
    s16 fovySin;
    s16 fovyCos;
    s16 aspect;
    u16 fovyIdx;
    s32 fovyDeg;
    u8 pad_14[2];
    u8 dirty;
} Persp021c930c;

typedef struct {
    u8 pad_00[0xf8];
    VecFx32 pos;
    VecFx32 target;
    VecFx32 up;
    Persp021c930c persp;
} Cam021c930c;

typedef struct {
    u32 b0 : 1;
} Flags021ccd44;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
} Flags021c930c;

typedef struct {
    u8 pad_00[0x2c];
    s32 unk_2c;
} Obj0218084c;

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021ccc94[];
extern void *data_0208cc94;
extern char data_ov000_021ccc68[];
extern char data_ov000_021ccc72[];
extern char data_ov000_021ccc7e[];
extern u8 data_ov002_021f0f90;
void *func_0203dd9c(u32 size);
void func_02043858(void *p);
void *func_020359d0(void *p, s32 a, s32 b);
void func_020359fc(void *p, void *q, s32 a, s32 b);
BOOL func_02035b90(void *p, s32 a);
BOOL func_02035bd4(void *p, void *q, s32 a);
void func_ov000_02173648(void *self);
extern u8 *data_02149ef0;
extern Mgr021c9198 *data_ov000_021ccd30;
extern u8 *data_02097d48;
// Overlay ids, defined by the linker script.
extern u8 OVERLAY_2_ID[];
extern u8 OVERLAY_3_ID[];
void func_0204b270(void *p, s32 a, s32 b);
void func_ov000_0216f844(void *p, s32 a);
void func_02043904(void *p);
void func_02043b20(void *p);
extern Flags021ccd44 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
extern Cam021c930c *data_ov000_021ccd54;
Obj0218084c *func_ov000_0218084c(void *a, s32 b, s32 c);

VObj *func_ov000_021c9020(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x1c4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021ccc94);
        func_02043858((u8 *)obj + 0x40);
        *(s32 *)((u8 *)obj + 0x3c) = 0;
        *((u8 *)obj + 0x1c0) = 0;
    }
    obj->vfunc_08(0x1a, 0xc8);
    return obj;
}

void func_ov000_021c908c(void) {
    func_020359d0(data_0208cc94, 7, 0);
    func_020359d0(data_ov000_021ccc68, 7, 0);
    func_020359fc(data_ov000_021ccc72, data_ov000_021ccc7e, 2, 0);
}

BOOL func_ov000_021c90e4(void) {
    BOOL ok = func_02035b90(data_0208cc94, 7) ? TRUE : FALSE;
    ok = (ok & func_02035b90(data_ov000_021ccc68, 7)) ? TRUE : FALSE;
    return (ok & func_02035bd4(data_ov000_021ccc72, data_ov000_021ccc7e, 2)) ? TRUE : FALSE;
}

void func_ov000_021c914c(VObj *self) {
    *(u32 *)((u8 *)self + 0x4) &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    *(s32 *)((u8 *)self + 0x20) = 0x1000;
    data_ov002_021f0f90 = 0;
    func_ov000_02173648(self);
}

static inline BOOL SubActive(Sub021c9198 *p) {
    s32 v = 0;
    BOOL r;
    if (p->unk_28 == 1) {
        v = p->unk_30;
    }
    r = TRUE;
    if (v == 0) {
        r = FALSE;
    }
    return r;
}

void func_ov000_021c9198(VObj *self) {
    switch (*(s32 *)((u8 *)self + 0x8)) {
    case 8:
        func_0204b270(data_02149ef0, (s32)OVERLAY_2_ID, 0);
        break;
    case 0xc: {
        u8 *g;
        u8 flag = FALSE;
        func_ov000_0218084c(data_ov000_021ccd44, 0x1b, 0);
        self->vfunc_4c();
        if (data_ov000_021ccd30 != NULL) {
            Sub021c9198 *sub = data_ov000_021ccd30->unk_118;
            if (sub != NULL) {
                flag = SubActive(sub) != FALSE;
            }
            if ((*((u8 *)self + 0x1c0) = flag) != 0 && data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 0);
            }
        }
        g = data_02097d48;
        MIi_CpuCopy32(g + 0x8b0, (u8 *)self + 0x40, 0x180);
        func_02043904(g + 0x8b0);
        ((Bits021c9198 *)(g + 0x8b0))->b4 = 0;
        ((Bits021c9198 *)(g + 0x8b0))->b5 = 1;
        *(vu16 *)0x4000060 &= 0xcfdf;
        func_02043b20(g + 0x8b0);
        break;
    }
    case 0xd:
        if (self->vfunc_54()) {
            *(u32 *)((u8 *)self + 0x4) |= 2;
            self->vfunc_0c(0);
        }
        break;
    }
}

void func_ov000_021c930c(VObj *self) {
    u8 *g;
    Cam021c930c *cam;
    if (*(s32 *)((u8 *)self + 0x8) != 0) {
        return;
    }
    if (!((Flags021c930c *)((u8 *)self + 0x4))->b2) {
        return;
    }
    func_ov000_0218084c(data_ov000_021ccd44, *(s32 *)((u8 *)self + 0x3c), 0)->unk_2c = 0;
    data_ov000_021ccd34 = 1;
    data_ov000_021ccd44->b0 = 0;
    if (*((u8 *)self + 0x1c0) && data_ov000_021ccd30->unk_118 != NULL) {
        func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
    }
    g = data_02097d48;
    MIi_CpuCopy32((u8 *)self + 0x40, g + 0x8b0, 0x180);
    func_02043b20(g + 0x8b0);
    cam = data_ov000_021ccd54;
    if (cam != NULL) {
        Persp021c930c *p = &cam->persp;
        u16 idx;
        NNS_G3dGlbLookAt(&cam->pos, &cam->up, &cam->target);
        p->fovyIdx = (u16)(((s64)p->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
        idx = (u16)(p->fovyIdx >> 1);
        p->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
        p->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
        p->dirty = 1;
        if (p->dirty == 1) {
            NNS_G3dGlbPerspectiveW(p->fovySin, p->fovyCos, p->aspect, p->n, p->f, 0x1000);
            p->dirty = 0;
        }
    }
    if (*(s32 *)((u8 *)self + 0x3c) == 2) {
        func_0204b270(data_02149ef0, (s32)OVERLAY_3_ID, 0);
    }
}

}
