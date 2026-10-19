#ifndef MAIN_GFX_SLIDEWIN_H
#define MAIN_GFX_SLIDEWIN_H

#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/SlidePanel.h"

// Owned object released through its deleting destructor.
struct SlideObj {
    virtual void unk_vf00();
    virtual void DeletingDtor();
};

// Text window with sliding panels (the full class behind SlideCtrl).
struct SlideWin : TextWin {
    /* 0x0b8 */ u32 mode : 4;
    /* 0x0b8 */ u32 unk_b8_4 : 10;
    /* 0x0b8 */ u32 flag14 : 1;
    /* 0x0b8 */ u32 unk_b8_15 : 9;
    /* 0x0b8 */ u32 unk_b8_24 : 8;
    /* 0x0bc */ u32 unk_bc_0 : 2;
    /* 0x0bc */ u32 style : 4;
    /* 0x0bc */ u32 unk_bc_6 : 26;
    /* 0x0c0 */ u32 unk_0c0;
    /* 0x0c4 */ u16 unk_0c4;
    /* 0x0c6 */ u16 unk_0c6;
    /* 0x0c8 */ u32 unk_0c8;
    /* 0x0cc */ u32 unk_0cc;
    /* 0x0d0 */ VramBlock *blocks[0x80];
    /* 0x2d0 */ u16 blockIds[0x80];
    /* 0x3d0 */ u16 unk_3d0[2];
    /* 0x3d4 */ u8 unk_3d4[0x40];
    /* 0x414 */ SlideObj *obj;
    /* 0x418 */ u32 unk_418;
    /* 0x41c */ u32 unk_41c;
    /* 0x420 */ u32 unk_420;
    /* 0x424 */ SlidePanelItem items[2];
    /* 0x4bc */ SlidePanel panels[5];
    /* 0xb24 */ u32 unk_b24;
    /* 0xb28 */ u32 unk_b28;
    /* 0xb2c */ u32 unk_b2c;
    /* 0xb30 */ u32 unk_b30;
    /* 0xb34 */ u32 unk_b34;
    /* 0xb38 */ u32 unk_b38;
    /* 0xb3c */ u32 unk_b3c;
    /* 0xb40 */ u32 unk_b40;
    /* 0xb44 */ u32 unk_b44;
    /* 0xb48 */ u32 unk_b48;
    /* 0xb4c */ u32 unk_b4c;
    /* 0xb50 */ u32 unk_b50;
    /* 0xb54 */ u32 unk_b54;
    /* 0xb58 */ u32 unk_b58;
    /* 0xb5c */ u32 unk_b5c;
    /* 0xb60 */ u32 unk_b60;
    /* 0xb64 */ u32 unk_b64;
    /* 0xb68 */ u32 unk_b68;
    /* 0xb6c */ u32 unk_b6c;
    /* 0xb70 */ u32 unk_b70;
    /* 0xb74 */ s32 numLines;
    /* 0xb78 */ u32 unk_b78;
    /* 0xb7c */ const char *text;
};

#endif
