__init__.pyi:475:putmask: Any
core/numeric.py:18:    putmask, result_type, set_numeric_ops, shares_memory, vdot, where,
core/numeric.py:51:    'identity', 'allclose', 'compare_chararrays', 'putmask',
core/src/multiarray/multiarraymodule.c:1471:array_putmask(PyObject *NPY_UNUSED(module), PyObject *args, PyObject *kwds)
core/src/multiarray/multiarraymodule.c:1478:    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!OO:putmask", kwlist,
core/src/multiarray/multiarraymodule.c:4130:    {"putmask",
core/src/multiarray/multiarraymodule.c:4131:        (PyCFunction)array_putmask,
core/src/multiarray/item_selection.c:495:npy_fastputmask_impl(
core/src/multiarray/item_selection.c:529:npy_fastputmask(
core/src/multiarray/item_selection.c:534:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:537:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:540:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:543:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:546:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:549:        return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:552:    return npy_fastputmask_impl(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/item_selection.c:574:                        "putmask: first argument must "
core/src/multiarray/item_selection.c:587:                        "putmask: mask and data must be "
core/src/multiarray/item_selection.c:646:        npy_fastputmask(dest, src, mask_data, ni, nv, chunk);
core/src/multiarray/usertypes.c:136:    f->fastputmask = NULL;
core/src/multiarray/usertypes.c:144:    if (f->fastputmask != NULL) {
core/src/multiarray/usertypes.c:146:                "The ->f->fastputmask member of custom dtypes is ignored; "
core/src/multiarray/usertypes.c:156:                "The ->f->fastputmask member of custom dtypes is ignored; "
core/multiarray.py:39:    'promote_types', 'putmask', 'ravel_multi_index', 'result_type', 'scalar',
core/multiarray.py:1086:@array_function_from_c_func_and_dispatcher(_multiarray_umath.putmask)
core/multiarray.py:1087:def putmask(a, mask, values):
core/multiarray.py:1089:    putmask(a, mask, values)
core/multiarray.py:1115:    >>> np.putmask(x, x>2, x**2)
core/multiarray.py:1123:    >>> np.putmask(x, x>1, [-33, -44])
core/include/numpy/ndarraytypes.h:549:        PyArray_FastPutmaskFunc *fastputmask;
core/build/lib.linux-x86_64-3.8/core/numeric.py:18:    putmask, result_type, set_numeric_ops, shares_memory, vdot, where,
core/build/lib.linux-x86_64-3.8/core/numeric.py:51:    'identity', 'allclose', 'compare_chararrays', 'putmask',
core/build/lib.linux-x86_64-3.8/core/multiarray.py:39:    'promote_types', 'putmask', 'ravel_multi_index', 'result_type', 'scalar',
core/build/lib.linux-x86_64-3.8/core/multiarray.py:1086:@array_function_from_c_func_and_dispatcher(_multiarray_umath.putmask)
core/build/lib.linux-x86_64-3.8/core/multiarray.py:1087:def putmask(a, mask, values):
core/build/lib.linux-x86_64-3.8/core/multiarray.py:1089:    putmask(a, mask, values)
core/build/lib.linux-x86_64-3.8/core/multiarray.py:1115:    >>> np.putmask(x, x>2, x**2)
core/build/lib.linux-x86_64-3.8/core/multiarray.py:1123:    >>> np.putmask(x, x>1, [-33, -44])
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4595:        np.putmask(x, mask, val)
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4615:        assert_raises(ValueError, np.putmask, np.array([1, 2, 3]), [True], 5)
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4620:        np.putmask(x, [True, False, True], -1)
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4627:        np.putmask(rec['x'], [True, False], 10)
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4631:        np.putmask(rec['y'], [True, False], 11)
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4639:        np.putmask(x[1:4], [True, True, True], x[:3])
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:4643:        np.putmask(x[1:4], x[:3], [True, False, True])
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:8369:    def test_putmask_noncontiguous(self):
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:8371:        # uses arr_putmask
core/build/lib.linux-x86_64-3.8/core/tests/test_multiarray.py:8372:        np.putmask(a, a>2, a**2)
core/build/lib.linux-x86_64-3.8/core/fromnumeric.py:522:    putmask, place
core/tests/test_multiarray.py:4595:        np.putmask(x, mask, val)
core/tests/test_multiarray.py:4615:        assert_raises(ValueError, np.putmask, np.array([1, 2, 3]), [True], 5)
core/tests/test_multiarray.py:4620:        np.putmask(x, [True, False, True], -1)
core/tests/test_multiarray.py:4627:        np.putmask(rec['x'], [True, False], 10)
core/tests/test_multiarray.py:4631:        np.putmask(rec['y'], [True, False], 11)
core/tests/test_multiarray.py:4639:        np.putmask(x[1:4], [True, True, True], x[:3])
core/tests/test_multiarray.py:4643:        np.putmask(x[1:4], x[:3], [True, False, True])
core/tests/test_multiarray.py:8369:    def test_putmask_noncontiguous(self):
core/tests/test_multiarray.py:8371:        # uses arr_putmask
core/tests/test_multiarray.py:8372:        np.putmask(a, a>2, a**2)
core/fromnumeric.py:522:    putmask, place
matrixlib/tests/test_defmatrix.py:284:            'getA', 'getA1', 'item', 'nonzero', 'put', 'putmask', 'resize',
lib/npyio.py:2201:            outputmask = np.array(masks, dtype=mdtype)
lib/npyio.py:2227:                outputmask = rowmasks.view(mdtype)
lib/npyio.py:2258:                outputmask = np.array(masks, dtype=mdtype)
lib/npyio.py:2266:                outputmask[name] |= (output[name] == mval)
lib/npyio.py:2270:        output._mask = outputmask

# Header 0


