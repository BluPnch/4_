set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

cmake_minimum_required(VERSION 3.28)
project(4_)

set(CMAKE_CXX_STANDARD 17)

add_executable(4_ main.cpp
        mainwindow.cpp
        mainwindow.h
        process.cpp
        process.h
        point.cpp
        point.h
        errors.h
        figure.cpp
        figure.h
        actions.cpp
        actions.h
        link.cpp
        link.h)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
target_link_libraries(4_ PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
include_directories(./cmake-build-debug/4__autogen/include/ui_mainwindow.h)