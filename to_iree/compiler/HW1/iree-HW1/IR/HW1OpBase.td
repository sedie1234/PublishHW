#ifndef IREE_HW1_IR_OP_BASE
#define IREE_HW1_IR_OP_BASE

include "mlir/IR/OpBase.td"
include "mlir/IR/AttrTypeBase.td"


// base op
class HW1_Op<string mnemonic, list<Trait> traits = []> :
    Op<HW1_Dialect, mnemonic, traits>;

// custom type
// def HW1_BufferType : TypeDef<HW1_Dialect, "Buffer"> {
//   let mnemonic = "buffer";
//   let summary = "HW1 가속기 내부 전용 메모리 버퍼";
//   let description = "가속기 SRAM에 할당된 메모리 공간을 나타내는 타입입니다.";
  
//   // 타입에 파라미터가 필요한 경우 (예: 크기, 메모리 공간 번호)
//   let parameters = (ins "int":$address, "int":$size);
//   let assemblyFormat = "`<` $address `,` $size `>`";
// }

// custom attribute
// def HW1_ConfigAttr : AttrDef<HW1_Dialect, "Config"> {
//   let mnemonic = "config";
//   let summary = "HW1 연산 설정 파라미터";
  
//   let parameters = (ins "int":$priority, "bool":$use_cache);
//   let assemblyFormat = "`<` $priority `,` $use_cache `>`";
// }

//custom interface
// def HW1_HardwareOpInterface : OpInterface<"HardwareOpInterface"> {
//   let description = "모든 HW1 가속기 전용 Op들이 공유하는 인터페이스";
//   let cppNamespace = "::mlir::iree_compiler::keti::hw1";

//   let methods = [
//     InterfaceMethod<"가속기 ID를 반환합니다.",
//       "int", "getAcceleratorId", (ins), [{}], [{ return 0; }]
//     >
//   ];
// }

#endif // IREE_HW1_IR_OP_BASE