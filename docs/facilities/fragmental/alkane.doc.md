# `MACARON_FRAGMENTAL_ALKANE_SPROUT`

<p style='text-align: right;'><a href="../../index.md#fragmental-alkane">To Index</a></p>

## Description

`MACARON_FRAGMENTAL_ALKANE_SPROUT` requires the user to define the following macros.

- `MACARON_FRAGMENTAL_ALKANE_PREFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_ALKANE_SUFFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_ALKANE_SEPARATOR_SYMBOLS`

```C++
#define MACARON_FRAGMENTAL_ALKANE_PREFIX_SYMBOLS  \
    a

#define MACARON_FRAGMENTAL_ALKANE_CARBON_SYMBOLS  \
    b

#define MACARON_FRAGMENTAL_ALKANE_SUFFIX_SYMBOLS  \
    c

#define MACARON_FRAGMENTAL_ALKANE_SEPARATOR_SYMBOLS  \
    d

    MACARON_FRAGMENTAL_ALKANE_SPROUT(4)
=>  a b c b
    a b c b
    a b c b
    a b c
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/fragmental/alkane.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/fragmental/amenity/define_alkane.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/fragmental/amenity/undef_alkane.hpp</code></td>
    </tr>
  </tbody>
</table>

After defining the convenience header, several premade instances become available.

- **`-1`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integer_negative_one_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integer_negative_one_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
  ALKANE_SPROUT(4) => -1, -1, -1, -1
  ```

- **`0`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integer_zero_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integer_zero_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
  ALKANE_SPROUT(4) => 0, 0, 0, 0
  ```

- **`1`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integer_one_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integer_one_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
     ALKANE_SPROUT(4) => 1, 1, 1, 1
  ```

- **`std::integral_constant<int, -1>`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integral_constant_negative_one_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integral_constant_negative_one_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
     ALKANE_SPROUT(4)
  => std::integral_constant<int, -1>,
     std::integral_constant<int, -1>,
     std::integral_constant<int, -1>,
     std::integral_constant<int, -1>
  ```

- **`std::integral_constant<int, 0>`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integral_constant_zero_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integral_constant_zero_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
     ALKANE_SPROUT(4)
  => std::integral_constant<int, 0>,
     std::integral_constant<int, 0>,
     std::integral_constant<int, 0>,
     std::integral_constant<int, 0>
  ```

- **`std::integral_constant<int, 1>`**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_integral_constant_one_alkane.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_integral_constant_one_alkane.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
     ALKANE_SPROUT(4)
  => std::integral_constant<int, 1>,
     std::integral_constant<int, 1>,
     std::integral_constant<int, 1>,
     std::integral_constant<int, 1>
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
      <td><code>ALKANE_PREFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_ALKANE_PREFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>ALKANE_SUFFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_ALKANE_SUFFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>ALKANE_SEPARATOR</code></td>
      <td><code>MACARON_FRAGMENTAL_ALKANE_SEPARATOR_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>ALKANE_SPROUT</code></td>
      <td><code>MACARON_FRAGMENTAL_ALKANE_SPROUT</code></td>
    </tr>
  </tbody>
</table>
