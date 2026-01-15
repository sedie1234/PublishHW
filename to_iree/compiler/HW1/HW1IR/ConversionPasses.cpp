#include "HW1/HW1IR/Passes.h"

namespace{
#define GEN_PASS_REGISTRATION
#include "HW1/Conversion/Passes.h.inc"
}  // namespace

namespace mlir::iree_compiler::HW1{
void registerHW1IRPasses() {
  registerLinalgToHW1();
}

} // namespace mlir::iree_compiler::HW1