#include "Main/Lang/LangData.h"

extern "C" {

typedef struct ParamOfs {
    /* 0x0 */ u32 offset;
    /* 0x4 */ u32 offset2;
} ParamOfs;

extern ParamOfs *data_0214b12c[];
extern u8 *data_0208d268[];

static inline u16 Param_Cat(u32 id) {
    return id >> 12;
}

static inline u16 Param_Idx(u32 id) {
    return id & 0xfff;
}

void *func_0206ec48(u32 id) {
    ParamOfs *ofs = &data_0214b12c[Param_Cat(id) - 1][Param_Idx(id)];
    return ofs->offset != 0 ? (u8 *)ofs + ofs->offset : NULL;
}

void *func_0206ec8c(u32 id) {
    ParamOfs *ofs = &data_0214b12c[Param_Cat(id) - 1][Param_Idx(id)];
    return ofs->offset != 0 ? (u8 *)ofs + ofs->offset2 : NULL;
}

static inline void *Param_GetStr(u32 id) {
    ParamOfs *ofs = &data_0214b12c[Param_Cat(id) - 1][Param_Idx(id)];
    return ofs->offset != 0 ? (u8 *)ofs + ofs->offset2 : NULL;
}

typedef struct ParamItem {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 kind;
    /* 0x2 */ u8 num;
    /* 0x3 */ u8 unk_3[0xd];
} ParamItem;

char *func_02040ab0(char *str, int c);
void func_02040a98(char *dst, int num);

void func_0206ecd4(void *self, char *dst, u32 id) {
    char num[0x10];
    char buf[0x100];
    const char *str = (const char *)Param_GetStr(id);
    int cat = Param_Cat(id) - 1;
    if (cat == 1) {
        ParamItem *item = &((ParamItem *)data_0208d268[(u16)cat])[Param_Idx(id)];
        char *q;
        func_0201e520(buf, str);
        dst[0] = 0;
        q = func_02040ab0(buf, '?');
        if (q != NULL) {
            *q = 0;
            func_02040a98(num, item->num);
            if (q[1] == '?') {
                q++;
            }
            func_0201e520(dst, buf);
            func_0201e78c(dst, num);
            func_0201e78c(dst, q + 1);
        }
        if (dst[0] == 0) {
            func_0201e520(dst, str);
        }
    } else {
        func_0201e520(dst, str);
    }
}

void *func_0206ede8(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x10;
}

void *func_0206ee20(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 4;
}

void *func_0206ee58(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 4;
}

void *func_0206ee90(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x14;
}

void *func_0206eed0(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x14;
}

void *func_0206ef10(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x2c;
}

void *func_0206ef50(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 2;
}

void *func_0206ef88(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 8;
}

void *func_0206efc0(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x14;
}

void *func_0206f000(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 6;
}

void *func_0206f040(u32 id) {
    return data_0208d268[(u16)(Param_Cat(id) - 1)] + Param_Idx(id) * 0x12;
}

typedef struct ParamKind {
    /* 0x0 */ u8 unk_0[4];
    /* 0x4 */ u16 value : 8;
    /* 0x4 */ u16 unk_4_8 : 8;
} ParamKind;

ParamKind *func_02070dcc(int kind);

u16 func_0206f080(u32 id) {
    u16 ret = 0xffff;
    switch (Param_Cat(id) - 1) {
    case 0:
    case 11:
        ret = 0x25;
        break;
    case 1:
        ret = func_02070dcc(((ParamItem *)data_0208d268[(u16)(Param_Cat(id) - 1)])[Param_Idx(id)].kind)->value;
        break;
    }
    return ret;
}

typedef struct ParamE0 {
    u16 unk_0;
    u16 value;
} ParamE0;

typedef struct ParamE1 {
    u32 unk_0;
    u32 value;
    u8 unk_8[8];
} ParamE1;

typedef struct ParamE4 {
    u16 value : 15;
    u16 unk_0_15 : 1;
    u8 unk_2[0x12];
} ParamE4;

typedef struct ParamE7 {
    u32 unk_0[2];
    u32 value;
    u8 unk_c[0x20];
} ParamE7;

u32 func_0206f0f4(u32 id) {
    u16 cat = Param_Cat(id);
    switch (cat - 1) {
    case 0:
        return ((ParamE0 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    case 1:
        return ((ParamE1 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    case 2:
        return ((ParamE0 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    case 3:
        return ((ParamE0 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    case 4:
        return ((ParamE4 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    case 7:
        return ((ParamE7 *)data_0208d268[(u16)(cat - 1)])[Param_Idx(id)].value;
    }
    return 0;
}

}
