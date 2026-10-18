#include "Main/Res/ResMgr.h"

extern "C" {

typedef struct ResData {
    /* 0x00 */ int type;
    /* 0x04 */ void *data[11];
} ResData;

extern void func_0200ed00(FSFile *file);
extern void func_0200ef1c(FSFile *file);
extern int func_0200f08c(FSFile *file, void *buf, u32 size);
extern BOOL func_0200f158(FSFile *file, const char *path);
extern u32 func_0200f168(FSFile *file);
extern ResList *func_02034b50(ResList *list);
extern void func_0203835c(ResData *data);
extern void func_0203de1c(void *ptr);
extern void *func_0203de84(u32 size, int align);
extern void func_0203df0c(void *ptr);
extern void func_0203df40(void *ptr);

void func_020381cc(ResMgr *mgr, ResNode *node) {
    if (node->type == 7) {
        void *heap = data_02097dd0->cur;
        ResList *list;
        data_02097dd0->cur = data_02097dd0->unk_08;
        list = node->u.arc.list;
        if (list != NULL) {
            if (list != NULL) {
                func_02034b50(list);
                func_0203de1c(list);
            }
            node->u.arc.list = NULL;
        }
        data_02097dd0->cur = heap;
        if (node->u.data[1] != NULL) {
            func_0203df40(node->u.data[1]);
            node->u.data[1] = NULL;
        }
        if (node->u.data[2] != NULL) {
            func_0203df0c(node->u.data[2]);
            node->u.data[2] = NULL;
        }
        if (node->u.data[3] != NULL) {
            func_0203df0c(node->u.data[3]);
            node->u.data[3] = NULL;
        }
    } else {
        func_0203835c((ResData *)&node->type);
    }
}

void *func_02038284(ResMgr *mgr, const char *path, u32 size, void *buf) {
    void *dst = NULL;
    BOOL ok = FS_IsFile(&mgr->file);
    if (!ok) {
        func_0200ed00(&mgr->file);
        ok = func_0200f158(&mgr->file, path);
    }
    if (ok) {
        if (size == 0) {
            size = func_0200f168(&mgr->file);
        }
        dst = buf;
        if (buf == NULL) {
            dst = func_0203de84(size, 4);
        }
        if (func_0200f08c(&mgr->file, dst, size) == -1) {
            func_0200ef1c(&mgr->file);
            if (buf == NULL && dst != NULL) {
                func_0203df0c(dst);
                dst = NULL;
            }
        }
    }
    return dst;
}

#define RES_DATA_FREE(i)                 \
    if (data->data[i] != NULL) {         \
        func_0203df0c(data->data[i]);    \
        data->data[i] = NULL;            \
    }

void func_0203835c(ResData *data) {
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
