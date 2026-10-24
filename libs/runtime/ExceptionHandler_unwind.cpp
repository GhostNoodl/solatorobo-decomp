// NextAction and UnwindStack. UnwindStack runs the cleanup actions of each frame up to the catcher's action.
// The original was C++ with exceptions on and : that stops MWCC from
// cross-jumping the destructor calls of different actions. With opt_propagation off the action flags
// and the advanced action pointer are computed early, as in the target. Every decoded number lives in
// one Ops struct, which fixes the stack layout (including the unused word at sp+0x30).
#pragma exceptions on
extern "C" {
#pragma opt_propagation off
#pragma unsigned_char on
#include "ExceptionHandler.h"

typedef void (*DtorFn)(void *obj, int flag);
typedef void (*DelFn)(void *obj);
typedef void (*Dtor2Fn)(void *obj, void *arg);

#define CFA(ctx) ((u8 *)(ctx)->cfa)
#define REG(ctx, i) ((ctx)->state.regs[i])

typedef struct Ops {
    s32 c19_x;
    s32 c18_a;
    s32 c18_b;
    u32 c18_elementSize;
    s32 c17_a;
    s32 c17_c;
    s32 c17_b;
    s32 c17_d;
    s32 c16_objectPointer;
    s32 c16_offset;
    s32 c16_offset2;
    s32 unused;
    u32 c15_specs;
    u32 c15_pcOffset;
    s32 c15_cinfoRef;
    s32 c13_cinfoRef;
    u32 c12_catchPCOffset;
    s32 c12_cinfoRef;
    s32 c11_cond;
    s32 c11_pointerObject;
    s32 c10_pointerObject;
    s32 c9_objectPointer;
    s32 c9_offset;
    u32 c9_elements;
    u32 c9_elementSize;
    s32 c8_cond;
    s32 c8_objectPointer;
    s32 c8_offset;
    s32 c7_objectPointer;
    s32 c7_offset;
    s32 c6_objectPointer;
    s32 c6_offset;
    s32 c5_array;
    u32 c5_elements;
    u32 c5_elementSize;
    s32 c4_pointer;
    s32 c3_cond;
    s32 c3_local;
    s32 c2_local;
    s32 c1_offset;
} Ops;

// NextAction skips the same records; its numbers are decoded into the same layout, without the branch offset.
typedef struct IterOps {
    s32 c19_x;
    s32 c18_a;
    s32 c18_b;
    u32 c18_elementSize;
    s32 c17_a;
    s32 c17_c;
    s32 c17_b;
    s32 c17_d;
    s32 c16_objectPointer;
    s32 c16_offset;
    s32 c16_offset2;
    s32 unused;
    u32 c15_specs;
    u32 c15_pcOffset;
    s32 c15_cinfoRef;
    s32 c13_cinfoRef;
    u32 c12_catchPCOffset;
    s32 c12_cinfoRef;
    s32 c11_cond;
    s32 c11_pointerObject;
    s32 c10_pointerObject;
    s32 c9_objectPointer;
    s32 c9_offset;
    u32 c9_elements;
    u32 c9_elementSize;
    s32 c8_cond;
    s32 c8_objectPointer;
    s32 c8_offset;
    s32 c7_objectPointer;
    s32 c7_offset;
    s32 c6_objectPointer;
    s32 c6_offset;
    s32 c5_array;
    u32 c5_elements;
    u32 c5_elementSize;
    s32 c4_pointer;
    s32 c3_cond;
    s32 c3_local;
    s32 c2_local;
} IterOps;

u8 NextAction(ActionIterator *iter) {
    u8 *p;
    u8 action;
    s32 offset;
    IterOps o;
    for (;;) {
        p = iter->info.actionPointer;
        if (p == NULL || ((action = *p) & 0x80)) {
            FindExceptionRecord(RestoreSavedRegisters(&iter->context, iter), &iter->info);
            if (iter->info.exceptionRecord == NULL) {
                return 0xff;
            }
            SetupFrameInfo(&iter->context, &iter->info);
            if (iter->info.actionPointer == NULL) {
                continue;
            }
            break;
        }
        switch (action & 0x1f) {
        case 2:
            iter->info.actionPointer = DecodeSignedNumber(p + 1, &o.c2_local) + 4;
            break;
        case 3:
            p = DecodeSignedNumber(p + 1, &o.c3_cond);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c3_local) + 4;
            break;
        case 4:
            iter->info.actionPointer = DecodeSignedNumber(p + 1, &o.c4_pointer) + 4;
            break;
        case 5:
            p = DecodeSignedNumber(p + 1, &o.c5_array);
            p = DecodeUnsignedNumber(p, &o.c5_elements);
            iter->info.actionPointer = DecodeUnsignedNumber(p, &o.c5_elementSize) + 4;
            break;
        case 6:
            p = DecodeSignedNumber(p + 1, &o.c6_objectPointer);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c6_offset) + 4;
            break;
        case 7:
            p = DecodeSignedNumber(p + 1, &o.c7_objectPointer);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c7_offset) + 4;
            break;
        case 8:
            p = DecodeSignedNumber(p + 1, &o.c8_cond);
            p = DecodeSignedNumber(p, &o.c8_objectPointer);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c8_offset) + 4;
            break;
        case 9:
            p = DecodeSignedNumber(p + 1, &o.c9_objectPointer);
            p = DecodeSignedNumber(p, &o.c9_offset);
            p = DecodeUnsignedNumber(p, &o.c9_elements);
            iter->info.actionPointer = DecodeUnsignedNumber(p, &o.c9_elementSize) + 4;
            break;
        case 10:
            iter->info.actionPointer = DecodeSignedNumber(p + 1, &o.c10_pointerObject) + 4;
            break;
        case 11:
            p = DecodeSignedNumber(p + 1, &o.c11_cond);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c11_pointerObject) + 4;
            break;
        case 12:
            p = DecodeUnsignedNumber(p + 5, &o.c12_catchPCOffset);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c12_cinfoRef);
            break;
        case 13:
            iter->info.actionPointer = DecodeSignedNumber(p + 1, &o.c13_cinfoRef);
            break;
        case 15:
            p = DecodeUnsignedNumber(p + 1, &o.c15_specs);
            p = DecodeUnsignedNumber(p, &o.c15_pcOffset);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c15_cinfoRef) + o.c15_specs * 4;
            break;
        case 16:
            p = DecodeSignedNumber(p + 1, &o.c16_objectPointer);
            p = DecodeSignedNumber(p, &o.c16_offset);
            p = DecodeSignedNumber(p + 4, &o.c16_offset2);
            iter->info.actionPointer = p + 4;
            break;
        case 17:
            p = DecodeSignedNumber(p + 1, &o.c17_a);
            p = DecodeSignedNumber(p, &o.c17_b);
            p = DecodeSignedNumber(p + 1, &o.c17_c);
            iter->info.actionPointer = DecodeSignedNumber(p, &o.c17_d) + 4;
            break;
        case 18:
            p = DecodeSignedNumber(p + 1, &o.c18_a);
            p = DecodeSignedNumber(p + 1, &o.c18_b);
            iter->info.actionPointer = DecodeUnsignedNumber(p, &o.c18_elementSize) + 4;
            break;
        case 19:
            iter->info.actionPointer = DecodeSignedNumber(p + 1, &o.c19_x);
            break;
        default:
            return 0xff;
        }
        break;
    }
    while ((action = *iter->info.actionPointer & 0x1f) == 1) {
        DecodeSignedNumber(iter->info.actionPointer + 1, &offset);
        iter->info.actionPointer += offset;
    }
    return action;
}


