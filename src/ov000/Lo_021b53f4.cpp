#include "types.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u8 pad[8];
    void *unk_08;
} Ent021b53f4;

extern "C" {
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);
void func_020434e0(s32 *proj);
void *func_ov000_021b7a7c(FieldProp *n);
void Heap_Free(void *p);
Ent021b53f4 *Lang_GetGroup(u8 id);
void func_0206dfd4(char *buf, u8 *ids);
void ResMgr_ReleaseArchive(void *a, char *buf, s32 c);

void func_ov000_021b53f4(FieldMgr *self) {
    FieldState *pb;
    FieldProp *prev;
    FieldProp *next;
    FieldProp *n;
    GfxSys *d48 = data_02097d48;
    Gfx3DState_SetDefaults(d48->unk_8b0);
    Gfx3DState_Apply(d48->unk_8b0);
    pb = data_ov000_021ccd54;
    func_020434e0(&pb->cam.base.nearClip);
    pb->cam.base.wallClip = 0;
    pb->cam.unk_da = 0;
    pb->cam.unk_d9 = 0;
    if (self->exits != NULL && self->exit != 0xff) {
        func_ov000_021b65ec(self);
    }
    while ((n = self->head) != NULL) {
        prev = n->prev;
        next = n->next;
        if (n != NULL) {
            func_ov000_021b7a7c(n);
            Heap_Free(n);
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            self->head = next;
        }
        if (next != NULL) {
            next->prev = prev;
        } else {
            self->tail = prev;
        }
    }
    if (self->blockB != NULL) {
        FieldState *p = data_ov000_021ccd54;
        u8 *ids = p->unk_d0.c;
        Ent021b53f4 *e;
        char buf[0x20];
        if (ids[0] == 0xff || ids[1] == 0xff || ids[2] == 0xff) {
            ids = p->unk_ca.c;
        }
        e = Lang_GetGroup(ids[0]);
        func_0206dfd4(buf, ids);
        ResMgr_ReleaseArchive(e->unk_08, buf, 0);
        {
            FieldCam *sub = &data_ov000_021ccd54->cam;
            sub->unk_c8 = 0;
            sub->unk_d6 = 0;
        }
        self->blockB = NULL;
    }
    self->exits = NULL;
    {
        FieldState *p = data_ov000_021ccd54;
        if (p->unk_ca.c[0] != p->unk_d0.c[0] || p->unk_ca.c[1] != p->unk_d0.c[1] || p->unk_c9 != 0) {
            func_ov000_021b6994(self, 0);
        }
    }
    self->unk_1f2 = 0;
    self->state = 0;
}

}
