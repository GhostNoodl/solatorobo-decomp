#include "ov006/Model.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern void *data_ov006_021ec434;
extern u8 data_ov006_021eb840[];
extern ov006_Unk02097e40 *data_02097e40;

void *func_02023410(int a, u16 b);
void func_02042628(ov006_Model *model, void *a, ov006_ModelPart *part, int b);
void func_02016e28(void *dst, int value, u32 size);
void func_02016fa0(const void *src, void *dst, u32 size);
void MIi_CpuClear16(int value, void *dst, u32 size);
int func_02046ab4(ov006_Unk02097e40 *a);
BOOL func_02045ea4(ov006_Unk02097e40 *a);
int func_ov006_021e4674(ov006_Unk021ec888 *self);

void func_ov006_021e49bc(ov006_Unk021ec888 *self) {
    ov006_MenuNode *head;
    ov006_MenuNode *cur;
    ov006_MenuNode *p;
    u8 timer;
    ov006_MenuNode *prev;
    ov006_MenuNode *next;
    head = self->nodes;
    if (head == NULL) {
        return;
    }
    for (cur = head->next; cur != NULL;) {
        prev = cur->prev;
        next = cur->next;
        p = prev;
        if (p != NULL) {
            timer = cur->timer;
            do {
                if (p->timer > timer) {
                    break;
                }
                if (p->timer == timer && p->count > cur->count) {
                    break;
                }
                p = p->prev;
            } while (p != NULL);
        }
        if (prev != NULL) {
            prev->next = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }
        if (p != NULL) {
            ov006_MenuNode *pn = p->next;
            if (pn != NULL) {
                pn->prev = cur;
            }
            cur->prev = p;
            cur->next = pn;
            p->next = cur;
        } else {
            head->prev = cur;
            cur->prev = NULL;
            cur->next = head;
            head = cur;
        }
        cur = next;
    }
    self->nodes = head;
    self->unk26 = 1;
}

static inline void ov006_MenuEntry_Set(ov006_MenuEntry *self, u16 a, int b, const void *src, u32 size) {
    self->unk0_0 = a;
    self->unk0_4 = b;
    if (src != NULL) {
        func_02016fa0(src, self->unk2, size);
    } else {
        func_02016e28(self->unk2, 0, size);
    }
}

void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size) {
    ov006_MenuEntry_Set(&self->entries[func_02046ab4(data_02097e40)], a, b, src, size);
}

void func_ov006_021e4b18(ov006_Unk021ec888 *self, int idx, u16 a, int b, const void *src, u32 size) {
    ov006_MenuEntry_Set(&self->entries[idx], a, b, src, size);
}

static inline void ov006_MenuEntry_Clear(ov006_MenuEntry *self) {
    self->unk0_0 = 0;
    self->unk0_4 = 0;
    MIi_CpuClear16(0, self->unk2, sizeof(self->unk2));
}

void func_ov006_021e4b90(ov006_Unk021ec888 *self) {
    int i;
    for (i = 0; i < 4; i++) {
        ov006_MenuEntry_Clear(&self->entries[i]);
    }
}

BOOL func_ov006_021e4bec(ov006_Unk021ec888 *self, u8 v) {
    BOOL result;
    self->unk18 = v;
    result = func_02045ea4(data_02097e40);
    if (result) {
        if (v == 0) {
            self->unk15C = data_02097e40->unk32;
        } else {
            self->unk15C = 0;
        }
    }
    return result;
}

static inline void ov006_Menu_SetState(ov006_Unk021ec888 *self, int state) {
    self->unk8 = state;
    self->unkC = 0;
}

BOOL func_ov006_021e4c38(ov006_Unk021ec888 *self) {
    if (self->unk8 != 1) {
        return FALSE;
    }
    ov006_Menu_SetState(self, 2);
    return TRUE;
}

BOOL func_ov006_021e4c5c(ov006_Unk021ec888 *self) {
    if (self->unk8 == 1 || self->unk8 == 7) {
        return FALSE;
    }
    ov006_Menu_SetState(self, 7);
    return TRUE;
}

BOOL func_ov006_021e4c84(ov006_Unk021ec888 *self) {
    if (self->unk8 == 4) {
        return TRUE;
    }
    if (self->unk8 != 3) {
        return FALSE;
    }
    ov006_Menu_SetState(self, 4);
    return TRUE;
}

BOOL func_ov006_021e4cb4(ov006_Unk021ec888 *self) {
    if (self->unk8 == 6) {
        return TRUE;
    }
    if (self->unk8 != 3 && self->unk8 != 4) {
        return FALSE;
    }
    ov006_Menu_SetState(self, 6);
    return TRUE;
}

BOOL func_ov006_021e4ce8(ov006_Unk021ec888 *self, const void *src) {
    if (self->unk8 == 5) {
        return TRUE;
    }
    if (self->unk8 != 3 && self->unk8 != 4) {
        return FALSE;
    }
    ov006_Menu_SetState(self, 5);
    func_02016fa0(src, &self->unk34, sizeof(self->unk34));
    return TRUE;
}

}
