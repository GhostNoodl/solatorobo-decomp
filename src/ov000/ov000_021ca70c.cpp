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

struct ResHandle;
struct StageRes;
struct VObj;
class SceneCmd;
class SceneScript;

extern "C" {
void ResHandle_Clear(ResHandle *handle);
void ResHandle_Unload(ResHandle *handle);
void ResHandle_LoadSync(ResHandle *handle, const char *name);
void ResHandle_OpenInArc(ResHandle *handle, const char *arcName, const char *name);
void ResHandle_Request(ResHandle *handle, const char *name);
void ResHandle_RequestFlag(ResHandle *handle, const char *name);
void ResHandle_LoadFromArc(ResHandle *handle, const char *arcName, const char *name);
void ResHandle_LoadFromArcFlag(ResHandle *handle, const char *arcName, const char *name);
BOOL ResHandle_IsLoaded(ResHandle *handle);
void *ResHandle_GetData(ResHandle *handle);
BOOL ResHandle_IsReady(ResHandle *handle);
BOOL ResHandle_OnLoad(ResHandle *handle);
u16 StageRes_EvalCond(StageRes *res, u16 *cmd);
u16 StageRes_AccessVar(StageRes *res, u16 *cmd, BOOL set, u16 value);
u16 StageRes_ExecCmd(StageRes *res, u16 *cmd);
VObj *Ov000Vt_021cc158_DtorDelete(VObj *self);
s32 func_ov000_02181efc(SceneScript *self, s32 a);
s32 SceneCmd_Run02(SceneCmd *self);
s32 SceneCmd_Run03(SceneCmd *self);
s32 SceneCmd_Run04(SceneCmd *self);
s32 SceneCmd_Run05(SceneCmd *self);
s32 SceneCmd_Run06to08(SceneCmd *self);
s32 SceneCmd_Run09(SceneCmd *self);
s32 SceneCmd_Run0a(SceneCmd *self);
s32 SceneCmd_Run0b(SceneCmd *self);
s32 SceneCmd_Run0c(SceneCmd *self);
s32 SceneCmd_Run0d(SceneCmd *self);
s32 SceneCmd_Run0e(SceneCmd *self);
s32 SceneCmd_Run0f(SceneCmd *self);
s32 SceneCmd_Run10(SceneCmd *self);
s32 SceneCmd_Run11to13(SceneCmd *self);
s32 SceneCmd_Run14to1a(SceneCmd *self);
s32 SceneCmd_Run1bto1c(SceneCmd *self);
s32 SceneCmd_Run1d(SceneCmd *self);
s32 SceneCmd_Run1e(SceneCmd *self);
s32 SceneCmd_Run1f(SceneCmd *self);
s32 SceneCmd_Run20(SceneCmd *self);
s32 SceneCmd_Run21(SceneCmd *self);
s32 SceneCmd_Run22(SceneCmd *self);
s32 SceneCmd_Run23(SceneCmd *self);
s32 SceneCmd_Run24(SceneCmd *self);
s32 SceneCmd_Run25(SceneCmd *self);
s32 SceneCmd_Run26(SceneCmd *self);
s32 SceneCmd_Run27(SceneCmd *self);
s32 SceneCmd_Run28(SceneCmd *self);
s32 SceneCmd_Run29(SceneCmd *self);
VObj *Ov000Vt_021cc158_Dtor(VObj *self);
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
Ov000Fn data_ov000_021cc158[18] = { (Ov000Fn)Ov000Vt_021cc158_Dtor, (Ov000Fn)Ov000Vt_021cc158_DtorDelete, (Ov000Fn)ResHandle_Clear, (Ov000Fn)ResHandle_Unload, (Ov000Fn)ResHandle_GetData, (Ov000Fn)ResHandle_LoadSync, (Ov000Fn)ResHandle_OpenInArc, (Ov000Fn)ResHandle_Request, (Ov000Fn)ResHandle_RequestFlag, (Ov000Fn)ResHandle_LoadFromArc, (Ov000Fn)ResHandle_LoadFromArcFlag, (Ov000Fn)ResHandle_IsLoaded, (Ov000Fn)ResHandle_OnLoad, (Ov000Fn)ResHandle_IsReady, (Ov000Fn)func_ov000_02181efc, (Ov000Fn)StageRes_EvalCond, (Ov000Fn)StageRes_AccessVar, (Ov000Fn)StageRes_ExecCmd };
__declspec(weak) Ov000ScpEnt data_ov000_021cc1a0[42] = {
    { 0, { .pm = 0 } },
    { 0, { .pm = 0 } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run02, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run03, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run04, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run05, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run06to08, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run06to08, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run06to08, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run09, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0b, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0c, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0d, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0e, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run0f, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run10, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run11to13, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run11to13, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run11to13, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run14to1a, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run1bto1c, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run1bto1c, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run1d, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run1e, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run1f, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run20, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run21, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run22, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run23, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run24, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run25, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run26, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run27, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run28, 0 } } },
    { 0, { .raw = { (Ov000Fn)SceneCmd_Run29, 0 } } },
};
}
