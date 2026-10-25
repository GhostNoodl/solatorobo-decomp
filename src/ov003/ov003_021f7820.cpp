#include "types.h"

// The original TU also held the functions that read these (ov003_021e57b8.cpp and the one at
// 0x021f6a14, which reads `act` through data_ov003_021f8540 + 4).
struct Ov003PhotoCfg {
    const char *photo;
    char act[6];
    char photo1[8];
    char photo0[8];
    const char *photoB;
    const char *photoA;
};

extern "C" {
extern Ov003PhotoCfg data_ov003_021f8540;
extern const char *const data_ov003_021f4c64[2];
const char *const data_ov003_021f4c64[2] = { data_ov003_021f8540.photo1, data_ov003_021f8540.photo0 };
Ov003PhotoCfg data_ov003_021f8540 = {
    data_ov003_021f4c64[0], "act00", "photo01", "photo00", data_ov003_021f4c64[1], data_ov003_021f4c64[0],
};
}
