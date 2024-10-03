// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_SAME_TYPE_H
#define MACARON_JUDGMENTAL_SAME_TYPE_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_pair.hpp"

#define MACARON_JUDGMENTAL_SAME_TYPE(...) \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    ((MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR(Not the same as, MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED)), std::same_as<__VA_ARGS__, MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED>)

#endif