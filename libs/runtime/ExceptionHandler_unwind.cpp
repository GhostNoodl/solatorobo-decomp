#pragma unsigned_char on
extern "C" {
#include "ExceptionHandler.h"
}

// C++ exception unwinder: NextAction (0x02008a20) and UnwindStack (0x02008cdc).
#ifdef NONMATCHING
// Status (round rwA): clean-room rewrite from the target assembly. Neither function matches, so this file has no
// delinks.txt entry and both come from the dsd gap.
// - NextAction: 38 / 38. Every instruction matches except the stack offsets. The target has a 4-byte slot at
//   sp+0x30, between the operands of action 15 (sp+0x34..0x3c) and action 16 (sp+0x24..0x2c), that no
//   instruction reads or writes. This draft has no such slot, so every operand below it is 4 bytes lower and the
//   frame is 0x9c instead of 0xa0. No plain source shape found makes MWCC reserve an unused slot there (an unused
//   local, an unused struct field, a reference parameter, an inline returning a struct, an array). Only a pointer
//   local holding &word does, which is not plausible source.
// - UnwindStack: same slot, plus scheduling and register differences in the array-destroy cases and different
//   cross-jump targets for the shared `actionPointer = next` stores (463 / 460, most of it the shifted offsets).
// The operand locals live in one static inline per action kind: MWCC gives inline locals stack slots in expansion
// order with the last-declared local highest, which is the target's layout. Block-scoped locals of the cases
// themselves would split into two size classes (records over 8 bytes first), which the target does not do.

// Keeps the operand flags and the next-action pointer in their own variables, computed before the decode calls as
// in the target.
#pragma opt_propagation off

// The action list of a function's exception record. Each action starts with a byte: bits 0-4 are
// the action kind, bit 7 marks the last action of the list, and bits 5 and 6 say whether a
// frame-relative operand lives in a saved register instead of in the frame. The operands that
// follow are packed numbers (DecodeSignedNumber / DecodeUnsignedNumber) and raw 32-bit words
// (function addresses).
enum {
    ACT_END_OF_LIST = 0,
    ACT_BRANCH = 1,
    ACT_DESTROY_LOCAL = 2,
    ACT_DESTROY_LOCAL_COND = 3,
    ACT_DESTROY_LOCAL_POINTER = 4,
    ACT_DESTROY_LOCAL_ARRAY = 5,
    ACT_DESTROY_BASE = 6,
    ACT_DESTROY_MEMBER = 7,
    ACT_DESTROY_MEMBER_COND = 8,
    ACT_DESTROY_MEMBER_ARRAY = 9,
    ACT_DELETE_POINTER = 10,
    ACT_DELETE_POINTER_COND = 11,
    ACT_CATCH_BLOCK = 12,
    ACT_ACTIVE_CATCH_BLOCK = 13,
    ACT_TERMINATE = 14,
    ACT_SPECIFICATION = 15,
    ACT_CALL_MEMBER = 16,
    ACT_CALL_MEMBER_PAIR = 17,
    ACT_DESTROY_SIZED_ARRAY = 18,
    ACT_NOP = 19,
};

#define ACT_KIND(b) ((b) & 0x1f)
#define ACT_LAST 0x80
#define ACT_IN_REG 0x20     // the object operand is a register number
#define ACT_COND_IN_REG 0x40 // the condition operand is a register number

typedef void (*DtorFn)(void *obj, int flag);
typedef void (*DeleteFn)(void *obj);
typedef void (*PairFn)(void *a, void *b);

// A word operand of an object: either a saved register or a frame slot.
#define FRAME_WORD(ctx, inReg, where) ((inReg) ? (ctx)->state.regs[where] : *(u32 *)((ctx)->cfa + (where)))

// Skipping an action: decode its operands to find where the next one starts.
static inline u8 *SkipLocal(u8 *p) {
    s32 local;
    return DecodeSignedNumber(p + 1, &local) + 4;
}

