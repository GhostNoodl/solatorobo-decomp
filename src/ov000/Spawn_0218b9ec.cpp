#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"

typedef struct {
    u16 id;
    u16 kind;
    u16 args[4];
    s16 unk_0c;
} Spawn0218b9ec;

typedef struct {
    u16 x, y, z;
} Rot0218b9ec;

typedef struct {
    u8 unk_00[0x30];
    Spawn0218b9ec desc;
    FieldId rgb0;
    FieldId rgb1;
    u8 unk_44[0x44];
    VecFx32 pos;
    Rot0218b9ec rot;
} Obj0218b9ec;

extern "C" {
extern void *data_ov000_021ccd64;
Obj0218b9ec *func_ov000_0218a9d8(void *p);
void Group_Add(void *mgr, Obj0218b9ec *obj);

Obj0218b9ec *func_ov000_0218b9ec(Spawn0218b9ec *desc, const FieldId *c0, const FieldId *c1, VecFx32 *pos, Rot0218b9ec *rot) {
    Obj0218b9ec *obj = (Obj0218b9ec *)Heap_Alloc(0xa4);
    if (obj != NULL) {
        obj = func_ov000_0218a9d8(obj);
    }
    if (obj != NULL) {
        Group_Add(data_ov000_021ccd64, obj);
        if (desc != NULL) {
            obj->desc = *desc;
        }
        {
            FieldState *g = data_ov000_021ccd54;
            if (c0 != NULL) {
                obj->rgb0 = *c0;
            } else {
                obj->rgb0 = g->unk_ca;
            }
            if (c1 != NULL) {
                obj->rgb1 = *c1;
            } else {
                obj->rgb1 = g->unk_ca;
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
