/*************** Introdution  ****************/
/* Welcome, welcome, welcome!                */
/*                                           */
/* These lovely and not at all frustrating   */
/* or confusing blocks are all needed.       */
/*                                           */
/* And I do mean ALL OF THEM!                */
/*********************************************/

#define PY_SSIZE_T_CLEAN /* This line is needed, so just put it. Always. */
#include <Python.h> /* This one is where the magic happens */

/* These are automatically included in <Python.h>
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <unistd.h> */


/*********** First Whatchamacallit ***********/
/* This fellow is the start of everything    */
/*                                           */
/* It gives to the Second Whatchamacallit:   */
/* --> `method_fputs`                        */
/*********************************************/

static PyObject *
method_fputs(PyObject *self, PyObject *args)
{
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    FILE *fp = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

	printf("Write: %s\n", str);
	printf("To: %s\n", filename);

    return PyLong_FromLong(bytes_copied);
}

/*********** Second Whatchamacallit **********/
/* This takes from First Whatchmacallit:     */
/* --> `method_fputs`                        */
/*                                           */
/* And gives to the Third Whatchamacallit:   */
/* --> `fputs`                               */
/*                                           */
/* This is how we interface with Python:     */
/* `import fputs`                            */
/*********************************************/


static PyMethodDef FputsMethods[] = 
{
    {"fputs", method_fputs, METH_VARARGS,
		"Python interface for fputs C library function"},
    {NULL, NULL, 0, NULL} /* This one is called a sentinel */
};


/*********** Third Whatchamacallit ***********/
/* This takes from Second Whatchamacallit:   */
/* --> `fputs`                               */
/* --> `FputsMethods`                        */
/*                                           */
/* And gives to the Fourth Whatchamacallit:  */
/* --> `fputsmodule`                         */
/*********************************************/

static struct PyModuleDef fputsmodule = 
{
    PyModuleDef_HEAD_INIT,
    "fputs",
    "Python interface for the fputs C library function",
    -1,
    FputsMethods
};

/********** Fourth Whatchamacallit ***********/
/* This takes from Third Whatchamacallit:    */
/* --> `fputsmodule`                         */
/*********************************************/

PyMODINIT_FUNC
PyInit_fputs(void)
{
    return PyModule_Create(&fputsmodule);
}

