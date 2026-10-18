#include "ov007/ov007.h"

extern "C" {

void func_ov007_021cd628(Ov007Scene *s) {
    u32 saved;
    Ov007V *p;
    void *m;
    s32 res;
    if (s->unk_48 != NULL) {
        s->unk_48->v0c();
        if (Ov007_Flag2(s->unk_48)) {
            OV007_FREE_V(s->unk_48, v04);
            s->state = 7;
            s->sub = 0;
            s->idx = 0;
            return;
        }
    }
    switch (s->sub) {
    case 1:
        if (!Ov007_FadeIdle() && !Ov007_FadeDone()) {
            return;
        }
        Ov007_FreePage(s);
        ++s->idx;
        s->sub = 2;
        return;
    case 0:
        if (s->mode == 0) {
            s->idx = 0;
            s->unk_4e = 0;
        } else if (s->mode == 1 || s->mode == 2) {
            s->unk_4d = 0;
            s->idx = 3;
        }
    case 2:
        p = (Ov007V *)s->unk_14->v10();
        if (s->idx >= 3) {
            if (s->idx == 3) {
                s->sub = 8;
                return;
            }
            if (s->idx == 4) {
                if (OS_IsRunOnTwl()) {
                    s->sub = 0xb;
                } else {
                    s->idx++;
                }
                return;
            }
            func_0203cc58(0, 1, -1);
            if (s->unk_4d == 0 || (s->mode == 1 || s->mode == 2)) {
                s->state = 5;
                s->sub = 0;
                s->idx = 0;
                return;
            }
            s->state = 4;
            s->sub = 0;
            s->idx = 0;
            return;
        }
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            res = data_ov007_021cfa50[s->idx].v;
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, res, 0);
        }
        s->unk_28 = m;
        func_020417e0(s->unk_28, func_02034d88(p, (u8 *)m + 0x4c));
        FLD(u32, s->unk_28, 0x6c) |= 2;
        func_02041d9c(s->unk_28, 2, 0xffff);
        if (data_ov007_021cfa54[s->idx].v != 0) {
            m = func_0203dd9c(0x160);
            if (m != NULL) {
                res = data_ov007_021cfa54[s->idx].v;
                func_02041218((u8 *)m + 0x88);
                func_02041440(m, res, 0);
            }
            s->unk_2c = m;
            func_020417e0(s->unk_2c, func_02034d88(p, (u8 *)m + 0x4c));
            FLD(u32, s->unk_2c, 0x6c) |= 2;
            func_02041d9c(s->unk_2c, 0, 0xffff);
        }
        s->sub = 3;
        return;
    case 3:
        if (s->unk_28 != NULL && !func_02054f10(s->unk_28, 0xffff)) {
            return;
        }
        if (s->unk_2c != NULL && !func_02054f10(s->unk_2c, 0xffff)) {
            return;
        }
        if (s->unk_4e == 0) {
            func_0203cb78(data_ov007_021cfa58[s->idx].v, 0, -1);
        } else {
            func_0203cb78(0, 0, -1);
        }
        s->unk_4e = 0;
        s->sub = 4;
        return;
    case 4:
        if (!Ov007_FadeIdle()) {
            if (data_ov007_021cfa64[s->idx].v != 1) {
                return;
            }
            if (!(data_02097dc8->trg & 1)) {
                return;
            }
            func_0203cb78(0, 0, -1);
            return;
        }
        s->timer = 0;
        s->sub = 5;
        return;
    case 5: {
        u8 kind = data_ov007_021cfa64[s->idx].v;
        if (kind != 0 && (data_02097dc8->trg & 1)) {
            if (s->timer < 0xf000) {
                return;
            }
            s->unk_4e = 1;
            if (kind == 1) {
                func_0203cc58(0, 1, -1);
                s->timer = 0;
                s->sub = 1;
                return;
            }
            func_0203cc58(data_ov007_021cfa60[s->idx].v, 1, -1);
            s->timer = 0;
            s->sub = 6;
            return;
        }
        if (s->timer < data_ov007_021cfa5c[s->idx].v) {
            return;
        }
        func_0203cc58(data_ov007_021cfa60[s->idx].v, 1, -1);
        s->sub = 6;
        return;
    }
    case 6:
        if (!Ov007_FadeIdle() && !Ov007_FadeDone()) {
            u8 kind = data_ov007_021cfa64[s->idx].v;
            if (kind == 0) {
                return;
            }
            if (!(data_02097dc8->trg & 1)) {
                return;
            }
            if (kind == 1) {
                func_0203cc58(0, 1, -1);
            }
            s->unk_4e = 1;
            return;
        }
        s->timer = 0;
        s->sub = 7;
        return;
    case 7:
        if (s->timer < 0x1e000 && s->unk_4e == 0) {
            if (!(data_02097dc8->trg & 1)) {
                return;
            }
            s->unk_4e = 1;
        }
        s->timer = 0;
        s->sub = 1;
        return;
    case 8:
        if (!func_ov000_02189068(data_ov000_021ccd54)) {
            return;
        }
        func_0203cb78(1, 0, 0);
        func_ov000_02180660(8, 3);
        s->sub = 9;
        return;
    case 9:
        p = (Ov007V *)func_ov000_02173610(8);
        if (p != NULL) {
            FLD(void *, p, 0xbc) = (void *)func_ov007_021cd58c;
            FLD(void *, p, 0xc0) = s;
            s->sub = 10;
            FLD(u8, data_02097dd0, 0x31) = 1;
        }
    case 10:
        FLD(u8, data_02097dd0, 0x1f) = 1;
        if (!Ov007_MenuDone()) {
            return;
        }
        func_ov000_02180754();
        s->sub = 1;
        FLD(u8, data_02097dd0, 0x31) = 0;
        return;
    case 11:
        s->timer = 0;
        p = (Ov007V *)func_0203dd9c(0x58);
        if (p != NULL) {
            FLD(void *, p, 0) = &data_0208b614;
            p->v14();
            FLD(void *, p, 0) = &data_0208ca9c;
            p->v14();
            FLD(void *, p, 0) = &data_0208c994;
            p->v14();
        }
        s->unk_48 = p;
        p->v08();
        FLD(Ov007Flags44, s->unk_48, 0x48).b0 = 1;
        s->sub = 12;
    case 12:
        p = s->unk_48;
        if (!Ov007_Flag7(p)) {
            return;
        }
        if (!Ov007_Closed(p)) {
            FLD(Ov007Flags44, p, 0x48).b3 = 1;
            if (s->unk_68 == NULL) {
                Ov007_NewPlayer(s, 0x6e);
            }
            func_0203cb78(1, 0, 0);
            s->sub = 0xf;
            FLD(u8, data_02097dd0, 0x31) = 1;
            FLD(u8, data_02097dd0, 0x1f) = 1;
        } else {
            s->sub = 1;
        }
        return;
    case 15:
        FLD(u8, data_02097dd0, 0x1f) = 1;
        if (Ov007_Flag3(s->unk_48)) {
            return;
        }
    case 16:
        if (s->unk_68 != NULL) {
            FLD(u8, data_02097dd0, 0x1f) = 1;
            if (Ov007_Busy(s->unk_68)) {
                return;
            }
            if (s->timer >= 0x78000) {
                FLD(u32, s->unk_68, 0xc) |= 0x40000;
            }
            return;
        }
        s->sub = 1;
        FLD(u8, data_02097dd0, 0x31) = 0;
        return;
    }
}

}
