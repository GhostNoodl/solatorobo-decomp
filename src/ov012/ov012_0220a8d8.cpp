#include "ov012/ov012.h"
#include "Main/Math/Rot16.h"
#include "ov003/Shot.h"

// This TU's constants up to the last vector the static initialiser copies, and its .data up to the
// last effect record. Everything follows the empty asm function, so both sections keep definition
// order. The three handler tables are vtables (two zero words, then 41 handlers); the TU's
// functions point objects at the handler part. The functions at the end, Ov012Lift_StateAttack2 to
// func_ov012_021fdfa0, are part of this TU: they read the constants through the .rodata base plus an offset.
// Round dtC also folded in the files of 0x021fa6a0..0x021fab7c and 0x021fe8b4..0x02200200 (each in
// its own namespace): they point objects at the handler tables and pass the angle tables, which they
// now reach by the TU's own names instead of u8[] externs. Round dtD folded in 0x02200200..0x02201c70
// (two files). The two motion names at the start of .rodata are separate pointers
// (data_ov012_0220a3c4/a3c8), not one const char *const [2]: as an array, Ov012Act_021ffa68_StateIdle
// hoists the name loads above the stores before them (13 lines).
typedef void (*Ov012Fn)(void);

extern "C" {

void Ov012Act_021ffa68_Init(Ov003Actor *self);
void Actor_Remove(void *light);
BOOL Ov012Act_021ffa68_IsReady(Ov003Actor *self);
void Actor_Destroy(Actor *self);
BOOL Actor_IsActive(Actor *self);
void func_ov000_0218d190(Actor *self);
void func_ov012_02201cb8(void);
Ov012Act_021ffa68 *Ov012Act_021ffa68_Dtor(Ov012Act_021ffa68 *self);
Ov012Act_021ffa68 *Ov012Act_021ffa68_DtorDelete(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_Start(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_Update(Ov012Act_021ffa68 *self);
void Ov012ActorBase_UpdateMode3(void);
void Ov012ActorBase_UpdateMode1(void);
void Ov012Actor_UpdateHit(Ov003Actor *self);
void Ov012ActorBase_UpdateSub44(Ov003Actor *self);
void Ov012Act_021ffa68_HandleMsg(Ov012Act_021ffa68 *self, void *msg);
void Ov012Act_021ffa68_StateIdle(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_StateFly(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_StateAttack(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_StateAttack2(Ov012Act_021ffa68 *self);
void Ov012Actor_StateAttack3(Ov003Actor *self);
void Ov012Actor_Shoot2(Ov003Actor *self);
void Ov012Actor_State16(Ov003Actor *self);
void Ov012Act_021ffa68_StateDown(Ov012Act_021ffa68 *self);
void Ov012Act_021ffa68_StateDie(Ov003Actor *self);
void Ov012Actor_State21(void);
void Ov012Actor_State22(void);
void Ov012Actor_State23(void);
void Ov012Actor_State24(void);
void Ov012Actor_State25(void);
Ov012Act_021fee1c *Ov012Act_021fee1c_Dtor(Ov012Act_021fee1c *self);
Ov012Act_021fee1c *Ov012Act_021fee1c_DtorDelete(Ov012Act_021fee1c *self);
void Ov012Act_021fee1c_Start(Ov012Act_021fee1c *self);
void Ov012Act_021fee1c_Update(Ov012Act_021fee1c *self);
void Ov012Act_021fee1c_HandleMsg(Ov012Act_021fee1c *self, void *msg);
void Ov012Act_021fee1c_StateAttack2(Ov003Actor *self);
void Ov012Act_021fee1c_StateShoot(Ov012Act_021fee1c *self);
void Ov012Act_021fee1c_StateDie(Ov012Act_021fee1c *self);
BOOL Ov012Lift_Draw(Ov012Lift *self);
void Ov012Lift_Init(Ov012Lift *self);
BOOL Ov012Lift_IsReady(Ov012Lift *self);
Ov012Lift *Ov012Lift_Dtor(Ov012Lift *self);
Ov012Lift *Ov012Lift_DtorDelete(Ov012Lift *self);
void Ov012Lift_Start(Ov012Lift *self);
void Ov012Lift_Update(Ov012Lift *self);
void Ov012Lift_HandleMsg(Ov012Lift *self, void *msg);
void Ov012Lift_StateIdle(Ov003Actor *self);
void Ov012Lift_StateAttack(Ov012Lift *self);
void Ov012Lift_StateAttack2(Ov012Lift *self);
void Ov012Lift_StateAttack3(Ov012Lift *self);
void Ov012Lift_StateShoot(Ov012Lift *self);
void Ov012Lift_StateHurt(Ov003Actor *self);
void Ov012Lift_StateDie(Ov012Lift *self);
void Ov012Lift_State20(Ov012Lift *self);
void Ov012Lift_State21(Ov012Lift *self);
void Ov012Lift_State22(Ov012Lift *self);

static asm void ov012_0220a8d8_order() {
}

extern const Rot16 data_ov012_0220a3cc;
extern const Rot16 data_ov012_0220a3d2;
extern const Rot16 data_ov012_0220a3d8;
extern const Rot16 data_ov012_0220a3de;
extern const Rot16 data_ov012_0220a3e4;
extern const Rot16 data_ov012_0220a3ea;
extern const s16 data_ov012_0220a3f0[4];
extern const s16 data_ov012_0220a3f8[4];
extern const s16 data_ov012_0220a400[4];
extern const VecFx32 data_ov012_0220a408;
extern const VecFx32 data_ov012_0220a414;
extern const VecFx32 data_ov012_0220a420;
extern const VecFx32 data_ov012_0220a42c;
extern const VecFx32 data_ov012_0220a438;
extern const VecFx32 data_ov012_0220a444;
extern const VecFx32 data_ov012_0220a450;
extern const VecFx32 data_ov012_0220a45c;
extern const VecFx32 data_ov012_0220a468;
extern const VecFx32 data_ov012_0220a474;
extern const Rot16 data_ov012_0220aaa0;
extern char data_ov012_0220aaa6[];
extern char data_ov012_0220aaac[];
extern char data_ov012_0220aab2[];
extern char data_ov012_0220aabe[];
extern const VecFx32 data_ov012_0220aacc;
extern char data_ov012_0220aad8[];
extern char data_ov012_0220aae7[];
extern char data_ov012_0220ab08[];
extern char data_ov012_0220ab10[];
extern char data_ov012_0220ab1b[];
extern char data_ov012_0220ab21[];
extern char data_ov012_0220ab27[];
extern char data_ov012_0220ab2d[];
extern char data_ov012_0220ab33[];
extern u32 data_ov012_0220ab3c[2];
extern Ov012Fn Ov012Act_021ffa68_vtbl[41];
extern u32 data_ov012_0220abe8[2];
extern Ov012Fn Ov012Act_021fee1c_vtbl[41];
extern u32 data_ov012_0220ac94[2];
extern Ov012Fn Ov012Lift_vtbl[41];
extern const Ov003BeamDef data_ov012_0220ad40[6];

const char *const data_ov012_0220a3c4 = data_ov012_0220aaa6;
const char *const data_ov012_0220a3c8 = data_ov012_0220aaac;
const Rot16 data_ov012_0220a3cc = {0x3fff, 0, 0};
const Rot16 data_ov012_0220a3d2 = {0xbff4, 0, 0};
const Rot16 data_ov012_0220a3d8 = {0xbfff, 0, 0};
const Rot16 data_ov012_0220a3de = {0x3fff, 0, 0};
const Rot16 data_ov012_0220a3e4 = {0, 0, 0};
const Rot16 data_ov012_0220a3ea = {0x3fff, 0, 0};
const s16 data_ov012_0220a3f0[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a3f8[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a400[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const VecFx32 data_ov012_0220a408 = {0, 0x3000, 0};
const VecFx32 data_ov012_0220a414 = {0, 0x4000, -0x4000};
const VecFx32 data_ov012_0220a420 = {0, 0x1333, 0x1800};
const VecFx32 data_ov012_0220a42c = {0x7000, 0, -0xa000};
const VecFx32 data_ov012_0220a438 = {0x3800, 0, 0x3000};
const VecFx32 data_ov012_0220a444 = {0x3000, 0, 0};
const VecFx32 data_ov012_0220a450 = {0x1000, 0x1000, 0x1333};
const VecFx32 data_ov012_0220a45c = {0x2800, 0, 0x3800};
const VecFx32 data_ov012_0220a468 = {0, 0x1333, 0x4000};
const VecFx32 data_ov012_0220a474 = {0, 0, 0};

const Rot16 data_ov012_0220aaa0 = data_ov012_0220a3e4;
char data_ov012_0220aaa6[] = "run00";
char data_ov012_0220aaac[] = "nut00";
char data_ov012_0220aab2[] = "ef3di1ope11";
char data_ov012_0220aabe[] = "ef3di1ope10";
const VecFx32 data_ov012_0220aacc = data_ov012_0220a474;
char data_ov012_0220aad8[] = "ef/effect3dope";
char data_ov012_0220aae7[] = "ef3di1ope12.cceff";
char data_ov012_0220aaf9[] = "ef/effect3dope";
char data_ov012_0220ab08[] = "g1lft01";
char data_ov012_0220ab10[] = "gm/g1lft01";
char data_ov012_0220ab1b[] = "att00";
char data_ov012_0220ab21[] = "nut00";
char data_ov012_0220ab27[] = "gun00";
char data_ov012_0220ab2d[] = "att10";
char data_ov012_0220ab33[] = "att20";
#pragma explicit_zero_data on
u32 data_ov012_0220ab3c[2] = {0, 0};
Ov012Fn Ov012Act_021ffa68_vtbl[41] = {
    (Ov012Fn)Ov003Actor_Draw,
    (Ov012Fn)Ov012Act_021ffa68_Init,
    (Ov012Fn)Actor_Remove,
    (Ov012Fn)Ov012Act_021ffa68_IsReady,
    (Ov012Fn)Actor_Destroy,
    (Ov012Fn)Actor_IsActive,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Act_021ffa68_Dtor,
    (Ov012Fn)Ov012Act_021ffa68_DtorDelete,
    (Ov012Fn)Ov012Act_021ffa68_Start,
    (Ov012Fn)Ov012Act_021ffa68_Update,
    (Ov012Fn)Ov012ActorBase_UpdateMode3,
    (Ov012Fn)Ov012ActorBase_UpdateMode1,
    (Ov012Fn)Ov003Actor_SelectState,
    (Ov012Fn)Ov003Actor_RunState,
    (Ov012Fn)Ov003Actor_Animate,
    (Ov012Fn)Ov012Actor_UpdateHit,
    (Ov012Fn)Ov012ActorBase_UpdateSub44,
    (Ov012Fn)Ov012Act_021ffa68_HandleMsg,
    (Ov012Fn)Ov012Act_021ffa68_StateIdle,
    (Ov012Fn)Ov003Actor_StateMove,
    (Ov012Fn)Ov003Actor_StateHeld,
    (Ov012Fn)Ov003Actor_StateThrown,
    (Ov012Fn)Ov012Act_021ffa68_StateFly,
    (Ov012Fn)Ov012Act_021ffa68_StateAttack,
    (Ov012Fn)Ov012Act_021ffa68_StateAttack2,
    (Ov012Fn)Ov012Actor_StateAttack3,
    (Ov012Fn)Ov003Actor_StateShoot,
    (Ov012Fn)Ov012Actor_Shoot2,
    (Ov012Fn)Ov012Actor_State16,
    (Ov012Fn)Ov003Actor_StateHurt,
    (Ov012Fn)Ov003Actor_StateKnockBack,
    (Ov012Fn)Ov012Act_021ffa68_StateDown,
    (Ov012Fn)Ov012Act_021ffa68_StateDie,
    (Ov012Fn)Ov003Actor_State20,
    (Ov012Fn)Ov012Actor_State21,
    (Ov012Fn)Ov012Actor_State22,
    (Ov012Fn)Ov012Actor_State23,
    (Ov012Fn)Ov012Actor_State24,
    (Ov012Fn)Ov012Actor_State25,
};
u32 data_ov012_0220abe8[2] = {0, 0};
Ov012Fn Ov012Act_021fee1c_vtbl[41] = {
    (Ov012Fn)Ov003Actor_Draw,
    (Ov012Fn)Ov003Actor_Init,
    (Ov012Fn)Actor_Remove,
    (Ov012Fn)Actor_IsReady,
    (Ov012Fn)Actor_Destroy,
    (Ov012Fn)Actor_IsActive,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Act_021fee1c_Dtor,
    (Ov012Fn)Ov012Act_021fee1c_DtorDelete,
    (Ov012Fn)Ov012Act_021fee1c_Start,
    (Ov012Fn)Ov012Act_021fee1c_Update,
    (Ov012Fn)Ov012ActorBase_UpdateMode3,
    (Ov012Fn)Ov012ActorBase_UpdateMode1,
    (Ov012Fn)Ov003Actor_SelectState,
    (Ov012Fn)Ov003Actor_RunState,
    (Ov012Fn)Ov003Actor_Animate,
    (Ov012Fn)Ov012Actor_UpdateHit,
    (Ov012Fn)Ov012ActorBase_UpdateSub44,
    (Ov012Fn)Ov012Act_021fee1c_HandleMsg,
    (Ov012Fn)Ov003Actor_StateIdle,
    (Ov012Fn)Ov003Actor_StateMove,
    (Ov012Fn)Ov003Actor_StateHeld,
    (Ov012Fn)Ov003Actor_StateThrown,
    (Ov012Fn)Ov003Actor_StateFly,
    (Ov012Fn)Ov003Actor_StateAttack,
    (Ov012Fn)Ov012Act_021fee1c_StateAttack2,
    (Ov012Fn)Ov012Actor_StateAttack3,
    (Ov012Fn)Ov012Act_021fee1c_StateShoot,
    (Ov012Fn)Ov012Actor_Shoot2,
    (Ov012Fn)Ov012Actor_State16,
    (Ov012Fn)Ov003Actor_StateHurt,
    (Ov012Fn)Ov003Actor_StateKnockBack,
    (Ov012Fn)Ov003Actor_StateDown,
    (Ov012Fn)Ov012Act_021fee1c_StateDie,
    (Ov012Fn)Ov003Actor_State20,
    (Ov012Fn)Ov012Actor_State21,
    (Ov012Fn)Ov012Actor_State22,
    (Ov012Fn)Ov012Actor_State23,
    (Ov012Fn)Ov012Actor_State24,
    (Ov012Fn)Ov012Actor_State25,
};
u32 data_ov012_0220ac94[2] = {0, 0};
Ov012Fn Ov012Lift_vtbl[41] = {
    (Ov012Fn)Ov012Lift_Draw,
    (Ov012Fn)Ov012Lift_Init,
    (Ov012Fn)Actor_Remove,
    (Ov012Fn)Ov012Lift_IsReady,
    (Ov012Fn)Actor_Destroy,
    (Ov012Fn)Actor_IsActive,
    (Ov012Fn)func_ov000_0218d190,
    (Ov012Fn)func_ov012_02201cb8,
    (Ov012Fn)Ov012Lift_Dtor,
    (Ov012Fn)Ov012Lift_DtorDelete,
    (Ov012Fn)Ov012Lift_Start,
    (Ov012Fn)Ov012Lift_Update,
    (Ov012Fn)Ov012ActorBase_UpdateMode3,
    (Ov012Fn)Ov012ActorBase_UpdateMode1,
    (Ov012Fn)Ov003Actor_SelectState,
    (Ov012Fn)Ov003Actor_RunState,
    (Ov012Fn)Ov003Actor_Animate,
    (Ov012Fn)Ov012Actor_UpdateHit,
    (Ov012Fn)Ov012ActorBase_UpdateSub44,
    (Ov012Fn)Ov012Lift_HandleMsg,
    (Ov012Fn)Ov012Lift_StateIdle,
    (Ov012Fn)Ov003Actor_StateMove,
    (Ov012Fn)Ov003Actor_StateHeld,
    (Ov012Fn)Ov003Actor_StateThrown,
    (Ov012Fn)Ov003Actor_StateFly,
    (Ov012Fn)Ov012Lift_StateAttack,
    (Ov012Fn)Ov012Lift_StateAttack2,
    (Ov012Fn)Ov012Lift_StateAttack3,
    (Ov012Fn)Ov012Lift_StateShoot,
    (Ov012Fn)Ov012Actor_Shoot2,
    (Ov012Fn)Ov012Actor_State16,
    (Ov012Fn)Ov012Lift_StateHurt,
    (Ov012Fn)Ov003Actor_StateKnockBack,
    (Ov012Fn)Ov003Actor_StateDown,
    (Ov012Fn)Ov012Lift_StateDie,
    (Ov012Fn)Ov012Lift_State20,
    (Ov012Fn)Ov012Lift_State21,
    (Ov012Fn)Ov012Lift_State22,
    (Ov012Fn)Ov012Actor_State23,
    (Ov012Fn)Ov012Actor_State24,
    (Ov012Fn)Ov012Actor_State25,
};

const Ov003BeamDef data_ov012_0220ad40[6] = {
    {data_ov012_0220aad8, 0x46, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1e, 0, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}, {data_ov012_0220aabe, -0x1, 0x1d, 0, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x19, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1e, 0, 0x180, 0x100, 0x33, 0x1a, 0x1a, 0xd}, {data_ov012_0220aabe, -0x1, 0x1d, 0, 0x100, 0x14d, 0x1a, 0x21, 0xd, 0x0}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x12c, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1d, 0, 0x300, 0x300, 0x4d, 0x4d, 0x26, 0x26}, {data_ov012_0220aabe, -0x1, 0x19, 0, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x14a, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1d, 0, 0x400, 0x400, 0x80, 0x66, 0x40, 0x33}, {data_ov012_0220aabe, -0x1, 0x1b, 0, 0x200, 0x14d, 0x33, 0x21, 0x1a, 0x0}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x1c2, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1e, 0, 0x280, 0x180, 0x4d, 0x33, 0x26, 0x1a}, {data_ov012_0220aabe, -0x1, 0x1d, 0, 0x180, 0x14d, 0x26, 0x21, 0x12, 0x0}}, data_ov012_0220aae7, 0x1000},
    {data_ov012_0220aad8, 0x3e8, {0, 0}, data_ov012_0220a468, 0x1a, {0, 0}, {{data_ov012_0220aab2, -0x1, 0x1e, 0, 0x366, 0x100, 0x66, 0x1a, 0x33, 0xd}, {data_ov012_0220aabe, -0x1, 0x1d, 0, 0x233, 0x140, 0x33, 0x21, 0x1a, 0x0}}, data_ov012_0220aae7, 0x1000}
};


// ---- merged from ov012_021fa6a0.cpp
namespace m_021fa6a0 {
extern "C" {

#pragma force_active on
Ov012Lift *Ov012Lift_Ctor(Ov012Lift *self) {
    u8 i;
    Ov003Actor_Ctor(self);
    *(void **)self = Ov012Lift_vtbl;
    ResSet_Init(&self->unk_174);
    Model0218fe1c_Init(&self->mdl);
    self->unk_10c = 0x40;
    self->unk_110 = 0;
    self->unk_136 = 0;
    self->unk_137 = 0;
    self->unk_112 = 0;
    for (i = 0; i < 3; i++) {
        self->fxId[i] = -1;
    }
    self->unk_3af = 0;
    self->unk_3ae = 0;
    self->unk_170 = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
Ov012Lift *Ov012Lift_Dtor(Ov012Lift *self) {
    *(void **)self = Ov012Lift_vtbl;
    Ov012_StopSnd();
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_174);
    Ov003Actor_DtorBase(self);
    return self;
}
}

extern "C" {
Ov012Lift *Ov012Lift_DtorDelete(Ov012Lift *self) {
    *(void **)self = Ov012Lift_vtbl;
    Ov012_StopSnd();
    Model0218fe1c_FreeAnims(&self->mdl);
    ResSet_ReleaseAll(&self->unk_174);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
}
}  // namespace m_021fa6a0

// ---- merged from ov012_021fa80c.cpp
namespace m_021fa80c {
extern "C" {


void Ov012Lift_Init(Ov012Lift *self) {
    Ov003Actor_Init(self);
    self->unk_f0 = self->unk_18;
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    SceneCmd_Push25(gSceneCmd, 5);
    ResMgr_Load(data_ov012_0220aaf9, 7, 0);
    if (self->unk_f0 == 1) {
        SceneCmd_Push25(gSceneCmd, 6);
        {
            const char *b = data_ov012_0220ab08;
            Ov012Names *n = &self->unk_174;
            if (b) {
                STD_CopyString(n->mdlDir, data_ov012_0220ab10);
                STD_CopyString(n->mdlName, b);
                n->ownMdl = 1;
            }
            n->unk_00 = 0;
        }
    }
}

}
}  // namespace m_021fa80c

// ---- merged from ov012_021fa8b8.cpp
namespace m_021fa8b8 {
extern "C" {
BOOL Ov012Lift_IsReady(Ov012Lift *self) {
    BOOL r = Actor_IsReady(self);
    r = (r & ResMgr_IsLoaded(data_ov012_0220aaf9, 7)) ? TRUE : FALSE;
    if (self->unk_f0 == 1 && self->unk_174.unk_00 >= 0) {
        r = (r & ResSet_UpdateLoad(&self->unk_174)) ? TRUE : FALSE;
    }
    return r;
}
}

extern "C" {
BOOL Ov012Lift_Draw(Ov012Lift *self) {
    if (self->unk_f0 == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            self->mdl.trans = self->arr[i];
            Model021903b4_Draw(&self->mdl);
        }
    }
    return Ov003Actor_Draw(self);
}
}

extern "C" {
void Ov012Lift_HandleMsg(Ov012Lift *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_112 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_16c = msg->unk_06;
        self->unk_3af = msg->unk_08;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    Ov003Actor_HandleMsg(self, msg);
}
}

extern "C" {
extern const u8 data_ov012_0220a498[];
extern const u8 data_ov012_0220a480[];
extern const VecFx32 data_ov012_0220a4bc[];

void Ov012Lift_Start(Ov012Lift *self) {
    Ov003Unit *o;
    ActorSub48 *m;
    Ov003Actor_Start(self);
    o = (Ov003Unit *)Group_FindNode(gGroup, self->unk_20);
    if (o != NULL) {
        o->unk_a2_0 = 0;
    }
    VEC_Add(&self->pos, (VecFx32 *)data_ov012_0220a498, &self->pos);
    VEC_Add(&self->pos, (VecFx32 *)data_ov012_0220a480, &self->unk_100);
    self->unk_f4 = self->pos;
    self->pos.y -= 0x11000;
    m = self->hit;
    m->offset.x = 0;
    m->offset.y = 0x3000;
    m->offset.z = 0;
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    if (self->unk_f0 == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            self->arr[i] = data_ov012_0220a4bc[i];
            self->unk_3ac[i] = 0;
        }
        Model0218fe1c_SetRes(&self->mdl, &self->unk_174, 0, 0);
        self->mdl.scale.x = 0x1000;
        self->mdl.scale.y = 0x1000;
        self->mdl.scale.z = 0x1333;
        self->mdl.visible = 1;
    }
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a3f8);
        self->unk_170 = 0x1800;
    }
}
}
}  // namespace m_021fa8b8
// ---- merged from 021fab7c
namespace m_021fab7c {




extern "C" {

extern void func_ov012_021fb060(Ov012Lift *self);
extern void func_ov012_021fb300(Ov012Lift *self);
extern void func_ov012_021fb818(Ov012Lift *self);
static inline Ov003Actor *Ov012_FindActorT(u16 id) {
    return gActorMgr == NULL ? NULL : (Ov003Actor *)ActorMgr_GetActor(gActorMgr, id);
}

static inline void Ov012_VSubP(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline u16 Ov012_Pct(u16 *p) {
    return p[0] * 100 / p[1];
}


void Ov012Lift_Update(Ov012Lift *self) {
    VecFx32 w;
    VecFx32 v;
    Ov003Actor *pl;
    u8 k;
    u16 s;
    u16 hp;
    u16 pct;
    Ov003Actor *a;
    EffectObj *o;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
    }
    self->unk_93_4 = 1;
    k = self->fsm->current;
    switch (self->unk_f0) {
    case 0:
        func_ov012_021fb060(self);
        break;
    case 1:
        func_ov012_021fb300(self);
        if (Ov012_GameIdle()) {
            func_ov012_021fb818(self);
        }
        break;
    }
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->msg_flags & 0x200) {
        if (Rand_UpTo(1)) {
            SndMgr_PlayAt((SndMgr *)gSndMgr, 0x503, &self->pos, 0);
        } else {
            SndMgr_PlayAt((SndMgr *)gSndMgr, 0x504, &self->pos, 0);
        }
        if (*self->hp == 0) {
            self->fsm->flags = 0;
            self->fsm->flags |= 0x200000;
        } else if (self->unk_f0 == 1) {
            s = self->fsm->st;
            if (k == 0x11) {
                if (s == 0xc) {
                    u16 id = self->target_id;
                    a = Ov012_FindActorT(id);
                    if (a != NULL) {
                        a->unk_1a = 1;
                        self->fsm->timer = 0;
                        self->fsm->st = 0xd;
                    }
                }
                if (s >= 0xc) {
                    Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x1000, 0);
                }
            } else if (k == 0x10 && (self->unk_10c & 0x20000000)) {
                if (s == 0xb) {
                    u16 id = self->target_id;
                    a = Ov012_FindActorT(id);
                    if (a != NULL) {
                        a->unk_1a = 1;
                        self->fsm->timer = 0;
                        self->fsm->st = 0xc;
                    }
                }
                if (s >= 0xb) {
                    Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x1000, 0);
                }
            }
        }
    }
    hp = self->hp[0];
    pct = hp * 100 / self->hp[1];
    if ((s32)pct > 0x2d) {
        return;
    }
    if (hp == 0) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 == 0) {
        s32 n;
        s32 z;
        v = self->pos;
        v.y += self->height >> 1;
        z = self->radius;
        Ov012_VecSet(&w, Rand_PlusMinus(z), Rand_PlusMinus(self->height >> 2), z);
        MTX_MultVec33(&w, (MtxFx33 *)NNS_G3dGlbGetInvV(), &w);
        VEC_Add(&w, &v, &w);
        n = Rand_UpTo(0x4cd);
        {
            Rot16 r = data_ov012_0220a3d2;
            o = Effect_SpawnId(0x325, &w);
            o->SetScaleAll(n + 0x800);
            o->SetRot(&r);
        }
        self->fxId[1] = o->id;
        self->unk_154 = w.x - self->pos.x;
        self->unk_158 = w.y - self->pos.y;
        self->unk_15c = w.z - self->pos.z;
        self->unk_b6 = 0xfa - (0xc8 - pct * 4);
    }
    if (self->fxId[1] == -1) {
        return;
    }
    o = Effect_Find_020657b0(gEffectMgr, self->fxId[1]);
    if (o == NULL) {
        return;
    }
    VEC_Add((VecFx32 *)((u8 *)self + 0x154), &self->pos, &w);
    { s32 ox = o->pos.x; s32 oy = o->pos.y; s32 oz = o->pos.z; w.x -= ox; w.y -= oy; w.z -= oz; }
    o->AddPos(&w);
}


}
}  // namespace m_021fab7c
// ---- merged from 021fb060
namespace m_021fb060 {

extern "C" {
void func_ov012_021fb060(Ov012Lift *self) {
    Ov003Actor *o;
    s32 r;
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->fsm->current != 1) {
        return;
    }
    o = Ov012_FindRes(0x4000, 0x480f);
    if (self->unk_10c == 0) {
        r = Rand_UpTo(9);
        if (((r >= 0 && r < 3) || History_HasState(self->fsm, 0x12, 2, 1) ||
             History_HasState(self->fsm, 0xe, 4, 1) || o != NULL) &&
            self->unk_136 < 2) {
            u16 *hp = self->hp;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            self->target_id = 0;
            if (pct > 0x4b) {
                self->unk_10c |= 0x100000;
                self->fsm->flags |= 0x8000;
            } else if (pct > 0x32) {
                self->unk_10c |= 0x200000;
                self->fsm->flags |= 0x8000;
            } else if (pct > 0x19) {
                self->unk_10c |= 8;
                self->fsm->flags |= 0x10000;
            } else {
                self->unk_10c |= 0x10;
                self->fsm->flags |= 0x20000;
            }
            self->unk_136++;
        } else if ((r >= 3 && r < 10) || self->unk_136 >= 2) {
            if (o == NULL) {
                self->fsm->flags |= 0x4000;
                self->unk_10c |= 0x20;
            }
            self->unk_136 = 0;
        }
    } else if (self->unk_10c & 1) {
        if (o == NULL) {
            self->unk_110++;
            self->fsm->timer = 0;
            if (self->unk_10c & 0x20) {
                self->unk_10c ^= 0x20;
            }
            if (self->unk_10c & 1) {
                self->unk_10c ^= 1;
            }
        } else if (Ov003_CountActorsOfKind(0x480f) <= 1) {
            if (self->unk_110++ >= 0x64) {
                if (self->unk_10c & 0x20) {
                    self->unk_10c ^= 0x20;
                }
                if (self->unk_10c & 1) {
                    self->unk_10c ^= 1;
                }
            }
        }
    }
}

void func_ov012_021feacc(Ov003Actor *self, s32 a);
void func_ov012_021fec58(Ov003Actor *self, s32 a);

static inline void Ov012_LiftTick(Ov012Lift *self) {
    if (self->unk_3af & 1) {
        func_ov012_021feacc(self, 0);
    }
    if (self->unk_3af & 2) {
        func_ov012_021feacc(self, 1);
    }
    if (self->unk_3af & 4) {
        func_ov012_021fec58(self, 0);
    }
    if (self->unk_3af & 8) {
        func_ov012_021fec58(self, 1);
    }
}

void func_ov012_021fb300(Ov012Lift *self) {
    u8 c;
    u8 d;
    s32 id;
    Ov003Actor *a = Ov012_FindRes(0x5000, 0x5c14);
    Ov003Actor *b = Ov012_FindRes(0x5000, 0x5c13);
    switch (self->unk_b4) {
    case 0:
        self->unk_b6++;
        if (self->unk_b6 > 10) {
            self->unk_3ae = 0;
            self->unk_3af = 0xc;
            self->unk_b6 = 0;
            self->unk_b4++;
        }
        break;
    case 1:
        Ov012_LiftTick(self);
        if (a != NULL) {
            a->pos = self->arr[0];
        }
        if (b != NULL) {
            b->pos = self->arr[1];
        }
        if (self->unk_3af == 0) {
            c = 1;
            ActorMgr_SendToKindOthers(0x5c13, self->kind, 6, 1, 1, &c);
            ActorMgr_SendToKindOthers(0x5c14, self->kind, 6, 1, 1, &c);
            self->unk_10c ^= 0x2000000;
            self->mdl.visible = 0;
            self->unk_b4 = 10;
        }
        break;
    case 10:
        if ((self->unk_10c & 0x8000000) || (self->unk_10c & 0x10000000)) {
            c = 2;
            if (self->unk_10c & 0x8000000) {
                id = 0x5c13;
            } else if (self->unk_10c & 0x10000000) {
                id = 0x5c14;
            }
            ActorMgr_SendToKindOthers(id, self->kind, 6, 1, 1, &c);
            if (!(self->unk_10c & 0x10)) {
                self->unk_16e = Rand_UpTo(1);
            }
            d = self->unk_16e;
            ActorMgr_SendToKindOthers(id, self->kind, 0xe, 1, 1, &d);
            self->unk_10c |= 0x4000000;
            self->unk_3ae = 0;
            self->mdl.visible = true;
            self->unk_b4++;
        }
        break;
    case 11: {
        BOOL go;
        Ov012_LiftTick(self);
        switch (self->unk_16c) {
        case 0x5c13:
            if (b != NULL) {
                b->pos = self->arr[self->unk_16e];
            }
            break;
        case 0x5c14:
            if (a != NULL) {
                Ov012_VecSet(&FLD(VecFx32, a, 0x70), a->pos.x, self->arr[self->unk_16e].y, a->pos.z);
            }
            break;
        }
        if (self->unk_3af == 0) {
            go = FALSE;
            self->unk_3ae = 0;
            if (self->unk_10c & 0x4000000) {
                if (self->unk_10c & 0x20000000) {
                    c = 4;
                    self->unk_b4++;
                    go = TRUE;
                } else if (self->unk_10c & 0x40000000) {
                    c = 8;
                    self->unk_b4++;
                    go = TRUE;
                }
            } else {
                go = TRUE;
                c = 1;
                self->mdl.visible = 0;
                self->unk_b4 = 10;
            }
            if (go) {
                ActorMgr_SendToKindOthers(self->unk_16c, self->kind, 6, 1, 1, &c);
            }
        }
        break;
    }
    case 12:
        if (self->unk_3af != 0) {
            if (self->unk_10c & 0x4000000) {
                self->unk_10c ^= 0x4000000;
            }
            if (self->unk_10c & 0x20000000) {
                self->unk_10c ^= 0x20000000;
            }
            if (self->unk_10c & 0x40000000) {
                self->unk_10c ^= 0x40000000;
            }
            if (self->unk_10c & 0x8000000) {
                self->unk_10c ^= 0x8000000;
            } else if (self->unk_10c & 0x10000000) {
                self->unk_10c ^= 0x10000000;
            }
            self->unk_b4 = 11;
        }
        break;
    }
    if (!(self->msg_flags & 0x200)) {
        return;
    }
    if (self->hp[0] != 0) {
        return;
    }
    c = 0x10;
    ActorMgr_SendToKindOthers(0x5c13, self->kind, 6, 1, 1, &c);
    ActorMgr_SendToKindOthers(0x5c14, self->kind, 6, 1, 1, &c);
}
}
}  // namespace m_021fb060
// ---- merged from 021fb818
namespace m_021fb818 {

extern "C" {
void func_ov012_021fb818(Ov012Lift *self) {
    u16 *hp = self->hp;
    s32 pct;
    u8 k = self->fsm->current;
    pct = (u16)(hp[0] * 100 / hp[1]);
    if (k == 1) {
        if (self->unk_10c == 0 && self->unk_3af == 0) {
            s32 r = Rand_UpTo(9);
            if ((r >= 4 || History_HasState(self->fsm, 0xf, 4, 1)) && self->unk_136 < 2) {
                s32 r2 = Rand_UpTo(9);
                if (pct >= 0x2d) {
                    if (r2 >= 2) {
                        self->unk_10c |= 0x10;
                    } else {
                        self->unk_10c |= 8;
                    }
                } else if (pct < 0x2d) {
                    if (r2 >= 2) {
                        self->unk_10c |= 8;
                    } else {
                        self->unk_10c |= 0x10;
                    }
                }
                if (self->unk_10c & 8) {
                    self->unk_10c |= 0x400000;
                    self->fsm->flags |= 0x10000;
                } else if (self->unk_10c & 0x10) {
                    self->fsm->flags |= 0x20000;
                }
                self->unk_136++;
            } else if (r < 4 || self->unk_136 >= 2) {
                self->unk_136 = 0;
                self->unk_10c |= 0x28400000;
                if (pct > 0x32) {
                    self->unk_10c |= 0x100000;
                    self->fsm->flags |= 0x8000;
                } else {
                    self->unk_10c |= 0x200000;
                    self->fsm->flags |= 0x8000;
                }
            }
        } else if (self->unk_10c & 1) {
            if (self->unk_110++ >= 0x14) {
                self->unk_10c ^= 1;
                self->unk_110 = 0;
            }
        }
    }
    if ((self->msg_flags & 0x40) && ((u16)self->unk_112) == 1) {
        Ov003Actor *o = Ov012_FindActor(self->target_id);
        if (o != NULL) {
            o->unk_1a = 1;
            self->fsm->timer = 0;
            switch (k) {
            case 0x10:
                self->fsm->st = 0xc;
                break;
            case 0x11:
                self->fsm->st = 0xd;
                break;
            }
        }
    }
}
}

extern "C" {
void Ov012Lift_State20(Ov012Lift *self) {
    ActorSub40 *s;
    VecFx32 d;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        SndMgr_PlayAt(gSndMgr, 0x50, &self->unk_f4, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0xa0) {
            if (self->unk_10c & 0x40) {
                self->unk_10c ^= 0x40;
            }
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(4);
            gSceneCmd->stageFlags = 1;
            if (self->unk_f0 == 0) {
                History_SetState(self->fsm, 1, 0);
            }
        }
        break;
    }
    d.x = self->unk_f4.x - self->pos.x;
    d.y = self->unk_f4.y - self->pos.y;
    d.z = self->unk_f4.z - self->pos.z;
    VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
}
}

