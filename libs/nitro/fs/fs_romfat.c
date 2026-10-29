#include "fs_private.h"

#pragma force_active on

typedef struct FSROMFATArchiveContext {
    FSArchive *base;            // 0x00
    u32 fat;                    // 0x04
    u32 fat_size;               // 0x08
    u32 fnt;                    // 0x0c
    u32 fnt_size;               // 0x10
    u32 fat_bak;                // 0x14
    u32 fnt_bak;                // 0x18
    void *load_mem;             // 0x1c
    FSResult (*read_func)(FSArchive *, void *, u32, u32);        // 0x20
    FSResult (*write_func)(FSArchive *, const void *, u32, u32); // 0x24
    FSResult (*table_func)(FSArchive *, void *, u32, u32);       // 0x28
    FSResult (*proc)(FSFile *, FSCommandType);                   // 0x2c
    u32 proc_flag;              // 0x30
} FSROMFATArchiveContext;

typedef struct FSROMFATProperty {
    u32 own_id;
    u32 top;
    u32 bottom;
    u32 pos;
} FSROMFATProperty;

typedef struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry;

typedef struct FSiSyncReadParam {
    FSArchive *arc;
    u32 pos;
} FSiSyncReadParam;

typedef struct FSArchiveFAT {
    u32 top;
    u32 bottom;
} FSArchiveFAT;

typedef struct FSDirTableFormat {
    u32 entry_start;
    u16 entry_file_id;
    u16 parent_id;
} FSDirTableFormat;

typedef struct FSDateTime {
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 second;
} FSDateTime;

typedef struct FSDirectoryEntryInfo {
    char shortname[16];
    u32 shortname_length;
    char longname[FS_ENTRY_LONGNAME_MAX];
    u32 longname_length;
    u32 attributes;
    FSDateTime atime;
    FSDateTime mtime;
    FSDateTime ctime;
    u32 filesize;
    u32 id;
} FSDirectoryEntryInfo;

typedef struct FSPathInfo {
    u32 attributes;
    FSDateTime ctime;
    FSDateTime mtime;
    FSDateTime atime;
    u32 filesize;
    u32 id;
} FSPathInfo;

#define FS_ATTRIBUTE_IS_DIRECTORY 0x00000100
#define FS_ATTRIBUTE_IS_PROTECTED 0x00000200
#define FS_ATTRIBUTE_IS_OFFLINE   0x00000400
#define FS_RESULT_NO_ENTRY        11
#define FS_FILE_NAME_MAX          127
#define FS_SEEK_SET 0
#define FS_SEEK_CUR 1
#define FS_SEEK_END 2

typedef struct FSROMFATArgReadFile { void *dst; u32 len_org; u32 len; } FSROMFATArgReadFile;
typedef struct FSROMFATArgSeekDir { FSDirPos pos; } FSROMFATArgSeekDir;
typedef struct FSROMFATArgReadDir { FSDirEntry *p_entry; BOOL skip_string; } FSROMFATArgReadDir;
typedef struct FSROMFATArgFindPath {
    FSDirPos pos;
    const char *path;
    BOOL find_directory;
    union { FSFileID *file; FSDirPos *dir; } result;
} FSROMFATArgFindPath;
typedef struct FSROMFATArgGetPath { u8 *buf; u32 buf_len; u16 total_len; u16 dir_id; } FSROMFATArgGetPath;
typedef struct FSROMFATArgOpenFileFast { FSFileID id; } FSROMFATArgOpenFileFast;
typedef struct FSROMFATArgOpenFileDirect { u32 top; u32 bottom; u32 index; } FSROMFATArgOpenFileDirect;

#define ARG(file, type) ((type *)&(file)->arg)
#define CONTEXT(arc) ((FSROMFATArchiveContext *)(arc)->userdata)

extern const char data_0208af40[];
extern FSResult (*const data_02070f2c[])(FSFile *);
BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset);
BOOL FS_IsArchiveTableLoaded(FSArchive *arc);
FSResult FSi_WaitForArchiveCompletion(FSFile *file, FSResult result);

FSResult FSi_ROMFAT_TranslateCommand(FSFile *file, FSCommandType command, BOOL block);
FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory);
FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode);
FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position);

