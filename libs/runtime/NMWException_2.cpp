#pragma unsigned_char on
#pragma exceptions on
#include "types.h"

// Itanium C++ ABI array construction/destruction helpers (compiled with exceptions enabled).

typedef void (*ConstructorDestructor)(void *);

extern "C" {
void *func_0203dddc(u32 size); // operator new[]
void func_0203de50(void *p);   // operator delete[]
void _ZSt9terminatev(void);

static void __destroy_partial_array(char *start, char *end, u32 size, ConstructorDestructor dtor) {
    try {
        while (end > start) {
            end -= size;
            dtor(end);
        }
    } catch (...) {
        _ZSt9terminatev();
    }
}

void *__cxa_vec_new(u32 count, u32 size, u32 padding, ConstructorDestructor ctor, ConstructorDestructor dtor) {
    char *mem = (char *)func_0203dddc(count * size + padding);
    char *p;
    if (mem == NULL) {
        return NULL;
    }
    if (padding != 0) {
        ((u32 *)(mem + padding))[-1] = count;
        if (padding >= 8) {
            ((u32 *)(mem + padding))[-2] = size;
        }
    }
    if (ctor != NULL) {
        u32 i;
        p = mem + padding;
        try {
            for (i = count; i != 0; i--) {
                ctor(p);
                p += size;
            }
        } catch (...) {
            if (dtor != NULL) {
                __destroy_partial_array(mem + padding, p, size, dtor);
            }
            func_0203de50(mem);
            throw;
        }
    }
    return mem + padding;
}

void __cxa_vec_ctor(void *array, u32 count, u32 size, ConstructorDestructor ctor, ConstructorDestructor dtor) {
    char *p;
    u32 i;
    if (ctor == NULL) {
        return;
    }
    if (dtor != NULL) {
        p = (char *)array;
        try {
            for (i = count; i != 0; i--) {
                ctor(p);
                p += size;
            }
        } catch (...) {
            __destroy_partial_array((char *)array, p, size, dtor);
            throw;
        }
    } else {
        p = (char *)array;
        for (i = count; i != 0; i--) {
            ctor(p);
            p += size;
        }
    }
}

void __cxa_vec_dtor(void *array, u32 count, u32 size, ConstructorDestructor dtor) {
    char *p;
    if (dtor != NULL) {
        p = (char *)array + count * size;
        try {
            for (; count != 0; count--) {
                p -= size;
                dtor(p);
            }
        } catch (...) {
            try {
                while (--count != 0) {
                    p -= size;
                    dtor(p);
                }
            } catch (...) {
                _ZSt9terminatev();
            }
            throw;
        }
    }
}

void __cxa_vec_cleanup(void *array, u32 count, u32 size, ConstructorDestructor dtor) {
    char *p;
    if (dtor != NULL) {
        p = (char *)array + count * size;
        try {
            for (; count != 0; count--) {
                p -= size;
                dtor(p);
            }
        } catch (...) {
            _ZSt9terminatev();
        }
    }
}

void __cxa_vec_delete(void *array, u32 size, u32 padding, ConstructorDestructor dtor) {
    if (array == NULL) {
        return;
    }
    if (dtor != NULL) {
        __cxa_vec_dtor(array, ((u32 *)array)[-1], size, dtor);
    }
    func_0203de50((char *)array - padding);
}
}
