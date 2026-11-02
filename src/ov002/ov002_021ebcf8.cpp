#include "ov002/ov002.h"

extern "C" {

s32 func_0201e950(const void *a, const void *b, u32 n);


typedef struct Hdr021ebcf8 {
    s32 count;
    s32 stride;
} Hdr021ebcf8;

typedef struct Rec021ebcf8 {
    s32 a;
    s32 b;
    s32 pad8;
    s32 c;
    s16 d;
    s8 e;
    s8 f;
    s32 g;
} Rec021ebcf8;

static inline void ov002_addPair(Ov002ResList *list, char *a, char *b, s32 kind) {
    Ov002ResNode *n;
    for (n = list->head; n != NULL; n = n->next) {
        if (func_0201e950(n->a, a, STD_GetStringLength(n->a)) == 0 && func_0201e950(n->b, b, STD_GetStringLength(n->a)) == 0 && n->kind == kind) {
            break;
        }
    }
    if (n == NULL) {
        n = (Ov002ResNode *)Heap_Alloc(0x50);
        MI_CpuFill8(n->a, 0, 0x20);
        MI_CpuFill8(n->b, 0, 0x20);
        n->unk_44 = 0;
        n->unk_48 = 0;
        n->next = NULL;
        STD_CopyLString(n->a, a, 0x20);
        STD_CopyLString(n->b, b, 0x20);
        n->kind = kind;
        n->next = list->head;
        list->head = n;
    }
}

void func_ov002_021ebcf8(Ov002StageFile *self, int kind, u8 *data, Ov002Obj021f075c **out) {
    Hdr021ebcf8 hdr;
    Rec021ebcf8 rec;
    s32 n;
    s32 stride;
    u8 *src;
    s32 i;
    Ov002Obj021f075c *o;
    char *s1;
    char *s2;
    char *s3;
    MI_CpuCopy8(data + 8, &hdr, 8);
    n = hdr.count;
    stride = hdr.stride;
    src = data + 0x10;
    for (i = 0; i < n; i++) {
        MI_CpuCopy8(src, &rec, 0x18);
        o = (Ov002Obj021f075c *)Ov002Obj021f075c_New(rec.a, rec.b, 1, rec.e, rec.g);
        o->unk_04 = kind;
        o->unk_84 = rec.f;
        o->unk_58 = rec.c;
        o->unk_5c = rec.d;
        s1 = FIELD(src, 0x18, s8) ? (char *)src + 0x18 : NULL;
        s2 = FIELD(src, 0x30, s8) ? (char *)src + 0x30 : NULL;
        s3 = FIELD(src, 0x48, s8) ? (char *)src + 0x48 : NULL;
        o->res.arc = s1;
        o->res.name = s2;
        o->res.item = s3;
        if (self->unk_60 != NULL && s1 != NULL && s2 != NULL) {
            ov002_addPair(self->unk_60, s1, s2, 6);
        }
        out[i] = o;
        src += stride;
    }
}

}
