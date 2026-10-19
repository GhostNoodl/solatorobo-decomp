#ifndef RUNTIME_EXCEPTIONHANDLER_H
#define RUNTIME_EXCEPTIONHANDLER_H

#include "types.h"

// CodeWarrior ARM C++ exception handling runtime (table-driven unwinder).
typedef struct ExceptionTableIndex {
    u32 functionStart;
    u32 functionSize; // bit 0: exception record is stored inline
    u8 *exceptionRecord;
} ExceptionTableIndex;

typedef struct ExceptionInfo {
    u32 currentFunction;    // 0x00
    u8 *exceptionRecord;    // 0x04
    u8 *actionPointer;      // 0x08
    ExceptionTableIndex *tableStart; // 0x0c
    ExceptionTableIndex *tableEnd;   // 0x10
    u32 unk_14;
} ExceptionInfo;

typedef struct CatchInfo {
    void *location;
    void *typeinfo;
    void (*dtor)(void *obj, int flag);
    void *sublocation;
    s32 pointercopy;
    void *stacktop;
} CatchInfo;

typedef struct ThrowState {
    u32 regs[16];    // 0x1c
    u32 unk_5c;      // 0x5c
    u32 frameSize;   // 0x60
    u32 argSize;     // 0x64
    u16 regMask;     // 0x68
    u8 savedArgs;    // 0x6a
    u8 hasFP;        // 0x6b
    u8 thumbFP;      // 0x6c
} ThrowState;

typedef struct ThrowContext {
    char *throwtype;      // 0x00
    void *location;       // 0x04
    void *dtor;           // 0x08
    CatchInfo *catchinfo; // 0x0c
    u32 returnAddr;       // 0x10
    u32 sp;               // 0x14
    u32 cfa;              // 0x18
    ThrowState state;     // 0x1c
} ThrowContext;

typedef struct ActionIterator {
    ExceptionInfo info;
    ThrowContext context;
} ActionIterator;

u32 RestoreSavedRegisters(ThrowContext *ctx, ActionIterator *iter);
void SetupFrameInfo(ThrowContext *ctx, ExceptionInfo *info);
int GetExceptionTable(ExceptionInfo *info, u32 pc);
u8 *SkipFrameInfo(u8 *p);
void JumpToHandler(ThrowContext *ctx, ExceptionInfo *info, u32 addr);
void _ZSt9terminatev(void);
int __throw_catch_compare(const char *throwtype, const char *catchtype, s32 *offset_result);
void UnwindStack(ThrowContext *ctx, ExceptionInfo *info, u8 *catcher);

typedef struct ExSpecification {
    u32 specs;
    u32 pcOffset;
    s32 cinfoRef;
    u8 *specList;
} ExSpecification;

typedef struct ExCatchBlock {
    char *catchType;
    u32 catchPCOffset;
    s32 cinfoRef;
} ExCatchBlock;

static inline void InitIterator(ActionIterator *iter, ThrowContext *context, ExceptionInfo *info) {
    iter->info.currentFunction = info->currentFunction;
    iter->info.exceptionRecord = info->exceptionRecord;
    iter->info.actionPointer = info->actionPointer;
    iter->info.tableStart = info->tableStart;
    iter->info.tableEnd = info->tableEnd;
    iter->info.unk_14 = info->unk_14;
    iter->context.throwtype = context->throwtype;
    iter->context.location = context->location;
    iter->context.dtor = context->dtor;
    iter->context.catchinfo = context->catchinfo;
    iter->context.returnAddr = context->returnAddr;
    iter->context.sp = context->sp;
    iter->context.cfa = context->cfa;
    iter->context.state = context->state;
}

static inline u32 ReadWord(u8 *p) {
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}

u8 *DecodeSignedNumber(u8 *p, s32 *out);
u8 *DecodeUnsignedNumber(u8 *p, u32 *out);
ExceptionTableIndex *FindTableEntry(ExceptionTableIndex *table, s32 count, u32 pc);
void FindExceptionRecord(u32 pc, ExceptionInfo *info);
u8 CurrentAction(ExceptionInfo *info);
u8 NextAction(ActionIterator *iter);
CatchInfo *FindMostRecentException(ThrowContext *context, ExceptionInfo *info);
int IsInSpecification(char *extype, ExSpecification *spec);
void HandleUnexpected(ThrowContext *context, ExceptionInfo *info, ExSpecification *spec, u8 *unexp);
u8 *FindExceptionHandler(ThrowContext *context, ExceptionInfo *info, s32 *result_offset);
void SetupCatchInfo(ThrowContext *context, s32 cinfoRef, s32 offset);
void __ThrowHandler(ThrowContext *context);

#endif
