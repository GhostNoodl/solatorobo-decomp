#include "mobiclip/mobiclip.h"
#include "nitro/mi.h"

extern "C" {

extern void func_02043e2c(void *ptr);
extern void *func_02043e1c(u32 size);
extern void *func_0203465c(void);
extern void *func_020346d4(void);
extern void *func_02034740(void);
extern u32 func_020347ac(void);

#define MOFLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

BOOL func_02033858(MoPlayer *player, MoStream *stream, u32 flags) {
    u32 i;
    s32 k;
    s32 k2;
    u32 pos;
    u32 header;
    s8 tag[2];
    u16 size;
    MoVideoDecoder *dec;

    player->stream = stream;
    player->dataOffset = stream->position;
    if (!stream->Read(player->magic, 0x30)) {
        return FALSE;
    }
    if (player->magic[0] != 'M' || player->magic[1] != 'O' || player->magic[2] != 'D' || player->magic[3] != 'S' ||
        player->signature[0] != 'N' || (player->signature[1] != '2' && player->signature[1] != '3') ||
        MOFLD(u16, player, 0xa) != 10) {
        return FALSE;
    }
    if (player->signature[0] == 'N' && player->signature[1] == '3') {
        do {
            if (!player->stream->Read(tag, 2)) {
                return FALSE;
            }
            if (!player->stream->Read(&size, 2)) {
                return FALSE;
            }
            if (!player->stream->Seek((size << 2) + player->stream->position)) {
                return FALSE;
            }
        } while (!(tag[0] == 'H' && tag[1] == 'E'));
    }
    if (player->audioCodec != 0 && player->audioCodec != 1 && player->audioCodec != 2 && player->audioCodec != 3 &&
        player->audioCodec != 4) {
        return FALSE;
    }
    dec = (MoVideoDecoder *)func_02043e1c(0x454);
    player->decoder = dec;
    MIi_CpuClearFast(0, dec, 0x454);
    player->decodeFunc = (int (*)(MoVideoDecoder *))func_0203465c();
    MOFLD(void *, player->decoder, 0x3c) = func_020346d4();
    MOFLD(u32, player->decoder, 0x40) = 0x2079bb8;
    MOFLD(u32, player->decoder, 0x44) = func_020347ac() + 0x40;
    MOFLD(u32, player, 0x4c) = player->width;
    MOFLD(u32, player, 0x50) = player->height;
    MOFLD(void *, player, 0x54) = func_02034740();
    MOFLD(u32, player->decoder, 0x4) = player->width;
    MOFLD(u32, player->decoder, 0x8) = player->height;
    if (player->width > 0x100) {
        return FALSE;
    }
    if (flags < 6) {
        return FALSE;
    }
    player->numBuffers = flags;
    player->framesY = (void **)func_02043e1c(flags * 4);
    if (player->framesY == NULL) {
        return FALSE;
    }
    player->framesUV = (void **)func_02043e1c(player->numBuffers * 4);
    if (player->framesUV == NULL) {
        return FALSE;
    }
    for (i = 0; i < player->numBuffers; i++) {
        player->framesY[i] = func_02043e1c(player->height << 8);
        if (player->framesY[i] == NULL) {
            return FALSE;
        }
        player->framesUV[i] = func_02043e1c((player->height >> 1) << 8);
        if (player->framesUV[i] == NULL) {
            return FALSE;
        }
        MIi_CpuClearFast(0, player->framesY[i], player->height << 8);
        MI_CpuFill8(player->framesUV[i], 0x80, (player->height >> 1) << 8);
    }
    player->unk_64 = (u32 *)func_02043e1c(player->numBuffers * 4);
    if (player->unk_64 == NULL) {
        return FALSE;
    }
    player->curFrame = 0;
    player->refIndices[0] = 0;
    for (k = 1; k < 6; k++) {
        player->refIndices[k] = player->numBuffers - k;
    }
    player->curBuffer = 0;
    player->decodedFrames = 0;
    player->shownFrames = 0;
    for (k = 0; k < 2; k++) {
        player->chunkBuffers[k] = func_02043e1c(MOFLD(u32, player, 0x24) + 0x400);
        if (player->chunkBuffers[k] == NULL) {
            return FALSE;
        }
    }
    if (player->audioCodec != 0) {
        player->audioDecoders = (MoAudioDecoder *)func_02043e1c(player->audioChannels * sizeof(MoAudioDecoder));
        if (player->audioDecoders == NULL) {
            return FALSE;
        }
        MIi_CpuClearFast(0, player->audioDecoders, player->audioChannels * sizeof(MoAudioDecoder));
    }
    pos = player->stream->position;
    player->stream->Seek(MOFLD(u32, player, 0x2c) + player->dataOffset);
    player->keyFrames = (MoKeyFrame *)func_02043e1c(player->numKeyFrames * 8);
    if (!player->stream->Read(player->keyFrames, player->numKeyFrames * 8)) {
        return FALSE;
    }
    player->stream->Seek(pos);
    if (player->audioCodec == 1) {
        u32 pos2 = player->stream->position;
        player->stream->Seek(player->unk_28 + player->dataOffset);
        for (k2 = 0; k2 < player->audioChannels; k2++) {
            if (!player->stream->Read((u8 *)&player->audioDecoders[k2] + 0x8c0, 0xc34)) {
                return FALSE;
            }
            MOFLD(u32, &player->audioDecoders[k2], 0x14f4) = 2;
        }
        player->stream->Seek(pos2);
    } else if (player->audioCodec == 2) {
        for (k = 0; k < player->audioChannels; k++) {
            MOFLD(u32, &player->audioDecoders[k], 0x1cc) = 2;
        }
    }
    player->stream->Read(&header, 4);
    player->chunkSizes[0] = header >> 14;
    player->chunkSamples[0] = header & 0x3fff;
    player->chunkOffsets[0] = 0;
    player->stream->Read(player->chunkBuffers[0], player->chunkSizes[0] + 4);
    player->chunkIndex = 1;
    return TRUE;
}


BOOL func_020340d8(MoPlayer *player, int keyFrame);

void func_02033df0(MoPlayer *player) {
    u32 i;
    int j;
    if (player->stream != NULL) {
        player->stream->Close();
        if (player->stream != NULL) {
            player->stream->Release();
        }
    }
    func_02043e2c(player->decoder);
    if (player->framesY != NULL) {
        for (i = 0; i < player->numBuffers; i++) {
            func_02043e2c(player->framesY[i]);
        }
        func_02043e2c(player->framesY);
    }
    if (player->framesUV != NULL) {
        for (i = 0; i < player->numBuffers; i++) {
            func_02043e2c(player->framesUV[i]);
        }
        func_02043e2c(player->framesUV);
    }
    if (player->unk_64 != NULL) {
        func_02043e2c(player->unk_64);
    }
    if (player->tmpY != NULL) {
        func_02043e2c(player->tmpY);
    }
    if (player->tmpUV != NULL) {
        func_02043e2c(player->tmpUV);
    }
    for (j = 0; j < 2; j++) {
        if (player->chunkBuffers[j] != NULL) {
            func_02043e2c(player->chunkBuffers[j]);
        }
        player->chunkBuffers[j] = NULL;
    }
    if (player->keyFrames != NULL) {
        func_02043e2c(player->keyFrames);
    }
    if (player->audioDecoders != NULL) {
        func_02043e2c(player->audioDecoders);
    }
    player->stream = NULL;
    player->framesY = NULL;
    player->framesUV = NULL;
    player->tmpY = NULL;
    player->tmpUV = NULL;
    player->unk_64 = NULL;
    player->audioDecoders = NULL;
    player->keyFrames = NULL;
}

u32 func_02033f54(MoPlayer *player) {
    return player->unk_20;
}

u16 func_02033f5c(MoPlayer *player) {
    return player->audioChannels;
}

u32 func_02033f64(MoPlayer *player) {
    return player->unk_18;
}

u32 func_02033f6c(MoPlayer *player) {
    return player->numFrames;
}

u32 func_02033f74(MoPlayer *player) {
    return player->curFrame;
}

u32 func_02033f7c(MoPlayer *player) {
    if (player->unk_20 == 0) {
        return 0;
    }
    if (player->unk_28 != 0) {
        return 0x80;
    }
    return 0x100;
}

BOOL func_02033fa0(MoPlayer *player) {
    int prev;
    if (player->curFrame == player->numFrames) {
        return FALSE;
    }
    prev = player->chunkIndex;
    player->curFrame++;
    player->chunkIndex = (prev + 1) % 2;
    player->stream->WaitAsync();
    {
        u32 header = *(u32 *)((u8 *)player->chunkBuffers[player->chunkIndex] + (player->chunkOffsets[player->chunkIndex] + player->chunkSizes[player->chunkIndex]));
        player->chunkSizes[prev] = header >> 14;
        player->chunkSamples[prev] = header & 0x3fff;
    }
    player->decoder->data = (u8 *)player->chunkBuffers[player->chunkIndex] + player->chunkOffsets[player->chunkIndex];
    if (player->curFrame < player->numFrames) {
        player->chunkOffsets[prev] = player->stream->ReadAsync(player->chunkBuffers[prev], player->chunkSizes[prev] + 4);
    }
    {
        int i;
        for (i = 0; i < 6; i++) {
            player->decoder->refY[i] = player->framesY[player->refIndices[i]];
            player->decoder->refUV[i] = player->framesUV[player->refIndices[i]];
        }
    }
    player->numAudioBlocks = player->audioChannels * player->chunkSamples[player->chunkIndex];
    return TRUE;
}

BOOL func_020340d8(MoPlayer *player, int keyFrame) {
    u32 header;
    if (keyFrame < 0 || keyFrame >= player->numKeyFrames) {
        return FALSE;
    }
    if (!player->stream->Seek(player->dataOffset + player->keyFrames[keyFrame].offset)) {
        return FALSE;
    }
    player->curFrame = player->keyFrames[keyFrame].frame;
    player->stream->WaitAsync();
    player->chunkIndex = 1;
    player->stream->Read(&header, 4);
    player->chunkSizes[0] = header >> 14;
    player->chunkSamples[0] = header & 0x3fff;
    player->chunkOffsets[0] = 0;
    player->stream->Read(player->chunkBuffers[0], player->chunkSizes[0] + 4);
    return TRUE;
}

BOOL func_020341ac(MoPlayer *player) {
    return func_020340d8(player, 0);
}

BOOL func_020341bc(MoPlayer *player) {
    int extra;
    int i;
    if (player->shownFrames > player->decodedFrames) {
        return FALSE;
    }
    if (*(u16 *)player->decoder->data & 0x8000) {
        player->unk_a4 = 1;
        extra = 4;
    } else {
        extra = 0;
        player->unk_a4 = 0;
    }
    player->decoder->data += player->decodeFunc(player->decoder);
    if (player->signature[0] == 'N' && player->signature[1] == '3') {
        player->decoder->data += extra;
    }
    player->unk_64[player->refIndices[0]] = player->decoder->unk_3b4;
    player->audioBlock = 0;
    player->audioChannel = 0;
    for (i = 0; i < 6; i++) {
        if (++player->refIndices[i] == player->numBuffers) {
            player->refIndices[i] = 0;
        }
    }
    player->decodedFrames++;
    return TRUE;
}

extern void func_02075810(MoYuvParams *params);
extern void func_02032f90(void *conv);

BOOL func_02034298(MoPlayer *player, void *dst, u32 stride, int mode) {
    MoYuvParams params;
    if (player->shownFrames >= player->decodedFrames) {
        return FALSE;
    }
    if (mode != 0) {
        if (player->tmpY == NULL) {
            player->tmpY = func_02043e1c(player->height << 8);
            if (player->tmpY == NULL) {
                return FALSE;
            }
        }
        if (player->tmpUV == NULL) {
            player->tmpUV = func_02043e1c((player->height >> 1) << 8);
            if (player->tmpUV == NULL) {
                return FALSE;
            }
        }
        params.y = player->framesY[player->curBuffer];
        params.uv = player->framesUV[player->curBuffer];
        params.tmpY = player->tmpY;
        params.tmpUV = player->tmpUV;
        params.width = player->width;
        params.height = player->height;
        params.unk_18 = player->unk_64[player->curBuffer];
        params.unk_1c = func_020347ac();
        if (mode == 2) {
            params.unk_20 = FALSE;
        } else {
            params.unk_20 = TRUE;
        }
        func_02075810(&params);
        player->convY = player->tmpY;
        player->convUV = player->tmpUV;
    } else {
        player->convY = player->framesY[player->curBuffer];
        player->convUV = player->framesUV[player->curBuffer];
    }
    player->convDst = dst;
    player->convStride = stride << 1;
    func_02032f90(&player->convY);
    player->shownFrames++;
    if (++player->curBuffer == player->numBuffers) {
        player->curBuffer = 0;
    }
    return TRUE;
}

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern int func_02075d4c(MoAudioDecoder *decoder);
extern void func_0207670c(MoAudioDecoder *decoder);
extern void func_020349dc(MoAudioDecoder *decoder, u8 *data);
extern void func_020349ec(MoAudioDecoder *decoder, u8 *data, u32 size, void *out);

BOOL func_02034408(MoPlayer *player) {
    if (player->shownFrames >= player->decodedFrames) {
        return FALSE;
    }
    player->shownFrames++;
    if (++player->curBuffer == player->numBuffers) {
        player->curBuffer = 0;
    }
    return TRUE;
}

u32 func_02034448(MoPlayer *player) {
    return player->chunkSamples[player->chunkIndex];
}

BOOL func_02034458(MoPlayer *player, void *out) {
    u16 codec;
    if (player->audioBlock == player->numAudioBlocks) {
        return FALSE;
    }
    codec = player->audioCodec;
    if (codec == 0) {
        return FALSE;
    }
    if (codec == 1) {
        player->audioDecoders[player->audioChannel].data = player->decoder->data;
        player->audioDecoders[player->audioChannel].out = out;
        player->decoder->data += func_02075d4c(&player->audioDecoders[player->audioChannel]);
    } else if (codec == 2) {
        player->audioDecoders[player->audioChannel].data = player->decoder->data;
        player->audioDecoders[player->audioChannel].out = out;
        func_0207670c(&player->audioDecoders[player->audioChannel]);
        player->decoder->data += 0x28;
    } else if (codec == 3) {
        if (player->unk_a4 == 1) {
            func_020349dc(&player->audioDecoders[player->audioChannel], player->decoder->data);
            player->decoder->data += 4;
        }
        func_020349ec(&player->audioDecoders[player->audioChannel], player->decoder->data, 0x80, out);
        player->decoder->data += 0x80;
    } else {
        MIi_CpuCopy16(player->decoder->data, out, 0x200);
        player->decoder->data += 0x200;
    }
    if (++player->audioChannel == player->audioChannels) {
        player->audioChannel = 0;
        player->unk_a4 = 0;
    }
    player->audioBlock++;
    return TRUE;
}

}
