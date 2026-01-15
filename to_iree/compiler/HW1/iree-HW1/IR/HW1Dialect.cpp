#include "HW1/iree-HW1/IR/HW1Dialect.h"

// #include "HW1/iree-HW1/IR/HW1Attrs.h"
#include "HW1/iree-HW1/IR/HW1Dialect.cpp.inc"

#include "mlir/Interfaces/FoldInterfaces.h"
#include "mlir/Transforms/InliningUtils.h"

namespace mlir::iree_compiler::HW1 {


void HW1Dialect::initialize() {
  // operation registration
  addOperations<
#define GET_OP_LIST
#include "IR/HW1Ops.cpp.inc"
  >();
 

// // types registration    
//   addTypes<
// #define GET_TYPEDEF_LIST
// #include "IR/HW1Types.cpp.inc"
//   >();
    
// // attributes registration
//   addAttributes<
// #define GET_ATTRDEF_LIST
// #include "IR/HW1Attrs.cpp.inc"
//   >();

}

} // namespace mlir::iree_compiler::HW1
