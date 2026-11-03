#include "Main/Res/ResMgr.h"
#include "Main/Res/ResArc.h"

extern "C" {

// Reference to a resource in the resource manager.
struct ResHandle {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void Clear();
    virtual void Unload();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20();
    virtual void unk_vf24();
    virtual void unk_vf28();
    virtual BOOL IsLoaded();
    /* 0x04 */ char arcName[0x20];
    /* 0x24 */ char name[0x20];
    /* 0x44 */ int type;
    /* 0x48 */ u8 unk_48;
};

extern ResNode *ResMgr_Find(ResMgr *mgr, const char *name, int type);
extern void ResMgr_ReleaseNode(ResMgr *mgr, ResNode *node, BOOL force);
extern ResNode *ResMgr_Request(ResMgr *mgr, const char *name, const char *arcName, int type, u8 toFront);
extern void ResMgr_LoadNode(ResMgr *mgr, ResNode *node);
extern void Sys_WaitVBlank(UnkSys *sys);
extern void *ResList_FindType0(ResList *list, const char *name);
extern void *func_02034cec(ResList *list, const char *name);
extern void *ResList_FindType3(ResList *list, const char *name);
extern void *ResList_FindType4(ResList *list, const char *name);
extern void *ResList_FindType5(ResList *list, const char *name);
extern void *ResList_FindType6(ResList *list, const char *name);

void ResHandle_Clear(ResHandle *handle) {
    handle->arcName[0] = '\0';
    handle->name[0] = '\0';
    handle->type = -1;
    handle->unk_48 = 0;
}

void ResHandle_Unload(ResHandle *handle) {
    int type = handle->type;
    if (type == -1) {
        return;
    }
    if (handle->name[0] != '\0') {
        if (handle->arcName[0] != '\0') {
            ResMgr *mgr = data_02097cdc;
            u16 hash = 0;
            ResNode *node = mgr->tail;
            while (node != NULL) {
                if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == type) {
                    if (hash == 0) {
                        hash = ResMgr_Hash(mgr, handle->arcName);
                    }
                    if (node->hash == hash && STD_CompareString(node->u.arc.name, handle->name) == 0) {
                        break;
                    }
                }
                node = node->prev;
            }
            if (node != NULL) {
                ResMgr_ReleaseNode(data_02097cdc, node, FALSE);
            }
        } else {
            ResMgr *mgr = data_02097cdc;
            ResNode *node = ResMgr_Find(mgr, handle->name, type);
            if (node != NULL) {
                ResMgr_ReleaseNode(mgr, node, FALSE);
            }
        }
    }
    handle->Clear();
}


#define RES_HANDLE_LOAD_SYNC(kind)                                          \
    {                                                                       \
        ResMgr *mgr = data_02097cdc;                                        \
        ResNode *node = ResMgr_Request(mgr, handle->name, NULL, kind, TRUE); \
        if (node == NULL) {                                                 \
            return;                                                         \
        }                                                                   \
        ResMgr_LoadNode(mgr, node);                                           \
        if (node->state == 7) {                                             \
            return;                                                         \
        }                                                                   \
        while (TRUE) {                                                      \
            ResMgr_LoadNode(mgr, node);                                       \
            if (node->state == 5) {                                         \
                return;                                                     \
            }                                                               \
            Sys_WaitVBlank(data_02097dd0);                                   \
        }                                                                   \
    }

void ResHandle_LoadSync(ResHandle *handle, const char *name) {
    STD_CopyString(handle->name, name);
    switch (handle->type) {
    case 0:
        RES_HANDLE_LOAD_SYNC(0);
        break;
    case 1:
        RES_HANDLE_LOAD_SYNC(1);
        break;
    case 2:
        RES_HANDLE_LOAD_SYNC(2);
        break;
    case 3:
        RES_HANDLE_LOAD_SYNC(3);
        break;
    case 4:
        RES_HANDLE_LOAD_SYNC(4);
        break;
    case 5:
        RES_HANDLE_LOAD_SYNC(5);
        break;
    case 6:
        RES_HANDLE_LOAD_SYNC(6);
        break;
    case 7: {
        ResNode *node = ResMgr_Request(data_02097cdc, handle->name, NULL, 7, TRUE);
        ResMgr *mgr;
        if (node == NULL) {
            return;
        }
        mgr = data_02097cdc;
        ResMgr_LoadNode(mgr, node);
        if (node->state == 7) {
            return;
        }
        while (TRUE) {
            ResMgr_LoadNode(mgr, node);
            if (node->state == 5) {
                return;
            }
            Sys_WaitVBlank(data_02097dd0);
        }
    }
    }
}

static inline ResNode *ResHandle_LoadArchive(ResHandle *handle, const char *name, const char *arcName, int id, u8 toFront) {
    ResNode *node = ResMgr_Request(data_02097cdc, name, arcName, id, toFront);
    if (node == NULL) {
        return node;
    }
    if (node->refCount == 1 && arcName != NULL && !node->unk_2b_6) {
        node->unk_2b_6 = TRUE;
        node->u.arc.id = id;
        STD_CopyString(node->u.arc.name, arcName);
    }
    return node;
}

