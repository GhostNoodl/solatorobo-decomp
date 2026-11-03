#include "ov015/ov015.h"

extern "C" {

s32 Interp_QuadLerp(s32 t, s32 a, s32 b);
extern void *data_0208cb74;
void ResMgr_ReleaseArchive(void *a, void *b, int c);
void ResMgr_LoadArchive(void *a, void *b, int c, int d);
int ResMgr_IsArchiveLoaded(void *a, void *b, int c);
void *Ov015Msg_Ctor(Ov015Msg *self);
extern u8 data_ov015_02213198[];
extern u8 data_ov015_02213188[];
void func_ov015_0220ec40(Ov015ResultPanel *self);
extern u8 data_ov015_022131ac[];
void ListRow_Unlink(Lo021cca40 *self); // the row base teardown (ctor ListRow_Init)
extern u8 data_ov015_02213200[];

void func_ov015_02210a10(Ov015Msg *self) {
    self->label->flags |= 2;
    self->textBox->flags |= 2;
    SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
}

static inline BOOL Ov015_IsState5(UiObj *o) {
    return o->state == 5 ? TRUE : FALSE;
}
BOOL func_ov015_02210a58(Ov015Msg *self) {
    BOOL r = FALSE;
    switch (self->step) {
    case 0: {
        s32 t = FX_Div(self->timer << 12, 0x28000);
        self->posX = 0x50000;
        self->posY = Interp_QuadLerp(t, -0x46000, -0x66000);
        self->posZ = -0x333;
        if (++self->timer > 0x28) {
            self->timer = 0x28;
            self->step++;
        }
        break;
    }
    case 1:
        if (Ov015_IsState5(self->label) && Ov015_IsState5(self->textBox)) {
            r = TRUE;
        }
        break;
    }
    self->label->vfunc_1c();
    self->textBox->vfunc_1c();
    return r;
}

void func_ov015_02210b3c(Ov015MsgMgr *self) {
    self->unk_04 = NULL;
    self->unk_08 = 0;
    self->unk_09 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
}

void func_ov015_02210b58(Ov015MsgMgr *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
    if (self->unk_09 != 0) {
        ResMgr_ReleaseArchive((void *)data_0208cca0, data_0208cb74, 2);
    }
}

int func_ov015_02210bd8(Ov015MsgMgr *self) {
    if (self->unk_09 == 0) {
        ResMgr_LoadArchive((void *)data_0208cca0, data_0208cb74, 2, 0);
    }
    return ResMgr_IsArchiveLoaded((void *)data_0208cca0, data_0208cb74, 2);
}

BOOL func_ov015_02210c28(void) {
    return TRUE;
}

s32 func_ov015_02210c30(Ov015MsgMgr *self, Ov015Stat *a, s32 b) {
    s32 r = 0;
    switch (self->unk_0c) {
    case 0:
        self->unk_04 = (VObj *)self->vfunc_08(a, b);
        if (self->unk_04 == NULL) {
            break;
        }
        self->unk_0c = 1;
    case 1:
        if (self->unk_04->vfunc_08() == 0) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->unk_04);
            HEAP_POP(saved);
            self->unk_0c = 0;
        } else {
            r = self->unk_04->vfunc_10();
        }
        break;
    }
    return r;
}

u8 func_ov015_02210cfc(Ov015Msg *self) {
    return self->unk_04;
}

void func_ov015_02210d04(Ov015MsgMgr *self) {
    VObj *o = self->unk_04;
    if (o != NULL) {
        o->vfunc_0c();
    }
}

static inline Ov015Msg *Ov015_NewMsg(void) {
    Ov015Msg *o = (Ov015Msg *)Heap_Alloc(0x144);
    if (o != NULL) o = (Ov015Msg *)Ov015Msg_Ctor(o);
    return o;
}
Ov015Msg *func_ov015_02210d24(Ov015MsgMgr *self, Ov015Stat *b, s32 msg) {
    Ov015Msg *r = NULL;
    switch (msg) {
    case 0x28:
        if (!self->unk_08_0) {
            r = Ov015_NewMsg();
            r->msgIdx = 0;
            r->unk_08 = 0x5a;
            r->unk_04 = 1;
            self->unk_08_0 = 1;
        }
        break;
    case 0x32:
        if (!self->unk_08_4 && b->unk_08 == 3) {
            r = Ov015_NewMsg();
            r->msgIdx = 4;
            r->unk_08 = 0x3c;
            r->unk_04 = 0;
            self->unk_10 = 0;
            self->unk_08 |= 0x10;
            break;
        }
        if (!self->unk_08_1) {
            if ((u32)(b->unk_10 - 2) <= 1) {
                r = Ov015_NewMsg();
                r->msgIdx = 1;
                r->unk_08 = 0x28;
                r->unk_04 = 0;
                self->unk_08 |= 0x2;
                break;
            }
        } else if (!self->unk_08_2) {
            s32 t4;
            s32 t3;
            BOOL x;
            t3 = b->unk_14;
            t4 = b->unk_10;
            if ((t3 == 2 && t4 == 3) || (t3 == 3 && t4 == 2)) {
                x = TRUE;
            } else {
                x = FALSE;
            }
            if (x) {
                self->unk_10 -= 0x1000;
            } else {
                self->unk_10 += 0x1000;
            }
            if (self->unk_10 < 0) self->unk_10 = 0;
            if (self->unk_10 > 0x12c000) {
                r = Ov015_NewMsg();
                r->msgIdx = 2;
                r->unk_08 = 0x28;
                r->unk_04 = 0;
                self->unk_08 |= 0x4;
                break;
            }
        }
        if (!self->unk_08_3 && b->unk_24 > 0x1e000) {
            r = Ov015_NewMsg();
            r->msgIdx = 3;
            r->unk_08 = 0;
            r->unk_04 = 0;
            self->unk_08 |= 0x8;
        }
        break;
    }
    return r;
}

