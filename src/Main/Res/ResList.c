#include "Main/Res/ResMgr.h"

extern void func_0203835c(void *data);

void func_02034b44(ResList *list) {
    list->head = NULL;
}

ResList *func_02034b50(ResList *list) {
    ResNode *node = list->head;
    ResNode *next;
    while (node != NULL) {
        func_0203835c(&node->type);
        next = node->next;
        func_020366d0(data_02097cdc, node);
        node = next;
    }
    return list;
}

#define RES_LIST_SEARCH(list, str, kind)                         \
    {                                                             \
        node = list->head;                                        \
        hash = 0;                                                 \
        while (node != NULL) {                                    \
            if (node->type == kind) {                             \
                if (hash == 0) {                                  \
                    hash = ResMgr_Hash(data_02097cdc, str);       \
                }                                                 \
                if (node->hash == hash && STD_CompareString(str, node->name) == 0) {  \
                    break;                                        \
                }                                                 \
            }                                                     \
            node = node->next;                                    \
        }                                                         \
    }

#define RES_LIST_FIND(list, str, kind)        \
    {                                         \
        if (str == NULL) {                    \
            node = NULL;                      \
        } else {                              \
            RES_LIST_SEARCH(list, str, kind)  \
        }                                     \
    }

#define RES_LIST_FIND_FUNC(func, kind)                    \
    void *func(ResList *list, const char *name) {         \
        u16 hash;                                         \
        void *result = NULL;                              \
        ResNode *node;                                    \
        RES_LIST_FIND(list, name, kind);                  \
        if (node != NULL) {                               \
            result = node->u.data;                          \
        }                                                 \
        return result;                                    \
    }

RES_LIST_FIND_FUNC(func_02034b98, 0)

void *func_02034c34(ResList *list, const char *dir, const char *name) {
    char path[0x18];
    u16 hash;
    char *str = path;
    void *result;
    ResNode *node;
    STD_CopyString(str, dir);
    STD_ConcatenateString(str, name);
    result = NULL;
    RES_LIST_SEARCH(list, str, 0);
    if (node != NULL) {
        result = node->u.data;
    }
    return result;
}

RES_LIST_FIND_FUNC(func_02034cec, 1)
RES_LIST_FIND_FUNC(func_02034d88, 2)
RES_LIST_FIND_FUNC(func_02034e24, 3)
RES_LIST_FIND_FUNC(func_02034ec0, 4)
RES_LIST_FIND_FUNC(func_02034f5c, 5)
RES_LIST_FIND_FUNC(func_02034ff8, 6)

extern const char data_0208b2c8[]; // ".ncer"
extern const char data_0208b2ce[]; // ".nanr"
extern const char data_0208b2d4[]; // ".ncgr"
extern const char data_0208b2da[]; // ".ncbr"
extern const char data_0208b2e0[]; // ".nclr"
extern const char data_0208b2e6[]; // ".nscr"
extern const char data_0208b2ec[]; // ".nsbca"
extern const char data_0208b2f3[]; // ".nsbma"
extern const char data_0208b2fa[]; // ".nsbta"
extern const char data_0208b301[]; // ".nsbtp"
extern const char data_0208b308[]; // ".nsbva"

extern BOOL func_020395a8(const char *a, const char *b, int len);
extern void func_02039610(char *dst, const char *src, int len);
extern const char *func_02039644(const char *path);
extern void NNS_G2dFontInitAuto(void *out, void *data);
extern void NNS_G2dGetUnpackedCellBank(void *data, void *out);
extern void NNS_G2dGetUnpackedAnimBank(void *data, void *out);
extern void NNS_G2dGetUnpackedCharacterData(void *data, void *out);
extern void NNS_G2dGetUnpackedBGCharacterData(void *data, void *out);
extern void NNS_G2dGetUnpackedPaletteData(void *data, void *out);
extern void NNS_G2dGetUnpackedPaletteCompressInfo(void *data, void *out);
extern void NNS_G2dGetUnpackedScreenData(void *data, void *out);

