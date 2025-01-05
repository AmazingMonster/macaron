// Copyright 2024 Feng Mofan
// SPDX-License-Identifier: Apache-2.0

#ifndef MACARON_FRAGMENTAL_TEST_FRAGMENTAL_H
#define MACARON_FRAGMENTAL_TEST_FRAGMENTAL_H

/*********************************************************************************************************************/
// This test demonstrates how to generate a list of enumerated tokens using `*_SPROUT`.
// The amount of tokens a single call to `*_SPROUT` can have is any number below 320.
// It is possible to create more tokens by calling `*_SPROUT` repeatedly.
// Llama and horse versions are essentially the same as the sheep version except the macro names.
/*********************************************************************************************************************/




#include <concepts>
#include <utility>




/*********************************************************************************************************************/
// First, We need to include this header, which contains the implementation of `MACARON_FRAGMENTAL_SHEEP_SPROUT`.
// It is needed for all examples showing below.
// It has a header guard and thus shall only be truely included once in the entire program.
// All macro defined here has `MACARON_FRAGMENTAL_SHEEP_*` prefix in their names.
#include "macaron/fragmental/sheep.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestSheep {

// `MACARON_FRAGMENTAL_SHEEP_SPROUT` relies on the following three macros to generate correct lists.
// It is necessary to define all three of them. 
// Otherwise these macro names will survive the preprocessing stage and likely cause syntax error during compiling.
#define MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS \
    std::integral_constant<int,
#define MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS \
    >
#define MACARON_FRAGMENTAL_SHEEP_SEPARATOR_SYMBOLS  \
    ,

static_assert(
std::same_as<

// Now, let's generate a tuple using the function macro MACARON_FRAGMENTAL_SHEEP_SPROUT.
    std::tuple<
        MACARON_FRAGMENTAL_SHEEP_SPROUT(10)
    >,

// It should be the same as the following tuple.
    std::tuple<

// The three macros we define at the beginning will layout like this:
// MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS  0  MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS  MACARON_FRAGMENTAL_SHEEP_SEPARATOR_SYMBOLS    
        std::integral_constant<int,         0                    >                                        , 
        std::integral_constant<int, 1>, 
        std::integral_constant<int, 2>, 
        std::integral_constant<int, 3>, 
        std::integral_constant<int, 4>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 6>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 8>, 

// The last one will not have trailing separator symbols:
// MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS  9  MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS
        std::integral_constant<int,         9                    >
    >
>
);


static_assert(
std::same_as<

// We can also add tokens as the second parameter of the `*SPROUT` function to modify the enumeration.
    std::tuple<
        MACARON_FRAGMENTAL_SHEEP_SPROUT(10, *2 + 1)
    >,

    std::tuple<

// In this case, the layout of all the symbols will look like this:
// MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS  0   __VA_ARGS__ MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS  MACARON_FRAGMENTAL_SHEEP_SEPARATOR_SYMBOLS    
        std::integral_constant<int,         0      *2+1                       >                                        , 
        std::integral_constant<int, 3>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 9>, 
        std::integral_constant<int, 11>, 
        std::integral_constant<int, 13>, 
        std::integral_constant<int, 15>, 
        std::integral_constant<int, 17>, 

// Like before, the last one will not have trailing separator symbols:
// MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS  9   __VA_ARGS__ MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS
        std::integral_constant<int,         9      *2+1                    >
    >
>
);

// Finally, we need to #undef all the macros.
#undef MACARON_FRAGMENTAL_SHEEP_PREFIX_SYMBOLS
#undef MACARON_FRAGMENTAL_SHEEP_SUFFIX_SYMBOLS
#undef MACARON_FRAGMENTAL_SHEEP_SEPARATOR_SYMBOLS

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// It is tiring and error-prone to type those names all the time. 
// Therefore, I wrote some helper macros to simplify the names.
// To use them, we will need an additional header:
#include "macaron/fragmental/amenity/define_sheep.hpp"
// This header does not has a header guard.
// It shortens the macro names but increases the chance of name collision.
// Therefor this header is intended to be included every time when short names are safe to use and unset after.
// We can unset everything by including its sister header 'undef_sheep.hpp'.

