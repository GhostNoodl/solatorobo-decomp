#include "Main/Res/StageCmd.h"

extern "C" {

int func_0205e818(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        } else {
            StageObj3D *o = Stage_FindObj3DPtr(slot->args[0]);
            if (o != NULL) {
                o->Remove();
            }
        }
    }
    return 1;
}

void func_0205e958(StageLight *light) {
    light->state = 3;
}

int func_0205e964(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], slot->args[1] & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        } else {
            StageObj3D *o = Stage_FindObj3DPtr(slot->args[0]);
            if (o != NULL) {
                o->Remove();
            }
        }
    }
    return 1;
}

int func_0205ea9c(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    if (func_ov000_0218bddc(data_ov000_021ccd64, slot->args[0], slot->args[2] & 0xff) == NULL) {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], slot->args[1] & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        }
    }
    return 1;
}

int func_0205ebb0(StageResSlot *slot) {
    StageObj3D *o;
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        u16 idx = slot->args[1];
        u16 kind = id & 0xf000;
        if (idx == 0xffff) {
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = (StageObj3D *)func_ov000_0218e6d0(data_ov000_021ccd68, kind, id);
            }
        } else {
            StageArea *area = (StageArea *)(slot->res->posEv->ev + idx * 12);
            StageVec pos;
            s32 r;
            pos.x = area->x << 4;
            pos.y = area->y << 4;
            pos.z = area->z << 4;
            r = area->w << 4;
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e750(data_ov000_021ccd68, kind, id, &pos, r);
            }
        }
    }
    data_02fe1534.unk_26 = o->unk_0c;
    return 1;
}

int func_0205ecd8(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    Stage_FindObj(slot->args[0], slot->args[1]);
    return 1;
}

int func_0205eda0(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        u16 b = slot->args[1];
        if (id != 0) {
            data_02149efc.unk_14 = Stage_FindObj3D(id);
            data_02149efc.unk_04 = Stage_FindLight1(id, b);
            if (data_02149efc.unk_04 == NULL) {
                data_02149efc.unk_04 = Stage_FindLight2(id, b);
            }
        }
    }
    if (data_02149efc.unk_14 != NULL || data_02149efc.unk_04 != NULL) {
        data_02fe1534.unk_80 = 1;
    } else {
        data_02fe1534.unk_80 = 0;
    }
    return 1;
}

