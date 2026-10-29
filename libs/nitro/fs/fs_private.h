#ifndef FS_PRIVATE_H
#define FS_PRIVATE_H

#include "nitro/os.h"
#include "nitro/mi.h"

typedef u32 FSResult;
typedef u32 FSCommandType;

#define FS_RESULT_SUCCESS       0
#define FS_RESULT_FAILURE       1
#define FS_RESULT_BUSY          2
#define FS_RESULT_CANCELED      3
#define FS_RESULT_UNSUPPORTED   4
#define FS_RESULT_ERROR         5
#define FS_RESULT_INVALID_PARAMETER 6
#define FS_RESULT_PROC_ASYNC    0x100
#define FS_RESULT_PROC_DEFAULT  0x101
#define FS_RESULT_PROC_UNKNOWN  0x102

#define FS_COMMAND_READFILE           0
#define FS_COMMAND_WRITEFILE          1
#define FS_COMMAND_SEEKDIR            2
#define FS_COMMAND_READDIR            3
#define FS_COMMAND_FINDPATH           4
#define FS_COMMAND_GETPATH            5
#define FS_COMMAND_OPENFILEFAST       6
#define FS_COMMAND_OPENFILEDIRECT     7
#define FS_COMMAND_CLOSEFILE          8
#define FS_COMMAND_ACTIVATE           9
#define FS_COMMAND_IDLE               10
#define FS_COMMAND_SUSPEND            11
#define FS_COMMAND_RESUME             12
#define FS_COMMAND_OPENFILE           13
#define FS_COMMAND_SEEKFILE           14
#define FS_COMMAND_GETFILELENGTH      15
#define FS_COMMAND_GETFILEPOSITION    16
#define FS_COMMAND_MOUNT              17
#define FS_COMMAND_UNMOUNT            18
#define FS_COMMAND_GETARCHIVECAPS     19
#define FS_COMMAND_CREATEFILE         20
#define FS_COMMAND_DELETEFILE         21
#define FS_COMMAND_RENAMEFILE         22
#define FS_COMMAND_GETPATHINFO        23
#define FS_COMMAND_SETPATHINFO        24
#define FS_COMMAND_CREATEDIRECTORY    25
#define FS_COMMAND_DELETEDIRECTORY    26
#define FS_COMMAND_RENAMEDIRECTORY    27
#define FS_COMMAND_GETARCHIVERESOURCE 28
#define FS_COMMAND_FLUSHFILE          30
#define FS_COMMAND_SETFILELENGTH      31
#define FS_COMMAND_OPENDIRECTORY      32
#define FS_COMMAND_CLOSEDIRECTORY     33
#define FS_COMMAND_SETSEEKCACHE       34
#define FS_COMMAND_MAX                35
#define FS_COMMAND_INVALID            35

#define FS_FILE_STATUS_BUSY        0x00000001
#define FS_FILE_STATUS_CANCEL      0x00000002
#define FS_FILE_STATUS_BLOCKING    0x00000004
#define FS_FILE_STATUS_ASYNC_DONE  0x00000008
#define FS_FILE_STATUS_IS_FILE     0x00000010
#define FS_FILE_STATUS_IS_DIR      0x00000020
#define FS_FILE_STATUS_OPERATING   0x00000040
#define FS_FILE_STATUS_UNICODE_MODE 0x00000080
#define FS_FILE_STATUS_CMD_SHIFT   8
#define FS_FILE_STATUS_CMD_MASK    0x000000ff

#define FS_ARCHIVE_FLAG_REGISTER   0x00000001
#define FS_ARCHIVE_FLAG_LOADED     0x00000002
#define FS_ARCHIVE_FLAG_TABLE_LOAD 0x00000004
#define FS_ARCHIVE_FLAG_SUSPEND    0x00000008
#define FS_ARCHIVE_FLAG_RUNNING    0x00000010
#define FS_ARCHIVE_FLAG_CANCELING  0x00000020
#define FS_ARCHIVE_FLAG_SUSPENDING 0x00000040
#define FS_ARCHIVE_FLAG_UNLOADING  0x00000080

#define FS_ENTRY_LONGNAME_MAX 0x104
#define FS_ARCHIVE_FULLPATH_MAX 0x118

struct FSArchive;
struct FSFile;

typedef struct FSFileID {
    struct FSArchive *arc;
    u32 file_id;
} FSFileID;

