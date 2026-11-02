#include "ov010/ov010.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern u8 data_ov010_02210154[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern void *Ov003Vt_021f7cd8_Dtor(void *p);
extern void func_ov010_02207520(Ov010Obj02210154 *self);
extern void func_ov010_022075bc(Ov010Obj02210154 *self);
extern void func_02049678(SndMgr *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(SndMgr *a);

void *Ov010ActVt_02210154_Ctor(Ov010Obj02210154 *self) {
    func_ov003_021d0c1c(self);
    *(void * *)self = data_ov010_02210154;
    func_ov003_021d8f24(&self->seq);
    func_ov010_0220d79c(&self->coll);
    Ov003Vt_021f7d10_Ctor(&self->ticker);
    Ov003Vt_021f7cd8_Ctor(&self->timer);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520(self);
    return self;
}

static inline void Ov010_02204294_Body(Ov010Obj02210154 *self) {
    *(void * *)self = data_ov010_02210154;
    func_ov003_021cf3fc(0);
    func_ov010_022075bc(self);
    Ov003Vt_021f7cd8_Dtor(&self->timer);
    Ov003Vt_021f7d10_Dtor(&self->ticker);
    Ov010Coll_Dtor(&self->coll);
    func_ov003_021d8f34(&self->seq);
    func_ov003_021d0edc(self);
}

void *Ov010ActVt_02210154_Dtor(Ov010Obj02210154 *self) {
    Ov010_02204294_Body(self);
    return self;
}

void *Ov010ActVt_02210154_DtorDelete(Ov010Obj02210154 *self) {
    Ov010_02204294_Body(self);
    Heap_Free(self);
    return self;
}

BOOL func_ov010_02204344(Ov010Obj02210154 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->unk_f0 == 0) {
        self->unk_f0 = 1;
        if (((VObj *)self)->vfunc_a8(&self->sndBank)) {
            func_02049678(data_02097e4c, 4, self->sndBank, -1);
        }
        r = FALSE;
    } else if (SndMgr_IsLoadDone(data_02097e4c) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov010_022043c4(Ov010Obj02210154 *self) {
    VecFx32 saved = self->pos;
    BOOL r;
    func_ov003_021d883c(&self->ticker, &self->pos, &self->pos, 0x480);
    r = func_ov003_021d16cc(self);
    self->pos = saved;
    return r;
}

}
