// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_CHECK_H
#define MACARON_RUDIMENTAL_CHECK_H

#include "macaron/rudimental/get_second.hpp"

#define MACARON_RUDIMENTAL_CHECK(...) \
    MACARON_RUDIMENTAL_GET_SECOND(__VA_ARGS__, 0,)

#endif