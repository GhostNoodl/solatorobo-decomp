#include "ov000/VObj.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ctrl0218372c;

typedef struct {
    u8 unk_00[0x4];
    Ctrl0218372c *unk_04;
} Data021ccd50;

typedef struct {
    u8 unk_00[0xb8];
    VObj *unk_b8;
} Obj0218372c;

extern "C" {

extern HeapState *data_02097dd0;
extern Data021ccd50 data_ov000_021ccd50;
extern void *data_02fe152c;
void func_020592c4(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02182590(u8 *p);

void func_ov000_0218372c(Obj0218372c *self, s32 a) {
    void *saved;
    func_020592c4(data_02fe152c, 2, 0x101, a, 1);
    saved = data_02097dd0->current;
    data_02097dd0->current = data_02097dd0->unk_08;
    if (self->unk_b8 != NULL) {
        if (self->unk_b8 != NULL) {
            self->unk_b8->vfunc_04();
        }
        self->unk_b8 = NULL;
    }
    data_02097dd0->current = saved;
    {
        Ctrl0218372c *c = data_ov000_021ccd50.unk_04;
        c->unk_ac = 1;
        func_ov000_02182590(&c->unk_ac);
    }
}

}
