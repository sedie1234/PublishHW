set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1::Transforms")


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
        "Passes.h"
        "Passes.h.inc"
    INCLUDES
        "$<BUILD_INTERFACE:${IREE_HW1_COMPILER_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${IREE_HW1_COMPILER_BINARY_DIR}>"
    DEPS
        ::PassesIncGen
        iree::target::hw1::IR::HW1Dialect
        MLIRPass
    PUBLIC
)

iree_cc_library(
    NAME
        Transforms
    HDRS
        "Passes.h"
    SRCS
        "Passes.cpp"
    DEPS
        ::PassHeaders
        ::PassesIncGen
        iree::compiler::Codegen::Common::TransformDialectInterpreterPass
        iree::compiler::Codegen::Dialect::Codegen::IR::IREECodegenDialect
        iree::compiler::Dialect::HAL::IR
        iree::compiler::Dialect::HAL::IR::HALDialect
        iree::compiler::Dialect::LinalgExt::IR
        iree::compiler::Dialect::LinalgExt::Transforms
        iree::compiler::Utils
        IREELinalgTransformDialectPasses
        MLIRFuncAllExtensions
        MLIRFuncDialect
        MLIRFunctionInterfaces
        MLIRLLVMCommonConversion
        MLIRLLVMDialect
        MLIRLinalgDialect
        MLIRLinalgTransforms
        MLIRMemRefDialect
        MLIRPDLDialect
        MLIRPDLInterpDialect
        MLIRPass
        MLIRSCFDialect
        MLIRSCFToControlFlow
        MLIRSCFTransforms
        MLIRSCFUtils
        MLIRSupport
        MLIRTensorDialect
        MLIRTensorTransforms
        MLIRToLLVMIRTranslationRegistration
        MLIRTransforms
        MLIRVectorDialect
        MLIRVectorToLLVM
        MLIRVectorToSCF
        MLIRVectorTransforms
    PUBLIC
)