#include "Main/Gfx/SlidePanel.h"

struct SlideDrawScene {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void DrawBox(s32 w, s32 h);
    virtual void DrawGrad(s32 w, s32 h, u32 top, u32 bottom);
    /* 0x004 */ u8 unk_004[0xb4];
    /* 0x0b8 */ u32 mode : 4;
    /* 0x0b8 */ u32 unk_b8_4 : 4;
    /* 0x0b8 */ u32 fading : 1;
    /* 0x0b8 */ u32 faded : 1;
    /* 0x0b8 */ u32 fadeOut : 1;
    /* 0x0b8 */ u32 unk_b8_11 : 21;
    /* 0x0bc */ u8 unk_0bc[0x400];
    /* 0x4bc */ SlidePanel panels[5];
    /* 0xb24 */ u8 unk_b24[0xc];
    /* 0xb30 */ s32 fadeT;
    /* 0xb34 */ s32 dimTimer;
    /* 0xb38 */ s32 dimT;
    /* 0xb3c */ s32 shakeX;
    /* 0xb40 */ s32 shakeY;
};

typedef struct SlideCol3 {
    u16 c[3];
} SlideCol3;

extern "C" {

extern const SlideCol3 data_020829c8;

u8 *func_0204f354(void);
void *func_02055a9c(u8 *p);
void func_02056c0c(u32 mode, ...);
void func_02056c30(void);
void func_0204f430(s32 x, s32 y, s32 z);
void func_0204f3a0(int texFmt, int texGen, int s, int t, int repeat, int flip, int pltt0, u32 addr);
void func_0204f368(int light, int polyMode, int cullMode, int polygonId, int alpha, int misc);
void func_0204f3ec(void);
void func_0204f404(s32 x, s32 y, s32 z);
void func_0204f45c(u32 color);
void func_0204f478(s32 num, ...);
extern void func_020435e8(void *pltt, void *src, u32 size);
BOOL func_02056c48(void);
s16 func_0204e2ac(s32 angle);
s32 func_0204e2c4(s32 a, s32 b);
s32 func_020534c4(s32 x);
s32 func_020534d4(SlideDrawScene *scene);
u8 func_02056c94(u8 *p);
int func_02043d84(void *st);
s32 func_02054ae8(Model *model, s32 idx);
s32 func_02056148(SlideDrawScene *scene, SlidePanel *panel, SlidePanel *other);
BOOL func_020554c8(SlidePanel *panel);
BOOL func_02056c9c(SlidePanel *panel);
void func_0205311c(SlideDrawScene *scene);
s32 func_02054894(SlidePanel *panel);
s32 func_020548c8(SlidePanel *panel);
void func_02051f3c(SlidePanel *panel, u32 v);
void func_020543bc(SlidePanel *panel);
void func_02050ea4(Model *model, u32 v);
void func_02050e94(Model *model);
void func_02056cb8(Model *model);
void func_0205563c(Model *model, int idx, ModelPos *pos);
void func_0204e2dc(Model *model, s32 v);
void func_02056cc8(Model *model, u32 r, u32 g, u32 b);
void func_0204e2e4(Model *model, s32 idx);
void func_02056cdc(Model *model, int idx, s32 dx, s32 dy);
void func_02056d04(Model *model);
void func_02056d14(Model *model);
u8 func_02056d24(Model *model);
void func_02056d38(Model *model, u32 v);
void func_02056d50(Model *model);

void func_02056230(SlideDrawScene *scene, s32 i) {
    s16 y;
    s32 sx;
    SlideCol3 cols;
    u32 bottom;
    void *pltt;
    u8 *gfx;
    s32 x;
    u32 polyId;
    ModelPos pos;
    s32 lift;
    u32 top;
    s32 sy;
    SlidePanel *first;
    s32 s;
    SlidePanel *panel;
    s32 dy;

    gfx = func_0204f354();
    pltt = func_02055a9c(func_0204f354());
    sx = scene->shakeX & ~0xfff;
    sy = scene->shakeY & ~0xfff;
    func_02056c0c(0);
    func_02056c30();
    func_0204f430(0x1000, 0x1000, 0x1000);
    func_0204f3a0(0, 0, 0, 0, 0, 0, 1, 0);
    if (!scene->fading) {
        return;
    }
    cols = data_020829c8;
    func_020435e8(pltt, &cols, 6);
    if (scene->mode == 4) {
        polyId = func_02056c48() ? 0x1f : 0x18;
        top = cols.c[1];
        bottom = cols.c[2];
    } else {
        bottom = cols.c[0];
        polyId = 0x12;
        top = bottom;
    }
    if (panel && panel && panel) {}
    dy = func_020534c4(func_0204e2c4(scene->dimT, 0x7000));
    lift = func_020534d4(scene);
    func_0204f3ec();
    if (scene->fadeOut) {
        s = 0x1000 - func_0204e2ac((scene->fadeT << 14) >> 12);
    } else {
        s = func_0204e2ac((scene->fadeT << 14) >> 12);
    }
    func_0204e2c4(0x80000, s);
    func_0204f368(0, 1, 3, func_02056c94(gfx), 0x12, 0);
    func_0204f3ec();
    func_0204f404(sx + (func_0204e2c4(0x110000, s) - 0x90000), sy + (dy + 0x35000) - (lift << 12), -0xa9a);
    func_0204f430(0x1000, 0x1000, 0x1000);
    func_0204f45c(0);
    scene->DrawBox(0x100, 4);
    func_0204f478(1);
    func_0204f3ec();
    func_0204f404(sx + (func_0204e2c4(-0x110000, s) + 0x190000), sy + (dy + 0x77000) - (lift << 12), -0xa9a);
    func_0204f430(0x1000, 0x1000, 0x1000);
    func_0204f45c(0);
    scene->DrawBox(0x100, 4);
    func_0204f478(1);
    func_0204f368(0, 1, 3, func_02043d84(gfx), polyId, 0);
    func_0204f3ec();
    func_0204f404(sx + 0x80000, sy + (dy + 0x56000) - (lift << 12), -0xa9a);
    func_0204f430(s, s, 0x1000);
    scene->DrawGrad(0x100, 0x3e, top, bottom);
    func_0204f478(1);
    func_0204f478(1);
    {
    s32 off[5] = {0, 0, 0, 0, 0};
    i = 0;
    first = &scene->panels[0];
    if (first->unk_0a != 0 && first->model != NULL) {
        if (func_02054ae8(first->model, i) > 0x40) {
            for (panel = scene->panels; i <= 2; i++, panel++) {
                if (i != 0 && panel->model != NULL) {
                    break;
                }
            }
            if (i <= 2) {
                if (!first->flag22) {
                    off[2] = func_0204e2c4(func_02056148(scene, first, &scene->panels[2]), 0x18000);
                    off[0] = func_0204e2c4(func_02056148(scene, first, &scene->panels[0]), 0x24000);
                } else {
                    off[1] = -func_0204e2c4(func_02056148(scene, first, &scene->panels[1]), 0x18000);
                    off[0] = -func_0204e2c4(func_02056148(scene, first, &scene->panels[0]), 0x24000);
                }
            }
        } else {
            for (panel = scene->panels; i <= 2; i++, panel++) {
                if (i != 0 && panel->model != NULL && func_02054ae8(panel->model, 0) > 0x40) {
                    break;
                }
            }
            if (i <= 2) {
                BOOL flag = first->flag22 ? TRUE : FALSE;
                if (i == 1) {
                    if (!func_020554c8(first)) {
                        first = panel;
                    } else if (func_02056c9c(first) && func_02056c9c(panel) && panel->unk_20 < first->unk_20) {
                        first = panel;
                    }
                    off[2] = func_0204e2c4(func_02056148(scene, first, &scene->panels[2]), 0xc000);
                    if (flag == FALSE) {
                        off[0] = func_0204e2c4(func_02056148(scene, first, &scene->panels[0]), 0x18000);
                    }
                } else if (i == 2) {
                    if (!func_020554c8(first)) {
                        first = panel;
                    } else if (func_02056c9c(first) && func_02056c9c(panel) && panel->unk_20 < first->unk_20) {
                        first = panel;
                    }
                    off[1] = -func_0204e2c4(func_02056148(scene, first, &scene->panels[1]), 0xc000);
                    if (flag == TRUE) {
                        off[0] = -func_0204e2c4(func_02056148(scene, first, &scene->panels[0]), 0x18000);
                    }
                }
            }
        }
    }
    func_0205311c(scene);
    for (i = 0, panel = scene->panels; i < 5; i++, panel++) {
        if (!panel->visible || panel->model == NULL) {
            continue;
        }
        if (panel->state == 0) {
            s32 a = func_02054894(panel);
            s32 b = func_020548c8(panel);
            x = a + (func_0204e2c4(func_0204e2ac((panel->unk_20 << 14) >> 12), (b - a) << 12) >> 12);
            if (panel->unk_20 == 0x1000) {
                if (panel->cur == 4) {
                    func_02051f3c(panel, panel->next);
                }
                panel->state = 0xf;
            }
        } else if (panel->state == 1) {
            s32 a = func_020548c8(panel);
            s32 b = func_02054894(panel);
            x = a + (func_0204e2c4(func_0204e2ac((panel->unk_20 << 14) >> 12), (b - a) << 12) >> 12);
            if (panel->unk_20 == 0x1000) {
                panel->flag4 = 1;
                if (!panel->flag27) {
                    func_020543bc(panel);
                    continue;
                }
            }
        } else if (panel->state == 2) {
            u8 alpha;
            x = func_020548c8(panel);
            if (panel->unk_20 == 0x1000) {
                panel->state = 0xf;
            }
            alpha = func_0204e2c4(panel->unk_20, 0x1f000) >> 12;
            func_02050ea4(panel->model, alpha);
            if (panel->model2 != NULL) {
                func_02050e94(panel->model2);
                func_02050ea4(panel->model2, alpha);
            }
        } else if (panel->state == 3) {
            u8 alpha;
            x = func_020548c8(panel);
            if (panel->unk_20 == 0x1000) {
                panel->flag4 = 1;
            }
            alpha = 0x1f - (func_0204e2c4(panel->unk_20, 0x1f000) >> 12);
            func_02050ea4(panel->model, alpha);
            if (panel->model2 != NULL) {
                func_02050e94(panel->model2);
                func_02050ea4(panel->model2, alpha);
            }
        } else {
            if (panel->state == 10) {
                x = func_02054894(panel);
            } else {
                x = func_020548c8(panel);
            }
        }
        pos.x = sx + (x << 12);
        pos.y = sy - 0xa000 - (lift << 12);
        y = 0xc0;
        if (panel->model2 != NULL) {
            y -= 0x40;
            func_02056cb8(panel->model2);
            pos.y += 0xa000;
            func_0205563c(panel->model2, 0, &pos);
            func_0204e2dc(panel->model2, -0x99a - y);
            func_02056cc8(panel->model2, 0x1f, 0x1f, 0x1f);
            func_0204e2e4(panel->model2, 0);
            func_0205563c(panel->model2, 0, &pos);
            if (i == 3) {
                pos.x -= 0x10000;
                func_02056cdc(panel->model2, 0, 3, 4);
            } else {
                pos.x += 0x10000;
                func_02056cdc(panel->model2, 0, -3, 4);
            }
            pos.y -= 0x30000;
            func_0204e2dc(panel->model2, -0x99a - (y + 0x10));
            func_02056cc8(panel->model2, 0, 0, 0);
            func_0204e2e4(panel->model2, 0);
            func_02056d04(panel->model2);
            func_02056d14(panel->model);
            func_02050e94(panel->model);
            if (func_02056d24(panel->model) > 0x1e) {
                func_02050ea4(panel->model, 0x1e);
            }
        } else if (scene->mode == 4) {
            if (i == 1) {
                pos.x -= 0x8000;
            } else if (i == 0) {
                y -= 0x20;
            } else {
                y -= (s16)(i << 4);
            }
        } else {
            y -= (s16)(i << 4);
        }
        if (i <= 2) {
            pos.x += off[i];
            pos.y += dy;
        }
        func_02056d38(panel->model, func_02043d84(gfx));
        func_0205563c(panel->model, 0, &pos);
        func_0204e2dc(panel->model, -0x99a - y);
        func_0204e2e4(panel->model, 0);
        func_02056d50(panel->model);
    }
    }
}

}
