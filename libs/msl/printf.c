#include "types.h"

#pragma unsigned_char on
#pragma dont_reuse_strings off

typedef char *va_list;
#define va_arg(ap, type) (*(type *)((ap += sizeof(type)) - sizeof(type)))

extern const u16 __ctype_mapC[];

typedef struct print_format {
    /* 0x0 */ u8 justification_options;
    /* 0x1 */ u8 sign_options;
    /* 0x2 */ u8 precision_specified;
    /* 0x3 */ u8 alternate_form;
    /* 0x4 */ u8 argument_options;
    /* 0x5 */ u8 conversion_char;
    /* 0x8 */ int field_width;
    /* 0xc */ int precision;
} print_format;

enum { left_justification, right_justification, zero_fill };
enum { only_minus, sign_always, space_holder };
enum {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    wchar_argument,
    intmax_argument,
    size_t_argument,
    ptrdiff_argument,
    long_double_argument
};

#define bad_conversion 0xff
#define conversion_max 509
#define max_width 509

static inline int isdigit(int c) { return ((c < 0) || (c >= 0x80)) ? 0 : (int)(__ctype_mapC[c] & 8); }
static inline int isupper(int c) { return ((c < 0) || (c >= 0x80)) ? 0 : (int)(__ctype_mapC[c] & 0x200); }
#define strcpy(d, s) __memcpy(d, s, sizeof(s))

typedef struct decform {
    char style;
    short digits;
} decform;

typedef struct decimal {
    char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;

void __num2dec(const decform *f, double x, decimal *d);
double fabs(double x);

const char *parse_format(const char *format_string, va_list *arg, print_format *format) {
    print_format f;
    const unsigned char *s = (const unsigned char *)format_string;
    int c;
    int flag_found;
    f.justification_options = right_justification;
    f.sign_options = only_minus;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = normal_argument;
    f.field_width = 0;
    f.precision = 0;
    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return s + 1;
    }
    for (;;) {
        flag_found = 1;
        switch (c) {
            case '-':
                f.justification_options = left_justification;
                break;
            case '+':
                f.sign_options = sign_always;
                break;
            case ' ':
                if (f.sign_options != sign_always) {
                    f.sign_options = space_holder;
                }
                break;
            case '#':
                f.alternate_form = 1;
                break;
            case '0':
                if (f.justification_options != left_justification) {
                    f.justification_options = zero_fill;
                }
                break;
            default:
                flag_found = 0;
                break;
        }
        if (flag_found) {
            c = *++s;
        } else {
            break;
        }
    }
    if (c == '*') {
        if ((f.field_width = va_arg(*arg, int)) < 0) {
            f.justification_options = left_justification;
            f.field_width = -f.field_width;
        }
        c = *++s;
    } else {
        while (isdigit(c)) {
            f.field_width = (f.field_width * 10) + (c - '0');
            c = *++s;
        }
    }
    if (f.field_width > max_width) {
        f.conversion_char = bad_conversion;
        *format = f;
        return s + 1;
    }
    if (c == '.') {
        f.precision_specified = 1;
        if ((c = *++s) == '*') {
            if ((f.precision = va_arg(*arg, int)) < 0) {
                f.precision_specified = 0;
            }
            c = *++s;
        } else {
            while (isdigit(c)) {
                f.precision = (f.precision * 10) + (c - '0');
                c = *++s;
            }
        }
    }
    flag_found = 1;
    switch (c) {
        case 'h':
            f.argument_options = short_argument;
            if (s[1] == 'h') {
                f.argument_options = char_argument;
                c = *++s;
            }
            break;
        case 'l':
            f.argument_options = long_argument;
            if (s[1] == 'l') {
                f.argument_options = long_long_argument;
                c = *++s;
            }
            break;
        case 'L':
            f.argument_options = long_double_argument;
            break;
        case 'j':
            f.argument_options = intmax_argument;
            break;
        case 't':
            f.argument_options = ptrdiff_argument;
            break;
        case 'z':
            f.argument_options = size_t_argument;
            break;
        default:
            flag_found = 0;
            break;
    }
    if (flag_found) {
        c = *++s;
    }
    f.conversion_char = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'u':
        case 'o':
        case 'x':
        case 'X':
            if (f.argument_options == long_double_argument) {
                f.conversion_char = bad_conversion;
                break;
            }
            if (!f.precision_specified) {
                f.precision = 1;
            } else if (f.justification_options == zero_fill) {
                f.justification_options = right_justification;
            }
            break;
        case 'f':
        case 'F':
            if (f.argument_options == short_argument || f.argument_options == intmax_argument ||
                f.argument_options == size_t_argument || f.argument_options == ptrdiff_argument ||
                f.argument_options == long_long_argument) {
                f.conversion_char = bad_conversion;
                break;
            }
            if (!f.precision_specified) {
                f.precision = 6;
            }
            break;
        case 'a':
        case 'A':
            if (!f.precision_specified) {
                f.precision = 13;
            }
            if (f.argument_options == short_argument || f.argument_options == intmax_argument ||
                f.argument_options == size_t_argument || f.argument_options == ptrdiff_argument ||
                f.argument_options == long_long_argument || f.argument_options == char_argument) {
                f.conversion_char = bad_conversion;
            }
            break;
        case 'g':
        case 'G':
            if (!f.precision) {
                f.precision = 1;
            }
        case 'e':
        case 'E':
            if (f.argument_options == short_argument || f.argument_options == char_argument ||
                f.argument_options == intmax_argument || f.argument_options == size_t_argument ||
                f.argument_options == ptrdiff_argument || f.argument_options == long_long_argument) {
                f.conversion_char = bad_conversion;
                break;
            }
            if (!f.precision_specified) {
                f.precision = 6;
            }
            break;
        case 'p':
            f.conversion_char = 'x';
            f.alternate_form = 1;
            f.argument_options = long_argument;
            f.precision = 8;
            break;
        case 'c':
            if (f.argument_options == long_argument) {
                f.argument_options = wchar_argument;
            } else if (f.precision_specified || f.argument_options != normal_argument) {
                f.conversion_char = bad_conversion;
            }
            break;
        case 's':
            if (f.argument_options == long_argument) {
                f.argument_options = wchar_argument;
            } else if (f.argument_options != normal_argument) {
                f.conversion_char = bad_conversion;
            }
            break;
        case 'n':
            if (f.argument_options == long_double_argument) {
                f.conversion_char = bad_conversion;
            }
            break;
        default:
            f.conversion_char = bad_conversion;
            break;
    }
    *format = f;
    return s + 1;
}

