#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} Obj021ccd70;

extern "C" {

extern Obj021ccd70 *gFieldFade;
void *Heap_Alloc(u32 size);

void FieldFade_Create(void) {
    Obj021ccd70 *p;
    if (gFieldFade != NULL) {
        return;
    }
    p = (Obj021ccd70 *)Heap_Alloc(sizeof(Obj021ccd70));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = 0;
        p->unk_0c = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
        p->unk_1c = 0;
        p->unk_20 = 0;
        p->unk_24 = 0;
        p->unk_28 = 0;
    }
    gFieldFade = p;
}

}
