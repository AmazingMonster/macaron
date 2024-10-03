// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_DERIVED_TYPE_H
#define MACARON_JUDGMENTAL_DERIVED_TYPE_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_pair.hpp"

#define MACARON_JUDGMENTAL_DERIVED_TYPE(...)   \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    ((MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR(Not derived from, MACARON_JUDGMENTAL_DERIVED_TYPE_BASE_SUPPOSED)), std::derived_from<__VA_ARGS__, MACARON_JUDGMENTAL_DERIVED_TYPE_BASE_SUPPOSED>)

#endif