#pragma unsigned_char on
#include "ExceptionHandler.h"

CatchInfo *FindMostRecentException(ThrowContext *context, ExceptionInfo *info) {
    ActionIterator iter;
    u8 action;

    InitIterator(&iter, context, info);
    action = CurrentAction(&iter.info);
    for (;;) {
        switch (action) {
        default:
            return NULL;
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
        case 12:
        case 15:
        case 16:
        case 17:
        case 18:
            action = NextAction(&iter);
            break;
        case 13: {
            s32 cinfoRef;
            CatchInfo *catchinfo;
            DecodeSignedNumber(iter.info.actionPointer + 1, &cinfoRef);
            catchinfo = (CatchInfo *)(iter.context.cfa + cinfoRef);
            context->throwtype = catchinfo->typeinfo;
            context->location = catchinfo->location;
            context->dtor = NULL;
            context->catchinfo = catchinfo;
            return catchinfo;
        }
        }
    }
}

int IsInSpecification(char *extype, ExSpecification *spec) {
    u8 *p = spec->specList;
    u32 i;
    s32 offset[2]; // the original reserves an 8-byte slot here
    for (i = 0; i < spec->specs; i++) {
        if (__throw_catch_compare(extype, (char *)ReadWord(p), offset)) {
            return 1;
        }
        p += 4;
    }
    return 0;
}
