#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218d398(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
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
        func_02016fa0(data, msg->data, size);
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

void func_ov000_0218d46c(Actor *self, u16 id, u8 value) {
    u8 buf = value;
    func_ov000_0218d398(self, id, 2, 1, 1, &buf);
}

BOOL func_ov000_0218d494(Actor *self, ActorMsg *msg) {
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
        if (self->unk_40 != NULL) {
            func_ov000_02198360(self->unk_40, 0, 0);
        }
        if (self->unk_38 != NULL) {
            func_ov000_02190e98(self->unk_38, zero, 0x1000, zero);
            func_ov000_02190cb0(self->unk_38, data_ov000_021cc404, 0x1000, zero);
        }
        handled = TRUE;
        break;
    case 2:
        sub40 = (ActorSub40 *)self->unk_40;
        if (sub40 == NULL) {
            handled = TRUE;
        } else {
            sub40->flags |= (u64)1 << msg->data[0];
        }
        break;
    case 3:
        sub40 = (ActorSub40 *)self->unk_40;
        if (sub40 == NULL || sub40->unk_13 == 1) {
            handled = TRUE;
        } else {
            sub40->flags |= 2;
        }
        break;
    case 4:
        sub40 = (ActorSub40 *)self->unk_40;
        if (sub40 != NULL) {
            sub40->flags |= 1;
        }
        if (self->unk_38 != NULL) {
            MsgData4 *data = (MsgData4 *)msg->data;
            func_ov000_02190cb0(self->unk_38, data->unk_08, data->unk_0c, 0);
            if (data->unk_0e) {
                func_ov000_021915a0(self->unk_38);
            }
        }
        handled = TRUE;
        break;
    case 5:
        sub40 = (ActorSub40 *)self->unk_40;
        if (sub40 != NULL) {
            sub40->flags |= 1;
        }
        if (self->unk_38 != NULL) {
            MsgData5 *data = (MsgData5 *)msg->data;
            func_ov000_02190e98(self->unk_38, data->unk_08, data->unk_0a, 0);
            if (data->unk_0c) {
                func_ov000_021915a0(self->unk_38);
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
            self->unk_a8 = data->unk_1c;
        } else if (data->unk_1c == 0) {
            self->unk_9c = handled;
            self->unk_a0 = handled;
            self->unk_a4 = handled;
            self->unk_a8 = handled;
        }
        handled = TRUE;
        break;
    }
    case 8:
        sub38 = (ActorSub38 *)self->unk_38;
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
        sub44 = (ActorSub44 *)self->unk_44;
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

void func_ov000_0218d77c(Actor *self) {
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

void func_ov000_0218d7e8(Actor *self, u8 arg) {
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

BOOL func_ov000_0218d850(Actor *self) {
    BOOL ret = FALSE;
    Player021ccd54Sub *player = &data_ov000_021ccd54->unk_f4;
    if (player != NULL) {
        s32 dx = player->pos.x;
        s32 dy = player->pos.y;
        s32 dz = player->pos.z;
        dx = self->pos.x - dx;
        dy = self->pos.y - dy;
        dz = self->pos.z - dz;
        if (ABS(dx) > 0x39000 || ABS(dy) > 0x39000 || ABS(dz) > 0x39000) {
            ret = TRUE;
            func_ov000_0218bed8(data_ov000_021ccd64, 1, self);
            self->vfunc_08();
        }
    }
    return ret;
}

u16 func_ov000_0218d8f4(Actor *self, VecFx32 *target) {
    return FX_Atan2(target->x - self->pos.x, target->z - self->pos.z);
}

void func_ov000_0218d918(Actor *self, VecFx32 *target, s32 step) {
    if (func_01ffc198(&self->pos, target, self->unk_64 + 0x400)) {
        return;
    }
    self->rot_y = func_01ffc128(FX_Atan2(target->x - self->pos.x, target->z - self->pos.z), self->rot_y, step, 1, 0x8000);
}

void func_ov000_0218d988(Actor *self, Actor *other, s32 step) {
    u16 angle;
    if (other == self) {
        return;
    }
    if (other == NULL || other == self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
    }
    self->rot_y = func_01ffc128(angle, self->rot_y, step, 1, 0x8000);
}

void func_ov000_0218d9e8(Actor *self, VecFx32 *target, s32 step) {
    s32 dz;
    s32 dx;
    if (func_01ffc198(&self->pos, target, self->unk_64 + 0x400)) {
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
    self->rot_x = func_01ffc128(FX_Atan2(self->pos.y - target->y, (s32)(REG_SQRT_RESULT + 1) >> 1), self->rot_x, step, 1, 0x8000);
}

}