static inline u8 *SkipLocalCond(u8 *p) {
    s32 cond, local;
    p = DecodeSignedNumber(p + 1, &cond);
    return DecodeSignedNumber(p, &local) + 4;
}

static inline u8 *SkipLocalArray(u8 *p) {
    s32 local;
    u32 count, size;
    p = DecodeSignedNumber(p + 1, &local);
    p = DecodeUnsignedNumber(p, &count);
    return DecodeUnsignedNumber(p, &size) + 4;
}

static inline u8 *SkipMember(u8 *p) {
    s32 object, offset;
    p = DecodeSignedNumber(p + 1, &object);
    return DecodeSignedNumber(p, &offset) + 4;
}

static inline u8 *SkipMemberCond(u8 *p) {
    s32 cond, object, offset;
    p = DecodeSignedNumber(p + 1, &cond);
    p = DecodeSignedNumber(p, &object);
    return DecodeSignedNumber(p, &offset) + 4;
}

static inline u8 *SkipMemberArray(u8 *p) {
    s32 object, offset;
    u32 count, size;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    p = DecodeUnsignedNumber(p, &count);
    return DecodeUnsignedNumber(p, &size) + 4;
}

static inline u8 *SkipPointerCond(u8 *p) {
    s32 cond, pointer;
    p = DecodeSignedNumber(p + 1, &cond);
    return DecodeSignedNumber(p, &pointer) + 4;
}

static inline u8 *SkipCatch(u8 *p) {
    u32 handler;
    s32 info;
    p = DecodeUnsignedNumber(p + 5, &handler);
    return DecodeSignedNumber(p, &info);
}

static inline u8 *SkipActiveCatch(u8 *p) {
    s32 info;
    return DecodeSignedNumber(p + 1, &info);
}

static inline u8 *SkipSpecification(u8 *p) {
    u32 count, handler;
    s32 info;
    p = DecodeUnsignedNumber(p + 1, &count);
    p = DecodeUnsignedNumber(p, &handler);
    return DecodeSignedNumber(p, &info) + count * 4;
}

static inline u8 *TakeWord(u8 *p, u32 *out) {
    *out = ReadWord(p);
    return p + 4;
}

static inline u8 *SkipCallMember(u8 *p) {
    s32 object, offset, argOffset;
    u32 base;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    p = TakeWord(p, &base);
    return DecodeSignedNumber(p, &argOffset) + 4;
}

static inline u8 *SkipCallMemberPair(u8 *p) {
    s32 object, object2, offset, offset2;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    p = DecodeSignedNumber(p + 1, &object2);
    return DecodeSignedNumber(p, &offset2) + 4;
}

static inline u8 *SkipSizedArray(u8 *p) {
    s32 object, bytes;
    u32 size;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p + 1, &bytes);
    return DecodeUnsignedNumber(p, &size) + 4;
}

static inline u8 *SkipNop(u8 *p) {
    s32 value;
    return DecodeSignedNumber(p + 1, &value);
}

// Follows branch actions; returns the kind of the action it stops at.
static inline u8 FollowBranches(ExceptionInfo *info) {
    u8 *p = info->actionPointer;
    u8 kind;
    s32 offset;
    while ((kind = ACT_KIND(*p)) == ACT_BRANCH) {
        DecodeSignedNumber(p + 1, &offset);
        p = info->actionPointer += offset;
    }
    return kind;
}