extern "C" {
void func_ov012_021feacc(Ov003Actor *self, s32 a);
void func_ov012_021fec58(Ov003Actor *self, s32 a);
void Ov012Lift_State21(Ov012Lift *self) {
    Ov003Actor *o;
    ActorSub40 *s;
    if (self->unk_f0 != 1) {
        return;
    }
    o = Ov012_FindRes(0x5000, 0x5c13);
    if (o == NULL) {
        return;
    }
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_3ae = 0;
        self->unk_3af = 2;
        s->st++;
    case 1:
        if (self->unk_3af & 1) {
            func_ov012_021feacc(self, 0);
        }
        if (self->unk_3af & 2) {
            func_ov012_021feacc(self, 1);
        }
        if (self->unk_3af & 4) {
            func_ov012_021fec58(self, 0);
        }
        if (self->unk_3af & 8) {
            func_ov012_021fec58(self, 1);
        }
        o->pos = self->arr[1];
        if (self->unk_3af == 0) {
            self->fsm->st++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        gSceneCmd->stageFlags = 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021feacc(Ov003Actor *self, s32 a);
void func_ov012_021fec58(Ov003Actor *self, s32 a);
void Ov012Lift_State22(Ov012Lift *self) {
    Ov003Actor *o;
    ActorSub40 *s;
    if (self->unk_f0 != 1) {
        return;
    }
    o = Ov012_FindRes(0x5000, 0x5c14);
    if (o == NULL) {
        return;
    }
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_3ae = 0;
        self->unk_3af = 1;
        s->timer = 0;
        self->fsm->st++;
    case 1:
        if (self->unk_3af & 1) {
            func_ov012_021feacc(self, 0);
        }
        if (self->unk_3af & 2) {
            func_ov012_021feacc(self, 1);
        }
        if (self->unk_3af & 4) {
            func_ov012_021fec58(self, 0);
        }
        if (self->unk_3af & 8) {
            func_ov012_021fec58(self, 1);
        }
        o->pos = self->arr[0];
        if (self->unk_3af == 0) {
            self->fsm->st++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer < 0x50) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        gSceneCmd->stageFlags = 1;
        self->fsm->timer = 0;
        History_SetState(self->fsm, 1, 0);
        self->unk_10c = 0x2000000;
        break;
    }
}
}

extern "C" {
void Ov012Lift_StateIdle(Ov003Actor *self) {
    if (self->fsm->st != 0) {
        return;
    }
    Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x89, 0);
    Model0218fe1c_SetLoop(self->model);
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    self->fsm->st++;
}
}
}  // namespace m_021fb818

