# Source files that were built with a different compiler version than the rest of the game, keyed by their path
# relative to the repository root. configure.py compiles them with this version and match.py uses it by default.
#
# The NitroSystem libraries were prebuilt by Nintendo with an older compiler: under dsi/1.3 the bit-field helper
# macros and some store forwarding come out differently, while dsi/1.1 reproduces the original code exactly. Every
# matched NitroSystem function matches under dsi/1.1, so the whole libs/nnsys tree is pinned to it.
FILE_MWCC_VERSIONS: dict[str, str] = {}

# Directory prefixes (relative to the repository root, ending in "/"). A file entry above wins over these, and a
# longer prefix wins over a shorter one.
DIR_MWCC_VERSIONS = {
    "libs/nnsys/": "dsi/1.1",
}


def mwcc_version_for(relative_path: str | None, default: str | None = None) -> str | None:
    """The compiler version for a source path relative to the repository root (POSIX separators), or `default`."""
    if relative_path is None:
        return default
    if relative_path in FILE_MWCC_VERSIONS:
        return FILE_MWCC_VERSIONS[relative_path]
    for prefix in sorted(DIR_MWCC_VERSIONS, key=len, reverse=True):
        if relative_path.startswith(prefix):
            return DIR_MWCC_VERSIONS[prefix]
    return default
