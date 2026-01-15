set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1::IR")
iree_add_all_subdirs()

iree_cc_library(
    NAME
        HW1Dialect
    HDRS
        "HW1Dialect.h"
    TEXTUAL_HDRS
        "HW1Dialect.cpp.inc"
        "HW1Dialect.h.inc"
        # "HW1Attrs.cpp.inc"
        # "HW1Attrs.h.inc"
        "HW1Ops.cpp.inc"
        "HW1Ops.h.inc"
        # "HW1Types.cpp.inc"
        # "HW1Types.h.inc"
        # "HW1Interface.cpp.inc"
        # "HW1Interface.h.inc"
    SRCS
        "HW1Dialect.cpp"
    DEPS
        ::HW1DialectGen
        # ::HW1AttrsGen
        ::HW1OpsGen
        # ::HW1TypesGen
        # ::HW1InterfaceGen
        LLVMSupport
        MLIRArithUtils
        MLIRDialectUtils
        MLIRIR
        MLIRParser
        MLIRSupport
        MLIRViewLikeInterface
    PUBLIC
)

iree_tablegen_library(
    NAME
        HW1DialectGen
    TD_FILE
        "HW1Dialect.td"
    OUTS
        --gen-dialect-decls HW1Dialect.cpp.inc
        --gen-dialect-defs HW1Dialect.h.inc
)

iree_tablegen_library(
    NAME
        HW1OpsGen
    TD_FILE
        "HW1Ops.td"
    OUTS
        --gen-op-decls HW1Ops.h.inc
        --gen-op-defs HW1Ops.cpp.inc
)

