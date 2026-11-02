#include "ov006/Tasks.h"
#include "nitro/fx.h"

#include "ov006/Racer.h"

extern "C" {

void *Tbl_FindEntry_0206fef8(u16 id);
Model0218fe1c *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(Model0218fe1c *p, void *a, int b, int c);
AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *p, int idx);
void func_ov000_02191920(Model0218fe1c *p, int a, s32 b, int c);
ActorSub48 *ActorSub48_Init(void *p);
void Body_SetOwner(ActorSub48 *p, u16 id);
void HitSphere_Link(void *p);
ActorSub44 *Obj021984c8_Init(void *p);
ActorSub40 *History_Init(void *p);

void Ov006ActVt_021ec4f4_Start(Ov006Racer *self) {
    u8 *info;
    s32 v;
    AnimCtrl *a;
    ov006_Slot *slot;
    slot = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, self->idx);
    self->flags_0 = 1;
    info = (u8 *)Tbl_FindEntry_0206fef8(self->kind);
    self->radius = *(s16 *)(info + 0x14) << 4;
    self->height = *(s16 *)(info + 0x16) << 4;
    self->centerY = self->height >> 1;
    {
        Model0218fe1c *p = (Model0218fe1c *)Heap_Alloc(sizeof(Model0218fe1c));
        if (p != NULL) {
            p = Model0218fe1c_Init(p);
        }
        self->model = p;
        Model0218fe1c_SetRes(p, self->unk_34, 0, 1);
    }
    self->model->actor_id = self->id;
    {
        a = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (a != NULL) {
            self->model->unk_c2 |= 0x40;
            func_ov000_02191920(self->model, 0, 0x1000, 0);
            if (a->cur != NULL) {
                a->cur->frame = 0;
            }
            a->paused = 1;
        }
    }
    Model0218fe1c_SetRes(&self->mdl, self->unk_34, 1, 0);
    self->mdl.actor_id = self->id;
    v = self->radius;
    {
        ActorSub48 *p = (ActorSub48 *)Heap_Alloc(sizeof(ActorSub48));
        if (p != NULL) {
            p = ActorSub48_Init(p);
        }
        self->hit = p;
        Body_SetOwner(p, self->id);
    }
    self->hit->radius = v;
    {
        ActorSub48 *q = self->hit;
        q->unk_9a_0 = 1;
        q->unk_9a |= 8;
        HitSphere_Link(q);
    }
    self->hit->unk_30 = 0xe0000000;
    self->hit->unk_28 = 0x80;
    self->hit->unk_9a |= 0x200;
    {
        ActorSub44 *p = (ActorSub44 *)Heap_Alloc(sizeof(ActorSub44));
        if (p != NULL) {
            p = Obj021984c8_Init(p);
        }
        self->unk_44 = p;
        p->unk_20 = self->id;
    }
    self->unk_44->unk_1c = v;
    {
        ActorSub44 *q = self->unk_44;
        q->unk_22_0 = 1;
        q->unk_22 |= 2;
    }
    {
        ActorSub40 *p = (ActorSub40 *)Heap_Alloc(sizeof(ActorSub40));
        if (p != NULL) {
            p = History_Init(p);
        }
        self->fsm = p;
    }
    self->mode = 1;
    {
        Ov006Marker *p = (Ov006Marker *)Heap_Alloc(sizeof(Ov006Marker));
        if (p != NULL) {
            p = Ov006Vt_021ec28c_Ctor(p);
        }
        self->marker = p;
        Ov006Marker_Load(p);
    }
    Ov006Marker_SetFrame(self->marker, self->idx, slot->type == 0);
    {
        Ov006Marker *q = self->marker;
        s32 z = q->ofs.z;
        q->ofs.x = 0;
        q->ofs.y = -0x6000;
        q->ofs.z = z;
    }
    self->look.x = self->rot_x;
    self->look.y = self->rot_y;
    self->look.z = self->rot_z;
    self->look2.x = self->rot_x;
    self->look2.y = self->rot_y;
    self->look2.z = self->rot_z;
    self->courseRot.x = 0;
    self->courseRot.y = 0;
    self->courseRot.z = 0;
    {
        Ov006RacerPt *b;
        Ov006RacerPt *a;
        a = self->pts + self->lastPt;
        b = self->pts + self->nextPt;
        if (a != NULL && b != NULL) {
            s32 dx;
            s32 dz;
            s64 sq;
            self->courseRot.y = FX_Atan2(b->pos.x - a->pos.x, b->pos.z - a->pos.z);
            dx = a->pos.x - b->pos.x;
            dz = a->pos.z - b->pos.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            REG_SQRT_PARAM = (u64)(sq * 4);
            while (REG_SQRTCNT & 0x8000) {
            }
            self->courseRot.x = -FX_Atan2(b->pos.y - a->pos.y, (s32)(REG_SQRT_RESULT + 1) >> 1);
        }
    }
}

}
