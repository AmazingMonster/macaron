// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR_H
#define MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR_H

#include "macaron/rudimental/remove_parenthesis.hpp"

#define MACARON_RUDIMENTAL_WHITESPACE_SEPARATED_PAIR(a,...) \
    MACARON_RUDIMENTAL_REMOVE_PARENTHESIS(a) __VA_ARGS__

#endif