char *long2str(long num, char *buff, print_format format) {
    unsigned long unsigned_num, base;
    char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
        case 'd':
        case 'i':
            base = 10;
            if (num < 0) {
                if (num != 0x8000000000000000LL)
                    unsigned_num = -num;
                minus = 1;
            }
            break;
        case 'o':
            base = 8;
            format.sign_options = only_minus;
            break;
        case 'u':
            base = 10;
            format.sign_options = only_minus;
            break;
        case 'x':
        case 'X':
            base = 16;
            format.sign_options = only_minus;
            break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *(unsigned char *)p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == zero_fill) {
        format.precision = format.field_width;
        if (minus || format.sign_options != only_minus)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > conversion_max)
        return NULL;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == sign_always)
        *--p = '+';
    else if (format.sign_options == space_holder)
        *--p = ' ';

    return p;
}

char *longlong2str(long long num, char *buff, print_format format) {
    unsigned long long unsigned_num, base;
    char *p;
    int n, digits;
    int minus = 0;

    unsigned_num = num;
    minus = 0;
    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format.precision && !(format.alternate_form && format.conversion_char == 'o'))
        return p;

    switch (format.conversion_char) {
        case 'd':
        case 'i':
            base = 10;
            if (num < 0) {
                if (num != 0x8000000000000000LL)
                    unsigned_num = -num;
                minus = 1;
            }
            break;
        case 'o':
            base = 8;
            format.sign_options = only_minus;
            break;
        case 'u':
            base = 10;
            format.sign_options = only_minus;
            break;
        case 'x':
        case 'X':
            base = 16;
            format.sign_options = only_minus;
            break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;
        if (n < 10)
            n += '0';
        else {
            n -= 10;
            if (format.conversion_char == 'x')
                n += 'a';
            else
                n += 'A';
        }
        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format.alternate_form && *(unsigned char *)p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format.justification_options == zero_fill) {
        format.precision = format.field_width;
        if (minus || format.sign_options != only_minus)
            --format.precision;
        if (base == 16 && format.alternate_form)
            format.precision -= 2;
    }

    if (buff - p + format.precision > conversion_max)
        return NULL;

    while (digits < format.precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format.alternate_form) {
        *--p = format.conversion_char;
        *--p = '0';
    }

    if (minus)
        *--p = '-';
    else if (format.sign_options == sign_always)
        *--p = '+';
    else if (format.sign_options == space_holder)
        *--p = ' ';

    return p;
}

