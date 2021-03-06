#include <Python.h>

#include "x13.h"

static PyObject *x13_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    sperocoin_x13_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    sperocoin_x13_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef X13Methods[] = {
    { "getPoWHash", x13_getpowhash, METH_VARARGS, "Returns the proof of work hash using x13 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef X13Module = {
    PyModuleDef_HEAD_INIT,
    "sperocoin_x13_hash",
    "...",
    -1,
    X13Methods
};

PyMODINIT_FUNC PyInit_sperocoin_x13_hash(void) {
    return PyModule_Create(&X13Module);
}

#else

PyMODINIT_FUNC initsperocoin_x13_hash(void) {
    (void) Py_InitModule("sperocoin_x13_hash", X13Methods);
}
#endif
