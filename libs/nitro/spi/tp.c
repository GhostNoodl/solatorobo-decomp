#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nitro/os_systemWork.h"

#define PXI_FIFO_TAG_TOUCHPANEL 6
#define PXI_PROC_ARM7 1

#define GX_LCD_SIZE_X 256
#define GX_LCD_SIZE_Y 192

#define SPI_PXI_START_BIT                   0x02000000
#define SPI_PXI_END_BIT                     0x01000000
#define SPI_PXI_INDEX_SHIFT                 16
#define SPI_PXI_DATA_MASK                   0x0000ffff

#define SPI_PXI_COMMAND_TP_SAMPLING         0x0000
#define SPI_PXI_COMMAND_TP_AUTO_ON          0x0001
#define SPI_PXI_COMMAND_TP_AUTO_OFF         0x0002
#define SPI_PXI_COMMAND_TP_SETUP_STABILITY  0x0003
#define SPI_PXI_COMMAND_TP_AUTO_SAMPLING    0x0010

#define SPI_PXI_RESULT_SUCCESS              0x0000
#define SPI_PXI_RESULT_INVALID_COMMAND      0x0001
#define SPI_PXI_RESULT_INVALID_PARAMETER    0x0002
#define SPI_PXI_RESULT_ILLEGAL_STATUS       0x0003
#define SPI_PXI_RESULT_EXCLUSIVE            0x0004

typedef enum {
    TP_REQUEST_COMMAND_SAMPLING = 0x0,
    TP_REQUEST_COMMAND_AUTO_ON = 0x1,
    TP_REQUEST_COMMAND_AUTO_OFF = 0x2,
    TP_REQUEST_COMMAND_SET_STABILITY = 0x3,
    TP_REQUEST_COMMAND_AUTO_SAMPLING = 0x10
} TPRequestCommand;

typedef enum {
    TP_RESULT_SUCCESS = 0,
    TP_RESULT_INVALID_PARAMETER,
    TP_RESULT_ILLEGAL_STATUS,
    TP_RESULT_EXCLUSIVE,
    TP_RESULT_PXI_BUSY
} TPRequestResult;

typedef enum {
    TP_STATE_READY = 0,
    TP_STATE_SAMPLING,
    TP_STATE_AUTO_SAMPLING,
    TP_STATE_AUTO_WAIT_END
} TPState;

typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

#define TP_CALIBRATE_DOT_SCALE_SHIFT        8
#define TP_CALIBRATE_ORIGIN_SCALE_SHIFT     2

typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;

typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);

typedef union SPITpData {
    struct {
        u32 x : 12;
        u32 y : 12;
        u32 touch : 1;
        u32 validity : 2;
        u32 dummy : 5;
    } e;
    u32 raw;
    u8 bytes[4];
    u16 halfs[2];
} SPITpData;

typedef struct {
    u8 unk_00[0x58];
    u16 raw_x1;
    u16 raw_y1;
    u8 dx1;
    u8 dy1;
    u16 raw_x2;
    u16 raw_y2;
    u8 dx2;
    u8 dy2;
} NVRAMConfig;

typedef u64 REGType64;
#define reg_CP_DIVCNT (*(vu16 *)0x04000280)
#define REG_DIV_NUMER_ADDR 0x04000290
#define REG_DIV_DENOM_ADDR 0x04000298
#define REG_DIV_RESULT_ADDR 0x040002a0

static inline void CP_SetDivImm32_32_NS_(u32 numer, u32 denom) {
    *(vu32 *)REG_DIV_NUMER_ADDR = numer;
    *(REGType64 *)REG_DIV_DENOM_ADDR = denom;
}

static inline void CP_SetDiv32_32(u32 numer, u32 denom) {
    reg_CP_DIVCNT = 0;
    CP_SetDivImm32_32_NS_(numer, denom);
}

static inline s32 CP_IsDivBusy(void) {
    return (reg_CP_DIVCNT & 0x8000);
}

static inline void CP_WaitDiv(void) {
    while (CP_IsDivBusy()) {
    }
}

static inline s32 CP_GetDivResultImm32(void) {
    return (s32)(*(vu32 *)REG_DIV_RESULT_ADDR);
}

