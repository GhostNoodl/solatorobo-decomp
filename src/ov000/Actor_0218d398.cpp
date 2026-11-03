#include "ov000/Actor.h"

extern "C" {

void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    ActorMsg *it;
    ActorMsg *msg = NULL;
    s32 i;
    ActorMsg *tail;
    for (i = 0, it = data_ov000_021ccd68->msgs; i < 0x80; i++, it++) {
        if (it->type == 0) {
            msg = it;
            break;
        }
    }
    if (msg == NULL) {
        return;
    }
    msg->id = id;
    msg->type = type;
    if (size != 0 && data != NULL) {
        MI_CpuCopy8(data, msg->data, size);
    }
    if (notify) {
        if (self->vfunc_4c(msg)) {
            msg->type = 0;
            msg->next = NULL;
            return;
        }
    }
    if (self->msgs == NULL) {
        self->msgs = msg;
        return;
    }
    for (tail = self->msgs; tail->next != NULL; tail = tail->next) {
    }
    tail->next = msg;
}

void Actor_SendMsgU8(Actor *self, u16 id, u8 value) {
    u8 buf = value;
    Actor_SendMsg(self, id, 2, 1, 1, &buf);
}

BOOL Actor_HandleMsg(Actor *self, ActorMsg *msg) {
    s32 zero = 0;
    BOOL handled = FALSE;
    ActorSub40 *sub40;
    ActorSub38 *sub38;
    ActorSub44 *sub44;
    if (!self->vfunc_14()) {
        return handled;
    }
    switch (msg->type) {
    case 1:
        if (self->fsm != NULL) {
            History_SetState(self->fsm, 0, 0);
        }
        if (self->model != NULL) {
            Model0218fe1c_SetAnimByIndex(self->model, zero, 0x1000, zero);
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc404, 0x1000, zero);
        }
        handled = TRUE;
        break;
    case 2:
        sub40 = (ActorSub40 *)self->fsm;
        if (sub40 == NULL) {
            handled = TRUE;
        } else {
            sub40->flags |= (u64)1 << msg->data[0];
        }
        break;
    case 3:
        sub40 = (ActorSub40 *)self->fsm;
        if (sub40 == NULL || sub40->current == 1) {
            handled = TRUE;
        } else {
            sub40->flags |= 2;
        }
        break;
    case 4:
        sub40 = (ActorSub40 *)self->fsm;
        if (sub40 != NULL) {
            sub40->flags |= 1;
        }
        if (self->model != NULL) {
            MsgData4 *data = (MsgData4 *)msg->data;
            Model0218fe1c_SetAnim(self->model, (const char *)data->unk_08, data->unk_0c, 0);
            if (data->unk_0e) {
                Model0218fe1c_SetLoop(self->model);
            }
        }
        handled = TRUE;
        break;
    case 5:
        sub40 = (ActorSub40 *)self->fsm;
        if (sub40 != NULL) {
            sub40->flags |= 1;
        }
        if (self->model != NULL) {
            MsgData5 *data = (MsgData5 *)msg->data;
            Model0218fe1c_SetAnimByIndex(self->model, data->unk_08, data->unk_0a, 0);
            if (data->unk_0c) {
                Model0218fe1c_SetLoop(self->model);
            }
        }
        handled = TRUE;
        break;
    case 7: {
        MsgData7 *data = (MsgData7 *)msg->data;
        self->pos.x = data->pos.x;
        self->pos.y = data->pos.y;
        self->pos.z = data->pos.z;
        self->rot_x = data->rot_x;
        self->rot_y = data->rot_y;
        self->rot_z = data->rot_z;
        if (data->unk_1c > 0) {
            self->gravity = data->unk_1c;
        } else if (data->unk_1c == 0) {
            self->speed = handled;
            self->velY = handled;
            self->friction = handled;
            self->gravity = handled;
        }
        handled = TRUE;
        break;
    }
    case 8:
        sub38 = (ActorSub38 *)self->model;
        if (sub38 != NULL) {
            MsgData8 *data = (MsgData8 *)msg->data;
            MI_Copy36B(data, sub38->unk_84);
            sub38->unk_78.x = data->unk_2c.x;
            sub38->unk_78.y = data->unk_2c.y;
            sub38->unk_78.z = data->unk_2c.z;
            self->unk_93_0 = 1;
        }
        handled = TRUE;
        break;
    case 13:
        sub44 = self->unk_44;
        if (sub44 != NULL) {
            if (msg->data[0] != 0) {
                sub44->unk_22_0 = 1;
                sub44->unk_22_1 = 1;
            } else {
                sub44->unk_22_0 = 0;
                sub44->unk_22_1 = 0;
            }
        }
        handled = TRUE;
        break;
    default:
        handled = TRUE;
        break;
    }
    if (handled) {
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    return handled;
}

