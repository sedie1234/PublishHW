set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1::Transforms")
iree_add_all_subdirs()

iree_tablegen_library(
    NAME
        PassesIncGen
    TD_FILE
        "Passes.td"
    OUTS
        --gen-pass-decls Passes.h.inc
)

iree_cc_library(
    NAME
        PassHeaders
    HDRS
        "PassDetail.h"
        "Passes.h"
        "Passes.h.inc"
    DEPS
        ::PassesIncGen
        iree::target::hw1::IR::HW1Dialect
        MLIRPass
    PUBLIC
)