void func_02035094(ResList *list, ResRequest *req) {
    ResFileEntry *entry;
    int type;
    ResNode *node;
    const char *ext;
    entry = &req->entries[req->index];
    node = NULL;
    type = entry->type;

    if (type == 2 || type == 3 || type == 6) {
        for (node = list->head; node != NULL; node = node->next) {
            if (node->type == type && func_020395a8(node->name, entry->name, 0x18)) {
                break;
            }
        }
    }
    if (node == NULL) {
        node = func_0203662c(data_02097cdc);
        node->state = 6;
        if (list->head == NULL) {
            list->head = node;
        } else {
            ResNode *last = list->head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = node;
        }
        if (entry->type == 0) {
            STD_CopyString(node->name, entry->name);
        } else {
            func_02039610(node->name, entry->name, 0x18);
        }
        node->hash = ResMgr_Hash(data_02097cdc, node->name);
        node->type = entry->type;
    }
    switch (node->type) {
    case 0:
        node->u.data[0] = req->data;
        break;
    case 1:
        node->u.data[0] = req->data;
        NNS_G2dFontInitAuto(&node->u.data[1], node->u.data[0]);
        break;
    case 2:
        ext = func_02039644(entry->name);
        if (STD_CompareString(ext, data_0208b2c8) == 0) {
            node->u.data[0] = req->data;
            NNS_G2dGetUnpackedCellBank(node->u.data[0], &node->u.data[1]);
        } else if (STD_CompareString(ext, data_0208b2ce) == 0) {
            node->u.data[2] = req->data;
            NNS_G2dGetUnpackedAnimBank(node->u.data[2], &node->u.data[3]);
        } else if (STD_CompareString(ext, data_0208b2d4) == 0) {
            node->u.data[4] = req->data;
            NNS_G2dGetUnpackedCharacterData(node->u.data[4], &node->u.data[5]);
        }
        if (STD_CompareString(ext, data_0208b2da) == 0) {
            node->u.data[6] = req->data;
            NNS_G2dGetUnpackedCharacterData(node->u.data[6], &node->u.data[7]);
        } else if (STD_CompareString(ext, data_0208b2e0) == 0) {
            node->u.data[8] = req->data;
            NNS_G2dGetUnpackedPaletteCompressInfo(node->u.data[8], &node->u.data[10]);
            NNS_G2dGetUnpackedPaletteData(node->u.data[8], &node->u.data[9]);
        }
        break;
    case 3:
        ext = func_02039644(entry->name);
        if (STD_CompareString(ext, data_0208b2e6) == 0) {
            node->u.data[0] = req->data;
            NNS_G2dGetUnpackedScreenData(node->u.data[0], &node->u.data[1]);
        } else if (STD_CompareString(ext, data_0208b2d4) == 0) {
            node->u.data[2] = req->data;
            NNS_G2dGetUnpackedBGCharacterData(node->u.data[2], &node->u.data[3]);
        } else if (STD_CompareString(ext, data_0208b2e0) == 0) {
            node->u.data[4] = req->data;
            NNS_G2dGetUnpackedPaletteCompressInfo(node->u.data[4], &node->u.data[6]);
            NNS_G2dGetUnpackedPaletteData(node->u.data[4], &node->u.data[5]);
        }
        break;
    case 4:
        node->u.data[0] = req->data;
        break;
    case 5:
        node->u.data[0] = req->data;
        break;
    case 6:
        ext = func_02039644(entry->name);
        if (STD_CompareString(ext, data_0208b2ec) == 0) {
            node->u.data[0] = req->data;
        } else if (STD_CompareString(ext, data_0208b2f3) == 0) {
            node->u.data[1] = req->data;
        } else if (STD_CompareString(ext, data_0208b2fa) == 0) {
            node->u.data[2] = req->data;
        } else if (STD_CompareString(ext, data_0208b301) == 0) {
            node->u.data[3] = req->data;
        } else if (STD_CompareString(ext, data_0208b308) == 0) {
            node->u.data[4] = req->data;
        }
        break;
    }
}
