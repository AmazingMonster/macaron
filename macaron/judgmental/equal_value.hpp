// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_EQUAL_VALUE_H
#define MACARON_JUDGMENTAL_EQUAL_VALUE_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_pair.hpp"

#define MACARON_JUDGMENTAL_EQUAL_VALUE(...) \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    ((MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR(Not equal to, MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED)), __VA_ARGS__ == MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED)

#endif