static inline void FS_SetFileHandle(FSFile *file, FSArchive *arc, void *userdata) {
    file->stat |= FS_FILE_STATUS_IS_FILE;
    file->stat &= ~FS_FILE_STATUS_IS_DIR;
    file->arc = arc;
    file->userdata = userdata;
}

static inline void FS_SetDirectoryHandle(FSFile *file, FSArchive *arc, void *userdata) {
    file->stat |= FS_FILE_STATUS_IS_DIR;
    file->stat &= ~FS_FILE_STATUS_IS_FILE;
    file->arc = arc;
    file->userdata = userdata;
}

static inline void FS_DetachHandle(FSFile *file) {
    file->userdata = NULL;
    file->stat &= ~(FS_FILE_STATUS_IS_FILE | FS_FILE_STATUS_IS_DIR);
}

static inline int FSi_StrNICmp(const char *str1, const char *str2, u32 len) {
    int retval = 0;
    int i;
    for (i = 0; i < len; ++i) {
        u32 c = (u8)(str1[i] - 'A');
        u32 d = (u8)(str2[i] - 'A');
        if (c <= 'Z' - 'A') {
            c += 'a' - 'A';
        }
        if (d <= 'Z' - 'A') {
            d += 'a' - 'A';
        }
        retval = (int)(c - d);
        if (retval != 0) {
            break;
        }
    }
    return retval;
}

FSResult FSi_ReadTable(FSiSyncReadParam *p, void *dst, u32 len) {
    FSResult result;
    FSArchive *const arc = p->arc;
    FSROMFATArchiveContext *const context = CONTEXT(arc);
    if (context->load_mem) {
        MI_CpuCopy8((const void *)p->pos, dst, len);
        result = FS_RESULT_SUCCESS;
    } else {
        result = (*context->read_func)(arc, dst, p->pos, len);
        result = FSi_WaitForArchiveCompletion(arc->list, result);
    }
    p->pos += len;
    return result;
}

void FSi_SeekDirDirect(FSFile *file, u32 id) {
    FSROMFATArgSeekDir *arg = ARG(file, FSROMFATArgSeekDir);
    arg->pos.arc = file->arc;
    arg->pos.own_id = (u16)id;
    arg->pos.index = 0;
    arg->pos.pos = 0;
    (void)FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_SEEKDIR, TRUE);
}

FSResult FSi_SeekDirCommand(FSFile *file) {
    FSResult result;
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = CONTEXT(arc);
    const FSDirPos *const arg = &ARG(file, FSROMFATArgSeekDir)->pos;
    FSDirTableFormat table;
    FSiSyncReadParam param;
    param.arc = arc;
    param.pos = context->fnt + arg->own_id * sizeof(FSDirTableFormat);
    result = FSi_ReadTable(&param, &table, sizeof(table));
    if (result == FS_RESULT_SUCCESS) {
        file->prop.dir.pos = *arg;
        if ((arg->index == 0) && (arg->pos == 0)) {
            file->prop.dir.pos.index = table.entry_file_id;
            file->prop.dir.pos.pos = context->fnt + table.entry_start;
        }
        file->prop.dir.parent = (u32)(table.parent_id & 0x0FFF);
    }
    return result;
}

FSResult FSi_ReadDirCommand(FSFile *file) {
    FSDirEntry *const entry = ARG(file, FSROMFATArgReadDir)->p_entry;
    FSResult result;
    u8 len;
    u16 id;
    FSiSyncReadParam param;
    param.arc = file->arc;
    param.pos = file->prop.dir.pos.pos;
    result = FSi_ReadTable(&param, &len, sizeof(len));
    if (result != FS_RESULT_SUCCESS) {
        return result;
    }
    entry->name_len = (u32)(len & 0x7f);
    entry->is_directory = (u32)((len >> 7) & 1);
    if (entry->name_len == 0) {
        return FS_RESULT_FAILURE;
    }
    if (!ARG(file, FSROMFATArgReadDir)->skip_string) {
        result = FSi_ReadTable(&param, entry->name, entry->name_len);
        if (result != FS_RESULT_SUCCESS) {
            return result;
        }
        entry->name[entry->name_len] = '\0';
    } else {
        param.pos += entry->name_len;
    }
    if (!entry->is_directory) {
        entry->file_id.arc = file->arc;
        entry->file_id.file_id = file->prop.dir.pos.index;
        ++file->prop.dir.pos.index;
    } else {
        result = FSi_ReadTable(&param, &id, sizeof(id));
        if (result == FS_RESULT_SUCCESS) {
            entry->dir_id.arc = file->arc;
            entry->dir_id.own_id = (u16)(id & 0x0FFF);
            entry->dir_id.index = 0;
            entry->dir_id.pos = 0;
        }
    }
    if (result == FS_RESULT_SUCCESS) {
        file->prop.dir.pos.pos = param.pos;
    }
    return result;
}