void func_ov012_021fe8b4(Ov012Lift *self, const VecFx32 *p, u8 n);

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov012_Fx2(Ov003Actor *self, s32 id, const Rot16 *base, VecFx32 *v, const VecFx32 *off, s32 scale) {
    EffectObj *o;
    Rot16 r = *base;
    r.y = self->rot_y;
    o = Effect_SpawnId(id, &self->pos);
    Vec_RotateY(v, off, r.y);
    o->SetScaleAll(scale);
    o->AddPos(v);
    o->SetRot(&r);
    o->loopCount = 0;
    return o->id;
}

static inline void Ov012_Finish(Ov012Lift *self) {
    if (self->unk_10c & 0x10) {
        self->unk_10c ^= 0x10;
    }
    if (self->unk_10c & 0x1000000) {
        self->unk_10c ^= 0x1000000;
    }
    self->unk_110 = 0;
    self->unk_10c |= 1;
    History_SetState(self->fsm, 1, 0);
}
static inline void Bec8_S10(Ov012Lift *self, Ov003BeamDef *ent) {
    Ov012SpawnDesc desc;
    Ov003Actor *o;
    self->unk_10c ^= 2;
    Field_ShakeCamera(10, 0xf);
    Ov012Spawn_Init(&desc, 0xffff);
    Ov012Spawn_Set(&desc, 0x4833);
    o = Factory_New4000(&desc);
    if (o != NULL) {
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->rot_x = self->rot_x;
        o->rot_y = self->rot_y;
        o->rot_z = self->rot_z;
        o->beamDef = ent;
        o->unk_1c = self->unk_170;
        o->vfunc_04();
        o->flags_0 = 1;
        o->target = self->target;
        self->target_id = o->id;
    }
    self->fsm->timer = 0;
    self->fsm->st++;
}

