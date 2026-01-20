#include "mlir/Pass/Pass.h"
#include "mlir/IR/Builders.h"
#include <memory>


// namespace{
// #define GEN_PASS_REGISTRATION
// #include "Conversion/Passes.h.inc"
// }  // namespace

#include "HW1/Conversion/Passes.h"
#include "HW1/Conversion/ConvertToHW1IRPass.h"

namespace{
#define GEN_PASS_REGISTRATION
#include "Conversion/Passes.h.inc"
}  // namespace


namespace mlir::iree_compiler::HW1{
void registerHW1IRPasses() {
  registerLinalgToHW1();
}



} // namespace mlir::iree_compiler::HW1