void ResHandle_OpenInArc(ResHandle *handle, const char *arcName, const char *name) {
    ResMgr *mgr;
    ResNode *node;
    int id;
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    id = handle->type;
    node = ResMgr_Request(data_02097cdc, handle->arcName, handle->name, id, TRUE);
    if (node == NULL) {
        return;
    }
    if (node->refCount == 1 && handle->name != NULL && !node->unk_2b_6) {
        node->unk_2b_6 = TRUE;
        node->u.arc.id = id;
        STD_CopyString(node->u.arc.name, handle->name);
    }
    mgr = data_02097cdc;
    ResMgr_LoadNode(mgr, node);
    if (node->state == 7) {
        return;
    }
    while (TRUE) {
        ResMgr_LoadNode(mgr, node);
        if (node->state == 5) {
            return;
        }
        Sys_WaitVBlank(data_02097dd0);
    }
}

void ResHandle_Request(ResHandle *handle, const char *name) {
    STD_CopyString(handle->name, name);
    ResMgr_Request(data_02097cdc, handle->name, NULL, handle->type, FALSE);
}

void ResHandle_RequestFlag(ResHandle *handle, const char *name) {
    STD_CopyString(handle->name, name);
    ResMgr_Request(data_02097cdc, handle->name, NULL, handle->type, TRUE);
}

void ResHandle_LoadFromArc(ResHandle *handle, const char *arcName, const char *name) {
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    ResHandle_LoadArchive(handle, handle->arcName, handle->name, handle->type, FALSE);
}

void ResHandle_LoadFromArcFlag(ResHandle *handle, const char *arcName, const char *name) {
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    ResHandle_LoadArchive(handle, handle->arcName, handle->name, handle->type, TRUE);
}

BOOL ResHandle_IsLoaded(ResHandle *handle) {
    ResMgr *mgr;
    int type;
    u16 hash;
    ResNode *node;
    BOOL done;
    if (handle->arcName[0] != '\0') {
        done = FALSE;
        mgr = data_02097cdc;
        hash = 0;
        node = mgr->tail;
        type = handle->type;
        while (node != NULL) {
            if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == type) {
                if (hash == 0) {
                    hash = ResMgr_Hash(mgr, handle->arcName);
                }
                if (node->hash == hash && STD_CompareString(node->u.arc.name, handle->name) == 0) {
                    break;
                }
            }
            node = node->prev;
        }
        if (node == NULL || node->state == 5) {
            done = TRUE;
        }
        if (done) {
            return TRUE;
        }
    } else {
        BOOL done2 = FALSE;
        ResNode *node2 = ResMgr_Find(data_02097cdc, handle->name, handle->type);
        if (node2 == NULL || node2->state == 5) {
            done2 = TRUE;
        }
        if (done2) {
            return TRUE;
        }
    }
    return FALSE;
}


#define RES_HANDLE_GET_ARC_DATA(kind, findFunc)                                                         \
    {                                                                                                   \
        ResMgr *mgr = data_02097cdc;                                                                    \
        ResList *list;                                                                                  \
        ResNode *node;                                                                                  \
        u16 hash;                                                                                       \
        void *result = NULL;                                                                            \
        list = NULL;                                                                                    \
        node = mgr->tail;                                                                               \
        hash = 0;                                                                                       \
        while (node != NULL) {                                                                          \
            if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == kind) {                          \
                if (hash == 0) {                                                                        \
                    hash = ResMgr_Hash(mgr, handle->arcName);                                           \
                }                                                                                       \
                if (node->hash == hash && STD_CompareString(node->u.arc.name, handle->name) == 0) {         \
                    break;                                                                              \
                }                                                                                       \
            }                                                                                           \
            node = node->prev;                                                                          \
        }                                                                                               \
        if (node != NULL) {                                                                             \
            list = node->u.arc.list;                                                                    \
        }                                                                                               \
        if (list != NULL) {                                                                             \
            result = findFunc(list, handle->name);                                                      \
        }                                                                                               \
        return result;                                                                                  \
    }

#define RES_HANDLE_GET_DATA(kind)                                           \
    {                                                                       \
        void *result = NULL;                                                \
        ResNode *node = ResMgr_Find(data_02097cdc, handle->name, kind);   \
        if (node != NULL) {                                                 \
            result = node->u.data;                                          \
        }                                                                   \
        return result;                                                      \
    }