static inline void Bec8_S11(Ov012Lift *self, Ov003BeamDef *ent) {
    ActorSub40 *s = self->fsm;
    s->timer++;
    if (s->timer <= ent->duration + 0x28) {
        return;
    }
    self->fsm->timer = 0;
    if ((self->unk_10c & 0x100000) || self->unk_137 >= self->unk_138) {
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x52, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        SndMgr_PlayAt(gSndMgr, 0x500, &self->pos, 0);
        SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
        self->fsm->st = 0x1e;
    } else if (self->unk_10c & 0x200000) {
        self->unk_137++;
        self->fsm->st = 0x14;
    }
}

static inline void Bec8_S14(Ov012Lift *self, Ov003Actor *pl) {
    VecFx32 v4;
    VecFx32 v3;
    u16 t;
    ActorSub40 *s = self->fsm;
    s->timer++;
    t = s->timer;
    if (t <= 0x32) {
        Actor_TurnToActor(self, pl, 0xf6);
    }
    if (t == 0x1e) {
        EffectObj *o = Effect_SpawnId(0x5e0, &self->pos);
        Vec_RotateY(&v3, &data_ov012_0220a420, self->rot_y);
        o->SetScaleAll(0x1800);
        o->AddPos(&v3);
        o->SetRot(&self->rot);
        o->loopCount = 0;
        self->fxId[0] = o->id;
        self->unk_10c |= 2;
        SndMgr_PlayAt(gSndMgr, 0x5b, &self->pos, 0);
    }
    if (self->unk_10c & 2) {
        EffectObj *e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
        if (e != NULL) {
            Vec_RotateY(&v4, &data_ov012_0220a420, self->rot_y);
            VEC_Add(&v4, &self->pos, &v4);
            e->SetPos(&v4);
            e->SetRot(&self->rot);
        }
    }
    if (t >= 0x50) {
        self->fsm->st = 10;
    }
}

static inline void Bec8_S1e(Ov012Lift *self) {
    VecFx32 d2;
    ActorSub40 *s;
    d2.x = self->unk_f4.x - self->pos.x;
    d2.y = self->unk_f4.y - self->pos.y;
    d2.z = self->unk_f4.z - self->pos.z;
    VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
    Actor_TurnToPos(self, &self->unk_100, 0x400);
    s = self->fsm;
    s->timer++;
    if (s->timer <= 100) {
        return;
    }
    if (self->unk_10c & 0x400000) {
        self->unk_10c ^= 0x400000;
    }
    if (self->unk_10c & 0x100000) {
        self->unk_10c ^= 0x100000;
    }
    if (self->unk_10c & 0x200000) {
        self->unk_10c ^= 0x200000;
    }
    self->unk_110 = 0;
    self->unk_137 = 0;
    self->unk_10c |= 1;
    History_SetState(self->fsm, 1, 0);
}

