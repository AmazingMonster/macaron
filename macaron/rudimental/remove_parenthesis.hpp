// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_REMOVE_PARENTHESIS_H
#define MACARON_RUDIMENTAL_REMOVE_PARENTHESIS_H

#include "macaron/rudimental/conditional.hpp"
#include "macaron/rudimental/is_parenthesized.hpp"
#include "macaron/rudimental/identity.hpp"

#define MACARON_RUDIMENTAL_REMOVE_PARENTHESIS(a) \
    MACARON_RUDIMENTAL_CONDITIONAL(MACARON_RUDIMENTAL_IS_PARENTHESIZED(a)) \
    (MACARON_RUDIMENTAL_IDENTITY a, a)

#endif
