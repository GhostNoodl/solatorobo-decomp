#include "card_private.h"

#pragma force_active on

#define CARD_REQ_IDENTIFY               2
#define CARD_REQ_READ_BACKUP            6
#define CARD_REQ_VERIFY_BACKUP          9
#define CARD_REQ_ERASE_SECTOR_BACKUP    11
#define CARD_REQ_ERASE_SUBSECTOR_BACKUP 15

#define CARD_REQUEST_MODE_RECV        0
#define CARD_REQUEST_MODE_SEND        1
#define CARD_REQUEST_MODE_SEND_VERIFY 2
#define CARD_REQUEST_MODE_SPECIAL     3

#define CARD_RESULT_UNSUPPORTED 3

#define CARD_BACKUP_TYPE_DEVICE_EEPROM 1
#define CARD_BACKUP_TYPE_DEVICE_FLASH  2
#define CARD_BACKUP_TYPE_DEVICE_FRAM   3

extern u8 data_0208e440[0x100];
#define backup_cache_page_buf data_0208e440


u32 CARD_GetBackupSectorSize(void);

void CARDi_RequestStreamCommandCore(CARDiCommon *p);

void CARDi_IdentifyBackupCore2(int type) {
    CARDiCommandArg *const p = cardi_common.cmd;

    MI_CpuFill8(&p->spec, 0, sizeof(p->spec));
    p->type = type;
    p->spec.caps = 0x203f;

    if (type != 0) {
        const u32 size = 1 << ((type >> 8) & 0xff);
        const u32 device = type & 0xff;
        const u32 vender = (type >> 16) & 0xff;

        p->spec.total_size = size;
        p->spec.initial_status = 0xff;

        if (device == CARD_BACKUP_TYPE_DEVICE_EEPROM) {
            switch (size) {
            default:
                goto invalid_type;
            case 0x000200:
                p->spec.page_size = 0x10;
                p->spec.addr_width = 1;
                p->spec.program_page = 5;
                p->spec.initial_status = 0xf0;
                break;
            case 0x002000:
                p->spec.page_size = 0x20;
                p->spec.addr_width = 2;
                p->spec.program_page = 5;
                p->spec.initial_status = 0x00;
                break;
            case 0x010000:
                p->spec.page_size = 0x80;
                p->spec.addr_width = 2;
                p->spec.program_page = 10;
                p->spec.initial_status = 0x00;
                break;
            case 0x020000:
                p->spec.page_size = 0x100;
                p->spec.addr_width = 3;
                p->spec.program_page = 5;
                p->spec.initial_status = 0x00;
                break;
            }
            p->spec.sect_size = p->spec.page_size;
            p->spec.caps |= 0x0140;
            p->spec.caps |= 0x4200;
        } else if (device == CARD_BACKUP_TYPE_DEVICE_FLASH) {
            switch (size) {
            default:
                goto invalid_type;
            case 0x040000:
            case 0x080000:
            case 0x100000:
                p->spec.write_page = 25;
                p->spec.write_page_total = 300;
                p->spec.erase_page = 300;
                p->spec.erase_sector = 5000;
                p->spec.caps |= 0x480;
                break;
            case 0x200000:
                p->spec.write_page = 23;
                p->spec.write_page_total = 300;
                p->spec.erase_sector = 500;
                p->spec.erase_sector_total = 5000;
                p->spec.erase_chip = 10000;
                p->spec.erase_chip_total = 60000;
                p->spec.initial_status = 0x00;
                p->spec.caps |= 0x0480;
                p->spec.caps |= 0x5000;
                break;
            case 0x400000:
                p->spec.erase_sector = 600;
                p->spec.erase_sector_total = 3000;
                p->spec.erase_subsector = 70;
                p->spec.erase_subsector_total = 150;
                p->spec.erase_chip = 23000;
                p->spec.erase_chip_total = 800000;
                p->spec.initial_status = 0x00;
                p->spec.subpage_size = 0x1000;
                p->spec.caps |= 0xd000;
                break;
            case 0x800000:
                if (vender == 0) {
                    p->spec.erase_sector = 1000;
                    p->spec.erase_sector_total = 3000;
                    p->spec.erase_chip = 68000;
                    p->spec.erase_chip_total = 160000;
                    p->spec.initial_status = 0x00;
                    p->spec.caps |= 0x5000;
                } else if (vender == 1) {
                    p->spec.erase_sector = 1000;
                    p->spec.erase_sector_total = 3000;
                    p->spec.erase_chip = 68000;
                    p->spec.erase_chip_total = 160000;
                    p->spec.initial_status = 0x84;
                    p->spec.caps |= 0x5000;
                }
                break;
            }
            p->spec.sect_size = 0x10000;
            p->spec.page_size = 0x100;
            p->spec.addr_width = 3;
            p->spec.program_page = 5;
            p->spec.caps |= 0xb40;
        } else if (device == CARD_BACKUP_TYPE_DEVICE_FRAM) {
            switch (size) {
            default:
                goto invalid_type;
            case 0x002000:
            case 0x008000:
                break;
            }
            p->spec.page_size = size;
            p->spec.sect_size = size;
            p->spec.addr_width = 2;
            p->spec.initial_status = 0x00;
            p->spec.caps |= 0x0140;
            p->spec.caps |= 0x4200;
        } else {
        invalid_type:
            p->type = 0;
            p->spec.total_size = 0;
            cardi_common.cmd->result = CARD_RESULT_UNSUPPORTED;
            return;
        }
    }
}

