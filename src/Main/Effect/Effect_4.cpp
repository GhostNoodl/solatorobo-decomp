#include "Main/Effect/Effect.h"

extern "C" {

void func_02065eec(EffectMgr *m) {
    m->head2 = m->head;
    m->count2 = m->count;
    m->head = NULL;
    m->count = 0;
}

void func_02065f0c(EffectMgr *m) {
    EffectMgr_Clear(m);
    m->head = m->head2;
    m->count = m->count2;
    m->head2 = NULL;
    m->count2 = 0;
}

extern u32 data_0208c2e4[];
extern void func_02063a34(EffectObj *obj);
extern struct EffectGroup *func_0206723c(s32 id, const EffectVec *pos);
extern struct Effect3D *func_020674dc(s32 id, const EffectVec *pos);
extern struct EffectGroup *func_02067984(const EffectVec *pos);
extern struct EffectGroup *func_02067b08(s32 id, const EffectVec *pos);
extern EffectObj *func_02067e9c(s32 id, const EffectVec *pos);
extern struct Effect3D *func_02067fd4(s32 id, const EffectVec *pos);
extern struct EffectGroup *func_0206811c(s32 id, const EffectVec *pos);
extern struct EffectGroup *func_02068228(s32 id, const EffectVec *pos);
extern struct EffectGroup *func_02068354(s32 id, const EffectVec *pos);
extern struct Effect3D *func_02066c58(void);
extern struct Effect3D *func_02066df0(void);
extern struct Effect3D *func_02066ec8(void);
extern struct Effect3D *func_02066f90(void);
extern struct Effect3D *func_02066d10(const EffectVec *pos);
extern struct Effect3D *func_02067058(void);
extern struct Effect3D *func_02067120(void);
extern struct EffectGroup *func_020671e8(const EffectVec *pos);

EffectObj *func_02065f88(s32 id, const EffectVec *pos) {
    EffectObj *obj;
    switch (id) {
    case 0x0:
    case 0x1:
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x6:
    case 0x64:
    case 0x65:
    case 0x6a:
    case 0x6c:
    case 0x6d:
    case 0x1f4:
    case 0x1f5:
    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1f9:
    case 0x328:
    case 0x6a4:
        obj = (EffectObj *)func_0206723c(id, pos);
        break;
    case 0x5:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x6b:
    case 0xc9:
    case 0x192:
    case 0x194:
    case 0x195:
    case 0x196:
    case 0x2bd:
    case 0x322:
    case 0x323:
    case 0x324:
    case 0x326:
    case 0x327:
    case 0x384:
    case 0x385:
    case 0x386:
    case 0x387:
    case 0x388:
    case 0x389:
    case 0x391:
    case 0x3e9:
    case 0x3ea:
    case 0x3eb:
    case 0x4b0:
        obj = (EffectObj *)func_020674dc(id, pos);
        break;
    case 0x69:
        obj = (EffectObj *)func_02067984(pos);
        break;
    case 0xc8:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0x12c:
    case 0x12d:
    case 0x12e:
    case 0x12f:
    case 0x130:
    case 0x131:
    case 0x190:
    case 0x193:
    case 0x258:
    case 0x259:
    case 0x25a:
    case 0x25b:
    case 0x25c:
    case 0x25d:
    case 0x25e:
    case 0x25f:
    case 0x260:
    case 0x261:
    case 0x2bc:
    case 0x320:
    case 0x321:
    case 0x325:
    case 0x38a:
    case 0x38b:
    case 0x38c:
    case 0x38d:
    case 0x38e:
    case 0x38f:
    case 0x390:
        obj = (EffectObj *)func_02067b08(id, pos);
        break;
    case 0x191:
        obj = (EffectObj *)func_02067e9c(id, pos);
        break;
    case 0x44c:
    case 0x44d:
    case 0x44e:
    case 0x44f:
        obj = (EffectObj *)func_02067fd4(id, pos);
        break;
    case 0x578:
    case 0x579:
    case 0x57a:
    case 0x57b:
    case 0x57c:
    case 0x57d:
    case 0x57e:
    case 0x57f:
        obj = (EffectObj *)func_0206811c(id, pos);
        break;
    case 0x5dc:
    case 0x5dd:
    case 0x5de:
    case 0x5df:
    case 0x5e0:
    case 0x5e1:
    case 0x5e2:
    case 0x5e3:
    case 0x5e4:
        obj = (EffectObj *)func_02068228(id, pos);
        break;
    case 0x640:
    case 0x641:
    case 0x642:
    case 0x643:
    case 0x644:
    case 0x645:
    case 0x646:
    case 0x647:
    case 0x648:
        obj = (EffectObj *)func_02068354(id, pos);
        break;
    case 0x2710:
        obj = (EffectObj *)func_02066c58();
        break;
    case 0x2711:
        obj = (EffectObj *)func_02066df0();
        break;
    case 0x2712:
        obj = (EffectObj *)func_02066ec8();
        break;
    case 0x2713:
        obj = (EffectObj *)func_02066f90();
        break;
    case 0x2714:
        obj = (EffectObj *)func_02066d10(pos);
        break;
    case 0x2715:
        obj = (EffectObj *)func_02067058();
        break;
    case 0x2716:
        obj = (EffectObj *)func_02067120();
        break;
    case 0x2717:
        obj = (EffectObj *)func_020671e8(pos);
        break;
    default:
        obj = (EffectObj *)func_0203dd9c(0xf8);
        if (obj != NULL) {
            *(u32 **)obj = data_0208c2e4;
            func_02063a34(obj);
        }
        break;
    }
    return obj;
}

}
