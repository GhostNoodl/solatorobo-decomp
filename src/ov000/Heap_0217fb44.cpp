#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u8 pad[0x3c];
    VObj *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    VObj *unk_48;
    void *unk_4c;
} Obj0217fb44;

extern "C" {

extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
void func_02036838(void *a, void *b, s32 c, s32 d);

void func_ov000_0217fb44(Obj0217fb44 *self) {
    HEAP_DELETE_VOBJ(self->unk_3c);
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_VOBJ(self->unk_44);
    HEAP_DELETE_VOBJ(self->unk_48);
    HEAP_DELETE_MODEL(self->unk_4c);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
}

}
