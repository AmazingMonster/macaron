// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_INVALID_H
#define MACARON_JUDGMENTAL_INVALID_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_pair.hpp"

#define MACARON_JUDGMENTAL_INVALID(...) \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    ((MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR((__VA_ARGS__)), is not invalid), not (__VA_ARGS__))

#endif