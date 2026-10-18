#ifndef MOBICLIP_MOBICLIP_H
#define MOBICLIP_MOBICLIP_H

#include "types.h"

// Actimagine Mobiclip SDK movie player.

#ifdef __cplusplus

// Data source of a movie. data_0208b2ac is the vtable of the file stream implementation.
struct MoStream {
    /* 0x00 */ // vtable
    virtual void unk_vf00();
    virtual void Release();
    virtual BOOL Seek(u32 offset);
    virtual u32 Read(void *buffer, u32 size);
    virtual u32 ReadAsync(void *buffer, u32 size);
    virtual void WaitAsync();
    virtual void Close();
    /* 0x04 */ u32 length;
    /* 0x08 */ u32 position;
    /* 0x0c */ void *file;
    /* 0x10 */ u8 asyncPending;
}; // size 0x14

#else

typedef struct MoStream MoStream;

#endif

typedef struct MoVideoDecoder {
    /* 0x000 */ u8 *data;
    /* 0x004 */ u8 unk_004[0x8];
    /* 0x00c */ void *refY[6];
    /* 0x024 */ void *refUV[6];
    /* 0x03c */ u8 unk_03c[0x378];
    /* 0x3b4 */ u32 unk_3b4;
} MoVideoDecoder;

typedef struct MoAudioDecoder {
    /* 0x0000 */ u8 *data;
    /* 0x0004 */ void *out;
    /* 0x0008 */ u8 unk_0008[0x14f0];
} MoAudioDecoder; // size 0x14f8

typedef struct MoYuvParams {
    /* 0x0 */ void *y;
    /* 0x4 */ void *uv;
    /* 0x8 */ void *tmpY;
    /* 0xc */ void *tmpUV;
    /* 0x10 */ u32 width;
    /* 0x14 */ u32 height;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ u32 unk_1c;
    /* 0x20 */ BOOL unk_20;
} MoYuvParams; // size 0x24

typedef struct MoKeyFrame {
    /* 0x0 */ u32 frame;
    /* 0x4 */ u32 offset;
} MoKeyFrame;

typedef struct MoPlayer {
    /* 0x00 */ MoStream *stream;
    /* 0x04 */ u8 unk_04[0x4];
    /* 0x08 */ s8 signature[4];
    /* 0x0c */ u32 numFrames;
    /* 0x10 */ u32 width;
    /* 0x14 */ u32 height;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ u16 audioCodec;
    /* 0x1e */ u16 audioChannels;
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ u8 unk_24[0x4];
    /* 0x28 */ u32 unk_28;
    /* 0x2c */ u8 unk_2c[0x4];
    /* 0x30 */ u32 numKeyFrames;
    /* 0x34 */ MoVideoDecoder *decoder;
    /* 0x38 */ int (*decodeFunc)(MoVideoDecoder *decoder);
    /* 0x3c */ void *convY;
    /* 0x40 */ void *convUV;
    /* 0x44 */ void *convDst;
    /* 0x48 */ u32 convStride;
    /* 0x4c */ u8 unk_4c[0xc];
    /* 0x58 */ MoAudioDecoder *audioDecoders;
    /* 0x5c */ void **framesY;
    /* 0x60 */ void **framesUV;
    /* 0x64 */ u32 *unk_64;
    /* 0x68 */ void *tmpY;
    /* 0x6c */ void *tmpUV;
    /* 0x70 */ void *chunkBuffers[2];
    /* 0x78 */ u32 chunkSizes[2];
    /* 0x80 */ u32 chunkOffsets[2];
    /* 0x88 */ u32 chunkSamples[2];
    /* 0x90 */ int chunkIndex;
    /* 0x94 */ MoKeyFrame *keyFrames;
    /* 0x98 */ u32 curFrame;
    /* 0x9c */ u32 shownFrames;
    /* 0xa0 */ u32 decodedFrames;
    /* 0xa4 */ int unk_a4;
    /* 0xa8 */ u32 numBuffers;
    /* 0xac */ u32 refIndices[6];
    /* 0xc4 */ u32 curBuffer;
    /* 0xc8 */ u32 numAudioBlocks;
    /* 0xcc */ u32 audioBlock;
    /* 0xd0 */ u32 audioChannel;
    /* 0xd4 */ u32 dataOffset;
} MoPlayer; // size 0xd8

#ifdef __cplusplus
extern "C" {
#endif

// mobiclip_api.cpp
BOOL func_02033550(MoPlayer *player, MoStream *stream, u32 flags);
MoPlayer *func_02033580(void *file, u32 flags);
void *func_02033648(void *ptr);
void func_0203365c(MoPlayer *player);
void *func_020337fc(u32 size);
void func_02033808(void *ptr);
MoPlayer *func_02033814(MoPlayer *player);
MoPlayer *func_02033844(MoPlayer *player);

// mobiclip_player.cpp
BOOL func_02033858(MoPlayer *player, MoStream *stream, u32 flags);
void func_02033df0(MoPlayer *player);
u32 func_02033f54(MoPlayer *player);
u16 func_02033f5c(MoPlayer *player);
u32 func_02033f64(MoPlayer *player);
u32 func_02033f6c(MoPlayer *player);
u32 func_02033f74(MoPlayer *player);
u32 func_02033f7c(MoPlayer *player);
BOOL func_02033fa0(MoPlayer *player);
BOOL func_020340d8(MoPlayer *player, int keyFrame);
BOOL func_020341ac(MoPlayer *player);
BOOL func_020341bc(MoPlayer *player);
BOOL func_02034298(MoPlayer *player, void *dst, u32 stride, int mode);
BOOL func_02034408(MoPlayer *player);
u32 func_02034448(MoPlayer *player);
BOOL func_02034458(MoPlayer *player, void *out);

#ifdef __cplusplus
}
#endif

#endif
