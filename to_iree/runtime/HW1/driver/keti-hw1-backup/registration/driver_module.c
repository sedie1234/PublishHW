// Copyright 2024 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "HW1/driver/keti_hw1/registration/driver_module.h"

#include "HW1/driver/keti_hw1/api.h"
#include "iree/base/api.h"

static iree_status_t iree_halhw1driver_factory_enumerate(
    void* self, iree_host_size_t* out_driver_info_count,
    const iree_hal_driver_info_t** out_driver_infos) {

  static const iree_hal_driver_info_t driver_info = {
      .driver_name = IREE_SVL("keti_hw1"),
      .full_name = IREE_SVL("HW1 Runtime"),
  };
  *out_driver_info_count = IREE_ARRAYSIZE(driver_info);
  *out_driver_infos = &driver_info;
  return iree_ok_status();
}

static iree_status_t iree_halhw1driver_factory_try_create(
    void* self, iree_string_view_t driver_name, iree_allocator_t host_allocator,
    iree_hal_driver_t** out_driver) {

  if (!iree_string_view_equal(driver_name, IREE_SV("keti_hw1"))) {
    return iree_make_status(IREE_STATUS_UNAVAILABLE,
                            "no driver '%.*s' is provided by this factory",
                            (int)driver_name.size, driver_name.data);
  }

  // iree_halhw1driver_options_t options;
  // iree_halhw1driver_options_initialize(&options);

  iree_status_t status = iree_halhw1driver_create(
      driver_name, &options, host_allocator, out_driver);

  return status;
}

IREE_API_EXPORT iree_status_t
iree_halhw1driver_module_register(iree_hal_driver_registry_t* registry) {
  static const iree_hal_driver_factory_t factory = {
      .self = NULL,
      .enumerate = iree_halhw1driver_factory_enumerate,
      .try_create = iree_halhw1driver_factory_try_create,
  };
  return iree_hal_driver_registry_register_factory(registry, &factory);
}
