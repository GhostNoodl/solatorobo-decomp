#include "mobiclip/mobiclip.h"

extern "C" {

extern void func_02043e2c(void *ptr);

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
    player->stream->unk_vf14();
    {
        u32 header = *(u32 *)((u8 *)player->chunkBuffers[player->chunkIndex] + (player->chunkOffsets[player->chunkIndex] + player->chunkSizes[player->chunkIndex]));
        player->chunkSizes[prev] = header >> 14;
        player->chunkSamples[prev] = header & 0x3fff;
    }
    player->decoder->data = (u8 *)player->chunkBuffers[player->chunkIndex] + player->chunkOffsets[player->chunkIndex];
    if (player->curFrame < player->numFrames) {
        player->chunkOffsets[prev] = player->stream->ReadAt(player->chunkBuffers[prev], player->chunkSizes[prev] + 4);
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
    player->stream->unk_vf14();
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

extern void *func_02043e1c(u32 size);
extern u32 func_020347ac(void);
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

extern void func_02016cbc(const void *src, void *dst, u32 size);
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
        func_02016cbc(player->decoder->data, out, 0x200);
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
