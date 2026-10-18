#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d9444(void *self);
void func_ov002_021d6e48(void *self);
void *func_ov000_0218e9c4(void *p);
extern char data_ov002_021efd98[];
extern char data_ov002_021efda3[];
extern char data_ov002_021efdba[];
extern char data_ov002_021efdb3[];
extern char data_ov002_021efdca[];

static inline void *ov002_NewAnim(void) {
    void *a = func_0203dd9c(0x138);
    if (a != NULL) {
        a = func_ov000_0218e9c4(a);
    }
    return a;
}

static inline void ov002_AnimSetA(u8 *a, char *name, char *file) {
    STD_CopyString(a + 0x10, name);
    STD_CopyString(a + 0x30, file);
    a[3] |= 2;
}

static inline void ov002_AnimSetB(u8 *a, char *name, char *file) {
    STD_CopyString(a + 0x4c, name);
    STD_CopyString(a + 0x6c, file);
    a[3] |= 4;
}

static inline void ov002_AnimSetC(u8 *a, char *name, char *file) {
    STD_CopyString(a + 0x100, name);
    STD_CopyString(a + 0x120, file);
    a[3] |= 0x20;
}

void func_ov002_021da5c0(void *self) {
    void *p;
    void *q;
    func_020359d0(data_ov002_021efdf6, 7, 0);
    p = func_0203dd9c(0xc8);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021efe6c;
        func_ov002_021d9444(p);
    }
    FIELD(self, 0x4, void *) = p;
    func_ov002_021d9504(p);
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(p, 0x4, VObject *));
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(p, 0x8c, void *) != NULL) {
            func_0203de1c(FIELD(p, 0x8c, void *));
            FIELD(p, 0x8c, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    func_ov002_021d9444(p);
    q = func_0203dd9c(0x70);
    if (q != NULL) {
        *(VFunc **)q = data_ov002_021efe4c;
        func_ov002_021d6e48(q);
    }
    FIELD(p, 0x4, void *) = q;
    FIELD(q, 0x4, void *) = ov002_NewAnim();
    {
        char *file = data_ov002_021efd98;
        char *nm = data_ov002_021efda3;
        if (nm) {
            ov002_AnimSetC(FIELD(q, 0x4, u8 *), nm, file);
        }
    }
    FIELD(FIELD(q, 0x4, u8 *), 0x0, u16) = 0;
    FIELD(q, 0xc, void *) = ov002_NewAnim();
    {
        char *file = data_ov002_021efdb3;
        char *nm = data_ov002_021efdba;
        if (nm) {
            ov002_AnimSetA(FIELD(q, 0xc, u8 *), nm, file);
            ov002_AnimSetB(FIELD(q, 0xc, u8 *), nm, file);
        }
    }
    FIELD(FIELD(q, 0xc, u8 *), 0x0, u16) = 0;
    FIELD(q, 0x14, void *) = ov002_NewAnim();
    {
        char *file = data_ov002_021efdca;
        char *nm = data_ov002_021efdba;
        if (nm) {
            ov002_AnimSetA(FIELD(q, 0x14, u8 *), nm, file);
            ov002_AnimSetB(FIELD(q, 0x14, u8 *), nm, file);
        }
    }
    FIELD(FIELD(q, 0x14, u8 *), 0x0, u16) = 0;
}

}
