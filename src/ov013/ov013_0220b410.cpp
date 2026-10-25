#include <nitro/fx.h>

// Two vectors built at startup at the start of the overlay's .data. The stub stores every member
// as an immediate: the original computed them with an expression MWCC folds in __sinit, which the
// inline identity reproduces. The first word is its own object, since a reader loads it and the
// rest through separate pool words.
static inline fx32 K(fx32 v) { return v; }

extern "C" {

extern const fx32 data_ov013_0220b5a0;
extern const fx32 data_ov013_0220b5a4[5];

const fx32 data_ov013_0220b5a0 = -K(0x5800);
const fx32 data_ov013_0220b5a4[5] = {K(0x1800), K(0x1800) - 0x15800, K(0x5800), K(0x1800), K(0x1800) - 0x15800};

}
