#include "Main/Res/StageCmd.h"

extern "C" {

int func_0205c37c(StageResSlot *slot) {
    if (slot == NULL) {
        if (StageRes_Last()->args[0] == 2) {
            data_02fe1534.unk_70 = data_0214a424->unk_020;
            if (data_02149efc.slotStart != data_02149efc.slotEnd) {
                s32 end = data_02149efc.slotEnd - 1;
                if (end < 0) {
                    end += 0x40;
                }
                data_02149efc.slotEnd = end;
            }
        }
        return 1;
    }
    if (slot->args[0] == 0) {
        {
            StageFlags *f = data_0214a424;
            f->unk_020 += slot->args[1];
            if (f->unk_020 > 99999) {
                f->unk_020 = 99999;
            }
        }
        {
            u32 v;
            StageFlags *f;
            v = slot->args[1];
            f = data_0214a424;
            if (f->unk_00c + v >= 999999) {
                f->unk_00c = 999999;
            } else {
                f->unk_00c = f->unk_00c + v;
            }
        }
    } else if (slot->args[0] == 1) {
        u16 x = slot->args[1];
        StageFlags *f = data_0214a424;
        f->unk_020 = f->unk_020 > x ? f->unk_020 - x : 0;
    }
    return 1;
}

int func_0205c490(StageResSlot *slot) {
    if (slot == NULL) {
        if (StageRes_Last()->args[0] == 2) {
            data_02fe1534.unk_70 = data_0214a424->unk_024;
            if (data_02149efc.slotStart != data_02149efc.slotEnd) {
                s32 end = data_02149efc.slotEnd - 1;
                if (end < 0) {
                    end += 0x40;
                }
                data_02149efc.slotEnd = end;
            }
        }
        return 1;
    }
    if (slot->args[0] == 0) {
        StageFlags *f = data_0214a424;
        f->unk_024 += slot->args[1];
        if (f->unk_024 > 9999) {
            f->unk_024 = 9999;
        }
    } else if (slot->args[0] == 1) {
        u16 x = slot->args[1];
        StageFlags *f = data_0214a424;
        f->unk_024 = f->unk_024 > x ? f->unk_024 - x : 0;
    }
    return 1;
}

int func_0205c580(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02184bb0(state, slot->args[0]);
    return 1;
}

int func_0205c5c4(StageResSlot *slot) {
    func_ov000_021762e4(slot->args[0], slot->args[1]);
    return 1;
}

int func_0205c5e0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02184d90(state, slot->args[0]);
    return 1;
}

int func_0205c624(StageResSlot *slot) {
    func_ov000_0214e7ac(slot->args[0]);
    return 1;
}

int func_0205c638(StageResSlot *slot) {
    u8 buf[3];
    buf[0] = slot->args[0];
    buf[1] = slot->args[1];
    buf[2] = slot->args[2];
    func_ov000_02188d28(buf);
    return 1;
}

int func_0205c664(StageResSlot *slot) {
    u8 buf[3];
    if (Field_HasEvent(0x1b) || Field_HasEvent(0x1c) || Field_HasEvent(0x16) || Field_HasEvent(4)) {
        return -0x63;
    }
    buf[0] = slot->args[0];
    buf[1] = slot->args[1];
    buf[2] = slot->args[2];
    func_ov000_02188ca0(buf, 1);
    return 1;
}

typedef struct StagePos {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} StagePos;

int func_0205c7cc(StageResSlot *slot) {
    u16 a = slot->args[0];
    StageRes *res = slot->res;
    if (a & 0x8000) {
        u16 idx = a & 0x7fff;
        StagePos *pos = &((StagePos *)res->posEv->pos)[idx];
        data_02fe1534.posFlags |= 1;
        data_02fe1534.posX = pos->x;
        data_02fe1534.posY = pos->y;
        data_02fe1534.posZ = pos->z;
    }
    return 1;
}

typedef struct StageCamera {
    virtual void Update();
    /* 0x04 */ u8 unk_04[0x98];
    /* 0x9c */ u8 active : 1;
    /* 0x9c */ u8 unk_9c_1 : 7;
    /* 0x9d */ u8 unk_9d[0x3d];
    /* 0xda */ u8 unk_da_0 : 2;
    /* 0xda */ u8 mode : 2;
    /* 0xda */ u8 axisX : 1;
    /* 0xda */ u8 axisY : 1;
    /* 0xda */ u8 axisZ : 1;
    /* 0xda */ u8 unk_da_7 : 1;
    /* 0xdb */ u8 unk_db[0x19];
    /* 0xf4 */ s32 z;
    /* 0xf8 */ u16 x;
    /* 0xfa */ u16 y;
    /* 0xfc */ u16 w;
} StageCamera;

