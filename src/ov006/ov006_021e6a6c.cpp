#include "ov006/Racer.h"

extern "C" {

int func_ov000_0218d17c(Actor *self);
u8 func_ov006_021d8cb8(void);

int func_ov006_021e6a6c(Ov006Racer *self) {
    int r = func_ov000_0218d17c(self);
    if (r != 0) {
        if (Ov006Racer_IsOver(self) || func_ov006_021d8cb8() <= 1) {
            r = 0;
        }
    }
    return r;
}

}
