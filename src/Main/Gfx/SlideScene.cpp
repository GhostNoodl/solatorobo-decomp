#include "Main/Gfx/SlidePanel.h"

// HUD block of the field scene (at 0xc0; the one func_02056e74 draws).
struct SlideHud {
    /* 0x000 */ u32 active : 1;
    /* 0x000 */ u32 shown : 1;
    /* 0x000 */ u32 unk_0_2 : 2;
    /* 0x000 */ u32 opening : 1;
    /* 0x000 */ u32 opened : 1;
    /* 0x000 */ u32 unk_0_6 : 8;
    /* 0x000 */ u32 flag14 : 1;
    /* 0x000 */ u32 closing : 1;
    /* 0x000 */ u32 flag16 : 1;
    /* 0x000 */ u32 unk_0_17 : 15;
    /* 0x004 */ s16 x;
    /* 0x006 */ s16 y;
    /* 0x008 */ s32 timer;
    /* 0x00c */ s32 t;
    /* 0x010 */ u8 unk_010[0x34c];
    /* 0x35c */ s32 timer2;
    /* 0x360 */ s32 t2;
}; // size 0x364

// Field scene with slide panels (the class of func_020534dc; same object as GameScene).
class SlideScene {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void End();
    /* 0x004 */ u32 inited : 1;
    /* 0x004 */ u32 loaded : 1;
    /* 0x004 */ u32 unk_04_2 : 1;
    /* 0x004 */ u32 skip : 1;
    /* 0x004 */ u32 unk_04_4 : 21;
    /* 0x004 */ u32 waitInput : 1;
    /* 0x004 */ u32 unk_04_26 : 1;
    /* 0x004 */ u32 waitPage : 1;
    /* 0x004 */ u32 unk_04_28 : 1;
    /* 0x004 */ u32 ended : 1;
    /* 0x004 */ u32 unk_04_30 : 2;
    /* 0x008 */ u8 unk_008[0xc];
    /* 0x014 */ Model *model;
    /* 0x018 */ s16 frame;
    /* 0x01a */ u8 unk_01a[0x22];
    /* 0x03c */ s32 msgX;
    /* 0x040 */ s32 msgY;
    /* 0x044 */ u8 unk_044[0x38];
    /* 0x07c */ s32 unk_07c;
    /* 0x080 */ u8 unk_080[0x18];
    /* 0x098 */ s8 msg[0x20];
    /* 0x0b8 */ u32 unk_b8_0 : 4;
    /* 0x0b8 */ u32 cancel : 1;
    /* 0x0b8 */ u32 flag5 : 1;
    /* 0x0b8 */ u32 flag6 : 1;
    /* 0x0b8 */ u32 unk_b8_7 : 1;
    /* 0x0b8 */ u32 fading : 1;
    /* 0x0b8 */ u32 faded : 1;
    /* 0x0b8 */ u32 fadeOut : 1;
    /* 0x0b8 */ u32 dim : 1;
    /* 0x0b8 */ u32 dimDir : 2;
    /* 0x0b8 */ u32 busy : 1;
    /* 0x0b8 */ u32 unk_b8_15 : 17;
    /* 0x0bc */ u32 unk_bc_0 : 6;
    /* 0x0bc */ u32 pressed : 1;
    /* 0x0bc */ u32 flag7 : 1;
    /* 0x0bc */ u32 unk_bc_8 : 24;
    /* 0x0c0 */ SlideHud huds[1];
    /* 0x424 */ u8 unk_424[0x98];
    /* 0x4bc */ SlidePanel panels[5];
    /* 0xb24 */ u8 unk_b24[8];
    /* 0xb2c */ s32 fadeTimer;
    /* 0xb30 */ s32 fadeT;
    /* 0xb34 */ s32 dimTimer;
    /* 0xb38 */ s32 dimT;
    /* 0xb3c */ u8 unk_b3c[0x20];
    /* 0xb5c */ s32 unk_b5c;
    /* 0xb60 */ s32 unk_b60;
    /* 0xb64 */ s32 unk_b64;
    /* 0xb68 */ s32 unk_b68;
    /* 0xb6c */ s32 unk_b6c;
    /* 0xb70 */ s32 page;
    /* 0xb74 */ s32 numPages;
};

