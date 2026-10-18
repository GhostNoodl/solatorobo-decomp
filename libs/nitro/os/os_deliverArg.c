#include "nitro/os.h"
#include "nitro/mi.h"

#define HW_PARAM_DELIVER_ARG        0x02000000
#define HW_TWL_ROM_HEADER_BUF       0x02ffe000
#define OS_DELIVER_ARG_BUFFER_SIZE  0x300

#define OS_DELIVER_ARG_ENCODE_FLAG  0x01
#define OS_DELIVER_ARG_VALID_FLAG   0x02

#define OS_DELIVER_ARG_STATE_INITIALIZE 0x1
#define OS_DELIVER_ARG_STATE_ENCODE     0x2

typedef u64 OSTitleId;

typedef struct OSDeliverArgInfo {
    OSTitleId titleId;
    u8 reserved1;
    u8 flag;
    u16 makerCode;
    u16 argBufferLength;
    u16 binaryLength;
    u16 crc;
    u16 reserved2;
    u8 buf[OS_DELIVER_ARG_BUFFER_SIZE - 0x14];
} OSDeliverArgInfo;

u16 GetCRC16(u16 start, const void *datap, u32 size);
#define SVC_GetCRC16 GetCRC16

static u32 deliverArgState = 0;
static u8 *deliverArgCurrentPtr = NULL;
static OSDeliverArgInfo *deliverArgInfoPtr = NULL;
OSTitleId OSi_LastBootTitleId;

void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize);
int OS_EncodeDeliverArg(void);
int OS_DecodeDeliverArg(void);
void OS_SetDeliverArgStateInvalid(void);
OSTitleId OS_GetTitleIdLastBootedApp(void);
BOOL OS_IsValidDeliverArg(void);

void OS_InitDeliverArgInfo (OSDeliverArgInfo *info, int binSize)
{
    deliverArgInfoPtr = info;
    MI_CpuFill8(info, 0, OS_DELIVER_ARG_BUFFER_SIZE);
    deliverArgState = OS_DELIVER_ARG_STATE_INITIALIZE | OS_DELIVER_ARG_STATE_ENCODE;
    deliverArgInfoPtr->argBufferLength = (u16)(OS_DELIVER_ARG_BUFFER_SIZE - 0x14 - binSize);
    deliverArgInfoPtr->binaryLength = 0;
    deliverArgCurrentPtr = deliverArgInfoPtr->buf;
    *deliverArgCurrentPtr = '\0';
    *(deliverArgCurrentPtr + 1) = '\0';
}

int OS_EncodeDeliverArg (void)
{
    if (!(deliverArgState & OS_DELIVER_ARG_STATE_INITIALIZE)) {
        return -1;
    }

    deliverArgInfoPtr->makerCode = *(u16 *)(HW_TWL_ROM_HEADER_BUF + 0x10);
    deliverArgInfoPtr->titleId = *(OSTitleId *)(HW_TWL_ROM_HEADER_BUF + 0x230);
    deliverArgInfoPtr->flag = OS_DELIVER_ARG_ENCODE_FLAG | OS_DELIVER_ARG_VALID_FLAG;
    OSi_LastBootTitleId = deliverArgInfoPtr->titleId;

    deliverArgInfoPtr->crc = 0;
    deliverArgInfoPtr->crc = SVC_GetCRC16(0xffff, deliverArgInfoPtr, OS_DELIVER_ARG_BUFFER_SIZE);

    MI_CpuCopy8(deliverArgInfoPtr, (void *)HW_PARAM_DELIVER_ARG, OS_DELIVER_ARG_BUFFER_SIZE);
    MI_CpuFill8(deliverArgInfoPtr, 0, OS_DELIVER_ARG_BUFFER_SIZE);
    deliverArgState = 0;
    return 0;
}

int OS_DecodeDeliverArg (void)
{
    u16 crc;

    if (!OS_IsValidDeliverArg()) {
        return -1;
    }
    if (deliverArgInfoPtr == NULL) {
        return -1;
    }

    MI_CpuCopy8((void *)HW_PARAM_DELIVER_ARG, deliverArgInfoPtr, OS_DELIVER_ARG_BUFFER_SIZE);

    crc = deliverArgInfoPtr->crc;
    deliverArgInfoPtr->crc = 0;
    deliverArgInfoPtr->crc = SVC_GetCRC16(0xffff, deliverArgInfoPtr, OS_DELIVER_ARG_BUFFER_SIZE);

    if (crc != deliverArgInfoPtr->crc) {
        MI_CpuFill8(deliverArgInfoPtr, 0, OS_DELIVER_ARG_BUFFER_SIZE);
        OS_SetDeliverArgStateInvalid();
        return 0;
    }

    deliverArgInfoPtr->flag &= ~OS_DELIVER_ARG_ENCODE_FLAG;
    deliverArgState = OS_DELIVER_ARG_STATE_INITIALIZE;
    return 0;
}

void OS_SetDeliverArgStateInvalid (void)
{
    deliverArgState = 0;
}

OSTitleId OS_GetTitleIdLastBootedApp (void)
{
    if (deliverArgState & OS_DELIVER_ARG_STATE_INITIALIZE) {
        return deliverArgInfoPtr->titleId;
    }
    return 0;
}

BOOL OS_IsValidDeliverArg (void)
{
    OSDeliverArgInfo *p = (OSDeliverArgInfo *)HW_PARAM_DELIVER_ARG;
    return (p->flag & OS_DELIVER_ARG_VALID_FLAG) ? TRUE : FALSE;
}
