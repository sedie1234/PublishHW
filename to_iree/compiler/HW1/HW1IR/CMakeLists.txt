set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1::hw1ir")

list(APPEND IREE_COMPILER_TABLEGEN_INCLUDE_DIRS
    "${IREE_MLIR_HW1_SOURCE_DIR}/include"
)

iree_cc_library(
    NAME
        defs
    INCLUDES
        ${IREE_MLIR_HW1_SOURCE_DIR}/include
        ${IREE_LLVM_PROJECT_SOURCE_DIR}/mlir/include
        ${IREE_LLVM_PROJECT_BINARY_DIR}/tools/mlir/include
        # "$<BUILD_INTERFACE:${IREE_SOURCE_DIR}/third_party/llvm-project/mlir/include>"
        # "$<BUILD_INTERFACE:${IREE_BINARY_DIR}/third_party/llvm-project/mlir/include>"
        # "$<BUILD_INTERFACE:${IREE_SOURCE_DIR}/third_party/llvm-project/llvm/include>"
        # "$<BUILD_INTERFACE:${IREE_BINARY_DIR}/third_party/llvm-project/include>"
)

#########################################################
#########################################################
##################### HW1IR Dialect #####################
#########################################################
#########################################################



#############################################
############## HW1IR Libraries ##############
#############################################

iree_tablegen_library(
    NAME
        HW1IRDialectGen
    TD_FILE
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Dialect/HW1IR/HW1IR.td"
    OUTS
        -gen-op-decls Dialect/HW1IR/HW1IROps.h.inc
        -gen-op-defs Dialect/HW1IR/HW1IROps.cpp.inc

    INCLUDE_DIRS
        ${IREE_MLIR_HW1_SOURCE_DIR}/include
        ${IREE_LLVM_PROJECT_SOURCE_DIR}/mlir/include
        #        ${IREE_LLVM_PROJECT_BINARY_DIR}/tools/mlir/include
    DEPS
        ::defs
        
)

iree_tablegen_library(
    NAME
        HW1IRInterfaceGen
    TD_FILE
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Dialect/HW1IR/HW1IROpBase.td"
    OUTS
        -gen-op-interface-decls Dialect/HW1IR/HW1IRInterface.h.inc
        -gen-op-interface-defs Dialect/HW1IR/HW1IRInterface.cpp.inc
        -gen-dialect-decls Dialect/HW1IR/HW1IRDialect.h.inc --dialect=hw1ir #??
        -gen-dialect-defs Dialect/HW1IR/HW1IRDialect.cpp.inc --dialect=hw1ir #??
        -gen-typedef-decls Dialect/HW1IR/HW1IRTypes.h.inc #??
        -gen-typedef-defs Dialect/HW1IR/HW1IRTypes.cpp.inc #??
        -gen-enum-decls Dialect/HW1IR/HW1IREnums.h.inc #??
        -gen-enum-defs Dialect/HW1IR/HW1IREnums.cpp.inc #??
)

iree_tablegen_library(
    NAME
        HW1IRConversionPassesIncGen
    TD_FILE
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Conversion/Passes.td"
    OUTS
        -gen-pass-decls Conversion/Passes.h.inc

)

##### transform ops example #####
# iree_tablegen_library(
#     NAME
#         HW1IRTransformOpsGen
#     TD_FILE
#         "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Transforms/TransformOps.td"
#     OUTS
#         -gen-op-decls Dialect/HW1IR/HW1IRTransformOps.h.inc
#         -gen-op-defs Dialect/HW1IR/HW1IRTransformOps.cpp.inc
# )

#############################################
############# HW1IR Source Files ############
#############################################

iree_cc_library(
    NAME
        HW1IRDialect
    SRCS
        ${IREE_MLIR_HW1_SOURCE_DIR}/lib/HW1/Dialect/HW1IR//IR/HW1IRDialect.cpp
    INCLUDES
        # ${CMAKE_BINARY_DIR}/compiler/plugins/HW1
        ${CMAKE_CURRENT_BINARY_DIR}
        ${IREE_MLIR_HW1_SOURCE_DIR}/include
        # ${IREE_LLVM_PROJECT_SOURCE_DIR}/mlir/include
        # ${IREE_LLVM_PROJECT_BINARY_DIR}/tools/mlir/include

    DEPS
        ::defs
        ::HW1IRDialectGen
        ::HW1IRInterfaceGen
        # ::HW1IRTransformationOpsGen
        ::HW1IRConversionPassesIncGen
        MLIRIR
)

#########################################################
#########################################################
################ HW1IR Conversion Passes ################
#########################################################
#########################################################


#############################################
############# HW1IR Source Files ############
#############################################

iree_cc_library(
    NAME
        HW1IRConversionPassHeaders
    HDRS
        ${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Conversion/Passes.h
        "Passes.h.inc"
    DEPS
        ::HW1IRConversionPassesIncGen
        MLIRPass
    PUBLIC
)

iree_cc_library(
    NAME
        HW1IRConversionPasses
    HDRS
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Conversion/ConvertToHW1IRPass.h"
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Conversion/Passes.h"
    SRCS
        "ConversionPasses.cpp"
        "${IREE_MLIR_HW1_SOURCE_DIR}/lib/HW1/Conversion/ConvertToHW1IRPass.cpp"
    INCLUDES
        "${IREE_MLIR_HW1_SOURCE_DIR}/include"
    DEPS
        ::defs
        ::HW1IRConversionPassHeaders
        # ::HW1IRTransform
        # ::HW1IRTransformOps
        ::HW1IRDialect
        MLIRIR
        MLIRLinalgTransforms
        MLIRLinalgUtils
        MLIRSupport
        MLIRTransforms
        MLIRPass        
)

#########################################################
#########################################################
##################### HW1IR Passes ######################
#########################################################
#########################################################

iree_cc_library(
    NAME
        HW1IRPasses
    HDRS
        "${IREE_MLIR_HW1_SOURCE_DIR}/include/HW1/Conversion/Passes.h"
    DEPS
        ::HW1IRConversionPasses
        # ::HW1IRTransformPasses
)


