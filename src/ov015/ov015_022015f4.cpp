#include "ov015/ov015.h"

extern "C" {

extern char data_ov015_022128c1[];
s32 func_02035b90(void *a, int b);
extern Ov015Shared *data_ov015_02213368;
extern Ov015Globals data_ov015_02213320;
extern u8 data_ov015_0221291c[];
extern u8 data_ov015_02213198[];
extern u8 data_ov015_0221290c[];
extern u8 data_ov015_0221295c[];
void func_0204b370(void *p);
u8 *func_02070744(u16 id);
void func_ov015_021fce94(Ov015CamPair *self);
void func_ov015_02210b3c(u8 *self);
s32 func_ov015_02211160(u8 *self, u16 *out, u32 n);
void func_ov015_02211890(u8 *self, u16 id, s32 mode);
void func_ov015_02209024(u8 *self, u16 a, const void *src);
void *func_ov015_02209114(u8 *self);
void func_ov015_02209364(u8 *self);

BOOL func_ov015_022015f4(void) {
    return func_02035b90(data_ov015_022128c1, 7) != 0 ? TRUE : FALSE;
}

BOOL func_ov015_02201618(u8 *self) {
    u16 ids[4];
    u8 *o;
    Ov015List *l;
    u32 n;
    u32 i;
    o = (u8 *)func_0203dd9c(0x1a0);
    if (o != NULL) {
        SET_VT(o, data_ov015_0221291c);
        func_0204b370(o + 0x4);
        func_0204b370(o + 0xc0);
        FLD(s32, o, 0x17c) = 1;
        FLD(s32, o, 0x180) = 0;
        FLD(s32, o, 0x184) = 0;
        FLD(s32, o, 0x188) = 0;
        FLD(s32, o, 0x18c) = 0;
        FLD(s32, o, 0x190) = 0;
        FLD(s32, o, 0x194) = 0;
        FLD(s32, o, 0x198) = 0;
        FLD(s32, o, 0x19c) = 0;
    }
    FLD(u8 *, self, 0x24) = o;
    func_ov015_021fce94((Ov015CamPair *)o);
    if ((u32)(FLD(s32, data_ov015_02213320.unk_00, 0x4) - 1) <= 1) {
        u8 *p = (u8 *)func_0203dd9c(0x14);
        if (p != NULL) {
            SET_VT(p, data_ov015_02213198);
            func_ov015_02210b3c(p);
        }
        FLD(u8 *, self, 0x90) = p;
    }
    l = (Ov015List *)func_0203dd9c(0x10);
    if (l != NULL) {
        SET_VT(l, data_ov015_0221290c);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    FLD(Ov015List *, self, 0x1c) = l;
    n = func_ov015_02211160((u8 *)data_ov015_02213368, ids, 3);
    func_ov015_02211890(self + 0x94, FLD(u16, data_ov015_02213368, 0x8), FLD(u16, FLD(u8 *, self, 0x18), 0xd48));
    for (i = 0; i < n; i++) {
        u16 id = ids[i];
        u8 *def = func_02070744(id);
        u8 *e = (u8 *)func_0203dd9c(0x5b0);
        Ov015List *L;
        Ov015Node *nd;
        if (e != NULL) e = (u8 *)func_ov015_02209114(e);
        FLD(u16, e, 0x4) = id;
        func_ov015_02209024(e + 0xc0, FLD(u16, e, 0x4), def);
        FLD(s32, e, 0xe0) = FLD(s32, self, 0xb4);
        FLD(s32, e, 0xe4) = FLD(s32, self, 0xb8);
        func_ov015_02209364(e);
        L = FLD(Ov015List *, self, 0x1c);
        nd = (Ov015Node *)func_0203dd9c(0x10);
        if (nd != NULL) {
            SET_VT(nd, data_ov015_0221295c);
            nd->key = (s32)e;
            nd->prev = NULL;
            nd->next = NULL;
        }
        if (L->head == NULL) {
            L->head = nd;
            L->tail = nd;
        } else {
            L->head->prev = nd;
            nd->next = L->head;
            L->head = nd;
        }
        L->count++;
    }
    FLD(s32, self, 0xc) = 10;
    {
        Ov015Pad *pad = data_02097e48;
        if (pad->b3) {
            pad->unk_06 = 0x8000;
            pad->unk_08 = 0x1e;
            pad->unk_02 = 0;
        }
    }
    return TRUE;
}

}