char *double2hex(double num, char *buff, print_format format) {
    char *p;
    unsigned char *q;
    unsigned char working_byte;
    double ld;
    long exp;
    print_format exp_format;
    int hex_precision;
    decform form;
    decimal dec;
    unsigned long snum;
    int i;
    int mantissa_bit;

    p = buff;
    ld = num;

    if (format.precision > conversion_max)
        return NULL;

    form.style = 0;
    form.digits = 0x20;
    __num2dec(&form, num, &dec);

    switch (dec.sig.text[0]) {
        case '0':
            dec.exp = 0;
            break;
        case 'I':
            if (dec.sign) {
                p = buff - 5;
                if (format.conversion_char == 'A')
                    strcpy(p, "-INF");
                else
                    strcpy(p, "-inf");
            } else {
                p = buff - 4;
                if (format.conversion_char == 'A')
                    strcpy(p, "INF");
                else
                    strcpy(p, "inf");
            }
            return p;
        case 'N':
            if (dec.sign) {
                p = buff - 5;
                if (format.conversion_char == 'A')
                    strcpy(p, "-NAN");
                else
                    strcpy(p, "-nan");
            } else {
                p = buff - 4;
                if (format.conversion_char == 'A')
                    strcpy(p, "NAN");
                else
                    strcpy(p, "nan");
            }
            return p;
    }

    exp_format.justification_options = right_justification;
    exp_format.sign_options = sign_always;
    exp_format.precision_specified = 0;
    exp_format.alternate_form = 0;
    exp_format.argument_options = normal_argument;
    exp_format.field_width = 0;
    exp_format.precision = 1;
    exp_format.conversion_char = 'd';

    {
        int k;
        unsigned char *b = (unsigned char *)&num;
        for (k = 0; k < 4; k++) {
            unsigned char t = b[k];
            b[k] = b[7 - k];
            b[7 - k] = t;
        }
    }
    snum = ((unsigned char *)&num)[0] << 25;
    snum |= ((unsigned char *)&num)[1] << 17;
    exp = (snum >> 21) & 0x7ff;
    exp = exp ? exp - 1023 : 0;

    p = long2str(exp, buff, exp_format);
    if (format.conversion_char == 'a')
        *--p = 'p';
    else
        *--p = 'P';

    q = (unsigned char *)&num;
    hex_precision = format.precision;
    mantissa_bit = (1 + 11 + hex_precision * 4) - 1;
    for (i = hex_precision; i >= 1; --i) {
        if (mantissa_bit < 64) {
            int mantissa_byte = mantissa_bit >> 3;
            int mbit = 7 - (mantissa_bit & 7);
            working_byte = q[mantissa_byte] >> mbit;
            if ((mantissa_bit & ~7) != ((mantissa_bit - 4) & ~7))
                working_byte |= (q[mantissa_byte - 1] << 8) >> (7 - (mantissa_bit & 7));
            working_byte &= 0x0f;
            if (working_byte < 10)
                working_byte += '0';
            else if (format.conversion_char == 'a')
                working_byte += 'a' - 10;
            else
                working_byte += 'A' - 10;
        } else
            working_byte = '0';
        *--p = working_byte;
        mantissa_bit -= 4;
    }

    if (format.precision || format.alternate_form)
        *--p = '.';

    if (fabs(ld) != 0.0)
        *--p = '1';
    else
        *--p = '0';

    if (format.conversion_char == 'a')
        *--p = 'x';
    else
        *--p = 'X';
    *--p = '0';

    if (dec.sign)
        *--p = '-';
    else if (format.sign_options == sign_always)
        *--p = '+';
    else if (format.sign_options == space_holder)
        *--p = ' ';

    return p;
}

void round_decimal(decimal *dec, int new_length) {
    char c;
    char *p;
    int carry;

    if (new_length < 0) {
    return_zero:
        dec->exp = 0;
        dec->sig.length = 1;
        *dec->sig.text = '0';
        return;
    }

    if (new_length >= dec->sig.length)
        return;

    p = (char *)dec->sig.text + new_length + 1;
    c = *--p - '0';

    if (c == 5) {
        char *q = &((char *)dec->sig.text)[dec->sig.length];
        while (--q > p && *q == '0')
            ;
        carry = (q == p) ? p[-1] & 1 : 1;
    } else
        carry = (c > 5);

    while (new_length != 0) {
        c = *--p - '0' + carry;
        if ((carry = (c > 9)) != 0 || c == 0)
            --new_length;
        else {
            *p = c + '0';
            break;
        }
    }

    if (carry) {
        dec->exp += 1;
        dec->sig.length = 1;
        *dec->sig.text = '1';
        return;
    } else if (new_length == 0)
        goto return_zero;

    dec->sig.length = new_length;
}

