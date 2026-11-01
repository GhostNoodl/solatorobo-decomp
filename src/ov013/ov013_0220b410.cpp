#include <nitro/fx.h>

// Two vectors built at startup at the start of the overlay's .data. The stub stores every member
// as an immediate: the original computed them with an expression MWCC folds in __sinit, which the
// inline identity reproduces. func_ov013_021fc7e0 indexes the pair, so it loads the array's
// address and the address of its first .y as two pool words.
static inline fx32 K(fx32 v) { return v; }

extern "C" {

extern const VecFx32 data_ov013_0220b5a0[2];

const VecFx32 data_ov013_0220b5a0[2] = {
    {-K(0x5800), K(0x1800), K(0x1800) - 0x15800},
    {K(0x5800), K(0x1800), K(0x1800) - 0x15800},
};

}
