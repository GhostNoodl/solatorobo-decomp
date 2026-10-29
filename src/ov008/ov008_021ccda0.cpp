#include "ov008/ov008.h"

struct Ov008Node {
    s32 unk_00;
    s16 id;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0a[0x2];
    s32 unk_0c;
    u8 unk_10[0x18];
    Ov008Node *prev;
    Ov008Node *next;
    s16 unk_30;
    s16 unk_32;
};

struct Ov008List {
    u8 unk_00[0x94];
    Ov008Node *head;
    Ov008Node *tail;
    s16 nextId;
};

extern "C" {

extern void *data_02097e4c;
extern char data_ov008_021d0458[];
extern char data_ov008_021d0462[];
void func_ov000_02153f90(void *p);
void *func_0206e7d0(u8 id);
void func_02070874(char *dst, const char *fmt, ...);
void *func_02049a48(void *a, int b, int c, int d, int e);
void func_02041440(void *p, void *name, int c);
void *STD_CopyString(void *dst, const void *src);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
s32 FX_Div(s32 a, s32 b);

Ov008Node *func_ov008_021ccda0(Ov008List *list, s32 a, s16 b, s16 c, s32 d) {
    Ov008Node *n = (Ov008Node *)func_0203dd9c(0x34);
    Ov008Node *p;
    if (n != NULL) {
        func_ov000_02153f90(n);
        n->unk_30 = 0;
        n->unk_32 = 0;
    }
    n->unk_00 = a;
    n->id = list->nextId++;
    n->unk_06 = b;
    n->unk_08 = c;
    n->unk_0c = d;
    if (list->head == NULL) {
        list->head = n;
        list->tail = n;
    } else {
        for (p = list->head; p->next != NULL; p = p->next) {
        }
        p->next = n;
        n->prev = p;
    }
    return n;
}

void func_ov008_021cce38(void *o) {
    char buf[0x20];
    BOOL again;
    do {
        again = FALSE;
        switch (FLD(s32, o, 0)) {
        case 0:
            if (FLD(u16, o, 0x50) == 0xffff) {
                break;
            }
            FLD(s32, o, 0) = 1;
        case 1: {
            u16 v = FLD(u16, o, 0x50);
            FLD(u16, o, 0x52) = v;
            FLD(u16, o, 0x50) = 0xffff;
            func_02070874(buf, data_ov008_021d0458, FLD(void *, func_0206e7d0(v), 0x4));
            VOBJ(o, 4)->v0c();
            FLD(s32, o, 0x48) = 2;
            VOBJ(o, 4)->v24(data_ov008_021d0462, buf);
            FLD(s32, o, 0) = 2;
        }
        case 2:
            if (VOBJ(o, 4)->v2c() != 0) {
                if (FLD(u16, o, 0x50) != 0xffff) {
                    again = TRUE;
                    FLD(s32, o, 0) = again;
                } else {
                    VOBJ(o, 4)->v30();
                    FLD(s32, o, 0) = 0;
                }
            }
            break;
        }
    } while (again);
}

void func_ov008_021ccf44(void *o) {
    s32 t = 0;
    void *m;
    switch (FLD(s32, o, 0)) {
    case 0:
        if (VOBJ(o, 4)->v34() != 0) {
            FLD(s32, o, 0) = 0xf;
        }
        break;
    case 0xf:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, (u8 *)o + 0x28, 1);
            STD_CopyString((u8 *)m + 0x2c, (u8 *)o + 0x8);
        }
        FLD(void *, o, 0x50) = m;
        func_020417e0(FLD(void *, o, 0x50), (void *)VOBJ(o, 4)->v10());
        FLD(u32, FLD(void *, o, 0x50), 0x6c) |= 2;
        func_02041d9c(FLD(void *, o, 0x50), 0, 0xffff);
        FLD(s32, FLD(void *, o, 0x50), 0x150) = 0xfffe0333;
        FLD(u32, FLD(void *, o, 0x50), 0x6c) |= 0x80000;
        FLD(s32, o, 0x58) = 0;
        FLD(s32, o, 0x5c) = 0;
        FLD(s32, o, 0x54) = 0x20000;
        VOBJ(o, 4)->v08();
        FLD(s32, o, 0) = 0x10;
    case 0x10:
        t = FX_Div(0x24000 - FLD(s32, o, 0x54), 0x20000);
        FLD(s32, o, 0x54) = FLD(s32, o, 0x54) + Ov008_FxMul(-FLD(s32, o, 0x54), 0x333);
        if (FLD(s32, o, 0x54) < 0x800 && FLD(u8, o, 0x68) != 0) {
            FLD(s32, o, 0x64) = -0x400;
            FLD(s32, o, 0) = 9;
        }
        break;
    case 0x11:
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        FLD(s32, o, 0) = 0x12;
    case 0x12:
        t = FX_Div(FLD(s32, o, 0x54) + 0x20000, 0x20000);
        FLD(s32, o, 0x54) = FLD(s32, o, 0x54) + Ov008_FxMul(FLD(s32, o, 0x54), 0x666);
        if (FLD(s32, o, 0x54) < -0x20000) {
            OV008_FREE_M(FLD(void *, o, 0x50));
            if (VOBJ(o, 4)->v34() != 0) {
                FLD(s32, o, 0) = 0xf;
            } else {
                FLD(s32, o, 0) = 0;
            }
        }
        break;
    case 9:
        FLD(s32, o, 0x54) = FLD(s32, o, 0x54) + FLD(s32, o, 0x64);
        t = 0x1000;
        break;
    case 8:
        t = 0x1000;
        break;
    }
    if (t >= 0x1000) {
        t = 0x1000;
    } else if (t < 0) {
        t = 0;
    }
    FLD(s32, o, 0x60) = Ov008_FxMul(t, 0x1f000) >> 12;
}

}

struct Ov008Glyph {
    u32 c : 8;
    u32 unk_08 : 8;
    u32 y : 9;
    u32 unk_19 : 7;
    u32 x : 10;
    u32 unk_2a : 22;
};

struct Ov008Cmd {
    u16 type;
    u8 unk_02[0x6];
    u32 val;
};

extern "C" {

}