int func_0205c83c(StageResSlot *slot) {
    u16 a = slot->args[0];
    StageRes *res = slot->res;
    u16 x;
    u16 y;
    u16 w;
    s32 z;
    if (a & 0x8000) {
        u16 idx = a & 0x7fff;
        StagePos *pos = &((StagePos *)res->posEv->pos)[idx];
        w = 0;
        x = pos->x;
        y = pos->y;
        z = pos->z;
    } else {
        x = 0;
        y = 0;
        w = 0;
        z = 0;
    }
    if (data_ov000_021ccd6c->unk_0a == 0xff) {
        StageCamera *cam = (StageCamera *)((u8 *)data_ov000_021ccd54 + 0xf4);
        cam->x = x;
        cam->y = y;
        cam->w = w;
        cam->axisX = 1;
        cam->axisY = 1;
        cam->axisZ = 1;
        cam->z = z;
        cam->mode = 1;
        cam->active = 0;
        cam->Update();
        cam->active = 1;
    } else {
        if (x != 0) {
            data_02fe1534.posFlags |= 2;
            data_02fe1534.unk_3c = x;
        }
        if (y != 0) {
            data_02fe1534.posFlags |= 4;
            data_02fe1534.unk_3e = y;
        }
        if (z != 0) {
            data_02fe1534.posFlags |= 8;
            data_02fe1534.unk_40 = z;
        }
    }
    return 1;
}

typedef struct StageCamRot {
    u16 v[3];
} StageCamRot;

typedef struct StageVecA {
    s32 v[3];
} StageVecA;

typedef struct StageFieldCam {
    virtual void Update();
    /* 0x04 */ u8 unk_04[0x98];
    /* 0x9c */ u8 active : 1;
    /* 0x9c */ u8 unk_9c_1 : 7;
    /* 0x9d */ u8 unk_9d[0x3d];
    /* 0xda */ u8 unk_da_0 : 1;
    /* 0xda */ u8 hasTarget : 1;
    /* 0xda */ u8 mode : 2;
    /* 0xda */ u8 axisX : 1;
    /* 0xda */ u8 axisY : 1;
    /* 0xda */ u8 axisZ : 1;
    /* 0xda */ u8 unk_da_7 : 1;
    /* 0xdb */ u8 unk_db[0xd];
    /* 0xe8 */ StageVec target;
    /* 0xf4 */ s32 z;
    /* 0xf8 */ u16 x;
    /* 0xfa */ u16 y;
} StageFieldCam;

typedef struct StageFieldCamState {
    /* 0x000 */ u8 unk_000[0xd3];
    /* 0x0d3 */ u8 camSet;
    /* 0x0d4 */ u8 unk_0d4[4];
    /* 0x0d8 */ StageVec camPos;
    /* 0x0e4 */ StageCamRot camRot;
    /* 0x0ec */ s32 camDist;
    /* 0x0f0 */ u16 camScale;
    /* 0x0f4 */ StageFieldCam cam;
} StageFieldCamState;

typedef struct StageFieldPlayerPos {
    /* 0x000 */ u8 unk_000[0x104];
    /* 0x104 */ StageVec pos;
} StageFieldPlayerPos;

typedef struct StageCamInfo {
    StageCamRot rot;
    StageVec pos;
} StageCamInfo;

int func_0205c968(StageResSlot *slot) {
    StageCamInfo info;
    s32 dist;
    u16 a;
    StageRes *res;
    StageFieldCamState *st;
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    a = slot->args[0];
    dist = 0;
    info.pos.x = 0;
    info.pos.y = 0;
    info.pos.z = 0;
    info.rot.v[0] = 0;
    info.rot.v[1] = 0;
    info.rot.v[2] = 0;
    res = slot->res;
    if (a == 0x1000) {
        StageVec *pp = &((StageFieldPlayerPos *)data_ov000_021ccd54)->pos;
        info.pos.x = pp->x;
        info.pos.y = pp->y;
        info.pos.z = pp->z;
    } else if (a & 0x8000) {
        StagePos *p = &((StagePos *)res->posEv->pos)[(u16)(a & 0x7fff)];
        info.pos.x = p->x << 4;
        info.pos.y = p->y << 4;
        info.pos.z = p->z << 4;
    } else {
        StageObj3D *obj;
        if (data_ov000_021ccd68 == NULL) {
            obj = NULL;
        } else {
            obj = (StageObj3D *)func_ov000_0218e6d0(data_ov000_021ccd68, a & 0xf000, a);
        }
        if (obj != NULL) {
            info.pos.x = obj->pos.x;
            info.pos.y = obj->pos.y;
            info.pos.z = obj->pos.z;
        } else {
            return 1;
        }
    }
    a = slot->args[1];
    if (a & 0x8000) {
        StagePos *p = &((StagePos *)res->posEv->pos)[(u16)(a & 0x7fff)];
        info.rot.v[0] = p->x;
        info.rot.v[1] = p->y;
        info.rot.v[2] = 0;
        dist = p->z << 4;
    }
    st = (StageFieldCamState *)data_ov000_021ccd54;
    st->camSet = 1;
    st->camPos.x = info.pos.x;
    st->camPos.y = info.pos.y;
    st->camPos.z = info.pos.z;
    st->camRot = info.rot;
    st->camDist = dist;
    st->camScale = 0x1000;
    st->cam.target.x = info.pos.x;
    st->cam.target.y = info.pos.y;
    st->cam.target.z = info.pos.z;
    st->cam.hasTarget = 1;
    st->cam.x = st->camRot.v[0];
    st->cam.axisX = 1;
    st->cam.y = st->camRot.v[1];
    st->cam.axisY = 1;
    st->cam.z = st->camDist;
    st->cam.mode = 1;
    st->cam.active = 0;
    st->cam.Update();
    return 1;
}

}
