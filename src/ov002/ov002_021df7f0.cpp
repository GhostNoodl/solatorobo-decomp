#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d8b04(void *self, Vec2 *out);
void Ov002_CopyVec2(Vec2 *dst, const Vec2 &src);
void func_ov002_021d8b2c(void *self, Vec2 *out);
void *func_ov002_021d8b40(void *self);
u8 func_ov002_021d8b48(void *self);
void Ov002_MultVec33(void *a, void *b, void *c);
u8 func_ov002_021d8b74(void *self);
void func_ov002_021d8b7c(void *self);
void func_ov002_021d8ba4(void *self);
void func_ov002_021d8bcc(void *self);
s32 Ov002_FxMul(s32 a, s32 b);
s32 func_ov002_021dc834(void *self);
void *func_ov002_021dc270(void *self);
u8 *func_ov002_021dd9d4(void *self);
u16 func_ov002_021d9e30(void *self);
void func_ov002_021d9e38(void *self, void *node);
void *Ov002Vt_021eff10_Ctor(void *self);
void func_ov002_021dbd08(void *self, void *a, s32 b);
void func_ov002_021dfc44(void *self, u16 v);
void *Ov002Vt_021efef0_Ctor(void *self);
void func_ov002_021e398c(s32 *m, int rot);
void *func_ov002_021e3874(void *v, u8 a, u8 b);
void func_ov002_021d7424(int se);
void func_ov002_021d7c54(void *self, u16 rot);
void func_ov002_021df7b4(void *self, void *ev);
void func_ov002_021e00bc(void *self);
void func_ov002_021dfcc0(void *self);
void func_ov002_021d792c(void *self);
void func_ov002_021d788c(void *self);
void *Heap_GetCurrent(void);
void func_0204c284(void);
void Heap_SetCurrent(void *heap);

