#include "ov000/ModelPart.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
    u8 pad04[0x24];
    Model *model;
} Obj0215e8b0;

extern "C" {

extern void *data_0208cb78;
extern void *data_0208cc9c;
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
void *func_0203dd9c(u32 size);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, void *b);
void STD_CopyString(void *dst, const void *src);
void func_02041c34(Model *m, s32 a, void *cb, void *arg);
void func_ov000_0215e6f0(void);

#define MODEL_NEW(out, NAME, ARC)                    \
    do {                                             \
        Model *m_ = (Model *)func_0203dd9c(0x160);   \
        if (m_) {                                    \
            void *arc_;                              \
            void *name_;                             \
            name_ = NAME;                            \
            arc_ = ARC;                              \
            func_02041218(m_->pltt);                 \
            func_02041440(m_, (const char *)name_, 0); \
            STD_CopyString(m_->name, arc_);          \
        }                                            \
        out = m_;                                    \
    } while (0)

static inline BOOL IsB4(Obj0215e8b0 *self) {
    return self->b4 ? TRUE : FALSE;
}

void func_ov000_0215e8b0(Obj0215e8b0 *self) {
    if (self->model != NULL) {
        return;
    }
    if (self->b3) {
        MODEL_NEW(self->model, data_0208cb78, data_0208cc9c);
        {
            void *a = func_02035d5c(self->model->name);
            void *b = func_02034d88(a, self->model->unk_04c);
            func_020417e0(self->model, b);
        }
        self->model->flags |= 2;
        func_02041d9c(self->model, 0, 0);
    } else {
        if (IsB4(self)) {
            MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
        } else {
            MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
        }
        {
            void *a = func_02035d5c(self->model->name);
            void *b = func_02034d88(a, self->model->unk_04c);
            func_020417e0(self->model, b);
        }
        self->model->flags |= 2;
        func_02041d9c(self->model, 0, 5);
        func_02041c34(self->model, 5, (void *)func_ov000_0215e6f0, self);
    }
    self->model->flags |= 0x80000;
    self->model->flags |= 0x200000;
    MODEL_FLAGS(self->model)->alpha = 0x1e;
}

}
