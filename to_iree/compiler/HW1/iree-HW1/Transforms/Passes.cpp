

// #include "HW1/iree-HW1/Transforms/Passes.h"

#include "HW1/Conversion/ConvertToHW1IRPass.h"

#include "iree-dialects/Dialect/LinalgTransform/Passes.h"
#include "iree/compiler/Codegen/Common/Passes.h"
#include "mlir/Conversion/AffineToStandard/AffineToStandard.h"
#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/MathToLLVM/MathToLLVM.h"
#include "mlir/Conversion/SCFToControlFlow/SCFToControlFlow.h"
#include "mlir/Conversion/VectorToLLVM/ConvertVectorToLLVMPass.h"
#include "mlir/Dialect/Affine/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Linalg/Passes.h"
#include "mlir/Dialect/MemRef/Transforms/Passes.h"
#include "mlir/Dialect/SCF/Transforms/Passes.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Transforms/Passes.h"

#define DEBUG_TYPE "iree-hw1-lowering-pass-pipeline"

namespace mlir::iree_compiler::HW1{

// namespace {
// #define GEN_PASS_REGISTRATION
// #include "HW1/iree-HW1/Transforms/Passes.h.inc"
// }  // namespace

void registerHW1Passes() {
  // Generated.
  registerPasses();
}
}