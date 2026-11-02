#include "ov000/VObj.h"
#include "ov000/ActorMarker.h"

extern "C" {

void func_ov000_021bd300(ActorMarker *self) {
    if (self->work.state == 10) {
        self->work.state = 4;
    }
}

}
