set(IREE_MLIR_HW1_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/RepresentHW/mlir")

option(TARGET_DEVICE "Target device for HW1 compilation" "HW1")

if(TARGET_DEVICE STREQUAL "HW1")
  message(STATUS "Configuring IREE HW1 Compiler Plugin for TARGET_DEVICE=HW1")
  include_directories("${CMAKE_CURRENT_LIST_DIR}/to_iree/runtime")
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/to_iree/runtime/HW1/driver/keti_hw1 keti_hw1)
else()
  message(FATAL_ERROR "Unsupported TARGET_DEVICE: ${TARGET_DEVICE}")
endif()
