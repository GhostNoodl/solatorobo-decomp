#include "ov006/SlotManager.h"
#include "ov006/Racer.h"


typedef struct ov006_Save0214a424 {
    u8 unk0[0x18];
    u16 unk18_0 : 10;
    u16 unk18_10 : 1;
    u16 unk18_11 : 5;
} ov006_Save0214a424;

extern "C" {

extern ov006_Save0214a424 *gStageFlags;
void *Tbl_FindEntry_0206fef8(u16 id);
Ov006RacerPrm *Tbl_Elem_020706a0(u16 id);
int Tbl_GetResFile(u16 id);
ActorRes *ResSet_Init(void *p);
void ResSet_SetFile(ActorRes *a, int b, int c, int d, int e, int f);

void Ov006ActVt_021ec4f4_Init(Ov006Racer *self) {
    int res;
    ActorRes *obj;
    Tbl_FindEntry_0206fef8(self->kind);
    self->prm = Tbl_Elem_020706a0(self->kind);
    res = Tbl_GetResFile(self->kind);
    obj = (ActorRes *)Heap_Alloc(sizeof(ActorRes));
    if (obj != NULL) {
        obj = ResSet_Init(obj);
    }
    self->unk_34 = obj;
    ResSet_SetFile((ActorRes *)self->unk_34, res, 1, 1, 0, 0);
    ((ActorRes *)self->unk_34)->unk_00 = 0;
    if (self->idx == gOv006SlotManager->unk5) {
        self->toggle = gStageFlags->unk18_10 ? TRUE : FALSE;
        self->swap = self->toggle;
    }
    self->unk_1c0.x = self->pos.x;
    self->unk_1c0.y = self->pos.y;
    self->unk_1c0.z = self->pos.z;
}

}
