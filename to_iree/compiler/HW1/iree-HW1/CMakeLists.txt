set(IREE_PACKAGE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(IREE_PACKAGE_ROOT_PREFIX "iree::target::hw1")

iree_cc_library(
    NAME
        registration
    SRCS
        "PluginRegistration.cpp"
    DEPS
        iree::compiler::Dialect::HAL::Target
        iree::compiler::PluginAPI
        iree::target::hw1::IR::HW1Dialect
        iree::target::hw1::Transforms
        iree::base::core_headers
        iree::base::internal::flatcc::building
    PUBLIC
)

iree_compiler_register_plugin(
    PLUGIN_ID
        hw1
    TARGET
        ::registration
)

add_subdirectory(IR)
add_subdirectory(Target)
add_subdirectory(Transforms)
# add_subdirectory(Test/samples)