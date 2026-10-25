#include <nitro/fx.h>

// A self-referencing name block: const pointers to the names inside the block (and to the menu
// path), and the block, whose pointers are filled in at startup from them.
struct Ov000PhotoNames {
    const char *photo;
    char photo0[8];
    char photo1[8];
    const char *photoB;
    const char *photoA;
};

extern "C" {
extern Ov000PhotoNames data_ov000_021ca8b0;
extern const char *const data_ov000_021c9838;
extern char data_ov000_021ca8cc[];
extern const char *const data_ov000_021c983c;
extern const char *const data_ov000_021c9840;
extern const u16 data_ov000_021c9844[2];
Ov000PhotoNames data_ov000_021ca8b0 = {data_ov000_021c983c, "photo00", "photo01", data_ov000_021c9840, data_ov000_021c983c};
const char *const data_ov000_021c9840 = data_ov000_021ca8b0.photo0;
const char *const data_ov000_021c983c = data_ov000_021ca8b0.photo1;
const u16 data_ov000_021c9844[2] = {0x800, 0x1000};
const char *const data_ov000_021c9838 = data_ov000_021ca8cc;
}
