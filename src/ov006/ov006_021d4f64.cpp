#include "ov006/Tasks.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk02046a50 {
    u8 unk0[4];
    u16 unk4;
} ov006_Unk02046a50;

typedef struct ov006_Model64Obj {
    u8 unk0[0x78];
    VecFx32 trans;
    MtxFx33 rot;
    VecFx32 scale;
} ov006_Model64Obj;

extern "C" {

extern char data_ov006_021ebc0a[];
extern char data_ov006_021ebc1c[];
extern char data_ov006_021ebc60[];
extern void *data_02097e40;

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
ov006_Unk02046a50 *func_02046a50(void *a, int idx);
void func_ov006_021dc054(ov006_Obj58 *a);
void func_ov006_021dc578(ov006_Obj58 *a);
void func_ov006_021e0af4(ov006_Unk68 *self);
void func_ov006_021e0b80(ov006_Unk68 *self);
void func_ov006_021e1af0(ov006_Obj13C *a);
void func_ov006_021e1bb4(ov006_Obj13C *a);
void func_ov000_02190a80(ov006_Model64 *a, int b);
void func_ov000_021903b4(ov006_Model64 *a);
BOOL func_ov006_021d5368(ov006_TaskD37 *self, ov006_Model64 *obj);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021cd580(int a, int b, int c);
void func_ov006_021e4b90(ov006_Unk021ec888 *self);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
void *func_0203de84(u32 size, int align);
void func_02016e28(void *dst, int value, u32 size);
int func_0201ea94(char *dst, u32 size, const char *fmt, ...);
void MIi_CpuClearFast(u32 data, void *destp, u32 size);

static inline void ov006_Window_SetSel(ov006_Window *w, u16 id) {
    int idx = func_ov000_02154b58(w, id);
    VCALL(w, A8, idx);
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, data_ov006_021ebc0a, info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, data_ov006_021ebc1c, info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

void func_ov006_021d4f64(ov006_TaskD37 *self) {
    BOOL done = FALSE;
    if (self->head.unk8 == 0xd && self->head.unkC != 0 && data_ov006_021ec888->unk8 != 9) {
        ov006_Unk02046a50 *p;
        done = TRUE;
        p = func_02046a50(data_02097e40, 0);
        if (self->head.unkC == 2 && self->unk3C == 0x28) {
            self->unk4C = p->unk4;
            if (self->unk4A != self->unk4C) {
                VCALL(self->unk50, A8, func_ov000_02154b58(self->unk50, self->unk4C));
                ov006_TaskD37_Select(self, self->unk4C);
            }
        }
    }
    VCALL(self->unk50, 1C);
    VCALL(self->unk54, 1C);
    func_ov006_021dc054(self->unk58);
    func_ov006_021e0af4(self->unk138);
    func_ov006_021e1af0(self->unk13C);
    VCALL(self->unk5C, 1C);
    func_ov000_02190a80(self->unk64, 0x1000);
    func_ov000_02190a80(self->unk6C, 0x1000);
    func_ov006_021d5368(self, self->unk6C);
    if (!done) {
        return;
    }
    if (self->head.unkC == 1) {
        self->unk48 = self->unk4A;
    }
    func_ov006_021e4a80(data_ov006_021ec888, self->unk44, 2, &self->unk46, 4);
}

void func_ov006_021d513c(ov006_TaskD37 *self) {
    if (self->head.unk8 != 0) {
        return;
    }
    switch (self->unk3C) {
    case 0x6e:
        func_ov006_021cd580(6, 1, self->head.unkC);
        self->unk3C++;
        break;
    case 0x78:
        func_ov006_021cd580(6, 0, self->head.unkC);
        self->unk3C++;
        break;
    case 0x82:
        func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
        self->unk3C++;
        break;
    }
    func_ov006_021e4b90(data_ov006_021ec888);
}

void func_ov006_021d51cc(ov006_TaskD37 *self) {
    if (!VCALL(self, 28)) {
        return;
    }
    func_ov006_021e0b80(self->unk138);
    func_ov006_021e1bb4(self->unk13C);
    func_ov006_021dc578(self->unk58);
    VCALL(self->unk50, 20);
    VCALL(self->unk54, 20);
    VCALL(self->unk5C, 20);
    VCALL(self->unk7C, 00);
    func_ov000_021903b4(self->unk64);
    func_ov000_021903b4(self->unk6C);
    if (data_ov006_021ec888 != NULL) {
        func_ov006_021e463c(data_ov006_021ec888);
    }
}

void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop) {
    void **res;
    char buf[0x10];
    if (self->unk70 == NULL || name == NULL) {
        return;
    }
    if (self->unk74 == NULL) {
        self->unk74 = (ov006_Anm74 *)func_0203de84(0x100, 4);
    }
    res = self->unk70->unk48;
    func_02016e28(buf, 0, sizeof(buf));
    func_0201ea94(buf, sizeof(buf), data_ov006_021ebc60, self->unk70->unk6C, name);
    self->unk74->res = (typeof(self->unk74->res))NNS_G3dGetAnmByName(*res, (const NNSG3dResName *)buf);
    self->unk74->frame = 0;
    self->unk74->speed = 0x1000;
    self->unk74->func = (void *)NNS_G3dFuncAnmJntNsBcaDefault;
    self->unk74->unk10 = 0;
    self->unk74->unk14 = 0;
    self->unk74->unk18 = 0x7f;
    self->unk74->unk19 = 0;
    self->unk78 = loop;
    self->unk7A = speed;
}

BOOL func_ov006_021d5368(ov006_TaskD37 *self, ov006_Model64 *m) {
    BOOL r;
    int end;
    int frame;
    ov006_Anm74 *anm;
    ov006_Model64Obj *obj;
    u32 flag;
    NNSG3dRS rs;
    NNSG3dJntAnmResult result;
    obj = (ov006_Model64Obj *)m;
    if (self->unk74 == NULL) {
        return FALSE;
    }
    r = FALSE;
    NNS_G3dRS = &rs;
    MIi_CpuClearFast(0, &rs, sizeof(rs));
    rs.funcJntScale = NNS_G3dGetJointScale_FuncArray[0];
    NNS_G3dFuncAnmJntNsBcaDefault(&result, (const NNSG3dAnmObj *)self->unk74, 0);
    flag = result.flag;
    if (flag & 2) {
        MTX_Identity33_(&result.rot);
    }
    if (flag & 4) {
        result.trans.x = 0;
        result.trans.y = 0;
        result.trans.z = 0;
    }
    if (flag & 1) {
        result.scale.x = 0x1000;
        result.scale.y = 0x1000;
        result.scale.z = 0x1000;
    }
    obj->scale = result.scale;
    obj->trans = result.trans;
    MI_Copy36B(&result.rot, &obj->rot);
    NNS_G3dRS = NULL;
    anm = self->unk74;
    end = (anm->res->numFrame << 12) - 0x1000;
    frame = anm->frame + self->unk7A;
    if (self->unk78) {
        frame = frame % end;
    } else if (frame >= end) {
        frame = end;
        r = TRUE;
    }
    anm->frame = frame;
    return r;
}

}
