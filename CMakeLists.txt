cmake_minimum_required(VERSION 3.15...3.26)

set(MODNAME pbstring)

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

python_add_library(${MODNAME} MODULE src/main.cpp src/MyString.cpp WITH_SOABI)
target_link_libraries(${MODNAME} PRIVATE pybind11::headers)
target_compile_definitions(${MODNAME} PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS ${MODNAME} DESTINATION ${MODNAME})
