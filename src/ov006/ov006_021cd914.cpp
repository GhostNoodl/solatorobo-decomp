#include "ov006/Tasks.h"

extern "C" {

extern void *data_02fe152c;
extern u8 *data_ov000_021ccd54;
extern const char data_ov006_021ebb91[];
extern const char data_ov006_021ebb94[];
extern const char data_ov006_021ebb9b[];
extern const char data_ov006_021ebba0[];

void func_ov006_021db65c(void);
ov006_SlotManagerInfo *func_ov006_021daaa8(u32 id);
void func_ov006_021daf80(ov006_SlotManager *self);
ov006_Slot *func_ov006_021dafb4(ov006_SlotManager *self, int idx, int type, const char *name, u16 unk12);
void func_ov006_021dab74(ov006_Slot *self, const ov006_SlotSub *src);
void func_ov006_021daba0(ov006_Slot *self, const ov006_SlotSub *src);
u16 func_020594bc(void *res, int a, int b, u32 idx);
void func_020592c4(void *res, int a, int b, u32 idx, u16 v);
void func_020627fc(u8 v);
void func_0206280c(u16 v);
void func_ov000_02182590(u8 *p);

static inline void ov006_SetInfo(u16 id) {
    ov006_SlotManagerInfo *info = func_ov006_021daaa8(id);
    ov006_SlotManager *m = data_ov006_021ec884;
    m->unk6 = id;
    m->unk8 = info;
}

static inline u32 ov006_RecordIdx(void) {
    u32 idx = 0xffff;
    switch (data_ov006_021ec860->unk14) {
    case 2:
        idx = 3;
        break;
    case 4:
    case 5:
        idx = 2;
        break;
    case 6:
        idx = 5;
        break;
    case 7:
        idx = 6;
        break;
    }
    return idx;
}

void func_ov006_021cd914(int type, void *obj, int arg) {
    ov006_Slot *slot;
    switch (type) {
    case 1:
        data_ov006_021ec860->taskType = 1;
        switch (data_ov006_021ec860->unk14) {
        case 0:
        case 1:
        default:
            func_ov006_021db65c();
            ov006_SetInfo(0xb005);
            break;
        case 2:
            func_ov006_021dafb4(data_ov006_021ec884, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7002;
            data_ov006_021ec884->unk5 = 0;
            func_ov006_021daf80(data_ov006_021ec884);
            ov006_SetInfo(0xb006);
            break;
        case 3:
            func_ov006_021dafb4(data_ov006_021ec884, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7000;
            func_ov006_021dafb4(data_ov006_021ec884, 1, 0, data_ov006_021ebb94, 0xff)->unkC = 0x7005;
            data_ov006_021ec884->unk5 = 0;
            func_ov006_021daf80(data_ov006_021ec884);
            ov006_SetInfo(0xb007);
            break;
        case 4:
        case 5:
            func_ov006_021db65c();
            slot = func_ov006_021dafb4(data_ov006_021ec884, 0, 1, data_ov006_021ebb91, 0xff);
            slot->unkC = data_ov006_021ec860->unk14 == 4 ? 0x7003 : 0x7001;
            slot = func_ov006_021dafb4(data_ov006_021ec884, 1, 0, data_ov006_021ebb9b, 0xff);
            slot->unkC = data_ov006_021ec860->unk14 == 4 ? 0x700d : 0x700e;
            ov006_SetInfo(0xb008);
            break;
        case 6:
            func_ov006_021dafb4(data_ov006_021ec884, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7000;
            func_ov006_021dafb4(data_ov006_021ec884, 1, 0, data_ov006_021ebba0, 0xff)->unkC = 0x700c;
            data_ov006_021ec884->unk5 = 0;
            func_ov006_021daf80(data_ov006_021ec884);
            ov006_SetInfo(0xb009);
            break;
        case 7:
            func_ov006_021db65c();
            ov006_SetInfo(0xb00a);
            break;
        }
        break;
    case 7: {
        u32 idx = 0xffff;
        u16 v = 0x2a30;
        switch (data_ov006_021ec860->unk14) {
        case 2:
            idx = 3;
            data_ov006_021ec884->unk13C = 0;
            data_ov006_021ec884->unk140 = 0;
            break;
        case 4:
        case 5:
            idx = 2;
            data_ov006_021ec884->unk13C = 0;
            data_ov006_021ec884->unk140 = 0;
            break;
        case 6:
            idx = 5;
            data_ov006_021ec884->unk13C = 0;
            data_ov006_021ec884->unk140 = 0;
            break;
        case 7:
            idx = 6;
            data_ov006_021ec884->unk13C = 0;
            data_ov006_021ec884->unk140 = 0;
            break;
        default:
            data_ov006_021ec884->unk13C = 0;
            data_ov006_021ec884->unk140 = 0;
            break;
        }
        if (idx != 0xffff) {
            v = func_020594bc(data_02fe152c, 4, 0x10, idx);
        }
        data_ov006_021ec884->unk144 = v;
        break;
    }
    case 8:
        if (arg == 2) {
            ov006_SlotSub sub;
            u8 i;
            data_ov006_021ec860->taskType = 1;
            data_ov006_021ec860->unk20 = 0;
            data_ov006_021ec884->unk13D = 0;
            sub.unk0 = 0;
            sub.unk2 = 0;
            sub.unk3 = 0;
            sub.unk4 = 0;
            sub.unk8 = 0;
            sub.unkC = 0;
            for (i = 0; i < 4; i++) {
                func_ov006_021dab74(func_ov006_021db060(data_ov006_021ec884, i), &sub);
                func_ov006_021daba0(func_ov006_021db060(data_ov006_021ec884, i), &sub);
            }
        } else {
            u8 b;
            u32 n;
            u8 c;
            u16 n16;
            ov006_SlotManager *m;
            data_ov006_021ec860->taskType = 3;
            m = data_ov006_021ec884;
            n = m->unk140;
            b = m->unk148;
            c = m->unk13E;
            if (n > 0xffff) {
                n = 0xffff;
            }
            n16 = n;
            if (b == 2) {
                u32 idx = ov006_RecordIdx();
                if (idx != 0xffff) {
                    func_020592c4(data_02fe152c, 4, 0x10, idx, n16);
                }
            }
            func_020627fc(c);
            func_0206280c(n16);
            {
                u8 *p = data_ov000_021ccd54 + 0xac;
                *p = 1;
                func_ov000_02182590(p);
            }
        }
        break;
    }
}

}
