# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(IREE_MLIR_HW1_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/RepresentHW/mlir")

message("IREE_LLVM_PROJECT_SOURCE_DIR : ${IREE_LLVM_PROJECT_SOURCE_DIR}")

set(TARGET_DEVICE "HW1" CACHE STRING "Target device for HW1 compilation")

if(TARGET_DEVICE STREQUAL "HW1")
  message(STATUS "Configuring IREE HW1 Compiler Plugin for TARGET_DEVICE=HW1")
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/to_iree/compiler/HW1/ HW1)

else()
  message(FATAL_ERROR "Unsupported TARGET_DEVICE: ${TARGET_DEVICE}")
endif()
