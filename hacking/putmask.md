# Header 0

#### Locations:

* core/numeric.py:18:
`putmask, result_type, set_numeric_ops, shares_memory, vdot, where,`

* core/numeric.py:51:
`'identity', 'allclose', 'compare_chararrays', 'putmask',`

<br>

#### Discussion:

This file `core/numeric.py` seems to be importing `put-mask` from `.multiarray`. 
Need to investigate further.


```
import numpy as np
from . import multiarray
from .multiarray import (
    _fastCopyAndTranspose as fastCopyAndTranspose, ALLOW_THREADS,
	...
    putmask, result_type, set_numeric_ops, shares_memory, vdot, where,
    zeros, normalize_axis_index)
```
```
__all__ = [
    'newaxis', 'ndarray', 'flatiter', 'nditer', 'nested_iters', 'ufunc',
    'identity', 'allclose', 'compare_chararrays', 'putmask']
```

# Header 1

#### Locations:

* core/multiarray.py:39:
`'promote_types', 'putmask', 'ravel_multi_index', 'result_type', 'scalar',`

* core/multiarray.py:1086:
`@array_function_from_c_func_and_dispatcher(_multiarray_umath.putmask)`

* core/multiarray.py:1087:
`def putmask(a, mask, values):`

* core/multiarray.py:1089:
`putmask(a, mask, values)`



<br>

#### Discussion:

This is the actual python implementation of the putmask function:

```
@array_function_from_c_func_and_dispatcher(_multiarray_umath.putmask)
def putmask(a, mask, values):
    """
    putmask(a, mask, values)

    Changes elements of an array based on conditional and input values.

    Sets ``a.flat[n] = values[n]`` for each n where ``mask.flat[n]==True``.

    If `values` is not the same size as `a` and `mask` then it will repeat.
    This gives behavior different from ``a[mask] = values``.

    Parameters
    ----------
    a : ndarray
        Target array.
    mask : array_like
        Boolean mask array. It has to be the same shape as `a`.
    values : array_like
        Values to put into `a` where `mask` is True. If `values` is smaller
        than `a` it will be repeated.

    See Also
    --------
    place, put, take, copyto

    Examples
    --------
    >>> x = np.arange(6).reshape(2, 3)
    >>> np.putmask(x, x>2, x**2)
    >>> x
    array([[ 0,  1,  2],
           [ 9, 16, 25]])

    If `values` is smaller than `a` it is repeated:

    >>> x = np.arange(5)
    >>> np.putmask(x, x>1, [-33, -44])
    >>> x
    array([  0,   1, -33, -44, -33])

    """
    return (a, mask, values)


```
