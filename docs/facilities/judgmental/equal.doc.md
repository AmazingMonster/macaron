# `MACARON_JUDGMENTAL_EQUAL`

<p style='text-align: right;'><a href="../../index.md#judgmental-equal">To Index</a></p>

## Description

```C++
    MACARON_JUDGMENTAL_EQUAL(a, b)
<=> static_assert(a == b)
```

If the parameter we want to test contains a comma, for example, `std::max(1, 2)`, we can surround the parameter with parentheses.

```C++
    MACARON_JUDGMENTAL_EQUAL(a, (std::max(1, 2)))
<=> static_assert(a == std::max(1, 2)>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/equal.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_equal.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_equal.hpp</code></td>
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
      <td><code>EQUAL</code></td>
      <td><code>MACARON_JUDGMENTAL_EQUAL</code></td>
    </tr>
  </tbody>
</table>