typedef struct FSDirPos {
    struct FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;

typedef struct FSFile {
    struct FSFile *next;        // 0x00
    void *userdata;             // 0x04
    struct FSArchive *arc;      // 0x08
    u32 stat;                   // 0x0c
    void *argument;             // 0x10
    FSResult error;             // 0x14
    OSThreadQueue queue[1];     // 0x18
    union {
        u8 reserved1[16];
        struct {
            u32 own_id;
            u32 top;
            u32 bottom;
            u32 pos;
        } file;
        struct {
            FSDirPos pos;
            u32 parent;
        } dir;
    } prop;                     // 0x20
    union {
        u8 reserved2[24];
        u32 words[6];
    } arg;                      // 0x30
} FSFile; // size 0x48

typedef struct FSArchiveResource {
    u32 words[8];
} FSArchiveResource;

typedef struct FSArchive {
    union {
        char pack[4];
        char *ptr;
    } name;                     // 0x00
    struct FSArchive *next;     // 0x04
    FSFile *list;               // 0x08
    OSThreadQueue queue;        // 0x0c
    u32 flag;                   // 0x14
    FSCommandType command;      // 0x18
    FSResult result;            // 0x1c
    void *userdata;             // 0x20
    const struct FSArchiveInterface *vtbl; // 0x24
    u8 reserved[0x34];          // 0x28
} FSArchive; // size 0x5c

typedef struct FSArgumentForReadFile {
    void *buffer;
    u32 length;
} FSArgumentForReadFile;

typedef struct FSArgumentForWriteFile {
    const void *buffer;
    u32 length;
} FSArgumentForWriteFile;

typedef struct FSArgumentForSeekDirectory {
    u32 id;
    u32 position;
} FSArgumentForSeekDirectory;

typedef struct FSArgumentForReadDirectory {
    void *info;
} FSArgumentForReadDirectory;

typedef struct FSArgumentForFindPath {
    u32 baseid;
    const char *relpath;
    u32 target_id;
    BOOL target_is_directory;
} FSArgumentForFindPath;

typedef struct FSArgumentForGetPath {
    u8 *buffer;
    u32 length;
    BOOL is_directory;
} FSArgumentForGetPath;

typedef struct FSArgumentForOpenFileFast {
    u32 id;
    u32 mode;
} FSArgumentForOpenFileFast;

typedef struct FSArgumentForOpenFileDirect {
    u32 id;
    u32 top;
    u32 bottom;
    u32 mode;
} FSArgumentForOpenFileDirect;

typedef struct FSArgumentForOpenFile {
    u32 baseid;
    const char *relpath;
    u32 mode;
} FSArgumentForOpenFile;

typedef struct FSArgumentForSeekFile {
    int offset;
    u32 from;
} FSArgumentForSeekFile;

typedef struct FSArgumentForGetFileLength {
    u32 length;
} FSArgumentForGetFileLength;

typedef struct FSArgumentForGetFilePosition {
    u32 position;
} FSArgumentForGetFilePosition;

typedef struct FSArgumentForGetArchiveCaps {
    u32 caps;
} FSArgumentForGetArchiveCaps;

typedef struct FSArgumentForCreateFile {
    u32 baseid;
    const char *relpath;
    u32 permit;
} FSArgumentForCreateFile;

typedef struct FSArgumentForDeleteFile {
    u32 baseid;
    const char *relpath;
} FSArgumentForDeleteFile;

typedef struct FSArgumentForRenameFile {
    u32 baseid_src;
    const char *relpath_src;
    u32 baseid_dst;
    const char *relpath_dst;
} FSArgumentForRenameFile;

typedef struct FSArgumentForGetPathInfo {
    u32 baseid;
    const char *relpath;
    void *info;
} FSArgumentForGetPathInfo;

typedef FSArgumentForGetPathInfo FSArgumentForSetPathInfo;
typedef FSArgumentForCreateFile FSArgumentForCreateDirectory;
typedef FSArgumentForDeleteFile FSArgumentForDeleteDirectory;
typedef FSArgumentForRenameFile FSArgumentForRenameDirectory;

typedef struct FSArgumentForGetArchiveResource {
    FSArchiveResource *resource;
} FSArgumentForGetArchiveResource;

typedef struct FSArgumentForSetFileLength {
    u32 length;
} FSArgumentForSetFileLength;

typedef struct FSArgumentForOpenDirectory {
    u32 baseid;
    const char *relpath;
    u32 mode;
} FSArgumentForOpenDirectory;

typedef struct FSArgumentForSetSeekCache {
    void *buf;
    u32 buf_size;
} FSArgumentForSetSeekCache;

typedef struct FSArchiveInterface {
    FSResult (*ReadFile)(FSArchive *, FSFile *, void *, u32 *);
    FSResult (*WriteFile)(FSArchive *, FSFile *, const void *, u32 *);
    FSResult (*SeekDirectory)(FSArchive *, FSFile *, u32, u32);
    FSResult (*ReadDirectory)(FSArchive *, FSFile *, void *);
    FSResult (*FindPath)(FSArchive *, u32, const char *, u32 *, BOOL);
    FSResult (*GetPath)(FSArchive *, FSFile *, BOOL, char *, u32 *);
    FSResult (*OpenFileFast)(FSArchive *, FSFile *, u32, u32);
    FSResult (*OpenFileDirect)(FSArchive *, FSFile *, u32, u32, u32 *);
    FSResult (*CloseFile)(FSArchive *, FSFile *);
    void (*Activate)(FSArchive *);
    void (*Idle)(FSArchive *);
    void (*Suspend)(FSArchive *);
    void (*Resume)(FSArchive *);
    FSResult (*OpenFile)(FSArchive *, FSFile *, u32, const char *, u32);
    FSResult (*SeekFile)(FSArchive *, FSFile *, int *, u32);
    FSResult (*GetFileLength)(FSArchive *, FSFile *, u32 *);
    FSResult (*GetFilePosition)(FSArchive *, FSFile *, u32 *);
    void (*Mount)(FSArchive *);
    void (*Unmount)(FSArchive *);
    FSResult (*GetArchiveCaps)(FSArchive *, u32 *);
    FSResult (*CreateFile)(FSArchive *, u32, const char *, u32);
    FSResult (*DeleteFile)(FSArchive *, u32, const char *);
    FSResult (*RenameFile)(FSArchive *, u32, const char *, u32, const char *);
    FSResult (*GetPathInfo)(FSArchive *, u32, const char *, void *);
    FSResult (*SetPathInfo)(FSArchive *, u32, const char *, void *);
    FSResult (*CreateDirectory)(FSArchive *, u32, const char *, u32);
    FSResult (*DeleteDirectory)(FSArchive *, u32, const char *);
    FSResult (*RenameDirectory)(FSArchive *, u32, const char *, u32, const char *);
    FSResult (*GetArchiveResource)(FSArchive *, FSArchiveResource *);
    void *unused_29;
    FSResult (*FlushFile)(FSArchive *, FSFile *);
    FSResult (*SetFileLength)(FSArchive *, FSFile *, u32);
    FSResult (*OpenDirectory)(FSArchive *, FSFile *, u32, const char *, u32);
    FSResult (*CloseDirectory)(FSArchive *, FSFile *);
    FSResult (*SetSeekCache)(FSArchive *, FSFile *, void *, u32);
} FSArchiveInterface;

static inline BOOL FS_IsBusy(volatile const FSFile *file) {
    return (file->stat & FS_FILE_STATUS_BUSY) ? TRUE : FALSE;
}

static inline BOOL FS_IsCanceling(volatile const FSFile *file) {
    return (file->stat & FS_FILE_STATUS_CANCEL) ? TRUE : FALSE;
}

static inline BOOL FS_IsSucceeded(volatile const FSFile *file) {
    return (file->error == FS_RESULT_SUCCESS) ? TRUE : FALSE;
}

static inline BOOL FS_IsFile(volatile const FSFile *file) {
    return (file->stat & FS_FILE_STATUS_IS_FILE) ? TRUE : FALSE;
}

static inline BOOL FS_IsDir(volatile const FSFile *file) {
    return (file->stat & FS_FILE_STATUS_IS_DIR) ? TRUE : FALSE;
}

static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *arc) {
    return (arc->flag & FS_ARCHIVE_FLAG_LOADED) ? TRUE : FALSE;
}