void *Ov015MsgMgr_Dtor(Ov015MsgMgr *self) {
    void *saved;
    SET_VT(self, data_ov015_02213198);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_04);
    HEAP_POP(saved);
    if (self->unk_09 != 0) {
        ResMgr_ReleaseArchive((void *)data_0208cca0, data_0208cb74, 2);
    }
    return self;
}

void *Ov015ResultPanel_Dtor(Ov015ResultPanel *self) {
    SET_VT(self, data_ov015_02213188);
    func_ov015_0220ec40(self);
    return self;
}

void *Ov015Vt_022131ac_DtorDelete(Lo021cca40 *self) {
    SET_VT(self, data_ov015_022131ac);
    ListRow_Unlink(self);
    Heap_Free(self);
    return self;
}

void func_ov015_02211004(void) {
}

void func_ov015_02211008(void) {
}

void *Ov015Vt_022131ac_Dtor(Lo021cca40 *self) {
    SET_VT(self, data_ov015_022131ac);
    ListRow_Unlink(self);

    return self;
}

void func_ov015_0221102c(void) {
    Ov015Shared *p;
    if (data_ov015_02213368 != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(data_ov015_02213368);
        HEAP_POP(saved);
    }
    p = (Ov015Shared *)Heap_Alloc(sizeof(Ov015Shared));
    if (p != NULL) {
        SET_VT(p, data_ov015_02213200);
        p->unk_04 = 0;
        p->unk_08 = 0xa000;
        p->unk_0a = 0xd000;
        p->catchId = 0xffff;
        MIi_CpuClearFast(0, p->items, sizeof(p->items));
        p->total = 0;
        p->unk_2c = 0;
    }
    data_ov015_02213368 = p;
}

void func_ov015_022110f0(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213368);
    HEAP_POP(saved);
}

void *Ov015Vt_02213200_DtorDelete(Ov015Shared *self) {
    Heap_Free(self);
    return self;
}

// A 0x12-byte record of func_0206f040: up to four ids, each picked with weight[k] percent.
typedef struct Ov015PickTable {
    u8 unk_00;
    u8 count;
    u16 id[4];
    u16 weight[4];
} Ov015PickTable;

extern Ov015PickTable *func_0206f040(u16 id);
extern s32 Rand_UpTo(s32 max);

u32 func_ov015_02211160(Ov015Shared *self, u16 *out, u32 n) {
    u32 cnt = 0;
    MIi_CpuClearFast(0xffff, out, n * 2);
    switch ((u32)self->unk_04) {
    case 3:
        cnt++;
        out[0] = 0x800b;
        break;
    case 4:
        cnt++;
        self->unk_08 = 0xa005;
        out[0] = 0x8008;
        break;
    case 5:
        cnt++;
        self->unk_08 = 0xa005;
        out[0] = 0x8003;
        break;
    case 1:
    case 2: {
        u32 i;
        for (i = cnt; i < n; i++) {
            out[i] = 0x800a;
            cnt++;
        }
        break;
    }
    default: {
        u32 j;
        for (j = 0; j < n; j++) {
            u32 k;
            s32 rnd;
            s32 acc;
            u32 m;
            Ov015PickTable *e;
            e = func_0206f040(self->unk_0a);
            m = e->count;
            rnd = Rand_UpTo(0x1000);
            acc = 0;
            for (k = 0; k < m; k++) {
                u16 w = e->weight[k];
                float f;
                if (w > 0) {
                    f = (float)(w << 12) + 0.5f;
                } else {
                    f = (float)(w << 12) - 0.5f;
                }
                acc += (s32)f / 100;
                if (rnd <= acc) {
                    break;
                }
            }
            if (k >= m) {
                k = m - 1;
            }
            out[j] = e->id[k];
            cnt++;
        }
        break;
    }
    }
    return cnt;
}

}