static inline s32 CP_GetDivResult32(void) {
    CP_WaitDiv();
    return CP_GetDivResultImm32();
}

void PXI_Init(void);
void OS_Terminate(void);
u32 TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2);

#define TP_RAW_MAX  0x1000
#define TP_CALIBRATE_DOT_INV_SCALE_SHIFT    (28 - TP_CALIBRATE_DOT_SCALE_SHIFT)
#define TP_CALIBRATE_DOT2ORIGIN_SCALE_SHIFT (TP_CALIBRATE_DOT_SCALE_SHIFT - TP_CALIBRATE_ORIGIN_SCALE_SHIFT)

static void TPi_TpCallback(u32 tag, u32 data, BOOL err);

typedef struct {
    s32 x0;
    s32 xDotSize;
    s32 xDotSizeInv;
    s32 y0;
    s32 yDotSize;
    s32 yDotSizeInv;
} TPiCalibrateParam;

#pragma warn_padding off

static u16 initial = FALSE;

static struct {
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    u16 frequence;
    TPData * samplingBufs;
    u16 bufSize;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    vu16 state;
    vu16 err_flg;
    vu16 command_flg;
} tpState = {0};

#pragma warn_padding reset

static inline BOOL TPi_SamplingNow (void)
{
    if (0 > PXI_SendWordByFifo(PXI_FIFO_TAG_TOUCHPANEL,
                               SPI_PXI_START_BIT
                               | SPI_PXI_END_BIT
                               | (0 << SPI_PXI_INDEX_SHIFT)
                               | (SPI_PXI_COMMAND_TP_SAMPLING << 8), 0)) {
        return FALSE;
    }

    return TRUE;
}

static inline BOOL TPi_AutoSamplingOn (u16 vCount, u8 frequency)
{
    if (0 > PXI_SendWordByFifo(PXI_FIFO_TAG_TOUCHPANEL,
                               SPI_PXI_START_BIT
                               | (0 << SPI_PXI_INDEX_SHIFT)
                               | (SPI_PXI_COMMAND_TP_AUTO_ON << 8) | (u32)frequency, 0)) {
        return FALSE;
    }

    if (0 > PXI_SendWordByFifo(PXI_FIFO_TAG_TOUCHPANEL,
                               SPI_PXI_END_BIT | (1 << SPI_PXI_INDEX_SHIFT) | (u32)vCount, 0)) {
        return FALSE;
    }

    return TRUE;
}

static inline BOOL TPi_AutoSamplingOff (void)
{
    if (0 > PXI_SendWordByFifo(PXI_FIFO_TAG_TOUCHPANEL,
                               SPI_PXI_START_BIT
                               | SPI_PXI_END_BIT
                               | (0 << SPI_PXI_INDEX_SHIFT)
                               | (SPI_PXI_COMMAND_TP_AUTO_OFF << 8), 0)) {
        return FALSE;
    }

    return TRUE;
}

static inline BOOL TPi_SetupStability (u16 range)
{
    if (0 > PXI_SendWordByFifo(PXI_FIFO_TAG_TOUCHPANEL,
                               SPI_PXI_START_BIT
                               | SPI_PXI_END_BIT
                               | (0 << SPI_PXI_INDEX_SHIFT)
                               | (SPI_PXI_COMMAND_TP_SETUP_STABILITY << 8) | (u32)range, 0)) {
        return FALSE;
    }

    return TRUE;
}

static inline void TPi_CopyTpFromSystemWork (TPData * result)
{
    SPITpData spi_tp;

    spi_tp.halfs[0] = *(u16 *)(&(OS_GetSystemWork()->touch_panel[0]));
    spi_tp.halfs[1] = *(u16 *)(&(OS_GetSystemWork()->touch_panel[2]));

    result->x = (u16)spi_tp.e.x;
    result->y = (u16)spi_tp.e.y;
    result->touch = (u8)spi_tp.e.touch;
    result->validity = (u8)spi_tp.e.validity;
}

static inline void TPi_ErrorAtPxi (TPRequestCommand command)
{
    tpState.err_flg |= (1 << command);

    if (tpState.callback) {
        (tpState.callback)(command, TP_RESULT_PXI_BUSY, 0);
    }
}

