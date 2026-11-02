#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

extern char data_ov002_021effec[];
extern char data_ov002_021efff8[];
void *func_020360b8(void *a, void *b);
void func_02041c5c(Model *m, void *fn);
void func_02041c18(Model *m, u8 a);
void func_ov002_021e331c(Obj021f002c *self);
void *func_ov002_021e2f04(Model *self, void *unused, u8 *entries, u16 *count);

static inline BOOL ov002_021e2fb4_flag2(Ov002Text2 *o) {
    return o->unk_4_2 ? TRUE : FALSE;
}

void func_ov002_021e2fb4(Obj021f002c *self) {
    switch (self->state) {
    case 0:
        if (self->hasModel) {
            Model *m = (Model *)Heap_Alloc(sizeof(Model));
            u8 *info;
            if (m != NULL) {
                char *nm = data_ov002_021effec;
                char *file = data_ov002_021efff8;
                if (nm) {
                    func_02041218(&m->pltt);
                    func_02041440(m, nm, 0);
                    STD_CopyString(m->name, file);
                }
            }
            self->model = m;
            func_020417e0(self->model, func_020360b8(data_ov002_021efff8, data_ov002_021effec));
            self->model->flags |= 2;
            self->model->flags |= 0x80000;
            self->model->flags |= 0x100000;
            self->model->flags |= 0x200000;
            func_02041c5c(self->model, (void *)func_ov002_021e2f04);
            info = func_0206ede8(self->id);
            self->part = func_02070dcc(info[1])->unk_4;
            func_02041c18(self->model, info[0]);
            func_02041d9c(self->model, 0, self->part);
            MODEL_FLAGS(self->model)->alpha = 0x1e;
        }
        func_ov002_021e331c(self);
        self->state = 1;
        break;
    case 1: {
        Ov002Text2 *o;
        if (self->shown) {
            return;
        }
        o = self->text;
        if (ov002_021e2fb4_flag2(o)) {
            o->vfunc_08();
            self->text->flags &= ~4;
        }
        {
            void *saved;
            HEAP_PUSH(saved);
            {
                Model *p = self->model;
                if (p != NULL) {
                    if (p != NULL) {
                        func_02041558(p);
                        func_02041278(&p->pltt);
                        Heap_Free(p);
                    }
                    self->model = NULL;
                }
            }
            HEAP_POP(saved);
        }
        {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(self->text);
            HEAP_POP(saved);
        }
        self->state = 2;
        break;
    }
    case 2:
        if (self->shown) {
            self->state = 0;
        }
        break;
    }
}

}