FSResult FSi_FindPathCommand(FSFile *p_dir) {
    FSROMFATArgFindPath *const arg = ARG(p_dir, FSROMFATArgFindPath);
    const char *path = arg->path;
    const BOOL is_dir = arg->find_directory;

    (void)FSi_ROMFAT_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);
    for (; *path; path += (*path ? 1 : 0)) {
        int name_len = FSi_IncrementSjisPositionToSlash(path, 0);
        u32 is_directory = ((path[name_len] != '\0') || is_dir);
        if (name_len == 0) {
            return FS_RESULT_INVALID_PARAMETER;
        } else if (*path == '.') {
            if (name_len == 1) {
                path += 1;
                continue;
            } else if ((name_len == 2) && (path[1] == '.')) {
                if (p_dir->prop.dir.pos.own_id != 0) {
                    FSi_SeekDirDirect(p_dir, p_dir->prop.dir.parent);
                }
                path += 2;
                continue;
            }
        } else if (*path == '*') {
            break;
        }
        if (name_len > FS_FILE_NAME_MAX) {
            return FS_RESULT_NO_ENTRY;
        } else {
            FSDirEntry etr;
            ARG(p_dir, FSROMFATArgReadDir)->p_entry = &etr;
            ARG(p_dir, FSROMFATArgReadDir)->skip_string = FALSE;
            for (;;) {
                if (FSi_ROMFAT_TranslateCommand(p_dir, FS_COMMAND_READDIR, TRUE) != FS_RESULT_SUCCESS) {
                    return FS_RESULT_NO_ENTRY;
                }
                if ((is_directory == etr.is_directory) && (name_len == etr.name_len) &&
                    (FSi_StrNICmp(path, etr.name, (u32)name_len) == 0)) {
                    if (is_directory) {
                        path += name_len;
                        ARG(p_dir, FSROMFATArgSeekDir)->pos = etr.dir_id;
                        (void)FSi_ROMFAT_TranslateCommand(p_dir, FS_COMMAND_SEEKDIR, TRUE);
                        break;
                    } else if (is_dir) {
                        return FS_RESULT_NO_ENTRY;
                    } else {
                        *arg->result.file = etr.file_id;
                        return FS_RESULT_SUCCESS;
                    }
                }
            }
        }
    }
    if (!is_dir) {
        return FS_RESULT_NO_ENTRY;
    }
    *arg->result.dir = p_dir->prop.dir.pos;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_GetPathCommand(FSFile *file) {
    FSArchive *const arc = file->arc;
    FSROMFATArgGetPath *p_info = ARG(file, FSROMFATArgGetPath);
    FSDirEntry entry;
    FSFile tmp;
    u32 dir_id;
    u32 file_id;
    u32 id;

    FS_InitFile(&tmp);
    tmp.arc = arc;
    if (FS_IsDir(file)) {
        dir_id = file->prop.dir.pos.own_id;
        file_id = 0x10000;
    } else {
        u32 pos = 0;
        u32 num_dir = 0;
        file_id = file->prop.file.own_id;
        dir_id = 0x10000;
        do {
            FSi_SeekDirDirect(&tmp, pos);
            if (pos == 0) {
                num_dir = tmp.prop.dir.parent;
            }
            ARG(&tmp, FSROMFATArgReadDir)->p_entry = &entry;
            ARG(&tmp, FSROMFATArgReadDir)->skip_string = TRUE;
            while (FSi_ROMFAT_TranslateCommand(&tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                if (!entry.is_directory && (entry.file_id.file_id == file_id)) {
                    dir_id = tmp.prop.dir.pos.own_id;
                    break;
                }
            }
        } while ((dir_id == 0x10000) && (++pos < num_dir));
    }
    if (dir_id == 0x10000) {
        p_info->total_len = 0;
        return FS_RESULT_NO_ENTRY;
    }
    {
        u32 total;
        id = dir_id;
        total = (u32)STD_GetStringLength(FS_GetArchiveName(arc)) + 2;
        FSi_SeekDirDirect(&tmp, id);
        if (file_id != 0x10000) {
            total += entry.name_len;
        }
        while (id != 0) {
            FSi_SeekDirDirect(&tmp, tmp.prop.dir.parent);
            ARG(&tmp, FSROMFATArgReadDir)->p_entry = &entry;
            ARG(&tmp, FSROMFATArgReadDir)->skip_string = TRUE;
            while (FSi_ROMFAT_TranslateCommand(&tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                if (entry.is_directory && (entry.dir_id.own_id == id)) {
                    total += entry.name_len + 1;
                    break;
                }
            }
            id = tmp.prop.dir.pos.own_id;
        }
        p_info->total_len = (u16)(total + 1);
        p_info->dir_id = (u16)dir_id;
    }
    if (p_info->buf) {
        u8 *const dst = p_info->buf;
        u32 total = p_info->total_len;
        if (p_info->buf_len >= total) {
            {
                const char *name = FS_GetArchiveName(arc);
                int len = STD_GetStringLength(name);
                int pos = 0;
                MI_CpuCopy8(name, dst + pos, (u32)len);
                pos += len;
                MI_CpuCopy8(data_0208af40, dst + pos, 2);
            }
            FSi_SeekDirDirect(&tmp, dir_id);
            if (file_id != 0x10000) {
                u32 len;
                ARG(&tmp, FSROMFATArgReadDir)->p_entry = &entry;
                ARG(&tmp, FSROMFATArgReadDir)->skip_string = FALSE;
                while (FSi_ROMFAT_TranslateCommand(&tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                    if (!entry.is_directory && (entry.file_id.file_id == file_id)) {
                        break;
                    }
                }
                len = entry.name_len + 1;
                MI_CpuCopy8(entry.name, dst + total - len, len);
                total -= len;
            } else {
                *(dst + total - 1) = '\0';
                total -= 1;
            }
            id = dir_id;
            while (id != 0) {
                FSi_SeekDirDirect(&tmp, tmp.prop.dir.parent);
                ARG(&tmp, FSROMFATArgReadDir)->p_entry = &entry;
                ARG(&tmp, FSROMFATArgReadDir)->skip_string = FALSE;
                dst[total - 1] = '/';
                total -= 1;
                while (FSi_ROMFAT_TranslateCommand(&tmp, FS_COMMAND_READDIR, TRUE) == FS_RESULT_SUCCESS) {
                    if (entry.is_directory && (entry.dir_id.own_id == id)) {
                        u32 len = entry.name_len;
                        MI_CpuCopy8(entry.name, dst + total - len, len);
                        total -= len;
                        break;
                    }
                }
                id = tmp.prop.dir.pos.own_id;
            }
        }
    }
    return FS_RESULT_SUCCESS;
}

FSResult FSi_OpenFileFastCommand(FSFile *file) {
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = CONTEXT(arc);
    const u32 index = ARG(file, FSROMFATArgOpenFileFast)->id.file_id;
    FSResult result;
    u32 pos = index * sizeof(FSArchiveFAT);
    if (pos >= context->fat_size) {
        return FS_RESULT_NO_ENTRY;
    } else {
        FSArchiveFAT fat;
        FSiSyncReadParam param;
        param.arc = arc;
        param.pos = context->fat + pos;
        result = FSi_ReadTable(&param, &fat, sizeof(fat));
        if (result == FS_RESULT_SUCCESS) {
            ARG(file, FSROMFATArgOpenFileDirect)->top = fat.top;
            ARG(file, FSROMFATArgOpenFileDirect)->bottom = fat.bottom;
            ARG(file, FSROMFATArgOpenFileDirect)->index = index;
            result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_OPENFILEDIRECT, TRUE);
        }
    }
    return result;
}

FSResult FSi_OpenFileDirectCommand(FSFile *file) {
    file->prop.file.top = ARG(file, FSROMFATArgOpenFileDirect)->top;
    file->prop.file.pos = ARG(file, FSROMFATArgOpenFileDirect)->top;
    file->prop.file.bottom = ARG(file, FSROMFATArgOpenFileDirect)->bottom;
    file->prop.file.own_id = ARG(file, FSROMFATArgOpenFileDirect)->index;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ReadFileCommand(FSFile *file) {
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = CONTEXT(arc);
    const u32 pos = file->prop.file.pos;
    const u32 len = ARG(file, FSROMFATArgReadFile)->len;
    void *const dst = ARG(file, FSROMFATArgReadFile)->dst;
    file->prop.file.pos += len;
    return (*context->read_func)(arc, dst, pos, len);
}

FSResult FSi_WriteFileCommand(FSFile *file) {
    FSArchive *const arc = file->arc;
    FSROMFATArchiveContext *const context = CONTEXT(arc);
    const u32 pos = file->prop.file.pos;
    const u32 len = ARG(file, FSROMFATArgReadFile)->len;
    void *const dst = ARG(file, FSROMFATArgReadFile)->dst;
    file->prop.file.pos += len;
    return (*context->write_func)(arc, dst, pos, len);
}

FSResult FSi_CloseFileCommand(FSFile *file) {
    (void)file;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ROMFAT_TranslateCommand(FSFile *file, FSCommandType command, BOOL block) {
    int result = FS_RESULT_PROC_DEFAULT;
    FSROMFATArchiveContext *const context = CONTEXT(file->arc);
    if ((context->proc_flag & (1 << command)) != 0) {
        result = (int)(*context->proc)(file, command);
        switch (result) {
        case FS_RESULT_SUCCESS:
        case FS_RESULT_FAILURE:
        case FS_RESULT_UNSUPPORTED:
            break;
        case FS_RESULT_PROC_ASYNC:
            break;
        case FS_RESULT_PROC_UNKNOWN:
            result = FS_RESULT_PROC_DEFAULT;
            context->proc_flag &= ~(1 << command);
            break;
        }
    }
    if (result == FS_RESULT_PROC_DEFAULT) {
        if (command < 13) {
            result = (int)(*data_02070f2c[command])(file);
        } else {
            result = FS_RESULT_UNSUPPORTED;
        }
    }
    if (block) {
        result = (int)FSi_WaitForArchiveCompletion(file, (FSResult)result);
    }
    return (FSResult)result;
}

FSResult FSi_ROMFAT_ReadFile(FSArchive *arc, FSFile *file, void *buffer, u32 *length) {
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    const u32 len = *length;
    const u32 rest = prop->bottom - prop->pos;
    if (len > rest) {
        *length = rest;
    }
    ARG(file, FSROMFATArgReadFile)->len_org = len;
    ARG(file, FSROMFATArgReadFile)->dst = buffer;
    ARG(file, FSROMFATArgReadFile)->len = *length;
    (void)arc;
    return FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_READFILE, FALSE);
}

FSResult FSi_ROMFAT_WriteFile(FSArchive *arc, FSFile *file, const void *buffer, u32 *length) {
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    const u32 len = *length;
    const u32 rest = prop->bottom - prop->pos;
    if (len > rest) {
        *length = rest;
    }
    ARG(file, FSROMFATArgReadFile)->len_org = len;
    ARG(file, FSROMFATArgReadFile)->dst = (void *)buffer;
    ARG(file, FSROMFATArgReadFile)->len = *length;
    (void)arc;
    return FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_WRITEFILE, FALSE);
}

FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position) {
    FSResult result;
    file->arc = arc;
    ARG(file, FSROMFATArgSeekDir)->pos.arc = arc;
    ARG(file, FSROMFATArgSeekDir)->pos.own_id = (u16)(id >> 0);
    ARG(file, FSROMFATArgSeekDir)->pos.index = (u16)(id >> 16);
    ARG(file, FSROMFATArgSeekDir)->pos.pos = position;
    result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_SEEKDIR, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetDirectoryHandle(file, arc, &file->prop);
    }
    return result;
}

FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info) {
    FSResult result;
    FSDirEntry entry;
    ARG(file, FSROMFATArgReadDir)->p_entry = &entry;
    ARG(file, FSROMFATArgReadDir)->skip_string = FALSE;
    result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_READDIR, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        info->shortname_length = 0;
        info->longname_length = entry.name_len;
        MI_CpuCopy8(entry.name, info->longname, info->longname_length);
        info->longname[info->longname_length] = '\0';
        if (entry.is_directory) {
            info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
            info->id = (u32)(entry.dir_id.own_id | (entry.dir_id.index << 16));
            info->filesize = 0;
        } else {
            FSROMFATArchiveContext *context;
            u32 pos;
            info->attributes = 0;
            info->id = entry.file_id.file_id;
            info->filesize = 0;
            context = CONTEXT(arc);
            pos = info->id * sizeof(FSArchiveFAT);
            if (pos < context->fat_size) {
                FSArchiveFAT fat;
                FSiSyncReadParam param;
                param.arc = arc;
                param.pos = context->fat + pos;
                if (FSi_ReadTable(&param, &fat, sizeof(fat)) == FS_RESULT_SUCCESS) {
                    info->filesize = fat.bottom - fat.top;
                    if (FSi_IsUnreadableRomOffset(arc, fat.top)) {
                        info->attributes |= FS_ATTRIBUTE_IS_OFFLINE;
                    }
                }
            }
        }
        info->mtime.year = 0;
        info->mtime.month = 0;
        info->mtime.day = 0;
        info->mtime.hour = 0;
        info->mtime.minute = 0;
        info->mtime.second = 0;
    }
    return result;
}

FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory) {
    FSResult result;
    union {
        FSFileID file;
        FSDirPos dir;
    } id;
    FSFile tmp[1];
    FS_InitFile(tmp);
    tmp->arc = arc;
    ARG(tmp, FSROMFATArgFindPath)->pos.arc = arc;
    ARG(tmp, FSROMFATArgFindPath)->pos.own_id = (u16)base_dir_id;
    ARG(tmp, FSROMFATArgFindPath)->pos.index = 0;
    ARG(tmp, FSROMFATArgFindPath)->pos.pos = 0;
    ARG(tmp, FSROMFATArgFindPath)->path = path;
    ARG(tmp, FSROMFATArgFindPath)->find_directory = target_is_directory;
    ARG(tmp, FSROMFATArgFindPath)->result.dir = &id.dir;
    result = FSi_ROMFAT_TranslateCommand(tmp, FS_COMMAND_FINDPATH, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        if (target_is_directory) {
            *target_id = id.dir.own_id;
        } else {
            *target_id = id.file.file_id;
        }
    }
    return result;
}

FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length) {
    FSResult result;
    ARG(file, FSROMFATArgGetPath)->total_len = 0;
    ARG(file, FSROMFATArgGetPath)->dir_id = 0;
    ARG(file, FSROMFATArgGetPath)->buf = (u8 *)buffer;
    ARG(file, FSROMFATArgGetPath)->buf_len = *length;
    result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_GETPATH, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        *length = ARG(file, FSROMFATArgGetPath)->buf_len;
    }
    (void)arc;
    (void)is_directory;
    return result;
}

FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode) {
    FSResult result;
    ARG(file, FSROMFATArgOpenFileFast)->id.file_id = id;
    ARG(file, FSROMFATArgOpenFileFast)->id.arc = arc;
    result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_OPENFILEFAST, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetFileHandle(file, arc, &file->prop);
    }
    (void)mode;
    return result;
}

FSResult FSi_ROMFAT_OpenFileDirect(FSArchive *arc, FSFile *file, u32 top, u32 bottom, u32 *id) {
    FSResult result;
    ARG(file, FSROMFATArgOpenFileDirect)->top = top;
    ARG(file, FSROMFATArgOpenFileDirect)->bottom = bottom;
    ARG(file, FSROMFATArgOpenFileDirect)->index = *id;
    result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_OPENFILEDIRECT, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        FS_SetFileHandle(file, arc, &file->prop);
    }
    return result;
}

FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file) {
    FSResult result = FSi_ROMFAT_TranslateCommand(file, FS_COMMAND_CLOSEFILE, TRUE);
    FS_DetachHandle(file);
    (void)arc;
    return result;
}

void FSi_ROMFAT_Activate(FSArchive *arc) {
    FSFile tmp[1];
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_ROMFAT_TranslateCommand(tmp, FS_COMMAND_ACTIVATE, FALSE);
}

void FSi_ROMFAT_Idle(FSArchive *arc) {
    FSFile tmp[1];
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_ROMFAT_TranslateCommand(tmp, FS_COMMAND_IDLE, FALSE);
}

void FSi_ROMFAT_Suspend(FSArchive *arc) {
    FSFile tmp[1];
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_ROMFAT_TranslateCommand(tmp, FS_COMMAND_SUSPEND, FALSE);
}

