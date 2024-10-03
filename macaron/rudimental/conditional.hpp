// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_RUDIMENTAL_CONDITIONAL_H
#define MACARON_RUDIMENTAL_CONDITIONAL_H

#include "macaron/rudimental/paste.hpp"

#define MACARON_RUDIMENTAL_CONDITIONAL(cond) \
    MACARON_RUDIMENTAL_PASTE(MACARON_RUDIMENTAL_CONDITIONAL_, cond)
#define MACARON_RUDIMENTAL_CONDITIONAL_0(t, f) \
    f
#define MACARON_RUDIMENTAL_CONDITIONAL_1(t, f) \
    t

#endif