# Macaron

A C++ preprocessor library for metaprogramming testing.

## Prologue

This library started as a collection of boilerplates wrapped around static_assert. It was used when I was working on a metaprogramming library named [Conceptrodon](https://github.com/AmazingMonster/conceptrodon).  

As Conceptrodon grows more complicated, the sheer amount of boilerplates is both bothersome and error-prone.
Often, a typo during testing could hide itself in plain sight as I frustratedly debugged through the production code. Eventually, I made this library.  

The goal of Macaron is to simplify numerous static_asserts and provide a convenient way to generate tokens. A macro call can create a list of tokens of any amount below 320.
This allows me to test metafunction performance on a large scale.  

Macaron consists of two sections:

- **Judgmental**: wrap `static_assert` boilerplates into function-like macros.
- **Fragmental**: list a large number of macros following specific patterns for sequential token generation.

## [Documentation](./DOCS.md)

## Install

Macaron is a header-only library. After downloading the code, move the directory *./macaron* to your project, then use it like your own headers.

You can also install Macaron using CMake:

### Windows

1. Download the library.

2. Open Developer Command Prompt that comes with Visual Studio. Redirect to the library folder. Generate a project buildsystem using CMake:

    ```Shell
    cmake -S . -B "Where to build"
    ```

3. Redirect to the build directory you specified after `-B` earlier. Run command:

    ```Shell
    cmake --install . --prefix "Where to install"
    ```

After installation, add the install directory you specified after `--prefix` to variable `CMAKE_PREFIX_PATH` in your project's *CMakeCache.txt*. If the variable doesn't exist, you will need to add the following line to your *CMakeCache.txt*:

```CMake
CMAKE_PREFIX_PATH:PATH=Install directory of the library
```

If `CMAKE_PREFIX_PATH` already exists,
append the install directory to the values of the variable(note the added semicolon):

```CMake
CMAKE_PREFIX_PATH:PATH=...; Install directory of the library
```

In the *CMakeList.txt* of your project, Add:

```CMake
find_package(Macaron REQUIRED CONFIG)
target_link_libraries(YourProject PRIVATE Macaron::Facilities)
```

You are good to go.

## References

I learned a lot from [CallableTraits](https://github.com/boostorg/callable_traits/tree/2a56a3a2496cdb66496f844db55085dd992d5e49) by [Barrett Adai](https://github.com/badair) and [Cloak](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms#deferred-expression) by [Paul Fultz II](https://github.com/pfultz2). I am appreciative of their willingness to share knowledge freely.