void UnwindStack(ThrowContext *context, ExceptionInfo *info, u8 *catcher) {
#pragma exception_terminate
    u8 *p;
    u8 action;
    Ops o;

    for (;;) {
        p = info->actionPointer;
        if (p == NULL) {
            FindExceptionRecord(RestoreSavedRegisters(context, (ActionIterator *)info), info);
            if (info->exceptionRecord == NULL) {
                _ZSt9terminatev();
            }
            SetupFrameInfo(context, info);
            p = info->actionPointer;
            if (p == NULL) {
                continue;
            }
        }
        action = *p;
        switch (action & 0x1f) {
        case 1: {
            DecodeSignedNumber(p + 1, &o.c1_offset);
            info->actionPointer += o.c1_offset;
            break;
        }
        case 2: {
            DtorFn dtor;
            u8 *obj;
            p = DecodeSignedNumber(p + 1, &o.c2_local);
            obj = CFA(context) + o.c2_local;
            dtor = (DtorFn)ReadWord(p);
            dtor(obj, -1);
            info->actionPointer = p + 4;
            break;
        }
        case 3: {
            DtorFn dtor;
            u8 c;
            s32 isReg;
            isReg = action & 0x40;
            p = DecodeSignedNumber(p + 1, &o.c3_cond);
            p = DecodeSignedNumber(p, &o.c3_local);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                c = REG(context, o.c3_cond);
            } else {
                c = *(u8 *)(CFA(context) + o.c3_cond);
            }
            if (c) {
                dtor(CFA(context) + o.c3_local, -1);
            }
            info->actionPointer = p;
            break;
        }
        case 4: {
            DtorFn dtor;
            void *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c4_pointer);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj = (void *)REG(context, o.c4_pointer);
            } else {
                obj = *(void **)(CFA(context) + o.c4_pointer);
            }
            dtor(obj, -1);
            info->actionPointer = p;
            break;
        }
        case 5: {
            u8 *ptr;
            DtorFn dtor;
            u32 n;
            p = DecodeSignedNumber(p + 1, &o.c5_array);
            p = DecodeUnsignedNumber(p, &o.c5_elements);
            p = DecodeUnsignedNumber(p, &o.c5_elementSize);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            ptr = CFA(context) + o.c5_array + o.c5_elements * o.c5_elementSize;
            for (n = o.c5_elements; n != 0; n--) {
                ptr -= o.c5_elementSize;
                dtor(ptr, -1);
            }
            info->actionPointer = p;
            break;
        }
        case 6: {
            DtorFn dtor;
            u8 *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c6_objectPointer);
            p = DecodeSignedNumber(p, &o.c6_offset);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj = (u8 *)REG(context, o.c6_objectPointer);
            } else {
                obj = *(u8 **)(CFA(context) + o.c6_objectPointer);
            }
            dtor(obj + o.c6_offset, 0);
            info->actionPointer = p;
            break;
        }
        case 7: {
            DtorFn dtor;
            u8 *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c7_objectPointer);
            p = DecodeSignedNumber(p, &o.c7_offset);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj = (u8 *)REG(context, o.c7_objectPointer);
            } else {
                obj = *(u8 **)(CFA(context) + o.c7_objectPointer);
            }
            dtor(obj + o.c7_offset, -1);
            info->actionPointer = p;
            break;
        }
        case 8: {
            DtorFn dtor;
            s16 c;
            u8 *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c8_cond);
            p = DecodeSignedNumber(p, &o.c8_objectPointer);
            p = DecodeSignedNumber(p, &o.c8_offset);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (action & 0x40) {
                c = REG(context, o.c8_cond);
            } else {
                c = *(s16 *)(CFA(context) + o.c8_cond);
            }
            if (c) {
                if (isReg) {
                    obj = (u8 *)REG(context, o.c8_objectPointer);
                } else {
                    obj = *(u8 **)(CFA(context) + o.c8_objectPointer);
                }
                dtor(obj + o.c8_offset, -1);
            }
            info->actionPointer = p;
            break;
        }
        case 9: {
            u8 *ptr;
            DtorFn dtor;
            u32 n;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c9_objectPointer);
            p = DecodeSignedNumber(p, &o.c9_offset);
            p = DecodeUnsignedNumber(p, &o.c9_elements);
            p = DecodeUnsignedNumber(p, &o.c9_elementSize);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                ptr = (u8 *)REG(context, o.c9_objectPointer) + o.c9_offset;
            } else {
                ptr = *(u8 **)(CFA(context) + o.c9_objectPointer) + o.c9_offset;
            }
            ptr += o.c9_elements * o.c9_elementSize;
            for (n = o.c9_elements; n != 0; n--) {
                ptr -= o.c9_elementSize;
                dtor(ptr, -1);
            }
            info->actionPointer = p;
            break;
        }
        case 10: {
            DelFn del;
            void *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c10_pointerObject);
            del = (DelFn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj = (void *)REG(context, o.c10_pointerObject);
            } else {
                obj = *(void **)(CFA(context) + o.c10_pointerObject);
            }
            del(obj);
            info->actionPointer = p;
            break;
        }
        case 11: {
            DelFn del;
            u8 c;
            void *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c11_cond);
            p = DecodeSignedNumber(p, &o.c11_pointerObject);
            del = (DelFn)ReadWord(p);
            p += 4;
            if (action & 0x40) {
                c = REG(context, o.c11_cond);
            } else {
                c = *(u8 *)(CFA(context) + o.c11_cond);
            }
            if (c) {
                if (isReg) {
                    obj = (void *)REG(context, o.c11_pointerObject);
                } else {
                    obj = *(void **)(CFA(context) + o.c11_pointerObject);
                }
                del(obj);
            }
            info->actionPointer = p;
            break;
        }
        case 12: {
            if (catcher == p) {
                return;
            }
            p = DecodeUnsignedNumber(p + 5, &o.c12_catchPCOffset);
            info->actionPointer = DecodeSignedNumber(p, &o.c12_cinfoRef);
            break;
        }
        case 13: {
            CatchInfo *catchinfo;
            p = DecodeSignedNumber(p + 1, &o.c13_cinfoRef);
            catchinfo = (CatchInfo *)(CFA(context) + o.c13_cinfoRef);
            if (catchinfo->dtor != NULL) {
                if (context->location == catchinfo->location) {
                    context->dtor = catchinfo->dtor;
                } else {
                    catchinfo->dtor(catchinfo->location, -1);
                }
            }
            info->actionPointer = p;
            break;
        }
        case 15: {
            if (catcher == p) {
                return;
            }
            p = DecodeUnsignedNumber(p + 1, &o.c15_specs);
            p = DecodeUnsignedNumber(p, &o.c15_pcOffset);
            p = DecodeSignedNumber(p, &o.c15_cinfoRef);
            info->actionPointer = p + o.c15_specs * 4;
            break;
        }
        case 16: {
            u8 *fn;
            Dtor2Fn dtor;
            u8 *obj;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c16_objectPointer);
            p = DecodeSignedNumber(p, &o.c16_offset);
            fn = (u8 *)ReadWord(p);
            p = DecodeSignedNumber(p + 4, &o.c16_offset2);
            dtor = (Dtor2Fn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj = (u8 *)REG(context, o.c16_objectPointer);
            } else {
                obj = *(u8 **)(CFA(context) + o.c16_objectPointer);
            }
            dtor(obj + o.c16_offset, fn + o.c16_offset2);
            info->actionPointer = p;
            break;
        }
        case 17: {
            s32 flag;
            Dtor2Fn dtor;
            u8 *obj1;
            u8 *obj2;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c17_a);
            p = DecodeSignedNumber(p, &o.c17_b);
            flag = *p++ & 0x20;
            p = DecodeSignedNumber(p, &o.c17_c);
            p = DecodeSignedNumber(p, &o.c17_d);
            dtor = (Dtor2Fn)ReadWord(p);
            p += 4;
            if (isReg) {
                obj1 = (u8 *)REG(context, o.c17_a);
            } else {
                obj1 = *(u8 **)(CFA(context) + o.c17_a);
            }
            if (flag) {
                obj2 = (u8 *)REG(context, o.c17_c);
            } else {
                obj2 = *(u8 **)(CFA(context) + o.c17_c);
            }
            dtor(obj1 + o.c17_b, obj2 + o.c17_d);
            info->actionPointer = p;
            break;
        }
        case 18: {
            s32 flag;
            u8 *ptr;
            DtorFn dtor;
            u32 size;
            u32 n;
            s32 isReg;
            isReg = action & 0x20;
            p = DecodeSignedNumber(p + 1, &o.c18_a);
            flag = *p++ & 0x20;
            p = DecodeSignedNumber(p, &o.c18_b);
            p = DecodeUnsignedNumber(p, &o.c18_elementSize);
            dtor = (DtorFn)ReadWord(p);
            p += 4;
            if (isReg) {
                ptr = (u8 *)REG(context, o.c18_a);
            } else {
                ptr = *(u8 **)(CFA(context) + o.c18_a);
            }
            if (flag) {
                size = REG(context, o.c18_b);
            } else {
                size = *(u32 *)(CFA(context) + o.c18_b);
            }
            ptr += size;
            for (n = size / o.c18_elementSize; n != 0; n--) {
                ptr -= o.c18_elementSize;
                dtor(ptr, -1);
            }
            info->actionPointer = p;
            break;
        }
        case 19: {
            info->actionPointer = DecodeSignedNumber(p + 1, &o.c19_x);
            break;
        }
        default:
            _ZSt9terminatev();
            break;
        }
        if (action & 0x80) {
            info->actionPointer = NULL;
        }
    }
}

}
