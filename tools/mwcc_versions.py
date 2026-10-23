# Source files that were built with a different compiler version than the rest of the game, keyed by their path
# relative to the repository root. configure.py compiles them with this version and match.py uses it by default.
#
# The NitroSystem libraries were prebuilt by Nintendo with an older compiler: under dsi/1.3p1 the bit-field helper
# macros and some store forwarding come out differently, while dsi/1.1 reproduces the original code exactly.
FILE_MWCC_VERSIONS = {
    "libs/nnsys/fnd/expheap.c": "dsi/1.1",
    "libs/nnsys/g3d/nsbtp_2.c": "dsi/1.1",
    # These need dsi/1.3 (dsi/1.2 to dsi/1.3 all match): it folds a u16 truncation into the next instruction's
    # operand (`lsl rA, rB, #16` then `rsb rC, rD, rA, lsr #16`), and dsi/1.3p1 does not. The whole ROM also
    # builds and matches with dsi/1.3 as the default, so the game itself may have been built with dsi/1.3.
    "src/ov000/Cam_021b2b08.cpp": "dsi/1.3",
    "src/ov011/ov011_021fc94c.cpp": "dsi/1.3",
}
