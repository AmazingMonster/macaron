# `MACARON_JUDGMENTAL_INHERIT`

<p style='text-align: right;'><a href="../../index.md#judgmental-inherit">To Index</a></p>

## Description

```C++
    MACARON_JUDGMENTAL_INHERIT(a, b)
<=> static_assert(std::derived_from<a, b>)
```

If the parameter we want to test contains a comma, for example, std::tuple&lt;int, int*&gt;, we can surround the parameter with parentheses.

```C++
    MACARON_JUDGMENTAL_INHERIT(a, (std::tuple<int, int*>))
<=> static_assert(std::derived_from<a, std::tuple<int, int*>>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/inherit.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_inherit.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_inherit.hpp</code></td>
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
      <td><code>INHERIT</code></td>
      <td><code>MACARON_JUDGMENTAL_INHERIT</code></td>
    </tr>
  </tbody>
</table>
