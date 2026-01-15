iree_add_all_subdirs()


iree_cc_library(
    NAME
        Target
    HDRS
        "HW1Target.h"
    SRCS
        "HW1Target.cpp"
    DEPS
        ::HW1Dialect
        iree::base::internal::flatcc::building
        iree::base::internal::flatcc::parsing
        iree::compiler::Dialect::HAL::Target
        MLIRLLVMDialect
)

