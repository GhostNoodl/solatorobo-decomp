#include "ov002/ov002.h"

extern "C" {

void Ov002_CopyVec2(Vec2 *dst, const Vec2 &src);
void Ov002_MultVec33(void *a, void *b, void *c);
s32 Ov002_FxMul(s32 a, s32 b);
void Ov002_QuarterRotMtx33(s32 *m, int rot);
void *func_ov002_021e3874(void *v, u8 a, u8 b);
void Ov002_PlaySe(int se);
void func_ov002_021e00bc(Obj021eff30 *self);
void func_ov002_021dfcc0(Obj021eff30 *self);
void *Heap_GetCurrent(void);
void Heap_SetCurrentHi(void);
void Heap_SetCurrent(void *heap);

void func_ov002_021df7f0(Obj021eff30 *self, Obj021eff50 *a) {
    self->owner = a;
    Obj021efe5c_SyncAnmFrame(self->unk_0c);
    self->unk_10->vfunc_0c();
    Obj021efe8c_SyncAnmFrame(self->unk_14);
    switch (self->unk_18) {
    case 0:
        if (func_ov002_021dc834(self->unk_10) == 1) {
            self->unk_18++;
        } else {
            func_ov002_021d8ba4(self->unk_10);
            break;
        }
    case 1:
        func_ov002_021dfcc0(self);
        break;
    case 10:
        func_ov002_021e00bc(self);
        break;
    case 20:
        if (func_ov002_021dc834(self->unk_10) == 2) {
            self->unk_18++;
            Obj021efe9c_GetCell(self->unk_10, (Vec2 *)((u8 *)self + 0x1c));
        } else {
            func_ov002_021d8b7c(self->unk_10);
            break;
        }
    case 21: {
        VecFx32 v;
        s32 mtx[9];
        VecFx32 off;
        Vec2 p;
        Ov002Shape *m;
        Obj021efe9c_GetOrigin(self->unk_10, &p);
        Ov002_CellToPos(&v.x, (s32 *)((u8 *)self + 0x1c), &p.x);
        m = Obj021efe9c_GetShape(self->unk_10);
        Ov002_QuarterRotMtx33(mtx, Obj021efe9c_GetRot(self->unk_10));
        off.x = Ov002_FxMul((m->w - m->ox * 2) << 11, 0x28f) + (0x148 - 0x28f);
        off.y = 0;
        off.z = Ov002_FxMul((m->h - m->oy * 2) << 11, 0x28f) + (0x148 - 0x28f);
        Ov002_MultVec33(&off, mtx, &off);
        v.y = 0x266;
        v.x += off.x;
        v.z += off.z;
        func_ov002_021e3874(&v, func_ov002_021d8b74(self->unk_10), m->w);
        Ov002_PlaySe(0x45);
        Obj021efe6c_AppendPiece(Obj021eff50_GetBoard(a), self->unk_10);
        self->unk_10 = NULL;
        {
            Obj021eff10 *q = (Obj021eff10 *)Heap_Alloc(sizeof(Obj021eff10));
            if (q != NULL) {
                q = Ov002Vt_021eff10_Ctor(q);
            }
            func_ov002_021dbd08(a, q, 10);
        }
        self->unk_18 = 0x32;
        break;
    }
    case 30:
        if (self->unk_08 == 10) {
            if (func_ov002_021dc834(self->unk_10) == 2) {
                Obj021efe6c_AppendPiece(Obj021eff50_GetBoard(a), self->unk_10);
                self->unk_10 = NULL;
                {
                    Obj021eff10 *q = (Obj021eff10 *)Heap_Alloc(sizeof(Obj021eff10));
                    if (q != NULL) {
                        q = Ov002Vt_021eff10_Ctor(q);
                    }
                    func_ov002_021dbd08(a, q, 10);
                }
                self->unk_18 = 0x32;
            } else {
                func_ov002_021d8b7c(self->unk_10);
                Obj021efe9c_SetCell(self->unk_10, (Vec2 *)((u8 *)self + 0x24));
                Obj021efe9c_SetRot(self->unk_10, self->unk_2c);
                Obj021efe9c_GetCell(self->unk_10, (Vec2 *)((u8 *)self + 0x1c));
            }
        } else if (func_ov002_021dc834(self->unk_10) == 0) {
            u16 id = func_ov002_021d9e30(self->unk_10);
            Obj021efef0 *q;
            void *h;
            func_ov002_021dd9d4(Obj021eff50_GetBoard(a))[(u16)(id & 0xfff)]++;
            Ov002_CopyVec2((Vec2 *)((u8 *)self + 0x1c), *(Vec2 *)((u8 *)self + 0x24));
            q = (Obj021efef0 *)Heap_Alloc(sizeof(Obj021efef0));
            if (q != NULL) {
                q = Ov002Vt_021efef0_Ctor(q);
            }
            func_ov002_021dfc44(q, func_ov002_021d9e30(self->unk_10));
            func_ov002_021dbd08(a, q, 0x14);
            h = Heap_GetCurrent();
            Heap_SetCurrentHi();
            DELETE_VOBJ(FIELD(self, 0x10, VObj *));
            Heap_SetCurrent(h);
            self->unk_18 = 0x32;
        } else {
            func_ov002_021d8bcc(self->unk_10);
        }
        break;
    case 40:
        if (func_ov002_021dc834(self->unk_10) == 0) {
            u16 id = func_ov002_021d9e30(self->unk_10);
            Obj021eff10 *q;
            void *h;
            func_ov002_021dd9d4(Obj021eff50_GetBoard(self->owner))[(u16)(id & 0xfff)]++;
            q = (Obj021eff10 *)Heap_Alloc(sizeof(Obj021eff10));
            if (q != NULL) {
                q = Ov002Vt_021eff10_Ctor(q);
            }
            func_ov002_021dbd08(self->owner, q, 10);
            h = Heap_GetCurrent();
            Heap_SetCurrentHi();
            DELETE_VOBJ(FIELD(self, 0x10, VObj *));
            Heap_SetCurrent(h);
            self->unk_18 = 0x32;
        } else {
            func_ov002_021d8bcc(self->unk_10);
        }
        break;
    }
    self->owner = NULL;
}

}