void func_ov002_021df7f0(void *self, void *a) {
    FIELD(self, 0x4, void *) = a;
    func_ov002_021d792c(FIELD(self, 0xc, void *));
    FIELD(self, 0x10, VObject *)->v0xc();
    func_ov002_021d788c(FIELD(self, 0x14, void *));
    switch (FIELD(self, 0x18, s32)) {
    case 0:
        if (func_ov002_021dc834(FIELD(self, 0x10, void *)) == 1) {
            FIELD(self, 0x18, s32)++;
        } else {
            func_ov002_021d8ba4(FIELD(self, 0x10, void *));
            break;
        }
    case 1:
        func_ov002_021dfcc0(self);
        break;
    case 10:
        func_ov002_021e00bc(self);
        break;
    case 20:
        if (func_ov002_021dc834(FIELD(self, 0x10, void *)) == 2) {
            FIELD(self, 0x18, s32)++;
            func_ov002_021d8b04(FIELD(self, 0x10, void *), (Vec2 *)((u8 *)self + 0x1c));
        } else {
            func_ov002_021d8b7c(FIELD(self, 0x10, void *));
            break;
        }
    case 21: {
        VecFx32 v;
        s32 mtx[9];
        VecFx32 off;
        Vec2 p;
        u8 *m;
        func_ov002_021d8b2c(FIELD(self, 0x10, void *), &p);
        func_ov002_021e3b0c(&v.x, (s32 *)((u8 *)self + 0x1c), &p.x);
        m = (u8 *)func_ov002_021d8b40(FIELD(self, 0x10, void *));
        func_ov002_021e398c(mtx, func_ov002_021d8b48(FIELD(self, 0x10, void *)));
        off.x = Ov002_FxMul((FIELD(m, 4, Nibbles16).n2 - FIELD(m, 6, Nibbles16).n0 * 2) << 11, 0x28f) + (0x148 - 0x28f);
        off.y = 0;
        off.z = Ov002_FxMul((FIELD(m, 4, Nibbles16).n3 - FIELD(m, 6, Nibbles16).n1 * 2) << 11, 0x28f) + (0x148 - 0x28f);
        Ov002_MultVec33(&off, mtx, &off);
        v.y = 0x266;
        v.x += off.x;
        v.z += off.z;
        func_ov002_021e3874(&v, func_ov002_021d8b74(FIELD(self, 0x10, void *)), FIELD(m, 4, Nibbles16).n2);
        func_ov002_021d7424(0x45);
        func_ov002_021d9e38(func_ov002_021dc270(a), FIELD(self, 0x10, void *));
        FIELD(self, 0x10, void *) = NULL;
        {
            void *q = Heap_Alloc(0x134);
            if (q != NULL) {
                q = Ov002Vt_021eff10_Ctor(q);
            }
            func_ov002_021dbd08(a, q, 10);
        }
        FIELD(self, 0x18, s32) = 0x32;
        break;
    }
    case 30:
        if (FIELD(self, 0x8, s32) == 10) {
            if (func_ov002_021dc834(FIELD(self, 0x10, void *)) == 2) {
                func_ov002_021d9e38(func_ov002_021dc270(a), FIELD(self, 0x10, void *));
                FIELD(self, 0x10, void *) = NULL;
                {
                    void *q = Heap_Alloc(0x134);
                    if (q != NULL) {
                        q = Ov002Vt_021eff10_Ctor(q);
                    }
                    func_ov002_021dbd08(a, q, 10);
                }
                FIELD(self, 0x18, s32) = 0x32;
            } else {
                func_ov002_021d8b7c(FIELD(self, 0x10, void *));
                func_ov002_021df7b4(FIELD(self, 0x10, void *), (u8 *)self + 0x24);
                func_ov002_021d7c54(FIELD(self, 0x10, void *), FIELD(self, 0x2c, u8));
                func_ov002_021d8b04(FIELD(self, 0x10, void *), (Vec2 *)((u8 *)self + 0x1c));
            }
        } else if (func_ov002_021dc834(FIELD(self, 0x10, void *)) == 0) {
            u16 id = func_ov002_021d9e30(FIELD(self, 0x10, void *));
            void *q;
            void *h;
            func_ov002_021dd9d4(func_ov002_021dc270(a))[(u16)(id & 0xfff)]++;
            Ov002_CopyVec2((Vec2 *)((u8 *)self + 0x1c), *(Vec2 *)((u8 *)self + 0x24));
            q = Heap_Alloc(0x138);
            if (q != NULL) {
                q = Ov002Vt_021efef0_Ctor(q);
            }
            func_ov002_021dfc44(q, func_ov002_021d9e30(FIELD(self, 0x10, void *)));
            func_ov002_021dbd08(a, q, 0x14);
            h = Heap_GetCurrent();
            func_0204c284();
            DELETE_VOBJ(FIELD(self, 0x10, VObject *));
            Heap_SetCurrent(h);
            FIELD(self, 0x18, s32) = 0x32;
        } else {
            func_ov002_021d8bcc(FIELD(self, 0x10, void *));
        }
        break;
    case 40:
        if (func_ov002_021dc834(FIELD(self, 0x10, void *)) == 0) {
            u16 id = func_ov002_021d9e30(FIELD(self, 0x10, void *));
            void *q;
            void *h;
            func_ov002_021dd9d4(func_ov002_021dc270(FIELD(self, 0x4, void *)))[(u16)(id & 0xfff)]++;
            q = Heap_Alloc(0x134);
            if (q != NULL) {
                q = Ov002Vt_021eff10_Ctor(q);
            }
            func_ov002_021dbd08(FIELD(self, 0x4, void *), q, 10);
            h = Heap_GetCurrent();
            func_0204c284();
            DELETE_VOBJ(FIELD(self, 0x10, VObject *));
            Heap_SetCurrent(h);
            FIELD(self, 0x18, s32) = 0x32;
        } else {
            func_ov002_021d8bcc(FIELD(self, 0x10, void *));
        }
        break;
    }
    FIELD(self, 0x4, void *) = NULL;
}

}
