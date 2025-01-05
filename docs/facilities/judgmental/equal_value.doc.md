# `MACARON_JUDGMENTAL_EQUAL_VALUE`

<p style='text-align: right;'><a href="../../index.md#judgmental-equal-value">To Index</a></p>

## Description

`MACARON_JUDGMENTAL_EQUAL_VALUE` requires the user to define the macro `MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED_VALUE`.

```C++
#define MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED_VALUE\
    b

    MACARON_JUDGMENTAL_EQUAL_VALUE(a)
<=> static_assert(std::equal_as<a, b>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/equal_value.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_equal_value.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_equal_value.hpp</code></td>
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
      <td><code>EQUAL_VALUE</code></td>
      <td><code>MACARON_JUDGMENTAL_EQUAL_VALUE</code></td>
    </tr>
    <tr>
      <td><code>SUPPOSED_VALUE</code></td>
      <td><code>MACARON_JUDGMENTAL_EQUAL_VALUE_SUPPOSED_VALUE</code></td>
    </tr>
  </tbody>
</table>
