<!-- Copyright 2024 Feng Mofan
SPDX-License-Identifier: Apache-2.0 -->

# Hello World

- [**To Index**](./index.md#introduction-hello-world)
- [*Prologue*](#prologue)
- [*Comma Problem*](#comma-problem)

## Prologue <a id="prologue"></a>

The purpose of this library is to simplify the metaprogramming testing process. The user-facing facilities are contained in two directories.

- **Judgmental**: wrap `static_assert` boilerplates into function-like macros.
- **Fragmental**: list a large number of macros following specific patterns for sequential token generation.

To use a macro function, we first need to include the implementation. For example, assuming we want to check whether two types are the same using `MACARON_JUDGMENTAL_SAME`, we will need the header `"macaron/judgmental/same.hpp"`.

```C++
#include "macaron/judgmental/same.hpp"

MACARON_JUDGMENTAL_SAME(int, int);
```

For every function-like macro in this library, there is a convenience header to simplify the notations. The header is always located in a `"amenity"` directory, which shares the same parent directory as the implementation. For example, to shorten `MACARON_JUDGMENTAL_SAME`, we include `"macaron/judgmental/amenity/define_same.hpp"`.

```C++
#include "macaron/judgmental/same.hpp"
#include "macaron/judgmental/amenity/define_same.hpp"

SAME(int, int);
```

Convenience headers do not contain header guards since the shortened names increase the chances of name collision. After the testing is done, the convenience headers shall be reset by including their counterparts, which are located in the same directory. For example, to `undef` `"define_same.hpp"`, we include `"macaron/judgmental/amenity/undef_same.hpp"`.

```C++
#include "macaron/judgmental/same.hpp"
#include "macaron/judgmental/amenity/define_same.hpp"

SAME(int, int);

#include "macaron/judgmental/amenity/undef_same.hpp"
```

## Comma Problem <a id="comma-problem"></a>

Since C++ inherits the syntax of macros from C, which does not have templates, angle brackets will always be recognized as comparison operators by the precompiler.
Thus, the comma within the angle brackets of template instantiation can separate the argument apart.
For example `FUNCTION(int, std::tuple<int, int*>)` will be parsed as if we are calling FUNCTION with `int`, `std::tuple<int`, and `int*>`.

If we have an argument like `std::max(1, 2)`, we can put a pair of parentheses around it so that the compiler will regard it as a single parameter.
A function-like macro call will look like `FUNCTION((std::max(1, 2)))`.

This will not work for `std::tuple<int, int*>` naively since parentheses around a type indicate a cast, which is not what we intended.

One way to get around this is to wrap the argument into another macro, say `Mono`. Then, a function-like macro call will look like `FUNCTION(Mono<std::tuple<int, int*>>)`.

However, after studying [Paul Fultz II's Cloak library](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms), I realized it is possible to detect the existence of the parentheses surrounding the arguments.
We will remove the parentheses if they are presented, after which its contents remain as a whole argument.
This method is consistent with the case of values and friendlier to users.
Therefore, we use it in this library. For example, we can check if `TT<int, int>` is the same as `std::tuple<int, int*>` by `SAME((TT<int, int>), int)`.