static inline BOOL FS_IsArchiveSuspended(volatile const FSArchive *arc) {
    return (arc->flag & FS_ARCHIVE_FLAG_SUSPEND) ? TRUE : FALSE;
}

static inline FSCommandType FSi_GetCurrentCommand(const FSFile *file) {
    return (FSCommandType)((file->stat >> FS_FILE_STATUS_CMD_SHIFT) & FS_FILE_STATUS_CMD_MASK);
}

static inline BOOL FSi_IsSlash(u32 c) {
    return (c == '/') || (c == '\\');
}

static inline BOOL STD_IsSjisLeadByte(s32 c) {
    return (u32)(((u8)c ^ 0x20) - 0xa1) < 0x3c;
}

static inline BOOL STD_IsSjisTrailByte(s32 c) {
    return (c != 0x7f) && ((u8)(c - 0x40) <= 0xbc);
}

static inline int FSi_IncrementSjisPosition(const char *str, int pos) {
    return pos + 1 + STD_IsSjisLeadByte(str[pos]);
}

int STD_CompareNString(const char *str1, const char *str2, int len);
int STD_CopyLString(char *dst, const char *src, int len);
int STD_GetStringLength(const char *str);
void OS_Terminate(void);
BOOL OS_IsRunOnTwl(void);
u16 OS_GetBootType(void);

void FS_InitFile(FSFile *file);
FSArchive *FS_FindArchive(const char *name, int name_len);
const char *FS_GetArchiveName(const FSArchive *arc);
FSArchive *FS_NormalizePath(const char *path, u32 *baseid, char *relpath);
BOOL FSi_SendCommand(FSFile *file, FSCommandType command, BOOL blocking);
int FSi_DecrementSjisPosition(const char *str, int pos);
int FSi_IncrementSjisPositionToSlash(const char *str, int pos);
int FSi_DecrementSjisPositionToSlash(const char *str, int pos);
int FSi_TrimSjisTrailingSlash(char *str);

#endif
