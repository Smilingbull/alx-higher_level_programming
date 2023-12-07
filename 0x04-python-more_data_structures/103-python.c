#include <Python.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "Invalid Python list object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        printf("Element %zd: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "Invalid Python bytes object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    char *data = PyBytes_AsString(p);

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", data ? data : "(null)");

    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf("%02hhx", data[i]);
        if (i < 9 && i + 1 < size) {
            printf(" ");
        }
    }
    printf("\n");
}