void CARDi_IdentifyBackupCore(CARDiCommon *p) {
    (void)CARDi_Request(p, CARD_REQ_IDENTIFY, 1);
    p->cmd->src = 0;
    p->cmd->dest = (u32)backup_cache_page_buf;
    p->cmd->len = 1;
    (void)CARDi_Request(p, CARD_REQ_READ_BACKUP, 1);
}

void func_0200cf78(u32 access, MIDmaCallback callback, void *arg) {
    SDK_USING_BACKUP();
    CARD_CheckEnabled();
    if ((CARDi_GetAccessLevel() & access) != access) {
        OS_Terminate();
    }
    (void)CARDi_WaitForTask(&cardi_common, TRUE, callback, arg);
}

BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async,
                                int req_type, int req_retry, int req_mode) {
    func_0200cf78((req_mode == CARD_REQUEST_MODE_RECV) ? 1 : 2, callback, arg);
    cardi_common.src = src;
    cardi_common.dst = dst;
    cardi_common.len = len;
    cardi_common.req_type = (u32)req_type;
    cardi_common.req_retry = req_retry;
    cardi_common.req_mode = (u32)req_mode;
    return CARDi_ExecuteOldTypeTask(CARDi_RequestStreamCommandCore, is_async);
}

BOOL CARD_IdentifyBackup(int type) {
    if (type == 0) {
        OS_Terminate();
    }
    func_0200cf78(0, NULL, NULL);
    CARDi_IdentifyBackupCore2(type);
    return CARDi_ExecuteOldTypeTask(CARDi_IdentifyBackupCore, FALSE);
}

u32 CARD_GetCurrentBackupType(void) {
    return cardi_common.cmd->type;
}

u32 CARD_GetBackupTotalSize(void) {
    return cardi_common.cmd->spec.total_size;
}

u32 CARD_GetBackupSectorSize(void) {
    return cardi_common.cmd->spec.sect_size;
}

u32 CARD_GetBackupPageSize(void) {
    return cardi_common.cmd->spec.page_size;
}

BOOL CARD_WaitBackupAsync(void) {
    return CARDi_WaitAsync();
}

BOOL CARD_TryWaitBackupAsync(void) {
    return CARDi_TryWaitAsync();
}
