#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
} Bits0214c934;

class Lo0214c934 : public VObj {
public:
    s32 state;
    s32 unk_08;
    Bits0214c934 bits;
    u8 pad10[0x1f0];
    VObj *unk_200;
    s32 unk_204;

    BOOL IsB4() {
        return bits.b4 ? TRUE : FALSE;
    }
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd70;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_021bc3ec(void *p, s32 a, s32 b);
void func_ov000_021bc458(void *p);

void func_ov000_0214c934(Lo0214c934 *self) {
    switch (self->state) {
    case 0:
        if (self->vfunc_4c() == 0) {
            self->state = 5;
            return;
        }
        if (self->IsB4()) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    case 1:
        if (self->IsB4()) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    }
    if (self->unk_200 == NULL) {
        return;
    }
    if (--self->unk_204 > 0) {
        return;
    }
    if (self->unk_204 == 0) {
        func_ov000_021bc3ec(data_ov000_021ccd70, 3, 0xa000);
    }
    if (self->unk_200->vfunc_8c() != 0) {
        return;
    }
    HEAP_DELETE_VOBJ(self->unk_200);
    self->bits.b1 = 0;
    func_ov000_021bc458(data_ov000_021ccd70);
    self->unk_204 = 0;
}

}
