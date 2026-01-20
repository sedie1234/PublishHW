// Copyright 2024 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_HAL_DRIVERSHW1SEMAPHORE_H_
#define IREE_HAL_DRIVERSHW1SEMAPHORE_H_

#include "iree/base/api.h"
#include "iree/hal/api.h"

//===----------------------------------------------------------------------===//
// iree_halhw1semaphore_t
//===----------------------------------------------------------------------===//

// Creates a Hw1 semaphore used for ordering queue operations and
// synchronizing between host/device and device/device.
iree_status_t iree_halhw1semaphore_create(
    iree_hal_queue_affinity_t queue_affinity, uint64_t initial_value,
    iree_hal_semaphore_flags_t flags, iree_allocator_t host_allocator,
    iree_hal_semaphore_t** out_semaphore);

#endif  // IREE_HAL_DRIVERSHW1SEMAPHORE_H_
