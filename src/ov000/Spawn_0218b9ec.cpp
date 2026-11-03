#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

extern "C" {
extern Group *gGroup;

GroupNode *func_ov000_0218b9ec(GroupActorDesc *desc, const FieldId *c0, const FieldId *c1, VecFx32 *pos, Rot16 *rot) {
    GroupNode *obj = (GroupNode *)Heap_Alloc(sizeof(GroupNode));
    if (obj != NULL) {
        obj = GroupNode_Init(obj);
    }
    if (obj != NULL) {
        Group_Add(gGroup, obj);
        if (desc != NULL) {
            obj->spawn = *desc;
        }
        {
            FieldState *g = gSceneCmd;
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
