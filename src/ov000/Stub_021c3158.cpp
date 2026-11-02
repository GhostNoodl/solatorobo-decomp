#include "types.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ListRow.h"


extern "C" {

extern char data_ov000_021cc9d3[];
extern char data_ov000_021cc9dc[];
void func_ov000_021c8408(void *self, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);
void func_ov000_021c2f90(ListRow021cca70 *self);
BOOL func_02054f10(void *m, u32 a);
void func_020359fc(const char *arc, const char *name, s32 a, s32 b);
BOOL func_02035bd4(const char *arc, const char *name, s32 a);
void *func_02035f30(const char *arc, const char *name, s32 a);
void *func_02034d88(void *a, const char *name);
void *Heap_Alloc(u32 size);
s32 FX_Div(s32 n, s32 d);
s32 Interp_SinLerp(s32 t, s32 a, s32 b);

static inline char *ObjName021c3158(ListRow021cca70 *o) {
    return o->name;
}

static inline void *LoadObjRes021c3158(ListRow021cca70 *o) {
    return func_02035f30(o->arc, o->name, 2);
}

static inline Model *NewModel021c3158(char *arc, const char *name) {
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        func_02041218(&m->pltt);
        func_02041440(m, name, 0);
        STD_CopyString((char *)m + 0x2c, arc);
    }
    return m;
}

static inline Model *NewModelObj021c3158(ListRow021cca70 *self) {
    char *arc;
    Model *m;
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        const char *name = ObjName021c3158(self);
        arc = self->arc;
        func_02041218(&m->pltt);
        func_02041440(m, name, 0);
        STD_CopyString((char *)m + 0x2c, arc);
    }
    return m;
}

void func_ov000_021c3158(ListRow021cca70 *self) {
    if (self->unk_68 != 0 && !self->shown) {
        if (self->unk_38 == NULL) {
            return;
        }
        if (!func_02054f10(self->unk_38, 0xffff)) {
            return;
        }
        func_ov000_021c2f90(self);
        self->unk_68 = 0;
        return;
    }
    switch (self->unk_68) {
    case 0:
        if (!self->shown) {
            return;
        }
        self->unk_68 = 10;
    case 10:
        self->ox = 0;
        self->oy = 0;
        func_020359fc(self->arc, self->name, 2, 0);
        func_020359fc(data_ov000_021cc9d3, data_ov000_021cc9dc, 2, 0);
        self->unk_68++;
        return;
    case 11:
        if (!func_02035bd4(self->arc, self->name, 2)) {
            return;
        }
        if (!func_02035bd4(data_ov000_021cc9d3, data_ov000_021cc9dc, 2)) {
            return;
        }
        self->unk_68 = 20;
    case 20: {
        s32 i;
        s32 n;
        s32 mask;
        {
            Model *m_0;
            void *res_0 = LoadObjRes021c3158(self);
            res_0 = func_02034d88(res_0, self->name);
            m_0 = NewModelObj021c3158(self);
            self->unk_38 = m_0;
            func_020417e0(m_0, res_0);
        }
        self->unk_38->flags |= 2;
        self->unk_38->flags |= 0x80000;
        self->unk_38->unk_158 = (void *)func_ov000_021c8408;
        {
            void *res_1;
            Model *m_1;
            char *arc = data_ov000_021cc9d3;
            char *name = data_ov000_021cc9dc;
            res_1 = func_02035f30(arc, name, 2);
            res_1 = func_02034d88(res_1, name);
            m_1 = NewModel021c3158(arc, name);
            self->unk_3c = m_1;
            func_020417e0(m_1, res_1);
        }
        self->unk_3c->flags |= 2;
        self->unk_3c->flags |= 0x80000;
        self->unk_3c->unk_158 = (void *)func_ov000_021c8408;

        n = self->item.n;
        mask = self->item.mask;
        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                func_02041d9c(self->unk_38, 0, (u16)i);
            } else {
                func_02041d9c(self->unk_3c, 0, (u16)i);
            }
        }
        self->unk_68 = 30;
        return;
    }
    case 30: {
        u8 a;
        s32 t;
        self->alpha += 2;
        if (self->unk_6c != 0 || (a = self->alpha) >= 0x1f) {
            a = 0x1f;
        }
        self->alpha = a;
        if (self->unk_6c != 0) {
            self->scale = self->scale >= 0x1000 ? 0x1000 : self->scale + 0x111;
        } else {
            self->scale = self->scale > 0x99a ? self->scale - 0x111 : 0x99a;
        }
        {
            t = FX_Div(self->scale - 0x99a, 0x1000 - 0x99a);
            self->ox = 0;
            self->oy = Interp_SinLerp(t, 0xa000, 0);
        }
        if (self->scale >= 0x1000) {
            self->partZ = 0x334 - 0x99a;
            return;
        }
        self->partZ = self->z;
        return;
    }
    }
}

}
