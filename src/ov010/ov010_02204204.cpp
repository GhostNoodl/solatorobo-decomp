#include "ov010/ov010.h"
#include "ov010/ObjLayouts.h"

extern "C" {

extern u8 data_ov010_02210154[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *data_02097e4c;
extern void *func_ov010_0220d79c(void *p);
extern void *Ov010Coll_Dtor(void *p);
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern void *Ov003Vt_021f7cd8_Dtor(void *p);
extern void func_ov010_02207520(void *self);
extern void func_ov010_022075bc(void *self);
extern BOOL func_ov000_0218cf5c(void *self);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(void *a);

void *Ov010ActVt_02210154_Ctor(Ov010ObjBase0220ffe4_0221009c *self) {
    func_ov003_021d0c1c(self);
    *(void * *)self = data_ov010_02210154;
    func_ov003_021d8f24((u8 *)self + 0x160);
    func_ov010_0220d79c((u8 *)self + 0x174);
    Ov003Vt_021f7d10_Ctor((u8 *)self + 0x1b0);
    Ov003Vt_021f7cd8_Ctor((u8 *)self + 0x1dc);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520(self);
    return self;
}

static inline void Ov010_02204294_Body(Ov010ObjBase0220ffe4_0221009c *self) {
    *(void * *)self = data_ov010_02210154;
    func_ov003_021cf3fc(0);
    func_ov010_022075bc(self);
    Ov003Vt_021f7cd8_Dtor((u8 *)self + 0x1dc);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x1b0);
    Ov010Coll_Dtor((u8 *)self + 0x174);
    func_ov003_021d8f34((u8 *)self + 0x160);
    func_ov003_021d0edc(self);
}

void *Ov010ActVt_02210154_Dtor(Ov010ObjBase0220ffe4_0221009c *self) {
    Ov010_02204294_Body(self);
    return self;
}

void *Ov010ActVt_02210154_DtorDelete(Ov010ObjBase0220ffe4_0221009c *self) {
    Ov010_02204294_Body(self);
    Heap_Free(self);
    return self;
}

BOOL func_ov010_02204344(Ov010ObjBase0220ffe4_0221009c *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->unk_f0 == 0) {
        self->unk_f0 = 1;
        if (((VObj *)self)->vfunc_a8((u8 *)self + 0x128)) {
            func_02049678(data_02097e4c, 4, self->unk_128, -1);
        }
        r = FALSE;
    } else if (SndMgr_IsLoadDone(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov010_022043c4(Ov010ObjBase0220ffe4_0221009c *self) {
    VecFx32 saved = self->pos;
    BOOL r;
    func_ov003_021d883c((u8 *)self + 0x1b0, &self->pos, &self->pos, 0x480);
    r = func_ov003_021d16cc(self);
    self->pos = saved;
    return r;
}

}
