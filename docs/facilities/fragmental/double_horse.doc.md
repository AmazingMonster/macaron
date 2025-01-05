# `MACARON_FRAGMENTAL_DOUBLE_HORSE_SPROUT`

<p style='text-align: right;'><a href="../../index.md#fragmental-double-horse">To Index</a></p>

## Description

`MACARON_FRAGMENTAL_DOUBLE_HORSE_SPROUT` requires the user to define the following macros.

- `MACARON_FRAGMENTAL_DOUBLE_HORSE_PREFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_DOUBLE_HORSE_MIDDLE_SYMBOLS`
- `MACARON_FRAGMENTAL_DOUBLE_HORSE_SUFFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_DOUBLE_HORSE_SEPARATOR_SYMBOLS`

```C++
#define MACARON_FRAGMENTAL_DOUBLE_HORSE_PREFIX_SYMBOLS  \
    a

#define MACARON_FRAGMENTAL_DOUBLE_HORSE_MIDDLE_SYMBOLS  \
    b

#define MACARON_FRAGMENTAL_DOUBLE_HORSE_SUFFIX_SYMBOLS  \
    c

#define MACARON_FRAGMENTAL_DOUBLE_HORSE_SEPARATOR_SYMBOLS  \
    d

    MACARON_FRAGMENTAL_DOUBLE_HORSE_SPROUT(4, e)
=>  a 0 b 0 e c d
    a 1 b 1 e c d
    a 2 b 2 e c d
    a 3 b 3 e c
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/fragmental/double_horse.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/fragmental/amenity/define_double_horse.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/fragmental/amenity/undef_double_horse.hpp</code></td>
    </tr>
  </tbody>
</table>

## Amenity

<table>
  <thead>
    <tr>
      <th>After</th>
      <th>Before</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>DOUBLE_HORSE_PREFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_DOUBLE_HORSE_PREFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>DOUBLE_HORSE_MIDDLE</code></td>
      <td><code>MACARON_FRAGMENTAL_DOUBLE_HORSE_MIDDLE_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>DOUBLE_HORSE_SUFFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_DOUBLE_HORSE_SUFFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>DOUBLE_HORSE_SEPARATOR</code></td>
      <td><code>MACARON_FRAGMENTAL_DOUBLE_HORSE_SEPARATOR_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>DOUBLE_HORSE_SPROUT</code></td>
      <td><code>MACARON_FRAGMENTAL_DOUBLE_HORSE_SPROUT</code></td>
    </tr>
  </tbody>
</table>
