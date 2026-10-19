#pragma unsigned_char on
#include "ExceptionHandler.h"

u8 *FindExceptionHandler(ThrowContext *context, ExceptionInfo *info, s32 *result_offset) {
    ActionIterator iter;
    ExCatchBlock catchblock;
    ExSpecification spec;
    u8 action;
    u8 *p;

    InitIterator(&iter, context, info);
    action = CurrentAction(&iter.info);
    for (;;) {
        switch (action) {
        case 12:
            p = iter.info.actionPointer;
            catchblock.catchType = (char *)ReadWord(p + 1);
            p = DecodeUnsignedNumber(p + 5, &catchblock.catchPCOffset);
            DecodeSignedNumber(p, &catchblock.cinfoRef);
            if (!__throw_catch_compare(context->throwtype, catchblock.catchType, result_offset)) {
                break;
            }
            goto found;
        case 15:
            p = DecodeUnsignedNumber(iter.info.actionPointer + 1, &spec.specs);
            p = DecodeUnsignedNumber(p, &spec.pcOffset);
            spec.specList = DecodeSignedNumber(p, &spec.cinfoRef);
            if (!IsInSpecification(context->throwtype, &spec)) {
                HandleUnexpected(context, info, &spec, iter.info.actionPointer);
            }
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
        default:
            _ZSt9terminatev();
            goto found;
        }
        action = NextAction(&iter);
    }
found:
    return iter.info.actionPointer;
}

void SetupCatchInfo(ThrowContext *context, s32 cinfoRef, s32 offset) {
    CatchInfo *catchinfo = (CatchInfo *)(context->cfa + cinfoRef);
    catchinfo->location = context->location;
    catchinfo->typeinfo = context->throwtype;
    catchinfo->dtor = context->dtor;
    if (*context->throwtype == '*') {
        catchinfo->sublocation = &catchinfo->pointercopy;
        catchinfo->pointercopy = *(s32 *)context->location + offset;
    } else {
        catchinfo->sublocation = (char *)context->location + offset;
    }
}

void __ThrowHandler(ThrowContext *context) {
    ExceptionInfo info;
    ExCatchBlock catchblock;
    s32 offset;
    u8 *ap;
    u8 *p;

    FindExceptionRecord(context->returnAddr, &info);
    if (info.exceptionRecord == NULL) {
        _ZSt9terminatev();
    }
    SetupFrameInfo(context, &info);
    if (context->throwtype != NULL) {
        context->catchinfo = NULL;
    } else {
        context->catchinfo = FindMostRecentException(context, &info);
        if (context->catchinfo == NULL) {
            _ZSt9terminatev();
        }
    }
    ap = FindExceptionHandler(context, &info, &offset);
    catchblock.catchType = (char *)ReadWord(ap + 1);
    p = DecodeUnsignedNumber(ap + 5, &catchblock.catchPCOffset);
    DecodeSignedNumber(p, &catchblock.cinfoRef);
    UnwindStack(context, &info, ap);
    SetupCatchInfo(context, catchblock.cinfoRef, offset);
    JumpToHandler(context, &info, info.currentFunction + catchblock.catchPCOffset);
}
