#include "ov002/ov002.h"

extern "C" {

static inline void ov002_Model_Delete(Model *m) {
    if (m != NULL) {
        TexObj_Release(m);
        PlttRes_Release(&m->pltt);
        Heap_Free(m);
    }
}

void Ov002Hud_Release(Ov002Hud *self) {
    void *saved;
    Model *p;
    s32 i;
    HEAP_PUSH(saved);
    p = self->unk_04;
    if (p != NULL) {
        ov002_Model_Delete(p);
        self->unk_04 = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = self->unk_08;
    if (p != NULL) {
        ov002_Model_Delete(p);
        self->unk_08 = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = self->unk_0c;
    if (p != NULL) {
        ov002_Model_Delete(p);
        self->unk_0c = NULL;
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    p = self->unk_10;
    if (p != NULL) {
        ov002_Model_Delete(p);
        self->unk_10 = NULL;
    }
    HEAP_POP(saved);
    for (i = 0; i < 5; i++) {
        void *saved2;
        HEAP_PUSH(saved2);
        DELETE_VOBJ(self->captions[i]);
        HEAP_POP(saved2);
    }
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->info);
    HEAP_POP(saved);
}

extern VFunc data_0208ba70[];
extern char data_ov002_021eff94[];
extern char data_ov002_021effa4[];
extern char data_ov002_021effb0[];
extern char data_ov002_021effbc[];
extern char data_ov002_021effc8[];
extern char data_ov002_021effd2[];

void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_InitLines(Ov002Text2 *a, int b);
void *func_02035de0(const char *file, const char *name);
void func_02041c5c(void *a, void *fn);
void *func_ov002_021e1988(void *a, void *b, void *c, u16 *d);

static inline Ov002Text2 *ov002_Anim_New(void) {
    Ov002Text2 *anim = (Ov002Text2 *)Heap_Alloc(0xb8);
    if (anim != NULL) {
        *(VFunc **)anim = data_0208ba70;
        TextWin_Init(anim);
    }
    return anim;
}

static inline void ov002_Anim_Start(Ov002Text2 *s, s32 str) {
    s->str = str;
    s->unk_4c = Text_Measure(s->font, s->spacing, s->str, &s->width, &s->height, s->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = s->font;
}

static inline Model *ov002_Model_New(char *name, char *file) {
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, name, 0);
        STD_CopyString(m->name, file);
    }
    return m;
}

static inline Ov002Caption *ov002_Caption_New(void) {
    Ov002Caption *c = (Ov002Caption *)Heap_Alloc(sizeof(Ov002Caption));
    if (c != NULL) {
        *(VFunc **)c = data_ov002_021f001c;
        c->anim = NULL;
        c->text = 0;
        c->y = 0;
        c->x = 0;
        c->nextY = 0;
        c->nextX = 0;
        c->fromY = 0;
        c->fromX = 0;
        c->toY = 0;
        c->toX = 0;
        c->timer = 0;
        c->mode = 0;
    }
    return c;
}

void Ov002Hud_Load(Ov002Hud *self) {
    void *res = data_02149ef8;
    char buf[0x20];
    void *arc;
    void *data;
    s32 i;
    LangData_LocalizePath(buf, data_ov002_021eff94);
    arc = ResMgr_GetArcList(buf);
    {
        char *name = data_ov002_021effa4;
        data = ResList_FindType2(arc, name);
        self->unk_04 = ov002_Model_New(name, buf);
    }
    TexObj_SetRes(self->unk_04, data);
    self->unk_04->flags |= 2;
    self->unk_04->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk_04, 2, 0);
    self->pending |= 1;
    {
        char *name = data_ov002_021effb0;
        data = ResList_FindType2(arc, name);
        self->unk_08 = ov002_Model_New(name, buf);
    }
    TexObj_SetRes(self->unk_08, data);
    self->unk_08->flags |= 2;
    self->unk_08->unk_150 = -0x1ccd;
    TexObj_SelectImage(self->unk_08, 2, 0);
    self->pending |= 2;
    {
        char *file = buf;
        char *name = data_ov002_021effbc;
        data = func_02035de0(file, name);
        self->unk_0c = ov002_Model_New(name, file);
    }
    TexObj_SetRes(self->unk_0c, data);
    self->unk_0c->flags |= 2;
    self->unk_0c->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk_0c, 2, 0);
    self->pending |= 4;
    {
        char *file = data_ov002_021effc8;
        char *name = data_ov002_021effd2;
        data = func_02035de0(file, name);
        self->unk_10 = ov002_Model_New(name, file);
    }
    TexObj_SetRes(self->unk_10, data);
    self->unk_10->flags |= 2;
    self->unk_10->unk_150 = -0x1ccd;
    func_02041c5c(self->unk_10, (void *)func_ov002_021e1988);
    TexObj_SelectImage(self->unk_10, 2, 1);
    TexObj_SelectImage(self->unk_10, 2, 8);
    TexObj_SelectImage(self->unk_10, 2, 9);
    TexObj_SelectImage(self->unk_10, 2, 10);
    self->pending |= 8;
    for (i = 0; i < 5; i++) {
        Ov002Caption *c;
        s32 text;
        s32 y;
        self->captions[i] = ov002_Caption_New();
        text = (s32)MsgRes_GetString(res, data_ov002_021ef058[0][i]);
        c = self->captions[i];
        if (text != 0) {
            if (c->anim == NULL) {
                c->anim = ov002_Anim_New();
            }
            c->anim->vfunc_08();
            c->anim->font = 3;
            c->anim->unk_2c = 0;
            c->anim->unk_34 = 1;
            ov002_Anim_Start(c->anim, text);
            TextWin_InitLines(c->anim, 8);
            c->anim->flags |= 4;
        }
        c = self->captions[i];
        y = i * 0x12 + 0x1b;
        if (i >= 0 && i <= 3) {
            c->nextX = 0x1c;
            c->nextY = y;
            c->unk_1c = 0x54;
        } else if (i == 4) {
            c->nextX = 0x26;
            c->nextY = y;
            c->unk_1c = 0x4a;
        }
        c = self->captions[i];
        c->x = -0x80;
        c->y = y;
        c = self->captions[i];
        c->fromX = c->x;
        c->fromY = c->y;
        c->toX = c->nextX;
        c->toY = c->nextY;
        c->mode = 2;
        c->timer = 8;
    }
}

}
