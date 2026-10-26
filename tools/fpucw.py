#!/usr/bin/env python3
"""Run a command with the x87 FPU control word set to 0x27F, the Windows default for a new thread.

mwccarm.exe never sets the control word itself; it relies on the value Windows gives it, which selects
53-bit (double) precision. Linux starts a process at 0x37F (64-bit precision), and wibo keeps that.
The difference is visible in codegen: MWCC merges switch cases into a jump-table cluster while
count / range >= 0.4, computed with the x87 FPU. At 64-bit precision an exact 2 / 5 (or 4 / 10, ...)
comes out just below the double constant 0.4 and the merge is refused; at 53-bit precision it is
equal and the merge happens, as in the original build (MSL's __pformatter, func_02006e48).

The child is started under ptrace, its control word is set right after execve, and it is then
detached, so nothing else about the run changes.

Usage: fpucw.py program [args...]
"""
import ctypes
import os
import sys

PTRACE_TRACEME = 0
PTRACE_GETFPREGS = 14
PTRACE_SETFPREGS = 15
PTRACE_DETACH = 17
WINDOWS_FPU_CW = 0x27F


def main() -> int:
    args = sys.argv[1:]
    if not args:
        print(__doc__, file=sys.stderr)
        return 2
    libc = ctypes.CDLL(None, use_errno=True)
    libc.ptrace.restype = ctypes.c_long
    libc.ptrace.argtypes = [ctypes.c_long, ctypes.c_long, ctypes.c_void_p, ctypes.c_void_p]
    pid = os.fork()
    if pid == 0:
        try:
            libc.ptrace(PTRACE_TRACEME, 0, None, None)
            os.execvp(args[0], args)
        finally:
            os._exit(127)
    _, status = os.waitpid(pid, 0)
    if os.WIFSTOPPED(status):
        # Stopped at the execve: the FXSAVE area starts with the 16-bit control word.
        fpregs = ctypes.create_string_buffer(512)
        if libc.ptrace(PTRACE_GETFPREGS, pid, None, fpregs) != 0:
            raise OSError(ctypes.get_errno(), "PTRACE_GETFPREGS failed")
        fpregs[0:2] = WINDOWS_FPU_CW.to_bytes(2, "little")
        if libc.ptrace(PTRACE_SETFPREGS, pid, None, fpregs) != 0:
            raise OSError(ctypes.get_errno(), "PTRACE_SETFPREGS failed")
        libc.ptrace(PTRACE_DETACH, pid, None, None)
        _, status = os.waitpid(pid, 0)
    return os.waitstatus_to_exitcode(status)


if __name__ == "__main__":
    sys.exit(main())
