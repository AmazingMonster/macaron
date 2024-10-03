// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_VALID_H
#define MACARON_JUDGMENTAL_VALID_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_pair.hpp"

#define MACARON_JUDGMENTAL_VALID(...) \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    ((MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR((__VA_ARGS__), is invalid)), __VA_ARGS__)

#endif