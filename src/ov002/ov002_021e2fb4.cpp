#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

extern char data_ov002_021effec[];
extern char data_ov002_021efff8[];
void *func_020360b8(void *a, void *b);
void TexObj_SetAllOamFuncs(Model *m, void *fn);
void func_02041c18(Model *m, u8 a);
void Obj021f002c_CreateText(Obj021f002c *self);
void *func_ov002_021e2f04(Model *self, void *unused, u8 *entries, u16 *count);

static inline BOOL ov002_021e2fb4_flag2(Ov002Text2 *o) {
    return o->unk_4_2 ? TRUE : FALSE;
}

void Obj021f002c_Update(Obj021f002c *self) {
    switch (self->state) {
    case 0:
        if (self->hasModel) {
            Model *m = (Model *)Heap_Alloc(sizeof(Model));
            u8 *info;
            if (m != NULL) {
                char *nm = data_ov002_021effec;
                char *file = data_ov002_021efff8;
                if (nm) {
                    PlttRes_Init_02041218(&m->pltt);
                    TexObj_Init(m, nm, 0);
                    STD_CopyString(m->name, file);
                }
            }
            self->model = m;
            TexObj_SetRes(self->model, func_020360b8(data_ov002_021efff8, data_ov002_021effec));
            self->model->flags |= 2;
            self->model->flags |= 0x80000;
            self->model->flags |= 0x100000;
            self->model->flags |= 0x200000;
            TexObj_SetAllOamFuncs(self->model, (void *)func_ov002_021e2f04);
            info = Param_GetEntry(self->id);
            self->part = ParamKind_GetShape(info[1])->unk_4;
            func_02041c18(self->model, info[0]);
            TexObj_SelectImage(self->model, 0, self->part);
            MODEL_FLAGS(self->model)->alpha = 0x1e;
        }
        Obj021f002c_CreateText(self);
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
                        TexObj_Release(p);
                        PlttRes_Release(&p->pltt);
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
