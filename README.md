# Macaron
A C++ preprocessor library for metaprogramming testing.

## Introduction
This library started as a collection of boilerplates wrapped around static_assert. It was used when I was working on a metaprogramming library named *Conceptrodon*.  

As Conceptrodon grows more complicated, the sheer amount of boilerplates is both bothersome and error-prone.
Oftentimes a typo during testing could hide itself in plain sight as I debugged frustratedly through the real code. Eventually, I made this library.  

The goal of Macaron is to simplify numerous static_asserts and provide a fast way to generate dummy testers. It is possible to create a list of tokens of any amount below 320 by a macro call.
This allows me to test performance on a large scale.  

Macaron consists of four sections:
- Rudimental. This section contains details of basic macro manipulation. It is not part of this library's interface.
- Judgmental. This section contains macro functions wrapped around static_assert.
- Fragmental. This section contains macro functions for token generation.
- Ornamental. Functions in this section were originally used to deal with the 'comma problem' of C++ preprocessor. The problem was solved via a different approach. This section is kept since it can still simplify some situations.

A detailed introduction to each section except Rudimental can be found in the test directory.

## References
I learned a lot from CallableTraits by Barrett Adair[https://github.com/badair] and Cloak by Paul Fultz II[https://github.com/pfultz2]. I am appreciative of their willingness to share knowledge freely.
