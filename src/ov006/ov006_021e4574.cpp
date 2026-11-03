#include "ov006/Model.h"
#include "ov000/ObjLayouts.h"
#include "Main/Net/Wh.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern void *ov006_MenuNode_vtbl;
extern u8 data_ov006_021eb840[];

u16 func_02046ab4(ov006_Unk02097e40 *a);
BOOL Wh_SetEntry(ov006_Unk02097e40 *a, BOOL enabled);
int ov006_Menu_NextUniqueId(ov006_Menu *self);

void ov006_Menu_DrawHolder(ov006_Menu *self) {
    ov006_ModelHolder *holder;

    if (gOv006Menu->state == 0 || (holder = self->unk1D4) == NULL) {
        return;
    }
    if (holder->unkC >= 4) {
        return;
    }
    if (holder->model == NULL) {
        return;
    }
    ov006_Model_SetPos(holder->model, holder->unk8, 0x76000, 0x46000);
    Model_PlayPart(holder->model, holder->unkC);
}

void ov006_Menu_ReleaseObj(ov006_Menu *self) {
    Lo021cad50 *obj;
    if (gOv006Menu->state != 0 && (obj = self->unk1D8->obj) != NULL) {
        obj->vfunc_20();
    }
}

int ov006_Menu_NextUniqueId(ov006_Menu *self) {
    int id = self->unk30;
    BOOL unique;
    do {
        unique = TRUE;
        if (id == 0) {
            unique = FALSE;
            id++;
        } else {
            ov006_MenuNode *node;
            for (node = self->nodes; node != NULL; node = node->next) {
                if (id == node->id) {
                    unique = FALSE;
                    id++;
                    break;
                }
            }
        }
    } while (!unique);
    self->unk30 = (u16)(id + 1);
    return id;
}

}
