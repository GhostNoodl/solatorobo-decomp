#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
void *ResSet_Init(void *p);

void Ov013ActEx_02204454_Init(Ov013ActEx_02204454 *self) {
    Ov013Names *n;
    ActorEx_InitActor(self);
    n = (Ov013Names *)Heap_Alloc(0x138);
    if (n != NULL) {
        n = (Ov013Names *)ResSet_Init(n);
    }
    self->unk_dc = n;
    {
        const char *b = data_ov013_0220ba58;
        if (b) {
            STD_CopyString(n->mdlDir, data_ov013_0220ba60);
            STD_CopyString(n->mdlName, b);
            n->ownMdl = 1;
        }
    }
    self->unk_dc->unk_00 = 0;
}

}