void FSi_ROMFAT_Resume(FSArchive *arc) {
    FSFile tmp[1];
    FS_InitFile(tmp);
    tmp->arc = arc;
    (void)FSi_ROMFAT_TranslateCommand(tmp, FS_COMMAND_RESUME, FALSE);
}

FSResult FSi_ROMFAT_OpenFile(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode) {
    FSResult result;
    u32 fileid;
    result = FSi_ROMFAT_FindPath(arc, baseid, path, &fileid, FALSE);
    if (result == FS_RESULT_SUCCESS) {
        result = FSi_ROMFAT_OpenFileFast(arc, file, fileid, mode);
    }
    return result;
}

FSResult FSi_ROMFAT_SeekFile(FSArchive *arc, FSFile *file, int *offset, u32 from) {
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    int pos = *offset;
    switch (from) {
    case FS_SEEK_SET:
        pos += prop->top;
        break;
    case FS_SEEK_CUR:
    default:
        pos += prop->pos;
        break;
    case FS_SEEK_END:
        pos += prop->bottom;
        break;
    }
    if ((pos < (int)prop->top) || (pos > (int)prop->bottom)) {
        return FS_RESULT_INVALID_PARAMETER;
    }
    prop->pos = (u32)pos;
    *offset = pos;
    (void)arc;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ROMFAT_GetFileLength(FSArchive *arc, FSFile *file, u32 *length) {
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    *length = prop->bottom - prop->top;
    (void)arc;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ROMFAT_GetFilePosition(FSArchive *arc, FSFile *file, u32 *position) {
    FSROMFATProperty *prop = (FSROMFATProperty *)file->userdata;
    *position = prop->pos - prop->top;
    (void)arc;
    return FS_RESULT_SUCCESS;
}

void FSi_ROMFAT_Unmount(FSArchive *arc) {
    FSROMFATArchiveContext *context = CONTEXT(arc);
    FS_IsArchiveTableLoaded(arc);
    context->base = 0;
    context->fat = 0;
    context->fat_size = 0;
    context->fnt = 0;
    context->fnt_size = 0;
    context->fat_bak = 0;
    context->fnt_bak = 0;
}

FSResult FSi_ROMFAT_GetArchiveCaps(FSArchive *arc, u32 *caps) {
    (void)arc;
    *caps = 0;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ROMFAT_OpenDirectory(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode) {
    FSResult result;
    u32 id = 0;
    result = FSi_ROMFAT_FindPath(arc, baseid, path, &id, TRUE);
    if (result == FS_RESULT_SUCCESS) {
        result = FSi_ROMFAT_SeekDirectory(arc, file, id, 0);
    }
    (void)mode;
    return result;
}

FSResult FSi_ROMFAT_CloseDirectory(FSArchive *arc, FSFile *file) {
    FS_DetachHandle(file);
    (void)arc;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info) {
    FSResult result = FS_RESULT_ERROR;
    u32 id = 0;
    MI_CpuFill8(info, 0x00, sizeof(*info));
    if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, TRUE) == FS_RESULT_SUCCESS) {
        info->attributes = FS_ATTRIBUTE_IS_DIRECTORY;
        info->id = id;
        result = FS_RESULT_SUCCESS;
    } else if (FSi_ROMFAT_FindPath(arc, baseid, path, &id, FALSE) == FS_RESULT_SUCCESS) {
        FSROMFATArchiveContext *context;
        u32 pos;
        info->attributes = 0;
        info->id = id;
        info->filesize = 0;
        context = CONTEXT(arc);
        pos = id * sizeof(FSArchiveFAT);
        if (pos < context->fat_size) {
            FSArchiveFAT fat;
            FSiSyncReadParam param;
            param.arc = arc;
            param.pos = context->fat + pos;
            if (FSi_ReadTable(&param, &fat, sizeof(fat)) == FS_RESULT_SUCCESS) {
                info->filesize = fat.bottom - fat.top;
                if (FSi_IsUnreadableRomOffset(arc, fat.top)) {
                    info->attributes |= FS_ATTRIBUTE_IS_OFFLINE;
                }
            }
        }
        result = FS_RESULT_SUCCESS;
    }
    info->attributes |= FS_ATTRIBUTE_IS_PROTECTED;
    return result;
}