void Ov012Lift_StateAttack(Ov012Lift *self) {
    Ov003Actor *pl;
    s32 idx;
    Ov003BeamDef *ent;
    s32 lim;
    u16 t;
    s32 px;
    pl = Actor_GetTarget(self);
    px = pl->pos.x;
    if (self->unk_10c & 0x100000) {
        idx = 0;
    } else if (self->unk_10c & 0x200000) {
        idx = 1;
    }
    ent = (Ov003BeamDef *)&data_ov012_0220ad40[idx];
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x111, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = self->unk_b0->unk_00;
        if (self->unk_f0 == 0) {
            self->unk_138 = 2;
        } else {
            u16 *hp = self->hp;
            u16 pct = hp[0] * 100 / hp[1];
            if (pct <= 0x19) {
                self->unk_138 = 2;
            } else {
                self->unk_138 = 1;
            }
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if ((self->unk_10c & 0x400000) && (self->unk_10c & 0x200000)) {
            self->unk_10c |= 0x8000000;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1: {
        VecFx32 d0;
        VecFx32 t0;
        VecFx32 d1;
        VecFx32 v1;
        VecFx32 v2;
        s32 x;
        s32 y;
        s32 z;
        ActorSub40 *s;
        s = self->fsm;
        s->timer++;
        t = s->timer;
        x = FLD(s32, self, 0x70);
        y = self->unk_f4.y + 0x14cd;
        z = self->pos.z;
        d0.x = x - self->pos.x;
        d0.y = y - self->pos.y;
        d0.z = z - self->pos.z;
        VEC_MultAdd(0x52, &d0, &self->pos, &self->pos);
        switch (self->unk_f0) {
        case 0:
            lim = 0x5a;
            break;
        case 1:
            lim = 0x46;
            break;
        }
        if (t <= lim) {
            self->unk_b8.x = px;
            self->unk_b8.y = self->pos.y;
            self->unk_b8.z = self->pos.z;
            Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
            t0 = self->unk_b8;
            Actor_MoveToPos(self, &t0, 0);
        } else {
            d1.x = x - self->pos.x;
            d1.y = y - self->pos.y;
            d1.z = z - self->pos.z;
            VEC_MultAdd(0x52, &d1, &self->pos, &self->pos);
        }
        if (t == 0x46) {
            EffectObj *o;
            SndMgr_PlayAt(gSndMgr, 0x502, &self->pos, 0);
            o = Effect_SpawnId(0x5e0, &self->pos);
            Vec_RotateY(&v1, &data_ov012_0220a420, self->rot_y);
            o->SetScaleAll(0x1800);
            o->AddPos(&v1);
            o->SetRot(&self->rot);
            o->loopCount = 0;
            self->fxId[0] = o->id;
            self->unk_10c |= 2;
            SndMgr_PlayAt(gSndMgr, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            EffectObj *e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
            if (e != NULL) {
                Vec_RotateY(&v2, &data_ov012_0220a420, self->rot_y);
                VEC_Add(&v2, &self->pos, &v2);
                e->SetPos(&v2);
                e->SetRot(&self->rot);
            }
        }
        if (t >= 0x78) {
            self->fsm->st = 10;
        }
        break;
    }
    case 10:
        Bec8_S10(self, ent);
        break;
    case 11:
        Bec8_S11(self, ent);
        break;
    case 0x14:
        Bec8_S14(self, pl);
        break;
    case 0x1e:
        Bec8_S1e(self);
        break;
    }
}

void Ov012Lift_StateAttack2(Ov012Lift *self) {
    VecFx32 dd;
    VecFx32 arr_[2];

    VecFx32 v2;
    Ov012SpawnDesc desc;
    VecFx32 v5;
    VecFx32 d2;
    Ov003Actor *pl;
    Ov003BeamDef *tbl;
    u16 kind;
    VecFx32 pp;
    ActorSub40 *s;
    u16 t;
    pl = Actor_GetTarget(self);
    pp = pl->pos;
    if (self->unk_10c & 0x400000) {
        tbl = (Ov003BeamDef *)&data_ov012_0220ad40[4];
        kind = 0x4835;
    } else {
        tbl = (Ov003BeamDef *)&data_ov012_0220ad40[2];
        kind = 0x4834;
    }
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_10c |= 0x800000;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x400, 0);
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (self->unk_10c & 0x400000) {
            self->unk_10c |= 0x10000000;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1: {
        EffectObj *e;
        s->timer++;
        t = s->timer;
        if (t <= 0x5a) {
            Actor_TurnToActor(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            arr_[1].x = x - self->pos.x;
            arr_[1].y = y - self->pos.y;
            arr_[1].z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &arr_[1], &self->pos, &self->pos);
        if (t == 0x28 || t == 0x5a) {
            EffectObj *o = Effect_SpawnId(0x5e0, &self->pos);
            Vec_RotateY(&arr_[0], &data_ov012_0220a420, self->rot_y);
            o->SetScaleAll(0x1800);
            o->AddPos(&arr_[0]);
            o->SetRot(&self->rot);
            o->loopCount = 0;
            self->fxId[0] = o->id;
            self->unk_10c |= 2;
            SndMgr_PlayAt(gSndMgr, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
            if (e != NULL) {
                Vec_RotateY(&v2, &data_ov012_0220a420, self->rot_y);
                VEC_Add(&v2, &self->pos, &v2);
                e->SetPos(&v2);
                e->SetRot(&self->rot);
            }
        }
        if (t >= 0x8c) {
            self->fsm->timer = 0;
            self->fsm->st = 10;
        }
        break;
    }
    case 10:
        s->timer++;
        if (s->timer == 1) {
            Ov003Actor *o;
            self->unk_10c ^= 2;
            Field_ShakeCamera(10, 0x14);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, kind);
            o = Factory_New4000(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
                o->beamDef = tbl;
                o->unk_1c = self->unk_170;
                o->vfunc_04();
                o->flags_0 = 1;
                o->target = self->target;
                self->target_id = o->id;
            }
            self->fxId[0] = Ov012_Fx2(self, 0x68, &data_ov012_0220a3de, &v5, &data_ov012_0220a468, 0x1333);
            SndMgr_PlayAt(gSndMgr, 0x502, &self->pos, 0);
            dd.x = pp.x - self->unk_f4.x;
            dd.y = pp.y - self->unk_f4.y;
            dd.z = pp.z - self->unk_f4.z;
            Vec_RotateY(&dd, &dd, 0xffff - self->rot_y);
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            if (dd.x <= 0) {
                self->unk_124.x = Ov012_FxMul64d(self->unk_124.x, -0x1000);
            }
        } else if (s->timer >= 0x28) {
            if (self->unk_10c & 0x10000000) {
                self->unk_130 = 0x25;
            } else {
                self->unk_130 = 0x29;
            }
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 11: {
        Ov003Actor *o;
        s->timer++;
        t = s->timer;
        o = Ov012_FindActor(self->target_id);
        if (t < tbl->duration) {
            if (self->unk_10c & 0x800000) {
                Actor_TurnToPos(self, &self->unk_124, self->unk_130);
                if (self->rot_y <= 0xe87a && self->rot_y >= 0x1776) {
                    self->unk_10c ^= 0x800000;
                    if (self->unk_10c & 0x10000000) {
                        self->unk_10c |= 0x20000000;
                    }
                }
            } else if (!(self->unk_10c & 0x20000000)) {
                switch (self->unk_f0) {
                case 0:
                    if (o != NULL) {
                        o->unk_1a = 1;
                    }
                    self->fsm->timer = 0;
                    self->fsm->st++;
                    break;
                case 1:
                    self->unk_124.x = Ov012_FxMul64d(self->unk_124.x, -0x1000);
                    if (!(self->unk_10c & 0x10000000)) {
                        self->unk_130 = 0x21;
                    }
                    Actor_TurnToPos(self, &self->unk_124, self->unk_130);
                    self->unk_10c |= 0x800000;
                    break;
                }
            }
            if (o != NULL) {
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
            }
            if (t % 40 == 1) {
                SndMgr_PlayAt(gSndMgr, 0x5c, &self->pos, 0);
            }
        } else if (t == tbl->duration) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 12:
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x52, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        SndMgr_PlayAt(gSndMgr, 0x500, &self->pos, 0);
        SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
        self->fsm->st = 0x1e;
        break;
    case 0x1e:
        d2.x = self->unk_f4.x - self->pos.x;
        d2.y = self->unk_f4.y - self->pos.y;
        d2.z = self->unk_f4.z - self->pos.z;
        VEC_MultAdd(0x66, &d2, &self->pos, &self->pos);
        Actor_TurnToPos(self, &self->unk_100, 0xcd);
        s = self->fsm;
        s->timer++;
        if (s->timer <= 100) {
            return;
        }
        if (self->unk_10c & 0x400000) {
            self->unk_10c ^= 0x400000;
        }
        if (self->unk_10c & 8) {
            self->unk_10c ^= 8;
        }
        if (self->unk_10c & 0x800000) {
            self->unk_10c ^= 0x800000;
        }
        self->unk_110 = 0;
        self->unk_10c |= 1;
        History_SetState(self->fsm, 1, 0);
        break;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Lift *self);
void func_ov012_021fdfa0(Ov012Lift *self);
void Ov012Lift_StateAttack3(Ov012Lift *self) {
    switch (self->unk_f0) {
    case 0:
        func_ov012_021fd708(self);
        break;
    case 1:
        func_ov012_021fdfa0(self);
        break;
    }
}
}

extern "C" {
extern char data_ov012_0220ab21[];
extern const VecFx32 data_ov012_0220a414;
void Ov012Lift_StateShoot(Ov012Lift *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab21, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        SndMgr_PlayAt(gSndMgr, 0xe, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1: {
        u8 i;
        for (i = 0; i < 4; i++) {
            Ov012SpawnDesc d;
            Ov003Actor *o;
            Ov012Spawn_Init(&d, 0xffff);
            Ov012Spawn_Set(&d, 0x480f);
            o = Factory_New4000(&d);
            if (o != NULL) {
                VecFx32 t;
                VEC_Add(&self->pos, &data_ov012_0220a414, &t);
                o->pos = t;
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
                o->unk_18 = i;
                o->target = self->target;
                o->vfunc_04();
                o->flags_0 = 1;
                func_ov000_0219bebc(o, self->unk_170);
                if (o->targetObj != NULL) {
                    o->targetObj->target = self->id;
                }
            }
        }
        SndMgr_PlayAt(gSndMgr, 0x501, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 2:
        s->timer = 0;
        History_SetState(self->fsm, 1, 0);
        self->unk_110 = 0;
        self->unk_10c |= 1;
        break;
    }
}
}

extern "C" {
void Ov012Lift_StateHurt(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        s->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 5) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}
}

extern "C" {
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);


static inline void Ov012_Flash(u8 a, u8 b, u8 c) {
    FieldState *g = gSceneCmd;
    g->cam.base.shakeX = 1;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 1;
    g->cam.base.shakeTime = a;
    g->cam.base.shakeLen = b;
    g->cam.base.shakeCur = c;
}

static inline void Ov012_SetTgt(Ov012Lift *self) {
    s32 y = self->unk_f4.y;
    s32 z = self->unk_f4.z;
    self->unk_100.z = z;
    self->unk_100.x = self->pos.x;
    self->unk_100.y = y + 0x4800;
}
static inline BOOL Ov012_PlBusy(Ov003Actor *pl) {
    return ((Robo021ca458 *)pl)->unk_b24_0 ? TRUE : FALSE;
}

void Ov012Lift_StateDie(Ov012Lift *self) {
    VecFx32 p;
    VecFx32 q;
    VecFx32 s;
    VecFx32 d;
    ActorSub40 *w = self->fsm;
    u16 st = w->st;
    switch (st) {
    case 0: {
        Ov003Actor *o;
        ActorSub48 *m48;
        ActorSub44 *n;
        EffectObj *e;
        ActorMgr_BroadcastKind(gActorMgr, 0x480f, 0x15);
        o = Ov012_FindActor(self->target_id);
        if (o != NULL) {
            o->unk_1a = 1;
        }
        self->hp[0] = 0;
        m48 = self->hit;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += 0x5000;
        self->fxId[0] = Effect_SpawnId(0x390, &p)->id;
        Effect_SpawnId(5, &p)->SetScaleAll(0x5800);
        switch (self->unk_f0) {
        case 0:
            self->unk_114 = 0x3000;
            break;
        case 1:
            self->unk_114 = -0x4000;
            break;
        }
        self->unk_1a = 0x28;
        Ov012_SetTgt(self);
        e = Effect_SpawnId(0x69, &self->pos);
        if (e != NULL) {
            e->SetScaleAll(0x4000);
            e->AddPosXYZ(0, self->centerY, 0);
        }
        SndMgr_PlayAt(gSndMgr, 0x56, &self->pos, 0);
        Field_ShakeCamera(0x19, 0x64);
        self->fsm->st++;
    }
    case 1: {
        u16 t;
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            t = q->timer;
        }
        if (t >= 0x96) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        if (t == 10) {
            func_ov000_02184508(gSceneCmd);
        }
        if (t == 0x1e || t == 0x3c || t == 0x5a || t == 0x78) {
            SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
        }
        break;
    }
    case 2: {
        u16 t;
        w->timer++;
        t = w->timer;
        if (t == 0x32) {
            EffectMgr_Kill(gEffectMgr, self->fxId[0]);
        }
        if (t >= 0x8c) {
            {
                s32 y = self->pos.y;
                s32 z = self->pos.z;
                s32 x = self->pos.x;
                d.x = x - FLD(s32, self, 0x70);
                d.y = (y - 0x11000) - self->pos.y;
                d.z = z - self->pos.z;
            }
            VEC_MultAdd(0xe, &d, &self->pos, &self->pos);
            if (t >= 0x12c) {
                Ov012_Flash(10, 0x3c, 0x3c);
                SndMgr_PlayAt(gSndMgr, 0x56, &self->pos, 0);
                self->fsm->timer = 0;
                self->fsm->st++;
                break;
            }
            if (t % 8 == 0) {
                self->rot_z += 0xb6;
            }
        }
        if (t % 20 == 0) {
            q.x = self->pos.x;
            q.y = self->pos.y;
            q.z = self->pos.z;
            q.y += self->height >> 1;
            s.x = self->radius;
            s.y = self->height >> 2;
            s.z = self->radius;
            Spawn_ScatterEffect(&q, &s, 0x99a, 0x1000, 2, 0x32);
            Ov012_Flash(0x14, 10, 10);
            SndMgr_PlayAt(gSndMgr, 0x35, &self->pos, 0);
        }
        break;
    }
    case 3:
        w->timer++;
        if (w->timer > 0x3c) {
            Ov003Actor_Defeat(self, 1, 1, 1);
            func_ov000_02184548(gSceneCmd);
        } else {
            Ov003Actor_SetAlpha(self, 0x1f - (self->fsm->timer >> 1));
        }
        break;
    }
    if (st < 1) {
        return;
    }
    {
        Ov003Actor *pl = (Ov003Actor *)ActorMgr_FindPlayer();
        FieldCam *cam;
        s16 r;
        if (pl == NULL) {
            return;
        }
        if (Ov012_PlBusy(pl)) {
            return;
        }
        cam = &gSceneCmd->cam;
        r = self->unk_1c;
        if (st == 1) {
            s16 c = self->unk_1a - 1;
            if (c <= 0) {
                self->unk_114 -= 0xb8;
                if (r < 0xb60) {
                    r = r + 0x16;
                    if (r >= 0xb60) {
                        r = 0xb60;
                    }
                    self->unk_1c = r;
                }
            } else {
                self->unk_1a = c;
            }
        } else {
            Ov012_SetTgt(self);
        }
        cam->unk_e8 = self->unk_100;
        cam->unk_da_1 = 1;
        cam->unk_f4 = self->unk_114;
        cam->unk_da_2 = 2;
        cam->unk_f8 = r + 0x5b0;
        cam->unk_da_4 = 1;
    }
}
}

extern "C" {
void func_ov012_021fd708(Ov012Lift *self) {
    VecFx32 pp;
    VecFx32 v4;
    VecFx32 dd;
    VecFx32 d1;
    VecFx32 v1;
    VecFx32 v2;
    VecFx32 v3;
    Ov012SpawnDesc desc;
    VecFx32 v5;
    VecFx32 d12;
    Rot16 r1;
    Rot16 r2;
    Ov003Actor *pl;
    Ov003BeamDef *tbl;
    ActorSub40 *s;
    u16 t;
    pl = Actor_GetTarget(self);
    tbl = (Ov003BeamDef *)&data_ov012_0220ad40[3];
    pp = pl->pos;
    s = self->fsm;
    switch (s->st) {
    case 0:
        self->unk_135 = 0;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x400, 0);
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 1: {
        EffectObj *e;
        s->timer++;
        t = s->timer;
        if (t <= 0xa0) {
            Actor_TurnToActor(self, pl, 0x7b);
        }
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            d1.x = x - self->pos.x;
            d1.y = y - self->pos.y;
            d1.z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &d1, &self->pos, &self->pos);
        r1 = data_ov012_0220a3d8;
        r1.y = self->rot_y;
        r1.z = self->rot_z;
        if (t == 0x28 || t == 0x5a || t == 0x8c) {
            EffectObj *o = Effect_SpawnId(0x5e0, &self->pos);
            Vec_RotateY(&v1, &data_ov012_0220a420, self->rot_y);
            o->SetScaleAll(0x1800);
            o->AddPos(&v1);
            o->SetRot(&self->rot);
            o->loopCount = 0;
            self->fxId[0] = o->id;
            o = Effect_SpawnId(0x68, &self->pos);
            Vec_RotateY(&v2, &data_ov012_0220a420, r1.y);
            o->SetScaleAll(0x4000);
            o->AddPos(&v2);
            o->SetRot(&r1);
            o->loopCount = 0;
            self->fxId[2] = o->id;
            self->unk_10c |= 2;
            SndMgr_PlayAt(gSndMgr, 0x5b, &self->pos, 0);
        }
        if (self->unk_10c & 2) {
            e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
            if (e != NULL) {
                Vec_RotateY(&v3, &data_ov012_0220a420, self->rot_y);
                VEC_Add(&v3, &self->pos, &v3);
                e->SetPos(&v3);
                e->SetRot(&self->rot);
            }
        }
        e = Effect_Find_020657b0(gEffectMgr, self->fxId[2]);
        if (e != NULL) {
            Vec_RotateY(&v4, &data_ov012_0220a420, self->rot_y);
            VEC_Add(&v4, &self->pos, &v4);
            e->SetPos(&v4);
            e->SetRot(&r1);
            if (e->scale.x > 0) {
                s32 a = e->scale.x - 0x333;
                if (a <= 0) {
                    e->state = 4;
                } else {
                    e->SetScaleAll(a);
                }
            }
        }
        if (t >= 0xbe) {
            self->fxId[0] = 0;
            self->fsm->timer = 0;
            self->fsm->st = 10;
        }
        break;
    }
    case 10: {
        EffectObj *e;
        s->timer++;
        if (s->timer == 1) {
            Ov003Actor *o;
            self->unk_10c ^= 2;
            Field_ShakeCamera(0xf, 0x28);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, 0x4836);
            o = Factory_New4000(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
                o->beamDef = tbl;
                o->unk_1c = self->unk_170;
                o->vfunc_04();
                o->flags_0 = 1;
                o->target = self->target;
                self->target_id = o->id;
            }
            self->fxId[0] = Ov012_Fx2(self, 0x68, &data_ov012_0220a3cc, &v5, &data_ov012_0220a468, 0x800);
            SndMgr_PlayAt(gSndMgr, 0x502, &self->pos, 0);
        } else if (s->timer >= 0x28) {
            dd.x = pp.x - self->unk_f4.x;
            dd.y = pp.y - self->unk_f4.y;
            dd.z = pp.z - self->unk_f4.z;
            Vec_RotateY(&dd, &dd, 0xffff - self->rot_y);
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            if (dd.x <= 0) {
                self->unk_134 = 0;
                self->unk_124.x = FX_Mul(self->unk_124.x, -0x1000);
            } else {
                self->unk_134 = 1;
            }
            self->unk_130 = 0xc;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
        if (e != NULL) {
            e->SetScaleAll(e->scale.x + 0x19a);
        }
        break;
    }
    case 11: {
        u16 lim;
        s->timer++;
        lim = tbl->duration;
        t = s->timer;
        if (t <= lim) {
            Ov003Actor *o;
            func_ov012_021fe8b4(self, &pp, 0x1e);
            o = Ov012_FindActor(self->target_id);
            if (o != NULL) {
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
            }
            if (t % 40 == 1) {
                SndMgr_PlayAt(gSndMgr, 0x5c, &self->pos, 0);
            }
        } else if (t > lim + 0x1e) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x52, 0);
            Model0218fe1c_SetLoop(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->timer = 0;
            SndMgr_PlayAt(gSndMgr, 0x500, &self->pos, 0);
            SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
            self->fsm->st++;
        }
        break;
    }
    case 12:
        d12.x = self->unk_f4.x - self->pos.x;
        d12.y = self->unk_f4.y - self->pos.y;
        d12.z = self->unk_f4.z - self->pos.z;
        VEC_MultAdd(0x66, &d12, &self->pos, &self->pos);
        Actor_TurnToPos(self, (u8 *)self + 0x100, 0xcd);
        s = self->fsm;
        s->timer++;
        if (s->timer > 0x64) {
            Ov012_Finish(self);
        }
        break;
    }
}
static inline void Ov012_VecSub(VecFx32 *o, const VecFx32 *a, const VecFx32 *b) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}


