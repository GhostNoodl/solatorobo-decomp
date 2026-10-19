#pragma unsigned_char on
#include "ExceptionHandler.h"

u8 *DecodeSignedNumber(u8 *p, s32 *out) {
    s32 v = (signed char)p[0];
    u32 b1, b2, b3;
    if (!(v & 1)) {
        *out = v >> 1;
        return p + 1;
    }
    b1 = p[1];
    if (!(v & 2)) {
        *out = ((v >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = p[2];
    if (!(v & 4)) {
        *out = ((v >> 3) << 16) | (b1 << 8) | b2;
        return p + 3;
    }
    b3 = p[3];
    *out = ((v >> 3) << 24) | (b1 << 16) | (b2 << 8) | b3;
    return p + 4;
}

u8 *DecodeUnsignedNumber(u8 *p, u32 *out) {
    u32 v = p[0];
    u32 b1, b2, b3;
    if (!(v & 1)) {
        *out = v >> 1;
        return p + 1;
    }
    b1 = p[1];
    if (!(v & 2)) {
        *out = ((v >> 2) << 8) | b1;
        return p + 2;
    }
    b2 = p[2];
    if (!(v & 4)) {
        *out = ((v >> 3) << 16) | (b1 << 8) | b2;
        return p + 3;
    }
    b3 = p[3];
    *out = ((v >> 3) << 24) | (b1 << 16) | (b2 << 8) | b3;
    return p + 4;
}

ExceptionTableIndex *FindTableEntry(ExceptionTableIndex *table, s32 count, u32 pc) {
    s32 lo = 0;
    s32 hi = count - 1;
    while (lo <= hi) {
        s32 mid = (lo + hi) >> 1;
        ExceptionTableIndex *ex = &table[mid];
        if (pc < ex->functionStart) {
            hi = mid - 1;
        } else if (pc > ex->functionStart + (ex->functionSize & ~1)) {
            lo = mid + 1;
        } else {
            return ex;
        }
    }
    return NULL;
}

void FindExceptionRecord(u32 pc, ExceptionInfo *info) {
    ExceptionTableIndex *ex;
    u8 *p;
    u32 offset;
    u32 i;
    u32 len;
    u32 size;
    u32 action;

    info->exceptionRecord = NULL;
    info->actionPointer = NULL;
    if (!GetExceptionTable(info, pc)) {
        return;
    }
    ex = FindTableEntry(info->tableStart, info->tableEnd - info->tableStart, pc);
    if (ex == NULL) {
        return;
    }
    if (ex->functionSize & 1) {
        info->exceptionRecord = (u8 *)&ex->exceptionRecord;
    } else {
        info->exceptionRecord = ex->exceptionRecord;
    }
    info->currentFunction = ex->functionStart;
    offset = pc - ex->functionStart;
    p = SkipFrameInfo(info->exceptionRecord);
    i = 0;
    do {
        p = DecodeUnsignedNumber(p, &len);
        if (len == 0) {
            return;
        }
        p = DecodeUnsignedNumber(p, &size);
        p = DecodeUnsignedNumber(p, &action);
        i += len;
        if (offset < i) {
            return;
        }
        i += size;
    } while (offset > i);
    info->actionPointer = info->exceptionRecord + action;
}

u8 CurrentAction(ExceptionInfo *info) {
    return info->actionPointer != NULL ? *info->actionPointer & 0x1f : 0;
}
