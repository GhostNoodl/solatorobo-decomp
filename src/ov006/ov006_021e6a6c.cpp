#include "ov006/Racer.h"

extern "C" {

int func_ov000_0218d17c(Actor *self);
u8 ov006_CountFinished(void);

int Ov006ActVt_021ec4f4_IsActive(Ov006Racer *self) {
    int r = func_ov000_0218d17c(self);
    if (r != 0) {
        if (Ov006Racer_IsOver(self) || ov006_CountFinished() <= 1) {
            r = 0;
        }
    }
    return r;
}

}
