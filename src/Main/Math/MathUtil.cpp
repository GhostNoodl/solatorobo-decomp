#include "types.h"

extern "C" {

typedef struct RandContext {
    /* 0x00 */ u64 x;
    /* 0x08 */ u64 mul;
    /* 0x10 */ u64 add;
} RandContext;

RandContext data_02097de8;

static inline void Rand_Init(RandContext *ctx, u64 seed) {
    ctx->x = seed;
    ctx->mul = 0x5d588b656c078965ULL;
    ctx->add = 0x269ec3;
}

static inline u32 Rand_Next(RandContext *ctx, u32 max) {
    ctx->x = ctx->mul * ctx->x + ctx->add;
    if (max == 0) {
        return (u32)(ctx->x >> 32);
    }
    return (u32)(((ctx->x >> 32) * max) >> 32);
}

void func_020403e4(u64 seed) {
    Rand_Init(&data_02097de8, seed);
}

u32 func_02040420(void) {
    return Rand_Next(&data_02097de8, 0);
}

u32 func_0204045c(void) {
    return Rand_Next(&data_02097de8, 0);
}

u32 func_02040498(u32 max) {
    return Rand_Next(&data_02097de8, max + 1);
}

u32 func_020404e0(void) {
    return Rand_Next(&data_02097de8, 0x1001);
}

int func_02040528(int range) {
    return (int)Rand_Next(&data_02097de8, range * 2 + 1) - range;
}


typedef struct MathVec {
    int x;
    int y;
    int z;
} MathVec;

typedef struct MathMtx43 {
    int m[4][3];
} MathMtx43;

typedef struct MathMtx44 {
    int m[4][4];
} MathMtx44;

extern s16 FX_SinCosTable_[];
extern MathMtx43 data_02092844;
extern MathMtx44 data_02092800;

extern void MTX_Identity43_(MathMtx43 *mtx);
extern int FX_Atan2(int y, int x);
extern void MTX_RotY43_(MathMtx43 *mtx, int sin, int cos);
extern void MTX_MultVec43(const MathVec *v, const MathMtx43 *mtx, MathVec *out);
extern void MTX_Copy44To43_(const MathMtx44 *src, MathMtx43 *dst);
extern int FX_Div(int numer, int denom);

static inline int Math_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

static inline void MathVec_Copy(const MathVec *src, MathVec *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void func_02040578(u16 *ang, const MathVec *v) {
    MathVec p;
    MathMtx43 mtx;
    MTX_Identity43_(&mtx);
    ((volatile MathVec *)&p)->x = ((volatile MathVec *)v)->x;
    ((volatile MathVec *)&p)->y = ((volatile MathVec *)v)->y;
    ((volatile MathVec *)&p)->z = ((volatile MathVec *)v)->z;
    ang[1] = -FX_Atan2(p.x, p.z);
    MTX_RotY43_(&mtx, FX_SinCosTable_[(ang[1] >> 4) * 2], FX_SinCosTable_[(ang[1] >> 4) * 2 + 1]);
    MTX_MultVec43(&p, &mtx, &p);
    ang[0] = -FX_Atan2(p.y, p.z);
    ang[2] = 0;
}

int func_0204061c(int *out, const MathVec *pos) {
    MathVec p;
    MathMtx43 mtx;
    int z;
    int w;
    int inv;
    MTX_MultVec43(pos, &data_02092844, &p);
    z = p.z;
    w = Math_Mul(z, -0x1000);
    MTX_Copy44To43_(&data_02092800, &mtx);
    MTX_MultVec43(&p, &mtx, &p);
    p.x += w;
    p.y += w;
    p.z += w;
    inv = FX_Div(0x1000, w * 2);
    p.x = Math_Mul(p.x, inv);
    p.y = Math_Mul(p.y, inv);
    p.z = Math_Mul(p.z, inv);
    out[0] = Math_Mul(p.x, 0x100000) >> 12;
    out[1] = 0xc0 - (Math_Mul(p.y, 0xc0000) >> 12);
    return z;
}


extern u32 STD_GetStringLength(const char *str);

u32 func_02040778(char *str, int *outLen) {
    char buf[0x10];
    int len = 0;
    char *dst = buf;
    char *p;
    u32 n;
    int shift;
    u32 value;
    int digit;
    while (*str != 0 && *str != '>' && *str != ',') {
        *dst++ = *str++;
        len++;
    }
    *dst = 0;
    p = buf + 2;
    if (str[1] != 'x') {
        p = buf;
    }
    n = STD_GetStringLength(p);
    shift = 0;
    value = 0;
    for (; n != 0; n--) {
        switch (p[n - 1]) {
        case '0':
            digit = 0;
            break;
        case '1':
            digit = 1;
            break;
        case '2':
            digit = 2;
            break;
        case '3':
            digit = 3;
            break;
        case '4':
            digit = 4;
            break;
        case '5':
            digit = 5;
            break;
        case '6':
            digit = 6;
            break;
        case '7':
            digit = 7;
            break;
        case '8':
            digit = 8;
            break;
        case '9':
            digit = 9;
            break;
        case 'a':
        case 'A':
            digit = 10;
            break;
        case 'b':
        case 'B':
            digit = 11;
            break;
        case 'c':
        case 'C':
            digit = 12;
            break;
        case 'd':
        case 'D':
            digit = 13;
            break;
        case 'e':
        case 'E':
            digit = 14;
            break;
        case 'f':
        case 'F':
            digit = 15;
            break;
        default:
            digit = 0;
            n = 0;
            break;
        }
        value |= digit << shift;
        shift += 4;
    }
    if (outLen != NULL) {
        *outLen = len;
    }
    return value;
}


void func_02040968(char *dst, int *dstLen, const u8 *src, int *srcLen) {
    int i;
    int out;
    int n;
    int maxDst;
    int maxSrc;
    int j;
    u32 c;
    char tmp[4];
    i = 0;
    out = 0;
    if (srcLen == NULL || (maxSrc = *srcLen) < 0) {
        maxSrc = 0x7fffffff;
    }
    if (dst == NULL || dstLen == NULL || (maxDst = *dstLen) < 0) {
        maxDst = 0x7fffffff;
    }
    while (out < maxDst && i < maxSrc) {
        c = (u16)(src[i * 2] | (src[i * 2 + 1] << 8));
        n = 0;
        if (c == 0) {
            break;
        }
        if (c < 0x80) {
            tmp[0] = c & 0x7f;
            n = 1;
        } else if (c < 0x800) {
            tmp[0] = ((c & 0x7c0) >> 6) | 0xc0;
            tmp[1] = (c & 0x3f) | 0x80;
            n = 2;
        } else if (c < 0x10000) {
            tmp[0] = ((c & 0xf000) >> 12) | 0xe0;
            tmp[1] = ((c & 0xfc0) >> 6) | 0x80;
            tmp[2] = (c & 0x3f) | 0x80;
            n = 3;
        }
        if (dst != NULL) {
            for (j = 0; j < n; j++) {
                dst[(u32)(out + j)] = tmp[j];
            }
            i++;
            out += n;
        }
    }
    if (dstLen != NULL) {
        *dstLen = out;
    }
}

extern void func_0200779c(void *a, void *b, void *c);
extern u8 data_0208b3cc[];

void func_02040a98(void *a, void *b) {
    func_0200779c(a, data_0208b3cc, b);
}

char *func_02040ab0(char *str, int ch) {
    int len = STD_GetStringLength(str);
    int i;
    for (i = 0; i < len; i++) {
        if (!(str[i] & 0x80)) {
            if (ch == str[i]) {
                return str + i;
            }
        } else if ((str[i] & 0xe0) == 0xc0) {
            i += 1;
        } else {
            i += 2;
        }
    }
    return NULL;
}


int func_02040b6c(u16 *dst, int max, const u16 *src, int n);

void func_02040b0c(char *dst, int *dstLen, const u16 *src, int *srcLen) {
    int len;
    int out;
    u16 buf[0x40];
    len = 0x40;
    len = func_02040b6c(buf, len, src, *srcLen);
    out = *dstLen - 1;
    func_02040968(dst, &out, (const u8 *)buf, &len);
    dst[out] = 0;
}

int func_02040b6c(u16 *dst, int max, const u16 *src, int n) {
    int out = 0;
    int i = 0;
    while (i < n && out + 1 < max) {
        u16 c = src[i++];
        if (c >= 0xe000 && c < 0xe030) {
            c = '?';
        }
        if (c == 0) {
            break;
        }
        dst[out++] = c;
    }
    dst[out] = 0;
    return out;
}

}