void func_ov012_021fdfa0(Ov012Lift *self) {
    VecFx32 tg;
    VecFx32 d;
    u16 lim;
    VecFx32 d2;
    VecFx32 v1;
    VecFx32 v3;
    Ov012SpawnDesc desc;
    VecFx32 v5;
    VecFx32 d14;
    Ov003Actor *pl;
    Ov003BeamDef *tbl;
    ActorSub40 *s;
    u16 t;
    s32 px;
    pl = Actor_GetTarget(self);
    s = self->fsm;
    px = pl->pos.x;
    tbl = (Ov003BeamDef *)&data_ov012_0220ad40[5];
    switch (s->st) {
    case 0:
        self->speed = 0x19a;
        if (px >= 0) {
            self->unk_16e = 0;
        } else {
            self->unk_16e = 1;
        }
        self->unk_135 = 0;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x400, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        tg = self->unk_f4;
        {
            s32 off = 0x5000;
            if (self->unk_16e == 1) off -= 0xa000;
            tg.x += off;
        }
        tg.y = self->pos.y;
        Ov012_VecSub(&d, &tg, &self->pos);
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        {
            s32 x = FLD(s32, self, 0x70);
            s32 y = self->unk_f4.y + 0x14cd;
            s32 z = self->pos.z;
            d2.x = x - self->pos.x;
            d2.y = y - self->pos.y;
            d2.z = z - self->pos.z;
        }
        VEC_MultAdd(0x52, &d2, &self->pos, &self->pos);
        if (Model0218fe1c_IsAnimDone(self->model)) {
            EffectObj *e;
            s = self->fsm;
            s->timer++;
            t = s->timer;
            if (t == 1 || t == 0x32 || t == 0x64) {
                EffectObj *o = Effect_SpawnId(0x5e0, &self->pos);
                Vec_RotateY(&v1, &data_ov012_0220a420, self->rot_y);
                o->SetScaleAll(0x1800);
                o->AddPos(&v1);
                o->SetRot(&self->rot);
                o->loopCount = 0;
                self->fxId[0] = o->id;
                self->unk_10c |= 2;
                SndMgr_PlayAt(gSndMgr, 0x5b, &self->pos, 0);
                if (t == 0x32) {
                    self->unk_10c |= 0x10000000;
                }
            }
            if (self->unk_10c & 2) {
                e = Effect_Find_020657b0(gEffectMgr, self->fxId[0]);
                if (e != NULL) {
                    Vec_RotateY(&v3, &data_ov012_0220a420, self->rot_y);
                    VEC_Add(&v3, &self->pos, &v3);
                    e->SetPos(&v3);
                    e->SetRot(&self->rot);
                }
            }
            if (t >= 0x96) {
                self->fsm->timer = 0;
                self->fsm->st = 10;
            }
        }
        break;
    case 10:
        s->timer++;
        if (s->timer == 1) {
            Ov003Actor *o;
            self->unk_10c ^= 2;
            Field_ShakeCamera(10, 0xf);
            Ov012Spawn_Init(&desc, 0xffff);
            Ov012Spawn_Set(&desc, 0x4837);
            o = Factory_New4000(&desc);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
                o->rot_x = self->rot_x;
                o->rot_y = self->rot_y;
                o->rot_z = self->rot_z;
                o->beamDef = tbl;
                o->unk_1c = self->unk_170;
                o->vfunc_04();
                o->flags_0 = 1;
                o->target = self->target;
                self->target_id = o->id;
            }
            self->fxId[0] = Ov012_Fx2(self, 0x68, &data_ov012_0220a3ea, &v5, &data_ov012_0220a468, 0x1800);
            SndMgr_PlayAt(gSndMgr, 0x502, &self->pos, 0);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 11:
        s->timer++;
        t = s->timer;
        if (t == 0x14) {
            self->unk_10c ^= 0x40000000;
        }
        if (t >= 0x14) {
            Ov003Actor *o;
            tg = self->pos;
            {
                s32 off = 0x3800;
                if (self->unk_16e == 0) off -= 0x7000;
                tg.x = self->unk_f4.x + off;
            }
            self->unk_b8 = tg;
            Actor_MoveToPos(self, &tg, 0);
            o = Ov012_FindActor(self->target_id);
            if (o != NULL) {
                o->pos.x = self->pos.x;
                o->pos.y = self->pos.y;
                o->pos.z = self->pos.z;
            }
        }
        if (t > 0x14 && VEC_Distance(&self->pos, &self->unk_b8) <= 0) {
            self->unk_134 = 1;
            self->unk_130 = 0xc;
            self->unk_124.x = 0x7000;
            self->unk_124.y = 0;
            self->unk_124.z = -0xa000;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 12: {
        Ov003Actor *r = Ov012_FindRes(0x4000, 0x4837);
        if (self->unk_10c & 0x10000000) {
            u16 pct = self->hp[0] * 100 / self->hp[1];
            if (pct <= 0x32) {
                tg.x = 0x3800;
                tg.y = 0;
                tg.z = 0x3000;
                if (self->unk_16e == 0) {
                    tg.x = Ov012_FxMul64d(tg.x, -0x1000);
                }
                func_ov012_021fe8b4(self, &tg, 0x1e);
                if (r != NULL) {
                    r->rot_x = self->rot_x;
                    r->rot_y = self->rot_y;
                    r->rot_z = self->rot_z;
                }
            }
            {
                lim = tbl->duration;
                s = self->fsm;
                s->timer++;
                t = s->timer;
                if (t <= lim - 0x28 && t % 40 == 1) {
                    SndMgr_PlayAt(gSndMgr, 0x5c, &self->pos, 0);
                }
            }
        } else {
            if (r != NULL) {
                r->unk_1a = 1;
            }
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 13:
        s->timer++;
        if (s->timer == 0x46) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x52, 0);
            Model0218fe1c_SetLoop(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->timer = 0;
            SndMgr_PlayAt(gSndMgr, 0x500, &self->pos, 0);
            SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
            self->fsm->st++;
        }
        break;
    case 14:
        if (!(self->unk_10c & 0x10000000)) {
            d14.x = self->unk_f4.x - self->pos.x;
            d14.y = self->unk_f4.y - self->pos.y;
            d14.z = self->unk_f4.z - self->pos.z;
            VEC_MultAdd(0x66, &d14, &self->pos, &self->pos);
            Actor_TurnToPos(self, (u8 *)self + 0x100, 0x400);
            s = self->fsm;
            s->timer++;
            if (s->timer > 0x64) {
                Ov012_Finish(self);
            }
        } else if (Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
        }
        break;
    }
}

}

// ---- merged from ov012_021feacc.cpp
namespace m_021feacc {
extern "C" {

extern u8 data_ov012_0220a4a4[];
extern u8 data_ov012_0220a4a8[];
extern u8 data_ov012_0220a4ac[];
extern u8 data_ov012_0220a4bc[];
extern u8 data_ov012_0220a4c0[];
extern u8 data_ov012_0220a4c4[];


static inline s32 Ov012_FxMulFe8b4(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov012_021fe8b4(Ov012Lift *self, const VecFx32 *p, u8 n) {
    VecFx32 d;
    d.x = p->x - self->pos.x;
    d.y = p->y - self->pos.y;
    d.z = p->z - self->pos.z;
    Vec_RotateY(&d, &d, 0xffff - self->rot_y);
    Actor_TurnToPos(self, (u8 *)self + 0x124, self->unk_130);
    switch (self->unk_134) {
    case 0:
        if (d.x > 0 && !(self->unk_10c & 0x1000000)) {
            if (self->unk_135 == 0) {
                self->unk_135 = n;
            }
            if (--self->unk_135 == 0) {
                self->unk_10c |= 0x1000000;
            }
        }
        if ((self->rot_y < 0xe87a && self->rot_y > 0xbff4) || (self->unk_10c & 0x1000000)) {
            self->unk_124.x = Ov012_FxMulFe8b4(self->unk_124.x, -0x1000);
            self->unk_134 = 1;
            self->unk_135 = 0;
            if (self->unk_10c & 0x1000000) {
                self->unk_10c ^= 0x1000000;
            }
        }
        break;
    case 1:
        if (d.x < 0 && !(self->unk_10c & 0x1000000)) {
            if (self->unk_135 == 0) {
                self->unk_135 = n;
            }
            if (--self->unk_135 == 0) {
                self->unk_10c |= 0x1000000;
            }
        }
        if ((self->rot_y > 0x1776 && self->rot_y < 0x4000) || (self->unk_10c & 0x1000000)) {
            self->unk_124.x = Ov012_FxMulFe8b4(self->unk_124.x, -0x1000);
            self->unk_134 = 0;
            self->unk_135 = 0;
            if (self->unk_10c & 0x1000000) {
                self->unk_10c ^= 0x1000000;
            }
        }
        break;
    }
}

struct Ov012Feacc {
    u8 pad[0x394];
    VecFx32 v[2];
};

void func_ov012_021feacc(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        SndMgr_PlayAt((SndMgr *)gSndMgr, 0x46, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
    case 1: {
        VecFx32 d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4a4, i * 12);
        d.x = tx - ((VecFx32 *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4a8, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4ac, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0x171, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (VecFx32 *)(data_ov012_0220a4a4 + i * 12)) >= 0x4cd) {
            return;
        }
        ((VecFx32 *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        Field_ShakeCamera(7, 0xf);
        if (FLD(u8, self, 0x3af) & 0x10) {
            SndMgr_PlayAt((SndMgr *)gSndMgr, 0x47, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 1) {
                FLD(u8, self, 0x3af) ^= 1;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 2) {
                FLD(u8, self, 0x3af) ^= 2;
            }
            break;
        }
        break;
    }
    }
}

void func_ov012_021fec58(u8 *self, s32 i) {
    switch (FLD(u8, self, 0x3ae)) {
    case 0:
        SndMgr_PlayAt((SndMgr *)gSndMgr, 0x18, &((Ov012Feacc *)self)->v[i], 0);
        FLD(u8, self, 0x3af) |= 0x10;
        FLD(u8, self, 0x3ae)++;
        break;
    case 1:
        if (FLD(u8, self + 0x3ac, i)++ <= 0x14) {
            return;
        }
        if (FLD(u8, self, 0x3af) & 0x10) {
            SndMgr_PlayAt((SndMgr *)gSndMgr, 0x46, &((Ov012Feacc *)self)->v[i], 0);
            FLD(u8, self, 0x3af) ^= 0x10;
        }
        FLD(u8, self + 0x3ac, i) = 0;
        FLD(u8, self, 0x3ae)++;
        break;
    case 2: {
        VecFx32 d;
        s32 tx, ty, tz;
        tx = FLD(s32, data_ov012_0220a4bc, i * 12);
        d.x = tx - ((VecFx32 *)(self + 0x394))[i].x;
        ty = FLD(s32, data_ov012_0220a4c0, i * 12);
        d.y = ty - ((Ov012Feacc *)self)->v[i].y;
        tz = FLD(s32, data_ov012_0220a4c4, i * 12);
        d.z = tz - ((Ov012Feacc *)self)->v[i].z;
        VEC_MultAdd(0xa4, &d, &((Ov012Feacc *)self)->v[i], &((Ov012Feacc *)self)->v[i]);
        if (VEC_Distance(&((Ov012Feacc *)self)->v[i], (VecFx32 *)(data_ov012_0220a4bc + i * 12)) >= 0x2000) {
            return;
        }
        ((VecFx32 *)(self + 0x394))[i].x = tx;
        ((Ov012Feacc *)self)->v[i].y = ty;
        ((Ov012Feacc *)self)->v[i].z = tz;
        switch (i) {
        case 0:
            if (FLD(u8, self, 0x3af) & 4) {
                FLD(u8, self, 0x3af) ^= 4;
            }
            break;
        case 1:
            if (FLD(u8, self, 0x3af) & 8) {
                FLD(u8, self, 0x3af) ^= 8;
            }
            break;
        }
        break;
    }
    }
}

}
}  // namespace m_021feacc

// ---- merged from ov012_021fee1c.cpp
namespace m_021fee1c {
extern "C" {
#pragma force_active on
Ov012Act_021fee1c *Ov012Act_021fee1c_Ctor(Ov012Act_021fee1c *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov012Act_021fee1c_vtbl;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_102 = 0;
    self->unk_104 = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
void Ov012Act_021fee1c_Start(Ov012Act_021fee1c *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    Ov003Actor_Start(self);
    Ov012_ClearOwnerFlag(self);
    Ov012_VecSet(&self->unk_f0, -0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, -0x9000, -0xa000, 0);
    self->rot_y = 0x4000;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a400);
        self->unk_104 = 0x1800;
    }
}
}

extern "C" {
void Ov012Act_021fee1c_HandleMsg(Ov012Act_021fee1c *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_100 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_102 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    Ov003Actor_HandleMsg(self, msg);
}
}

extern "C" {
extern const VecFx32 data_ov012_0220a4a4[];
extern const VecFx32 data_ov012_0220a4bc[];
void Ov012Act_021fee1c_Update(Ov012Act_021fee1c *self) {
    Ov003Actor *pl;
    VecFx32 v;
    s32 a;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    VEC_Distance(&self->pos, &v);
    if (!(self->msg_flags & 0x40)) {
        return;
    }
    switch (((u16)self->unk_100)) {
    case 1:
        self->model->visible = 0;
        self->unk_fc |= 0x100000;
        break;
    case 2:
        if (self->unk_fc & 0x100000) {
            self->unk_fc ^= 0x100000;
        }
        self->model->visible = 1;
        self->unk_f0 = data_ov012_0220a4a4[self->unk_102];
        self->pos = data_ov012_0220a4bc[self->unk_102];
        switch (self->unk_102) {
        case 0:
            a = 1;
            self->rot_y = 0xbff4;
            break;
        case 1:
            a = 2;
            self->rot_y = 0x4000;
            break;
        }
        ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &a);
        break;
    case 4:
        self->model->visible = 1;
        self->fsm->flags |= 0x4000;
        break;
    case 0x10:
        self->fsm->flags = 0;
        self->fsm->flags |= 0x200000;
        break;
    }
    self->unk_100 = 0;
}
}
}  // namespace m_021fee1c

// ---- merged from ov012_021ff674.cpp
namespace m_021ff674 {
extern "C" {
extern const VecFx32 data_ov012_0220a4d4[];
extern const VecFx32 data_ov012_0220a4bc[];
void func_ov012_021ff8b4(Ov012Act_021fee1c *self, s32 idx);

void Ov012Act_021fee1c_StateShoot(Ov012Act_021fee1c *self) {
    s32 off;
    Actor_GetTarget(self);
    off = 0;
    switch (self->unk_102) {
    case 0:
        off = -0x1000;
        break;
    case 1:
        off = 0x1000;
        break;
    }
    switch (self->fsm->st) {
    case 0: {
        Ov003Actor *t;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x1000, 0);
        self->speed = self->unk_b0->unk_00;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        {
            s32 x = self->pos.x + off;
            s32 y = self->pos.y;
            s32 z = self->pos.z;
            Ov012_VecSet(&self->unk_b8, x, y, z);
        }
        t = Ov012_FindRes(0x5000, 0x5c02);
        if (t == NULL) {
            goto st1;
        }
        {
            u16 pct = t->hp[0] * 100 / t->hp[1];
            u16 n;
            if (pct <= 20) {
                self->unk_103 = 10;
                n = 5;
            } else {
                self->unk_103 = 0x28;
                n = 3;
            }
            self->targetObj->unk_1e = n;
        }
        self->fsm->st++;
    }
    case 1:
    st1: {
        VecFx32 v;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab27, 0x400, 0);
        Model0218fe1c_SetAnimDelay(self->model, self->unk_103, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 2: {
        VecFx32 d;
        ActorSub40 *s;
        s32 k = self->targetObj->unk_1e - 1;
        d.x = data_ov012_0220a4d4[k].x;
        d.y = data_ov012_0220a4d4[k].y;
        d.z = data_ov012_0220a4d4[k].z;
        if (self->unk_f0.x >= 0) {
            d.x = FX_Mul(d.x, -0x1000);
        }
        Actor_TurnToPos(self, &d, 0x19a);
        s = self->fsm;
        s->timer++;
        if (s->timer < self->unk_103) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 3:
        func_ov012_021ff8b4(self, self->targetObj->unk_1e);
        self->fsm->st++;
        return;
    case 4: {
        u16 n;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        n = self->targetObj->unk_1e - 1;
        self->targetObj->unk_1e = n;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x400, 0);
        if (n != 0) {
            self->fsm->st = 1;
            return;
        }
        {
            s32 x = self->pos.x - off;
            s32 y = self->pos.y;
            s32 z = self->pos.z;
            Ov012_VecSet(&self->unk_b8, x, y, z);
        }
        self->fsm->st = 10;
        return;
    }
    case 10: {
        VecFx32 v;
        s32 a;
        ActorSub40 *s;
        s = self->fsm;
        s->timer++;
        if (s->timer <= 20) {
            return;
        }
        Actor_TurnToPos(self, (void *)&data_ov012_0220a4bc[self->unk_102], 0x19a);
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
            return;
        }
        switch (self->unk_102) {
        case 0:
            a = 4;
            break;
        case 1:
            a = 8;
            break;
        }
        ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &a);
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}
}

extern "C" {
extern const VecFx32 data_ov012_0220a4bc[];
void Ov012Act_021fee1c_StateDie(Ov012Act_021fee1c *self) {
    s32 off = 0;
    ActorSub40 *s;
    u8 side = self->unk_102;
    switch (side) {
    case 0:
        off = -0x1000;
        break;
    case 1:
        off = 0x1000;
        break;
    }
    s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0:
        ActorMgr_BroadcastKind(gActorMgr, 0x480b, 0x15);
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x400, 0);
        self->unk_b8.y = self->pos.y;
        self->unk_b8.z = self->pos.z;
        self->unk_b8.x = self->pos.x - off;
        self->fsm->st++;
        break;
    case 1:
        if (!(self->unk_fc & 0x100000)) {
            VecFx32 v;
            s32 a;
            Actor_TurnToPos(self, (void *)&data_ov012_0220a4bc[side], 0x19a);
            if (!Model0218fe1c_IsAnimDone(self->model)) {
                return;
            }
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            Actor_MoveToPos(self, &v, 0);
            if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
                return;
            }
            switch (self->unk_102) {
            case 0:
                a = 4;
                break;
            case 1:
                a = 8;
                break;
            }
            ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &a);
            self->fsm->st++;
        } else {
            s->st++;
        }
        break;
    case 2:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 3:
        if (self->unk_fc & 0x100000) {
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
        }
        break;
    }
}
}

