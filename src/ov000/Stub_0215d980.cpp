#include "ov000/ObjLayouts.h"

extern "C" {

// Sets the number of a number display; with both, the shown number jumps to it at once.
void Lo021cae48_SetValue(Lo021cae48 *self, s32 value, BOOL both) {
    if (both) {
        self->shown = value;
    }
    self->value = value;
}

}
