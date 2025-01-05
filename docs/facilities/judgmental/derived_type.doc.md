# `MACARON_JUDGMENTAL_DERIVED_TYPE`

<p style='text-align: right;'><a href="../../index.md#judgmental-derived-type">To Index</a></p>

## Description

`MACARON_JUDGMENTAL_DERIVED_TYPE` requires the user to define the macro `MACARON_JUDGMENTAL_DERIVED_TYPE_SUPPOSED_BASE`.

```C++
#define MACARON_JUDGMENTAL_DERIVED_TYPE_SUPPOSED_BASE\
    b

    MACARON_JUDGMENTAL_DERIVED_TYPE(a)
<=> static_assert(std::derived_from<a, b>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/derived_type.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_derived_type.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_derived_type.hpp</code></td>
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
      <td><code>DERIVED_TYPE</code></td>
      <td><code>MACARON_JUDGMENTAL_DERIVED_TYPE</code></td>
    </tr>
    <tr>
      <td><code>SUPPOSED_BASE</code></td>
      <td><code>MACARON_JUDGMENTAL_DERIVED_TYPE_SUPPOSED_BASE</code></td>
    </tr>
  </tbody>
</table>
