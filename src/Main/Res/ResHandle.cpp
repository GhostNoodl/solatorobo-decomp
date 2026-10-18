#include "Main/Res/ResMgr.h"

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

extern ResNode *func_0203657c(ResMgr *mgr, const char *name, int type);
extern void func_02036720(ResMgr *mgr, ResNode *node, BOOL force);
extern ResNode *func_02036860(ResMgr *mgr, const char *name, const char *arcName, int type, u8 toFront);
extern void func_02036b30(ResMgr *mgr, ResNode *node);
extern void func_0203daa4(UnkSys *sys);
extern void *func_02034b98(ResList *list, const char *name);
extern void *func_02034cec(ResList *list, const char *name);
extern void *func_02034d88(ResList *list, const char *name);
extern void *func_02034e24(ResList *list, const char *name);
extern void *func_02034ec0(ResList *list, const char *name);
extern void *func_02034f5c(ResList *list, const char *name);
extern void *func_02034ff8(ResList *list, const char *name);

void func_02038504(ResHandle *handle) {
    handle->arcName[0] = '\0';
    handle->name[0] = '\0';
    handle->type = -1;
    handle->unk_48 = 0;
}

void func_02038520(ResHandle *handle) {
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
                    if (node->hash == hash && func_0201e7b0(node->u.arc.name, handle->name) == 0) {
                        break;
                    }
                }
                node = node->prev;
            }
            if (node != NULL) {
                func_02036720(data_02097cdc, node, FALSE);
            }
        } else {
            ResMgr *mgr = data_02097cdc;
            ResNode *node = func_0203657c(mgr, handle->name, type);
            if (node != NULL) {
                func_02036720(mgr, node, FALSE);
            }
        }
    }
    handle->Clear();
}


#define RES_HANDLE_LOAD_SYNC(kind)                                          \
    {                                                                       \
        ResMgr *mgr = data_02097cdc;                                        \
        ResNode *node = func_02036860(mgr, handle->name, NULL, kind, TRUE); \
        if (node == NULL) {                                                 \
            return;                                                         \
        }                                                                   \
        func_02036b30(mgr, node);                                           \
        if (node->state == 7) {                                             \
            return;                                                         \
        }                                                                   \
        while (TRUE) {                                                      \
            func_02036b30(mgr, node);                                       \
            if (node->state == 5) {                                         \
                return;                                                     \
            }                                                               \
            func_0203daa4(data_02097dd0);                                   \
        }                                                                   \
    }

void func_02038638(ResHandle *handle, const char *name) {
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
        ResNode *node = func_02036860(data_02097cdc, handle->name, NULL, 7, TRUE);
        ResMgr *mgr;
        if (node == NULL) {
            return;
        }
        mgr = data_02097cdc;
        func_02036b30(mgr, node);
        if (node->state == 7) {
            return;
        }
        while (TRUE) {
            func_02036b30(mgr, node);
            if (node->state == 5) {
                return;
            }
            func_0203daa4(data_02097dd0);
        }
    }
    }
}

