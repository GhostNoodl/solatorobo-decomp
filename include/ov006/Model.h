#ifndef OV006_MODEL_H
#define OV006_MODEL_H

#include "ov006/ov006.h"
#include "ov000/ModelPart.h"

/* Owns one model (vtable ov006_ModelHolder_vtbl). */
typedef struct ov006_ModelHolder {
    void *vtbl;
    Model *model;
    int unk8;
    u8 unkC;
} ov006_ModelHolder;

#ifdef __cplusplus
extern "C" {
#endif

void *func_02035de0(const char *a, const char *b);

#ifdef __cplusplus
}
#endif

typedef struct ov006_Unk02023390 {
    u8 unk0[0xc];
    u16 **unkC;
} ov006_Unk02023390;

static inline void ov006_Model_SetPos(Model *self, int idx, s32 x, s32 y) {
    self->pos[idx].x = x;
    self->pos[idx].y = y;
}

#define OV006_DELETE_MODEL(obj)                                  \
    do {                                                         \
        void *saved_ = gSysState->cur;                       \
        gSysState->cur = gSysState->heapHi;              \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                Model *m_ = (obj);                               \
                TexObj_Release(m_);                               \
                PlttRes_Release(&m_->pltt);                        \
                Heap_Free(m_);                                   \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        gSysState->cur = saved_;                             \
    } while (0)

#endif
