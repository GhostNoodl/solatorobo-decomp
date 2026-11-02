#include "ov002/ov002.h"

extern "C" {

void *Heap_AllocArray(u32 size);

void Ov002StrTable_Load(Ov002StrTable *self, u8 *src) {
    u8 *p;
    u16 i;
    self->src = NULL;
    self->count = 0;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->pairs != NULL) {
            Heap_FreeArray(self->pairs);
            self->pairs = NULL;
        }
        HEAP_POP(saved);
    }
    self->src = src;
    MI_CpuCopy8(src, &self->count, 4);
    p = src + 4;
    self->pairs = (Ov002StrPair *)Heap_AllocArray(self->count * 12);
    for (i = 0; i < self->count; i++) {
        s32 len;
        u8 *s;
        MI_CpuCopy8(p, &len, 4);
        s = p + 4;
        self->pairs[i].index = i;
        self->pairs[i].label = (char *)s;
        s = s + (STD_GetStringLength((char *)s) + 1);
        self->pairs[i].desc = (char *)s;
        STD_GetStringLength((char *)s);
        p += len;
    }
}

}