extern "C" {
extern const VecFx32 data_ov012_0220a4d4[];
void func_ov012_021ff8b4(Ov012Act_021fee1c *self, s32 idx) {
    Ov012SpawnDesc d;
    VecFx32 v;
    VecFx32 dir;
    u16 r[3];
    Ov003Actor *o;
    Ov012Spawn_Init(&d, 0x480b);
    v.x = 0x99a;
    v.y = 0x1000;
    v.z = 0x2000;
    Vec_RotateY(&v, &v, self->rot_y);
    VEC_Add(&self->pos, &v, &v);
    dir = data_ov012_0220a4d4[idx - 1];
    if (self->unk_f0.x >= 0) {
        dir.x = -dir.x;
    }
    dir.x = dir.x - v.x;
    dir.y = dir.y - v.y;
    dir.z = dir.z - v.z;
    VEC_Normalize(&dir, &dir);
    r[0] = 0;
    r[1] = 0;
    r[2] = 0;
    r[0] = FX_AsinIdx(-dir.y);
    r[1] = FX_Atan2(dir.x, dir.z);
    o = Group_SpawnActor(gGroup, &d, &v, r, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_18 = 6;
    func_ov000_0219bebc(o, self->unk_104);
    o->flags_0 = 1;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
}
}

extern "C" {
#pragma force_active on
Ov012Act_021ffa68 *Ov012Act_021ffa68_Ctor(Ov012Act_021ffa68 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov012Act_021ffa68_vtbl;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_106 = 0;
    self->unk_107 = 0;
    self->unk_fc = 0;
    self->fxList = NULL;
    return self;
}
#pragma force_active reset
}

extern "C" {
Ov012Act_021ffa68 *Ov012Act_021ffa68_Dtor(Ov012Act_021ffa68 *self) {
    *(void **)self = Ov012Act_021ffa68_vtbl;
    Ov012_FreeFx(&self->fxList);
    Ov003Actor_DtorBase(self);
    return self;
}
}

extern "C" {
Ov012Act_021ffa68 *Ov012Act_021ffa68_DtorDelete(Ov012Act_021ffa68 *self) {
    *(void **)self = Ov012Act_021ffa68_vtbl;
    Ov012_FreeFx(&self->fxList);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void Ov012Act_021ffa68_Init(Ov003Actor *self) {
    Ov003Actor_Init(self);
}
}

extern "C" {
BOOL Ov012Act_021ffa68_IsReady(Ov003Actor *self) {
    return Actor_IsReady(self);
}
}

extern "C" {
void Ov012Act_021ffa68_Start(Ov012Act_021ffa68 *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    Ov003Actor_Start(self);
    self->fxList = Ov012_NewFx();
    Ov012_ClearOwnerFlag(self);
    self->unk_ea_6 = 1;
    Ov012_VecSet(&self->unk_f0, 0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, 0x9000, -0xa000, 0);
    self->rot_y = 0xbff4;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a3f0);
    }
}
}

extern "C" {
void Ov012Act_021ffa68_HandleMsg(Ov012Act_021ffa68 *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_104 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        self->unk_106 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    Ov003Actor_HandleMsg(self, msg);
}
}


extern "C" {
extern const VecFx32 data_ov012_0220a4a4[];
void Ov012Act_021ffa68_Update(Ov012Act_021ffa68 *self) {
    VecFx32 v;
    VecFx32 w;
    s32 n;
    s32 n2;
    u8 b;
    Ov003Actor *pl;
    u8 kind;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
    }
    v = pl->pos;
    VEC_Distance(&self->pos, &v);
    kind = self->fsm->current;
    {
        u16 *hp = self->hp;
        u16 mx = self->unk_b0->unk_08;
        if (hp[0] < mx) {
            hp[0] = mx;
        }
    }
    if (self->msg_flags & 0x40) {
        switch (((u16)self->unk_104)) {
        case 1: {
            ActorSub44 *q;
            ActorSub48 *m;
            self->model->visible = 0;
            q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->unk_100 |= 0x200000;
            break;
        }
        case 2: {
            if (self->unk_100 & 0x200000) {
                self->unk_100 ^= 0x200000;
            }
            self->model->visible = 1;
            self->unk_f0 = data_ov012_0220a4a4[self->unk_106];
            self->pos = data_ov012_0220a4bc[self->unk_106];
            n = 3;
            switch (self->unk_106) {
            case 0:
                self->rot_y = 0xbff4;
                break;
            case 1:
                self->rot_y = 0x4000;
                break;
            }
            ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &n);
            break;
        }
        case 4:
            self->model->visible = 1;
            self->unk_100 |= 4;
            self->fsm->flags |= 0x8000;
            break;
        case 8:
            self->model->visible = 1;
            self->unk_100 |= 8;
            self->fsm->flags |= 0x10000;
            break;
        case 0x10:
            self->unk_100 |= 0x1000;
            break;
        }
        self->unk_104 = 0;
    }
    if (self->pos.y <= -0x14000) {
        ActorSub44 *q;
        self->model->visible = 0;
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->targetObj->target = 0xffff;
        n2 = 0xc;
        ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &n2);
        self->unk_100 = 1;
        self->fsm->flags |= 2;
    }
    switch (kind) {
    case 0x14:
        self->unk_100 = 0x800;
        break;
    case 11: {
        Ov003Actor *o = Ov012_FindRes(0x5000, 0x5c02);
        if (o != NULL) {
            w = o->pos;
            VEC_Distance(&self->pos, &w);
            self->unk_100 |= 0x100;
            if (self->unk_100 & 0x200) {
                self->unk_100 ^= 0x200;
            }
            if (self->unk_100 & 0x800) {
                self->unk_100 ^= 0x800;
            }
            self->hit->unk_30 = 0;
        }
        break;
    }
    case 10:
        self->unk_100 |= 0x200;
        b = 1;
        ActorMgr_SendToKindOthers(0x5c02, self->kind, 6, 1, 1, &b);
        break;
    }
    if ((self->unk_100 & 0x200000) && (self->unk_100 & 0x1000)) {
        self->fsm->flags = 0;
        self->fsm->flags |= 0x200000;
    }
    Ov003FxList_Prune(self->fxList);
}
}
}  // namespace m_021ff674

// ---- merged from ov012_02200200.cpp
namespace m_02200200 {
extern "C" {
BOOL func_ov012_02201910(Ov012Act_021ffa68 *self, void *p, s32 a);
void Ov012Act_021ffa68_StateIdle(Ov012Act_021ffa68 *self) {
    u32 f = self->unk_100;
    if ((f & 0x200) || (f & 0x800) || (f & 0x400000)) {
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *m;
            s32 x = 0x3000;
            if (self->unk_106 == 1) {
                x = -0x3000;
            }
            Ov012_VecSet(&self->unk_b8, x, self->pos.y, 0);
            self->unk_107 = 0;
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x111, 0);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->hit->unk_30 = 0;
            self->fsm->st++;
            break;
        }
        case 1:
            if (func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
                if (self->unk_100 & 0x200) {
                    self->unk_100 ^= 0x200;
                }
                if (self->unk_100 & 0x800) {
                    self->unk_100 ^= 0x800;
                }
                if (self->unk_100 & 0x400000) {
                    self->unk_100 ^= 0x400000;
                }
                self->fsm->st = 0;
            }
            break;
        }
    } else if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x111, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
}
}

extern "C" {
BOOL func_ov012_022016d8(Ov012Act_021ffa68 *self, s32 a);

void Ov012Act_021ffa68_StateAttack(Ov012Act_021ffa68 *self) {
    Ov003Actor *pl = Actor_GetTarget(self);
    VecFx32 t;
    VecFx32 v;
    s32 py = pl->pos.y;
    s32 pz = pl->pos.z;
    t = self->unk_f0;
    t.x = FX_Mul(t.x, -0x1000);
    self->unk_ea_0 = 3;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->hit;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.y = py;
        v.z = pz;
        v.x = 0;
        self->unk_b8 = v;
        SndMgr_PlayAt(gSndMgr, 0x601, &self->pos, 0);
        self->unk_107 = 0;
        self->fsm->st++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00 * 2)) {
            return;
        }
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        self->fsm->st++;
        return;
    case 2:
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0 && !Hit_DiffInSphere(&pl->pos, &self->pos, pl->radius + 0x2000)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab2d, 0x111, 0);
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        SndMgr_PlayAt(gSndMgr, 0x600, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    case 3: {
        ActorSub40 *s;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        s = self->fsm;
        s->timer++;
        if (s->timer == 1) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            return;
        }
        if (s->timer == 0x1e) {
            EffectObj *e = Effect_SpawnId(0x12f, &self->pos);
            e->AddPosXYZ(0, 0x800, 0);
            e->SetScaleXYZ(0x800, 0x800, 0x800);
            return;
        }
        if (s->timer < 0x50) {
            return;
        }
        self->unk_100 = 1;
        v.x = 0x3000;
        v.y = 0;
        v.z = 0;
        if (self->unk_106 == 0) {
            v.x = -v.x;
        }
        v.y = self->pos.y;
        self->unk_b8 = v;
        self->unk_107 = 0;
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
        }
        self->unk_94_1 = 1;
        self->fsm->st++;
        return;
    }
    case 4:
        if (!func_ov012_02201910(self, &t, self->unk_b0->unk_00 * 2)) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
}
}

