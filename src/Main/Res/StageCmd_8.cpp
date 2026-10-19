#include "Main/Res/StageCmd.h"

extern "C" {

int func_0205f8f8(StageResSlot *slot) {
    return func_0205f5c4(slot->res, slot->args[0], slot->args[1], 0, slot->args[2]);
}

int func_0205f91c(StageResSlot *slot) {
    return func_0205f5c4(slot->res, slot->args[0], slot->args[1], slot->args[2], slot->args[3]);
}

int func_0205f940(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_d4 = 0;
    return 1;
}

int func_0205f978(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL) {
        return 1;
    }
    switch (slot->args[0]) {
    case 0:
        data_02fe1534.unk_80 = player->bitsB2a.flag0 ? 1 : 0;
        break;
    case 1:
        data_02fe1534.unk_80 = player->bitsB2a.flag1 ? 1 : 0;
        break;
    }
    return 1;
}

int func_0205f9dc(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    if (slot->args[0] == 0) {
        player->bitsB28.flag3 = 1;
    } else {
        player->bitsB28.flag3 = 0;
    }
    return 1;
}

int func_0205fa48(StageResSlot *slot) {
    StageVec pos;
    StagePlayer *player;
    if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
        return -0x63;
    }
    player = func_ov000_0219bf90();
    if (player != NULL && player->unk_b1e != 0xffff) {
        return -0x63;
    }
    {
        StageRes *res = slot->res;
        u16 arg = slot->args[0];
        if (arg & 0x8000) {
            s16 *p = (s16 *)(res->posEv->pos + (u16)(arg & 0x7fff) * 6);
            pos.x = p[0] << 4;
            pos.y = p[1] << 4;
            pos.z = p[2] << 4;
        } else if (arg == 0xff) {
            StageCamMgr *mgr = data_ov000_021ccd6c;
            u8 i = mgr->next;
            StageCamPoint *pts = mgr->points;
            StageCamPoint *pt;
            if (i != 0xff) {
                mgr->next = 0xff;
            } else {
                i = mgr->cur;
                if (i == 0xff) {
                    i = 0;
                }
            }
            pt = &pts[i];
            pos.x = pt->x << 4;
            pos.y = pt->y << 4;
            pos.z = pt->z << 4;
            VEC_Add(&pos, &pt->pos, &pos);
        }
    }
    if (player != NULL) {
        player->unk_015 = 3;
        player->bitsB28.mode = 2;
        player->unk_b10 = pos;
        player->unk_b08 = 0x252;
    }
    if (slot->args[1] != 0) {
        Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
    }
    return 1;
}

void func_0205fc88(u32 flags) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player != NULL) {
        if (flags & 1) {
            func_ov000_021b12c0(player, 0);
            func_ov000_021b1514(player);
        } else if (flags & 2) {
            func_ov000_021b13cc(player, 0);
        }
        if (flags & 4) {
            func_ov000_021b14e8(player);
        } else if (flags & 8) {
            func_ov000_021b1514(player);
        }
        if (flags & 0x20) {
            func_ov000_021b1540(player, 0, 0);
        } else if (flags & 0x10) {
            func_ov000_021b1740(player, 0);
        }
        if (flags & 0x800) {
            func_ov000_021b1814(player, 0, 1);
        } else if (flags & 0x400) {
            func_ov000_021b1a54(player, 0);
        }
        if (flags & 0x1000) {
            func_ov000_021b4774(player);
        }
    }
    if ((flags & 0x30) || (flags & 0xc00)) {
        Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
    }
}



static inline void Stage_SetMark(const StageVec *v, u16 rot, u16 active) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    x += 8;
    y += 8;
    z += 8;
    data_02fe1534.unk_16 = active;
    data_02fe1534.unk_18 = x >> 4;
    data_02fe1534.unk_1a = y >> 4;
    data_02fe1534.unk_1c = z >> 4;
    data_02fe1534.unk_1e = rot;
}

int func_0205fdb0(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player != NULL) {
        Stage_SetMark(&player->pos, player->rot[1], 1);
    }
    return 1;
}

u16 func_020600cc(StageResSlot *slot, StageVec *pos, u16 *rot, u16 *idx);
extern void func_ov000_0219cbf8(StagePlayer *player, StageVec *pos, u16 *rot);
extern void func_ov000_02184594(FieldState *state);

int func_0205fe10(StageResSlot *slot) {
    StagePlayer *player;
    u16 flags;
    u16 idx;
    u16 rot[3];
    StageVec pos;
    player = func_ov000_0219bf90();
    flags = slot->args[2];
    switch (slot->bits.unk_04_0) {
    case 0:
        if (Field_HasEvent(9)) {
            return -0x63;
        }
        func_020600cc(slot, &pos, rot, &idx);
        if (idx == 0xfe) {
            data_02fe1534.unk_16 = 1;
            data_ov000_021ccd6c->unk_0a = 0xff;
        } else if (idx == 0xffff) {
            if (data_ov000_021ccd6c->unk_0a == 0xff && player != NULL) {
                func_ov000_0219cbf8(player, &pos, rot);
                if (!(flags & 0x20)) {
                    player->unk_vf18();
                }
                {
                    StageVec *v = (StageVec *)((u8 *)data_ov000_021ccd6c + 0x24);
                    v->x = pos.x;
                    v->y = pos.y;
                    v->z = pos.z;
                }
            }
            Stage_SetMark(&pos, rot[1], 1);
            data_ov000_021ccd6c->unk_0a = 0xff;
            if (player != NULL && !Field_HasEvent(10)) {
                data_02fe1534.unk_16 = 0;
            }
        } else {
            data_ov000_021ccd6c->unk_0a = idx;
        }
        data_ov000_021ccd6c->next = 0xff;
        if (flags == 0) {
            break;
        }
        slot->bits.unk_04_0 = 1;
    case 1:
        if (!Stage_IsWirelessReady() || Field_IsEventPending(data_ov000_021ccd54)) {
            return -0x63;
        }
        if (player == NULL) {
            func_ov000_02184594(data_ov000_021ccd54);
            return -0x63;
        }
        func_0205fc88(flags);
        break;
    }
    return 1;
}

}
