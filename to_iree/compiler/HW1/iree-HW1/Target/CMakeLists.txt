set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1::target")

iree_cc_library(
    NAME
        Target
    HDRS
        "HW1Target.h"
    SRCS
        "HW1Target.cpp"
    INCLUDES
        "$<BUILD_INTERFACE:${IREE_HW1_COMPILER_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${IREE_HW1_COMPILER_BINARY_DIR}>"
    DEPS
        iree::compiler::Dialect::HAL::Target
        MLIRLLVMDialect
    PUBLIC
)

