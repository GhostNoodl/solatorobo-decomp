#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov002_021f06bc[];

void *Ov002Vt_021f0cf8_Dtor(Ov002Snd021f0cf8 *p);

void *Ov002Vt_021f06bc_DtorDelete(Ov002Obj021f06bc *self) {
    s16 *p;
    s32 t;
    *(VFunc **)self = data_ov002_021f06bc;
    if (FIELD(self, 0x14, void *) != NULL) {
        ResMgr_ReleaseArchive(self->unk_4c, self->unk_6c, 0);
    }
    for (p = self->snd.cur; p != NULL; p = self->snd.cur) {
        t = p[1];
        if (t == 1 || t == 3 || t == 7 || t == 10) {
            SndQueue_Exec(data_02097e48.queue, (SndCmd *)p);
        }
        Ov002Snd021f0cf8_Next(&self->snd);
    }
    Ov002Vt_021f0cf8_Dtor(&self->snd);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f06bc_Dtor(Ov002Obj021f06bc *self) {
    s16 *p;
    s32 t;
    *(VFunc **)self = data_ov002_021f06bc;
    if (FIELD(self, 0x14, void *) != NULL) {
        ResMgr_ReleaseArchive(self->unk_4c, self->unk_6c, 0);
    }
    for (p = self->snd.cur; p != NULL; p = self->snd.cur) {
        t = p[1];
        if (t == 1 || t == 3 || t == 7 || t == 10) {
            SndQueue_Exec(data_02097e48.queue, (SndCmd *)p);
        }
        Ov002Snd021f0cf8_Next(&self->snd);
    }
    Ov002Vt_021f0cf8_Dtor(&self->snd);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

}
