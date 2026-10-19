#include "types.h"
#pragma unsigned_char on
#pragma dont_reuse_strings off
typedef struct decimal { char sign; char unused; short exp; struct { unsigned char length; unsigned char text[32]; unsigned char unused; } sig; } decimal;

int __must_round(const decimal *d, int digits) {
    unsigned char const *i = d->sig.text + digits;
    if (*i > 5)
        return 1;
    if (*i < 5)
        return -1;
    {
        unsigned char const *e = d->sig.text + d->sig.length;
        for (++i; i < e; ++i)
            if (*i != 0)
                return 1;
    }
    if (d->sig.text[digits - 1] & 1)
        return 1;
    return -1;
}

void __dorounddecup(decimal *d, int digits) {
    unsigned char *b = d->sig.text;
    unsigned char *i = b + digits - 1;
    while (1) {
        if (*i < 9) {
            (*i)++;
            break;
        }
        if (i == b) {
            *i = 1;
            d->exp++;
            break;
        }
        *i-- = 0;
    }
}


void __rounddec(decimal *d, int digits) {
    int r;
    if (digits <= 0 || digits >= d->sig.length)
        return;
    r = __must_round(d, digits);
    d->sig.length = (unsigned char)digits;
    if (r < 0)
        return;
    __dorounddecup(d, digits);
}

void __ull2dec(decimal *result, unsigned long long integer) {
    result->sign = 0;
    result->sig.length = 0;
    for (; integer != 0; integer /= 10)
        result->sig.text[result->sig.length++] = (unsigned char)(integer % 10);
    {
        unsigned char *i = result->sig.text;
        unsigned char *j = result->sig.text + result->sig.length;
        for (; i < --j; ++i) {
            unsigned char t = *i;
            *i = *j;
            *j = t;
        }
    }
    result->exp = (short)(result->sig.length - 1);
}

#define SIGDIGLEN 32
void __timesdec(decimal *result, const decimal *x, const decimal *y) {
    unsigned long accumulator = 0;
    unsigned char mantissa[2 * SIGDIGLEN];
    int i = x->sig.length + y->sig.length - 1;
    unsigned char *ip = mantissa + i + 1;
    unsigned char *ep = ip;
    result->sign = 0;
    for (; i > 0; --i) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        unsigned char const *jp;
        unsigned char const *kp;
        if (j < 0) {
            j = 0;
            k = i - 1;
        }
        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;
        if (l > t)
            l = t;
        for (; l > 0; --l, ++jp, --kp)
            accumulator += (unsigned long)(*jp) * *kp;
        *--ip = (unsigned char)(accumulator % 10);
        accumulator /= 10;
    }
    result->exp = (short)(x->exp + y->exp);
    if (accumulator > 0) {
        *--ip = (unsigned char)accumulator;
        result->exp++;
    }
    for (i = 0; i < SIGDIGLEN && ip < ep; ++i, ++ip)
        result->sig.text[i] = *ip;
    result->sig.length = (unsigned char)i;
    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            unsigned char *jp = ip + 1;
            for (; jp < ep; ++jp)
                if (*jp != 0)
                    goto round;
            if ((*(ip - 1) & 1) == 0)
                return;
        }
    round:
        __dorounddecup(result, result->sig.length);
    }
}

void __str2dec(decimal *d, const char *s, short exp) {
    int i;
    d->exp = exp;
    d->sign = 0;
    for (i = 0; i < SIGDIGLEN && *s;)
        d->sig.text[i++] = (unsigned char)(*s++ - '0');
    d->sig.length = (unsigned char)i;
    if (*s != 0) {
        if (*s < 5)
            return;
        if (*s > 5)
            goto round;
        {
            const char *p = s + 1;
            for (; *p != 0; ++p)
                if (*p != '0')
                    goto round;
            if ((d->sig.text[i - 1] & 1) == 0)
                return;
        }
    round:
        __dorounddecup(d, d->sig.length);
    }
}

