#include "ov002/ov002.h"

extern "C" {

extern u8 data_ov002_021efe30[];

static inline BOOL ov002_Menu_IsBusy(u8 *m) {
    return (FIELD(m, 0x98, s32) != FIELD(m, 0xa4, s32) || FIELD(m, 0xb3, s8) != 0) ? TRUE : FALSE;
}

static inline u8 *ov002_Menu_GetSel(u8 *m) {
    u8 *p = FIELD(m, 0x98, u8 *);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = FIELD(m, 0xb1, s8);
    while (n-- != 0) {
        p = FIELD(p, 0x2c, u8 *);
    }
    return p;
}

static inline void ov002_Menu_Close(Obj021eff74 *self) {
    self->unk_0c->flags |= 2;
    self->unk_10->flags |= 2;
    gOv002BoardRef.unk_00 = self->unk_14;
    self->unk_18 = 2;
    if (self->unk_08 == 2 || self->unk_08 == 3) {
        GfxSys_StartFadeOut(0xa000, 2, -1);
    }
}

void CustomizeMenu_PreUpdate(Obj021eff74 *self) {
    u16 id;
    u32 flags;
    if (self->unk_18 >= 2) {
        return;
    }
    if (self->unk_0c != NULL) {
        if (ov002_Menu_IsBusy(((u8 *)self->unk_0c))) {
            return;
        }
        if (!self->unk_0c->vfunc_0c()) {
            return;
        }
    }
    id = FIELD(ov002_Menu_GetSel(((u8 *)self->unk_0c)), 0x6, u16);
    if (self->unk_14 != id && self->unk_10 != NULL) {
        void *str;
        void *g = gMsgRes;
        switch (id) {
        case 0:
            str = MsgRes_GetString(g, 0xbd);
            break;
        case 1:
            str = MsgRes_GetString(g, 0xbf);
            break;
        case 2:
            str = MsgRes_GetString(g, 0xfb);
            break;
        default:
            str = data_ov002_021efe30;
            break;
        }
        Obj0215bb14_SetText(self->unk_10, str);
        self->unk_10->vfunc_70();
    }
    self->unk_14 = id;
    flags = self->unk_1c;
    if (flags & 1) {
        switch (id) {
        case 0:
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            self->unk_08 = 1;
            ov002_Menu_Close(self);
            break;
        case 1:
            if (self->unk_20 == 0) {
                SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
                self->unk_08 = 2;
                ov002_Menu_Close(self);
            } else {
                void *str;
                void *g;
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
                g = gMsgRes;
                str = NULL;
                if (self->unk_20 == 1) {
                    str = MsgRes_GetString(g, 0xc0);
                } else if (self->unk_20 == 2) {
                    str = MsgRes_GetString(g, 0xc1);
                }
                if (str != NULL) {
                    Obj0215bb14_SetText(self->unk_10, str);
                    self->unk_10->vfunc_70();
                }
            }
            break;
        case 2:
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            self->unk_08 = 3;
            ov002_Menu_Close(self);
            break;
        }
    } else if (flags & 2) {
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        self->unk_08 = 3;
        ov002_Menu_Close(self);
    }
    self->unk_1c = 0;
}

}
