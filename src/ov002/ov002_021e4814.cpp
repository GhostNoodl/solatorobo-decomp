#include "ov002/ov002.h"

extern "C" {

void *Heap_AllocArray(u32 size);

void Ov002LevelTable_Load(Ov002LevelTable *self, u8 *src) {
    u8 *p;
    func_ov002_021e4904_inline(self);
    self->src = src;
    MI_CpuCopy8(src, &self->count, 4);
    p = src + 4;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->thresholds != NULL) {
            Heap_FreeArray(self->thresholds);
            self->thresholds = NULL;
        }
        HEAP_POP(saved);
    }
    self->thresholds = (s32 *)Heap_AllocArray(self->count << 2);
    MI_CpuCopy8(p, self->thresholds, self->count << 2);
    p += self->count * 4;
    self->label = (char *)p;
    self->desc = (char *)p + (STD_GetStringLength((char *)p) + 1);
    STD_GetStringLength(self->desc);
}

}
