#ifndef MSL_ANSI_FILES_H
#define MSL_ANSI_FILES_H

#include "types.h"

// MSL C stdio file record (FILE).

typedef struct MSLFileModes {
    u32 open_mode : 2;
    u32 io_mode : 3;
    u32 buffer_mode : 2;
    u32 file_kind : 3;
    u32 file_orientation : 2;
    u32 binary_io : 1;
} MSLFileModes;

typedef struct MSLFileStates {
    u32 io_state : 3;
    u32 free_buffer : 1;
    u8 eof;
    u8 error;
} MSLFileStates;

typedef int (*MSLIOProc)(u32 handle, u8 *buf, u32 *count, void *ref);

typedef struct MSLFile {
    /* 0x00 */ u32 handle;
    /* 0x04 */ MSLFileModes mode;
    /* 0x08 */ MSLFileStates state;
    /* 0x10 */ u8 unk_10[8];
    /* 0x18 */ u32 position;
    /* 0x1c */ u8 *buffer;
    /* 0x20 */ u32 buffer_size;
    /* 0x24 */ u8 *buffer_ptr;
    /* 0x28 */ u32 buffer_len;
    /* 0x2c */ u32 buffer_alignment;
    /* 0x30 */ u32 saved_buffer_len;
    /* 0x34 */ u32 buffer_pos;
    /* 0x38 */ MSLIOProc position_proc;
    /* 0x3c */ MSLIOProc read_proc;
    /* 0x40 */ MSLIOProc write_proc;
    /* 0x44 */ MSLIOProc close_proc;
    /* 0x48 */ void *ref_con;
} MSLFile; // size 0x4c

#define MSL_FILE_COUNT 3

extern MSLFile data_0208aa80[MSL_FILE_COUNT];

int __flush_all(void);
void __convert_from_newlines(u8 *buf, u32 *count);
void __prep_buffer(MSLFile *file);
int __flush_buffer(MSLFile *file, u32 *bytes_flushed);
int fflush(MSLFile *file);

#endif
