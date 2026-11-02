#include "ov006/ov006.h"
#include "Main/Effect/Effect.h"

extern "C" {

void func_0206e900(char *dst, const char *src);

extern char data_ov006_021ec178[];
extern const char data_ov006_021ec1b6[];
extern const char data_ov006_021ec1c2[];
extern const char *const data_ov006_021ec154[];
extern const char data_ov006_021ec1ce[];
extern const char data_ov006_021ec1da[];
extern const char data_ov006_021ec1e6[];
extern const char *const data_ov006_021ec144[];

EffectObj *func_ov006_021e37d0(int type, const VecFx32 *pos) {
    char path[0x20];
    EffectObj *eff = NULL;

    func_0206e900(path, data_ov006_021ec178);
    switch (type) {
    case 0:
        eff = func_0206682c(path, data_ov006_021ec1b6, 0, pos);
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
        eff = func_0206682c(path, data_ov006_021ec1c2, 0, pos);
        func_0206682c(path, data_ov006_021ec154[type - 1], 0, pos);
        break;
    case 10:
        eff = func_0206682c(path, data_ov006_021ec1ce, 0, pos);
        break;
    case 11:
        eff = func_0206682c(path, data_ov006_021ec1da, 0, pos);
        break;
    case 12:
        eff = func_0206682c(path, data_ov006_021ec1e6, 0, pos);
        eff->loopStart = 0x10000;
        eff->loopCount = -1;
        break;
    case 13:
    case 14:
    case 15:
    case 16:
        eff = func_0206682c(path, data_ov006_021ec144[type - 13], 0, pos);
        eff->loopCount = -1;
        eff->loopStart = 0x32000;
        break;
    }
    return eff;
}

}
