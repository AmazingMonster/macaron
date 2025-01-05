# `MACARON_FRAGMENTAL_SHEEP_REVERSED_SPROUT`

<p style='text-align: right;'><a href="../../index.md#fragmental-sheep-reversed">To Index</a></p>

## Description

`MACARON_FRAGMENTAL_SHEEP_REVERSED_SPROUT` requires the user to define the following macros.

- `MACARON_FRAGMENTAL_SHEEP_REVERSED_PREFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_SHEEP_REVERSED_SUFFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_SHEEP_REVERSED_SEPARATOR_SYMBOLS`

```C++
#define MACARON_FRAGMENTAL_SHEEP_REVERSED_PREFIX_SYMBOLS \
    a
#define MACARON_FRAGMENTAL_SHEEP_REVERSED_SUFFIX_SYMBOLS \
    b
#define MACARON_FRAGMENTAL_SHEEP_REVERSED_SEPARATOR_SYMBOLS \
    c

    MACARON_FRAGMENTAL_SHEEP_REVERSED_SPROUT(4, d)
=>  a 3 d b c
    a 2 d b c
    a 1 d b c
    a 0 d b
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/fragmental/sheep_reversed.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/fragmental/amenity/define_sheep_reversed.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/fragmental/amenity/undef_sheep_reversed.hpp</code></td>
    </tr>
  </tbody>
</table>

After defining the convenience header, several premade instances become available.

- **Integer**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integer_sheep_reversed.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integer_sheep_reversed.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
  SHEEP_REVERSED_SPROUT(4, a) => 3 a, 2 a, 1 a, 0 a
  ```

- **Integral Constant**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integral_constant_sheep_reversed.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integral_constant_sheep_reversed.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
     SHEEP_REVERSED_SPROUT(4, a)
  => std::integral_constant<int, 3 a>,
     std::integral_constant<int, 2 a>,
     std::integral_constant<int, 1 a>,
     std::integral_constant<int, 0 a>
  ```

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
      <td><code>SHEEP_REVERSED_PREFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_SHEEP_REVERSED_PREFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>SHEEP_REVERSED_SUFFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_SHEEP_REVERSED_SUFFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>SHEEP_REVERSED_SEPARATOR</code></td>
      <td><code>MACARON_FRAGMENTAL_SHEEP_REVERSED_SEPARATOR_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>SHEEP_REVERSED_SPROUT</code></td>
      <td><code>MACARON_FRAGMENTAL_SHEEP_REVERSED_SPROUT</code></td>
    </tr>
  </tbody>
</table>