u8 NextAction(ActionIterator *iter) {
    u8 *ap;
    for (;;) {
        ap = iter->info.actionPointer;
        if (ap == NULL || (*ap & ACT_LAST)) {
            FindExceptionRecord(RestoreSavedRegisters(&iter->context, &iter->info), &iter->info);
            if (iter->info.exceptionRecord == NULL) {
                return 0xff;
            }
            SetupFrameInfo(&iter->context, &iter->info);
            if (iter->info.actionPointer == NULL) {
                continue;
            }
            break;
        }
        switch (ACT_KIND(*ap)) {
        case ACT_DESTROY_LOCAL:
            iter->info.actionPointer = SkipLocal(ap);
            break;
        case ACT_DESTROY_LOCAL_COND:
            iter->info.actionPointer = SkipLocalCond(ap);
            break;
        case ACT_DESTROY_LOCAL_POINTER:
            iter->info.actionPointer = SkipLocal(ap);
            break;
        case ACT_DESTROY_LOCAL_ARRAY:
            iter->info.actionPointer = SkipLocalArray(ap);
            break;
        case ACT_DESTROY_BASE:
            iter->info.actionPointer = SkipMember(ap);
            break;
        case ACT_DESTROY_MEMBER:
            iter->info.actionPointer = SkipMember(ap);
            break;
        case ACT_DESTROY_MEMBER_COND:
            iter->info.actionPointer = SkipMemberCond(ap);
            break;
        case ACT_DESTROY_MEMBER_ARRAY:
            iter->info.actionPointer = SkipMemberArray(ap);
            break;
        case ACT_DELETE_POINTER:
            iter->info.actionPointer = SkipLocal(ap);
            break;
        case ACT_DELETE_POINTER_COND:
            iter->info.actionPointer = SkipPointerCond(ap);
            break;
        case ACT_CATCH_BLOCK:
            iter->info.actionPointer = SkipCatch(ap);
            break;
        case ACT_ACTIVE_CATCH_BLOCK:
            iter->info.actionPointer = SkipActiveCatch(ap);
            break;
        case ACT_SPECIFICATION:
            iter->info.actionPointer = SkipSpecification(ap);
            break;
        case ACT_CALL_MEMBER:
            iter->info.actionPointer = SkipCallMember(ap);
            break;
        case ACT_CALL_MEMBER_PAIR:
            iter->info.actionPointer = SkipCallMemberPair(ap);
            break;
        case ACT_DESTROY_SIZED_ARRAY:
            iter->info.actionPointer = SkipSizedArray(ap);
            break;
        case ACT_NOP:
            iter->info.actionPointer = SkipNop(ap);
            break;
        default:
            return 0xff;
        }
        break;
    }
    return FollowBranches(&iter->info);
}

// Running an action: decode its operands, destroy what it names, return where the next one starts.
// inReg says whether the object operand is a register number (ACT_IN_REG).
static inline u8 *DestroyLocal(ThrowContext *ctx, u8 *p) {
    s32 local;
    p = DecodeSignedNumber(p + 1, &local);
    ((DtorFn)ReadWord(p))((void *)(ctx->cfa + local), -1);
    return p + 4;
}

static inline u8 *DestroyLocalCond(ThrowContext *ctx, u8 flags, u8 *p) {
    int condInReg = flags & ACT_COND_IN_REG;
    s32 cond, local;
    DtorFn dtor;
    u8 alive;
    p = DecodeSignedNumber(p + 1, &cond);
    p = DecodeSignedNumber(p, &local);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    alive = condInReg ? (u8)ctx->state.regs[cond] : *(u8 *)(ctx->cfa + cond);
    if (alive) {
        dtor((void *)(ctx->cfa + local), -1);
    }
    return p;
}

static inline u8 *DestroyLocalPointer(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 pointer;
    DtorFn dtor;
    p = DecodeSignedNumber(p + 1, &pointer);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    dtor((void *)FRAME_WORD(ctx, inReg, pointer), -1);
    return p;
}

static inline u8 *DestroyLocalArray(ThrowContext *ctx, u8 *p) {
    s32 local;
    u32 count, size, i;
    DtorFn dtor;
    u8 *obj;
    p = DecodeSignedNumber(p + 1, &local);
    p = DecodeUnsignedNumber(p, &count);
    p = DecodeUnsignedNumber(p, &size);
    obj = (u8 *)(ctx->cfa + local) + count * size;
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    for (i = count; i != 0; i--) {
        obj -= size;
        dtor(obj, -1);
    }
    return p;
}

