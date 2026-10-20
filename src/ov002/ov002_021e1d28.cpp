#include "ov002/ov002.h"

typedef struct ov002_Anim021e0c28 {
    void *vtbl;
    u32 unk4;
    u8 unk8[0x1c];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[4];
    u16 unk34;
    u8 unk36;
    s8 unk37;
    s32 unk38;
    u8 unk3C[8];
    u8 unk44[4];
    u8 unk48[4];
    s32 unk4C;
} ov002_Anim021e0c28;

typedef struct ov002_Caption021e0c28 {
    void *vtbl;
    ov002_Anim021e0c28 *anim;
    s32 text;
    s32 x;
    s32 y;
    s32 nextX;
    s32 nextY;
    s32 unk1C;
    s32 fromX;
    s32 fromY;
    s32 toX;
    s32 toY;
    s32 timer;
    u8 mode;
} ov002_Caption021e0c28;

typedef struct ov002_Flags41 {
    u8 m0 : 1;
    u8 m1 : 1;
    u8 m2 : 1;
    u8 m3 : 1;
} ov002_Flags41;

extern "C" {

void func_ov002_021e1d28(void *self) {
    u32 saved;
    void *p;
    s32 i;
    HEAP_PUSH(saved);
    p = FIELD(self, 0x4, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x4, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0x8, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x8, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0xc, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0xc, void *) = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = FIELD(self, 0x10, void *);
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        FIELD(self, 0x10, void *) = NULL;
    }
    HEAP_POP(saved);
    for (i = 0; i < 5; i++) {
        u32 saved2;
        HEAP_PUSH(saved2);
        DELETE_VOBJ((&FIELD(self, 0x14, VObject *))[i]);
        HEAP_POP(saved2);
    }
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x28, VObject *));
    HEAP_POP(saved);
}

extern VFunc data_0208ba70[];
extern VFunc data_ov002_021f001c[];
extern char data_ov002_021eff94[];
extern char data_ov002_021effa4[];
extern char data_ov002_021effb0[];
extern char data_ov002_021effbc[];
extern char data_ov002_021effc8[];
extern char data_ov002_021effd2[];

void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca14(ov002_Anim021e0c28 *a, int b);
void *func_02035d5c(char *name);
void *func_02035de0(void *file, void *name);
void func_02041c5c(void *a, void *fn);
void *func_ov002_021e1988(void *a, void *b, void *c, u16 *d);

static inline ov002_Anim021e0c28 *ov002_Anim_New(void) {
    ov002_Anim021e0c28 *anim = (ov002_Anim021e0c28 *)func_0203dd9c(0xb8);
    if (anim != NULL) {
        *(VFunc **)anim = data_0208ba70;
        func_0204c7d0(anim);
    }
    return anim;
}

static inline void ov002_Anim_Start(ov002_Anim021e0c28 *s, s32 a) {
    s->unk24 = a;
    s->unk4C = func_0204c4fc(s->unk28, s->unk38, s->unk24, s->unk44, s->unk48, s->unk37 != 0 ? TRUE : FALSE);
    FIELD(data_02097ce0, 0x4, s32) = s->unk28;
}

static inline void *ov002_Model_New(void *name, void *file) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, file);
    }
    return m;
}

static inline ov002_Caption021e0c28 *ov002_Caption_New(void) {
    ov002_Caption021e0c28 *c = (ov002_Caption021e0c28 *)func_0203dd9c(0x38);
    if (c != NULL) {
        c->vtbl = data_ov002_021f001c;
        c->anim = NULL;
        c->text = 0;
        c->y = 0;
        c->x = 0;
        c->nextY = 0;
        c->nextX = 0;
        c->fromY = 0;
        c->fromX = 0;
        c->toY = 0;
        c->toX = 0;
        c->timer = 0;
        c->mode = 0;
    }
    return c;
}

