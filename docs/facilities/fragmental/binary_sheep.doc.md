# `MACARON_FRAGMENTAL_BINARY_SHEEP_SPROUT`

<p style='text-align: right;'><a href="../../index.md#fragmental-binary-sheep">To Index</a></p>

## Description

`MACARON_FRAGMENTAL_BINARY_SHEEP_SPROUT` requires the user to define the following macros.

- `MACARON_FRAGMENTAL_BINARY_SHEEP_PREFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_BINARY_SHEEP_SUFFIX_SYMBOLS`
- `MACARON_FRAGMENTAL_BINARY_SHEEP_SEPARATOR_SYMBOLS`

```C++
#define MACARON_FRAGMENTAL_BINARY_SHEEP_PREFIX_SYMBOLS  \
    a

#define MACARON_FRAGMENTAL_BINARY_SHEEP_SUFFIX_SYMBOLS  \
    b

#define MACARON_FRAGMENTAL_BINARY_SHEEP_SEPARATOR_SYMBOLS  \
    c

    MACARON_FRAGMENTAL_BINARY_SHEEP_SPROUT(4)
=>  a 0 b c
    a 1 b c
    a 0 b c
    a 1 b
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/fragmental/binary_sheep.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/fragmental/amenity/define_binary_sheep.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/fragmental/amenity/undef_binary_sheep.hpp</code></td>
    </tr>
  </tbody>
</table>

After defining the convenience header, a premade instance become available.

- **Boolean**

  <table>
    <tbody>
      <tr>
        <td><b>Define</b></td>
        <td><code>macaron\fragmental\amenity\instances\define_boolean_sheep.hpp</td>
      </tr>
      <tr>
        <td><b>Undef</b></td>
        <td><code>macaron\fragmental\amenity\instances\undef_boolean_sheep.hpp</code></td>
      </tr>
    </tbody>
  </table>

  ```C++
  BINARY_SHEEP_SPROUT(4) => 0, 1, 0, 1
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
      <td><code>BINARY_SHEEP_PREFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_BINARY_SHEEP_PREFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>BINARY_SHEEP_SUFFIX</code></td>
      <td><code>MACARON_FRAGMENTAL_BINARY_SHEEP_SUFFIX_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>BINARY_SHEEP_SEPARATOR</code></td>
      <td><code>MACARON_FRAGMENTAL_BINARY_SHEEP_SEPARATOR_SYMBOLS</code></td>
    </tr>
    <tr>
      <td><code>BINARY_SHEEP_SPROUT</code></td>
      <td><code>MACARON_FRAGMENTAL_BINARY_SHEEP_SPROUT</code></td>
    </tr>
  </tbody>
</table>