static inline u8 *DestroyMember(ThrowContext *ctx, u8 flags, u8 *p, int flag) {
    int inReg = flags & ACT_IN_REG;
    s32 object, offset;
    DtorFn dtor;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    dtor((void *)(FRAME_WORD(ctx, inReg, object) + offset), flag);
    return p;
}

static inline u8 *DestroyMemberCond(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 cond, object, offset;
    DtorFn dtor;
    s16 alive;
    p = DecodeSignedNumber(p + 1, &cond);
    p = DecodeSignedNumber(p, &object);
    p = DecodeSignedNumber(p, &offset);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    alive = (flags & ACT_COND_IN_REG) ? (s16)ctx->state.regs[cond] : *(s16 *)(ctx->cfa + cond);
    if (alive) {
        dtor((void *)(FRAME_WORD(ctx, inReg, object) + offset), -1);
    }
    return p;
}

static inline u8 *DestroyMemberArray(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 object, offset;
    u32 count, size, i;
    DtorFn dtor;
    u8 *obj;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    p = DecodeUnsignedNumber(p, &count);
    p = DecodeUnsignedNumber(p, &size);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    obj = (u8 *)(FRAME_WORD(ctx, inReg, object) + offset) + count * size;
    for (i = count; i != 0; i--) {
        obj -= size;
        dtor(obj, -1);
    }
    return p;
}

static inline u8 *DeletePointer(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 pointer;
    DeleteFn del;
    p = DecodeSignedNumber(p + 1, &pointer);
    del = (DeleteFn)ReadWord(p);
    p += 4;
    del((void *)FRAME_WORD(ctx, inReg, pointer));
    return p;
}

static inline u8 *DeletePointerCond(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 cond, pointer;
    DeleteFn del;
    u8 alive;
    p = DecodeSignedNumber(p + 1, &cond);
    p = DecodeSignedNumber(p, &pointer);
    del = (DeleteFn)ReadWord(p);
    p += 4;
    alive = (flags & ACT_COND_IN_REG) ? (u8)ctx->state.regs[cond] : *(u8 *)(ctx->cfa + cond);
    if (alive) {
        del((void *)FRAME_WORD(ctx, inReg, pointer));
    }
    return p;
}

static inline u8 *EndActiveCatch(ThrowContext *ctx, u8 *p) {
    s32 info;
    CatchInfo *record;
    p = DecodeSignedNumber(p + 1, &info);
    record = (CatchInfo *)(ctx->cfa + info);
    if (record->dtor != NULL) {
        if (record->location == ctx->location) {
            ctx->dtor = (void *)record->dtor;
        } else {
            record->dtor(record->location, -1);
        }
    }
    return p;
}

static inline u8 *CallMember(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    s32 object, offset, argOffset;
    u32 arg;
    PairFn fn;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    arg = ReadWord(p);
    p = DecodeSignedNumber(p + 4, &argOffset);
    fn = (PairFn)ReadWord(p);
    p += 4;
    fn((void *)(FRAME_WORD(ctx, inReg, object) + offset), (void *)(arg + argOffset));
    return p;
}

static inline u8 *CallMemberPair(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    int inReg2;
    s32 object, object2, offset, offset2;
    PairFn fn;
    p = DecodeSignedNumber(p + 1, &object);
    p = DecodeSignedNumber(p, &offset);
    inReg2 = *p++ & ACT_IN_REG;
    p = DecodeSignedNumber(p, &object2);
    p = DecodeSignedNumber(p, &offset2);
    fn = (PairFn)ReadWord(p);
    p += 4;
    fn((void *)(FRAME_WORD(ctx, inReg, object) + offset), (void *)(FRAME_WORD(ctx, inReg2, object2) + offset2));
    return p;
}

