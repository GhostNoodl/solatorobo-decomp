#include "Main/Gfx/GfxMgr.h"

extern "C" {

// Allocates `size` bytes from the main (sub == FALSE) or sub VRAM range heap and returns the
// offset: first after the last node, otherwise in the first gap between two nodes that fits.
// `cur` and `node` are locals; declaring them as parameters gives the target's registers.
u32 func_0203bc20(GfxSys *sys, u32 size, BOOL sub, GfxVramNode *cur, GfxVramNode *node) {
    GfxVramHeap *heap = &sys->heaps[0];
    GfxVramNode *tail;
    GfxVramNode *next;
    u32 offset;
    int i;
    if (sub) {
        heap = &sys->heaps[1];
    }
    tail = heap->tail;
    offset = tail->offset + tail->size;
    if (heap->size - offset >= size) {
        node = NULL;
        for (i = 0; i < 64; i++) {
            if (heap->nodes[i].size == 0) {
                node = &heap->nodes[i];
                break;
            }
        }
        if (node == NULL) {
            return -1;
        }
        node->offset = offset;
        node->size = size;
        node->prev = tail;
        tail->next = node;
        heap->tail = node;
        return node->offset;
    }
    for (cur = &heap->head; cur != NULL; cur = next) {
        next = cur->next;
        if (next != NULL) {
            offset = cur->offset + cur->size;
            if (next->offset - offset >= size) {
                node = NULL;
                for (i = 0; i < 64; i++) {
                    if (heap->nodes[i].size == 0) {
                        node = &heap->nodes[i];
                        break;
                    }
                }
                if (node == NULL) {
                    return 0;
                }
                node->offset = offset;
                node->size = size;
                node->prev = cur;
                node->next = next;
                cur->next = node;
                next->prev = node;
                return node->offset;
            }
        }
    }
    return -1;
}

}