namespace Macaron {
namespace Fragmental {
namespace TestSheep {

// Now the names are much shorter!
#define SHEEP_PREFIX \
    std::integral_constant<int,
#define SHEEP_SUFFIX \
    >
#define SHEEP_SEPARATOR  \
    ,

static_assert(
std::same_as<
    std::tuple<
        SHEEP_SPROUT(10, *2 + 1)
    >,
    std::tuple<
// the layout of all the symbols now look like this:
//              SHEEP_PREFIX                0       __VA_ARGS__     SHEEP_SUFFIX    SHEEP_SEPARATOR   
        std::integral_constant<int,         0          *2+1              >               , 
        std::integral_constant<int, 3>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 9>, 
        std::integral_constant<int, 11>, 
        std::integral_constant<int, 13>, 
        std::integral_constant<int, 15>, 
        std::integral_constant<int, 17>, 

//          SHEEP_PREFIX                    9       __VA_ARGS__     SHEEP_SUFFIX    SHEEP_SEPARATOR    
        std::integral_constant<int,         9          *2+1              >
    >
>
);

// We still need to undefine all the macros.
#undef SHEEP_PREFIX
#undef SHEEP_SUFFIX
#undef SHEEP_SEPARATOR

// Include the sister header to unset "define_sheep.hpp".
#include "macaron/fragmental/amenity/undef_sheep.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// It is still annoying to define these setup macros all the time.
// Therefore I pre-define some instances which I find the most useful.

// Still, we need to include this header.
// It defines all the names needed for the setup.
#include "macaron/fragmental/amenity/define_sheep.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestSheep {

// The definitions of all the setup macros are now moved into this header.
// It does not have a header guard and is intended to be unset right after its use.
// We can unset it by including its sister header "undef_integral_constant_sheep.hpp".
#include "macaron/fragmental/amenity/instances/define_integral_constant_sheep.hpp"
static_assert(
std::same_as<
    std::tuple<
        SHEEP_SPROUT(10, *2 + 1)
    >,
    std::tuple<
        std::integral_constant<int, 1>, 
        std::integral_constant<int, 3>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 9>, 
        std::integral_constant<int, 11>, 
        std::integral_constant<int, 13>, 
        std::integral_constant<int, 15>, 
        std::integral_constant<int, 17>,
        std::integral_constant<int, 19>
    >
>
);
// This header behaves the same as #undef `SHEEP_PREFIX`, `SHEEP_SUFFIX`, `SHEEP_SEPARATOR` manually.
#include "macaron/fragmental/amenity/instances/undef_integral_constant_sheep.hpp"



// There is a another one for plain numbers
#include "macaron/fragmental/amenity/instances/define_integer_sheep.hpp"
static_assert(
std::same_as<
    std::index_sequence<
        SHEEP_SPROUT(10, *2 + 1)
    >,
    std::index_sequence<
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19
    >
>
);
#include "macaron/fragmental/amenity/instances/undef_integer_sheep.hpp"

// Unset "define_sheep.hpp"
#include "macaron/fragmental/amenity/undef_sheep.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// There are a couple variations that can generate different lists.
// While some of them can be produced by manipulating setup macros from the macro function mentioned above,
// I implement these variations independently to keep the logic simple and to avoid potential compile time overhead.
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// Here's a function that counts numbers in reverse.
// Firstly, we include this header for the implementation.
#include "macaron/fragmental/sheep_reversed.hpp"

// Then, we using the convenient header to shorten the names.
#include "macaron/fragmental/amenity/define_sheep_reversed.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestSheepReversed {

// Note the name changes in the setup macros.
// This way we can use them alongside the other list generation macro functions.
#define SHEEP_REVERSED_PREFIX \
    std::integral_constant<int,
#define SHEEP_REVERSED_SUFFIX \
    >
#define SHEEP_REVERSED_SEPARATOR  \
    ,

static_assert(
std::same_as<
    std::tuple<
        SHEEP_REVERSED_SPROUT(10, *2 + 1)
    >,
    std::tuple<
//         SHEEP_REVERSED_PREFIX            9       __VA_ARGS__     SHEEP_REVERSED_SUFFIX    SHEEP_REVERSED_SEPARATOR   
        std::integral_constant<int,         9          *2+1                 >                           , 
        std::integral_constant<int, 17>, 
        std::integral_constant<int, 15>, 
        std::integral_constant<int, 13>, 
        std::integral_constant<int, 11>, 
        std::integral_constant<int, 9>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 3>,
//         SHEEP_REVERSED_PREFIX            0       __VA_ARGS__     SHEEP_REVERSED_SUFFIX
        std::integral_constant<int,         0          *2+1                 >
    >
>
);

// #undef the macros.
#undef SHEEP_REVERSED_PREFIX
#undef SHEEP_REVERSED_SUFFIX
#undef SHEEP_REVERSED_SEPARATOR

// There are also some pre-defined instances.
// Here's one for `std::integral_constant`:
#include "macaron/fragmental/amenity/instances/define_integral_constant_sheep_reversed.hpp"
static_assert(
std::same_as<
    std::tuple<
        SHEEP_REVERSED_SPROUT(10, *2 + 1)
    >,
    std::tuple<
        std::integral_constant<int, 19>,
        std::integral_constant<int, 17>, 
        std::integral_constant<int, 15>, 
        std::integral_constant<int, 13>, 
        std::integral_constant<int, 11>, 
        std::integral_constant<int, 9>, 
        std::integral_constant<int, 7>, 
        std::integral_constant<int, 5>, 
        std::integral_constant<int, 3>,
        std::integral_constant<int, 1>
    >
>
);
// Unset "define_integral_constant_sheep_reversed.hpp".
#include "macaron/fragmental/amenity/instances/undef_integral_constant_sheep_reversed.hpp"

// Here's one for plain integers:
#include "macaron/fragmental/amenity/instances/define_integer_sheep_reversed.hpp"
static_assert(
std::same_as<
    std::index_sequence<
        SHEEP_REVERSED_SPROUT(10, *2 + 1)
    >,
    std::index_sequence<
        19, 17, 15, 13, 11, 9, 7, 5, 3, 1
    >
>
);
// Unset "define_integer_sheep_reversed.hpp".
#include "macaron/fragmental/amenity/instances/undef_integer_sheep_reversed.hpp"

// Unset "define_sheep_reversed.hpp".
#include "macaron/fragmental/amenity/undef_sheep_reversed.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// Here's a function that count the same number twice before preceed to the next one.
// Implementation header:
#include "macaron/fragmental/double_sheep.hpp"

// Convenient header:
#include "macaron/fragmental/amenity/define_double_sheep.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestDoubleSheep {

// There're four setup macros to define:
#define DOUBLE_SHEEP_PREFIX \
    std::integral_constant<int,
#define DOUBLE_SHEEP_MIDDLE \
    >, std::integral_constant<int,
#define DOUBLE_SHEEP_SUFFIX \
    >
#define DOUBLE_SHEEP_SEPARATOR  \
    ,

static_assert(
std::same_as<
    std::tuple<
        DOUBLE_SHEEP_SPROUT(10, *2 + 1)
    >,
    std::tuple<
// The second argument will be added to the end of the second number.
//         DOUBLE_SHEEP_PREFIX              0           DOUBLE_SHEEP_MIDDLE             0   __VA_ARGS__     DOUBLE_SHEEP_SUFFIX      DOUBLE_SHEEP_SEPARATOR   
        std::integral_constant<int,         0       >, std::integral_constant<int,      0      *2+1                 >                           , 
        std::integral_constant<int, 1>, std::integral_constant<int, 3>, 
        std::integral_constant<int, 2>, std::integral_constant<int, 5>,
        std::integral_constant<int, 3>, std::integral_constant<int, 7>,
        std::integral_constant<int, 4>, std::integral_constant<int, 9>,
        std::integral_constant<int, 5>, std::integral_constant<int, 11>,
        std::integral_constant<int, 6>, std::integral_constant<int, 13>,
        std::integral_constant<int, 7>, std::integral_constant<int, 15>,
        std::integral_constant<int, 8>, std::integral_constant<int, 17>,
//         DOUBLE_SHEEP_PREFIX              9           DOUBLE_SHEEP_MIDDLE             9   __VA_ARGS__     DOUBLE_SHEEP_SUFFIX
        std::integral_constant<int,         9       >, std::integral_constant<int,      9      *2+1                 >
    >
>
);

// #undef the macros.
#undef DOUBLE_SHEEP_PREFIX
#undef DOUBLE_SHEEP_MIDDLE
#undef DOUBLE_SHEEP_SUFFIX
#undef DOUBLE_SHEEP_SEPARATOR

// Unset "define_double_sheep.hpp".
#include "macaron/fragmental/amenity/undef_double_sheep.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// Here's the reversed version for `DOUBLE_SHEEP_SPROUT`.
// Implementation header:
#include "macaron/fragmental/double_sheep_reversed.hpp"

// Convenient header:
#include "macaron/fragmental/amenity/define_double_sheep_reversed.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestDoubleReversedSheep {

// Setup macros:
#define DOUBLE_SHEEP_REVERSED_PREFIX \
    std::integral_constant<int,
#define DOUBLE_SHEEP_REVERSED_MIDDLE \
    >, std::integral_constant<int,
#define DOUBLE_SHEEP_REVERSED_SUFFIX \
    >
#define DOUBLE_SHEEP_REVERSED_SEPARATOR  \
    ,

static_assert(
std::same_as<
    std::tuple<
        DOUBLE_SHEEP_REVERSED_SPROUT(10, *2 + 1)
    >,
    std::tuple<
// The second argument will be added to the end of the second number.
//      DOUBLE_SHEEP_REVERSED_PREFIX              9           DOUBLE_SHEEP_REVERSED_MIDDLE             9   __VA_ARGS__     DOUBLE_SHEEP_REVERSED_SUFFIX      DOUBLE_SHEEP_REVERSED_SEPARATOR   
        std::integral_constant<int,               9           >, std::integral_constant<int,           9      *2+1                      >                                   , 
        std::integral_constant<int, 8>, std::integral_constant<int, 17>, 
        std::integral_constant<int, 7>, std::integral_constant<int, 15>,
        std::integral_constant<int, 6>, std::integral_constant<int, 13>,
        std::integral_constant<int, 5>, std::integral_constant<int, 11>,
        std::integral_constant<int, 4>, std::integral_constant<int, 9>,
        std::integral_constant<int, 3>, std::integral_constant<int, 7>,
        std::integral_constant<int, 2>, std::integral_constant<int, 5>,
        std::integral_constant<int, 1>, std::integral_constant<int, 3>,
//      DOUBLE_SHEEP_REVERSED_PREFIX              0           DOUBLE_SHEEP_REVERSED_MIDDLE             0   __VA_ARGS__     DOUBLE_SHEEP_REVERSED_SUFFIX
        std::integral_constant<int,               0           >, std::integral_constant<int,           0      *2+1                      >
    >
>
);

// #undef the macros.
#undef DOUBLE_SHEEP_REVERSED_PREFIX
#undef DOUBLE_SHEEP_REVERSED_MIDDLE
#undef DOUBLE_SHEEP_REVERSED_SUFFIX
#undef DOUBLE_SHEEP_REVERSED_SEPARATOR

// Unset "define_double_sheep_reversed.hpp".
#include "macaron/fragmental/amenity/undef_double_sheep_reversed.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// Here's a macro function that count 0 and 1 repeatedly.
// Implementation header:
#include "macaron/fragmental/binary_sheep.hpp"

// Convenient header:
#include "macaron/fragmental/amenity/define_binary_sheep.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestBinarySheep {

// Setup macros:
#define BINARY_SHEEP_PREFIX \
    std::integral_constant<int,
#define BINARY_SHEEP_SUFFIX \
    >
#define BINARY_SHEEP_SEPARATOR  \
    ,

static_assert(
std::same_as<
// Second argument is not available for this macro function:
    std::tuple<
        BINARY_SHEEP_SPROUT(10)
    >,
    std::tuple<
// The second argument will be added to the end of the second number.
//      BINARY_SHEEP_PREFIX             0           BINARY_SHEEP_SUFFIX      BINARY_SHEEP_SEPARATOR   
        std::integral_constant<int,     0                   >                       , 
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
//      BINARY_SHEEP_PREFIX             1           BINARY_SHEEP_SUFFIX
        std::integral_constant<int,     1                   >
    >
>
);

// #undef the macros.
#undef BINARY_SHEEP_PREFIX
#undef BINARY_SHEEP_SUFFIX
#undef BINARY_SHEEP_SEPARATOR

// Here's a pre-defined instance for plain integers:
#include "macaron/fragmental/amenity/instances/define_boolean_sheep.hpp"
static_assert(
std::same_as<
    std::integer_sequence<bool,
        BINARY_SHEEP_SPROUT(10)
    >,
    std::integer_sequence<bool,
        false, true, false, true, false, true, false, true, false, true
    >
>
);
// Unset "define_boolean_sheep.hpp".
#include "macaron/fragmental/amenity/instances/undef_boolean_sheep.hpp"

// Unset "define_binary_sheep.hpp".
#include "macaron/fragmental/amenity/undef_binary_sheep.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This macro function counts 1 and 0 repeatedly.
// Implementation header:
#include "macaron/fragmental/binary_sheep_alternative.hpp"

// Convenient header:
#include "macaron/fragmental/amenity/define_binary_sheep_alternative.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestBinarySheepAlternative {

// Setup macros:
#define BINARY_SHEEP_ALTERNATIVE_PREFIX \
    std::integral_constant<int,
#define BINARY_SHEEP_ALTERNATIVE_SUFFIX \
    >
#define BINARY_SHEEP_ALTERNATIVE_SEPARATOR  \
    ,

static_assert(
std::same_as<
// Second argument is not available for this macro function:
    std::tuple<
        BINARY_SHEEP_ALTERNATIVE_SPROUT(10)
    >,
    std::tuple<
// The second argument will be added to the end of the second number.
//      BINARY_SHEEP_PREFIX             1           BINARY_SHEEP_SUFFIX      BINARY_SHEEP_SEPARATOR   
        std::integral_constant<int,     1                   >                       , 
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 1>,
//      BINARY_SHEEP_PREFIX             0           BINARY_SHEEP_SUFFIX
        std::integral_constant<int,     0                   >
    >
>
);

// #undef the macros!
#undef BINARY_SHEEP_ALTERNATIVE_PREFIX
#undef BINARY_SHEEP_ALTERNATIVE_SUFFIX
#undef BINARY_SHEEP_ALTERNATIVE_SEPARATOR

// Here's a pre-defined instance for plain integers:
#include "macaron/fragmental/amenity/instances/define_boolean_sheep_alternative.hpp"
static_assert(
std::same_as<
    std::integer_sequence<bool,
        BINARY_SHEEP_ALTERNATIVE_SPROUT(10)
    >,
    std::integer_sequence<bool,
        true, false, true, false, true, false, true, false, true, false
    >
>
);
// Unset "define_boolean_sheep_alternative.hpp".
#include "macaron/fragmental/amenity/instances/undef_boolean_sheep_alternative.hpp"

// Unset "define_binary_sheep_alternative.hpp".
#include "macaron/fragmental/amenity/undef_binary_sheep_alternative.hpp"

}}}
/*********************************************************************************************************************/




