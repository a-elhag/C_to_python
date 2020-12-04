# Header 0

#### Locations:

1) numpy/__init__.pxd:598: 
`object PyArray_PutMask (ndarray, object, object)`

2) numpy/__init__.cython-30.pxd:640: 
`object PyArray_PutMask (ndarray, object, object)`

<br>

#### Discussion:

These are not needed. 

Or maybe they are needed. 

Who knows? 

But there is nothinig more in there than what is shown next to them

# Header 1

#### Locations:

1) numpy/core/src/multiarray/multiarraymodule.c:1482:
`return PyArray_PutMask((PyArrayObject *)array, values, mask);`

<br>

#### Discussion:

This is the *first whatchamacallit* 

```
static PyObject *
array_putmask(PyObject *NPY_UNUSED(module), PyObject *args, PyObject *kwds)
{
    PyObject *mask, *values;
    PyObject *array;

    static char *kwlist[] = {"arr", "mask", "values", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!OO:putmask", kwlist,
                &PyArray_Type, &array, &mask, &values)) {
        return NULL;
    }
    return PyArray_PutMask((PyArrayObject *)array, values, mask);
}
```

And in the same file, we got the *SECOND WHATCHAMACALLIT*
**static struct PyMethodDef ..[]**

line: 4075 || line: 4131
```
static struct PyMethodDef array_module_methods[] = {
	...
	...
	...
    {"putmask",
        (PyCFunction)array_putmask,
        METH_VARARGS | METH_KEYWORDS, NULL},
	...
	...
	...
    {NULL, NULL, 0, NULL}                /* sentinel */
};

```

# Header 2

#### Locations:
* numpy/core/src/multiarray/item_selection.c:560:
`PyArray_PutMask(PyArrayObject *self, PyObject* values0, PyObject* mask0)`


And now this is the actual function called by the *FIRST WHATCHAMACALLIT*

```
/*NUMPY_API
 * Put values into an array according to a mask.
 */
NPY_NO_EXPORT PyObject *
PyArray_PutMask(PyArrayObject *self, PyObject* values0, PyObject* mask0)
{
    PyArrayObject *mask, *values;
    PyArray_Descr *dtype;
    npy_intp chunk, ni, nv;
    char *src, *dest;
    npy_bool *mask_data;
    int copied = 0;
    int overlap = 0;

    mask = NULL;
    values = NULL;
    if (!PyArray_Check(self)) {
        PyErr_SetString(PyExc_TypeError,
                        "putmask: first argument must "
                        "be an array");
        return NULL;
    }

    mask = (PyArrayObject *)PyArray_FROM_OTF(mask0, NPY_BOOL,
                                NPY_ARRAY_CARRAY | NPY_ARRAY_FORCECAST);
    if (mask == NULL) {
        goto fail;
    }
    ni = PyArray_SIZE(mask);
    if (ni != PyArray_SIZE(self)) {
        PyErr_SetString(PyExc_ValueError,
                        "putmask: mask and data must be "
                        "the same size");
        goto fail;
    }
    mask_data = PyArray_DATA(mask);
    dtype = PyArray_DESCR(self);
    Py_INCREF(dtype);
    values = (PyArrayObject *)PyArray_FromAny(values0, dtype,
                                    0, 0, NPY_ARRAY_CARRAY, NULL);
    if (values == NULL) {
        goto fail;
    }
    nv = PyArray_SIZE(values); /* zero if null array */
    if (nv <= 0) {
        Py_XDECREF(values);
        Py_XDECREF(mask);
        Py_RETURN_NONE;
    }
    src = PyArray_DATA(values);

    overlap = arrays_overlap(self, values) || arrays_overlap(self, mask);
    if (overlap || !PyArray_ISCONTIGUOUS(self)) {
        int flags = NPY_ARRAY_CARRAY | NPY_ARRAY_WRITEBACKIFCOPY;
        PyArrayObject *obj;

        if (overlap) {
            flags |= NPY_ARRAY_ENSURECOPY;
        }

        dtype = PyArray_DESCR(self);
        Py_INCREF(dtype);
        obj = (PyArrayObject *)PyArray_FromArray(self, dtype, flags);
        if (obj != self) {
            copied = 1;
        }
        self = obj;
    }

    chunk = PyArray_DESCR(self)->elsize;
    dest = PyArray_DATA(self);

    if (PyDataType_REFCHK(PyArray_DESCR(self))) {
        for (npy_intp i = 0, j = 0; i < ni; i++, j++) {
            if (j >= nv) {
                j = 0;
            }
            if (mask_data[i]) {
                char *src_ptr = src + j*chunk;
                char *dest_ptr = dest + i*chunk;

                PyArray_Item_INCREF(src_ptr, PyArray_DESCR(self));
                PyArray_Item_XDECREF(dest_ptr, PyArray_DESCR(self));
                memmove(dest_ptr, src_ptr, chunk);
            }
        }
    }
    else {
        NPY_BEGIN_THREADS_DEF;
        NPY_BEGIN_THREADS_DESCR(PyArray_DESCR(self));
        npy_fastputmask(dest, src, mask_data, ni, nv, chunk);
        NPY_END_THREADS;
    }

    Py_XDECREF(values);
    Py_XDECREF(mask);
    if (copied) {
        PyArray_ResolveWritebackIfCopy(self);
        Py_DECREF(self);
    }
    Py_RETURN_NONE;

 fail:
    Py_XDECREF(mask);
    Py_XDECREF(values);
    if (copied) {
        PyArray_DiscardWritebackIfCopy(self);
        Py_XDECREF(self);
    }
    return NULL;
}
```
# Header 3

#### Locations:

* numpy/core/include/numpy/multiarray_api.txt:777:
`PyArray_PutMask(PyArrayObject *self, PyObject*values0, PyObject*mask0)`

<br> 

#### Discussion

Nothing more here than this:

```
::

  PyObject *
  PyArray_PutMask(PyArrayObject *self, PyObject*values0, PyObject*mask0)

Put values into an array according to a mask.

```

# Header 4

#### Locations:

* numpy/core/include/numpy/__multiarray_api.h:266:
`NPY_NO_EXPORT  PyObject * PyArray_PutMask \`

* numpy/core/include/numpy/__multiarray_api.h:939:
`#define PyArray_PutMask \`

<br>

#### Discussion:

This is what the first link shows:

```
NPY_NO_EXPORT  PyObject * PyArray_PutMask \
       (PyArrayObject *, PyObject*, PyObject*);
```

And this is what the second location shows:

```
...
...
...

#define PyArray_PutTo \
        (*(PyObject * (*)(PyArrayObject *, PyObject*, PyObject *, NPY_CLIPMODE)) \
         PyArray_API[125])
#define PyArray_PutMask \
        (*(PyObject * (*)(PyArrayObject *, PyObject*, PyObject*)) \
         PyArray_API[126])
#define PyArray_Repeat \
        (*(PyObject * (*)(PyArrayObject *, PyObject *, int)) \
         PyArray_API[127])

...
...
...
```

# Header 5

#### Locations:

numpy/core/include/numpy/__multiarray_api.c:133:
`(void *) PyArray_PutMask,`

#### Discussion:

This is a very long void pointer array ==> `PyArray_API[]`

```
void *PyArray_API[] = {
        (void *) PyArray_GetNDArrayCVersion,
        (void *) &PyBigArray_Type,
        (void *) &PyArray_Type,
		...
		...
        (void *) PyArray_PutTo,
        (void *) PyArray_PutMask,
        (void *) PyArray_Repeat,
		...
		...
};

```

