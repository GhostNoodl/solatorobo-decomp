#include "ov008/ov008.h"


extern "C" {

extern void *data_02097e4c;
extern char data_ov008_021d0458[];
extern char data_ov008_021d0462[];
void func_ov000_02153f90(void *p);
Ov008Def *func_0206e7d0(u8 id);
void func_02070874(char *dst, const char *fmt, ...);
void *func_02049a48(void *a, int b, int c, int d, int e);

Ov008Item *func_ov008_021ccda0(Ov008Menu *list, s32 a, s16 b, s16 c, s32 d) {
    Ov008Item *n = (Ov008Item *)Heap_Alloc(0x34);
    Ov008Item *p;
    if (n != NULL) {
        func_ov000_02153f90(n);
        n->unk_30 = 0;
        n->unk_32 = 0;
    }
    n->unk_00 = a;
    n->unk_04 = list->unk_9c++;
    n->id = b;
    n->unk_08 = c;
    n->unk_0c = d;
    if (list->unk_94 == NULL) {
        list->unk_94 = n;
        list->unk_98 = n;
    } else {
        for (p = list->unk_94; p->next != NULL; p = p->next) {
        }
        p->next = n;
        n->prev = p;
    }
    return n;
}

void func_ov008_021cce38(Ov008Caption *o) {
    char buf[0x20];
    BOOL again;
    do {
        again = FALSE;
        switch (o->state) {
        case 0:
            if (o->unk_50 == 0xffff) {
                break;
            }
            o->state = 1;
        case 1: {
            u16 v = o->unk_50;
            o->unk_52 = v;
            o->unk_50 = 0xffff;
            func_02070874(buf, data_ov008_021d0458, func_0206e7d0(v)->unk_04);
            o->pic.v0c();
            o->pic.unk_44 = 2;
            o->pic.v24(data_ov008_021d0462, buf);
            o->state = 2;
        }
        case 2:
            if (o->pic.v2c() != 0) {
                if (o->unk_50 != 0xffff) {
                    again = TRUE;
                    o->state = again;
                } else {
                    o->pic.v30();
                    o->state = 0;
                }
            }
            break;
        }
    } while (again);
}

void func_ov008_021ccf44(Ov008Panel *o) {
    s32 t = 0;
    Model *m;
    switch (o->state) {
    case 0:
        if (o->pic.v34() != 0) {
            o->state = 0xf;
        }
        break;
    case 0xf:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        m = (Model *)Heap_Alloc(0x160);
        if (m != NULL) {
            func_02041218(&m->pltt);
            func_02041440(m, o->pic.unk_24, 1);
            STD_CopyString(m->name, o->pic.unk_04);
        }
        o->unk_50 = m;
        func_020417e0(o->unk_50, (void *)o->pic.v10());
        o->unk_50->flags |= 2;
        func_02041d9c(o->unk_50, 0, 0xffff);
        o->unk_50->unk_150 = 0xfffe0333;
        o->unk_50->flags |= 0x80000;
        o->unk_58 = 0;
        o->unk_5c = 0;
        o->unk_54 = 0x20000;
        o->pic.v08();
        o->state = 0x10;
    case 0x10:
        t = FX_Div(0x24000 - o->unk_54, 0x20000);
        o->unk_54 = o->unk_54 + FX_Mul(-o->unk_54, 0x333);
        if (o->unk_54 < 0x800 && o->unk_68 != 0) {
            o->unk_64 = -0x400;
            o->state = 9;
        }
        break;
    case 0x11:
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        o->state = 0x12;
    case 0x12:
        t = FX_Div(o->unk_54 + 0x20000, 0x20000);
        o->unk_54 = o->unk_54 + FX_Mul(o->unk_54, 0x666);
        if (o->unk_54 < -0x20000) {
            OV008_FREE_M(o->unk_50);
            if (o->pic.v34() != 0) {
                o->state = 0xf;
            } else {
                o->state = 0;
            }
        }
        break;
    case 9:
        o->unk_54 = o->unk_54 + o->unk_64;
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
    o->unk_60 = FX_Mul(t, 0x1f000) >> 12;
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
