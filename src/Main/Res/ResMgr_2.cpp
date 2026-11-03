#include "Main/Res/ResMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

typedef struct ResData {
    /* 0x00 */ int type;
    /* 0x04 */ void *data[11];
} ResData;

extern void FS_InitFile(FSFile *file);
extern BOOL FS_CloseFile(FSFile *file);
extern int FS_ReadFileAsync(FSFile *file, void *buf, int size);
extern BOOL FS_OpenFile(FSFile *file, const char *path);
extern u32 FS_GetLength(FSFile *file);
extern ResList *ResList_Dtor(ResList *list);
extern void ResData_Free(ResData *data);
extern void Heap_Free(void *ptr);
extern void Heap_FreeLo(void *ptr);

void ResMgr_FreeNodeData(ResMgr *mgr, ResNode *node) {
    if (node->type == 7) {
        void *heap = gSysState->cur;
        ResList *list;
        gSysState->cur = gSysState->heapHi;
        list = node->u.arc.list;
        if (list != NULL) {
            if (list != NULL) {
                ResList_Dtor(list);
                Heap_Free(list);
            }
            node->u.arc.list = NULL;
        }
        gSysState->cur = heap;
        if (node->u.data[1] != NULL) {
            Heap_FreeLo(node->u.data[1]);
            node->u.data[1] = NULL;
        }
        if (node->u.data[2] != NULL) {
            Heap_FreeHi(node->u.data[2]);
            node->u.data[2] = NULL;
        }
        if (node->u.data[3] != NULL) {
            Heap_FreeHi(node->u.data[3]);
            node->u.data[3] = NULL;
        }
    } else {
        ResData_Free((ResData *)&node->type);
    }
}

void *ResMgr_ReadFile(ResMgr *mgr, const char *path, u32 size, void *buf) {
    void *dst = NULL;
    BOOL ok = FS_IsFile(&mgr->file);
    if (!ok) {
        FS_InitFile(&mgr->file);
        ok = FS_OpenFile(&mgr->file, path);
    }
    if (ok) {
        if (size == 0) {
            size = FS_GetLength(&mgr->file);
        }
        dst = buf;
        if (buf == NULL) {
            dst = Heap_AllocHi(size, 4);
        }
        if (FS_ReadFileAsync(&mgr->file, dst, size) == -1) {
            FS_CloseFile(&mgr->file);
            if (buf == NULL && dst != NULL) {
                Heap_FreeHi(dst);
                dst = NULL;
            }
        }
    }
    return dst;
}

#define RES_DATA_FREE(i)                 \
    if (data->data[i] != NULL) {         \
        Heap_FreeHi(data->data[i]);    \
        data->data[i] = NULL;            \
    }

void ResData_Free(ResData *data) {
    switch (data->type) {
    case 0:
        RES_DATA_FREE(0);
        break;
    case 1:
        RES_DATA_FREE(0);
        break;
    case 2:
        RES_DATA_FREE(0);
        RES_DATA_FREE(2);
        RES_DATA_FREE(4);
        RES_DATA_FREE(6);
        RES_DATA_FREE(8);
        break;
    case 3:
        RES_DATA_FREE(0);
        RES_DATA_FREE(2);
        RES_DATA_FREE(4);
        break;
    case 4:
        RES_DATA_FREE(0);
        break;
    case 5:
        RES_DATA_FREE(0);
        break;
    case 6:
        RES_DATA_FREE(0);
        RES_DATA_FREE(1);
        RES_DATA_FREE(2);
        RES_DATA_FREE(3);
        RES_DATA_FREE(4);
        break;
    }
}

}
