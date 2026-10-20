#include "Main/Res/StageRes.h"

extern "C" {

extern void func_0205ae68(void);
extern u16 func_0205ae7c(StageRes *res);
extern void func_0205beb0(void);
extern void func_0205bec8(u16 id);
extern void func_0205bee4(void);
extern int func_0205bf70(StageResSlot *slot);
extern int func_0205c37c(StageResSlot *slot);
extern int func_0205c490(StageResSlot *slot);
extern int func_0205c5c4(StageResSlot *slot);
extern int func_0205c624(StageResSlot *slot);
extern int func_0205de88(StageResSlot *slot);
extern int func_0205e19c(StageResSlot *slot);
extern int func_0205e29c(StageResSlot *slot);
extern int func_0205eda0(StageResSlot *slot);
extern int func_0205f354(StageResSlot *slot);
extern int func_0205f978(StageResSlot *slot);
extern int func_020616b0(StageResSlot *slot);
extern int func_02061c8c(StageResSlot *slot);
extern s32 func_02040498(s32 max);
extern u16 func_0205b3cc(StageRes *res, u16 id, u32 argc, u16 *cmd);
extern StageResSlot *func_0205b378(BOOL pop);

void func_0205b8c4(void) {
    data_02149efc.unk_00++;
}

u16 func_0205b8dc(StageRes *res, u16 *cmd) {
    u16 op = cmd[1];
    u16 argc = (op & 0xff00) >> 8;
    u16 len = 1;
    if (op == 0xff) {
        res->unk_59 = 1;
        return 2;
    }
    if (op == 0xf3) {
        res->unk_5a = 1;
        return 2;
    }
    func_0205b8c4();
    if (data_02fe1534.unk_00 == 1) {
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205b378(TRUE);
        return len;
    }
    switch (op) {
    case 0x100:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)data_02fe1534.unk_02 = func_0205ae7c(res);
        break;
    case 0x101:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)&data_02fe1534.unk_08[0] = func_0205ae7c(res);
        *(u16 *)&data_02fe1534.unk_08[2] = 0;
        break;
    case 0x102:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205bf70(func_0205b378(TRUE));
        break;
    case 0x209:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c37c(NULL);
        break;
    case 0x20a:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c490(NULL);
        break;
    case 0x20c:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c5c4(func_0205b378(TRUE));
        break;
    case 0x20e:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c624(func_0205b378(TRUE));
        break;
    case 0x11:
        len++;
        func_0205beb0();
        break;
    case 0x23a:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205e19c(func_0205b378(TRUE));
        break;
    case 0x43b:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205e29c(func_0205b378(TRUE));
        break;
    case 0x243:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205eda0(func_0205b378(TRUE));
        break;
    case 0x347:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205f354(func_0205b378(TRUE));
        break;
    case 0x14c:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205f978(func_0205b378(TRUE));
        break;
    case 0x32:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        break;
    case 0x136:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205de88(func_0205b378(TRUE));
        break;
    case 0x17d:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205bec8(func_0205b378(TRUE)->args[0]);
        break;
    case 0x16f:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_020616b0(func_0205b378(TRUE));
        break;
    case 0x280:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_02061c8c(func_0205b378(TRUE));
        break;
    case 0x1f0:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)data_02fe1534.unk_7e = func_02040498(func_0205ae7c(res));
        break;
    case 0xf1:
        len++;
        func_0205bee4();
        break;
    case 0xf2:
        len++;
        func_0205ae68();
        break;
    default:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        break;
    }
    if (op == 0x237 || op == 0x27f) {
        res->unk_5a = 1;
    }
    return len;
}

}
