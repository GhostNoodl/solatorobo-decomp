#include "ov000/CmdObj.h"
#include "ov000/LoCommon.h"

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

typedef struct {
    u8 pad_00[8];
    void (*unk_08)(void);
    void (*unk_0c)(void);
    void (*unk_10)(void);
} Data021ccd50;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Flags021ccd44;

extern "C" {
extern u8 data_02097d78;
extern u8 *data_ov000_021ccd30;
extern void *data_02149ef8;
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0206c620(void *p);
BOOL func_0205a9c8(void *p);
void func_0205aa30(void *p);
BOOL func_ov000_021820bc(void *p, s32 a);
void func_ov000_0214ba18(void);
BOOL func_ov000_0214bb04(void);
void func_ov000_0214bb2c(void);
void func_ov000_0214bb5c(void);
void func_ov000_0214baa8(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_0217060c(void *p);
void func_ov000_02172390(void *mgr, s32 a, void *b);
void *func_0204c0e8(void *p, s32 a);
s32 func_02061d54(s32 a);
s32 func_02062834(void);
s32 func_ov000_02184a1c(CmdObj *self, s32 arg);
extern void *data_02097e4c;
extern void *data_02097e44;
extern Obj02097e48 *data_02097e48;
extern void *data_0214a424;
extern void *data_ov000_021ccd68;
extern Flags021ccd44 *data_ov000_021ccd44;
extern Data021ccd50 data_ov000_021ccd50;
void func_02049564(void *p, s32 a, s32 b);
void func_0206c72c(void *p, s32 a);
u8 *func_ov000_0219bf90(void);
BOOL func_ov000_0218e470(void *p);
void func_ov000_02180660(s32 a, s32 b);
void func_ov000_02180754(void);
BOOL func_02046e28(void *p);
void func_02049678(void *p, s32 a, s32 b, s32 c);
BOOL func_0204985c(void *p);
void func_ov000_02187564(void);
void func_ov000_02187570(void);
void func_ov000_0218757c(void);
void func_ov000_0214b438(void);
BOOL func_ov000_0214b540(void);

static inline BOOL MsgDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL MgrBusy(void);

s32 func_ov000_02184be8(CmdObj *self) {
    switch (self->unk_a4 / 100) {
    case 0:
        func_ov000_02184a1c(self, self->unk_a4);
        break;
    case 1:
        switch (self->step) {
        case 0:
            func_ov000_02180660(4, self->unk_a4);
            self->step++;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 2:
        switch (self->step) {
        case 0:
            func_ov000_02180660(0xb, self->unk_a4);
            self->step++;
            break;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    case 3:
        switch (self->step) {
        case 0:
            func_ov000_02180660(4, self->unk_a4);
            self->step++;
            break;
        case 1:
            if (MsgDone()) {
                func_ov000_02180754();
                CmdObj_Done(self);
            }
            break;
        }
        break;
    default:
        CmdObj_Done(self);
        break;
    }
    return 1;
}

}
