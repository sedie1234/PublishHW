#ifndef IREE_HW1_DIALECT_IREEHW1_DIALECT
#define IREE_HW1_DIALECT_IREEHW1_DIALECT

include "mlir/IR/OpBase.td"

def HW1_Dialect : Dialect {
  let name = "hw1";
  let cppNamespace = "::mlir::iree_compiler::keti::hw1";
  let summary = "HW1 Hardware Dialect";
  let hasConstantMaterializer = 1; // 필요 시 추가
}

#endif // IREE_HW1_DIALECT_IREEHW1_DIALECT