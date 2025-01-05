# `MACARON_JUDGMENTAL_SAME_TYPE`

<p style='text-align: right;'><a href="../../index.md#judgmental-same-type">To Index</a></p>

## Description

`MACARON_JUDGMENTAL_SAME_TYPE` requires the user to define the macro `MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED_TYPE`.

```C++
#define MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED_TYPE\
    b

    MACARON_JUDGMENTAL_SAME_TYPE(a)
<=> static_assert(std::same_as<a, b>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/same_type.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_same_type.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_same_type.hpp</code></td>
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
      <td><code>SAME_TYPE</code></td>
      <td><code>MACARON_JUDGMENTAL_SAME_TYPE</code></td>
    </tr>
    <tr>
      <td><code>SUPPOSED_TYPE</code></td>
      <td><code>MACARON_JUDGMENTAL_SAME_TYPE_SUPPOSED_TYPE</code></td>
    </tr>
  </tbody>
</table>