extern "C" {

void Ov012Act_021ffa68_StateAttack2(Ov012Act_021ffa68 *self) {
    VecFx32 v;
    VecFx32 w;
    Actor_GetTarget(self);
    self->unk_ea_0 = 3;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->hit;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        v.x = 0x2800;
        v.y = 0;
        v.z = 0x3800;
        if (self->unk_106 == 1) {
            v.x = FX_Mul(v.x, -0x1000);
        }
        if ((u8)Rand_UpTo(1)) {
            v.z = FX_Mul(v.z, -0x1000);
        }
        self->unk_b8 = v;
        self->unk_107 = 0;
        self->fsm->st++;
    }
    case 1:
        if (!func_ov012_022016d8(self, self->unk_b0->unk_00)) {
            return;
        }
        {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
        }
        self->fsm->st++;
        return;
    case 2:
        v = self->unk_b8;
        Actor_MoveToPos(self, &v, 0);
        w = v;
        w.z = FX_Mul(w.z, -0x1000);
        Actor_TurnToPos(self, &w, 0x19a);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab33, 0x111, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    case 3: {
        u16 t;
        ActorSub40 *s = self->fsm;
        s->timer++;
        t = s->timer;
        if (t > 0x69) {
            self->unk_94_1 = 1;
            if (t != 0x6e) {
                return;
            }
            {
                ActorSub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            self->fsm->timer = 0;
            self->fsm->st++;
            return;
        }
        if (t == 0x14) {
            EffectObj *e = Effect_SpawnId(0x391, &self->pos);
            e->AddPosXYZ(0, 0x1000, 0);
            Ov003FxList_Add(self->fxList, 0, e);
            SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
        }
        if (t == 0x64) {
            EffectObj *e = Effect_SpawnId(0x69, &self->pos);
            e->AddPosXYZ(0, 0x1000, 0);
            e->SetScaleAll(0xb33);
            SndMgr_PlayAt(gSndMgr, 0x601, &self->pos, 0);
        }
        w = self->unk_b8;
        w.z = FX_Mul(w.z, -0x1000);
        Actor_TurnToPos(self, &w, 0x19a);
        return;
    }
    case 4:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->unk_100 = 1;
            v.x = 0x3000;
            v.y = 0;
            v.z = 0;
            if (self->unk_106 == 1) {
                v.x = -v.x;
            }
            v.y = self->pos.y;
            self->unk_b8 = v;
            self->unk_107 = 0;
            {
                ActorSub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            {
                ActorSub48 *m = self->hit;
                m->unk_9a_0 = 0;
                m->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(m);
            }
            self->fsm->st++;
        }
        self->unk_94_1 = 1;
        return;
    case 5:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00)) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
}
}

extern "C" {
extern u16 func_ov000_02199e94(void *p);
extern u8 func_ov000_02199f08(void *p);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, void *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);

struct Ov012HitArg {
    u16 a;
    u8 kind;
    u16 b;
};

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov012_Flash(s32 b) {
    FieldState *g = gSceneCmd;
    u8 c = (b << 1) + 0x14 + b;
    g->cam.base.shakeX = 1;
    g->cam.base.shakeY = 1;
    g->cam.base.shakeZ = 1;
    g->cam.base.shakeTime = b * 2 + 6;
    g->cam.base.shakeLen = c;
    g->cam.base.shakeCur = c;
}

/* The hit result is an enum: the optimizer does not constant-propagate enum-typed
   locals, so `j = hit - 1` stays a subtraction from the register (round lfA). */
typedef enum { OV012_HIT_NONE = 0, OV012_HIT_YES = 1 } Ov012Hit;

void Ov012Act_021ffa68_StateFly(Ov012Act_021ffa68 *self) {
    VecFx32 t;
    VecFx32 hv;
    Ov003Actor *pl;
    s32 k;
    ActorSub40 *s;

    pl = (Ov003Actor *)ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    k = pl->fsm != NULL ? pl->fsm->current : 0;
    if (k == 0x11 || (self->unk_100 & 0x400000)) {
        s = self->fsm;
        switch (s->st) {
        case 0:
            self->hit->unk_30 = 0;
            self->unk_100 |= 0x400000;
            break;
        case 1:
            s->timer = 0;
            break;
        }
        Ov003Actor_StateFly(self);
        return;
    }
    if ((self->unk_100 & 0x200) || (self->unk_100 & 0x800)) {
        s = self->fsm;
        switch (s->st) {
        case 0: {
            ActorSub44 *q = self->unk_44;
            ActorSub48 *m;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            self->hit->unk_30 = 0x40000000;
            m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)m);
            if (self->gravity == 0) {
                self->gravity = 0x52;
            }
            self->fsm->st++;
            break;
        }
        case 1:
            s->timer = 0;
            break;
        }
        Ov003Actor_StateFly(self);
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link((HitSphere *)m);
        self->hit->unk_30 = 0;
        self->fsm->st++;
    }
    case 1: {
        Ov012Hit hit;
        u16 x;
        s32 j;
        Ov003Actor *g;
        ActorSub48 *m;
        ActorSub48 *gm;
        ActorSub4c *p;
        BOOL re;
        if (self->unk_100 & 0x100) {
            Ov003Actor *o = Ov012_FindRes(0x5000, 0x5c02);
            if (o != NULL) {
                s32 d;
                u16 a;
                s32 dx = o->pos.x; dx = self->pos.x - dx;
                s64 sq = (s64)dx * dx;
                s32 dz = o->pos.z; dz = self->pos.z - dz;
                s32 oy = o->pos.y;
                sq += (s64)dz * dz;
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                d = Ov012_Sqrt2(sq);
                a = FX_Atan2(d, oy + 0x3000 - self->pos.y);
                self->speed = Ov012_FxMul64d(OV012_SIN(a), 0x666);
                self->velY = Ov012_FxMul64d(OV012_COS(a), 0x666);
                self->unk_100 ^= 0x100;
            }
        }
        g = NULL;
        if (self->targetObj != NULL) {
            g = (Ov003Actor *)Target_Get(self->targetObj);
        }
        if (g != NULL && self->targetObj->unk_01 == 1) {
            m = self->hit;
            if ((m->unk_50 & 0x60000000) || m->unk_58 != 0) {
                Ov012HitArg arg;
                u8 kind;
                hit = OV012_HIT_NONE;
                x = func_ov000_02199e94(self->targetObj);
                j = hit - 1;
                if (!(self->hit->unk_50 & 0x20000000)) {
                    EffectObj *e = Effect_SpawnId(0x65, &self->pos);
                    // SetRotXYZ through the variadic view: the u16 parameter would truncate hit (the original passes it whole)
                    ((Ov012V *)e)->v34(0x1800, (u16)(self->rot_y + 0x8000), hit);
                    {
                        Ov012_Flash(self->targetObj->unk_1a);
                    }
                    SndMgr_PlayAt(gSndMgr, 0x1a, &self->pos, hit);
                    self->fsm->st = 10;
                }
                if (self->targetObj->unk_03 == 1) {
                    s32 lim = self->radius + 0xccd;
                    if (lim < 0x199a) {
                        lim = 0x199a;
                    }
                    hv.y = self->height >> 1;
                    hv.x = 0;
                    hv.z = 0;
                    hit = (Ov012Hit)Hit_ApplyInArea(self, g, x, self->targetObj->unk_0a, 0x20, &hv, NULL, lim, 0, j, 0x1000);
                }
                kind = 0x40;
                if (self->targetObj->unk_19) {
                    kind = func_ov000_02199f08(self->targetObj);
                    self->unk_100 |= 0x100000;
                }
                arg.a = 0;
                arg.kind = kind;
                arg.b = 0xffff;
                if (hit && kind == 0x41) {
                    g = self;
                }
                if (g != NULL) {
                    Actor_SendMsg(self, g->id, 9, 0, 6, &arg);
                }
                self->targetObj->target = 0xffff;
            }
        }
        gm = NULL;
        Actor_Move(self, 0);
        m = self->hit;
        if (m == NULL) {
            return;
        }
        re = FALSE;
        p = self->targetObj;
        if (p != NULL && p->target != 0xffff && p->unk_01 == 1) {
            Ov003Actor *g2;
            s32 v = self->radius + 0x4cd;
            if (v < 0xccd) {
                v = 0xccd;
            }
            m->unk_44 = v;
            g2 = (Ov003Actor *)Target_Get(self->targetObj);
            if (g2 != NULL && (gm = g2->hit) != NULL && gm->unk_9a_3) {
                gm->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(gm);
                re = TRUE;
            }
        }
        Body_Update(self->hit, 1, 0, 0);
        if (re) {
            gm->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)gm);
        }
        break;
    }
    case 10: {
        ActorSub44 *q;
        ActorSub48 *m;
        EffectObj *e;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x111, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = self->unk_b0->unk_00 * 2;
        self->velY = 0x333;
        self->gravity = 0x52;
        self->unk_b8.x = 0;
        self->unk_b8.y = 0;
        self->unk_b8.z = 0xa000;
        SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
        q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        m = self->hit;
        m->unk_9a_2 = 1;
        m->unk_9a_5 = 1;
        self->targetObj->target = 0xffff;
        e = EffectMgr_FindByKey(gEffectMgr, 0x321);
        if (e != NULL) {
            e->state = 4;
        }
        self->fsm->st++;
        break;
    }
    case 11: {
        ActorSub48 *m;
        EffectObj *o;
        if (self->model->anim_state == 2) {
            Model0218fe1c_SetAnimDelay(self->model, 0x1e, 0);
        }
        t = self->unk_b8;
        Actor_MoveToPos(self, &t, 0);
        Actor_TurnToPos(self, &t, 0x400);
        self->hit->unk_9a_5 = 1;
        Body_Update(self->hit, 1, 0, 0);
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        o = Effect_SpawnId(0x12f, &self->pos);
        o->SetScaleAll(0x800);
        SndMgr_PlayAt(gSndMgr, 0x2a, &self->pos, 0);
        t.x = 0x3000;
        t.y = 0;
        t.z = 0;
        if (self->unk_106 == 1) {
            t.x = -t.x;
        }
        t.y = self->pos.y;
        self->unk_b8 = t;
        self->unk_107 = 0;
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x111, 0);
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
        m = self->hit;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
        self->fsm->st++;
        break;
    }
    case 12:
        if (!func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
            return;
        }
        if (self->unk_100 & 0x100000) {
            self->unk_100 ^= 0x100000;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
}
}
}  // namespace m_02200200

// ---- merged from ov012_022015a0.cpp
namespace m_022015a0 {
extern "C" {
void Ov012Act_021ffa68_StateDown(Ov012Act_021ffa68 *self) {
    ActorSub48 *m;
    Ov003Actor *o;
    self->hit->unk_30 = 0x40000000;
    self->hit->unk_9a |= 0x12;
    Ov003FxList_Kill(self->fxList, 0);
    self->fsm->timer = 0;
    Ov003Actor_StateDown(self);
    if (!(self->unk_100 & 0x100000)) {
        return;
    }
    if (self->fsm->st != 1) {
        return;
    }
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    if (self->unk_100 & 0x100000) {
        self->unk_100 ^= 0x100000;
    }
    self->speed = 0x266;
    self->velY = 0x333;
    o = Ov012_FindRes(0x5000, 0x5c02);
    if (o == NULL) {
        return;
    }
    if (o->hp[0] != 0) {
        return;
    }
    History_SetState(self->fsm, 4, 0);
    self->fsm->st = 10;
}
}

extern "C" {
void Ov012Act_021ffa68_StateDie(Ov003Actor *self) {
    Group_UpdateActor(gGroup, 0, self);
    self->vfunc_08();
}
}

extern "C" {
BOOL func_ov012_022016d8(Ov012Act_021ffa68 *self, s32 spd) {
    VecFx32 v;
    switch (self->unk_107) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x111, 0);
        self->speed = self->unk_b0->unk_00 * 2;
        self->velY = 0x266;
        self->friction = 0;
        self->gravity = 0x52;
        self->unk_107++;
    case 1:
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        if (self->model->anim_state == 1) {
            SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
            self->unk_107++;
        }
        break;
    case 2:
        if (self->model->anim_state == 2) {
            Model0218fe1c_SetAnimDelay(self->model, 0x1e, 0);
        }
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_MoveToPos(self, &v, 0);
        self->hit->unk_9a_5 = 1;
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            Field_ShakeCamera(3, 5);
            Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
            SndMgr_PlayAt(gSndMgr, 0x2a, &self->pos, 0);
            Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x111, 0);
            self->speed = spd;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->unk_107++;
        }
        break;
    case 3:
        self->hit->unk_9a_5 = 0;
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        v.y = self->pos.y;
        self->unk_b8 = v;
        return TRUE;
    }
    return FALSE;
}
}

extern "C" {
BOOL func_ov012_02201910(Ov012Act_021ffa68 *self, const VecFx32 *target, s32 spd) {
    VecFx32 v;
    s32 n;
    self->unk_94_1 = 1;
    switch (self->unk_107) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c4, 0x111, 0);
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = spd;
        self->unk_107++;
    case 1:
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0) {
            break;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220ab1b, 0x111, 0);
        self->speed = self->unk_b0->unk_00 * 2;
        self->velY = 0x59a;
        self->gravity = 0x52;
        self->unk_b8 = *target;
        self->unk_107++;
        break;
    case 2:
        Actor_TurnToPos(self, (void *)target, 0x333);
        if (self->model->anim_state == 1) {
            SndMgr_PlayAt(gSndMgr, 0x29, &self->pos, 0);
            self->unk_107++;
        }
        break;
    case 3:
        if (self->model->anim_state == 2) {
            Model0218fe1c_SetAnimDelay(self->model, 0x1e, 0);
        }
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        Actor_TurnToPos(self, &v, 0x333);
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
            break;
        }
        self->pos = *target;
        Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
        SndMgr_PlayAt(gSndMgr, 0x2a, &self->pos, 0);
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a3c8, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->fsm->timer = 0;
        self->unk_107++;
        break;
    case 4: {
        Ov003Actor *o;
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer <= 10) {
            break;
        }
        n = 0xc;
        ActorMgr_SendToKindOthers(0x5c02, self->kind, 0xe, 1, 4, &n);
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        o = Ov012_FindRes(0x5000, 0x5c02);
        if (o != NULL) {
            if (o->hp[0] == 0) {
                self->model->alpha = 0;
            }
        }
        return TRUE;
    }
    }
    return FALSE;
}
}
}  // namespace m_022015a0
