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


}
