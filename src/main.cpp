#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "MyString.h"

namespace py = pybind11;


PYBIND11_MODULE(pbstring, m) {
    py::class_<MyString>(m, "MyString")
        .def(py::init<char*>())
        .def("length", &MyString::length)
        .def("is_palindrome", &MyString::is_palindrome)
        // i want to call call &MyString::slice(start, end, step) when calling s[start:end:step] for a MyString s
        .def("__getitem__", [](const MyString &ms, py::slice slice) {
            size_t start, stop, step, slicelength;
            if (!slice.compute(ms.length(), &start, &stop, &step, &slicelength)) {
                throw py::error_already_set();
            }
            return ms.slice(start, stop, step);
        });
        // .def("__repr__", [](const MyString &ms) {
        //     return "<MyString: " + std::string(ms) + ">";
        // });
}

