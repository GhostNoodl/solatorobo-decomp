#include <nitro/fx.h>

// This TU's .data from its base to the end of its handler table, and the two .rodata
// pointers into the name block. The static initialiser fills the block's scale and pointers
// and copies __ptmf_null into the table's first two handlers.
//
// - The strings are the TU's file-name formats. They sit between the block and the vtable, so
//   they are written here as char arrays (MWCC packs those unaligned, as the ROM has them).
// - 0x021cc150 is a vtable written as two zero words plus 18 function pointers; the TU's
//   functions point objects at the handler part (0x021cc158).
// - The handler table is 42 {key, pointer-to-member} entries. Only the two null ones are
//   written as pointers-to-member; the rest give the {function, adjustment} words directly
//   through a union, so the handlers can stay C functions.
// - The target reaches the table through its own pool word, not as an offset from the name
//   block's address. MWCC addresses a weak object by its own symbol, so the table is
//   __declspec(weak); a plain definition reuses the block's base register (13 diffs).

#pragma explicit_zero_data on

class Ov000Scp;
typedef void (Ov000Scp::*Ov000ScpFn)();
typedef void (*Ov000Fn)(void);
struct Ov000ScpRaw { Ov000Fn fn; s32 adj; };
struct Ov000ScpEnt { s32 key; union { Ov000ScpFn pm; Ov000ScpRaw raw; } h; };

struct Ov000ScpNames {
    fx32 scale;
    const char *photo;
    char photo0[8];
    char photo1[8];
    const char *photoB;
    const char *photoA;
};

extern "C" {
void func_02038504(void);
void func_02038520(void);
void func_02038638(void);
void func_02038a10(void);
void func_02038b0c(void);
void func_02038b48(void);
void func_02038b88(void);
void func_02038c14(void);
void func_02038ca0(void);
void func_02038dbc(void);
void func_020396d4(void);
void func_020396e8(void);
void func_0205b588(void);
void func_0205b68c(void);
void func_0205b8dc(void);
void func_ov000_02181ab0(void);
void func_ov000_02181efc(void);
void func_ov000_02182cb8(void);
void func_ov000_021833d8(void);
void func_ov000_021834c4(void);
void func_ov000_021835f4(void);
void func_ov000_02183880(void);
void func_ov000_02183a10(void);
void func_ov000_02183db8(void);
void func_ov000_021845cc(void);
void func_ov000_02184810(void);
void func_ov000_02184924(void);
void func_ov000_02184be8(void);
void func_ov000_02184dc8(void);
void func_ov000_02184f20(void);
void func_ov000_021855a4(void);
void func_ov000_021859c4(void);
void func_ov000_021862b0(void);
void func_ov000_021866d0(void);
void func_ov000_02186a24(void);
void func_ov000_02186c88(void);
void func_ov000_02186df4(void);
void func_ov000_0218722c(void);
void func_ov000_02187420(void);
void func_ov000_02187660(void);
void func_ov000_021878c8(void);
void func_ov000_02187a58(void);
void func_ov000_02187b88(void);
void func_ov000_0218819c(void);
void func_ov000_02188438(void);
void func_ov000_0218867c(void);
void func_ov000_02189a38(void);
extern Ov000ScpNames data_ov000_021cc0d8;
extern const char *const data_ov000_021c9d44;
extern const char *const data_ov000_021c9d48;
}

static asm void ov000_021ca70c_order() {}

extern "C" {
Ov000ScpNames data_ov000_021cc0d8 = {FX_Div(256 * FX32_ONE, 15 * FX32_ONE), data_ov000_021c9d44, "photo00", "photo01", data_ov000_021c9d48, data_ov000_021c9d44};
const char *const data_ov000_021c9d44 = data_ov000_021cc0d8.photo1;
const char *const data_ov000_021c9d48 = data_ov000_021cc0d8.photo0;
char data_ov000_021cc0f8[] = "scpdmy.ccscp";
char data_ov000_021cc105[] = "scp%s.ccscp";
char data_ov000_021cc111[] = "script/";
char data_ov000_021cc119[] = "scninfo";
char data_ov000_021cc121[] = "scpmis%d.ccscp";
char data_ov000_021cc130[] = "misinfo";
char data_ov000_021cc138[] = "scpqst%d.ccscp";
char data_ov000_021cc147[] = "qstinfo";
u32 data_ov000_021cc150[2] = {0, 0};
Ov000Fn data_ov000_021cc158[18] = { func_ov000_02189a38, func_ov000_02181ab0, func_02038504, func_02038520, func_02038dbc, func_02038638, func_02038a10, func_02038b0c, func_02038b48, func_02038b88, func_02038c14, func_02038ca0, func_020396e8, func_020396d4, func_ov000_02181efc, func_0205b588, func_0205b68c, func_0205b8dc };
__declspec(weak) Ov000ScpEnt data_ov000_021cc1a0[42] = {
    { 0, { .pm = 0 } },
    { 0, { .pm = 0 } },
    { 0, { .raw = { func_ov000_02182cb8, 0 } } },
    { 0, { .raw = { func_ov000_021833d8, 0 } } },
    { 0, { .raw = { func_ov000_021834c4, 0 } } },
    { 0, { .raw = { func_ov000_021835f4, 0 } } },
    { 0, { .raw = { func_ov000_02183880, 0 } } },
    { 0, { .raw = { func_ov000_02183880, 0 } } },
    { 0, { .raw = { func_ov000_02183880, 0 } } },
    { 0, { .raw = { func_ov000_02183a10, 0 } } },
    { 0, { .raw = { func_ov000_02183db8, 0 } } },
    { 0, { .raw = { func_ov000_021845cc, 0 } } },
    { 0, { .raw = { func_ov000_02184810, 0 } } },
    { 0, { .raw = { func_ov000_02184924, 0 } } },
    { 0, { .raw = { func_ov000_02184be8, 0 } } },
    { 0, { .raw = { func_ov000_02184dc8, 0 } } },
    { 0, { .raw = { func_ov000_02184f20, 0 } } },
    { 0, { .raw = { func_ov000_021855a4, 0 } } },
    { 0, { .raw = { func_ov000_021855a4, 0 } } },
    { 0, { .raw = { func_ov000_021855a4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021859c4, 0 } } },
    { 0, { .raw = { func_ov000_021862b0, 0 } } },
    { 0, { .raw = { func_ov000_021862b0, 0 } } },
    { 0, { .raw = { func_ov000_021866d0, 0 } } },
    { 0, { .raw = { func_ov000_02186a24, 0 } } },
    { 0, { .raw = { func_ov000_02186c88, 0 } } },
    { 0, { .raw = { func_ov000_02186df4, 0 } } },
    { 0, { .raw = { func_ov000_0218722c, 0 } } },
    { 0, { .raw = { func_ov000_02187420, 0 } } },
    { 0, { .raw = { func_ov000_02187660, 0 } } },
    { 0, { .raw = { func_ov000_021878c8, 0 } } },
    { 0, { .raw = { func_ov000_02187a58, 0 } } },
    { 0, { .raw = { func_ov000_02187b88, 0 } } },
    { 0, { .raw = { func_ov000_0218819c, 0 } } },
    { 0, { .raw = { func_ov000_02188438, 0 } } },
    { 0, { .raw = { func_ov000_0218867c, 0 } } },
};
}
