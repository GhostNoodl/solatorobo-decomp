#include "ov002/ov002.h"

extern "C" {

extern char data_ov002_021f0d00[];

extern char data_ov002_021f0d0f[];

void func_ov002_021eb298(Ov002StageFile *self);

void func_ov002_021ebcf8(Ov002StageFile *self, int kind, u8 *data, Ov002Obj021f075c **out);

void func_ov002_021eb0f8(Ov002StageFile *self);

void func_ov002_021eb448(Ov002StageFile *self);

void func_ov002_021eb7c0(Ov002StageFile *self);

void func_ov002_021eb870(Ov002StageFile *self);

void Ov002_MakeSlideName(void *dst, u32 size, void *src, int mode, u8 idx);

void Ov002_MakeSlideFileName(void *dst, u32 size, void *src, int mode, u8 idx);

Ov002Obj *Ov002Obj021f07ac_New(void *a, void *b);

Ov002Obj *Ov002Obj021f06bc_New(void *a, void *b);

Ov002Obj *Ov002Obj021f0784_New(s32 a, s32 b, s32 c, s32 d, u16 e, s32 mode, u8 f, u8 g);

typedef struct Hdr021eaf20 {
    s32 count;
    s32 stride;
} Hdr021eaf20;

typedef struct Rec021eaf20 {
    s32 a;
    s32 b;
    u8 d;
    s32 mode;
    s32 c;
    s32 e;
    u16 f;
    u16 g;
} Rec021eaf20;

void Ov002StageFile_BuildScene(Ov002StageFile *self) {
    u8 *d;
    s32 stride;
    s32 i;
    s32 n;
    u8 *src;
    Rec021eaf20 rec;
    char bufB[0x20];
    char bufA[0x20];
    char bufD[0x20];
    char bufC[0x20];
    s32 end;
    Hdr021eaf20 hdr;
    func_ov002_021eb298(self);
    func_ov002_021ebcf8(self, 2, self->unk_1c, self->unk_44);
    func_ov002_021ebcf8(self, 3, self->unk_20, self->unk_48);
    func_ov002_021ebcf8(self, 3, self->unk_24, self->unk_4c);
    func_ov002_021eb0f8(self);
    func_ov002_021eb448(self);
    d = self->unk_28;
    MI_CpuCopy8(d + 8, &hdr, 8);
    n = hdr.count;
    src = d + 0x10;
    stride = hdr.stride;
    for (i = 0; i < n; i++) {
        MI_CpuCopy8(src, &rec, 0x1c);
        Ov002Obj021f0784_New(rec.a, rec.b, rec.c, rec.d, rec.e, rec.mode, rec.f, rec.g);
        src += stride;
    }
    func_ov002_021eb7c0(self);
    func_ov002_021eb870(self);
    Ov002_MakeSlideName(bufA, 0x20, data_ov002_021f0d00, 1, ((u8 (*)(void))LangData_GetLang)());
    Ov002_MakeSlideFileName(bufB, 0x20, self->unk_04, 1, ((u8 (*)(void))LangData_GetLang)());
    Ov002Obj021f06bc_New(bufA, bufB);
    Ov002_MakeSlideName(bufC, 0x20, data_ov002_021f0d0f, 2, ((u8 (*)(void))LangData_GetLang)());
    Ov002_MakeSlideFileName(bufD, 0x20, self->unk_04, 2, ((u8 (*)(void))LangData_GetLang)());
    Ov002Obj021f07ac_New(bufC, bufD);
    MI_CpuCopy8(self->data + 0xc, &end, 4);
    Ov002Vt_021f0694_New(end);
}

void *Heap_AllocArray(u32 size);

Ov002Obj *Ov002Cam021f07fc_New(u8 *a, u8 *b);

Ov002Obj *Ov002Cam021f0828_New(u8 *a, u8 *b);

void Ov002Cam021f0828_SetFovy(Ov002Cam021f0828 *self, s32 deg);


typedef struct Hdr021eb0f8 {
    s32 count;
    s32 stride;
} Hdr021eb0f8;

typedef struct Rec021eb0f8 {
    s16 id;
    s16 type;
    s16 parent;
} Rec021eb0f8;

typedef struct Ent021eb0f8 {
    Ov002Obj *obj;
    s32 parent;
} Ent021eb0f8;

void func_ov002_021eb0f8(Ov002StageFile *self) {
    Rec021eb0f8 rec;
    Hdr021eb0f8 hdr;
    u8 *d = self->unk_10;
    s32 n;
    s32 stride;
    u8 *src;
    Ent021eb0f8 *tbl;
    s32 i;
    MI_CpuCopy8(d + 8, &hdr, 8);
    n = hdr.count;
    stride = hdr.stride;
    src = d + 0x10;
    tbl = (Ent021eb0f8 *)Heap_AllocArray(n * 8);
    for (i = 0; i < n; i++) {
        Ov002Obj *obj;
        s32 k;
        s32 cnt;
        MI_CpuCopy8(src, &rec, 6);
        switch (rec.type) {
        case 0:
            obj = Ov002Cam021f07fc_New(NULL, NULL);
            break;
        case 1:
            obj = Ov002Cam021f0828_New(NULL, NULL);
            Ov002Cam021f0828_SetFovy((Ov002Cam021f0828 *)obj, 0x1e000);
            break;
        case 2:
            obj = Ov002Cam021f0828_New(NULL, NULL);
            Ov002Cam021f0828_SetFovy((Ov002Cam021f0828 *)obj, 0x28000);
            break;
        case 3:
            obj = Ov002Cam021f0828_New(NULL, NULL);
            Ov002Cam021f0828_SetFovy((Ov002Cam021f0828 *)obj, 0xf000);
            break;
        }
        ((Ov002Cam021f0854 *)obj)->unk_4c = rec.id;
        obj->unk_08 = (i % 2) ? 2 : 1;
        cnt = self->unk_58;
        for (k = 0; k < cnt; k++) {
            Ov002Obj021f075c *q = self->unk_48[k];
            if (rec.id == q->unk_5c) {
                q->owner = obj;
                Ov002Obj_AddChild(obj, self->unk_48[k]);
            }
        }
        tbl[i].obj = obj;
        tbl[i].parent = rec.parent;
        src += stride;
    }
    for (i = 0; i < n; i++) {
        s32 par = tbl[i].parent;
        Ov002Obj *o = tbl[i].obj;
        if (par >= 0) {
            Ov002Obj *po = tbl[par].obj;
            o->owner = po;
            Ov002Obj_AddChild(po, o);
        }
    }
    Heap_Free(tbl);
}

s32 func_0201e950(const void *a, const void *b, u32 n);

typedef struct Rec021eb298 {
    s32 id;
    u8 kind;
    u8 flags;
    u8 pad[2];
} Rec021eb298;

static inline void ov002_addPair(Ov002ResList *list, char *a, char *b, s32 kind) {
    Ov002ResNode *n;
    for (n = list->head; n != NULL; n = n->next) {
        if (func_0201e950(n->a, a, STD_GetStringLength(n->a)) == 0 && func_0201e950(n->b, b, STD_GetStringLength(n->a)) == 0 && n->kind == kind) {
            break;
        }
    }
    if (n == NULL) {
        n = (Ov002ResNode *)Heap_Alloc(0x50);
        MI_CpuFill8(n->a, 0, 0x20);
        MI_CpuFill8(n->b, 0, 0x20);
        n->unk_44 = 0;
        n->unk_48 = 0;
        n->next = NULL;
        STD_CopyLString(n->a, a, 0x20);
        STD_CopyLString(n->b, b, 0x20);
        n->kind = kind;
        n->next = list->head;
        list->head = n;
    }
}

static inline void ov002_initEnt(Ov002ObjLink *e) {
    e->id = 0;
    e->arc = NULL;
    e->name = NULL;
    e->task = 0;
    e->res = NULL;
    e->loaded = 0;
    e->alt = 0;
    e->res2 = NULL;
}

void func_ov002_021eb298(Ov002StageFile *self) {
    Rec021eb298 rec;
    s32 hdr[2];
    u8 *d;
    s32 n;
    u8 *src;
    s32 i;
    d = self->unk_18;
    MI_CpuCopy8(d + 8, hdr, 8);
    n = hdr[0];
    src = d + 0x10;
    for (i = 0; i < n; i++) {
        Ov002ObjLink *e;
        u8 fl;
        MI_CpuCopy8(src, &rec, 8);
        fl = rec.flags;
        e = &self->links[i];
        ov002_initEnt(e);
        src += 8;
        {
            s32 f1 = fl & 1;
            e->arc = f1 ? (char *)src : NULL;
            if (f1) {
                src += 0x18;
            }
        }
        {
            s32 f2 = fl & 2;
            e->name = f2 ? (char *)src : NULL;
            if (f2) {
                src += 0x18;
            }
        }
        e->id = rec.kind;
        if (self->unk_60 != NULL) {
            ov002_addPair(self->unk_60, e->arc, e->name, 5);
        }
    }
}

void Ov002Obj021f07d4_AddLink(Ov002Obj021f07d4 *self, Ov002ObjLink *src);

typedef struct Hdr021eb448 {
    s32 count;
    s32 stride;
} Hdr021eb448;

typedef struct Rec021eb448 {
    s32 id;
    s32 a;
    s32 b;
    u8 c;
    u8 pad[3];
    u8 kind;
    u8 speed;
    u16 extra;
    u32 mask;
} Rec021eb448;

void func_ov002_021eb448(Ov002StageFile *self) {
    Hdr021eb448 hdr;
    Rec021eb448 rec;
    u8 *d;
    u8 *src;
    s32 n;
    s32 stride;
    s32 i;
    d = self->unk_14;
    MI_CpuCopy8(d + 8, &hdr, 8);
    src = d + 0x10;
    n = hdr.count;
    stride = hdr.stride;
    for (i = 0; i < n; i++) {
        Ov002Obj021f07d4 *obj;
        u8 *s1;
        u8 *s2;
        u8 *s3;
        s32 off;
        s32 spd;
        s32 q;
        s32 j;
        s32 m;
        s32 m2;
        s32 k;
        MI_CpuCopy8(src, &rec, 0x18);
        obj = (Ov002Obj021f07d4 *)Ov002Obj021f07d4_New(rec.a, rec.b, rec.c, false, 0);
        obj->unk_4c = rec.id;
        switch (rec.kind) {
        case 0:
            obj->unk_1f0_1 = 0;
            obj->unk_1f0_0 = 0;
            break;
        case 1:
            obj->unk_1f0_1 = 1;
            obj->unk_1f0_0 = 0;
            break;
        case 2:
            obj->unk_1f0_1 = 0;
            obj->unk_1f0_0 = 1;
            break;
        }
        switch (rec.speed) {
        case 0:
            spd = -0xa66;
            break;
        case 1:
            spd = -0x119a;
            break;
        case 2:
            spd = -0x18cd;
            break;
        case 3:
            spd = -0x2000;
            break;
        default:
            spd = -0xa66;
            break;
        }
        obj->unk_20 = spd;
        off = 0x18;
        s1 = (rec.mask & 1) ? src + 0x18 : NULL;
        if (rec.mask & 1) {
            off += 0x18;
        }
        s2 = (rec.mask & 2) ? src + off : NULL;
        if (rec.mask & 2) {
            off += 0x18;
        }
        s3 = (rec.mask & 4) ? src + off : NULL;
        obj->res.arc = (char *)s1;
        obj->res.name = (char *)s2;
        obj->res.item = (char *)s3;
        for (q = 0; q < self->linkCount; q++) {
            Ov002ObjLink *l = &self->links[q];
            if (l->id == obj->unk_4c) {
                Ov002Obj021f07d4_AddLink(obj, l);
            }
        }
        m = self->unk_54;
        for (j = 0; j < m; j++) {
            if (rec.id == self->unk_44[j]->unk_5c) {
                Ov002Obj_AddChild(obj, self->unk_44[j]);
                self->unk_44[j]->owner = obj;
                self->unk_44[j]->unk_08 = obj->unk_08;
            }
        }
        m2 = self->unk_5c;
        for (k = 0; k < m2; k++) {
            if (rec.id == self->unk_4c[k]->unk_5c) {
                Ov002Obj_AddChild(obj, self->unk_4c[k]);
                self->unk_4c[k]->owner = obj;
                self->unk_4c[k]->unk_08 = obj->unk_08;
            }
        }
        if (self->unk_60 != NULL && s1 != NULL && s2 != NULL) {
            ov002_addPair(self->unk_60, (char *)s1, (char *)s2, 4);
        }
        src += stride + rec.extra;
    }
}

}
