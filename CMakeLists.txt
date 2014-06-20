cmake_minimum_required(VERSION 2.8.8)

project(Rampage)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(rampage_SOURCES main.cpp mainwindow.cpp editorblade.cpp)
set(rampage_HEADERS mainwindow.h editorblade.h)

find_package(Qt5Widgets REQUIRED)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(rampage ${rampage_SOURCES} ${rampage_HEADERS} )

target_link_libraries(rampage Qt5::Widgets ${PYTHON_LIBRARIES})
