#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Obj0215eab4_Draw(void *p);

void Lo021cb798_Unload(Lo021cb798 *self) {
    LO_FREE_M(self, 0xa4);
    LO_FREE_M(self, 0xa0);
    self->unk_0c_3 = 0;
}

}
