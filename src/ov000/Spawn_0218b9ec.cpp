#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u16 id;
    u16 kind;
    u16 args[4];
    s16 unk_0c;
} Spawn0218b9ec;

typedef struct {
    u8 c[3];
} Rgb0218b9ec;

typedef struct {
    u16 x, y, z;
} Rot0218b9ec;

typedef struct {
    u8 unk_00[0x30];
    Spawn0218b9ec desc;
    Rgb0218b9ec rgb0;
    Rgb0218b9ec rgb1;
    u8 unk_44[0x44];
    VecFx32 pos;
    Rot0218b9ec rot;
} Obj0218b9ec;

extern "C" {
extern void *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd54;
Obj0218b9ec *func_ov000_0218a9d8(void *p);
void func_ov000_0218bbb0(void *mgr, Obj0218b9ec *obj);

Obj0218b9ec *func_ov000_0218b9ec(Spawn0218b9ec *desc, const Rgb0218b9ec *c0, const Rgb0218b9ec *c1, VecFx32 *pos, Rot0218b9ec *rot) {
    Obj0218b9ec *obj = (Obj0218b9ec *)func_0203dd9c(0xa4);
    if (obj != NULL) {
        obj = func_ov000_0218a9d8(obj);
    }
    if (obj != NULL) {
        func_ov000_0218bbb0(data_ov000_021ccd64, obj);
        if (desc != NULL) {
            obj->desc = *desc;
        }
        {
            u8 *g = data_ov000_021ccd54;
            if (c0 != NULL) {
                obj->rgb0 = *c0;
            } else {
                obj->rgb0 = LFLD(Rgb0218b9ec, g, 0xca);
            }
            if (c1 != NULL) {
                obj->rgb1 = *c1;
            } else {
                obj->rgb1 = LFLD(Rgb0218b9ec, g, 0xca);
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
