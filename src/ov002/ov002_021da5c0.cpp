#include "ov002/ov002.h"

extern "C" {

ActorRes *func_ov000_0218e9c4(void *p);
extern char data_ov002_021efd98[];
extern char data_ov002_021efda3[];
extern char data_ov002_021efdba[];
extern char data_ov002_021efdb3[];
extern char data_ov002_021efdca[];

static inline ActorRes *ov002_NewAnim(void) {
    ActorRes *a = (ActorRes *)Heap_Alloc(sizeof(ActorRes));
    if (a != NULL) {
        a = func_ov000_0218e9c4(a);
    }
    return a;
}

static inline void ov002_AnimSetA(u8 *a, char *name, char *file) {
    STD_CopyString((char *)(a + 0x10), name);
    STD_CopyString((char *)(a + 0x30), file);
    a[3] |= 2;
}

static inline void ov002_AnimSetB(u8 *a, char *name, char *file) {
    STD_CopyString((char *)(a + 0x4c), name);
    STD_CopyString((char *)(a + 0x6c), file);
    a[3] |= 4;
}

static inline void ov002_AnimSetC(u8 *a, char *name, char *file) {
    STD_CopyString((char *)(a + 0x100), name);
    STD_CopyString((char *)(a + 0x120), file);
    a[3] |= 0x20;
}

void func_ov002_021da5c0(Obj021efe7c *self) {
    Obj021efe6c *p;
    Obj021efe4c *q;
    func_020359d0(data_ov002_021efdf6, 7, 0);
    p = (Obj021efe6c *)Heap_Alloc(sizeof(Obj021efe6c));
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021efe6c;
        func_ov002_021d9444(p);
    }
    self->board = p;
    func_ov002_021d9504(p);
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(p->field);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        if (p->cam != NULL) {
            Heap_Free(p->cam);
            p->cam = NULL;
        }
        HEAP_POP(saved);
    }
    func_ov002_021d9444(p);
    q = (Obj021efe4c *)Heap_Alloc(sizeof(Obj021efe4c));
    if (q != NULL) {
        *(VFunc **)q = data_ov002_021efe4c;
        func_ov002_021d6e48(q);
    }
    p->field = q;
    q->unk_04 = ov002_NewAnim();
    {
        char *file = data_ov002_021efd98;
        char *nm = data_ov002_021efda3;
        if (nm) {
            ov002_AnimSetC((u8 *)q->unk_04, nm, file);
        }
    }
    q->unk_04->unk_00 = 0;
    q->unk_0c = ov002_NewAnim();
    {
        char *file = data_ov002_021efdb3;
        char *nm = data_ov002_021efdba;
        if (nm) {
            ov002_AnimSetA((u8 *)q->unk_0c, nm, file);
            ov002_AnimSetB((u8 *)q->unk_0c, nm, file);
        }
    }
    q->unk_0c->unk_00 = 0;
    q->unk_14 = ov002_NewAnim();
    {
        char *file = data_ov002_021efdca;
        char *nm = data_ov002_021efdba;
        if (nm) {
            ov002_AnimSetA((u8 *)q->unk_14, nm, file);
            ov002_AnimSetB((u8 *)q->unk_14, nm, file);
        }
    }
    q->unk_14->unk_00 = 0;
}

}
