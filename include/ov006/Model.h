#ifndef OV006_MODEL_H
#define OV006_MODEL_H

#include "ov006/ov006.h"

/* A 0x160-byte object built by func_02041440 and torn down by func_02041558. */
typedef struct ov006_ModelRes {
    u8 unk0[4];
    int unk4;
    u8 unk8[4];
    int unkC;
} ov006_ModelRes;

typedef struct ov006_ModelPart {
    u8 unk0[4];
    struct ov006_ModelPartRes *unk4;
    u8 unk8[0x20];
} ov006_ModelPart;

typedef struct ov006_ModelPartRes {
    u8 unk0[0x30];
    void *unk30;
} ov006_ModelPartRes;

typedef struct ov006_ModelPos {
    s32 x;
    s32 y;
} ov006_ModelPos;

typedef struct ov006_Model {
    u8 unk0[0x28];
    ov006_ModelRes *unk28;
    u8 unk2C[0x40];
    u32 unk6C;
    u8 unk70[0x8];
    ov006_ModelPart *parts;
    int unk7C;
    int numParts;
    u8 unk84[0x4];
    u8 unk88[0x74];
    ov006_ModelPos unkFC[4];
    u8 unk11C[0x34];
    int unk150;
    int unk154;
    void *unk158;
    u8 unk15C[0x4];
} ov006_Model;

/* Owns one model (vtable data_ov006_021ec424). */
typedef struct ov006_ModelHolder {
    void *vtbl;
    ov006_Model *model;
    int unk8;
    u8 unkC;
} ov006_ModelHolder;

#ifdef __cplusplus
extern "C" {
#endif

void func_02041558(ov006_Model *self);
void func_02041278(void *self);
void func_02041218(void *self);
void func_02041440(ov006_Model *self, const char *name, int a);
void *STD_CopyString(void *dst, const char *src);
void func_020417e0(ov006_Model *self, void *res);
void func_02041d9c(ov006_Model *self, int a, int b);
void *func_02035de0(const char *a, const char *b);
void *NNS_G2dGetAnimSequenceByIdx(int a, int b);
void *NNS_G2dGetCellDataByIdx(int a, u16 b);
void func_02042628(ov006_Model *model, void *a, ov006_ModelPart *part, u8 b);

#ifdef __cplusplus
}
#endif

typedef struct ov006_Unk02023390 {
    u8 unk0[0xc];
    u16 **unkC;
} ov006_Unk02023390;

static inline void ov006_Model_SetPos(ov006_Model *self, int idx, s32 x, s32 y) {
    self->unkFC[idx].x = x;
    self->unkFC[idx].y = y;
}

static inline ov006_ModelPart *ov006_Model_GetPart(ov006_Model *self, int idx) {
    if (idx >= self->numParts) {
        return NULL;
    }
    return &self->parts[idx];
}

static inline void ov006_Model_PlayPart(ov006_Model *model, int idx) {
    ov006_ModelRes *res = model->unk28;
    ov006_ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov006_Model_GetPart(model, idx);
    if (part != NULL && part->unk4 != NULL) {
        anim = part->unk4->unk30;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->unk4, **((ov006_Unk02023390 *)NNS_G2dGetAnimSequenceByIdx(res->unkC, idx))->unkC);
    }
    func_02042628(model, anim, part, 0);
}

#define OV006_DELETE_MODEL(obj)                                  \
    do {                                                         \
        void *saved_ = data_02097dd0->current;                   \
        data_02097dd0->current = data_02097dd0->unk8;            \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                ov006_Model *m_ = (obj);                         \
                func_02041558(m_);                               \
                func_02041278(m_->unk88);                        \
                func_0203de1c(m_);                               \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->current = saved_;                         \
    } while (0)

#endif
