#ifndef IREE_HW1_TARGET_HW1TARGET_H_
#define IREE_HW1_TARGET_HW1TARGET_H_

#include <string>

#include "iree/compiler/Dialect/HAL/Target/TargetBackend.h"
#include "iree/compiler/Dialect/HAL/Target/TargetDevice.h"
#include "iree/compiler/Utils/OptionUtils.h"

namespace mlir::iree_compiler::HW1 {

struct HW1Options {

  enum class DeviceHAL { HRT, HRT_LITE }; 
  DeviceHAL deviceHal{DeviceHAL::HRT_LITE};

// options for HW1 target can be added here

  bool debugPass{false};

  void bindOptions(OptionsBinder &binder) {
    static llvm::cl::OptionCategory category("HW1 Options");
    binder.opt<bool>(
        "iree-hw1-debug-pass", debugPass, llvm::cl::cat(category),
        llvm::cl::desc("Enable debug output for HW1 pass"));
  }
};

std::shared_ptr<IREE::HAL::TargetDevice> createTarget(
    const HW1Options &options);

std::shared_ptr<IREE::HAL::TargetBackend> createBackend(
    const HW1Options &options);

}  // namespace mlir::iree_compiler::HW1

#endif // IREE_HW1_TARGET_HW1TARGET_H_