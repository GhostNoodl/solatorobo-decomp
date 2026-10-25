#include <nitro/fx.h>

// Read by ov015_02209364.cpp, ov015_0220947c.cpp, ov015_0220df48.cpp and ov015_0220e024.cpp,
// which the original TU also held, with the string pool at 0x02212dc0.
extern "C" {
extern const char data_ov015_02212dc6[];
}

struct Ov015ShipCfg {
    const char *name;
    fx32 scale;
};

extern "C" const Ov015ShipCfg data_ov015_02212db0;
const Ov015ShipCfg data_ov015_02212db0 = { data_ov015_02212dc6, FX_Div(256 * FX32_ONE, 15 * FX32_ONE) };
