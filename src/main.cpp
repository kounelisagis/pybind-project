#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "MyString.h"

namespace py = pybind11;


PYBIND11_MODULE(pbstring, m) {
    py::class_<MyString>(m, "MyString")
        .def(py::init<char*>())
        .def("length", &MyString::length)
        .def("is_palindrome", &MyString::is_palindrome)
        .def("__getitem__", [](const MyString &ms, py::object arg) {
            if (py::isinstance<py::int_>(arg)) {
                size_t index = arg.cast<size_t>();
                if (index >= ms.length()) {
                    throw py::index_error();
                }
                return ms.slice(index, index + 1, 1);
            } else if (py::isinstance<py::slice>(arg)) {
                py::slice slice = arg.cast<py::slice>();
                size_t start, stop, step, slicelength;
                if (!slice.compute(ms.length(), &start, &stop, &step, &slicelength)) {
                    throw py::error_already_set();
                }
                return ms.slice(start, stop, step);
            } else {
                throw std::logic_error("Invalid argument type for __getitem__");
            }
        })
        .def("__len__", &MyString::length)
        .def("__repr__", [](const MyString &ms) {
            return std::string(ms.get_data());
        });
}
