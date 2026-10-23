# Source files that were built with a different compiler version than the rest of the game, keyed by their path
# relative to the repository root. configure.py compiles them with this version and match.py uses it by default.
#
# The NitroSystem libraries were prebuilt by Nintendo with an older compiler: under dsi/1.3 the bit-field helper
# macros and some store forwarding come out differently, while dsi/1.1 reproduces the original code exactly.
FILE_MWCC_VERSIONS = {
    "libs/nnsys/fnd/expheap.c": "dsi/1.1",
    "libs/nnsys/g3d/nsbtp_2.c": "dsi/1.1",
}
