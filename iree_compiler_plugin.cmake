# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


set(IREE_MLIR_HW1_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/RepresentHW/mlir")

option(TARGET_DEVICE "Target device for HW1 compilation" "HW1")

if(TARGET_DEVICE STREQUAL "HW1")
  message(STATUS "Configuring IREE AMD HW1 Compiler Plugin for TARGET_DEVICE=HW1")
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/compiler/plugins/target/HW1)
else()
  message(FATAL_ERROR "Unsupported TARGET_DEVICE: ${TARGET_DEVICE}")
