# `MACARON_JUDGMENTAL_SAME`

<p style='text-align: right;'><a href="../../index.md#judgmental-same">To Index</a></p>

## Description

```C++
    MACARON_JUDGMENTAL_SAME(a, b)
<=> static_assert(std::same_as<a, b>)
```

If the parameter we want to test contains a comma, for example, std::tuple&lt;int, int*&gt;, we can surround the parameter with parentheses.

```C++
    MACARON_JUDGMENTAL_SAME(a, (std::tuple<int, int*>))
<=> static_assert(std::same_as<a, std::tuple<int, int*>>)
```

## Headers

<table>
  <tbody>
    <tr>
      <td><b>Implementation</b></td>
      <td><code>macaron/judgmental/same.hpp</code></td>
    </tr>
    <tr>
      <td><b>Define amenity</b></td>
      <td><code>macaron/judgmental/amenity/define_same.hpp</code></td>
    </tr>
    <tr>
      <td><b>Undef amenity</b></td>
      <td><code>macaron/judgmental/amenity/undef_same.hpp</code></td>
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
      <td><code>SAME</code></td>
      <td><code>MACARON_JUDGMENTAL_SAME</code></td>
    </tr>
  </tbody>
</table>
