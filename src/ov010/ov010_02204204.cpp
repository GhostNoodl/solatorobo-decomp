#include "ov010/ov010.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern u8 Ov010ActVt_02210154_vtbl[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern void *Ov003Vt_021f7cd8_Dtor(void *p);
extern void Ov010Obj02210154_ClearFields(Ov010Obj02210154 *self);
extern void Ov010Obj02210154_Release(Ov010Obj02210154 *self);
extern void SndMgr_RequestLoad_02049678(SndMgr *a, s32 b, s32 c, s32 d);
extern BOOL SndMgr_IsLoadDone(SndMgr *a);

void *Ov010ActVt_02210154_Ctor(Ov010Obj02210154 *self) {
    Ov003Actor_Ctor(self);
    *(void * *)self = Ov010ActVt_02210154_vtbl;
    Ov003Flag_Deactivate(&self->seq);
    Ov010Coll_Ctor(&self->coll);
    Ov003Vt_021f7d10_Ctor(&self->ticker);
    Ov003Vt_021f7cd8_Ctor(&self->timer);
    Ov003_DupString(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    Ov003_DupString2(2, data_ov010_0220ff91);
    Ov003_DupString2(0, data_ov010_0220ffa1);
    Ov003_DupString2(1, data_ov010_0220ffae);
    Ov010Obj02210154_ClearFields(self);
    return self;
}

static inline void Ov010_02204294_Body(Ov010Obj02210154 *self) {
    *(void * *)self = Ov010ActVt_02210154_vtbl;
    func_ov003_021cf3fc(0);
    Ov010Obj02210154_Release(self);
    Ov003Vt_021f7cd8_Dtor(&self->timer);
    Ov003Vt_021f7d10_Dtor(&self->ticker);
    Ov010Coll_Dtor(&self->coll);
    Ov003Flag_Stop(&self->seq);
    Ov003Actor_DtorBase(self);
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

BOOL Ov010Obj02210154_IsReady(Ov010Obj02210154 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->unk_f0 == 0) {
        self->unk_f0 = 1;
        if (((VObj *)self)->vfunc_a8(&self->sndBank)) {
            SndMgr_RequestLoad_02049678(gSndMgr, 4, self->sndBank, -1);
        }
        r = FALSE;
    } else if (SndMgr_IsLoadDone(gSndMgr) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL Ov010Obj02210154_Draw(Ov010Obj02210154 *self) {
    VecFx32 saved = self->pos;
    BOOL r;
    Ov003TickerSet_Apply(&self->ticker, &self->pos, &self->pos, 0x480);
    r = Ov003Actor_Draw(self);
    self->pos = saved;
    return r;
}

}
