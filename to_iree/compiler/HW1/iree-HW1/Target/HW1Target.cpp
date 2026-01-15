#include "HW1/iree-HW1/Target/HW1Target.h"

#include <fstream>
#include <utility>

#include "HW1/Dialect/HW1IR/HW1IRDialect.h"
#include "HW1/iree-HW1/IR/HW1Dialect.h"
#include "HW1/iree-HW1/Transforms/Passes.h"
#include "HW1/iree-HW1/Target/HW1Target.h"

#include "iree/compiler/Codegen/Dialect/Codegen/IR/IREECodegenDialect.h"
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"
#include "iree/compiler/Dialect/LinalgExt/IR/LinalgExtDialect.h"
#include "iree/compiler/Utils/FlatbufferUtils.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/SourceMgr.h"
#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/ControlFlowToLLVM/ControlFlowToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVM.h"
#include "mlir/Conversion/IndexToLLVM/IndexToLLVM.h"
#include "mlir/Conversion/MathToLLVM/MathToLLVM.h"
#include "mlir/Conversion/MemRefToLLVM/MemRefToLLVM.h"
#include "mlir/Dialect/DLTI/DLTI.h"
#include "mlir/Dialect/EmitC/IR/EmitC.h"
#include "mlir/Dialect/Func/Extensions/AllExtensions.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Math/IR/Math.h"
#include "mlir/Dialect/Transform/IR/TransformDialect.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include "mlir/Parser/Parser.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Target/LLVMIR/Dialect/All.h"

#define DEBUG_TYPE "hw1-target"

namespace mlir::iree_compiler::HW1{

class HW1TargetDevice : public IREE::HAL::TargetDevice {
public:
  void buildDeviceTargetPassPipeline(OpPassManager &passManager) override {}
};



class HW1TargetBackend : public IREE::HAL::TargetBackend {
public:
  HW1TargetBackend(const HW1Options options) : options(std::move(options)) {}

  std::string name() const override { return "hw1ir"; }

  // HW1 pipeline
  void buildTranslationPassPipeline(IREE::HAL::ExecutableVariantOp variantOp,
                                    OpPassManager &passManager) override {
  
    passManager.addPass(mlir::createLinalgToMyHWPass()); 
    
    llvm::errs() << "HW1: Pipeline is being built for " << name() << "\n";
  }

  // binary serialization
  LogicalResult serializeExecutable(const SerializationOptions &serializationOptions,
                                    IREE::HAL::ExecutableVariantOp variantOp,
                                    OpPassManager &executablePassManager) override {
    
    return success();
  }

private:
  HW1Options options;
};

// create target device
std::shared_ptr<IREE::HAL::TargetDevice> createTarget(const HW1Options &options) {
  return std::make_shared<HW1TargetDevice>();
}

// create target backend 
std::shared_ptr<IREE::HAL::TargetBackend> createBackend(const HW1Options &options) {
  return std::make_shared<HW1TargetBackend>(options);
}



}   // namespace mlir::iree_compiler::HW1