void Actor_ProcessMsgs(Actor *self) {
    ActorMsg *prev = NULL;
    ActorMsg *msg = self->msgs;
    ActorMsg *next;
    if (msg == NULL) {
        return;
    }
    do {
        self->vfunc_4c(msg);
        next = msg->next;
        if (msg->type == 0) {
            if (prev != NULL) {
                prev->next = next;
            } else {
                self->msgs = next;
            }
            msg->type = 0;
            msg->next = NULL;
        } else {
            prev = msg;
        }
        msg = next;
    } while (next != NULL);
}

void Actor_DropStateMsgs(Actor *self, u8 arg) {
    ActorMsg *prev = NULL;
    ActorMsg *msg = self->msgs;
    ActorMsg *next;
    if (msg == NULL) {
        return;
    }
    do {
        next = msg->next;
        if (msg->type == 2 && (arg == msg->data[0] || arg == 0)) {
            if (prev != NULL) {
                prev->next = next;
            } else {
                self->msgs = next;
            }
            msg->type = 0;
            msg->next = NULL;
            msg = prev;
        }
        prev = msg;
        msg = next;
    } while (next != NULL);
}

BOOL Actor_DespawnIfFar(Actor *self) {
    BOOL ret = FALSE;
    Camera *cam = &data_ov000_021ccd54->cam.base;
    if (cam != NULL) {
        s32 dx = cam->eye.x;
        s32 dy = cam->eye.y;
        s32 dz = cam->eye.z;
        dx = self->pos.x - dx;
        dy = self->pos.y - dy;
        dz = self->pos.z - dz;
        if (ABS(dx) > 0x39000 || ABS(dy) > 0x39000 || ABS(dz) > 0x39000) {
            ret = TRUE;
            Group_UpdateActor(data_ov000_021ccd64, 1, self);
            self->vfunc_08();
        }
    }
    return ret;
}

u16 Actor_YawToPos(Actor *self, VecFx32 *target) {
    return FX_Atan2(target->x - self->pos.x, target->z - self->pos.z);
}

void Actor_TurnToPos(Actor *self, VecFx32 *target, s32 step) {
    if (Hit_DiffInSphere(&self->pos, target, self->radius + 0x400)) {
        return;
    }
    self->rot_y = Angle_Approach(FX_Atan2(target->x - self->pos.x, target->z - self->pos.z), self->rot_y, step, 1, 0x8000);
}

void Actor_TurnToActor(Actor *self, Actor *other, s32 step) {
    u16 angle;
    if (other == self) {
        return;
    }
    if (other == NULL || other == self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
    }
    self->rot_y = Angle_Approach(angle, self->rot_y, step, 1, 0x8000);
}

void Actor_PitchToPos(Actor *self, VecFx32 *target, s32 step) {
    s32 dz;
    s32 dx;
    if (Hit_DiffInSphere(&self->pos, target, self->radius + 0x400)) {
        return;
    }
    dx = self->pos.x - target->x;
    dz = self->pos.z - target->z;
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    self->rot_x = Angle_Approach(FX_Atan2(self->pos.y - target->y, (s32)(REG_SQRT_RESULT + 1) >> 1), self->rot_x, step, 1, 0x8000);
}

}
