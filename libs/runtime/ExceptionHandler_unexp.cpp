// HandleUnexpected: C++ with exceptions on and `#pragma exception_terminate`, like UnwindStack.
// The pragma is what moves the argument copies (r3 to r4, r2 to r5) ahead of the r0 save.
#pragma exceptions on
extern "C" {
#pragma unsigned_char on
#include "ExceptionHandler.h"

void HandleUnexpected(ThrowContext *context, ExceptionInfo *info, ExSpecification *spec, u8 *unexp) {
#pragma exception_terminate
    CatchInfo *catchinfo;

    UnwindStack(context, info, unexp);
    catchinfo = (CatchInfo *)(context->cfa + spec->cinfoRef);
    catchinfo->location = context->location;
    catchinfo->typeinfo = context->throwtype;
    catchinfo->dtor = (void (*)(void *, int))context->dtor;
    catchinfo->stacktop = unexp;
    JumpToHandler(context, info, info->currentFunction + spec->pcOffset);
}
}