char *float2str(double num, char *buff, print_format format) {
    decimal dec;
    decform form;
    char *p;
    char *q;
    int n, digits, sign;
    int int_digits, frac_digits;

    if (format.precision > conversion_max)
        return NULL;

    form.style = 0;
    form.digits = 0x20;

    __num2dec(&form, num, &dec);

    p = (char *)dec.sig.text + dec.sig.length;

    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }

    switch (*dec.sig.text) {
        case '0':
            dec.exp = 0;
            break;
        case 'I':
            if (num < 0) {
                p = buff - 5;
                if (isupper(format.conversion_char))
                    strcpy(p, "-INF");
                else
                    strcpy(p, "-inf");
            } else {
                p = buff - 4;
                if (isupper(format.conversion_char))
                    strcpy(p, "INF");
                else
                    strcpy(p, "inf");
            }
            return p;
        case 'N':
            if (dec.sign) {
                p = buff - 5;
                if (isupper(format.conversion_char))
                    strcpy(p, "-NAN");
                else
                    strcpy(p, "-nan");
            } else {
                p = buff - 4;
                if (isupper(format.conversion_char))
                    strcpy(p, "NAN");
                else
                    strcpy(p, "nan");
            }
            return p;
    }

    dec.exp += dec.sig.length - 1;
    p = buff;
    *--p = 0;

    switch (format.conversion_char) {
        case 'g':
        case 'G':
            if (dec.sig.length > format.precision)
                round_decimal(&dec, format.precision);
            if (dec.exp < -4 || dec.exp >= format.precision) {
                if (format.alternate_form)
                    --format.precision;
                else
                    format.precision = dec.sig.length - 1;
                if (format.conversion_char == 'g')
                    format.conversion_char = 'e';
                else
                    format.conversion_char = 'E';
                goto e_format;
            }
            if (format.alternate_form)
                format.precision -= dec.exp + 1;
            else if ((format.precision = dec.sig.length - (dec.exp + 1)) < 0)
                format.precision = 0;
            goto f_format;

        case 'e':
        case 'E':
        e_format:
            if (dec.sig.length > format.precision + 1)
                round_decimal(&dec, format.precision + 1);
            n = dec.exp;
            sign = '+';
            if (n < 0) {
                n = -n;
                sign = '-';
            }
            for (digits = 0; n || digits < 2; ++digits) {
                *--p = n % 10 + '0';
                n /= 10;
            }
            *--p = sign;
            *--p = format.conversion_char;
            if (buff - p + format.precision > conversion_max)
                return NULL;
            if (dec.sig.length < format.precision + 1)
                for (n = format.precision + 1 - dec.sig.length + 1; --n;)
                    *--p = '0';
            for (n = dec.sig.length, q = (char *)dec.sig.text + dec.sig.length; --n;)
                *--p = *--q;
            if (format.precision || format.alternate_form)
                *--p = '.';
            *--p = *dec.sig.text;
            if (dec.sign)
                *--p = '-';
            else if (format.sign_options == sign_always)
                *--p = '+';
            else if (format.sign_options == space_holder)
                *--p = ' ';
            break;

        case 'f':
        case 'F':
        f_format:
            if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
                frac_digits = 0;
            if (frac_digits > format.precision) {
                round_decimal(&dec, dec.sig.length - (frac_digits - format.precision));
                if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0)
                    frac_digits = 0;
            }
            if ((int_digits = dec.exp + 1) < 0)
                int_digits = 0;
            if (int_digits + frac_digits > conversion_max)
                return NULL;
            q = (char *)dec.sig.text + dec.sig.length;
            for (digits = 0; digits < (format.precision - frac_digits); ++digits)
                *--p = '0';
            for (digits = 0; digits < frac_digits && digits < dec.sig.length; ++digits)
                *--p = *--q;
            for (; digits < frac_digits; ++digits)
                *--p = '0';
            if (format.precision || format.alternate_form)
                *--p = '.';
            if (int_digits) {
                for (digits = 0; digits < int_digits - dec.sig.length; ++digits)
                    *--p = '0';
                for (; digits < int_digits; ++digits)
                    *--p = *--q;
            } else
                *--p = '0';
            if (dec.sign)
                *--p = '-';
            else if (format.sign_options == sign_always)
                *--p = '+';
            else if (format.sign_options == space_holder)
                *--p = ' ';
            break;
    }

    return p;
}
