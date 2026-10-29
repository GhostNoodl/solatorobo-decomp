#include "ov000/VObj.h"

class Widget021820bc : public VObj {
public:
    u8 pad_04[0xc4];
    u16 unk_c8;
    u8 pad_ca[0xa];
    Widget021820bc *unk_d4;
};

typedef struct {
    u8 pad_00[0xc];
    Widget021820bc *unk_0c;
    Widget021820bc *unk_10;
} Panel021820bc;

typedef struct {
    u8 pad_00[0x44];
    u16 unk_44;
} Dtcm02fe1534;

extern "C" {

extern Dtcm02fe1534 data_02fe1534;
BOOL func_0205a9c8(Widget021820bc *w);
BOOL func_0205aa30(Widget021820bc *w);

BOOL func_ov000_021820bc(Panel021820bc *self, BOOL notify) {
    Widget021820bc *w = self->unk_10;
    BOOL changed;
    u16 saved;

    if (w == NULL) {
        return TRUE;
    }
    saved = data_02fe1534.unk_44;
    changed = FALSE;
    data_02fe1534.unk_44 = 1;
    while (w != NULL) {
        if (!w->vfunc_34() && func_0205a9c8(w)) {
            func_0205aa30(w);
            if (notify && w->unk_c8 == 0) {
                w->vfunc_38(1);
            }
            changed = TRUE;
        }
        w = w->unk_d4;
    }
    if (changed && self->unk_0c != NULL) {
        self->unk_0c->vfunc_38(1);
    }
    data_02fe1534.unk_44 = saved;
    return changed;
}

}
