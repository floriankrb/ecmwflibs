#include <stdio.h>
#include <Python.h>

#include <eccodes.h>
// #include <magics.h>
#define MAGICS_VERSION_STR "xxx"

static PyObject* versions(PyObject *self, PyObject *args) {
    long s = grib_get_api_version();

    return Py_BuildValue("{s:s,s:s}",
        "eccodes", ECCODES_VERSION_STR,
        "magics", MAGICS_VERSION_STR);
}

static PyMethodDef ecmwflibs_methods[] = {
    {
        "versions", versions, METH_NOARGS,
        "Versions",
    },
    {0,}
};

static struct PyModuleDef ecmwflibs_definition = {
    PyModuleDef_HEAD_INIT,
    "ecmwflibs",
    "Load ECMWF libraries.",
    -1,
    ecmwflibs_methods
};

PyMODINIT_FUNC PyInit__ecmwflibs(void) {
    Py_Initialize();
    return PyModule_Create(&ecmwflibs_definition);
}
