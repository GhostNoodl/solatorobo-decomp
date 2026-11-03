#include "ov000/MessageQueue.h"

static inline BOOL ListBuffer021cb940_IsReady(ListBuffer021cb940 *self) { return self->ready != 0; }

extern "C" {

bool ListBuffer021cb940_IsReady_02172a3c(ListBuffer021cb940 *self) {
    return ListBuffer021cb940_IsReady(self);
}

}
