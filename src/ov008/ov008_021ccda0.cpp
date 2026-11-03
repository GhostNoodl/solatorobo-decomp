#include "ov008/ov008.h"


extern "C" {

extern void *data_02097e4c;
extern char data_ov008_021d0458[];
extern char data_ov008_021d0462[];
void MsgEntry_Init(void *p);
Ov008Def *Lang_GetGroup(u8 id);
void Tbl_Format_02070874(char *dst, const char *fmt, ...);
void *SndMgr_PlayVolume(void *a, int b, int c, int d, int e);

Ov008Item *Ov008Menu_AddItem(Ov008Menu *list, s32 a, s16 b, s16 c, s32 d) {
    Ov008Item *n = (Ov008Item *)Heap_Alloc(0x34);
    Ov008Item *p;
    if (n != NULL) {
        MsgEntry_Init(n);
        n->unk_30 = 0;
        n->unk_32 = 0;
    }
    n->unk_00 = a;
    n->serial = list->serial++;
    n->id = b;
    n->unk_08 = c;
    n->unk_0c = d;
    if (list->items == NULL) {
        list->items = n;
        list->topItem = n;
    } else {
        for (p = list->items; p->next != NULL; p = p->next) {
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
            if (o->next == 0xffff) {
                break;
            }
            o->state = 1;
        case 1: {
            u16 v = o->next;
            o->shown = v;
            o->next = 0xffff;
            Tbl_Format_02070874(buf, data_ov008_021d0458, Lang_GetGroup(v)->unk_04);
            o->pic.v0c();
            o->pic.unk_44 = 2;
            o->pic.v24(data_ov008_021d0462, buf);
            o->state = 2;
        }
        case 2:
            if (o->pic.v2c() != 0) {
                if (o->next != 0xffff) {
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
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, o->pic.cell, 1);
            STD_CopyString(m->name, o->pic.file);
        }
        o->sprite = m;
        TexObj_SetRes(o->sprite, (void *)o->pic.v10());
        o->sprite->flags |= 2;
        TexObj_SelectImage(o->sprite, 0, 0xffff);
        o->sprite->unk_150 = 0xfffe0333;
        o->sprite->flags |= 0x80000;
        o->unk_58 = 0;
        o->unk_5c = 0;
        o->offset = 0x20000;
        o->pic.v08();
        o->state = 0x10;
    case 0x10:
        t = FX_Div(0x24000 - o->offset, 0x20000);
        o->offset = o->offset + FX_Mul(-o->offset, 0x333);
        if (o->offset < 0x800 && o->unk_68 != 0) {
            o->speed = -0x400;
            o->state = 9;
        }
        break;
    case 0x11:
        SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
        o->state = 0x12;
    case 0x12:
        t = FX_Div(o->offset + 0x20000, 0x20000);
        o->offset = o->offset + FX_Mul(o->offset, 0x666);
        if (o->offset < -0x20000) {
            OV008_FREE_M(o->sprite);
            if (o->pic.v34() != 0) {
                o->state = 0xf;
            } else {
                o->state = 0;
            }
        }
        break;
    case 9:
        o->offset = o->offset + o->speed;
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
    o->alpha = FX_Mul(t, 0x1f000) >> 12;
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