extern "C" {

extern char *data_0208cca0;
extern char *data_0208cc8c;
extern char *data_0208cb84;
extern char *data_0208cb74;

extern u16 func_0205422c(void);
extern u16 func_02054240(void);
extern void func_02051a34(SlideScene *scene);
extern void *func_02035d5c(const char *name);
extern void *func_0204c270(void);
extern void func_0204c284(void);
extern Model *func_0204c9f8(Model *model);
extern void func_0204c2e0(void *heap);
extern BOOL func_0204e218(SlideScene *scene);
extern Model *func_0204e238(void *model, const char *name, const char *file, int a);
extern char *func_0204e28c(Model *model);
extern void *func_0204e294(Model *model);
extern void *func_02034d88(void *a, void *b);
extern void func_020417e0(Model *model, void *res);
extern void func_0204e29c(Model *model);
extern void func_02054254(SlidePanel *panel);
extern void func_02051f3c(SlidePanel *panel, u32 v);
extern BOOL func_020544e4(SlidePanel *panel, BOOL sound);
extern BOOL func_02035bd4(const char *name, void *arcName, u16 id);
extern void *func_02035f30(const char *name, void *arcName, u16 id);
extern void func_02054b70(Model *model);
extern void func_02054b80(Model *model);
extern void func_02050e94(Model *model);
extern void *func_0204e278(void *pltt);
extern void func_02040c40(void *res, Model *src);
extern u32 *func_02054b90(void *pltt);
extern void func_02054b98(void *dst, u32 size);
extern void DC_FlushRange(const void *addr, u32 size);
extern void func_02040dd8(void *res, int idx, bool load);
extern void func_02054bac(Model *model, void *pltt);
extern void func_02054bb4(SlidePanel *panel);
extern BOOL func_02054b4c(int ch);
extern BOOL func_02054f10(Model *model, u32 idx);
extern void func_02055068(SlidePanel *panel, SlidePanel *prev);
extern void func_020554e4(SlidePanel *panel);
extern void func_02055654(SlideScene *scene);
extern void func_0205567c(SlideScene *scene);
extern BOOL func_0204ffb0(int idx);
extern s32 FX_Div(s32 a, s32 b);
extern void func_020556a0(SlideHud *hud, s8 *text);
extern void func_02055bbc(SlideScene *scene);
extern void func_02055cbc(SlideScene *scene);
extern void func_02052178(SlideScene *scene);
extern BOOL func_020557f8(SlideScene *scene);
extern BOOL func_02055aa4(SlideScene *scene);
extern BOOL func_02055844(void);
extern void func_02055870(void);
extern u16 func_0204dd84(void);
extern BOOL func_02055898(void);
extern void func_0205592c(SlideHud *hud);
extern BOOL func_020559c8(SlideHud *hud);
extern BOOL func_020559f8(s32 id);
extern BOOL func_02055a4c(void);
extern void func_02055a78(void);
extern u8 *func_0204f354(void);
extern void *func_02055a9c(u8 *p);
extern void func_02055a90(void *p);

BOOL func_020534dc(SlideScene *scene) {
    u16 pad;
    s32 i;
    SlidePanel *panel;
    s32 count;
    SlidePanel *other;
    s32 j;
    SlideHud *hud;
    void *heap;
    Model *model;
    void *res;
    u16 pad2;
    BOOL hit;
    pad = func_0205422c();
    if (scene->cancel) {
        if ((pad & 0x100) || (func_02054240() & 0x81)) {
            scene->cancel = 0;
        }
    } else if (pad & 0x81) {
        if (!scene->waitPage) {
            scene->unk_b64 = 0;
            scene->unk_b5c = 0;
        }
    }
    scene->unk_b64--;
    scene->unk_b60--;
    scene->unk_b5c--;
    if (!scene->inited) {
        scene->inited = 1;
        func_02051a34(scene);
    }
    scene->flag5 = 1;
    scene->flag6 = 1;
    if (!scene->loaded && func_02035d5c(data_0208cca0) != NULL) {
        scene->loaded = 1;
        heap = func_0204c270();
        func_0204c284();
        model = scene->model;
        if (model != NULL) {
            if (model != NULL) {
                func_0204c9f8(model);
                func_0203de1c(model);
            }
            scene->model = NULL;
        }
        func_0204c2e0(heap);
        if (func_0204e218(scene)) {
            model = (Model *)func_0203dd9c(0x160);
            if (model != NULL) {
                model = func_0204e238(model, data_0208cc8c, data_0208cb84, 0);
            }
            scene->model = model;
        } else {
            model = (Model *)func_0203dd9c(0x160);
            if (model != NULL) {
                model = func_0204e238(model, data_0208cca0, data_0208cb74, 0);
            }
            scene->model = model;
        }
        res = func_02035d5c(func_0204e28c(scene->model));
        func_020417e0(scene->model, func_02034d88(res, func_0204e294(scene->model)));
        func_0204e29c(scene->model);
        func_02041d9c(scene->model, 0, 4);
        func_02041d9c(scene->model, 0, 0);
    }
    count = 0;
    for (i = 0, panel = scene->panels; i < 5; i++, panel++) {
        if (panel->flag4) {
            func_02054254(panel);
            scene->unk_b64 = 10;
            scene->unk_b5c = 0;
        }
        if (!panel->opened && panel->flag20) {
            if (panel->visible == 1) {
                func_02051f3c(panel, panel->next);
                if (func_020544e4(panel, TRUE)) {
                    break;
                }
            }
            if (!func_02035bd4(func_0204e28c(panel->nextModel), func_0204e294(panel->nextModel), 2)) {
                goto check;
            }
            model = panel->nextModel2;
            if (model != NULL) {
                if (!func_02035bd4(func_0204e28c(model), func_0204e294(model), 2)) {
                    goto check;
                }
            }
            res = func_02035f30(func_0204e28c(panel->nextModel), func_0204e294(panel->nextModel), 2);
            func_02054254(panel);
            func_020417e0(panel->nextModel, func_02034d88(res, func_0204e294(panel->nextModel)));
            if (panel->flag22) {
                func_02054b70(panel->nextModel);
            }
            if (panel->flag24) {
                func_02054b80(panel->nextModel);
            }
            func_0204e29c(panel->nextModel);
            func_02050e94(panel->nextModel);
            func_02041d9c(panel->nextModel, 0, 0);
            if (panel->flag26) {
                u32 *buf;
                void *pltt = func_0203dd9c(0x64);
                if (pltt != NULL) {
                    pltt = func_0204e278(pltt);
                }
                panel->nextPltt = pltt;
                func_02040c40(pltt, panel->nextModel);
                buf = func_02054b90(panel->nextPltt);
                func_02054b98((void *)buf[3], buf[2]);
                DC_FlushRange((void *)buf[3], buf[2]);
                func_02040dd8(panel->nextPltt, 0, 1);
                func_02054bac(panel->nextModel, panel->nextPltt);
            }
            model = panel->nextModel2;
            if (model != NULL) {
                res = func_02035f30(func_0204e28c(model), func_0204e294(model), 2);
                func_020417e0(panel->nextModel2, func_02034d88(res, func_0204e294(panel->nextModel2)));
                if (i == 3) {
                    func_02054b70(panel->nextModel2);
                }
                func_0204e29c(panel->nextModel2);
                func_02041d9c(panel->nextModel2, 0, 0xffff);
            }
            func_02054bb4(panel);
            panel->flag20 = 0;
            if (!scene->fading) {
                scene->fading = 1;
                if (func_02054b4c(0) && !scene->faded) {
                    func_02049a48(data_02097e4c, 0x27, 0x3c, -1, -1);
                }
            }
        }
    check:
        if (!panel->visible) {
            continue;
        }
        if (!panel->flag20 && panel->nextModel != NULL) {
            if (!func_02054f10(panel->nextModel, 0xffff)) {
                continue;
            }
            if (panel->nextModel2 != NULL && !func_02054f10(panel->nextModel2, 0xffff)) {
                continue;
            }
            for (j = 0, other = scene->panels; j < 5; j++, other++) {
                if (other->visible && i != j && panel->unk_0a == other->unk_0a) {
                    if (j <= 2) {
                        func_02055068(panel, other);
                    } else {
                        func_02051f3c(other, panel->next);
                        func_020544e4(other, TRUE);
                        panel->link = j + 1;
                    }
                    break;
                }
            }
            if (panel->link != 0) {
                if (other->visible) {
                    continue;
                }
                panel->link = 0;
            }
            func_020554e4(panel);
        }
        count++;
        if (scene->flag5 == 1 && scene->faded == 1 && panel->moving) {
            if (panel->frame == 0 && panel->model2 != NULL) {
                if (panel->state == 0 || panel->state == 2) {
                    func_02055654(scene);
                }
                if (panel->state == 1 || panel->state == 3) {
                    func_0205567c(scene);
                }
            }
            if (func_0204ffb0(0)) { panel->frame = panel->frames; } else { panel->frame++; }
            panel->unk_20 = FX_Div(panel->frame << 12, panel->frames << 12);
            if (panel->unk_20 >= 0x1000) {
                panel->frame = 0;
                panel->unk_20 = 0x1000;
                panel->moving = 0;
                scene->unk_b64 = 10;
                scene->unk_b5c = 0;
            }
        } else if (scene->skip == 1) {
            u32 kind = panel->kind;
            if (kind == 3) {
                panel->cur = 1;
            } else if (kind == 4) {
                panel->cur = 2;
            } else {
                panel->cur = 3;
            }
            func_020544e4(panel, FALSE);
        }
    }
    if (scene->fading == 1) {
        if (!scene->faded) {
            scene->fadeTimer++;
            scene->fadeT = FX_Div(scene->fadeTimer << 12, 0xa000);
            if (scene->fadeT >= 0x1000) {
                scene->fadeT = 0x1000;
                scene->faded = 1;
                if (scene->fadeOut) {
                    scene->fading = 0;
                    scene->flag5 = 0;
                }
            }
        } else if (scene->skip == 1 && count == 0) {
            func_02049a48(data_02097e4c, 0x28, 0x3c, -1, -1);
            scene->fadeTimer = 0;
            scene->faded = 0;
            scene->fadeOut = 1;
            scene->fadeT = 0;
        }
        if (scene->dim) {
            if (scene->dimDir) {
                scene->dimTimer++;
                scene->dimT = FX_Div(scene->dimTimer << 12, 0xa000);
                if (scene->dimT >= 0x1000) {
                    scene->dimT = 0x1000;
                    scene->dimTimer = 10;
                }
            } else {
                scene->dimTimer--;
                scene->dimT = FX_Div(scene->dimTimer << 12, 0xa000);
                if (scene->dimT < 0) {
                    scene->dimT = 0;
                    scene->dim = 0;
                    scene->dimTimer = 0;
                }
            }
        }
    }
    hud = scene->huds;
    if (hud->flag14) {
        if (hud->closing && func_02054f10(scene->model, 0xffff)) {
            if (hud->shown == 1) {
                hud->t2 = hud->t;
            } else {
                hud->timer2++;
                hud->t2 = FX_Div(hud->timer2 << 12, 0xa000);
            }
            if (hud->t2 >= 0x1000) {
                hud->t2 = 0x1000;
                hud->closing = 0;
                if (hud->flag16) {
                    if (!scene->skip) {
                        if (scene->msg[0] != 0) {
                            func_020556a0(hud, scene->msg);
                        }
                    } else {
                        hud->flag14 = 0;
                    }
                }
                scene->unk_b64 = 10;
                scene->unk_b5c = 0;
            }
        } else if (hud->flag16 && !scene->skip && scene->msg[0] != 0) {
            func_020556a0(hud, scene->msg);
        }
    }
    func_02055bbc(scene);
    func_02055cbc(scene);
    func_02052178(scene);
    scene->pressed = 0;
    if (!scene->loaded || func_020557f8(scene)) {
        return TRUE;
    }
    if (!func_02055aa4(scene)) {
        if (func_02055844()) {
            func_02055870();
        }
        return FALSE;
    }
    if (!scene->busy && scene->waitInput) {
        pad2 = func_0204dd84();
        scene->frame++;
        if (!func_02055898()) {
            hit = FALSE;
            if (!scene->waitPage) {
                if (pad2 & 0x81) {
                    func_02049a48(data_02097e4c, 0x24, 0x50, -1, -1);
                    scene->cancel = 1;
                    scene->pressed = 1;
                    hit = TRUE;
                } else if ((pad & 0x100) && (pad & 0x81)) {
                    scene->pressed = 1;
                    hit = TRUE;
                }
            }
            if (hit || scene->waitPage) {
                scene->unk_b5c = 0x1e;
                scene->unk_b68 = 1;
                scene->waitPage = 0;
                scene->waitInput = 0;
                if (scene->page >= scene->numPages) {
                    scene->ended = 1;
                    scene->End();
                }
                if (scene->unk_07c == 0 && hud->active) {
                    func_0205592c(hud);
                    scene->msgX = hud->x;
                    scene->msgY = hud->y;
                }
            }
        }
    }
    if (hud->opening) {
        if ((scene->busy == 1 || scene->skip == 1) && !hud->shown) {
            func_0205592c(hud);
            hud->shown = 1;
            hud->opened = 0;
            hud->timer = 0;
            hud->t = 0;
            func_020559c8(hud);
        }
        if (!hud->opened) {
            hud->timer++;
            hud->t = FX_Div(hud->timer << 12, 0xa000);
            if (hud->t >= 0x1000) {
                hud->opened = 1;
                hud->flag14 = 1;
                hud->t = 0x1000;
                scene->msgX = hud->x;
                scene->msgY = hud->y;
                if (hud->shown) {
                    hud->opening = 0;
                }
            }
        }
    }
    if (!scene->skip) {
        if (func_020559f8(0x20)) {
            scene->End();
            if (!func_02055a4c()) {
                func_02055a78();
            }
            func_02055a90(func_02055a9c(func_0204f354()));
        }
        if (scene->unk_b8_0 == 0 || scene->flag7 == 1) {
            if (func_0204dd84() & 2) {
                scene->End();
            }
        }
    }
    if (scene->skip) {
        for (j = 0, panel = scene->panels; j < 5; j++, panel++) {
            if (panel->visible) {
                return TRUE;
            }
        }
        if (scene->fading) {
            return TRUE;
        }
        for (i = 0, hud = scene->huds; i < 1; i++, hud++) {
            if (hud->opening) {
                return TRUE;
            }
        }
        if (!scene->flag6) {
            return TRUE;
        }
        if (func_02055844()) {
            func_02055870();
        }
        return FALSE;
    }
    return TRUE;
}

}
