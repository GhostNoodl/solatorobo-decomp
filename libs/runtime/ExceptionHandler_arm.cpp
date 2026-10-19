#pragma unsigned_char on
#include "types.h"

// Unwinding context used by the exception handler (CodeWarrior ARM runtime).
typedef struct ThrowContext {
    u32 unk_00[5];
    u32 sp;          // 0x14
    u32 cfa;         // 0x18
    u32 regs[16];    // 0x1c
    u32 unk_5c;      // 0x5c
    u32 frameSize;   // 0x60
    u32 argSize;     // 0x64
    u16 regMask;     // 0x68
    u8 savedArgs;    // 0x6a
    u8 hasFP;        // 0x6b
    u8 thumbFP;      // 0x6c
} ThrowContext;

typedef struct ExceptionTableIndex {
    u32 unk_00;
    u8 *frameInfo;   // 0x04
} ExceptionTableIndex;

typedef struct ExceptionInfo {
    u32 unk_00[3];
    void *tableStart; // 0x0c
    void *tableEnd;   // 0x10
} ExceptionInfo;

extern "C" {
u8 *DecodeUnsignedNumber(u8 *p, u32 *out);
void __ThrowHandler(ThrowContext *ctx);
extern char __ctype_mapC[];
}

// The exception table start and end are both linked at the same address (the table is empty).
namespace Dup { extern "C" char __ctype_mapC[]; }

extern "C" u32 RestoreSavedRegisters(ThrowContext *ctx) {
    u32 size = ctx->frameSize;
    u32 *p = (u32 *)(ctx->cfa + size - (ctx->savedArgs ? 16 : 0));
    int i;
    for (i = 15; i >= 0; i--) {
        if (ctx->regMask & (1 << i)) {
            ctx->regs[i] = *--p;
        }
    }
    ctx->sp = ctx->cfa + size;
    return ctx->regs[14];
}

extern "C" void SetupFrameInfo(ThrowContext *ctx, ExceptionTableIndex *index) {
    u8 *p = index->frameInfo;
    u8 flags = *p;
    u32 hasFP = flags & 0x40;
    u32 thumb;
    ctx->hasFP = hasFP ? 1 : 0;
    ctx->savedArgs = (flags & 0x20) ? 1 : 0;
    thumb = flags & 0x80;
    ctx->thumbFP = thumb ? 1 : 0;
    ctx->regMask = p[1] << 4;
    ctx->regMask |= 0x4000;
    p = DecodeUnsignedNumber(p + 2, &ctx->frameSize);
    if (hasFP) {
        DecodeUnsignedNumber(p, &ctx->argSize);
    }
    if (hasFP) {
        if (thumb) {
            ctx->cfa = ctx->regs[7];
        } else {
            ctx->cfa = ctx->regs[11];
        }
    } else {
        ctx->cfa = ctx->sp;
    }
}

extern "C" int GetExceptionTable(ExceptionInfo *info, u32 pc) {
    info->tableStart = __ctype_mapC;
    info->tableEnd = Dup::__ctype_mapC;
    return 1;
}

extern "C" u8 *SkipFrameInfo(u8 *p) {
    u8 flags = *p;
    u32 tmp;
    p = DecodeUnsignedNumber(p + 2, &tmp);
    if (flags & 0x40) {
        p = DecodeUnsignedNumber(p, &tmp);
    }
    return p;
}

extern "C" asm void JumpToHandler(register ThrowContext *ctx, register void *unused, register void *addr) {
    ldr r4, [r0, #0x2c]
    ldr r5, [r0, #0x30]
    ldr r6, [r0, #0x34]
    ldr r7, [r0, #0x38]
    ldr r8, [r0, #0x3c]
    ldr r9, [r0, #0x40]
    ldr r10, [r0, #0x44]
    ldr r11, [r0, #0x48]
    ldr sp, [r0, #0x5c]
    ldr ip, [r0, #0x64]
    sub sp, sp, ip
    bx r2
}

extern "C" asm void __rethrow(void) {
    mov ip, sp
    sub sp, sp, #0x70
    str r4, [sp, #0x2c]
    str r5, [sp, #0x30]
    str r6, [sp, #0x34]
    str r7, [sp, #0x38]
    str r8, [sp, #0x3c]
    str r9, [sp, #0x40]
    str r10, [sp, #0x44]
    str r11, [sp, #0x48]
    str ip, [sp, #0x14]
    str ip, [sp, #0x5c]
    str lr, [sp, #0x10]
    mov ip, #0
    str ip, [sp, #0x0]
    str ip, [sp, #0x4]
    str ip, [sp, #0x8]
    mov r0, sp
    b __ThrowHandler
}
