// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_IS_PARENTHESIZED_H
#define MACARON_RUDIMENTAL_IS_PARENTHESIZED_H

#include "macaron/rudimental/check.hpp"
#include "macaron/rudimental/probe.hpp"

#define MACARON_RUDIMENTAL_IS_PARENTHESIZED(a) \
    MACARON_RUDIMENTAL_CHECK(MACARON_RUDIMENTAL_IS_PARENTHESIZED_PROBE a)

#define MACARON_RUDIMENTAL_IS_PARENTHESIZED_PROBE(...) \
    MACARON_RUDIMENTAL_PROBE(~)

#endif