static inline ResNode *ResHandle_LoadArchive(ResHandle *handle, const char *name, const char *arcName, int id, u8 toFront) {
    ResNode *node = func_02036860(data_02097cdc, name, arcName, id, toFront);
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

void func_02038a10(ResHandle *handle, const char *arcName, const char *name) {
    ResMgr *mgr;
    ResNode *node;
    int id;
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    id = handle->type;
    node = func_02036860(data_02097cdc, handle->arcName, handle->name, id, TRUE);
    if (node == NULL) {
        return;
    }
    if (node->refCount == 1 && handle->name != NULL && !node->unk_2b_6) {
        node->unk_2b_6 = TRUE;
        node->u.arc.id = id;
        STD_CopyString(node->u.arc.name, handle->name);
    }
    mgr = data_02097cdc;
    func_02036b30(mgr, node);
    if (node->state == 7) {
        return;
    }
    while (TRUE) {
        func_02036b30(mgr, node);
        if (node->state == 5) {
            return;
        }
        func_0203daa4(data_02097dd0);
    }
}

void func_02038b0c(ResHandle *handle, const char *name) {
    STD_CopyString(handle->name, name);
    func_02036860(data_02097cdc, handle->name, NULL, handle->type, FALSE);
}

void func_02038b48(ResHandle *handle, const char *name) {
    STD_CopyString(handle->name, name);
    func_02036860(data_02097cdc, handle->name, NULL, handle->type, TRUE);
}

void func_02038b88(ResHandle *handle, const char *arcName, const char *name) {
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    ResHandle_LoadArchive(handle, handle->arcName, handle->name, handle->type, FALSE);
}

void func_02038c14(ResHandle *handle, const char *arcName, const char *name) {
    STD_CopyString(handle->arcName, arcName);
    STD_CopyString(handle->name, name);
    ResHandle_LoadArchive(handle, handle->arcName, handle->name, handle->type, TRUE);
}

BOOL func_02038ca0(ResHandle *handle) {
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
                if (node->hash == hash && func_0201e7b0(node->u.arc.name, handle->name) == 0) {
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
        ResNode *node2 = func_0203657c(data_02097cdc, handle->name, handle->type);
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
                if (node->hash == hash && func_0201e7b0(node->u.arc.name, handle->name) == 0) {         \
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
        ResNode *node = func_0203657c(data_02097cdc, handle->name, kind);   \
        if (node != NULL) {                                                 \
            result = node->u.data;                                          \
        }                                                                   \
        return result;                                                      \
    }

void *func_02038dbc(ResHandle *handle) {
    if (!handle->IsLoaded()) {
        return NULL;
    }
    if (handle->arcName[0] != '\0') {
        switch (handle->type) {
        case 0:
            RES_HANDLE_GET_ARC_DATA(0, func_02034b98);
        case 1:
            RES_HANDLE_GET_ARC_DATA(1, func_02034cec);
        case 2:
            RES_HANDLE_GET_ARC_DATA(2, func_02034d88);
        case 3:
            RES_HANDLE_GET_ARC_DATA(3, func_02034e24);
        case 4:
            RES_HANDLE_GET_ARC_DATA(4, func_02034ec0);
        case 5:
            RES_HANDLE_GET_ARC_DATA(5, func_02034f5c);
        case 6:
            RES_HANDLE_GET_ARC_DATA(6, func_02034ff8);
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
            ResNode *node = func_0203657c(data_02097cdc, handle->name, 7);
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
extern void func_0203df74(void *ptr, u32 size);
extern void *func_0203e458(int arg0, void *arg1, u32 arg2, u32 arg3, int arg4);

void func_02039494(void *res) {
    G3dTex *tex = NNS_G3dGetTex(res);
    if (tex != NULL && tex->unk_14 != 0) {
        u32 size = (u8 *)tex + tex->unk_14 - (u8 *)res;
        tex->unk_14 = 0;
        func_0203df74(res, size);
    }
}

void *func_020394cc(void *res, void *arg) {
    void *result = NULL;
    G3dTex *tex = NNS_G3dGetTex(res);
    if (tex != NULL) {
        u32 size = tex->unk_0c << 3;
        if (size != 0) {
            result = func_0203e458(0, arg, (u16)tex->unk_08 << 3, size, 0);
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
        func_0203df74(model->mem1, model->block1->end - model->mem1);
        model->block1->end = NULL;
        model->block1->start = NULL;
    }
    if (model->mem2 != NULL && model->block2 != NULL && model->block2->end != NULL && model->block2->start != NULL) {
        func_0203df74(model->mem2, model->block2->end - model->mem2);
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
void func_02039610(char *dst, const char *src, int len) {
    int i = 0;
    while (src[i] != '.' && src[i] != '\0' && i < len) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

// Returns the extension of a path, or the path itself if it has none.
const char *func_02039644(const char *path) {
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
const char *func_02039674(const char *path) {
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
extern void func_0203de1c(void *ptr);

ResHandle *func_020396a4(ResHandle *handle) {
    *(const void ***)handle = data_0208b318;
    handle->Unload();
    func_0203de1c(handle);
    return handle;
}

BOOL func_020396d4(ResHandle *handle) {
    return handle->unk_48 ? TRUE : FALSE;
}

BOOL func_020396e8(ResHandle *handle) {
    handle->unk_48 = TRUE;
    return TRUE;
}

ResHandle *func_020396f8(ResHandle *handle) {
    *(const void ***)handle = data_0208b318;
    handle->Unload();
    return handle;
}

}
