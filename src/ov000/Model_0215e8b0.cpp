#include "ov000/ModelPart.h"

#ifdef NONMATCHING
// func_ov000_0215e6f0 (0x1c0 bytes, the OAM callback that func_ov000_0215e8b0 registers with type 5):
// 11 / 0 (raw / register-masked). This file starts at 0x0215e8b0; the function fills the gap after
// Obj_0215e5f8.c, so it goes at the top of this file once it matches. It is C++ (as C the BOOL test is
// 97 / 97). The miss: in the four-entry branch the 0xfe00ffff x mask (node 170, created after codegen) is
// sl and the shifted x (nodes 62, 64) lr; the ROM has them the other way round. Round qpH's restricted
// ramerge pairs search: 62 and 64 must both be numbered below about 58 or above 170, never one alone.
// The older 9 / 0 draft (cmA/o/r3/e6f0/best.cpp) gets there with a no-op (int) cast on one argument.
// Tried, all 11 / 0 or worse: x - 0x80 split into its own statement in SetPos, a u16/u32 local there, a
// u16 sx assigned in each branch (it becomes a dead @ object), a BOOL local for the test, x read in two
// statements (107), pal read later (23 / 9), a p = pal + b1 local (11 or 98), loops for the entries (106+).
typedef struct OamEntry0215e6f0 {
    u32 y : 8;
    u32 unk_00_8 : 8;
    u32 x : 9;
    u32 unk_00_25 : 7;
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 unk_04_16 : 16;
} OamEntry0215e6f0;

typedef struct Obj0215e6f0 {
    u32 b0 : 1;
    u32 b1 : 2;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 27;
    u8 pad_04[0xc];
    s32 unk_10;
} Obj0215e6f0;

typedef struct Req0215e6f0 {
    u16 type;
    u8 pad_02[6];
    Obj0215e6f0 *obj;
} Req0215e6f0;

extern "C" {

static inline void SetPos0215e6f0(OamEntry0215e6f0 *e, s32 x, s32 y) {
    e->x = (u16)(x - 0x80);
    e->y = y;
}

OamEntry0215e6f0 *func_ov000_0215e6f0(void *self, Req0215e6f0 *req, OamEntry0215e6f0 *buf, u16 *count) {
    u16 n = *count;
    Obj0215e6f0 *o = req->obj;
    OamEntry0215e6f0 *e = &buf[n - 1];
    u32 pal = e->pal;
    s32 x = (o->unk_10 >> 12) - 8;
    if (o->b4 ? TRUE : FALSE) {
        SetPos0215e6f0(&buf[0], x, 0xa0);
        SetPos0215e6f0(&buf[1], x, 0xb0);
        SetPos0215e6f0(&buf[2], 0, 0xa0);
        SetPos0215e6f0(&buf[3], 0, 0xb0);
        buf[0].pal = buf[1].pal = buf[2].pal = buf[3].pal = pal + o->b1;
    } else {
        SetPos0215e6f0(&buf[0], x, 0xa1);
        SetPos0215e6f0(&buf[1], 0, 0xa0);
        buf[0].pal = buf[1].pal = pal + o->b1;
    }
    *count = n;
    return buf;
}

}
#endif

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
struct Req0215e6f0;
struct OamEntry0215e6f0;
struct OamEntry0215e6f0 *func_ov000_0215e6f0(void *self, struct Req0215e6f0 *req, struct OamEntry0215e6f0 *buf, u16 *count);

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