/*********************************************************************************************************************/
// This is a macro function that repeats a customizable token.
#include "macaron/fragmental/alkane.hpp"

// Convenient header:
#include "macaron/fragmental/amenity/define_alkane.hpp"

namespace Macaron {
namespace Fragmental {
namespace TestAlkane {

// Setup macros:
#define ALKANE_PREFIX \
    std::integral_constant<int,
// This is the token that will be repeated:
#define ALKANE_CARBON   \
    0
#define ALKANE_SUFFIX \
    >
#define ALKANE_SEPARATOR  \
    ,

static_assert(
std::same_as<
// Second argument is not available for this macro function:
    std::tuple<
        ALKANE_SPROUT(10)
    >,
    std::tuple<
// The second argument will be added to the end of the second number.
//      BINARY_SHEEP_PREFIX             0           BINARY_SHEEP_SUFFIX      BINARY_SHEEP_SEPARATOR   
        std::integral_constant<int,     0                    >                       , 
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
//      BINARY_SHEEP_PREFIX             0           BINARY_SHEEP_SUFFIX
        std::integral_constant<int,     0                    >
    >
>
);

// #undef the macros.
#undef ALKANE_PREFIX
#undef ALKANE_CARBON
#undef ALKANE_SUFFIX
#undef ALKANE_SEPARATOR

// Pre-defined instance for `std::integral_constant<int, 0>`:
#include "macaron/fragmental/amenity/instances/define_integral_constant_zero_alkane.hpp"
static_assert(
std::same_as<
    std::tuple<
        ALKANE_SPROUT(10)
    >,
    std::tuple<
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>,
        std::integral_constant<int, 0>
    >
>
);
// Unset the instance.
#include "macaron/fragmental/amenity/instances/undef_integral_constant_zero_alkane.hpp"

// Pre-defined instance for std::integral_constant<int, -1>:
#include "macaron/fragmental/amenity/instances/define_integral_constant_negative_one_alkane.hpp"
static_assert(
std::same_as<
    std::tuple<
        ALKANE_SPROUT(10)
    >,
    std::tuple<
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>,
        std::integral_constant<int, -1>
    >
>
);
// Unset the instance.
#include "macaron/fragmental/amenity/instances/undef_integral_constant_negative_one_alkane.hpp"

// Pre-defined instance for std::integral_constant<int, 1>:
#include "macaron/fragmental/amenity/instances/define_integral_constant_one_alkane.hpp"
static_assert(
std::same_as<
    std::tuple<
        ALKANE_SPROUT(10)
    >,
    std::tuple<
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>,
        std::integral_constant<int, 1>
    >
>
);
// Unset the instance.
#include "macaron/fragmental/amenity/instances/undef_integral_constant_one_alkane.hpp"

// Pre-defined instance for 0:
#include "macaron/fragmental/amenity/instances/define_integer_zero_alkane.hpp"
static_assert(
std::same_as<
    std::index_sequence<
        ALKANE_SPROUT(10)
    >,
    std::index_sequence<
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    >
>
);
// Unset "define_integer_zero_alkane.hpp".
#include "macaron/fragmental/amenity/instances/undef_integer_zero_alkane.hpp"

// Pre-defined instance for -1:
#include "macaron/fragmental/amenity/instances/define_integer_negative_one_alkane.hpp"
static_assert(
std::same_as<
    std::integer_sequence<int, 
        ALKANE_SPROUT(10)
    >,
    std::integer_sequence<int,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    >
>
);
// Unset "define_integer_negative_one_alkane.hpp".
#include "macaron/fragmental/amenity/instances/undef_integer_negative_one_alkane.hpp"

// Pre-defined instance for 1:
#include "macaron/fragmental/amenity/instances/define_integer_one_alkane.hpp"
static_assert(
std::same_as<
    std::integer_sequence<int, 
        ALKANE_SPROUT(10)
    >,
    std::integer_sequence<int,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    >
>
);
// Unset "define_integer_one_alkane.hpp".
#include "macaron/fragmental/amenity/instances/undef_integer_one_alkane.hpp"

// Unset "define_alkane.hpp".
#include "macaron/fragmental/amenity/undef_alkane.hpp"

}}}
/*********************************************************************************************************************/




#endif
