#ifndef OV006_WINDOW_H
#define OV006_WINDOW_H

#include "ov006/Model.h"

typedef struct ov006_ListNode {
    const char *text;
    u16 unk4;
    u16 id;
    u32 unk8;
    u32 unkC;
    int unk10;
    u8 unk14[0x8];
    struct Object *unk1C;
    u8 unk20[0x4];
    int unk24;
    u8 unk28[4];
    struct ov006_ListNode *next;
} ov006_ListNode;

typedef struct ov006_Widget {
    void *vtbl;
    u32 unk4_0 : 6;
    u32 busy : 1;
    u32 unk4_7 : 25;
    u8 unk8[0x64];
    void *unk6C;
} ov006_Widget;

typedef struct ov006_Window ov006_Window;
typedef BOOL (*ov006_WindowFunc)(ov006_Window *self, ov006_ListNode *node);

struct ov006_Window {
    void *vtbl;
    int state;
    void *owner;
    u32 flags;
    int unk10;
    ov006_Widget *unk14;
    ov006_Widget *unk18;
    int unk1C;
    int unk20;
    int unk24;
    u8 unk28[0x4];
    int unk2C;
    u8 unk30[0x4];
    int unk34;
    u8 unk38[0x10];
    u16 unk48;
    u16 unk4A;
    u8 unk4C[0xc];
    int unk58;
    int unk5C;
    int unk60;
    s16 unk64;
    s16 unk66;
    s16 unk68;
    u8 unk6A[0x16];
    void (*unk80)(int arg, ov006_Window *self, int arg2);
    ov006_WindowFunc unk84;
    ov006_WindowFunc unk88;
    ov006_WindowFunc unk8C;
    ov006_WindowFunc unk90;
    u8 unk94[0x4];
    ov006_ListNode *unk98;
    u8 unk9C[0x15];
    s8 unkB1;
    u8 unkB2[0x2];
    int unkB4;
    void *unkB8;
    u8 unkBC[0x4];
    u8 unkC0;
    s8 unkC1;
    u8 unkC2[0x12];
    ov006_Widget *unkD4;
};

static inline ov006_ListNode *ov006_Window_GetSelected(ov006_Window *self) {
    ov006_ListNode *node = self->unk98;
    int i;
    if (node == NULL) {
        return NULL;
    }
    i = self->unkB1;
    while (i-- != 0) {
        node = node->next;
    }
    return node;
}

static inline void ov006_Window_SetRot(ov006_Window *self, s16 x, s16 y, s16 z) {
    self->unk64 = x;
    self->unk66 = y;
    self->unk68 = z;
}

static inline void ov006_Window_SetPos(ov006_Window *self, int x, int y, int z) {
    self->unk58 = x;
    self->unk5C = y;
    self->unk60 = z;
}

#define OV006_LISTNODE_SETTEXT(node, str)    \
    do {                                      \
        (node)->text = NULL;                  \
        OV006_DELETE_OBJECT((node)->unk1C);   \
        (node)->text = (str);                 \
    } while (0)

static inline BOOL ov006_Window_IsState5(ov006_Window *self) {
    return self->state == 5 ? TRUE : FALSE;
}

/* Base of the overlay's tasks (base vtable data_ov000_021cc060). */
typedef struct ov006_TaskFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} ov006_TaskFlags;

typedef struct ov006_TaskBase {
    void *vtbl;
    union {
        u32 flags;
        ov006_TaskFlags f;
    };
    int unk8;
    int unkC;
    u8 unk10[0x10];
    int unk20;
    u8 unk24[0x18];
    int state;
    int subState;
} ov006_TaskBase;

#ifdef __cplusplus
extern "C" {
#endif
extern void *data_ov000_021cc060;
#ifdef __cplusplus
}
#endif

#define OV006_TASKBASE_CTOR(self)              \
    do {                                       \
        (self)->vtbl = &data_ov000_021cc060;   \
        VCALL((self), 58);                     \
    } while (0)

#define OV006_TASKBASE_DTOR(self)              \
    do {                                       \
        (self)->vtbl = &data_ov000_021cc060;   \
        VCALL((self), 5C);                     \
    } while (0)

#endif
