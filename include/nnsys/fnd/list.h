#ifndef NNSYS_FND_LIST_H
#define NNSYS_FND_LIST_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NNSFndLink {
    /* 0x0 */ void *prevObject;
    /* 0x4 */ void *nextObject;
} NNSFndLink; // size 0x8

typedef struct NNSFndList {
    /* 0x0 */ void *headObject;
    /* 0x4 */ void *tailObject;
    /* 0x8 */ u16 numObjects;
    /* 0xa */ u16 offset; // Offset of the NNSFndLink within each object
} NNSFndList; // size 0xc

void NNS_FndInitList(NNSFndList *list, u16 offset);
void NNS_FndAppendListObject(NNSFndList *list, void *object);
void NNS_FndRemoveListObject(NNSFndList *list, void *object);
void *NNS_FndGetNextListObject(NNSFndList *list, void *object);

#ifdef __cplusplus
}
#endif

#endif
