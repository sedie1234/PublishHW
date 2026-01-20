#ifndef IREE_HW1_TRANSFORMS_PASSES_H_
#define IREE_HW1_TRANSFORMS_PASSES_H_

// #include "iree-HW1/Transforms/PassDetail.h"
#include "mlir/Pass/Pass.h"

namespace mlir::iree_compiler::HW1 {

// void addMLIRHWIRLoweringPasses(OpPassManager &passManager, AMDAIEDevice device,
//                             TilePassPipeline useTilePipeline,
//                             bool matmulElementwiseFusion,
//                             bool enableVectorizationPasses);
// std::unique_ptr<Pass> createXXXXPass();


void registerHW1Passes();

}// namespace mlir::iree_compiler::HW1

#endif // IREE_HW1_TRANSFORMS_PASSES_H_