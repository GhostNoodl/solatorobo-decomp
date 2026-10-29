// Teardown of the scene object: inlines the whole destructor of the object at
// 0x100. Past the default inline size limit MWCC calls the helpers instead.
#pragma inline_max_size(512)

#include "ov011/ov011.h"

struct Ov011Tw108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 unk_02;
    s16 unk_04;
};

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011FreeNode {
    u8 pad[0xc];
    Ov011FreeNode *next;
};

struct Ov011Fed {
    u8 pad[0xf0];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 padf1;
    u16 unk_f2;
    s32 unk_f4;
    s32 unk_f8;
    s32 unk_fc;
    u8 *unk_100;
    u8 *unk_104;
    Ov011Tw108 *unk_108;
    void *unk_10c;
};

struct Ov011Lst {
    u8 pad[4];
    Ov011Lst *next;
};

extern "C" {

extern void *data_0214a420;
extern s32 data_ov011_02207258[];
void func_02065804(void *a, void *b);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov003_021d7800(void *p);
void func_ov011_02201688(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fa7dc(void *p);
void func_ov011_02202f04(void *p);
void *func_ov011_02201d10(void *p);
void *func_ov011_0220154c(void *p);
void *func_ov011_02202cac(void *p);

static inline void Ov011B_FreeBuf(u8 *b) {
    if (FLD(Ov011Bit01, b, 0x10).b0) {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (FLD(void *, b, 0x18) != NULL) {
            func_0203de50(FLD(void *, b, 0x18));
            FLD(void *, b, 0x18) = NULL;
        }
        data_02097dd0->cur = saved;
        FLD(Ov011Bit01, b, 0x10).b0 = 0;
    }
}

static inline void Ov011B_FreeVec(u8 *b) {
    if (FLD(Ov011Bit01, b, 0xb4).b0) {
        FLD(Ov011Bit01, b, 0xb4).b0 = 0;
        {
            u32 saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->def;
            if (FLD(void *, b, 0xbc) != NULL) {
                __cxa_vec_delete(FLD(void *, b, 0xbc), 0x40, 8, func_ov011_021fb66c);
                FLD(void *, b, 0xbc) = NULL;
            }
            data_02097dd0->cur = saved;
        }
        func_ov011_0220205c(b + 0xdc);
        func_ov011_02202fbc(b + 0x194);
    }
}

static inline void Ov011B_FreeList(u8 *b) {
    if (FLD(Ov011Bit01, b, 0x204).b0) {
        if (FLD(Ov011Bit01, b, 0x204).b0) {
            Ov011FreeNode *p = FLD(Ov011FreeNode *, b, 0x208);
            while (p != NULL) {
                Ov011FreeNode *next = p->next;
                if (p != NULL) {
                    func_0203de1c(p);
                }
                p = next;
            }
            FLD(Ov011FreeNode *, b, 0x208) = NULL;
        }
        FLD(Ov011Bit01, b, 0x204).b0 = 0;
    }
}

static inline void Ov011B_Free(u8 *b) {
    if (FLD(Ov011Bit01, b, 0).b0) {
        Ov011Lst *p;
        Ov011Lst *next;
        FLD(Ov011Bit01, b, 0).b0 = 0;
        for (p = FLD(Ov011Lst *, b, 0xc); p != NULL; p = next) {
            next = p->next;
            func_ov003_021d7800(p);
        }
        Ov011B_FreeBuf(b);
        func_ov011_02201688(b + 0x34);
        Ov011B_FreeVec(b);
        if (FLD(Ov011Bit01, b, 0x1b4).b0) {
            FLD(Ov011Bit01, b, 0x1b4).b0 = 0;
        }
        func_ov011_021fa7dc(b + 0x1d4);
        Ov011B_FreeList(b);
    }
}

static inline void Ov011B_Dtor(u8 *b) {
    Ov011B_Free(b);
    Ov011B_FreeList(b);
    func_ov011_021fa7dc(b + 0x1d4);
    if (FLD(Ov011Bit01, b, 0x1b4).b0) {
        FLD(Ov011Bit01, b, 0x1b4).b0 = 0;
    }
    Ov011B_FreeVec(b);
    func_ov011_02202f04(b + 0x194);
    func_ov011_02201d10(b + 0xdc);
    func_ov011_0220154c(b + 0x34);
    Ov011B_FreeBuf(b);
}

void func_ov011_0220068c(Ov011Fed *self) {
    u8 *a = self->unk_104;
    if (a != NULL) {
        func_ov003_021da48c(a, 0);
        ((Ov011V *)(a + 0x14))->v08();
        if (FLD(void *, a, 0x38) != NULL) {
            func_02065804(data_0214a420, FLD(void *, a, 0x38));
            FLD(void *, a, 0x38) = NULL;
        }
    }
    if (self->unk_108 != NULL) {
        Ov011Tw108 *q = self->unk_108;
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = 0x1000;
        q->unk_04 = 0x1000;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_100 != NULL) {
            u8 *b = self->unk_100;
            if (b != NULL) {
                Ov011B_Dtor(b);
                func_0203de1c(b);
            }
            self->unk_100 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_104 != NULL) {
            u8 *b = self->unk_104;
            if (b != NULL) {
                func_ov011_02202cac(b + 0x14);
                func_0203de1c(b);
            }
            self->unk_104 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_108 != NULL) {
            func_0203de1c(self->unk_108);
            self->unk_108 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_10c != NULL) {
            func_0203de1c(self->unk_10c);
            self->unk_10c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->b0 = 0;
    self->b1 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = data_ov011_02207258[8];
    self->unk_f8 = data_ov011_02207258[9];
    self->unk_fc = data_ov011_02207258[10];
    self->unk_100 = NULL;
    self->unk_104 = NULL;
    self->unk_108 = NULL;
    self->unk_10c = NULL;
}

}
