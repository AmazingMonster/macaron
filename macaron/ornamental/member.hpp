// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_ORNAMENTAL_MEMBER_H
#define MACARON_ORNAMENTAL_MEMBER_H

#define MACARON_ORNAMENTAL_MEMBER(...) \
    typename __VA_ARGS__    \
    ::MACARON_ORNAMENTAL_MEMBER_INSPECTING

#endif