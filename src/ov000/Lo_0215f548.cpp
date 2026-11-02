#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"

extern "C" {

void UiLabel_Release(UiLabel *self) {
    LO_FREE_V(self, 0x24); // text
    LO_FREE_M(self, 0x28); // model
    UiLabel_Reset(self);
}

}