int func_0205eeb4(StageResSlot *slot) {
    u8 color[3];
    s16 rot[3];
    StageVec pos;
    StageRes *res;
    if (data_02149efc.unk_04 == NULL) {
        return 1;
    }
    res = slot->res;
    color[0] = slot->args[0];
    color[1] = slot->args[1];
    color[2] = slot->args[2];
    if (slot->args[3] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(slot->args[3] & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    }
    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    if (slot->args[4] != 0xffff) {
        if (slot->args[4] & 0x8000) {
            rot[1] = ((s16 *)(res->posEv->pos + (u16)(slot->args[4] & 0x7fff) * 6))[1];
        } else {
            rot[1] = (s32)(((s64)FX_Div(slot->args[4] << 12, 0x168000) * 0x10000000 + 0x800) >> 12) >> 12;
        }
    }
    func_ov000_0218b60c(data_02149efc.unk_04, color, &pos, rot);
    return 1;
}

int func_0205eff8(StageResSlot *slot) {
    StageVec pos;
    StageObj3D *o;
    StageLightObj *l;
    u16 rot;
    StageRes *res = slot->res;
    if (slot->args[2] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(slot->args[2] & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    }
    rot = Stage_GetAngle(res, slot->args[3], 0xffff);
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149efc.unk_14;
        l = (StageLightObj *)data_02149efc.unk_04;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        o->pos = pos;
        if (rot != 0xffff) {
            o->rot[0] = 0;
            o->rot[1] = rot;
            o->rot[2] = 0;
        }
        o->unk_9c = 0;
        o->unk_a0 = 0;
        o->unk_a4 = 0;
        o->unk_a8 = 0;
        if (o->unk_48 != NULL) {
            func_ov000_02198d28(o->unk_48, &pos, o->rot[1]);
        }
    }
    if (l != NULL) {
        l->pos = pos;
        if (rot != 0xffff) {
            l->rot[0] = 0;
            l->rot[1] = rot;
            l->rot[2] = 0;
        }
    }
    return 1;
}

int func_0205f22c(StageResSlot *slot) {
    StageObj3D *o;
    StageLightObj *l;
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149efc.unk_14;
        l = (StageLightObj *)data_02149efc.unk_04;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else if (slot->args[1] == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        o->params[slot->args[2]] = slot->args[3];
    }
    if (l != NULL) {
        l->params[slot->args[2]] = slot->args[3];
    }
    return 1;
}

int func_0205f354(StageResSlot *slot) {
    StageObj3D *o;
    StageLightObj *l;
    s16 v;
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149efc.unk_14;
        l = (StageLightObj *)data_02149efc.unk_04;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else if (slot->args[1] == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        v = o->params[slot->args[2]];
    }
    if (l != NULL) {
        v = l->params[slot->args[2]];
    }
    data_02fe1534.unk_80 = v;
    return 1;
}


int func_0205f47c(StageResSlot *slot) {
    void *o = NULL;
    StageObj3D *l = NULL;
    u16 id;
    s32 m;
    if (Field_HasEvent(0xc)) {
        return -0x63;
    }
    id = slot->args[0];
    if (id == 0xffff) {
        l = (StageObj3D *)data_02149efc.unk_14;
    } else if (id != 0) {
        o = func_ov000_0218e4cc(data_ov000_021ccd68, id & 0xf000);
    } else if (slot->args[1] == 0xffff) {
        l = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
    } else {
        l = Stage_FindObj3DByIdx(slot->args[1]);
    }
    m = slot->args[2] == 10 ? 6 : slot->args[2] + 0x21;
    if (o != NULL) {
        func_ov000_0218e044(o, slot->args[0], m);
    }
    if (l != NULL) {
        func_ov000_0218d46c(l, 0xffff, m);
    }
    return 1;
}


static inline s32 StageCam_Mul(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

int func_0205f5c4(StageRes *res, u16 id, u16 idx, u16 posIdx, u16 mode) {
    StageObj3D *o;
    StagePlayer *pl;
    StageAng ang;
    StageVec d;
    StageVec pos;
    s32 dist;
    StageCamView *cam;
    StageCamCur *cur;
    if (StageCam_IsActive() || Field_IsBusy()) {
        return -0x63;
    }
    if (id == 0xffff) {
        o = (StageObj3D *)data_02149efc.unk_14;
    } else if (id != 0) {
        o = Stage_FindObj3DPtr(id);
    } else if (idx == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(idx);
    }
    if (o != NULL && (pl = func_ov000_0219bf90()) != NULL) {
        cur = &((StageCamView *)data_ov000_021ccd54)->cur;
        if (posIdx != 0) {
            s16 *p = (s16 *)(res->posEv->pos + (u16)(posIdx & 0x7fff) * 6);
            // Written as s16 and read back as u16, which keeps ang on the stack.
            ((s16 *)&ang)[0] = p[0];
            ((s16 *)&ang)[1] = p[1];
            ((s16 *)&ang)[2] = 0;
            dist = p[2] << 4;
            {
                u16 cx = cur->ang.x;
                u16 cy = cur->ang.y;
                if (ang.x == 0xffff) {
                    ang.x = cx;
                }
                if (ang.y == 0xffff) {
                    ang.y = cy;
                }
            }
        } else {
            ang = cur->ang;
            dist = 0xa000;
        }
        if (mode == 0) {
            d = o->pos;
            pos = pl->pos;
            d.x -= pos.x;
            d.y -= pos.y;
            d.z -= pos.z;
            d.x = StageCam_Mul(d.x, 0x733);
            d.y = StageCam_Mul(d.y, 0x733);
            d.z = StageCam_Mul(d.z, 0x733);
            d.y = pl->unk_68;
            VEC_Add(&d, &pos, &pos);
        } else if (mode == 1) {
            pos = o->pos;
            pos.y += o->unk_68;
        }
        cam = (StageCamView *)data_ov000_021ccd54;
        cam->active = 0xffff;
        cam->pos = pos;
        cam->ang = ang;
        cam->dist = dist;
        cam->unk_f0 = 0x1000;
    }
    return 1;
}

}