typedef struct decform { char style; short digits; } decform;
int __signbitd(double x);
int __fpclassifyd(double x);
double frexp(double x, int *exp);
double ldexp(double x, int n);
int __msl_count_bits64(unsigned long long x);

void __two_exp(decimal *result, long exp) {
    switch (exp) {
        case -64:
            __str2dec(result, "542101086242752217003726400434970855712890625", -20);
            return;
        case -53:
            __str2dec(result, "11102230246251565404236316680908203125", -16);
            return;
        case -32:
            __str2dec(result, "23283064365386962890625", -10);
            return;
        case -16:
            __str2dec(result, "152587890625", -5);
            return;
        case -8:
            __str2dec(result, "390625", -3);
            return;
        case -7:
            __str2dec(result, "78125", -3);
            return;
        case -6:
            __str2dec(result, "15625", -2);
            return;
        case -5:
            __str2dec(result, "3125", -2);
            return;
        case -4:
            __str2dec(result, "625", -2);
            return;
        case -3:
            __str2dec(result, "125", -1);
            return;
        case -2:
            __str2dec(result, "25", -1);
            return;
        case -1:
            __str2dec(result, "5", -1);
            return;
        case 0:
            __str2dec(result, "1", 0);
            return;
        case 1:
            __str2dec(result, "2", 0);
            return;
        case 2:
            __str2dec(result, "4", 0);
            return;
        case 3:
            __str2dec(result, "8", 0);
            return;
        case 4:
            __str2dec(result, "16", 1);
            return;
        case 5:
            __str2dec(result, "32", 1);
            return;
        case 6:
            __str2dec(result, "64", 1);
            return;
        case 7:
            __str2dec(result, "128", 2);
            return;
        case 8:
            __str2dec(result, "256", 2);
            return;
    }
    {
        decimal x2, temp;
        // fake match: equivalent to exp / 2, which MWCC emits as add r1, r4, r4, lsr #31
        __two_exp(&x2, (exp + (long)((unsigned long)(exp & 0x80000000) >> 31)) >> 1);
        __timesdec(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                __str2dec(&x2, "2", 0);
            else
                __str2dec(&x2, "5", -1);
            __timesdec(result, &temp, &x2);
        }
    }
}

static inline unsigned long long __dbl_bits(double d) {
    return *(unsigned long long *)&d;
}

static inline int __msl_count_trailing_zero64(unsigned long long x) {
    return __msl_count_bits64((x & -x) - 1);
}

void __num2dec_internal(decimal *d, double x) {
    char sign = (char)(__signbitd(x) != 0);
    if (x == 0) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] = 0;
        return;
    }
    if (__fpclassifyd(x) <= 2) {
        d->sign = sign;
        d->exp = 0;
        d->sig.length = 1;
        d->sig.text[0] = (unsigned char)(__fpclassifyd(x) == 1 ? 'N' : 'I');
        return;
    }
    if (sign)
        x = -x;
    {
        int exp;
        double frac = frexp(x, &exp);
        long num_bits_extract = 53 - __msl_count_trailing_zero64(__dbl_bits(frac) | 0x0010000000000000ULL);
        decimal int_d, pow2_d;
        __two_exp(&pow2_d, exp - num_bits_extract);
        __ull2dec(&int_d, (unsigned long long)ldexp(frac, num_bits_extract));
        __timesdec(d, &int_d, &pow2_d);
        d->sign = sign;
    }
}

void __num2dec(const decform *f, double x, decimal *d) {
    short digits = f->digits;
    int i;
    __num2dec_internal(d, x);
    if (d->sig.text[0] > 9)
        return;
    if (digits > SIGDIGLEN)
        digits = SIGDIGLEN;
    __rounddec(d, digits);
    while (d->sig.length < digits)
        d->sig.text[d->sig.length++] = 0;
    d->exp -= d->sig.length - 1;
    for (i = 0; i < d->sig.length; ++i)
        d->sig.text[i] += '0';
}
