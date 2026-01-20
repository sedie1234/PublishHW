set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1")

iree_cc_library(
  NAME
    defs
  INCLUDES
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
  PUBLIC
)

iree_cc_library(
    NAME
        registration
    SRCS
        "PluginRegistration.cpp"
    DEPS
        iree::compiler::Dialect::HAL::Target
        iree::compiler::PluginAPI

        # iree::base::core_headers
        # iree::base::internal::flatcc::building
        MLIRIR
        MLIRPass

        ::defs
        
        iree::compiler::PluginAPI

        iree::target::hw1::IR::HW1Dialect
        iree::target::hw1::target::Target
        iree::target::hw1::Transforms

    PUBLIC
)

iree_compiler_register_plugin(
    PLUGIN_ID
        keti_hw1
    TARGET
        ::registration
)

add_subdirectory(IR)
add_subdirectory(Target)
add_subdirectory(Transforms)
# add_subdirectory(Test/samples)