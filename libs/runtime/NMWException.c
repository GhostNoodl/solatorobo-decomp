#include "types.h"
#pragma unsigned_char on

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

typedef void (*DtorFunc)(void *obj, int flag);
typedef void (*VoidFunc)(void);

typedef struct CatchInfo {
    void *location;
    void *typeinfo;
    DtorFunc dtor;
} CatchInfo;

extern DestructorChain *__global_destructor_chain;
extern VoidFunc thandler;
void abort(void);
void _ZSt9terminatev(void);

void __end__catch(CatchInfo *catchinfo) {
    if (catchinfo->location != NULL && catchinfo->dtor != NULL) {
        catchinfo->dtor(catchinfo->location, -1);
    }
}

void __call_static_initializers(void) {
    VoidFunc *p;
    for (p = (VoidFunc *)0x0208aa68; p != NULL && *p != NULL; p++) {
        (*p)();
    }
}

void __destroy_global_chain(void) {
    DestructorChain *gdc;
    while ((gdc = __global_destructor_chain) != NULL) {
        __global_destructor_chain = gdc->next;
        ((DtorFunc)gdc->destructor)(gdc->object, -1);
    }
}

void dthandler(void) {
    abort();
}

void duhandler(void) {
    _ZSt9terminatev();
}

void _ZSt9terminatev(void) {
    thandler();
}

void __register_global_object(void *object, void *destructor, void *regmem) {
    ((DestructorChain *)regmem)->next = __global_destructor_chain;
    ((DestructorChain *)regmem)->destructor = destructor;
    ((DestructorChain *)regmem)->object = object;
    __global_destructor_chain = (DestructorChain *)regmem;
}

int __throw_catch_compare(const char *throwtype, const char *catchtype, s32 *offset_result) {
    const char *cptr1, *cptr2;

    *offset_result = 0;
    if ((cptr2 = catchtype) == NULL) {
        return 1;
    }
    cptr1 = throwtype;

    if (*cptr2 == 'P') {
        cptr2++;
        if (*cptr2 == 'V') cptr2++;
        if (*cptr2 == 'K') cptr2++;
        if (*cptr2 == 'v') {
            if (*cptr1 == 'P' || *cptr1 == '*') {
                return 1;
            }
        }
        cptr2 = catchtype;
    }

    switch (*cptr1) {
    case '*':
    case '!':
        if (*cptr1++ != *cptr2++) return 0;
        for (;;) {
            if (*cptr1 == *cptr2++) {
                if (*cptr1++ == '!') {
                    s32 offset;
                    for (offset = 0; *cptr1 != '!';) offset = offset * 10 + *cptr1++ - '0';
                    *offset_result = offset;
                    return 1;
                }
            } else {
                while (*cptr1++ != '!') ;
                while (*cptr1++ != '!') ;
                if (*cptr1 == 0) return 0;
                cptr2 = catchtype + 1;
            }
        }
        return 0;
    }

    while ((*cptr1 == 'P' || *cptr1 == 'R') && *cptr1 == *cptr2) {
        cptr1++;
        cptr2++;
        if (*cptr2 == 'K') {
            if (*cptr1 == 'K') cptr1++;
            cptr2++;
        }
        if (*cptr1 == 'K') return 0;
        if (*cptr2 == 'V') {
            if (*cptr1 == 'V') cptr1++;
            cptr2++;
        }
        if (*cptr1 == 'V') return 0;
    }

    for (; *cptr1 == *cptr2; cptr1++, cptr2++) {
        if (*cptr1 == 0) return 1;
    }
    return 0;
}
