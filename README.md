# Macaron

A C++ preprocessor library for metaprogramming testing.

## Introduction

This library started as a collection of boilerplates wrapped around static_assert. It was used when I was working on a metaprogramming library named [Conceptrodon](https://github.com/AmazingMonster/conceptrodon).  

As Conceptrodon grows more complicated, the sheer amount of boilerplates is both bothersome and error-prone.
Often, a typo during testing could hide itself in plain sight as I frustratedly debugged through the real code. Eventually, I made this library.  

The goal of Macaron is to simplify numerous static_asserts and provide a fast way to generate dummy testers. A macro call can create a list of tokens of any amount below 320.
This allows me to test metafunction performance on a large scale.  

Macaron consists of four sections:

- [Rudimental](https://github.com/AmazingMonster/macaron/tree/main/macaron/rudimental). This section contains details of basic macro manipulation. It is not part of this library's interface.
- [Judgmental](https://github.com/AmazingMonster/macaron/tree/main/macaron/judgmental). This section contains macro functions wrapped around static_assert.
- [Fragmental](https://github.com/AmazingMonster/macaron/tree/main/macaron/fragmental). This section contains macro functions for token generation.
- [Ornamental](https://github.com/AmazingMonster/macaron/tree/main/macaron/ornamental). Functions in this section were originally used to deal with the 'comma problem' of C++ preprocessor. The problem was solved via a different approach. This section is kept since it can still simplify some situations.

A detailed introduction to each section, except Rudimental, can be found in the test directory.

## References

I learned a lot from [CallableTraits](https://github.com/boostorg/callable_traits/tree/2a56a3a2496cdb66496f844db55085dd992d5e49) by [Barrett Adai](https://github.com/badair) and [Cloak](https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms#deferred-expression) by [Paul Fultz II](https://github.com/pfultz2). I am appreciative of their willingness to share knowledge freely.
