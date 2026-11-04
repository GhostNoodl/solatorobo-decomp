#include "Main/Effect/EffectInt.h"

extern "C" {

void EffectMgr_SaveList(EffectMgr *m) {
    m->head2 = m->head;
    m->count2 = m->count;
    m->head = NULL;
    m->count = 0;
}

void EffectMgr_RestoreList(EffectMgr *m) {
    EffectMgr_Clear(m);
    m->head = m->head2;
    m->count = m->count2;
    m->head2 = NULL;
    m->count2 = 0;
}

extern u32 EffectObj_vtbl[];
extern void EffectObj_Register(EffectObj *obj);
extern struct EffectGroup *Effect_SpawnGroupById(s32 id, const VecFx32 *pos);
extern struct Effect3D *Effect_Spawn3DById(s32 id, const VecFx32 *pos);
extern struct EffectGroup *Effect_SpawnRingBurst(const VecFx32 *pos);
extern struct EffectGroup *Effect_SpawnGroup12c(s32 id, const VecFx32 *pos);
extern EffectObj *Effect_Spawn191(s32 id, const VecFx32 *pos);
extern struct Effect3D *Effect_Spawn3D44c(s32 id, const VecFx32 *pos);
extern struct EffectGroup *Effect_SpawnGroup578(s32 id, const VecFx32 *pos);
extern struct EffectGroup *Effect_SpawnGroup5dc(s32 id, const VecFx32 *pos);
extern struct EffectGroup *Effect_SpawnGroup640(s32 id, const VecFx32 *pos);
extern struct Effect3D *EffectHud_New2714(const VecFx32 *pos);
extern struct EffectGroup *EffectGroup_New2717(const VecFx32 *pos);

EffectObj *Effect_SpawnId(s32 id, const VecFx32 *pos) {
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
        obj = (EffectObj *)Effect_SpawnGroupById(id, pos);
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
        obj = (EffectObj *)Effect_Spawn3DById(id, pos);
        break;
    case 0x69:
        obj = (EffectObj *)Effect_SpawnRingBurst(pos);
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
        obj = (EffectObj *)Effect_SpawnGroup12c(id, pos);
        break;
    case 0x191:
        obj = (EffectObj *)Effect_Spawn191(id, pos);
        break;
    case 0x44c:
    case 0x44d:
    case 0x44e:
    case 0x44f:
        obj = (EffectObj *)Effect_Spawn3D44c(id, pos);
        break;
    case 0x578:
    case 0x579:
    case 0x57a:
    case 0x57b:
    case 0x57c:
    case 0x57d:
    case 0x57e:
    case 0x57f:
        obj = (EffectObj *)Effect_SpawnGroup578(id, pos);
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
        obj = (EffectObj *)Effect_SpawnGroup5dc(id, pos);
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
        obj = (EffectObj *)Effect_SpawnGroup640(id, pos);
        break;
    case 0x2710:
        obj = (EffectObj *)EffectHud_New2710();
        break;
    case 0x2711:
        obj = (EffectObj *)EffectHud_New2711();
        break;
    case 0x2712:
        obj = (EffectObj *)EffectHud_New2712();
        break;
    case 0x2713:
        obj = (EffectObj *)EffectHud_New2713();
        break;
    case 0x2714:
        obj = (EffectObj *)EffectHud_New2714(pos);
        break;
    case 0x2715:
        obj = (EffectObj *)EffectHud_New2715();
        break;
    case 0x2716:
        obj = (EffectObj *)EffectHud_New2716();
        break;
    case 0x2717:
        obj = (EffectObj *)EffectGroup_New2717(pos);
        break;
    default:
        obj = (EffectObj *)Heap_Alloc(0xf8);
        if (obj != NULL) {
            *(u32 **)obj = EffectObj_vtbl;
            EffectObj_Register(obj);
        }
        break;
    }
    return obj;
}

}
