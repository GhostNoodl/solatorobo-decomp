#pragma unsigned_char on
extern "C" {
#include "ExceptionHandler.h"
}

// HandleUnexpected (0x020096e4).
#ifdef NONMATCHING
// Status (round rwA): clean-room rewrite from the target assembly, 2 / 0. This file has no delinks.txt entry, so
// the function comes from the dsd gap. The target copies r3 to r4 and r2 to r5, then sets up r2 for UnwindStack
// before it saves r0; this draft saves r0 first. Parameter types, the callee's return type, opt_* pragmas,
// optimization levels, `exceptions on`, compiling as C, UnwindStack in the same file (also with `ipa file`) and a
// cxxperm run (21673 compiles) do not change it.

// Called when a thrown type is not in a function's exception specification: unwind to the
// specification's frame, fill its catch record with the active exception, and enter its
// handler (which calls the unexpected handler).
void HandleUnexpected(ThrowContext *context, ExceptionInfo *info, ExSpecification *spec, u8 *unexp) {
    CatchInfo *record;

    UnwindStack(context, info, unexp);
    record = (CatchInfo *)(context->cfa + spec->cinfoRef);
    record->location = context->location;
    record->typeinfo = context->throwtype;
    record->dtor = (void (*)(void *, int))context->dtor;
    record->stacktop = unexp;
    JumpToHandler(context, info, info->currentFunction + spec->pcOffset);
}

#endif // NONMATCHING