static void TPi_TpCallback(u32 tag, u32 data, BOOL err)
{
#pragma unused(tag)

    u16 result;
    u16 command;

    result = (u16)(data & SPI_PXI_DATA_MASK);
    command = (u16)((result & 0x7f00) >> 8);

    if (err) {
        TPi_ErrorAtPxi((TPRequestCommand)command);
        return;
    }

    if (command == SPI_PXI_COMMAND_TP_AUTO_SAMPLING) {
        tpState.index++;

        if (tpState.index >= tpState.bufSize) {
            tpState.index = 0;
        }

        TPi_CopyTpFromSystemWork(&tpState.samplingBufs[tpState.index]);

        if (tpState.callback) {
            (tpState.callback)((TPRequestCommand)command, TP_RESULT_SUCCESS, (u8)tpState.index);
        }

        return;
    }

    if (!(data & SPI_PXI_END_BIT)) {
        return;
    }

    switch ((u8)(result & 0x00ff)) {
    case SPI_PXI_RESULT_SUCCESS:
        switch (command) {
        case SPI_PXI_COMMAND_TP_SAMPLING:
            TPi_CopyTpFromSystemWork(&tpState.buf);
            tpState.state = TP_STATE_READY;
            break;
        case SPI_PXI_COMMAND_TP_AUTO_ON:
            tpState.state = TP_STATE_AUTO_SAMPLING;
            break;
        case SPI_PXI_COMMAND_TP_AUTO_OFF:
            tpState.state = TP_STATE_READY;
            break;
        }

        tpState.command_flg &= ~(1 << command);

        if (tpState.callback) {
            (tpState.callback)((TPRequestCommand)command, TP_RESULT_SUCCESS, 0);
        }

        break;
    case SPI_PXI_RESULT_EXCLUSIVE:
        result = TP_RESULT_EXCLUSIVE;
        goto common;
    case SPI_PXI_RESULT_INVALID_PARAMETER:
        result = TP_RESULT_INVALID_PARAMETER;
        goto common;
    case SPI_PXI_RESULT_ILLEGAL_STATUS:
        result = TP_RESULT_ILLEGAL_STATUS;
common:
        tpState.err_flg |= (1 << command);
        tpState.command_flg &= ~(1 << command);

        if (tpState.callback) {
            (tpState.callback)((TPRequestCommand)command, (TPRequestResult)(result & 0xff), 0);
        }
        break;

    case SPI_PXI_RESULT_INVALID_COMMAND:
    default:
        OS_Terminate();
        return;
    }
}

void TP_Init (void)
{
    if (initial) {
        return;
    }

    initial = TRUE;

    PXI_Init();

    tpState.index = 0;
    tpState.callback = NULL;
    tpState.samplingBufs = NULL;
    tpState.state = TP_STATE_READY;
    tpState.calibrate_flg = FALSE;
    tpState.command_flg = 0;
    tpState.err_flg = 0;

    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_TOUCHPANEL, PXI_PROC_ARM7)) {
    }

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_TOUCHPANEL, TPi_TpCallback);
}

BOOL TP_GetUserInfo (TPCalibrateParam * calibrate)
{
    NVRAMConfig * info = (NVRAMConfig *)(OS_GetSystemWork()->nvramUserInfo);

    u16 x1, y1, x2, y2, dx1, dy1, dx2, dy2;

#if (defined(SDK_TS) && (SDK_TS_VERSION >= 200 || SDK_NVRAM_FORMAT >= 100))
    x1 = info->raw_x1;
    y1 = info->raw_y1;
    dx1 = (u16)(info->dx1);
    dy1 = (u16)(info->dy1);
    x2 = info->raw_x2;
    y2 = info->raw_y2;
    dx2 = (u16)(info->dx2);
    dy2 = (u16)(info->dy2);
#else
    x1 = info->raw_x1;
    y1 = info->raw_y1;
    dx1 = (u16)(info->dx1);
    dy1 = (u16)(info->dy1);
    x2 = info->raw_x2;
    y2 = info->raw_y2;
    dx2 = (u16)(info->dx2);
    dy2 = (u16)(info->dy2);
#endif

    if ((x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) ||
        (TP_CalcCalibrateParam(calibrate, x1, y1, dx1, dy1, x2, y2, dx2, dy2) != 0)) {
        calibrate->x0 = 0;
        calibrate->y0 = 0;
        calibrate->xDotSize = 0;
        calibrate->yDotSize = 0;

        return TRUE;
    }

    return TRUE;
}

