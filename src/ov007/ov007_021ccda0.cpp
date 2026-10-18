#include "ov007/ov007.h"

extern "C" {

#pragma force_active on
void func_ov007_021ccda0(void) {
    Ov007Scene *p = (Ov007Scene *)func_0203dd9c(0x6c);
    if (p != NULL) {
        func_ov007_021cce28(p);
    }
    data_ov007_021cfc60 = p;
}

void func_ov007_021ccdc8(void) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (data_ov007_021cfc60 != NULL) {
        Ov007Scene *p = data_ov007_021cfc60;
        if (p != NULL) {
            func_ov007_021ccec0(p);
            func_0203de1c(p);
        }
        data_ov007_021cfc60 = NULL;
    }
    data_02097dd0->cur = saved;
}

#pragma force_active reset

void func_ov007_021cce28(Ov007Scene *s) {
    s32 i;
    s->timer = 0;
    s->mode = 0;
    s->state = 1;
    s->sub = 0;
    s->idx = 0;
    s->unk_14 = NULL;
    s->unk_18 = NULL;
    s->unk_1c = NULL;
    s->unk_20 = NULL;
    s->unk_24 = NULL;
    s->unk_28 = NULL;
    s->unk_2c = NULL;
    s->unk_30 = NULL;
    s->unk_34 = NULL;
    s->unk_38 = NULL;
    s->unk_3c = NULL;
    s->unk_48 = NULL;
    s->unk_4c = 0;
    s->unk_4d = 0;
    s->unk_4e = 0;
    s->unk_4f = 0;
    s->unk_50 = 0;
    s->unk_54 = 0;
    s->unk_58 = 0;
    for (i = 0; i < 2; i++) {
        s->unk_5c[i] = NULL;
    }
    s->unk_64 = 0;
    s->unk_65 = 0x1f;
    s->unk_66 = 0;
    s->unk_68 = NULL;
}

void func_ov007_021ccec0(Ov007Scene *s) {
    OV007_FREE_V(s->unk_14, v04);
    OV007_FREE_V(s->unk_48, v04);
    OV007_FREE_V(s->unk_68, v04);
    func_ov007_021ccf9c(s);
}

void func_ov007_021ccf9c(Ov007Scene *s) {
    s32 i;
    u32 saved;
    s->unk_64 = 0;
    s->unk_4f = 0;
    OV007_FREE_D(s->unk_18, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_1c, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_20, func_ov000_0218ea20);
    OV007_FREE_D(s->unk_24, func_ov000_0218ea20);
    OV007_FREE_M(s->unk_28);
    OV007_FREE_M(s->unk_2c);
    OV007_FREE_D(s->unk_30, func_ov000_0218fee4);
    OV007_FREE_D(s->unk_34, func_ov000_0218fee4);
    OV007_FREE_D(s->unk_38, func_ov000_0218fee4);
    OV007_PUSH(saved); OV007_DEL_V(s->unk_3c, v08); OV007_POP(saved);
    for (i = 0; i < 2; i++) {
        OV007_PUSH(saved); OV007_DEL_V(s->unk_5c[i], v04); OV007_POP(saved);
    }
}

s32 func_ov007_021cd270(Ov007Scene *s) {
    Ov007V *p;
    s->timer += 0x1000;
    if (s->unk_68 != NULL) {
        if (s->unk_68->v1c() == 0) {
            OV007_FREE_V(s->unk_68, v04);
        } else if (s->unk_68->v0c() == 0) {
            return 1;
        }
    }
    switch (s->state) {
    case 1: {
        s32 m1 = -1;
        FLD(s32, data_02097d48, 0x9e4) = m1;
        func_0203c9e8(0x3f, m1);
        func_0203cc58(0, 1, m1);
        s->state = 2;
        s->sub = 0;
        s->idx = 0;
    }
    case 2:
        switch (s->sub) {
        case 0:
            p = (Ov007V *)func_0203dd9c(0x4c);
            if (p != NULL) {
                FLD(void *, p, 0) = &data_0208b318;
                p->v08();
            }
            s->unk_14 = p;
            FLD(s32, p, 0x44) = 7;
            s->unk_14->v20(data_ov007_021cfbd8);
            s->sub = 1;
            break;
        case 1:
            if (s->unk_14->v2c() != 0) {
                s->state = 3;
                s->sub = 0;
                s->idx = 0;
            }
            break;
        }
        break;
    case 3:
        func_ov007_021cd628(s);
        break;
    case 4:
        func_ov007_021cef80(s);
        break;
    case 5:
        func_ov007_021ce038(s);
        break;
    case 7:
        if (s->sub == 0 && func_ov000_02189068(data_ov000_021ccd54)) {
            if (s->unk_68 != NULL) {
                FLD(u32, s->unk_68, 0xc) |= 0x40000;
                break;
            }
            func_0203cb78(1, 0, 0);
            if (s->unk_68 == NULL) {
                p = (Ov007V *)func_0203dd9c(0xe8);
                if (p != NULL) {
                    FLD(void *, p, 0) = &data_ov000_021cac60;
                    p->v28();
                    FLD(void *, p, 0) = &data_ov000_021cad50;
                    p->v28();
                }
                s->unk_68 = p;
                FLD(u32, s->unk_68, 0xc) |= 0x10000;
                p = s->unk_68;
                FLD(u32, p, 0xc) |= 0x8;
                FLD(u16, p, 0x48) = 0x14a5;
                FLD(s32, p, 0x54) = 0x1c;
                FLD(u32, s->unk_68, 0xc) |= 0x20000;
                FLD(s32, s->unk_68, 0x1c) = 4;
                s->unk_68->v08();
                func_ov000_0215c1bc(s->unk_68, 0x8000, func_0204c0e8(data_02149ef8, 0x76));
                FLD(s16, s->unk_68, 0x68) = -0x299a;
                s->unk_68->v70();
            }
            s->sub = 1;
        }
        break;
    case 6:
        return 0;
    }
    return 1;
}

void func_ov007_021cd58c(void *task, Ov007Scene *s) {
    u32 b = FLD(Ov007Rank, FLD(void *, FLD(void *, task, 0x5c), 0x28), 0x24).rank;
    u8 lvl = b & ~0xc0;
    u8 fl = b & 0xc0;
    u8 a;
    u8 c;
    if (lvl > 20) {
        a = 3;
    } else if (lvl > 10) {
        a = 2;
    } else if (fl != 0 && lvl == 10) {
        a = 2;
    } else {
        a = 1;
    }
    if (lvl > 10 || (lvl == 10 && (fl & 0x40))) {
        c = 2;
    } else if (lvl > 0 || (lvl == 0 && (fl & 0x80))) {
        c = 1;
    } else {
        c = 0;
    }
    s->unk_4c = a;
    s->unk_4d = c;
}

}
