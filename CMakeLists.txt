set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

cmake_minimum_required(VERSION 3.28)
project(4_)

include_directories(inc)

set(CMAKE_CXX_STANDARD 17)

add_executable(4_ src/main.cpp
        src/mainwindow.cpp
        inc/mainwindow.h
        src/process.cpp
        inc/process.h
        src/point.cpp
        inc/point.h
        inc/errors.h
        src/figure.cpp
        inc/figure.h
        src/draws.cpp
        inc/draws.h
        src/link.cpp
        inc/link.h
        src/transformations.cpp
        inc/transformations.h)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
target_link_libraries(4_ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
include_directories(cmake-build-debug/4__autogen/include/ui_mainwindow.h)