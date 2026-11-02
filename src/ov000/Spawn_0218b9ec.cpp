#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

extern "C" {
extern Group *data_ov000_021ccd64;

GroupNode *func_ov000_0218b9ec(GroupActorDesc *desc, const FieldId *c0, const FieldId *c1, VecFx32 *pos, Rot16 *rot) {
    GroupNode *obj = (GroupNode *)Heap_Alloc(sizeof(GroupNode));
    if (obj != NULL) {
        obj = func_ov000_0218a9d8(obj);
    }
    if (obj != NULL) {
        Group_Add(data_ov000_021ccd64, obj);
        if (desc != NULL) {
            obj->spawn = *desc;
        }
        {
            FieldState *g = data_ov000_021ccd54;
            if (c0 != NULL) {
                obj->fieldId = *c0;
            } else {
                obj->fieldId = g->unk_ca;
            }
            if (c1 != NULL) {
                obj->fieldFilter = *c1;
            } else {
                obj->fieldFilter = g->unk_ca;
            }
        }
        if (pos != NULL) {
            obj->pos = *pos;
        }
        if (rot != NULL) {
            obj->rot = *rot;
        }
    }
    return obj;
}
}