void func_ov002_021e1ed8(void *self) {
    void *res = data_02149ef8;
    char buf[0x20];
    void *arc;
    void *data;
    s32 i;
    func_0206e900(buf, data_ov002_021eff94);
    arc = func_02035d5c(buf);
    {
        char *name = data_ov002_021effa4;
        data = func_02034d88(arc, name);
        FIELD(self, 0x4, void *) = ov002_Model_New(name, buf);
    }
    func_020417e0(FIELD(self, 0x4, void *), data);
    FIELD(FIELD(self, 0x4, u8 *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0x4, u8 *), 0x150, s32) = -0x2000;
    func_02041d9c(FIELD(self, 0x4, void *), 2, 0);
    FIELD(self, 0x41, u8) |= 1;
    {
        char *name = data_ov002_021effb0;
        data = func_02034d88(arc, name);
        FIELD(self, 0x8, void *) = ov002_Model_New(name, buf);
    }
    func_020417e0(FIELD(self, 0x8, void *), data);
    FIELD(FIELD(self, 0x8, u8 *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0x8, u8 *), 0x150, s32) = -0x1ccd;
    func_02041d9c(FIELD(self, 0x8, void *), 2, 0);
    FIELD(self, 0x41, u8) |= 2;
    {
        char *file = buf;
        char *name = data_ov002_021effbc;
        data = func_02035de0(file, name);
        FIELD(self, 0xc, void *) = ov002_Model_New(name, file);
    }
    func_020417e0(FIELD(self, 0xc, void *), data);
    FIELD(FIELD(self, 0xc, u8 *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0xc, u8 *), 0x150, s32) = -0x2000;
    func_02041d9c(FIELD(self, 0xc, void *), 2, 0);
    FIELD(self, 0x41, u8) |= 4;
    {
        char *file = data_ov002_021effc8;
        char *name = data_ov002_021effd2;
        data = func_02035de0(file, name);
        FIELD(self, 0x10, void *) = ov002_Model_New(name, file);
    }
    func_020417e0(FIELD(self, 0x10, void *), data);
    FIELD(FIELD(self, 0x10, u8 *), 0x6c, u32) |= 2;
    FIELD(FIELD(self, 0x10, u8 *), 0x150, s32) = -0x1ccd;
    func_02041c5c(FIELD(self, 0x10, void *), (void *)func_ov002_021e1988);
    func_02041d9c(FIELD(self, 0x10, void *), 2, 1);
    func_02041d9c(FIELD(self, 0x10, void *), 2, 8);
    func_02041d9c(FIELD(self, 0x10, void *), 2, 9);
    func_02041d9c(FIELD(self, 0x10, void *), 2, 10);
    FIELD(self, 0x41, u8) |= 8;
    for (i = 0; i < 5; i++) {
        ov002_Caption021e0c28 *c;
        s32 text;
        s32 y;
        ((ov002_Caption021e0c28 **)((u8 *)self + 0x14))[i] = ov002_Caption_New();
        text = (s32)func_0204c0e8(res, data_ov002_021ef058[0][i]);
        c = ((ov002_Caption021e0c28 **)((u8 *)self + 0x14))[i];
        if (text != 0) {
            if (c->anim == NULL) {
                c->anim = ov002_Anim_New();
            }
            ((VObject *)c->anim)->v0x8();
            c->anim->unk28 = 3;
            c->anim->unk2C = 0;
            c->anim->unk34 = 1;
            ov002_Anim_Start(c->anim, text);
            func_0204ca14(c->anim, 8);
            c->anim->unk4 |= 4;
        }
        c = ((ov002_Caption021e0c28 **)((u8 *)self + 0x14))[i];
        y = i * 0x12 + 0x1b;
        if (i >= 0 && i <= 3) {
            c->nextX = 0x1c;
            c->nextY = y;
            c->unk1C = 0x54;
        } else if (i == 4) {
            c->nextX = 0x26;
            c->nextY = y;
            c->unk1C = 0x4a;
        }
        c = ((ov002_Caption021e0c28 **)((u8 *)self + 0x14))[i];
        c->x = -0x80;
        c->y = y;
        c = ((ov002_Caption021e0c28 **)((u8 *)self + 0x14))[i];
        c->fromX = c->x;
        c->fromY = c->y;
        c->toX = c->nextX;
        c->toY = c->nextY;
        c->mode = 2;
        c->timer = 8;
    }
}

}
