#ifndef OV006_OV006_H
#define OV006_OV006_H

#include "types.h"
#include "Main/Sys/SysState.h"

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


/* Deletes a virtual object while temporarily switching the current heap. */
#define OV006_DELETE_OBJECT(obj)                                 \
    do {                                                         \
        void *saved_ = data_02097dd0->cur;                       \
        data_02097dd0->cur = data_02097dd0->heapHi;              \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                ((Object *)(obj))->vtbl->dtor((Object *)(obj));  \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->cur = saved_;                             \
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
    int state;
    u16 stateTime;
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

void *Heap_Alloc(u32 size);
void Heap_Free(void *p);
void func_0201bbfc(u32 a);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
#include "ov000/VObj.h"
#define VCALL(obj, off, ...) (((VObj *)(obj))->vfunc_##off(__VA_ARGS__))
#endif

#endif
