#include "ov006/ov006.h"

typedef struct ov006_Eff021e37d0 {
    u8 unk0[0xc8];
    int unkC8;
    int unkCC;
} ov006_Eff021e37d0;

extern "C" {

void func_0206e900(char *dst, const char *src);
ov006_Eff021e37d0 *func_0206682c(const char *path, const char *name, int a, int b);

extern const char data_ov006_021ec178[];
extern const char data_ov006_021ec1b6[];
extern const char data_ov006_021ec1c2[];
extern const char *const data_ov006_021ec154[];
extern const char data_ov006_021ec1ce[];
extern const char data_ov006_021ec1da[];
extern const char data_ov006_021ec1e6[];
extern const char *const data_ov006_021ec144[];

ov006_Eff021e37d0 *func_ov006_021e37d0(int type, int arg) {
    char path[0x20];
    ov006_Eff021e37d0 *eff = NULL;

    func_0206e900(path, data_ov006_021ec178);
    switch (type) {
    case 0:
        eff = func_0206682c(path, data_ov006_021ec1b6, 0, arg);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        eff = func_0206682c(path, data_ov006_021ec1c2, 0, arg);
        func_0206682c(path, data_ov006_021ec154[type - 1], 0, arg);
        break;
    case 10:
        eff = func_0206682c(path, data_ov006_021ec1ce, 0, arg);
        break;
    case 11:
        eff = func_0206682c(path, data_ov006_021ec1da, 0, arg);
        break;
    case 12:
        eff = func_0206682c(path, data_ov006_021ec1e6, 0, arg);
        eff->unkCC = 0x10000;
        eff->unkC8 = -1;
        break;
    case 13:
    case 14:
    case 15:
    case 16:
        eff = func_0206682c(path, data_ov006_021ec144[type - 13], 0, arg);
        eff->unkC8 = -1;
        eff->unkCC = 0x32000;
        break;
    }
    return eff;
}

}
