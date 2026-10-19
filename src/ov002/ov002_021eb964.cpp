#include "ov002/ov002.h"

extern "C" {

int STD_CompareNString(const char *a, const char *b, int n);
extern char data_ov002_021f0d1e[];
extern char data_ov002_021f0d26[];
extern char data_ov002_021f0d2e[];
extern char data_ov002_021f0d36[];
extern char data_ov002_021f0d3e[];
extern char data_ov002_021f0d46[];
extern char data_ov002_021f0d4e[];
extern char data_ov002_021f0d56[];
extern char data_ov002_021f0d5e[];
extern char data_ov002_021f0d66[];
extern char data_ov002_021f0d6e[];
extern char data_ov002_021f0d75[];
extern char data_ov002_021f0d7d[];

void func_ov002_021eb964(void *self) {
    s32 texSize;
    s32 sneSize;
    char *p = FIELD(self, 0x8, char *) + 0x10;
    while (TRUE) {
        if (STD_CompareNString(p, data_ov002_021f0d1e, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x10, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d26, 8) == 0) {
            s32 hdr[2];
            s32 sz;
            s32 n;
            char *q;
            int i;
            FIELD(self, 0x14, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            n = hdr[0];
            q = p + 0x10;
            sz = hdr[1];
            for (i = 0; i < n; i++) {
                s16 len;
                MI_CpuCopy8(q + 0x12, &len, 2);
                q += len + sz;
            }
            p = q + 8;
        } else if (STD_CompareNString(p, data_ov002_021f0d2e, 8) == 0) {
            FIELD(self, 0x18, char *) = p;
            MI_CpuCopy8(p + 0xc, &texSize, 4);
            p += texSize + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d36, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x1c, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d3e, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x20, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d46, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x24, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d4e, 8) == 0) {
            s32 hdr[2];
            s32 sz;
            s32 n;
            char *q;
            int i;
            FIELD(self, 0x30, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            n = hdr[0];
            q = p + 0x10;
            sz = hdr[1];
            for (i = 0; i < n; i++) {
                s16 len;
                MI_CpuCopy8(q + 0x14, &len, 2);
                q += len + sz;
            }
            p = q + 8;
        } else if (STD_CompareNString(p, data_ov002_021f0d56, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x28, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d5e, 8) == 0) {
            FIELD(self, 0x2c, char *) = p;
            MI_CpuCopy8(p + 0xc, &sneSize, 4);
            p += sneSize + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d66, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x34, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d6e, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x38, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d75, 8) == 0) {
            s32 hdr[2];
            FIELD(self, 0x3c, char *) = p;
            MI_CpuCopy8(p + 8, hdr, 8);
            p += hdr[0] * hdr[1] + 0x18;
        } else if (STD_CompareNString(p, data_ov002_021f0d7d, 8) == 0) {
            break;
        }
    }
}

}
