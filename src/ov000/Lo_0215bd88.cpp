#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void *STD_CopyString(void *dst, void *src);
VObj *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    func_02041218((struct PlttRes *)(m + 0x88));
    func_02041440(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

class Model {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Model(void *nm, void *s) {
        func_02041218((struct PlttRes *)(data + 0x88));
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

void func_ov000_0215bd88(Lo021cadcc *self) {
    self->height = self->vfunc_44();
    if ((s32)self->title != 0 && (u8 *)self->model == NULL) {
        if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
            self->model = new Model(data_0208cb84, data_0208cc8c);
        } else {
            self->model = new Model(data_0208cb74, data_0208cca0);
        }
        {
            void *a = func_02035d5c((u8 *)self->model + 0x2c);
            func_020417e0((u8 *)self->model, func_02034d88(a, (u8 *)self->model + 0x4c));
        }
        LFLD(u32, self->model, 0x6c) |= 2;
        func_02041d9c((u8 *)self->model, 0, 7);
    }
    if (self->flags & 0x10000) {
        self->posX = (0x100 - self->width) >> 1;
    }
    if (self->flags & 0x20000) {
        self->posY = (0xc0 - self->height) >> 1;
    }
    LBIT(self, 0xc).b0 = 1;
}

}
