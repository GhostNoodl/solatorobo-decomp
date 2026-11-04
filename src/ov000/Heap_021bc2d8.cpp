#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    VObj *unk_10;
    void *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} Obj021bc2d8;

extern "C" {

extern Obj021bc2d8 *gFieldFade;

static inline void Obj021bc2d8_Delete(Obj021bc2d8 *o) {
    HEAP_DELETE_VOBJ(o->unk_10);
    HEAP_DELETE_MODEL(o->unk_14);
    o->unk_00 = 0;
    o->unk_04 = 0;
    o->unk_08 = 0;
    o->unk_0c = 0;
    o->unk_10 = 0;
    o->unk_14 = 0;
    o->unk_18 = 0;
    o->unk_1c = 0;
    o->unk_20 = 0;
    o->unk_24 = 0;
    o->unk_28 = 0;
    Heap_Free(o);
}

void FieldFade_Destroy(void) {
    Obj021bc2d8 *p;
    void *saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    p = gFieldFade;
    if (p != NULL) {
        if (p != NULL) {
            Obj021bc2d8_Delete(p);
        }
        gFieldFade = NULL;
    }
    gSysState->cur = saved;
}

}
