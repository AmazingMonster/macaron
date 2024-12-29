// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_JUDGMENTAL_TEST_JUDGMENTAL_H
#define MACARON_JUDGMENTAL_TEST_JUDGMENTAL_H

/*********************************************************************************************************************/
// I made a few macro functions which are wrapped around static_assert to simplify testing.
// Everything I learned about C++ preprocessor are from Paul Fultz II's library Cloak and \
// Barrett Adair's library CallableTraits.
// Link to Cloak: https://github.com/pfultz2/Cloak/tree/master
// Link to CallableTraits: https://www.boost.org/doc/libs/master/libs/callable_traits/doc/html/index.html
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// The assertions depend on the standard concept library.
// I did not include it in the implementation. Thus We need to include it here.
#include <concepts>
// Since macaron is intended to be used for testing, \
// including external headers like this could cause false positive or negative.
// For example, if the code we are testing forgot to `#include <concepts>` itself \
// and macaron included the header for it, the test would still pass.

// Additional dependence for this test.
#include <tuple>
#include <type_traits>
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This header contains a macro function which simplifies `static_asscert(std::same_as<,>)`.
// It has a header guard and thus shall only be truely included once in the entire program.
#include "macaron/judgmental/same.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestSame {

// The test looks like a funtion call now! 
MACARON_JUDGMENTAL_SAME(int, int);
// MACARON_JUDGMENTAL_SAME(int, int*); /* This one will not pass. */

// If the parameter we want to test contains comma, we can surrounded it by parentheses.
template<auto, auto>
using TesterA = int;

MACARON_JUDGMENTAL_SAME(int, (TesterA<0, 0>));

template<typename A, typename B>
using TesterB = std::tuple<A, B>;

MACARON_JUDGMENTAL_SAME((std::tuple<int, int*>), (TesterB<int, int*>));

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// It doesn't save many letters if we have to type `MACARON_JUDGMENTAL_SAME` all the time.
// That's why I wrote a convenient header to shorten the name to `SAME`.
#include "macaron/judgmental/amenity/define_same.hpp"
// Renaming the macro `SAME` increases the chance of colliding with other names. 
// Therefore This header does not have a header guard.
// It is intended to be included every time we want to use it and unset right after.
// It can be unset by including its sister header "undef_same.hpp".

namespace Macaron {
namespace Judgmental {
namespace TestSame {

// The function is more descriptive now! 
SAME(int, int);
// SAME(int, int*); /* This one will not pass. */

// Tiny note: we can redefine template alias as long as both definition are the same.
template<auto, auto>
using TesterA = int;

SAME(int, (TesterA<0, 0>));

template<typename A, typename B>
using TesterB = std::tuple<A, B>;

SAME((std::tuple<int, int*>), (TesterB<int, int*>));

}}}

// unset "define_same.hpp"
#include "macaron/judgmental/amenity/undef_same.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// Here is a function which is also wrapped around `static_assert(std::same_as<,>)`.
// However, it only takes one parameter. 
// Another parameter for `std::same_as` is provided by macro MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED.
#include "macaron/judgmental/same_type.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_same_type.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestSameType {

// Since we included the convenient header, the name to define is shorter and more descriptive.
#define SUPPOSED_TYPE   \
    int
// If we did not include the convenient header, we will have to #define MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED

// Do tests.
SAME_TYPE(int);
// SAME_TYPE(int*); /* This one will not pass. */

// No need for annoying parentheses anymore!
template<auto, auto>
using TesterA = int;

SAME_TYPE(TesterA<0, 0>);

// #undef SUPPOSED_TYPE
#undef SUPPOSED_TYPE

// Commas can also appear insid SUPPOSED_TYPE:
#define SUPPOSED_TYPE   \
    std::tuple<int, int*>

template<typename A, typename B>
using TesterB = std::tuple<A, B>;

SAME_TYPE(TesterB<int, int*>);

// #undef SUPPOSED_TYPE
#undef SUPPOSED_TYPE

}}}

// Unset "define_same_type.hpp"
#include "macaron/judgmental/amenity/undef_same_type.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function simplifies static_assert(std::derived_from<,>).
#include "macaron/judgmental/inherit.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_inherit.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestInherit {

INHERIT(std::bool_constant<true>, (std::integral_constant<bool, true>));

}}}

// Unset convenient header.
#include "macaron/judgmental/amenity/undef_same.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function simplifies `static_assert(std::derived_from<,>)` but takes only one parameter.
// Another parameter is provided by macro `MACARON_JUDGMENTAL_DERIVED_TYPE_BASE_SUPPOSED`.
#include "macaron/judgmental/derived_type.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_derived_type.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestDeriveType {

#define SUPPOSED_BASE   \
    std::integral_constant<bool, true>

DERIVED_TYPE(std::bool_constant<true>);
DERIVED_TYPE(std::integral_constant<bool, true>);

// undef the macro.
#undef SUPPOSED_BASE

}}}

// Unset "define_derived_type.hpp".
#include "macaron/judgmental/amenity/undef_derived_type.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function 'simplifies' `static_assert(==)`.
// It is hardly a simplification. I wrote them for symmetry.
#include "macaron/judgmental/equal.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_equal.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestEqual {

EQUAL(1, 1);
// Need two pairs of parentheses if the comma is being used as an operator.
EQUAL(1, ((0, 1)));

}}}

// Unset "def_equal.hpp".
#include "macaron/judgmental/amenity/undef_equal.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function is essentially the same as previous one but takes only one parameter   \
// with the other one provided by macro `MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED`.
#include "macaron/judgmental/equal_value.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_equal_value.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestEqualValue {

#define SUPPOSED_VALUE   \
    1

EQUAL_VALUE(1);

#undef SUPPOSED_VALUE

}}}

// Unset "define_equal_value.hpp".
#include "macaron/judgmental/amenity/undef_equal_value.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function tests whether an expression evaluates to true.
// It is a simplification to `static_assert()`.
#include "macaron/judgmental/valid.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_valid.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestValid {

VALID(1);
VALID(10);
VALID(1==1);
// VALID(1==10);
// VALID(0);

template<auto A, auto B>
constexpr auto Tester {A+B};

// Note the white space between > and =:
VALID(Tester<1, 10> == 11);

}}}

// Unset "define_valid.hpp".
#include "macaron/judgmental/amenity/undef_valid.hpp"
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This function tests whether an expression evaluates to false.
// It is a simplification to `static_assert(not)`.
#include "macaron/judgmental/invalid.hpp"

// Convenient header.
#include "macaron/judgmental/amenity/define_invalid.hpp"

namespace Macaron {
namespace Judgmental {
namespace TestInvalid {

// INVALID(1);
// INVALID(10);
// INVALID(1==1);
INVALID(1==10);
INVALID(0);

template<auto A, auto B>
constexpr auto Tester {A+B};

// Note the white space between > and =:
INVALID(Tester<1, 10> != 11);

}}}

// Unset `define_invalid`.
#include "macaron/judgmental/amenity/undef_invalid.hpp"
/*********************************************************************************************************************/




#endif
