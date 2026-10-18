#include "types.h"

extern "C" {
extern char data_ov000_021ca923[];
extern char data_ov000_021ca926[];
extern char data_ov000_021ca929[];
extern char data_ov000_021ca92c[];
extern char data_ov000_021ca92f[];
extern char data_ov000_021ca932[];
extern char data_ov000_021ca935[];
extern char data_ov000_021ca938[];
extern char data_ov000_021ca93b[];
char *STD_SearchString(char *str, const char *sub);
char *func_02061f08(void);

u32 func_ov000_0214bf2c(void) {
    char *s = func_02061f08();
    u32 flags = 0;
    if (s != NULL) {
        if (STD_SearchString(s, data_ov000_021ca923)) flags |= 0x2;
        if (STD_SearchString(s, data_ov000_021ca926)) flags |= 0x4;
        if (STD_SearchString(s, data_ov000_021ca929)) flags |= 0x8;
        if (STD_SearchString(s, data_ov000_021ca92c)) flags |= 0x10;
        if (STD_SearchString(s, data_ov000_021ca92f)) flags |= 0x20;
        if (STD_SearchString(s, data_ov000_021ca932)) flags |= 0x40;
        if (STD_SearchString(s, data_ov000_021ca935)) flags |= 0x200;
        if (STD_SearchString(s, data_ov000_021ca938)) flags |= 0x80;
        if (STD_SearchString(s, data_ov000_021ca93b)) flags |= 0x100;
    }
    return flags;
}
}
