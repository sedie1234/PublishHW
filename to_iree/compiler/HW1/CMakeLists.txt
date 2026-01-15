include_directories(("${IREE_MLIR_HW1_SOURCE_DIR}/include"))

iree_setup_c_src_root(
    PACKAGE_ROOT_PREFIX iree::target
    IMPLICIT_DEFS_TARGET iree_target_hw1_compiler_defs
)
add_subdirectory(iree_HW1)
add_subdirectory(HW1IR)