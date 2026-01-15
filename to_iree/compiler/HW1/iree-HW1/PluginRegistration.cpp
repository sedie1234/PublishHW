// hardware aware operations plugin registration
#include "HW1/Dialect/HW1IR/HW1IRDialect.h"
#include "HW1/HW1IR/Passes.h"

// iree aware plugin registration
// #include "iree-HW1/IR/HW1Dialect.h"
#include "iree-HW1/Target/HW1Target.h"
// #include "iree-HW1/Transforms/Passes.h"

// iree compiler core plugin registration
#include "iree/compiler/Dialect/HAL/Target/TargetRegistry.h"
#include "iree/compiler/PluginAPI/Client.h"


namespace mlir::iree_compiler {
namespace {

namespace{
#define GEN_PASS_REGISTRATION
#include "HW1/HW1IR/Passes.h.inc"

} // namespace


struct HW1Session
    : public PluginSession<HW1Session, HW1::HW1Options,
                           PluginActivationPolicy::DefaultActivated> {
  static void registerPasses() {
    HW1::registerHW1Passes(); 
    HW1::registerHW1IRPasses();
  }

  void onRegisterDialects(DialectRegistry &registry) override {
    registry.insert<keti::hw1ir::HW1IRDialect>();
  }

  void populateHALTargetDevices(IREE::HAL::TargetDeviceList &targets) override {
    // #hal.device.target<"keti-hw1", ...
    targets.add("keti-hw1", [=] {
      options.deviceHal = HW1::HW1Options::DeviceHAL::HRT; 
      return HW1::createTarget(options);
    });
  }

  void populateHALTargetBackends(
      IREE::HAL::TargetBackendList &backends) override {
    // #hal.target.backend<"keti-hw1", ...
    backends.add("keti-hw1", [=] {
      options.deviceHal = HW1::HW1Options::DeviceHAL::HRT; 
      return HW1::createBackend(options);
    });
  }

};

} // namespace
} // namespace mlir::iree_compiler

IREE_DEFINE_COMPILER_OPTION_FLAGS(::mlir::iree_compiler::HW1::HW1Options);

extern "C" iree_register_compiler_plugin_hw1(mlir::iree_compiler::PluginRegistrar *registrar) {
  registrar->registerPlugin<::mlir::iree_compiler::HW1Session>("hw1");
  return true;
}