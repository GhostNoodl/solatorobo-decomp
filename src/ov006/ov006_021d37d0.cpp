#include "ov006/Tasks.h"

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

extern "C" {

extern void *data_ov006_021ebdc0;
extern char data_ov006_021ebc0a[];
extern char data_ov006_021ebc1c[];
extern char data_ov006_021ebc2d[];
extern char data_ov006_021ebc37[];
extern char data_ov006_021ebc3e[];
extern char data_ov006_021ebc4a[];

ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_0204b370(void *self);
void func_0204b420(void *self);
void func_ov000_0218ea20(void *self);
void func_ov000_0218fee4(void *self);
ov006_Model60 *func_ov000_0218e9c4(void *self);
void func_0203df0c(void *p);
void func_02035acc(const char *a, const char *b, int c);
const char *func_0207011c(u16 id);
const char *func_020701d4(u16 id);
int func_ov000_0218f110(ov006_Model60 *self);

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, data_ov006_021ebc0a, info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, data_ov006_021ebc1c, info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

BOOL func_ov006_021d37d0(ov006_Window *window, ov006_ListNode *node) {
    if (node != NULL) {
        ov006_TaskD37 *t;
        u16 id;
        id = node->id;
        t = (ov006_TaskD37 *)window->owner;
        ov006_TaskD37_Select(t, id);
    }
    return TRUE;
}

ov006_TaskD37 *func_ov006_021d3874(ov006_TaskD37 *self) {
    OV006_TASKBASE_CTOR(&self->head);
    self->head.vtbl = &data_ov006_021ebdc0;
    func_0204b370(self->unk7C);
    self->unk3C = 0;
    self->unk44 = 0;
    self->unk46 = 0;
    self->unk48 = 0;
    self->unk3D = 1;
    self->unk4C = self->unk4A = data_ov006_021ec884->unk6;
    self->unk50 = NULL;
    self->unk54 = NULL;
    self->unk58 = NULL;
    self->unk5C = NULL;
    self->unk60 = NULL;
    self->unk64 = NULL;
    self->unk68 = NULL;
    self->unk6C = NULL;
    self->unk70 = NULL;
    self->unk74 = NULL;
    self->unk138 = NULL;
    self->unk13C = NULL;
    return self;
}

#define OV006_DELETE_WITH(obj, dtor)                             \
    do {                                                         \
        void *saved_ = data_02097dd0->current;                   \
        data_02097dd0->current = data_02097dd0->unk8;            \
        if ((obj) != NULL) {                                     \
            if ((obj) != NULL) {                                 \
                void *p_ = (obj);                                \
                dtor(p_);                                        \
                func_0203de1c(p_);                               \
            }                                                    \
            (obj) = NULL;                                        \
        }                                                        \
        data_02097dd0->current = saved_;                         \
    } while (0)

static inline void ov006_TaskD37_Dtor(ov006_TaskD37 *self) {
    self->head.vtbl = &data_ov006_021ebdc0;
    OV006_DELETE_OBJECT(self->unk50);
    OV006_DELETE_OBJECT(self->unk54);
    OV006_DELETE_OBJECT(self->unk58);
    OV006_DELETE_OBJECT(self->unk5C);
    OV006_DELETE_WITH(self->unk60, func_ov000_0218ea20);
    OV006_DELETE_WITH(self->unk64, func_ov000_0218fee4);
    OV006_DELETE_WITH(self->unk68, func_ov000_0218ea20);
    OV006_DELETE_WITH(self->unk6C, func_ov000_0218fee4);
    OV006_DELETE_WITH(self->unk70, func_ov000_0218ea20);
    if (self->unk74 != NULL) {
        func_0203df0c(self->unk74);
        self->unk74 = NULL;
    }
    OV006_DELETE_OBJECT(self->unk138);
    OV006_DELETE_OBJECT(self->unk13C);
    func_02035acc(data_ov006_021ebc2d, data_ov006_021ebc37, 6);
    func_0204b420(self->unk7C);
    OV006_TASKBASE_DTOR(&self->head);
}

ov006_TaskD37 *func_ov006_021d3914(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    return self;
}

ov006_TaskD37 *func_ov006_021d3c08(ov006_TaskD37 *self) {
    ov006_TaskD37_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
