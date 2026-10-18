#ifndef OV006_OV006_H
#define OV006_OV006_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Generic object with a virtual table. */
typedef struct Object Object;
typedef struct ObjectVtbl {
    void *unk0;
    void (*dtor)(Object *self);
    int (*unk8)(Object *self);
    int (*unkC)(Object *self);
    int (*unk10)(Object *self);
    int (*unk14)(Object *self);
    int (*unk18)(Object *self);
    int (*unk1C)(Object *self);
} ObjectVtbl;
struct Object {
    ObjectVtbl *vtbl;
};

/* Global heap context (data_02097dd0). */
typedef struct HeapCtx {
    void *current;
    void *unk4;
    void *unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
} HeapCtx;

extern HeapCtx *data_02097dd0;

/* Deletes a virtual object while temporarily switching the current heap. */
#define OV006_DELETE_OBJECT(obj)                                 \
    do {                                                         \
        void *saved_ = data_02097dd0->current;                   \
        data_02097dd0->current = data_02097dd0->unk8;            \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                ((Object *)(obj))->vtbl->dtor((Object *)(obj));  \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->current = saved_;                         \
    } while (0)

typedef struct ov006_Task {
    ObjectVtbl *vtbl;
    int type;
    int state;
    int subState;
} ov006_Task;

typedef struct ov006_Manager {
    void *vtbl;
    int state;
    int subState;
    int taskType;
    ov006_Task *task;
    int unk14;
    u32 unk18;
    u8 unk1C;
    u32 unk20;
} ov006_Manager;

typedef struct ov006_MenuData {
    u32 unk0;
    union {
        u16 h[3];
        u8 b[6];
    } key;
    u8 unkA[0x3a];
    u32 unk44;
    u8 unk48[0x78];
} ov006_MenuData;

typedef struct ov006_MenuNode {
    ObjectVtbl *vtbl;
    int id;
    u32 count;
    u8 timer;
    ov006_MenuData data;
    struct ov006_MenuNode *next;
    struct ov006_MenuNode *prev;
} ov006_MenuNode;

/* Holds one virtual object (vtable data_ov006_021ec414). */
typedef struct ov006_ObjectHolder {
    void *vtbl;
    Object *obj;
} ov006_ObjectHolder;

typedef struct ov006_MenuEntry {
    u16 unk0_0 : 4;
    u16 unk0_4 : 4;
    u16 unk0_8 : 8;
    u8 unk2[0x1a];
} ov006_MenuEntry;

/* Singleton at data_ov006_021ec888 (0x1dc bytes). */
typedef struct ov006_Unk021ec888 {
    void *vtbl;
    void *vtbl2;
    int unk8;
    u16 unkC;
    int unk10;
    int unk14;
    u8 unk18;
    int unk1C;
    ov006_MenuNode *nodes;
    u16 unk24;
    u8 unk26;
    int unk28;
    u8 unk2C;
    int unk30;
    ov006_MenuData unk34;
    u8 unkF4[0x66];
    u16 unk15A;
    u16 unk15C;
    u8 unk15E;
    u8 unk15F;
    u8 unk160;
    ov006_MenuEntry entries[4];
    struct ov006_ModelHolder *unk1D4;
    ov006_ObjectHolder *unk1D8;
} ov006_Unk021ec888;

extern ov006_Manager *data_ov006_021ec860;
extern ov006_Unk021ec888 *data_ov006_021ec888;

void *func_0203dd9c(u32 size);
void func_0203de1c(void *p);
void func_0201bbfc(int a);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
/* Declares virtual slots by byte offset so C++ code can make virtual calls
 * on objects whose classes are not known yet. Never instantiated. */
struct VObj {
    virtual int v00(...);
    virtual int v04(...);
    virtual int v08(...);
    virtual int v0C(...);
    virtual int v10(...);
    virtual int v14(...);
    virtual int v18(...);
    virtual int v1C(...);
    virtual int v20(...);
    virtual int v24(...);
    virtual int v28(...);
    virtual int v2C(...);
    virtual int v30(...);
    virtual int v34(...);
    virtual int v38(...);
    virtual int v3C(...);
    virtual int v40(...);
    virtual int v44(...);
    virtual int v48(...);
    virtual int v4C(...);
    virtual int v50(...);
    virtual int v54(...);
    virtual int v58(...);
    virtual int v5C(...);
    virtual int v60(...);
    virtual int v64(...);
    virtual int v68(...);
    virtual int v6C(...);
    virtual int v70(...);
    virtual int v74(...);
    virtual int v78(...);
    virtual int v7C(...);
    virtual int v80(...);
    virtual int v84(...);
    virtual int v88(...);
    virtual int v8C(...);
    virtual int v90(...);
    virtual int v94(...);
    virtual int v98(...);
    virtual int v9C(...);
    virtual int vA0(...);
    virtual int vA4(...);
    virtual int vA8(...);
    virtual int vAC(...);
    virtual int vB0(...);
    virtual int vB4(...);
    virtual int vB8(...);
    virtual int vBC(...);
    virtual int vC0(...);
    virtual int vC4(...);
    virtual int vC8(...);
    virtual int vCC(...);
    virtual int vD0(...);
    virtual int vD4(...);
    virtual int vD8(...);
    virtual int vDC(...);
    virtual int vE0(...);
    virtual int vE4(...);
    virtual int vE8(...);
    virtual int vEC(...);
    virtual int vF0(...);
    virtual int vF4(...);
    virtual int vF8(...);
    virtual int vFC(...);
};
#define VCALL(obj, off, ...) (((VObj *)(obj))->v##off(__VA_ARGS__))
#endif

#endif