void TP_SetCalibrateParam (const TPCalibrateParam * param)
{
    OSIntrMode enabled;

    if (param == NULL) {
        tpState.calibrate_flg = FALSE;
        return;
    }

    enabled = OS_DisableInterrupts();

    if (param->xDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->xDotSize);

        tpState.calibrate.x0 = param->x0;
        tpState.calibrate.xDotSize = param->xDotSize;
        tpState.calibrate.xDotSizeInv = (s32)CP_GetDivResult32();
    } else {
        tpState.calibrate.x0 = 0;
        tpState.calibrate.xDotSize = 0;
        tpState.calibrate.xDotSizeInv = 0;
    }

    if (param->yDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->yDotSize);

        tpState.calibrate.y0 = param->y0;
        tpState.calibrate.yDotSize = param->yDotSize;
        tpState.calibrate.yDotSizeInv = (s32)CP_GetDivResult32();
    } else {
        tpState.calibrate.y0 = 0;
        tpState.calibrate.yDotSize = 0;
        tpState.calibrate.yDotSizeInv = 0;
    }

    (void)OS_RestoreInterrupts(enabled);

    tpState.calibrate_flg = TRUE;

}

u32 TP_CalcCalibrateParam (TPCalibrateParam * calibrate,
                           u16 raw_x1, u16 raw_y1,
                           u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2)
{
    s32 rx_width, dx_width, ry_width, dy_width;
    s32 tmp32;
    OSIntrMode enabled;

#define IN_S16_RANGE(x) ((x) < 0x8000 && (x) >= -0x8000)

    if (raw_x1 >= TP_RAW_MAX || raw_y1 >= TP_RAW_MAX || raw_x2 >= TP_RAW_MAX
        || raw_y2 >= TP_RAW_MAX) {
        return 1;
    }
    if (dx1 >= GX_LCD_SIZE_X || dx2 >= GX_LCD_SIZE_X || dy1 >= GX_LCD_SIZE_Y
        || dy2 >= GX_LCD_SIZE_Y) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }

    rx_width = raw_x1 - raw_x2;
    dx_width = dx1 - dx2;

    enabled = OS_DisableInterrupts();

    CP_SetDiv32_32(((u32)rx_width) << TP_CALIBRATE_DOT_SCALE_SHIFT, (u32)dx_width);

    ry_width = raw_y1 - raw_y2;
    dy_width = dy1 - dy2;

    tmp32 = CP_GetDivResult32();
    CP_SetDiv32_32(((u32)ry_width) << TP_CALIBRATE_DOT_SCALE_SHIFT, (u32)dy_width);

    if (!IN_S16_RANGE(tmp32)) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->xDotSize = (s16)tmp32;
    tmp32 = (s16)((((s32)(raw_x1 + raw_x2) << TP_CALIBRATE_DOT_SCALE_SHIFT)
                   - ((s32)(dx1 + dx2) * calibrate->xDotSize)) >> (TP_CALIBRATE_DOT_SCALE_SHIFT -
                                                                   TP_CALIBRATE_ORIGIN_SCALE_SHIFT +
                                                                   1));
    if (!IN_S16_RANGE(tmp32)) {
        (void)OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->x0 = (s16)tmp32;

    tmp32 = CP_GetDivResult32();
    (void)OS_RestoreInterrupts(enabled);

    if (!IN_S16_RANGE(tmp32)) {
        return 1;
    }

    calibrate->yDotSize = (s16)tmp32;
    tmp32 = (s16)((((s32)(raw_y1 + raw_y2) << TP_CALIBRATE_DOT_SCALE_SHIFT)
                   - ((s32)(dy1 + dy2) * calibrate->yDotSize)) >> (TP_CALIBRATE_DOT_SCALE_SHIFT -
                                                                   TP_CALIBRATE_ORIGIN_SCALE_SHIFT +
                                                                   1));
    if (!IN_S16_RANGE(tmp32)) {
        return 1;
    }

    calibrate->y0 = (s16)tmp32;

    return 0;
}
