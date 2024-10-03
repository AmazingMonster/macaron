// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_EQUAL_H
#define MACARON_JUDGMENTAL_EQUAL_H

#include "macaron/rudimental/static_assert.hpp"
#include "macaron/rudimental/whitespace_separated_triplet.hpp"
#include "macaron/rudimental/remove_parenthesis.hpp"

#define MACARON_JUDGMENTAL_EQUAL(a, b) \
    MACARON_RUDIMENTAL_STATIC_ASSERT \
    (   \
        (MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_TRIPLET(a, is not equal to, b)), \
        MACARON_RUDIMENTAL_REMOVE_PARENTHESIS(a) == MACARON_RUDIMENTAL_REMOVE_PARENTHESIS(b)  \
    )

#endif