static inline u8 *DestroySizedArray(ThrowContext *ctx, u8 flags, u8 *p) {
    int inReg = flags & ACT_IN_REG;
    int inReg2;
    s32 object, bytes;
    u32 size, i, total;
    DtorFn dtor;
    u8 *obj;
    p = DecodeSignedNumber(p + 1, &object);
    inReg2 = *p++ & ACT_IN_REG;
    p = DecodeSignedNumber(p, &bytes);
    p = DecodeUnsignedNumber(p, &size);
    dtor = (DtorFn)ReadWord(p);
    p += 4;
    obj = (u8 *)FRAME_WORD(ctx, inReg, object);
    total = FRAME_WORD(ctx, inReg2, bytes);
    obj += total;
    for (i = total / size; i != 0; i--) {
        obj -= size;
        dtor(obj, -1);
    }
    return p;
}

static inline void TakeBranch(ExceptionInfo *info, u8 *p) {
    s32 offset;
    DecodeSignedNumber(p + 1, &offset);
    info->actionPointer += offset;
}

void UnwindStack(ThrowContext *ctx, ExceptionInfo *info, u8 *catcher) {
    u8 *ap;
    u8 flags;
    for (;;) {
        if (info->actionPointer == NULL) {
            FindExceptionRecord(RestoreSavedRegisters(ctx, info), info);
            if (info->exceptionRecord == NULL) {
                _ZSt9terminatev();
            }
            SetupFrameInfo(ctx, info);
            if (info->actionPointer == NULL) {
                continue;
            }
        }
        ap = info->actionPointer;
        flags = *ap;
        switch (ACT_KIND(flags)) {
        case ACT_BRANCH:
            TakeBranch(info, ap);
            break;
        case ACT_DESTROY_LOCAL:
            info->actionPointer = DestroyLocal(ctx, ap);
            break;
        case ACT_DESTROY_LOCAL_COND:
            info->actionPointer = DestroyLocalCond(ctx, flags, ap);
            break;
        case ACT_DESTROY_LOCAL_POINTER:
            info->actionPointer = DestroyLocalPointer(ctx, flags, ap);
            break;
        case ACT_DESTROY_LOCAL_ARRAY:
            info->actionPointer = DestroyLocalArray(ctx, ap);
            break;
        case ACT_DESTROY_BASE:
            info->actionPointer = DestroyMember(ctx, flags, ap, 0);
            break;
        case ACT_DESTROY_MEMBER:
            info->actionPointer = DestroyMember(ctx, flags, ap, -1);
            break;
        case ACT_DESTROY_MEMBER_COND:
            info->actionPointer = DestroyMemberCond(ctx, flags, ap);
            break;
        case ACT_DESTROY_MEMBER_ARRAY:
            info->actionPointer = DestroyMemberArray(ctx, flags, ap);
            break;
        case ACT_DELETE_POINTER:
            info->actionPointer = DeletePointer(ctx, flags, ap);
            break;
        case ACT_DELETE_POINTER_COND:
            info->actionPointer = DeletePointerCond(ctx, flags, ap);
            break;
        case ACT_CATCH_BLOCK:
            if (ap == catcher) {
                return;
            }
            info->actionPointer = SkipCatch(ap);
            break;
        case ACT_ACTIVE_CATCH_BLOCK:
            info->actionPointer = EndActiveCatch(ctx, ap);
            break;
        case ACT_SPECIFICATION:
            if (ap == catcher) {
                return;
            }
            info->actionPointer = SkipSpecification(ap);
            break;
        case ACT_CALL_MEMBER:
            info->actionPointer = CallMember(ctx, flags, ap);
            break;
        case ACT_CALL_MEMBER_PAIR:
            info->actionPointer = CallMemberPair(ctx, flags, ap);
            break;
        case ACT_DESTROY_SIZED_ARRAY:
            info->actionPointer = DestroySizedArray(ctx, flags, ap);
            break;
        case ACT_NOP:
            info->actionPointer = SkipNop(ap);
            break;
        default:
            _ZSt9terminatev();
            break;
        }
        if (flags & ACT_LAST) {
            info->actionPointer = NULL;
        }
    }
}

#endif // NONMATCHING
