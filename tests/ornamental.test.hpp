// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_ORNAMENTAL_TEST_ORNAMENTAL_H
#define MACARON_ORNAMENTAL_TEST_ORNAMENTAL_H

/*********************************************************************************************************************/
// The original propose for this section was to seek an elegant way \
// in order to get around the 'comma problem' in C++ macro functions.
// For example `FUNCTION(int, std::tuple<int, int*>)` will be parsed \
// as if we are calling FUNCTION with `int`, `std::tuple<int`, and `int*>`.

// If we have a argument like `std::max(1, 2)`, \
// we will put a pair of parentheses around it so that the compiler will regard it as a single parameter.
// A macro function call will look like `FUNCTION((std::max(1, 2)))`.

// This will not work for `std::tuple<int, int*>` since parentheses around a type indicate a cast,
// which is not what we intended.

// One way to get around this is to put the parameter into another macro, in this library, `MONO`.
// This way, the call to `FUNCTION` will become `FUNCTION(int, MONO(std::tuple<int, int*>))`   \
// where `MONO(std::tuple<int, int*>)` will be expanded into a single paramenter.

// However, after studying Paul Fultz II's Cloak library. I found a different solution, \
// which is more consistent to what we will do with values.
// I keep this section around since it can still simplify testing in some scenarios.
/*********************************************************************************************************************/




#include <concepts>
#include <tuple>
#include <type_traits>




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_MONO`.
// It groups comma separated symbols together as one entity.
// It has a header guard and thus shall only be truely included once in the entire program.
#include "macaron/ornamental/mono.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestMono {

#define FUNCTION(a, b) static_assert(std::same_as<b, std::tuple<int, int*>>)

// FUNCTION(int, std::tuple<int, int*>) /* This won't work */
FUNCTION(int, MACARON_ORNAMENTAL_MONO(std::tuple<int, int*>));

}}}

// Here is a convenient header that shortens the name of `MACARON_ORNAMENTAL_MONO` to `MONO`.
#include "macaron/ornamental/amenity/define_mono.hpp"
// This header does not have a header guard.
// It is intended to be included every time we want to use it and unset right after.
// It can be unset by including its sister header "undef_mono.hpp".

namespace Macaron {
namespace Ornamental {
namespace TestMono {

FUNCTION(int, MONO(std::tuple<int, int*>));

}}}

// Unset "define_mono.hpp"
#include "macaron/ornamental/amenity/undef_mono.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_TYPE`.
// It takes out the member `type` from the parameter.
#include "macaron/ornamental/type.hpp"

// Convenient header:
#include "macaron/ornamental/amenity/define_type.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestType {

template<typename A, typename B>
struct Tester
{
    using type = std::tuple<A, B>;
};

// Better than writing `FUNCTION(int, MONO(Tester<int, int*>::type))`;
FUNCTION(int, TYPE(Tester<int, int*>));

}}}

// Unset `define_type.hpp`
#include "macaron/ornamental/amenity/undef_type.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_VALUE`.
// It takes out the member `value` from the parameter.
#include "macaron/ornamental/value.hpp"

// Convenient header:
#include "macaron/ornamental/amenity/define_value.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestValue {

template<typename A, typename B>
struct Tester
{
    static constexpr auto value {std::tuple<A, B>{}};
};

// `decltype(VALUE(Tester<int, int*>))` gives us `const std::tuple<A, B>`.
// We need to remove the constness in order to pass `FUNCTION`.
FUNCTION(int, std::remove_const_t<decltype(VALUE(Tester<int, int*>))>);

}}}

// Unset "define_value.hpp"
#include "macaron/ornamental/amenity/undef_value.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_MEMBER`.
// It takes out the member specified by macro `MACARON_ORNAMENTAL_MEMBER_INSPECTING` from the parameter.
#include "macaron/ornamental/member.hpp"

// Convenient header:
#include "macaron/ornamental/amenity/define_member.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestMember {

template<typename A, typename B>
struct Tester
{
    using AnyName = std::tuple<A, B>;
};

// `MACARON_ORNAMENTAL_MEMBER_INSPECTING` has been shortened by the convenient header.
#define INSPECT_MEMBER  \
    AnyName

FUNCTION(int, MEMBER(Tester<int, int*>));

// #undef INSPECT_MEMBER
#undef INSPECT_MEMBER

}}}

// Unset "define_member.hpp"
#include "macaron/ornamental/amenity/undef_member.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_TEMPLATE`.
// It instantiates a template specified by macro `MACARON_ORNAMENTAL_TEMPLATE_INSPECTING` with its parameters.
#include "macaron/ornamental/template.hpp"

// Convenient header:
#include "macaron/ornamental/amenity/define_template.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestTemplate {

template<typename A, typename B>
struct Tester
{
    using AnyName = std::tuple<A, B>;
};

// `MACARON_ORNAMENTAL_TEMPLATE_INSPECTING` has been shortened by the convenient header.
#define INSPECT_TEMPLATE  \
    Tester

FUNCTION(int, TEMPLATE(int, int*)::AnyName);

// #undef INSPECT_TEMPLATE
#undef INSPECT_TEMPLATE

}}}

// Unset "define_template.hpp"
#include "macaron/ornamental/amenity/undef_template.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header defines macro function `MACARON_ORNAMENTAL_CONSTRUCT`.
// It instantiates its parameter with tokens specified by macro `MACARON_ORNAMENTAL_CONSTRUCT_PARAMETERS_INSPECTING`.
#include "macaron/ornamental/construct.hpp"

// Convenient header:
#include "macaron/ornamental/amenity/define_construct.hpp"

namespace Macaron {
namespace Ornamental {
namespace TestConstruct {

template<typename A, typename B>
struct Tester
{
    using AnyName = std::tuple<A, B>;

    template<typename C, typename D>
    struct NestedTester
    {
        using AnyName = std::tuple<C, D>;
    };
};

// `MACARON_ORNAMENTAL_CONSTRUCT_PARAMETERS_INSPECTING` has been shortened by the convenient header.
#define INSPECT_PARAMETERS  \
    int, int*

FUNCTION(int, CONSTRUCT(Tester)::AnyName);
FUNCTION(int, CONSTRUCT(Tester<int, int>::NestedTester)::AnyName);

// #undef INSPECT_PARAMETERS
#undef INSPECT_PARAMETERS

}}}

// Unset "undef_construct.hpp"
#include "macaron/ornamental/amenity/undef_construct.hpp"
/*********************************************************************************************************************/




#endif
