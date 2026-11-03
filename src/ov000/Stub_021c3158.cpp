#include "types.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ListRow.h"


extern "C" {

extern char data_ov000_021cc9d3[];
extern char data_ov000_021cc9dc[];
void func_ov000_021c8408(void *self, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);
void ListRow021cca70_Release(ListRow021cca70 *self);
BOOL Model_IsReady(void *m, u32 a);
void ResMgr_LoadArchive(const char *arc, const char *name, s32 a, s32 b);
BOOL ResMgr_IsArchiveLoaded(const char *arc, const char *name, s32 a);
void *ResMgr_GetArchiveList(const char *arc, const char *name, s32 a);
void *ResList_FindType2(void *a, const char *name);
void *Heap_Alloc(u32 size);
s32 FX_Div(s32 n, s32 d);
s32 Interp_SinLerp(s32 t, s32 a, s32 b);

static inline char *ObjName021c3158(ListRow021cca70 *o) {
    return o->name;
}

static inline void *LoadObjRes021c3158(ListRow021cca70 *o) {
    return ResMgr_GetArchiveList(o->arc, o->name, 2);
}

static inline Model *NewModel021c3158(char *arc, const char *name) {
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
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
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString((char *)m + 0x2c, arc);
    }
    return m;
}

void ListRow021cca70_Update(ListRow021cca70 *self) {
    if (self->unk_68 != 0 && !self->shown) {
        if (self->unk_38 == NULL) {
            return;
        }
        if (!Model_IsReady(self->unk_38, 0xffff)) {
            return;
        }
        ListRow021cca70_Release(self);
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
        ResMgr_LoadArchive(self->arc, self->name, 2, 0);
        ResMgr_LoadArchive(data_ov000_021cc9d3, data_ov000_021cc9dc, 2, 0);
        self->unk_68++;
        return;
    case 11:
        if (!ResMgr_IsArchiveLoaded(self->arc, self->name, 2)) {
            return;
        }
        if (!ResMgr_IsArchiveLoaded(data_ov000_021cc9d3, data_ov000_021cc9dc, 2)) {
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
            res_0 = ResList_FindType2(res_0, self->name);
            m_0 = NewModelObj021c3158(self);
            self->unk_38 = m_0;
            TexObj_SetRes(m_0, res_0);
        }
        self->unk_38->flags |= 2;
        self->unk_38->flags |= 0x80000;
        self->unk_38->unk_158 = (void *)func_ov000_021c8408;
        {
            void *res_1;
            Model *m_1;
            char *arc = data_ov000_021cc9d3;
            char *name = data_ov000_021cc9dc;
            res_1 = ResMgr_GetArchiveList(arc, name, 2);
            res_1 = ResList_FindType2(res_1, name);
            m_1 = NewModel021c3158(arc, name);
            self->unk_3c = m_1;
            TexObj_SetRes(m_1, res_1);
        }
        self->unk_3c->flags |= 2;
        self->unk_3c->flags |= 0x80000;
        self->unk_3c->unk_158 = (void *)func_ov000_021c8408;

        n = self->item.n;
        mask = self->item.mask;
        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                TexObj_SelectImage(self->unk_38, 0, (u16)i);
            } else {
                TexObj_SelectImage(self->unk_3c, 0, (u16)i);
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
