// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_STATIC_ASSERT_H
#define MACARON_RUDIMENTAL_STATIC_ASSERT_H

#include "macaron/rudimental/stringize.hpp"
#include "macaron/rudimental/remove_parenthesis.hpp"

#define MACARON_RUDIMENTAL_STATIC_ASSERT(a, ...) \
    static_assert(__VA_ARGS__, MACARON_RUDIMENTAL_STRINGIZE(MACARON_RUDIMENTAL_REMOVE_PARENTHESIS(a)))

#endif