void *ResHandle_GetData(ResHandle *handle) {
    if (!handle->IsLoaded()) {
        return NULL;
    }
    if (handle->arcName[0] != '\0') {
        switch (handle->type) {
        case 0:
            RES_HANDLE_GET_ARC_DATA(0, ResList_FindType0);
        case 1:
            RES_HANDLE_GET_ARC_DATA(1, func_02034cec);
        case 2:
            RES_HANDLE_GET_ARC_DATA(2, ResList_FindType2);
        case 3:
            RES_HANDLE_GET_ARC_DATA(3, ResList_FindType3);
        case 4:
            RES_HANDLE_GET_ARC_DATA(4, ResList_FindType4);
        case 5:
            RES_HANDLE_GET_ARC_DATA(5, ResList_FindType5);
        case 6:
            RES_HANDLE_GET_ARC_DATA(6, ResList_FindType6);
        }
    } else {
        switch (handle->type) {
        case 0:
            RES_HANDLE_GET_DATA(0);
        case 1:
            RES_HANDLE_GET_DATA(1);
        case 2:
            RES_HANDLE_GET_DATA(2);
        case 3:
            RES_HANDLE_GET_DATA(3);
        case 4:
            RES_HANDLE_GET_DATA(4);
        case 5:
            RES_HANDLE_GET_DATA(5);
        case 6:
            RES_HANDLE_GET_DATA(6);
        case 7: {
            ResList *result = NULL;
            ResNode *node = ResMgr_Find(data_02097cdc, handle->name, 7);
            if (node != NULL) {
                result = node->u.arc.list;
            }
            return result;
        }
        }
    }
    return NULL;
}


typedef struct G3dTex {
    /* 0x00 */ u8 unk_00[0x8];
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u8 unk_0e[0x6];
    /* 0x14 */ u32 unk_14;
} G3dTex;

extern G3dTex *NNS_G3dGetTex(void *res);
extern u32 Heap_Resize(void *ptr, u32 size);
extern void *Vram_QueueTransfer(int arg0, void *arg1, u32 arg2, u32 arg3, int arg4);

void G3dRes_DropTexData(void *res) {
    G3dTex *tex = NNS_G3dGetTex(res);
    if (tex != NULL && tex->unk_14 != 0) {
        u32 size = (u8 *)tex + tex->unk_14 - (u8 *)res;
        tex->unk_14 = 0;
        Heap_Resize(res, size);
    }
}

void *G3dRes_QueueTexUpload(void *res, void *arg) {
    void *result = NULL;
    G3dTex *tex = NNS_G3dGetTex(res);
    if (tex != NULL) {
        u32 size = tex->unk_0c << 3;
        if (size != 0) {
            result = Vram_QueueTransfer(0, arg, (u16)tex->unk_08 << 3, size, 0);
        }
    }
    return result;
}

typedef struct UnkBlock {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u8 *start;
    /* 0x14 */ u8 *end;
} UnkBlock;

typedef struct UnkModel {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u8 *mem1;
    /* 0x14 */ UnkBlock *block1;
    /* 0x18 */ u8 *mem2;
    /* 0x1c */ UnkBlock *block2;
} UnkModel;

void func_02039518(UnkModel *model) {
    if (model == NULL) {
        return;
    }
    if (model->mem1 != NULL && model->block1 != NULL && model->block1->end != NULL && model->block1->start != NULL) {
        Heap_Resize(model->mem1, model->block1->end - model->mem1);
        model->block1->end = NULL;
        model->block1->start = NULL;
    }
    if (model->mem2 != NULL && model->block2 != NULL && model->block2->end != NULL && model->block2->start != NULL) {
        Heap_Resize(model->mem2, model->block2->end - model->mem2);
        model->block2->end = NULL;
        model->block2->start = NULL;
    }
}

// Compares two file names up to their extensions.
BOOL func_020395a8(const char *a, const char *b, int len) {
    int i;
    for (i = 0; i < len; i++) {
        char c = b[i];
        if (c == '.' && (a[i] == '.' || a[i] == '\0')) {
            break;
        }
        if (c == '\0' && (a[i] == '.' || a[i] == '\0')) {
            break;
        }
        if (a[i] != b[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

// Copies a file name without its extension.
void Str_CopyStem(char *dst, const char *src, int len) {
    int i = 0;
    while (src[i] != '.' && src[i] != '\0' && i < len) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

// Returns the extension of a path, or the path itself if it has none.
const char *Path_FindExt(const char *path) {
    const char *p = path;
    if (*p == '\0') {
        return path;
    }
    do {
        if (*p == '.') {
            return p;
        }
    } while (*++p != '\0');
    return path;
}

// Returns the file name of a path.
const char *Path_SkipDir(const char *path) {
    const char *p = path;
    if (*p == '\0') {
        return path;
    }
    do {
        if (*p == '/') {
            return p + 1;
        }
    } while (*++p != '\0');
    return path;
}

extern const void *data_0208b318[];
extern void Heap_Free(void *ptr);

// ResHandle::~ResHandle (deleting).
ResHandle *_ZN9ResHandleD0Ev(ResHandle *handle) {
    *(const void ***)handle = data_0208b318;
    handle->Unload();
    Heap_Free(handle);
    return handle;
}

BOOL ResHandle_IsReady(ResHandle *handle) {
    return handle->unk_48 ? TRUE : FALSE;
}

BOOL ResHandle_OnLoad(ResHandle *handle) {
    handle->unk_48 = TRUE;
    return TRUE;
}

// ResHandle::~ResHandle (complete); LangHandle.cpp registers it as the global handle's destructor.
ResHandle *_ZN9ResHandleD1Ev(ResHandle *handle) {
    *(const void ***)handle = data_0208b318;
    handle->Unload();
    return handle;
}

}
