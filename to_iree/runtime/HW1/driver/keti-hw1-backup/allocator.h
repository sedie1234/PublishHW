// Copyright 2024 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_HAL_DRIVERSHW1ALLOCATOR_H_
#define IREE_HAL_DRIVERSHW1ALLOCATOR_H_

#include "iree/base/api.h"
#include "iree/hal/api.h"

//===----------------------------------------------------------------------===//
// iree_halhw1allocator_t
//===----------------------------------------------------------------------===//

// Creates a Hw1 buffer allocator used for persistent allocations.
iree_status_t iree_halhw1allocator_create(
    iree_allocator_t host_allocator, iree_hal_allocator_t** out_allocator);

#endif  // IREE_HAL_DRIVERSHW1ALLOCATOR_H_
